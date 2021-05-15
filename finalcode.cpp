#include<string.h> // for strstr or string functions
#include<iostream> // cin cout 
#include<conio.h> // getche 
#include<windows.h> // system.(color E4)
#include<fstream> // fstream : ifstream(input , write) , ofstream(output, read)
#include<stdio.h> //fflush()
#include<stdlib.h> //goto
#include<dirent.h> // used to display all files in currrent directory 
using namespace std; // standard library (with the same name available in different libraries) if we do not use it we have to write std:: 

class List{

private:
    struct dataB{ //node
        string name;
        int open; //1 if open 0 if closed
        dataB *next; // pointer to next node
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
    dataB *n = new dataB;  // everytime you call this function it will create new linked list
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
    ofstream db; // create file 
    string fileName;

    
    cout << "Enter the name of the file you want to create: \n";
    getline (cin, fileName);

    
    if(this->search(fileName) == false){ 
        db.open(fileName.c_str()); // c_str is used to convert the argument into c-string in order to open file in latest c++ version
        cout << "\nYour file " << fileName << " was created successfully\n";

        
        this->insert(fileName, 0);
    }

    
    else{
        cout << "\nCould not create file because file name is already taken\n";
    }

    

    db.close();
}



void List::openDB() {
    //this function displays the contents of the file
    // need to add check to see if one is already open
    fstream db; // open file in read mode
    
    char ch;
    string filename;
    cout << "Enter the name of the file you want to open: ";
    getline (cin, filename);
    db.open(filename, fstream::in); // fstream::in means open file for reading: the internal stream buffer supports input operations.
    cout<<"\nContent of "<<filename<<":-\n";
    while(db>>noskipws>>ch) // noskipws : it does not skip any number of whitespaces before the next input. Tab spaces, blank spaces and carriage returns are considered whitespaces.
        cout<<ch;
    db.close();
    cout<<endl;
    //return 0;

}





void display() {
    //function to display all the files present in the directory where this code is present
    struct dirent *d;        // inbuilt structure for directory read
    DIR *dr;                // DIR is a type representing a directory stream.    Declare a poniter dr to the DIR type.
    dr = opendir(".");      // function to open all file in present directory
    if(dr!=NULL)            // check if directory is not null / empty
    {
        cout<<"List of Files & Folders:-\n";
        for(d=readdir(dr); d!=NULL; d=readdir(dr))  // readdir returns a null pointer upon reaching the end of the directory stream.
        {
            cout<<d->d_name<<endl; // d_name is specified under structure dirent
        }
        closedir(dr);
    }
    else
        cout<<"\nError Occurred!";
    cout<<endl;

}



void add() { 
// function to write into file explicitely
    cout<<"Here you can write your contents into the file implicitly , \n otherwise you can also just open the file from your system and write into it \n \n";
    char fname[20], str[200];
    fstream fp;
    cout<<"Enter the Name of File: ";
    gets(fname);
    fp.open(fname, fstream::out); // File open for writing: the internal stream buffer supports output operations.
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


int List::menu() {
    cout << "Enter the number of the operation you wish to perform (1-5)\n"
    << "1. Create new File\n"
    << "2. Write into the file implicitly\n"
    << "3. Display all the files of database present in current directory\n"
    << "4. Open the contents of File \n"
    << "5. Quit\n";

    int sel = 0; // sel = select
    (std::cin >> sel).ignore();

    switch (sel) {
        case 1: createDB();
            menu(); // after creating file go back to list of options
            break;
        case 2: add();
            menu();
            break;
        case 3: display();
           menu();
            break;
        case 4: openDB();
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
        
        ofstream history("history.txt",ios::app); // append the searched contents into history.txt
        history<<"-->";

        for(int i=0;i<50 && sr[i]!='\0';i++)
        {
            history<<sr[i];
        }

        history<<endl;

        history.close();


    }
 int again()
    {
        CA:
            fflush(stdin);//Its purpose is to clear (or flush) the output buffer and move the buffered data to console
        cout<<endl<<endl;
        char c; // for input choice
        cout<< " \t\t\t\t\t     #################################################################################\n " ;
        cout<< " \t\t\t\t\t     #          Type among the belows keywords to search about any information       #\n " ;
        cout<< " \t\t\t\t\t     # ------------------------------------------------------------------------------#\n " ;
        cout<< " \t\t\t\t\t     # *academic , *admission ,*bank ,*branch , *campus , *canteen ,*lab, *career    #\n " ;
        cout<< " \t\t\t\t\t     # *event ,*facility ,*faculty ,*fee ,*ground ,*infirmary ,*hostel ,*library     #\n " ;
        cout<< " \t\t\t\t\t     # *placement ,*social life,*stationary ,*placement ,*training,*exchange program #\n " ;
        cout<< " \t\t\t\t\t     # *career ,*company ,*credit ,*department ,*food court,*infrastructure,*sport   #\n " ;
        cout<< " \t\t\t\t\t     #################################################################################\n " ;
       

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
    cout<<"\t\t\t\t                                                                 -BY GROUP 7 (Mayank , Shekhar , Tanish ,Urviza) "<<endl;
    cout<<"\t\t\t\t                                                                                               B-tech CSE-BFSI VI"<<endl;

}  


void Input::check_history()
{
    ifstream history("history.txt"); // create a file history.txt
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
    else if(strstr(sr,"Student exchange"))
    {
        file.open("student_exchange.txt");
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
    else if(strstr(sr,"placement") || strstr(sr,"boy"))
    {
        file.open("placement.txt");
    }
    else if(strstr(sr,"canteen") || strstr(sr,"cafeteria") || strstr(sr,"cafe") || strstr(sr , "food court"))
    {
        file.open("food_court.txt");
    }
    else if(strstr(sr,"career") || strstr(sr,"development"))
    {
        file.open("career.txt");
    }
    else if(strstr(sr,"credit") || strstr(sr,"grade") ||  strstr(sr,"result"))
    {
        file.open("credit.txt");
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
    else if(strstr(sr,"rpcp") || strstr(sr,"pdpi") || strstr(sr,"cmpica") || strstr(sr,"i2im") || strstr(sr , "department"))
    {
        file.open("department.txt");
    }
    
    else if(strstr(sr,"event"))
    {
        file.open("event.txt");
    }
    
    else if(strstr(sr,"ground"))
    {
        file.open("ground.txt");
    }
    else if(strstr(sr,"hospital") || strstr(sr,"health") || strstr(sr , "infirmary"))
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
   else if(strstr(sr,"game") || strstr(sr,"movie") || strstr(sr,"facebook") || strstr(sr,"fb") || strstr(sr,"insta"))
    {
       
       goto f;
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
        }
    b:
        system("cls");
        S1.formating1();

        if(c=='3')
        {
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
