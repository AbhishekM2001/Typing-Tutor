#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;

struct LL
{
    int menu;
    string name;
    double time;
    double acc;
    LL * next;
};


LL* Insert(LL*, string, double, double, int);
LL * Delete(LL*, string);
LL * Search(LL*, string);

void Create();
void newUser();
void oldUser();
void viewRecords();
