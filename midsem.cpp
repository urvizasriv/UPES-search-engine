#include<string.h> // for strstr or string functions
#include<iostream> // cin cout 
#include<conio.h> // getche 
#include<windows.h> // system.(color E4)
#include<fstream> // fstream : ifstream(input , write) , ofstream(output, read)
#include<stdio.h> //fflush()
#include<stdlib.h> //goto
using namespace std; // standard library (with the same name available in different libraries) if we do not use it we have to write std:: 
class Input
{
protected: 
    char sr[50];  //sr for search
public:
void input()
    {
        fflush(stdin); //used for output stream only. Its purpose is to clear (or flush) the output buffer and move the buffered data to console (in case of stdout) or disk (in case of file output stream).
        cout<<"\t\t\t\t\t    ##########################################\n";
        cout<<"\t\t\t\t\t    ##  Press any key to start searching    ##\n    ";
        cout<<"\t\t\t\t\t    ##########################################\n";
        
        getche(); // waits for any character input from keyboard and it will also echo the input character on to the output screen
        system("cls"); //clear the screen and move cursor to the upper left corner of screen 
        formating1();
        cout<<"\t\t\t\t\t    ###########################################################################################\n";
        cout<<"\t\t\t\t\t    #";
        cout<<"\t\t\t\t\t                                                      #\n";
        cout<<"\t\t\t\t\t    ###########################################################################################\n";
        COORD e; //coordinate e
        e.X=45;
        e.Y=18;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),e); //SetConsoleCursorPosition(HANDLE,COORD);
        cin.getline(sr,51); // Reads a stream of characters into the string buffer, It stops when. it has read length -1
        e.X=50;
        e.Y=20;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),e);
        for(int i=0;i<50 && sr[i]!='\n';i++)
        {
            sr[i]=tolower(sr[i]);
        }


    }
 int again()
    {
        CA:
            fflush(stdin);//Its purpose is to clear (or flush) the output buffer and move the buffered data to console
        cout<<endl<<endl;
        char c; // for input choice
        cout<< " \t\t\t\t\t Type among the belows keywords to search about any information : \t\t\t\t\t \n # academic , # admission , # bank , # branch , # campus , # canteen , # career , # UPES , # company , # credit , # department , # depstar , # egovernance , \n # event , # facility , # faculty , # fee , # foyer , # ground , # hospital , # hostel , # infrastructure \n , #lab , # library , # placement , # social life , # sport , # stationary , # student , # training \n    "<<endl ;

        cout<<"\n \t\t\t\t\t    1.Search  \n \t\t\t\t\t    2.Check History \n \t\t\t\t\t    3.Clear History \n \t\t\t\t\t    4.Upload \n\t\t\t\t\t    5.Exit \n\t\t\t\t\t    \n\t\t\t\t\t  "<<endl;
        cin>>c;
        if((c=='1') || (c=='2') || (c=='3')  || (c=='4') || (c=='5')) // choices 
        {
            return c;
        }
        else
        {
            cout<<"Enter valid choice."<<endl;
            goto CA; // goto to a labeled statement in the same function
        }
    }
    void check_history();
    void clear_history();
    void formating1();
    void formating();


};

void Input::formating1()
{
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t              ##      ##                  ## ####                ########                 ########	   "<<endl;
    cout<<"\t\t\t\t\t              ##      ##                  ##    ##               ##                       ##          "<<endl;
    cout<<"\t\t\t\t\t              ##      ##                  ## ####                #####                    ########       "<<endl;
    cout<<"\t\t\t\t\t              ##      ##                  ##                     ##                             ##       "<<endl;
    cout<<"\t\t\t\t\t              ##########                  ##                     ########                 ########       "<<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t\t     ####  #####      #      ######  ######  #    #          ######  #     #  #########  #######  #     #  ######"<<endl;
    cout<<"\t\t\t\t     #     #         # #     #    #  #       #    #          #       # #   #  #             #     # #   #  #"<<endl;
    cout<<"\t\t\t\t     ####  #####    #####    ######  #       ######          ######  #  #  #  #  ######     #     #  #  #  ######"<<endl;
    cout<<"\t\t\t\t        #  #       #     #   # #     #       #    #          #       #   # #  #   # #       #     #   # #  #"<<endl;
    cout<<"\t\t\t\t     ####  #####  #       #  #  ###  ######  #    #          ######  #     #  #####   #  #######  #     #  ######"<<endl;
    cout<<"\t\t\t\t    -------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"\t\t\t\t    -------------------------------------------------------------------------------------------------------------"<<endl;
}
void Input::formating()
{
    cout<<endl<<endl;

    Sleep(300);
    cout<<"\t\t\t\t\t              ##      ##                  ## ####                ########                 ########	   "<<endl;
    Sleep(600);
    cout<<"\t\t\t\t\t              ##      ##                  ##    ##               ##                       ##          "<<endl;
    Sleep(600);
    cout<<"\t\t\t\t\t              ##      ##                  ## ####                #####                    ########       "<<endl;
    Sleep(600);
    cout<<"\t\t\t\t\t              ##      ##                  ##                     ##                             ##       "<<endl;
    Sleep(600);
    cout<<"\t\t\t\t\t              ##########                  ##                     ########                 ########       "<<endl;
    Sleep(600);
    cout<<endl<<endl;
    
    Sleep(600);
    cout<<"\t\t\t\t     ####  #####      #      ######  ######  #    #          ######  #     #  #########  #######  #     #  ######"<<endl;
    Sleep(600);
    cout<<"\t\t\t\t     #     #         # #     #    #  #       #    #          #       # #   #  #             #     # #   #  #"<<endl;
    Sleep(600);
    cout<<"\t\t\t\t     ####  #####    #####    ######  #       ######          ######  #  #  #  #  ######     #     #  #  #  ######"<<endl;
    Sleep(600);
    cout<<"\t\t\t\t        #  #       #     #   # #     #       #    #          #       #   # #  #   # #       #     #   # #  #"<<endl;
    Sleep(600);
    cout<<"\t\t\t\t     ####  #####  #       #  #  ###  ######  #    #          ######  #     #  #####   #  #######  #     #  ######"<<endl;
    Sleep(600);
    cout<<"\t\t\t\t    -------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"\t\t\t\t    -------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"\t\t\t\t                                                                                             -BY GROUP 7 (Mayank , Shekhar , Tanish ,Urviza) "<<endl;
    cout<<"\t\t\t\t                                                                                                B-tech CSE-BFSI VI"<<endl;

}  
class Search:public Input       //class search for open file
{
    public:

        void Find();
        ~Search()
        {
            
            cout<<endl<<endl;
            cout<<"\n\t\t\t\t\t\t thanks for  visit"<<endl<<endl;
            getche();
        }

};
void Search::Find()
{
    
    ifstream file;
// strlen() - this function returns length of any string
// strcmp() - this function compares two strings
// strstr() - this function check if string contains substring
    if(strstr(sr,"campus") || strstr(sr,"gate"))
    {
        file.open("campus.txt");
    }

    else if(strstr(sr,"academic") || strstr(sr,"education") ||  strstr(sr,"semester") )
    {
        file.open("academic.txt");
    }
    else if(strstr(sr,"career") || strstr(sr,"development"))
    {
        file.open("career.txt");
    }
    else if(strstr(sr,"branch") || strstr(sr,"field"))
    {
        file.open("branch.txt");
    }
    else if(strstr(sr,"library") || strstr(sr,"libraries"))
    {
        file.open("library.txt");
    }
    else if(strstr(sr,"bank") || strstr(sr,"atm") || strstr(sr,"postoffice"))
    {
        file.open("bank.txt");
    }
    else if(strstr(sr,"canteen") || strstr(sr,"cafeteria") || strstr(sr,"cafe"))
    {
        file.open("canteen.txt");
    }
    else if(strstr(sr,"admission"))
    {
        file.open("admission.txt");
    }
    else
    {
        
        cout<<"no result found ......";

    }
    
}

int main()
{
    char c; // for entering choice

    system("color E4 "); // used to change color (E(yellow)= background , 4(Red) = text)
    Search S1; // S1 is object of class Search
    S1.formating(); // for printing UPES Search engine 
    
    S1.again(); // for displaying command menu and calling any function to work again
    // do while loop executed atleast once if condition is false
    do
    {

        system("cls"); //clear the screen and move cursor to the upper left corner of screen 
        S1.formating1();

        S1.input();
        S1.Find(); // Find function is used to find the string using string compare strstr

        c=S1.again(); // if user enters same choice again
    a:
        system("cls");
        S1.formating1();
        

        if(c=='2') // for history
        {
               cout<<"In Progress";
                

        }

    b:
        system("cls");
        S1.formating1();

        if(c=='3') // for clear history
        {
            cout<<"In progress";

            
        }
    

    }while(c=='1' || c=='2' || c=='3' || c=='4'|| c=='5' ); // 1.Search 2.history 3.clear history 4.Upload 5.exit

}
