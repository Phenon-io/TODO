#ifndef TO_DO
#define TO_DO

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "ToDoList.h"
using namespace std;

// Set type of list here, sort of like templating for non class items 
typedef string listType;

//Function Prototypes
void display(ostream& out, ToDoList<listType> list);
void menu(ToDoList<listType> l);
int getPriority();
listType getTask();
int getPos();
char menu_gui();
void Menu_Format(char* a);
void Title_Format(char* a);
bool confirm_quit(string outfile, ToDoList<listType>* l);


#endif