#include<fstream>
#include<string>
#include"Prerequisites.h"

LL whereItHappens(string line)
{
    int c = 0;
    LL node;
    cout<<"Start writing\n\n";
    cout<<line<<endl;
    clock_t start = clock();
    string input;
    cin.ignore();
    getline(cin,input);
    clock_t en = clock();
    for(string::iterator i = line.begin(), j = input.begin(); j != input.end(); i++, j++)
    {
        if(*i != *j)
            c++;
    }
    node.acc = 1.0 - ((double)c)/line.length();
    node.time = ((double)(en - start))/CLOCKS_PER_SEC;
    cout<<"Time : "<<node.time<<endl;
    cout<<"Accuracy : "<<node.acc<<endl;
    Sleep(5000);
    return node;
}

int SubMenu()
{
    int ch;
    cout<<"Enter\n1. Beginner\n2. Intermediate\n3. Expert\n4. Go Back\n\nChoice: ";
    cin>>ch;
    return ch;
}

LL * SearchLeast(LL * head, int menu)
{
    LL * p = head;
    LL * minnode = NULL;
    double minimum = 100000.0;
    while(p != NULL)
    {
        if(p->menu == menu)
        {
            if(p->time < minimum)
            {
                minimum = p->time;
                minnode = p;
            }
        }
        p = p->next;
    }
    return minnode;
}

void mainProgram(LL* head, string Name)
{
    int ch;
    ifstream b,i,e;
    b.open("Beginner.txt");
    i.open("Intermediate.txt");
    e.open("Expert.txt");
    do
    {
        LL node;
        system("CLS");
        ch = SubMenu();
        switch(ch)
        {
        case 1:
            {
                string line;
                getline(b,line);
                cout<< "-----------Tutorial-----------\n\n"<< endl;
                cout<< "Put Index finger of left hand on F and Index finger of right hand on J..."<< endl;
                cout<< "The buttons have a raised bar on the bottom part\n"<< endl;
                cout<< "Put the remaining fingers of left hand towards the left of F and that of right hand towards right of J"<< endl;
                cout<< "The spacebar can be held by either of the thumbs... Use only one of them\n"<< endl;
                cout<< "-----------Tutorial-----------\n"<< endl;
                Sleep(10000);
                node = whereItHappens(line);
                break;
            }
        case 2:
            {
                string line;
                getline(i,line);
                cout<< "-----------Tutorial-----------\n\n"<< endl;
                cout<< "Initially, the fingers are the same as that for beginner "<< endl;
                cout<< "The other keys can be reached by moving the fingers diagonally up or down\n"<< endl;
                cout<< "-----------Tutorial-----------"<< endl;
                Sleep(10000);
                node = whereItHappens(line);
                break;
            }
        case 3:
            {
                string line;
                getline(e,line);
                cout<< "-----------Tutorial-----------\n\n"<< endl;
                cout<< "Shift and Ctrl can be reached by stretching the left little finger"<< endl;
                cout<< "The keys to the right can be reached by stretching the right little finger\n"<< endl;
                cout<< "The numbers can be similarly reached by stretching the other fingers"<< endl;
                cout<< "-----------Tutorial-----------"<< endl;
                Sleep(10000);
                node = whereItHappens(line);
                break;
            }
        case 4: break;
        }
        if(ch != 4) head = Insert(head,Name,node.acc,node.time,ch);
    }while(ch != 4);
    b.close();
    i.close();
    e.close();
    for(int j = 1; j <= 3; j++)
    {
        LL * temp = SearchLeast(head, j);
        ofstream y;
        if(j == 1) y.open("BegPrevGames.txt", ios:: app);
        else if(j == 2) y.open("IntPrevGames.txt", ios:: app);
        else if(j == 3) y.open("AdvPrevGames.txt", ios:: app);
        if(temp)
        {
            y<< temp->name<< "#"
             << temp->acc<< " "
             << temp->time<< "\n" ;
        }
        y.close();
    }


}

void newUser()
{
    LL * head;
    head = NULL;
    string name;
    cout<<"Enter Username: ";
    cin.ignore();
    getline(cin,name);
    mainProgram(head,name);
}

void oldUser()
{
    Create();
    LL * head;
    head = NULL;
    string name, NameFromFile = "";
    cout<<"Enter Username: ";
    cin.ignore();
    getline(cin, name);
    ifstream f;
    int fl = 0;
    bool fbeg, fint, fexp; fbeg = fint = fexp = false;
    f.open("BegPrevGames.txt");
    while(true)
    {
        getline(f,NameFromFile,'#');
        //cout<< NameFromFile;
        if(NameFromFile == name)
        {
            cout<< "You have a save in Beginner"<<endl;
            fl = 1;
            fbeg = true;
            break;
        }
        if(f.eof()) break;
        getline(f,NameFromFile);
    }
    f.close();
    f.open("IntPrevGames.txt");
    while(true)
    {
        getline(f,NameFromFile,'#');
        //cout<< NameFromFile;
        if(NameFromFile == name)
        {
            cout<< "You have a save in Intermediate"<<endl;
            fl = 1;
            fint = true;
            break;
        }
        if(f.eof()) break;
        getline(f,NameFromFile);
    }
    f.close();
    f.open("AdvPrevGames.txt");
    while(true)
    {
        getline(f,NameFromFile,'#');
        //cout<< NameFromFile;
        if(NameFromFile == name)
        {
            cout<< "You have a save in Expert"<<endl;
            fl = 1;
            fexp = true;
            break;
        }
        if(f.eof()) break;
        getline(f,NameFromFile);
    }
    f.close();
    int ch = 0;
    if(fl == 0)
    {
        cout<< "You don't have a save progress...\nPress 1 to create a new user file or 0 to go back: ";
        cin>> ch;
        if(ch == 1)
        {
            newUser();
            return;
        }
        else if(ch == 0) return;
        else
        {
            cout<< "Invalid Input. Please Enter Correct Input";
            goto point1;
        }
    }

    double AccFromFile; double TimeFromFile;
    cout<< "Select the category to open"<<endl<<endl;
    point1:
    ch = SubMenu();
    switch(ch)
    {
        case 1:
            {
                if(fbeg)
                    f.open("BegPrevGames.txt");
                else
                {
                    cout<< "You dont have a save in Beginner"<<endl;
                    goto point1;
                }
                break;
            }
        case 2:
            {
                if(fint)
                    f.open("IntPrevGames.txt");
                else
                {
                    cout<< "You dont have a save in Intemediate"<<endl;
                    goto point1;
                }
                break;
            }
        case 3:
            {
                if(fexp)
                    f.open("AdvPrevGames.txt");
                else
                {
                    cout<< "You dont have a save in Expert"<<endl;
                    goto point1;
                }
                break;
            }
        case 4: return;
        default:
            {
                cout<< "Invalid Input. Please Enter Correct Input"<<endl;
                goto point1;
            }
    }
    getline(f,NameFromFile,'#');
    f>> AccFromFile;
    f>> TimeFromFile;
    head = Insert(head, NameFromFile, AccFromFile, TimeFromFile, ch);
    mainProgram(head, name);

}

void viewRecords()
{
    LL * head, * Min; int i = 1;
    head = NULL;
    string NameFromFile; double AccFromFile; double TimeFromFile;
    ifstream f;
    point2:
    system("CLS");
    int ch = SubMenu();
    switch(ch)
    {
        case 1: {f.open("BegPrevGames.txt"); break; }
        case 2: {f.open("IntPrevGames.txt"); break; }
        case 3: {f.open("AdvPrevGames.txt"); break; }
        default: {cout<< "Invalid Input. Please Enter Correct Input."; goto point2; }
    }
    while(true)
    {
        getline(f,NameFromFile,'#');
        if(f.eof()) break;
        f>> AccFromFile;
        f>> TimeFromFile;
        head = Insert(head, NameFromFile, AccFromFile, TimeFromFile, ch);
    }
    cout<< "Sl. No.\t\tName\t\tTime\t\tAccuracy\n";
    Min = head;
    while(Min)
    {
         cout<< i << "\t\t" << Min->name << "\t\t" << Min->time << "\t\t" << Min->acc << endl;
         Min = Min->next;
         i++;
    }
    cout<< "Press any key to return: ";
    string anyKey;
    cin>> anyKey;
}

int Menu()
{
    int ch;
    cout<<"Welcome to Typing Tutor\n\n\n1. New User\n2. Existing User\n3. View Records\n4. Exit\n\n CHOICE: ";
    cin>>ch;
    return ch;
}
int main()
{
    while(true)
    {
        system("CLS");
        switch(Menu())
        {
        case 1:
            newUser();
            break;
        case 2:
            oldUser();
            break;
        case 3:
            viewRecords();
            break;
        case 4:
            exit(0);
        default: cout<<"Input Entered is invalid, please enter a Valid Input"<<endl;
        }
    }
}

