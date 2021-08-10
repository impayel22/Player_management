#include<iostream>
#include<fstream> // #File Handling  fstream, ifstream, ofstream
#include<string>   //#string manipulation
#include<stdlib.h>
#include<conio.h>  //#clrscr() function



// Here input();   Takes the Input of Player Information from user
// And output();  Shows the last input information of Player
// And writeInFile(); Writes the Input information into the File "PlayersRecord.txt"
// Also searchInRecord();  Searches the information such as PlayerName, PlayerId in the File "PlayersRecord.txt"
// deleteInRecord();  Deletes the Player's Record using PlayerName
// showAllRecords();  Shows complete Player's Records
// clearCompleteDatabase(); Clears the complete Player's Record Database

using namespace std;

class file
{
    private:
        int playerid;
        int DoB;
        string playerName;
        int age;
        int RoT;
        int RoD;
        int Ro20;


    public:

//This function takes input from user and stored in the File using writeFile() function
        void input(){

            cout<<"\nEnter player id no: ";
            cin>>playerid;
            cout<<"\nEnter player Date of Birth: ";
            cin>>DoB;
            cout<<"\nEnter player age: ";
            cin>>age;

//Taking input of Player Name as First Name and Last Name
            string strFname="", strLname="";
            cout<<"\nEnter the First Name of Player: ";
            cin>>strFname;
            cout<<"\nEnter the Last Name of Player: ";
            cin>>strLname;
            playerName = strFname +" "+ strLname;

            cout<<"\nEnter player rankings of Test: ";
            cin>>RoT;
            cout<<"\nEnter player rankings of one day internationals: ";
            cin>>RoD;
            cout<<"\nEnter player rankings of T20 internationals.: ";
            cin>>Ro20;

        }

        void output(){
            cout<<"\nPlayer Details: \n";
            cout<<"playerid==>"<<playerid<<endl;
            cout<<"DoB==>"<<DoB<<endl;
            cout<<"player age==>"<<age<<endl;
            cout<<"player name==>"<<playerName<<endl;
            cout<<"rankings of test==>"<<RoT<<endl;
            cout<<"rankings of day==>"<<RoD<<endl;
            cout<<"rankings of t20==>"<<Ro20<<endl;

        }



        string retplayername(){
            return playerName;
        }


        int retdob(){
            return DoB;
        }

        int retplayerid(){
            return playerid;
        }

        int retage(){
            return age;
        }

        int retrot(){
            return RoT;
        }

        int retrod(){
            return RoD;
        }

        int retro20(){
            return Ro20;
        }
        };

//This function  used to write the details in the file and it also takes details of class instance and append that into the file

void writeInFile(file fobj){

    char arr[]= "     ";
    ofstream fout;
    fout.open("PlayersRecord.txt", ios::out | ios::app);

    fout<<"id";
    fout<<fobj.retdob();fout<<arr;
    fout<<fobj.retage();fout<<arr;
    fout<<fobj.retplayername();fout<<arr;
    fout<<fobj.retrot();fout<<arr;
    fout<<fobj.retrod();fout<<arr;
    fout<<fobj.retro20();fout<<arr;


    fout.close();

}

//This functions shows all the Players record which  stored in this file

void showAllRecords(){

    ifstream readFile;
    readFile.open("PlayersRecord.txt");
    char charsInLine[1024];
    int count=0;
    cout<<"Players records :\n\n";
    while(!readFile.eof()){
        readFile.getline(charsInLine,1024);
        cout<<charsInLine<<endl;
    }
    readFile.close();

}
//This function which deletes the Record of Player from Playersrecord.txt file by using player name
//The bool function checks wheather Player Record is there or not


void deleteInRecords(){

    string deleteString;
    string strFname="", strLname="";

        cout<<"Enter the First Name of Player: ";
        cin>>strFname;
        cout<<"\nEnter the Last Name of Player: ";
        cin>>strLname;
        deleteString = strFname+"_"+strLname;
        cout<<"deleteString: "<<deleteString<<endl;



    ifstream readFile;
    ofstream writeFile("sample.txt");

    char charsInLine[1024];

    readFile.open("PlayersRecord.txt");

    int count=0;
    bool found = false;

    while(!readFile.eof()){

        readFile.getline(charsInLine,1024);
        string strLine(charsInLine);
        cout<<count<<": "<<charsInLine<<endl;

        size_t found = strLine.find(deleteString);

        if(found != string::npos){

            found = true;
            break;
        }


        else{
            writeFile<<charsInLine;
            writeFile<<"\n";

        }
        count++;

    }

    readFile.close();
    writeFile.close();

//Here we delete the Playersrecord.txt file since unmatched content is copied to sample.txt file and rename sample.txt as PlayersRecord.txt

    remove("PlayersRecord.txt");
    rename("sample.txt", "PlayersRecord.txt");

    if(found == false){
       cout<<"No records available...!\n";
    }
}



//This function finds the Player record by using the PlayerId and PlayerName.


void searchInRecords(int choice){
    string searchString="";
    string strFname="", strLname="";

    switch(choice){

        case 1:
                cout<<"Enter the First Name of Player: ";
                cin>>strFname;
                cout<<"Enter the Last Name of Player: ";
                cin>>strLname;
                searchString = strFname+" "+strLname;
                cout<<"Search String: "<<searchString<<endl;
                break;

        case 2:
                cout<<"Enter the Player Id: ";
                cin>>searchString;
                searchString = "id"+searchString;
                cout<<"Search String: "<<searchString<<endl;
                break;

        case 3: cout<<"Wrong Input..! Enter your choice again...\n";
                break;

    }


    ifstream readFile;
    readFile.open("PlayersRecord.txt");
    char charsInLine[1024];
    int count=0;
    searchString = searchString+" ";

    while(!readFile.eof()){
        readFile.getline(charsInLine, 1024);


        string strLine(charsInLine);

        size_t found = strLine.find(searchString);

        if(found!= string::npos){
            count++;
            cout<<"Records "<<count<<" : "<<charsInLine<<endl;
        }
    }

    readFile.close();
    if( count == 0 )
        cout<<"NO records found...!\n";
    else{
        cout<<"No. of Records found for "<<searchString<<": "<<count<<endl;
    }
}



//This function is used to completely delete the Player Database

void clearCompleteDatabase(){
    int x;
    cout<<"Do you want to delete the complete database of Players...?\n Press 1 to confirm: ";
    cin>>x;

    if(x==1){
        remove("PlayersRecord.txt");
        ofstream writeFile("PlayersRecord.txt");
        writeFile.close();
    }
}





int main(){

    file fileobj;

    while(1){
        int choice;
        cout<<"\n\n***=============== Bangladesh National Cricket Team===================***";
        cout<<"\n1: Add a new Player Record";
        cout<<"\n2: Show all Players Record";
        cout<<"\n3: Delete Player by its Player Name from Record";
        cout<<"\n4: Search Player using Player Name";
        cout<<"\n5: Search Player using Player Id";
        cout<<"\n6: Clear the complete database of Player's Record";
        cout<<"\n7: Exit from Program";

        cout<<"\n\nEnter your choice...!\n";
        cin>>choice;
        system("cls");

        switch(choice){

            case 1: fileobj.input();
                    writeInFile(fileobj);
                    break;
            case 2: showAllRecords();
                    break;

            case 3: deleteInRecords();
                    break;
            case 4: searchInRecords(1);
                    break;
            case 5: searchInRecords(2);
                    break;
            case 6: clearCompleteDatabase();
                    break;
            case 7: cout<<"Exiting from program...\n";
                     exit(0);
            default: cout<<"Wrong Choice..! enter your choice again...\n";
                     break;

        }
   }

}