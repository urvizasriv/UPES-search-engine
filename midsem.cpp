#include<string.h> // for strstr or string functions
#include<iostream> // cin cout 
#include<conio.h> // getche 
#include<windows.h> // system.(color E4)
#include<fstream> // fstream : ifstream(input , write) , ofstream(output, read)
#include<stdio.h> //fflush()
#include<stdlib.h> //goto
#include<dirent.h>
using namespace std; // standard library (with the same name available in different libraries) if we do not use it we have to write std:: 
class List{

private:
    struct dataB{ //node
        string name;
        int open; //1 if open 0 if closed
        dataB *next;
    };
    // initializing node variables to go through linked list and search
    dataB *head;
    dataB *curr;
    dataB *temp;

public:
    List();
    void insert(string name, int open);
    bool search(string fName);
    void createDB();
    void openDB();
    int menu();
}; //end class
List::List(){
    head = NULL;
    curr = NULL;
    temp = NULL;
}
void List::insert(string name, int open){
    dataB *n = new dataB;
    n->next = NULL;
    n->name = name;
    n->open = open;

    if(head != NULL){ // if already things in list put it last
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = n; // always puts new node at the end
    }
    else{ // if no list, make new node the start of list
        head = n;
    }
}
bool List::search(string fName){
   curr = head;
   while(curr != NULL) {
      if (fName == curr->name){

         // If a match is found, return true
         // There is no need to continue any more checks.
         return true;
      }
   }

   // If we come here, there is no match.
   // Return false.
   return false;
}



    void List::createDB() {
        //this function creates a new file
    ofstream db;
    string fileName;

    
    cout << "Enter the name of the database you want to create: \n";
    getline (cin, fileName);

    
    if(this->search(fileName) == false){ 
        db.open(fileName.c_str());
        cout << "\nYour database " << fileName << " was created successfully\n";

        
        this->insert(fileName, 0);
    }

    
    else{
        cout << "\nCould not create database because database name is already taken\n";
    }

    

    db.close();
}



void List::openDB() {
    //this function displays the contents of the file
    // need to add check to see if one is already open
    fstream db;
    
    char ch;
    string filename;
    cout << "Enter the name of the database you want to open: ";
    getline (cin, filename);
    db.open(filename, fstream::in);
    cout<<"\nContent of "<<filename<<":-\n";
    while(db>>noskipws>>ch)
        cout<<ch;
    db.close();
    cout<<endl;
    //return 0;

}





void display() {
    //function to display all the files present in the directory where this code is present
    struct dirent *d;
    DIR *dr;
    dr = opendir(".");
    if(dr!=NULL)
    {
        cout<<"List of Files & Folders:-\n";
        for(d=readdir(dr); d!=NULL; d=readdir(dr))
        {
            cout<<d->d_name<<endl;
        }
        closedir(dr);
    }
    else
        cout<<"\nError Occurred!";
    cout<<endl;

}



void add() { 
// function to write into file explicitely
    cout<<"Here you can write your contents into the file implicitly , otherwise just open the file and write into it \n \n";
    char fname[20], str[200];
    fstream fp;
    cout<<"Enter the Name of File: ";
    gets(fname);
    fp.open(fname, fstream::out);
    if(!fp)
    {
        cout<<"\nError Occurred!";
        
    }
    cout<<"Enter the Data: ";
    gets(str);
    while(strlen(str)>0)
    {
        fp<<str;
        fp<<"\n";
        gets(str);
    }
    fp.close();
    cout<<endl;

}

void del() {
    //function to delete the file
    int status;
    char fileName[20];
    cout<<"Enter the Name of File: ";
    cin>>fileName;
    status = remove(fileName);
    if(status==0)
        cout<<"\nFile Deleted Successfully!";
    else
        cout<<"\nErorr Occurred!";
    cout<<endl;
    

}

int List::menu() {
    cout << "Enter the number of the operation you wish to perform (1-5)\n"
    << "1. Create new File\n"
    << "2. Open the contents of File \n"
    << "3. Display all the files of database present in current directory\n"
    << "4. Write into the file implicitly\n"
   
    << "5. Quit\n";

    int sel = 0;
    (std::cin >> sel).ignore();

    switch (sel) {
        case 1: createDB();
            menu(); // after creating file go back to list of options
            break;

        case 2: openDB();
            menu();
            break;



        case 3: display();
           menu();
            break;

        

        

        case 4: add();
           menu();
            break;

        

        case 5: return 0;
            break;

        default: cout << "Please try again and enter a valid number\n\n";
            menu();
            break;
    }
    return true; // to avoid error saying control may reach end of non-void function
}







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
    cout<<"\t\t\t\t\t              ##      ##                  ##########             ###    ###               ########	   "<<endl;
    cout<<"\t\t\t\t\t              ##      ##                      ##                 ## #  # ##               ##          "<<endl;
    cout<<"\t\t\t\t\t              ##      ##                      ##                 ##  ##  ##               ########       "<<endl;
    cout<<"\t\t\t\t\t              ##      ##                      ##                 ##      ##                     ##       "<<endl;
    cout<<"\t\t\t\t\t              ##########                      ##                 ##      ##               ########       "<<endl;
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
    cout<<endl<<endl;
    
    cout<<"\t\t\t\t\t              ##      ##                  ##########             ###    ###               ########	   "<<endl;
    Sleep(600);
    cout<<"\t\t\t\t\t              ##      ##                      ##                 ## #  # ##               ##          "<<endl;
    Sleep(600);
    cout<<"\t\t\t\t\t              ##      ##                      ##                 ##  ##  ##               ########       "<<endl;
    Sleep(600);
    cout<<"\t\t\t\t\t              ##      ##                      ##                 ##      ##                     ##       "<<endl;
    Sleep(600);
    cout<<"\t\t\t\t\t              ##########                      ##                 ##      ##               ########       "<<endl;
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


void Input::check_history()
{
    ifstream history("history.txt");
        char c;
        history.get(c);
        while(!(history.eof()))
        {
            history.get(c);
            cout<<c;
        }
    history.close();
}


void Input::clear_history()
{
    ofstream history("history.txt");
    history.close();
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
    else if(strstr(sr,"faculty")||strstr(sr,"professor")||strstr(sr,"faculties"))
    {
        file.open("faculty.txt");
    }
    else if(strstr(sr,"fee"))
    {
        file.open("fee.txt");
    }
    else if(strstr(sr,"hostel") || strstr(sr,"girl"))
    {
        file.open("hostel.txt");
    }
    else if(strstr(sr,"ground"))
    {
        file.open("ground.txt");
    }
    else if(strstr(sr,"event")|| strstr(sr,"workshop") || strstr(sr,"spoural") || strstr(sr,"cognizance"))
    {
        file.open("event.txt");
    }
    else if(strstr(sr,"transport")|| strstr(sr,"bus") )
    {
        file.open("transport.txt");
    }
    else if(strstr(sr,"sport"))
    {
        file.open("sport.txt");
    }
    else if(strstr(sr,"stationary") || strstr(sr,"stationaries"))
    {
        file.open("stationary,txt");
    }
    else if(strstr(sr,"egovernance"))
    {
        file.open("egovernance.txt");
    }
    else if(strstr(sr,"library") || strstr(sr,"libraries"))
    {
        file.open("library.txt");
    }
    else if(strstr(sr,"branch") || strstr(sr,"field"))
    {
        file.open("branch.txt");
    }
    else if(strstr(sr,"bank") || strstr(sr,"atm") || strstr(sr,"postoffice"))
    {
        file.open("bank.txt");
    }
    else if(strstr(sr,"academic") || strstr(sr,"education") ||  strstr(sr,"semester") )
    {
        file.open("academic.txt");
    }
    else if(strstr(sr,"student") || strstr(sr,"boy"))
    {
        file.open("student.txt");
    }
    else if(strstr(sr,"canteen") || strstr(sr,"cafeteria") || strstr(sr,"cafe"))
    {
        file.open("canteen.txt");
    }
    else if(strstr(sr,"career") || strstr(sr,"development"))
    {
        file.open("career.txt");
    }
    else if(strstr(sr,"credit") || strstr(sr,"grade") ||  strstr(sr,"result"))
    {
        file.open("credit.txt");
    }
    else if(strstr(sr,"egovernance"))
    {
        file.open("egovernance.txt");
    }
    else if(strstr(sr,"department") || strstr(sr,"building") || strstr(sr,"admin"))
    {
        file.open("department.txt");
    }
    else if(strstr(sr,"lab") || strstr(sr,"laboratory"))
    {
        file.open("lab.txt");
    }
    else if(strstr(sr,"admission"))
    {
        file.open("admission.txt");
    }
    else if(strstr(sr,"rpcp") || strstr(sr,"pdpi") || strstr(sr,"cmpica") || strstr(sr,"i2im"))
    {
        file.open("department.txt");
    }
    else if(strstr(sr,"arip") || strstr(sr,"mtin") || strstr(sr,"chandubhai"))
    {
        file.open("department.txt");
    }
    else if(strstr(sr,"event"))
    {
        file.open("event.txt");
    }
    else if(strstr(sr,"foyer") || strstr(sr,"reading"))
    {
        file.open("foyer.txt");
    }
    else if(strstr(sr,"ground"))
    {
        file.open("ground.txt");
    }
    else if(strstr(sr,"hospital") || strstr(sr,"health"))
    {
        file.open("hospital.txt");
    }
    else if(strstr(sr,"infrastructure"))
    {
        file.open("infrastructure.txt");
    }
    else if(strstr(sr,"placement") || strstr(sr,"company") || strstr(sr,"companies"))
    {
        file.open("placement.txt");
    }
    else if(strstr(sr,"social"))
    {
        file.open("social life.txt");
    }
    else if(strstr(sr,"sport") || strstr(sr,"activity") || strstr(sr,"activities") || strstr(sr,"cricket"))
    {
        file.open("sport.txt");
    }
    else if(strstr(sr,"chess") || strstr(sr,"ball") || strstr(sr,"carrom") || strstr(sr,"tennis") || strstr(sr,"gym"))
    {
        file.open("sport.txt");
    }
    else if(strstr(sr,"stationary") || strstr(sr,"stationaries") || strstr(sr,"material") || strstr(sr,"reprograph"))
    {
        file.open("stationary.txt");
    }
    else if(strstr(sr,"training"))
    {
        file.open("training.txt");
    }
    else if(strstr(sr,"transport") || strstr(sr,"bus"))
    {
        file.open("transport.txt");
    }
    else if(strstr(sr,"wifi") || strstr(sr,"enternet")|| strstr(sr,"wincell") || strstr(sr,"sophos"))
    {
        file.open("wifi.txt");
    }
    else if(strstr(sr,"depstar") || strstr(sr,"devang"))
    {
        file.open("depstar.txt");
    }
    else if(strstr(sr,"cspit") || strstr(sr,"chandubhai"))
    {
        file.open("cspit.txt");
    }
     else if(strstr(sr,"game") || strstr(sr,"movie") || strstr(sr,"facebook") || strstr(sr,"fb") || strstr(sr,"insta"))
    {
       //PlaySound(TEXT("funny.wav"),NULL,SND_SYNC);
       goto f;
    }
     else if(strstr(sr,"UPES") || strstr(sr,"university") ||  strstr(sr,"petroleum"))
    {
        file.open("UPES .txt");
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
        

        if(c=='2')
        {
                S1.check_history();
                getche();

                system("cls");
                S1.formating1();
                c=S1.again();

                if(c=='2')
                    goto a;
                if(c=='4')
                   goto c; 

    b:
        S1.clear_history();

            cout<<"History is cleared."<<endl;

            getche();
            system("cls");

            S1.formating1();
            c=S1.again();

            if(c=='3')
                goto b;
                if(c=='2')
                    goto a;
                if(c=='4')
                    goto c; 
                    
        }
    c:
    {
          if(c=='4')
          {
          List list;
          list.menu();
          return 0;
          }
          
    }
    

    }while(c=='1' || c=='2' || c=='3' || c=='4' ); // 1.Search 2.history 3.clear history 4.Upload 5.exit
       }
