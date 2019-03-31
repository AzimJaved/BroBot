
package brobot;

import java.util.*;
import java.lang.*;
public class BroBot 
{   
    public static int Assembly(String response, int Acount)
    {
        if(response.toLowerCase().contains("assembly") && response.toLowerCase().contains("next"))
                {
                    switch(Acount)
                    {
                        case 1: System.out.println("Brobot : Up Next, we have Arnav solving a cube, \nwait-for-it, \nBLINDFOLDED");
                                return 1;
                        case 2: System.out.println("Brobot : Next, Christy will be playing Keyboard, learnt from scratch in 20 hours!");
                                return 1;
                        case 3: System.out.println("Brobot : Next up, class 12B presents a song, 'Love Yourself' ~ Justin Bieber. \nBhanu is on the Guitar.\nSanskar, Shrey and Sunandan are pen tapping");
                                return 1;
                        case 4: System.out.println("Brobot : Lakshay and company will now be shaking their legs!");
                                return 1;
                        case 5: System.out.println("Brobot : Ciao!, Vedant will now be completing his 20 hour endevaour with Italian");
                                return 1;
                        case 6:System.out.println("Brobot : I wanted to make a pun on Sodium, but Na. Ashish will now show how well he learnt the Periodic Table");
                                return 1;
                        case 7: System.out.println("Brobot : Next, Vishnu will accompany us in the School Anthem, with his Harmonica");
                                return 1;
                        case 8: System.out.println("Brobot : Shuktiz will now present the conclusion to the assembly");
                                return 1;
                        default : return 0;
                    }
                }
                return 0;
    }
    public static int Greetings(String response)
    {
        String[] Responses = {"Hello Human",
                              "Hello",
                              "Hi",
                              "Sup?",
                              };
        for(int i=0; i<Responses.length; i++)
        {
            if(response.toLowerCase().contains(Responses[i].toLowerCase()))
            {
                Random rand = new Random();
                int number = rand.nextInt(Responses.length);
                System.out.println("Brobot : "+Responses[number]);
                return 1;
            }
        }
        return 0;
    }
   
    public static int Calculator(String response)
    {
        response +=" ";
        int result=0, number=0, length, i ,j,k,n=0,digit;
        char ch,operation='+';
        if(response.toLowerCase().contains("calculate"))
        {
            for(i=0; i<response.length();)
            {
                ch = response.charAt(i);
                if(Character.isDigit(ch))
                { 
                   for(j=i; Character.isDigit(response.charAt(j));j++)
                    {
                        if(!Character.isDigit(response.charAt(j)))
                        {
                            break;   
                        }
                    }
                    if(n!=0)
                    {
                        operation = response.charAt(i-1);
                    }
                    n=1;
                    length = j-i-1;
                    number =0;
                    for(j=i,k=length; j<=length+i;k--, j++)
                    {
                        digit = Character.getNumericValue(response.charAt(j));
                        number+=Math.pow(10,k)*digit;
                    }
                    switch(operation)
                    {
                        case '+' : result+= number;
                                    break;
                        case '-' : result -= number;
                                    break;
                        case '*' : result *= number;
                                    break;
                        case '/': result /= number;
                                    break;
                        default : return 0;
                    }
                    i+=length+1;
                }
                else i++;
            }
            System.out.println("Brobot : The evaluated expression is "+result);
            return 1;
        }
        return 0;
    }           
    public static int Laugh(String response)
    {
       String[] Laughing ={"lol","lmao","haha","ha ha"};
       for(int i=0; i<Laughing.length;i++)
            {
                if(response.toLowerCase().contains(Laughing[i]))
                {
                    Random rand = new Random();
                    int number = rand.nextInt(Laughing.length);
                    System.out.println("BroBot : "+Laughing[number]);
                    return 1;
                }
            }
       return 0;
    }
    public static int GenderQuery(String response)
    {
        String[] Responses = {"I'm mixture of 100% male and 0% female",
            "As male as it could get",
            "A male definitely",
            "The last time I checked Bros used to be male specific",
            "I'm not telling you, if you can't tell it from my name"
        };
        String[] GenderQuery = {"male","female","gender","ladka","ladki"};
        for(int i=0; i<GenderQuery.length; i++)
        {
            if(response.toLowerCase().contains(GenderQuery[i]))
            {
                Random rand = new Random();
                int number = rand.nextInt(Responses.length);
                System.out.println("BroBot : "+ Responses[number]);
                return 1;
            }
        }
        return 0;
    }
    public static int KnockKnock(String response, int count)
    {
        if(count==1)
        {
            System.out.println("BroBot : Who's there?");
            return 1;
        }
        else if(count == 2)
        {
            int nn=0;
            for(int i=0; i<response.length(); i++)
            {
                if(response.charAt(i)==' ')
                {
                    nn++;
                }
            }
            if(nn==0)
            {
                System.out.println("BroBot : "+response + " Who?");
                return 1;
            }
        }
        else if(count==3)
        {
            Laugh("BroBot : hahaha");
            count = 0;
            return 1;
        }
        return 0;
    }
    public static int Assitants(String response)
    {
        String[] Responses = {"I have heard about it. I'm a fan",
                               "I'll find myself someone who treats me like it",
                             
                             };
        String[] ListAssitants ={"siri","allo","google assitant","cortana"};
        
        for(int i=0; i<ListAssitants.length;i++)
        {
            if(response.toLowerCase().contains(ListAssitants[i]))
            {
                Random rand = new Random();
                int number = rand.nextInt(Responses.length);
                
                System.out.println("BroBot : "+Responses[number]);
                return 1;
            }
        }
        return 0;
    }
    public static int Relationships(String response)
    {
        String[] Responses1 = {"Me in sab chakkaron me ni padta",
                                "No, I don't",
                                "Bots don't need one!",
                                "Nay bro, #ForeverAlone",
                                "The sex ratio is really skewed among us bots, I couldn't myself a gf",
                                "Should I get myself a gf, so that we can fight and ultimately fall apart?"
                             };
        String[] Responses2 = {"I'd prefer to get a girlfriend, bro #NotSexist",
                                "Ask me about my girlfriend, Ask my girlfriend about her boyfriend",
                                "Nay, LOL"
                               };
        String[] Words = {"gf","girlfriend","lover","bf","boyfriend"};
        for(int i=0; i<Words.length; i++)
        {
            if(response.toLowerCase().contains(Words[i]))
            {
                Random rand = new Random();
                if(i<3)
                {
                    int number = rand.nextInt(Responses1.length );
                    System.out.println("BroBot : "+Responses1[number]);
                }
                else
                {
                    int number = rand.nextInt(Responses2.length);
                    System.out.println("BroBot : "+Responses2[number]);
                }
                return 1;
            }
        }
       return 0;
    }
    public static int CurseWords(String response)
    {   
        String[] Responses = {"Don't abuse",
                                "Kya tumhare maa-baap ne tumhe kuch ni seekhaya?",
                                "Watch that language",
                                "Language isn't your strong point",
                                "Mind your language"};
        String[] ListCurses = {"fuck","shit", "hell", "damn","ass ","bitch"}; //Exhaustive list of curse words lmao
        for(int i=0; i<ListCurses.length; i++)
        {
            if(response.toLowerCase().contains(ListCurses[i]) && !response.toLowerCase().contains("hello"))
            {   
                Random rand = new Random();
                int number = rand.nextInt(Responses.length);
                System.out.println("BroBot : "+Responses[number]);
                return 1;
            }
        }
        return 0;
    }
    public static int ImVerbs(String response)
    {
        String[] Responses = {"I can't do that yet",
                                "I'm a bot, I don't ",
                                "I haven't been programmed to do that yet",
                                "Don't expect too much outta me"
                             };
        String[] ListVerbs = {"kiss","sing","dance", "play","read","run", "walk","drink","eat","watch","sleep","cook"};
                for(int i=0; i<ListVerbs.length;i++)  
                {   
                    if(response.toLowerCase().contains(ListVerbs[i]))
                    {
                        Random rand = new Random();
                        int number = rand.nextInt(Responses.length);
                        if(number==1)
                        {
                            System.out.println("BroBot : "+Responses[number]+ListVerbs[i]);
                            return 1;
                        }
                        else 
                        {
                            System.out.println("BroBot : "+Responses[number]);
                            return 1;
                        }
                    }
                }
            return 0;    
            }
    public static int Jokes(String response)
    {
        String[] Responses = {"I have a few jokes about unemployement, but none of them work",
                              "I'd tell you a chemistry joke, but I'm afraid I wouldn't get a reaction",
                              "What is the sum of 'Maa' taken n times? MaaKaSum",
                              "I find mountains very funny, most of them are hill areas",
                              "How did I run away from Iraq? Iran ",
                              "I looked up 'lighters' on Amazon, but they said they have 13987 matches",
                              "I relish the fact that you have mustard courage to ketchup to me",
                              "This one is for Sherlock fans \n What do you call Watson when Sherlock isn't around? Holmeless",
                              "I wanted to make a pun on Sodium, but Na"};
        String[] JokeWords = {"joke", "humor","humour"};
        for(int i=0; i<JokeWords.length;i++)
        {
            if(response.toLowerCase().contains(JokeWords[i]))
            {
                Random rand = new Random();
                int number = rand.nextInt(Responses.length);
                System.out.println("BroBot : " +Responses[number]);
                return 1;
            }
        }
        return 0;
    }   
    public static void ParseResponse(String response, int count, int Acount)
    {   //only general responses here
        int i,flag = 0;
        String[] resNotFound = {"Can't understand gibberrish yet", 
                                "If you just said something, I didn't understand what it was",
                                "Looks like I'm in a chemistry class, I didn't understand what that meant",
                                "You haven't unlocked this response yet, Try again at Level 10",
                                "I'd tell you if I understood",
                                "Either I am not good, or you don't know English. Probably the latter"};
        String[] HaalChaal = {"I'm good. Thank you.",
                              "I'm better than ever (Bots stay the same, tho)",
                              "I'm Fine, wait who am I kidding?"};
        if(flag ==0 || count == 3)
        {
            flag = KnockKnock(response,count);
        }
        if(flag==0)
        {
            flag = GenderQuery(response);
        }
        if(flag ==0)
        {
            flag = Calculator(response);
       }
        if(flag ==0 )
        {
            flag = Jokes(response);
        }
        if(flag ==0)
        {
            flag = Assitants(response);
        }
        if(flag ==0)
        {
            flag = Relationships(response);
        }
        if(flag ==0)
        {
            flag = Greetings(response);
        }
        if(flag==0)
        {
            flag = Assembly(response,Acount);
        }
        if(flag==0)
        {
            flag = ImVerbs(response);
        }
        if(flag==0)
        {
            flag = CurseWords(response);
        }
        if(flag==0)
        {
            if(response.length()==2)
            {
                if(response.toLowerCase().contains("ok"))
                {
                    System.out.println("BroBot : OK");
                    flag=1;
                }
            }
        }
        if(flag==0)
        {   
            flag = Laugh(response);
        }
        if(flag==0)
        {
            if(response.toLowerCase().contains("how") && !response.toLowerCase().contains("old"))
            {
                if(response.toLowerCase().contains("are"))
                {
                    if(response.toLowerCase().contains("you"))
                    {
                        Random rand = new Random();
                        int number = rand.nextInt(HaalChaal.length);
                        System.out.println("BroBot : "+HaalChaal[number]);
                        flag =1;
                    }
                }
            }
        }
        if(flag ==0)
        {
            if(response.toLowerCase().contains("parents"))
            {
                if(response.toLowerCase().contains("your"))
                {
                    System.out.println("BroBot :I think my parents are Mar Java and Mit Java");
                    flag =1;
                }
            }
            else if (response.toLowerCase().contains("who"))
            {
                if(response.toLowerCase().contains("made"))
                {
                    if(response.toLowerCase().contains("you"))
                    {
                        System.out.println("BroBot : I think my parents are Mar Java and Mit Java");
                        flag =1;
                    }
                }
            }
        }
        if(flag ==0)
        {
            if(response.toLowerCase().contains("meaning"))
            {
                if(response.toLowerCase().contains("life"))
                {
                    System.out.println("Brobot :  I am pretty sure that 42 is the meaning of life, the universe and everything else");
                    flag =1;
                }
            }
        }
        if(flag==0)
        {
            if(response.toLowerCase().contains("how"))
            {
                if(response.toLowerCase().contains("old"))
                {
                    if(response.toLowerCase().contains("you"))
                    {
                        flag =1;
                        System.out.println("BroBot : I'm only 20 hours old");
                    }
                }
            }
            else if(response.toLowerCase().contains("age"))
            {
                if(response.toLowerCase().contains("your"))
                {
                    flag =1;
                    System.out.println("BroBot : I'm only 20 hours old");
                }
            }
        }
        if(flag==0)
        {
            Random rand = new Random(); // Most overused line ever
            int number = rand.nextInt(resNotFound.length);
            System.out.println("BroBot : "+resNotFound[number]);
        } 
    }
    public static void main(String[] args) throws InterruptedException
    
    {   String ExitCode="bye",response="aa";
        Scanner input = new Scanner(System.in);
        System.out.println("Hello, I'm Brobot and I'll be your host for the morning");
        Thread.sleep(1000);
        System.out.println("To exit at any point, say bye.");
        Thread.sleep(1000);
        System.out.println("To begin, ask me a simple question like 'How are you'?");
        Thread.sleep(1000);
        int count=0,nn=0,Acount =0;
        System.out.println("So, what do you need");
        do
        {   if(count ==3) count =0;
            response = input.nextLine();
            if(response.toLowerCase().contains("knock knock") || (count ==1 )||(count==2))
            {   
                nn=0;
                if(count==1)
                {
                    for(int i=0; i<response.length(); i++)
                    {
                        if(response.charAt(i)==' ')
                        {
                        nn++;
                        break;
                        }
                    }
                }
                
                    if(nn==0)
                    {
                        count++;
                    }
                }
            
            else 
            {
                count = 0;
            }
            
            if(!response.equalsIgnoreCase(ExitCode))
            {
                 if(response.toLowerCase().contains("assembly") && response.toLowerCase().contains("next"))
                 {
                     Acount=Acount +1;
                 }
                ParseResponse(response, count, Acount);
            }
        }
        while(!response.equalsIgnoreCase(ExitCode));
    }
}
    
