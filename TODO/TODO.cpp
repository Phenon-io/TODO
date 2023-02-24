/* -----------------------------------------------------------------------------
FILE NAME:         Polynomial.cpp

DESCRIPTION:       test program for polynomials implemented as structures
USAGE:             ./Polynomial.cpp
COMPILER:          GNU g++ compiler on Linux
NOTES:             Handles a basic polynomial array with pointers

MODIFICATION HISTORY:
Author               Date               Version
------------------   ----------         --------------
Nicholas Whitehorn    2023-02-17        1.0.00
Nicholas Whitehorn    2023-02-22        2.0.00
Nicholas Whitehorn    2023-02-23        2.1.00

CHANGELOG:
Version      Description
-------      ---------------------------------------------------
1.0.00	 Initial writeup - skeleton of class structures and some implementation
2.0.00	 Class object updates
2.1.00	 Main function writeup

----------------------------------------------------------------------------- */
#include "Todo.h"

int main()
{
    ToDoList<listType> list = ToDoList<listType>();

    menu(list);




    return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          display()
DESCRIPTION:       Grouped display functions for common templates
RETURNS:           nothing
NOTES:             Behavior defined by client
------------------------------------------------------------------------------- */
void display(ostream& out, ToDoList<listType> list) {
    if (!list.isEmpty()) {
        for (int i = 1; i < list.getLength(); i++) {
            out << i << ") " << list.getEntry(i) << endl;
        }
        return;
    }
}
/* -----------------------------------------------------------------------------
FUNCTION:          menu()
DESCRIPTION:       Shows an interactive menu
RETURNS:           nothing(void)
NOTES:
------------------------------------------------------------------------------- */
void menu(ToDoList<listType> l)
{
    bool loop = true;
    char choice;
    string outfileName = "NewTodo.txt";
    int priority, pos;
    listType task;
    
    while (loop)
    {
        choice = menu_gui();     //shows menu
        switch (choice)
        {
        case '1':
            display(cout, l);
            if (l.isEmpty()) cout << "No current tasks" << endl;
            priority = getPriority();
            task = getTask();
            break;
        case '2':
            display(cout, l);
            pos = getPos();
            break;
        case '3':
            display(cout, l);
            break;
        case '4':
            display(cout, l);
            l.clear();
            break;
        case '0':
            loop = confirm_quit(outfileName, &l);
            break;

        default:
            cout << "You did not enter a valid option. "
                << "Please select a valid option." << endl;
            break;
        }
    }
}

/* -----------------------------------------------------------------------------
FUNCTION:          getPriority()
DESCRIPTION:       Simple cout cin to user
RETURNS:           int
NOTES:             
------------------------------------------------------------------------------- */
int getPriority() {
    int priority;
    cout << "What is the priority of your new task?" << endl;
    cin >> priority;
    return priority;
}
/* -----------------------------------------------------------------------------
FUNCTION:          getTask()
DESCRIPTION:       Simple cout cin to user
RETURNS:           int
NOTES:
------------------------------------------------------------------------------- */
listType getTask() {
    listType task;
    cout << "What is your new task?" << endl;
    cin >> task;
    return task;
}
/* -----------------------------------------------------------------------------
FUNCTION:          getPos()
DESCRIPTION:       Simple cout cin to user
RETURNS:           int
NOTES:
------------------------------------------------------------------------------- */
int getPos() {
    int pos;
    cout << "Which task would you like to complete?" << endl;
    cin >> pos;
    return pos;
}

/* -----------------------------------------------------------------------------
FUNCTION:          menu_gui()
DESCRIPTION:       Shows an interactive menu
RETURNS:           char choice
NOTES:             returns a single character for menu logic
------------------------------------------------------------------------------- */
char menu_gui()
{
    int size1 = 8, size2 = 20;
    char choice;
    char title[] = "To-do List Menu";
    char menu1[] = "1) Create new list item\n";
    char menu2[] = "2) Complete (remove) item\n";
    char menu3[] = "3) Display list\n";
    char menu4[] = "4) Write an accounting report to the screen and a file.\n";
    char menu5[] = "0) Quit program\n";

    char uinput[] = "Enter your choice: [0-4]: ";
    Title_Format(title);
    Menu_Format(menu1);
    Menu_Format(menu2);
    Menu_Format(menu3);
    Menu_Format(menu4);
    Menu_Format(menu5);
    Title_Format(uinput);
    cout << "Choice: ";

    cin >> choice;
    choice = toupper(choice);
    cout << endl;
    //     cout << "echo choice: " << choice << endl;

    return choice;

}


/* -----------------------------------------------------------------------------
FUNCTION:          Menu_Format();
DESCRIPTION:       Formats the main menu and power menu items
RETURNS:           Nothing (void)
NOTES:             Sets max length, outputs to console, continues Main_Menu();
------------------------------------------------------------------------------- */

void Menu_Format(char* a)
{
    cout << setw(25) << setfill(' ') << left << a;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Title_Format();
DESCRIPTION:       Formats the main menu and power menu items
RETURNS:           Nothing (void)
NOTES:             Sets max length, outputs to console, continues Main_Menu();
------------------------------------------------------------------------------- */

void Title_Format(char* a)
{
    cout << endl << setw(47) << setfill('-') << " " << endl;
    cout << setw(25) << setfill(' ') << right << a << endl;
    cout << setw(47) << setfill('-') << " " << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          confirm_quit()
DESCRIPTION:       confirm if the user would like to quit, asks for file to write to
RETURNS:           bool loop
NOTES:             Also connects to the print out functions
------------------------------------------------------------------------------- */
bool confirm_quit(string outfile, ToDoList<listType>* l)
{
    bool loop = true;
    char conf;
    cout << "Are you sure you would like to quit? [Y/N]: ";
    cin >> conf;

    conf = toupper(conf);

    if (conf != 'N')
    {
        loop = false;
    }
    else cout << "Returning to menu" << endl;

    return loop;
}

