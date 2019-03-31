#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int contains(char*, char*);
void outleft(char[], int);
void strlower(char*);
int getn(char[]);
void welcome();
char dontknow[10][100];
int nknow,pop=0;

void main()
{
	clrscr();
	welcome();
	strcpy(dontknow[0],"You havent unlocked this response yet. Try again at level 5");
	strcpy(dontknow[1],"Pardon?");
	strcpy(dontknow[2],"I didn't understand that, I'm not siri yet");
	strcpy(dontknow[3],"My information on that topic is very limited. Ask me to play something!");
	strcpy(dontknow[4],"I totally understood what that meant");
	nknow=5;
	char resp[100], ach[100][100];
	int bcode1, k,flg;
	do
	{
		ifstream fin("bbot1.dat",ios::binary);
		gets(resp);
		do
		{
			fin.read((char*)&bboto, sizeof(bboto));
			bcode1=bboto.gbcode();
			k=0;
			ifstream fint("bresp.txt");
			while(!fint.eof()  && k<bboto.grespcount())
			{
				char filin[80]; int strl;
				fint.getline(filin, 80);
				strl=strlen(filin);
				int num = getn(filin);
				if(num==bcode1)
				{
					for(int i=0;i<strl;i++)
					{
						filin[i]=filin[i+2];
					}
					strcpy(ach[k], filin);
					k++;
				}
			}
			bboto.putresp(ach);
			flg=bboto.chckkey(resp);
			if(flg!=0 && flg!=21)
			{
				break;
			}
		}while(!fin.eof());
		switch(flg)
		{
			case 22: outleft("Heerree we go, Hisssss!. Press any key to continue",wherey());
				getch();
				snakeo.smain();
				break;
			case 3: outleft(" * typing noises *. Press any key to continue ", wherey());
				getch();
				typero.tymain();
				break;
			case 25:
			case 24:outleft("Hmmm, I see that as a challenge. Press any key to continue", wherey());
				getch();
				ttto.tmain();
				break;
			case 0: outleft(dontknow[rand()%nknow],wherey());
				break;
			default:outleft(bboto.response, wherey());
		}
	}while(strcmp(resp,"bye"));
}

/********************************************************************
			Modules
*********************************************************************/
/*		       <Brobot>					    */
class bbot
{
	int keycount;
	int respcount;
	int bcode;
	int xkflag;
	char responses[100][100];
	char keys[100][100];
	public:
	char response[100];
	void retresp();
	int chckkey(char*);
	void display();
	void putresp(char[100][100]);
	int gxkflag();
	int gkeycount();
	int grespcount();
	int gbcode();
	char* gkeys(int);
	char* gresponses(int);
	void learn();
	bbot();
}bboto;

void bbot::putresp(char ach[100][100])
{
	for(int i=0; i<respcount; i++)
	{
		strcpy(responses[i], ach[i]);
	}
}

int bbot::chckkey(char* resp)
{
	for(int i=0; i<keycount; i++)
	{
		if(contains(resp, keys[i]))
		{
			if(xkflag==1)
			{
				retresp();
				return bcode;
			}
		}
		else if (xkflag==0)
		{
			return 0;
		}
	}
	if(xkflag==1)
	{
		return 0;
	}
	else if(xkflag==0)
	{
		retresp();
		return bcode;
	}
	return 0;
}
void bbot::retresp()
{
    if(keycount!=0)
    {
	srand(time(0));
	strcpy(response, responses[rand()%respcount]);
    }
}
void bbot::learn()
{
	cout<<"Enter Bcode (!=0, unique) ";
	cin>>bcode;
	cout<<"X(0) or K(1)?";
	cin>>xkflag;
	cout<<"Number of keys";
	cin>>keycount;
	cout<<"Enter Keys ";
	for(int i=0; i<keycount; i++)
	{
		gets(keys[i]);
	}
	cout<<"Number of responses ";
	cin>>respcount;
}
bbot::bbot()
{
	xkflag=69;
	keycount=0;
	respcount=0;
}
void bbot::display()
{
	cout<<"\nflg "<<xkflag;
	cout<<"\nkeyc "<<keycount;
	cout<<"\nrespc "<<respcount;
	cout<<"\nkeys\n";
	for(int i=0; i<keycount; i++)
	{
		puts(keys[i]);
	}
	cout<<"\nresponses\n";
	for(i=0; i<respcount; i++)
	{
		puts(responses[i]);
	}
}
int bbot::gxkflag()
{
	return xkflag;
}
int bbot::gkeycount()
{
	return keycount;
}
int bbot::grespcount()
{
	return respcount;
}
int bbot::gbcode()
{
	return bcode;
}
char* bbot::gkeys(int n)
{
	return keys[n];
}
char* bbot::gresponses(int n)
{
	return responses[n];
}
/*				</Brobot>			*/
/*			      <Tic Tac Toe>  			*/
class ttt
{
	char square[9],choices[15];
	int val[9],first;
	public:
	ttt();
	void display();
	int getval(int);
	int ifwin();
	int getmaxval();
	int wincheck();
	int tmain();
}ttto;
ttt::ttt()
{
	first=0;
}
void ttt::display()
{
	int x=31, y=8;
	gotoxy(x,y);
	cout<<"     |     |     \n";gotoxy(x,y+1);
	cout<<"  "<<square[0]<<"  |  "<<square[1]<<"  |  "<<square[2]<<endl;gotoxy(x,y+2);
	cout<<"_____|_____|_____\n";gotoxy(x,y+3);
	cout<<"     |     |     \n";             gotoxy(x,y+4);
	cout<<"  "<<square[3]<<"  |  "<<square[4]<<"  |  "<<square[5]<<endl; gotoxy(x,y+5);
	cout<<"_____|_____|_____\n";                                                   gotoxy(x,y+6);
	cout<<"     |     |     \n";   gotoxy(x,y+7);
	cout<<"  "<<square[6]<<"  |  "<<square[7]<<"  |  "<<square[8]<<endl; gotoxy(x,y+8);
	cout<<"     |     |     \n";                                gotoxy(x,y+9);
}
int ttt::getval(int num)  //Only defense
{
	if(num==0)
	{
		if(square[8]=='X') val[4]++;
		else if(square[2]=='X') val[1]++;
		else if(square[1]=='X') val[2]++;
		else if(square[6]=='X') val[3]++;
		else if(square[3]=='X') val[6]++;
		val[4]++; val[1]++; val[8]++; val[2]++; val[3]++; val[6]++;
	}
	else if(num==1)
	{
		if(square[0]=='X') val[2]++;
		else if (square[7]=='X') val[4]++;
		else if (square[2]=='X') val[0]++;
		else if (square[4]=='X') val[7]++;
		val[0]++; val[7]++; val[2]++; val[4]++;
	}
	else if(num==2)
	{
		if(square[0]=='X') val[1]++;
		else if(square[1]=='X') val[0]++;
		else if (square[8]=='X') val[5]++;
		else if(square[5]=='X') val[8]++;
		else if(square[6]=='X') val[4]++;
		else if (square[4]=='X') val[6]++;
		val[1]++;val[0]++;val[4]++;val[6]++;val[5]++;val[8]++;
	}
	else if(num==3)
	{
		if (square[5]=='X') val[4]++;
		else if (square[4]=='X') val[5]++;
		else if (square[0]=='X') val[6]++;
		else if (square[6]=='X') val[0]++;
		val[0]++;val[6]++;val[4]++;val[5];
	}
	else if(num==4)
	{
		if(square[0]=='X') val[8]++;
		else if(square[8]=='X') val[0]++;
		else if (square[2]=='X') val[8]++;
		else if (square[1]=='X') val[7]++;
		else if (square[7]=='X') val[1]++;
		else if (square[1]=='X') val[7]++;
		else if (square[3]=='X') val[5]++;
		else if (square[5]=='X') val[3]++;
		else if (first==0) {val[0]++; val[2]++; val[8]++; val[6]++; first=1;}
		val[0]++;val[1]++;val[2]++;val[3]++;val[5]++;val[6]++;val[7]++;val[8]++;
	}
	else if(num==5)
	{
		if (square[2]=='X') val[8]++;
		else if (square[8]=='X') val[2]++;
		else if (square[3]=='X') val[4]++;
		else if (square[4]=='X') val[3]++;
		val[2]++;val[8]++;val[3]++;val[4]++;
	}
	else if(num==6)
	{
		if (square[0]=='X') val[3]++;
		else if (square[3]=='X') val[0]++;
		else if (square[7]=='X') val[8]++;
		else if (square[8]=='X') val[7]++;
		else if (square[4]=='X') val[2]++;
		else if (square[2]=='X') val[4]++;
		val[0]++;val[3]++;val[7]++;val[8]++;val[4]++;val[2]++;
	}
	else if(num==7)
	{
		if (square[1]=='X') val[4]++;
		else if (square[4]=='X') val[1]++;
		else if (square[6]=='X') val[6]++;
		else if (square[8]=='X') val[6]++;
		val[1]++;val[4]++; val[6]++; val[8]++;
	}
	else if(num==8)
	{
		if (square[0]=='X') val[4]++;
		else if (square[4]=='X') val[0]++;
		else if (square[2]=='X') val[5]++;
		else if (square[5]=='X') val[2]++;
		else if (square[7]=='X') val[6]++;
		else if (square[6]=='X') val[7]++;
		val[0]++;val[4]++;val[2]++;val[5]++;val[6]++;val[7]++;
	}
	else
	{
		return 0;
	}
	return 1;
}

int ttt::ifwin()
{
	int i;
	for(i=0; i<8; i+=3)
	{
		if(square[i]=='O')
		{
			if(square[i+2]=='O')
			{
				if(isdigit(square[i+1]))
					return i+1;
			}
		}
	}

	for(i=0; i<8; i+=3)
	{
		if(square[i]=='O')
		{
			if(square[i+1]=='O')
			{
				if(isdigit(square[i+2]))
					return i+2;
			}
		}
	}
	for(i=2; i<8; i+=3)
	{
		if(square[i]=='O')
		{
			if(square[i-1]=='O')
			{
				if(isdigit(square[i-2]))
					return i-2;
			}
		}
	}
	for(i=0; i<3; i++)
	{
		if(square[i]=='O')
		{
			if(square[i+3]=='O')
			{
				if(isdigit(square[i+6]))
					return i+6;
			}
		}
	}
	for(i=6; i<9; i++)
	{
		if(square[i]=='O')
		{
			if(square[i-3]=='O')
			{
				if(isdigit(square[i-6]))
					return i-6;
			}
		}
	}
	if(square[4]=='O')
	{
		if(square[0]=='O')
		{
			if(isdigit(square[8]))
				return 8;
		}
		else if(square[8]=='O')
		{
			if(isdigit(square[0]))
				return 0;
		}
		else if(square[2]=='O')
		{
			if(isdigit(square[6]))
				return 6;
		}
		else if(square[6]=='O')
		{
			if(isdigit(square[2]))
				return 2;
		}
	}
	return -1;
}
int ttt::getmaxval()
{
	choices[0]='\0';
	int mval=0,j=0;
	for(int i=0; i<9; i++)
	{
		if(val[i]>=mval)
		{
			if(isdigit(square[i]))
			{
				mval=val[i];
			}
		}
	}
	for(i=0; i<9; i++)
	{
		if(isdigit(square[i]))
		{
			if(val[i]==mval)
			{
				choices[j]=i+48;
				choices[j+1]='\0';
				j++;
			}
		}
	}
	return j;
}
int ttt::wincheck()
{
	char chars[3]="OX";
	int j;
	for(int i=0; i<8; i+=3)
	{
		for(j=0; j<2; j++)
		{
			if(square[i]==chars[j] && square[i+1]==chars[j] && square[i+2]==chars[j])
			{
				return j+1;
			}
		}
	}
	for(i=0; i<3; i++)
	{
		for(j=0; j<2; j++)
		{
			if(square[i]==chars[j] && square[i+3]==chars[j] && square[i+6]==chars[j])
			{
				return j+1;
			}
		}
	}
	for(j=0; j<2; j++)
	{
		if(square[4]==chars[j])
		{
			if(square[0]==chars[j] && square[8]==chars[j])
			{
				return j;
			}
			else if(square[2]==chars[j] && square[6]==chars[j])
			{
				return j+1;
			}
		}
	}
	return 0;
}
int ttt::tmain()
{
	int num,choice,flag=0,win;
	for(int i=0; i<9; i++)
	{
		square[i]=i+48;
		val[i]=0;
	}
	val[4]=2;
	do
	{
		clrscr();
		display();
		cout<<"Enter a number as shown ";
		cin>>num;
		if(isdigit(square[num]))
		{
			square[num]='X';
			getval(num);
			int number=getmaxval();
			choice=ifwin();
			if(choice>0)
			{
				square[choice]='O';
				flag=1;
			}
			else
			{
				choice= choices[rand()%number]-48;
				square[choice]='O';
				flag=2;
			}
			if(first ==1) //cheating pt2
			{
				if(choice==0)
				{
					val[1]--;val[4]--;
				}
				else if(choice==2)
				{
					val[1]--; val[5]--;
				}
				else if(choice==8)
				{
					val[5]--; val[7]--;
				}
				else if(choice==6)
				{
					val[3]--; val[7]--;
				}
			}
			win=wincheck();
			cout<<"Decided  "<<choice<<" Flag "<<flag;
			cout<<" Choices "<<choices<<endl;
			getch();
		}
	}
	while(num!=10 && win==0);
	if(win==1)
	{
		cout<<"Computer won, boo human ";
	}
	else if(win==2)
	{
		cout<<"Well played, my maker didn't think this if condition would ever be true ";
	}
	else
	{
		cout<<"Draw, but we'll give it to the underdog.. You win";
	}
	return 383;
}
/*				</Tic Tac Toe>				*/
/*				<Typer>                                 */
class typer
{
	int keyprs,lev,won,lose,spos, strl;
	char* a;
	public:
	typer();
	void sseed();
	char getinp();
	void welcomescreen();
	void inst();
	int check(char[], char, int);
	void s();
	int tymain();
}typero;

typer::typer()
{
	keyprs=0;
	lev=1;
	won=0;
	lose=0;
	spos=0;
}
class string
{
	int num;
	char a[500] ;
	public :
	void accept();
	char* cpy()
	{
		return a;
	}
	int ch()
	{
		return num;
	}
	void display()
	{
		cout<<"Num "<<num<<endl<<"String- "<<a<<endl;
	}
};
void string::accept()
{
	cout<<"Enter number ";
	cin>>num;
	cout<<"Enter string "<<endl;
	gets(a);
}
char typer::getinp()
{
	return kbhit()?getch():NULL;
}
void typer::sseed()
{
	randomize();
	int r= random(15)+1;
	ifstream fin("quo.dat",ios::binary);
	string s;
	while(!fin.eof())
	{
		fin.read((char*)&s, sizeof(s));
		if(r==s.ch())
		strcpy(a,s.cpy());
	}
}
void typer::welcomescreen()
{
	gotoxy(35,13);
	cout<<"WELCOME TO TYPER GAME";
	delay(2500);
	clrscr();
}
void typer::inst()
{
	gotoxy(35,1);
	cout<<"INSTRUCTIONS";
	gotoxy(1,2);
	cout<<"A sentence will move from the left end towards the right end."
	    <<"\nYou have to be fast enough to type the sentence before"
	    <<" it reaches the right end";
	cout<<endl<<"Ready!? Press any key to continue!";
	if(!getch())
	{
		delay(6000);
	}
	gotoxy(35,13);
	cout<<"LETS GO!";
	if (!getch())
	{
		delay(2500);
	}
	clrscr();
}
int typer::check(char a[], char b, int j)
{
	if(tolower(b)==tolower(a[j]))
	{
		if(j==strl-1)
		{
			won=1;
		}
		a[j]=NULL;
		return 1;
	}
	else if(tolower(b)!=tolower(a[j]))
	{
		lose=1;
		return 0;
	}
	else return NULL;
}

void typer::s()
{
	int chk=1;
	do
	{
		clrscr();
		int j=0,k=0, x=80;
		sseed();
		strl=strlen(a);
		lose=0;
		won=0;
		do
		{
			clrscr();
			char r;
			for(;;x--)
			{
				j=0;
				for(int i=x;i<=80 && j<=strl  ;j++,i++)
				{
					gotoxy(i,13);
					cout<<a[j];
					r=getinp();
					gotoxy(1,1);
					cout<<r;
					gotoxy(1,2);
					cout<<"will be comparing "<<r<<" and "<<k<<"th letter"<<a[k]<<" lev="<<lev<<" strl"<<strl<<" won-"<<won<<"x="<<x<<" "<<"Spos-"<<spos;
					if(r!=NULL)
					{
						chk=check( a,r,k);
						gotoxy(1,3);
						cout<<"chek= "<<chk;
						k+=chk;
						keyprs += chk;
					}
					if(won==1)
					{
						clrscr();
						lev++;
						gotoxy(35,13);
						cout<<"You won this level, level now is"<< lev;
						delay(2000);
						break;
					}
					if(chk==0)
					{
						clrscr();
						gotoxy(35,13);
						cout<<"Wrong Input";
						delay(1000);
						lose=1;
						break;
					}
					if(x+keyprs==1)
					{
						lose=1;
						break;
					}
				}
				if (won==1 || lose==1)
				{
					break;
				}
				if(lev>=6)
				{
					cout<<"You seem to be an expert in typing."   ;
					delay(1000);
					clrscr();
				}
				delay(300);
			}
		}
		while(chk!=0 && won!=1 && lose!=1);
	}
	while(lose!=1);
	delay(200);
	clrscr();
	gotoxy(35,13);
	cout<<"You lose";
	delay(2500);
}
int typer::tymain()
{
	clrscr();
	welcomescreen();
	inst();
	s();
	getch();
	return 383;
}
/*				</Typer>				*/
/*				<Snakes>				*/
class snake
{
	int sflg,score,snkc[80][2],fx,sfx,fy,sfy,snkv[80],keyprs[5][2],bkeyprs[5],snkl,keypc;
	long tm;
	public:
	snake();
	void putfd();
	int turnsnk();
	void movesnk();
	void chckfd();
	void putsfd();
	void snkdisp();
	void getv(char);
	int winchck();
	int smain();
}snakeo;
snake::snake()
{
	score=0;
	keypc=0;
	for(int i=0; i<5; i++)
	{
		keyprs[i][0]=keyprs[i][1]=-1;
	}
	snkl=4;
	snkc[0][0]=25;
	snkc[1][0]=26;
	snkc[2][0]=27;
	snkc[3][0]=28;
	snkc[0][1]=snkc[3][1]=snkc[1][1]=snkc[2][1]=12;
	snkv[1]=snkv[2]=snkv[0]=snkv[3]=4;


}
void snake::putfd()
{
	srand(time(0));
	fx=rand()%80;
	fy=rand()%25;
	if(fy==1)
	{
		putfd();
	}
	for(int i=1; i<snkl; i++)
	{
		if(fx==snkc[i][0] && fy==snkc[i][1])
		{
			 putfd();
		}
	}
}
char input()
{
	if(kbhit())
		return getch();
	return NULL;
}

int snake::turnsnk()
{
	for(int i=1; i<snkl; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(keyprs[j][0]>0)
			{
				if(snkc[i][0]==keyprs[j][0] && snkc[i][1]==keyprs[j][1])
				{
					snkv[i]=bkeyprs[j];
					if(snkc[snkl-1][0]==keyprs[j][0] && snkc[snkl-1][1]==keyprs[j][1])
					{
						keyprs[j][0]=keyprs[j][1]=-1;
					}
				}
			}
		}
	}
	return 1;
}

void snake::movesnk()
{
	for(int i=0; i<snkl; i++)
	{
		if(snkv[i]==6)
		{
			if(snkc[i][0]==79)
			{
				snkc[i][0]=1;
			}
			else
			{
				snkc[i][0]+=1;
			}
		}
		else if(snkv[i]==4)
		{
			if(snkc[i][0]==1)
			{
				snkc[i][0]=79;
			}
			else
			{
				snkc[i][0]-=1;
			}
		}
		else if(snkv[i]==8)
		{
			if(snkc[i][1]==2)
			{
				snkc[i][1]=24;
			}
			else
			{
				snkc[i][1]-=1;
			}
		}
		else if(snkv[i]==2)
		{
			if(snkc[i][1]==24)
			{
				snkc[i][1]=2;
			}
			else
			{
				snkc[i][1]+=1;
			}
		}
	}
}                              void putsfd();

void snake::chckfd()
{
	if(snkc[0][0]==fx && snkc[0][1]==fy)
	{
		if(snkv[snkl-1]==8)
		{
			snkc[snkl][0]=snkc[snkl-1][0];
			snkc[snkl][1]=snkc[snkl-1][1]+1;
		}
		else if(snkv[snkl-1]==2)
		{
			snkc[snkl][0]=snkc[snkl-1][0];
			snkc[snkl][1]=snkc[snkl-1][1]-1;
		}
		else if(snkv[snkl-1]==6)
		{
			snkc[snkl][0]=snkc[snkl-1][0]-1;
			snkc[snkl][1]=snkc[snkl-1][1];
		}
		else if(snkv[snkl-1]==4)
		{
			snkc[snkl][0]=snkc[snkl-1][0]+1;
			snkc[snkl][1]=snkc[snkl-1][1];
		}
		snkv[snkl]=snkv[snkl-1];
		snkl++;
		putfd();
		score++;
		if((score+1)%2==0 && sflg==0)
		{
			sflg=1;
			tm=time(0);
			putsfd();
		}
	}
	else if(snkc[0][0]==sfx && snkc[0][1]==sfy)
	{
		score+=5;
		sflg=0;
		sfx=sfy=-1;
	}
}
void snake::putsfd()
{
	sfx=rand()%80;
	sfy=rand()%25;
	if(sfy==fy && sfx==fx)
	{
		putsfd();
	}
	if(sfy==1)
	{
		putsfd();
	}
	for(int i=1; i<snkl; i++)
	{
		if(snkc[i][0]==sfx && snkc[i][1]==sfy)
		{
			putsfd();
		}
	}
}

void snake::snkdisp()
{
	gotoxy(snkc[0][0],snkc[0][1]);
	cout<<"!";
	gotoxy(69,1);
	cout<<"Score : "<<score;
	long td=time(0)-tm;
	if(sflg==1 && td<=15)
	{
		gotoxy(2,1);
		cout<<"Time : ";
		for(int i=0; i<(15-td); i++)
		{
			gotoxy(i+10,1);
			cout<<"*";
		}
	}
	if(td==15)
	{
		sflg=0;
	}
	for(int i=1; i<snkl; i++)
	{
		gotoxy(snkc[i][0], snkc[i][1]);
		switch(snkv[i])
		{
			case 8: textcolor(5);
				break;
			case 6: textcolor(6);
				break;
			case 4: textcolor(9);
				break;
			case 2: textcolor(8);
				break;
		}
		cputs("o");
	}
	if(sflg==1)
	{
		textcolor(12);
		gotoxy(sfx,sfy);
		cputs("@");
	}
	textcolor(7);
	gotoxy(fx,fy);
	cout<<"#";
}

void snake::getv(char resp)
{
	if(resp=='w' || resp=='a' || resp=='s'|| resp=='d')
	{
		if(keyprs[keypc][0]==-1)
		{
			if(snkv[0]==8)
			{
				keyprs[keypc][0]=snkc[0][0];
				keyprs[keypc][1]=snkc[0][1];
			}
			else if(snkv[0]==2)
			{
				keyprs[keypc][0]=snkc[0][0];
				keyprs[keypc][1]=snkc[0][1];
			}
			else if(snkv[0]==6)
			{
				keyprs[keypc][0]=snkc[0][0];
				keyprs[keypc][1]=snkc[0][1];
			}
			else if(snkv[0]==4)
			{
				keyprs[keypc][0]=snkc[0][0];
				keyprs[keypc][1]=snkc[0][1];
			}
			switch(resp)
			{
				case 'w':bkeyprs[keypc]=8;
					break;
				case 'a':bkeyprs[keypc]=4;
					break;
				case 's':bkeyprs[keypc]=2;
					break;
				case 'd':bkeyprs[keypc]=6;
					break;
			}
			snkv[0]=bkeyprs[keypc];
		}
		if(keypc==4)
		{
			keypc=0;
		}
		else
		{
			keypc++;
		}
	}
}
int snake::winchck()
{
	for(int i=1; i<snkl; i++)
	{
		if(snkc[0][0]==snkc[i][0] && snkc[0][1]==snkc[i][1])
		{
			return 1;
		}
	}
	return 0;
}
int snake::smain()
{
	clrscr();
	char resp;
	int win=0;
	putfd();
	do
	{
		resp=input();
		getv(resp);
		chckfd();
		clrscr();
		cout<<resp;
		snkdisp();
		movesnk();
		turnsnk();
		delay(500-(snkl*10));
		win=winchck();
	}
	while(resp!='z'&& win==0);
	getch();
	return 383;
}
/*			</Snakes>					*/

void outleft(char str[], int y)
{
	int strl= strlen(str);
	if(y==24 || y==25 || y==23 ||y==22 || pop ==1)
	{
		gotoxy(1,1);
		delline();
		pop=1;
	}
	textcolor(CYAN);
	if(pop==0)
	{
		gotoxy(80-strl+1,y+1);
		cputs(str);
	}
	else
	{
		gotoxy(80-strl+1,25);
		cputs(str);
	}
	textcolor(WHITE);
}
int contains(char* str1, char* str2)
{
	int strl1=strlen(str1);
	strlower(str1);
	strlower(str2);
	int strl2=strlen(str2);
	for(int i=0; i<strl1; i++)
	{
		int j=0;
		while(str1[i+j]==str2[j] && j<strl2)
		{
			j++;
		}
		if (j==strl2)
		{
			return 1;
		}
	}
	return 0;
}
int getn(char str[])
{
	int ch1=str[0]-48;
	int ch2=str[1]-48;
	int number = ch1*10 + ch2;
	return number;
}
void welcome()
{
	outleft("Heelllooo, I didn't see you there ",wherey());
	outleft("I'm BroBot, and I'll be you host over here, in my kingdom",wherey());
	outleft("I can answer some of your very simple queries(Try asking a joke), or even ask me to play a few games",wherey());
	outleft("OK,I lied, I can only play Tic Tac Toe, Snake and, Typing game right now :D",wherey());
	outleft("So, what do you want to talk about today?",wherey());
}

void strlower(char* str)
{
	while(*str!='\0')
	{
		*str=tolower(*str);
		str++;
	}
}
