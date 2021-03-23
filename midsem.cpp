#include<string.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<mmsystem.h>
using namespace std;
class Input
{
protected:
    char sr[50];  //sr for search
public:
void input()
    {
        fflush(stdin);
        cout<<"\t\t\t\t\t    ##########################################\n";
        cout<<"\t\t\t\t\t    ##  Press any key to start searching    ##\n    ";
        cout<<"\t\t\t\t\t    ##########################################\n";
        
        getche();
        system("cls");
        formating1();
        cout<<"\t\t\t\t\t    ###########################################################################################\n";
        cout<<"\t\t\t\t\t    #";
        cout<<"\t\t\t\t\t                                                      #\n";
        cout<<"\t\t\t\t\t    ###########################################################################################\n";
        COORD e;
        e.X=45;
        e.Y=18;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),e);
        cin.getline(sr,51);
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
            fflush(stdin);
        cout<<endl<<endl;
        char c;
        cout<< " \t\t\t\t\t Type among the belows keywords to search about any information : \t\t\t\t\t \n # academic , # admission , # bank , # branch , # campus , # canteen , # career , # UPES , # company , # credit , # department , # depstar , # egovernance , \n # event , # facility , # faculty , # fee , # foyer , # ground , # hospital , # hostel , # infrastructure \n , #lab , # library , # placement , # social life , # sport , # stationary , # student , # training \n    "<<endl ;

        cout<<"\n \t\t\t\t\t    1.Search  \n \t\t\t\t\t    2.Check History \n \t\t\t\t\t    3.Clear History \n \t\t\t\t\t    4.Upload \n\t\t\t\t\t    5.End \n\t\t\t\t\t    \n\t\t\t\t\t  "<<endl;
        cin>>c;
        if((c=='1') || (c=='2') || (c=='3')  || (c=='4') || (c=='5'))
        {
            return c;
        }
        else
        {
            cout<<"Enter valid choice."<<endl;
            goto CA;
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
    cout<<"\t\t\t\t                                                                                             -BY GROUP 8 (Mayank , Shekhar , Tanish ,Urviza) B-tech CSE-BFSI VI  "<<endl;
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
    int a ;
    ifstream file;

    if(strstr(sr,"campus") || strstr(sr,"gate"))
    {
        file.open("campus.txt");
    }

    else if(strstr(sr,"academic") || strstr(sr,"education") ||  strstr(sr,"semester") )
    {
        file.open("academic.txt");
    }

    else if(strstr(sr,"branch") || strstr(sr,"field"))
    {
        file.open("branch.txt");
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
        f:
        a=1;
        cout<<"no result found ......";

    }
    if(a==1)
    {
        
    }
    else
    {
        Sleep(800);
        cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        char c;
        while(!(file.eof()))
        {
            file.get(c);
            cout<<c;
        }
        cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    }
}

int main()
{
    char c;

    system("color E4 ");
    Search S1;
    S1.formating();
    
    S1.again();

    do
    {

        system("cls");
        S1.formating1();

        S1.input();
        S1.Find();

        c=S1.again();
    a:
        system("cls");
        S1.formating1();
        

        if(c=='2')
        {
               cout<<"In Progress";
                getche();

                system("cls");
                S1.formating1();
                c=S1.again();

                if(c=='2')
                    goto a;

        }

    b:
        system("cls");
        S1.formating1();

        if(c=='3')
        {
            cout<<"In progress";

            cout<<"History is cleared."<<endl;

            getche();
            system("cls");

            S1.formating1();
            c=S1.again();

            if(c=='3')
                goto b;
                if(c=='2')
                    goto a;
        }
    

    }while(c=='1' || c=='2' || c=='3' || c=='5' );

}