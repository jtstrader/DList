#include<iostream>
#include<vector>
#include<string>
#include<exception>
#include<stdexcept>
#include "dlist.h"

typedef int ItemType;

// function prototypes
void HeadInsert(DList<ItemType>& dl);  // inserts item into head of list
void TailInsert(DList<ItemType>& dl);  // inserts item into tail of list
void SortList(DList<ItemType>& dl);  // sorts the list from low to high
void AccessItem(DList<ItemType>& dl);  // get item from list
bool FindAndMove(DList<ItemType>& dl, const ItemType item);  // finds an item and moves it. called by AccessItem(DList<ItemType>& dl)
void Delete(DList<ItemType>& dl);  // deletes item from list
void EmptyList(DList<ItemType>& dl);  // complete empties list
void PrintList(const DList<ItemType>& dl);  // prints list'
void PrintListLength(const DList<ItemType>& dl);  // prints the length of the list
char menu();  // option menu

// main method
int main() {
    DList<ItemType> dl;
    bool exit = false;
    // main menu
    do {
        switch(toupper(menu())) {
            case 'H': HeadInsert(dl); break;
            case 'T': TailInsert(dl); break;
            case 'S': SortList(dl); break;
            case 'A': AccessItem(dl); break;
            case 'D': Delete(dl); break;
            case 'M': EmptyList(dl); break;
            case 'P': PrintList(dl); break;
            case 'L': PrintListLength(dl); break;
            case 'Q':
                cout<<endl<<"Exiting program. Have a great day!"<<endl;
                exit = true;
                break;
            default:
                cout<<endl<<"Please enter a valid option..."<<endl<<endl;
                break;
        }
    }while(!exit);

    return 0;
}

// option menu
char menu() {
    string input;  // takes initial input
    char option;   // takes first char of input string for option
    cout<<endl;
    cout<<"=====Move to Front Algorithm====="<<endl;
    cout<<"= H: Insert item at front\t="<<endl;
    cout<<"= T: Insert item at back\t="<<endl;
    cout<<"= S: Sort List\t\t\t="<<endl;
    cout<<"= A: Access an item in list\t="<<endl;
    cout<<"= D: Delete an item in list\t="<<endl;
    cout<<"= M: Clear entire list\t\t="<<endl;
    cout<<"= P: Print the list\t\t="<<endl;
    cout<<"= L: Print the list's length\t="<<endl;
    cout<<"= Q: Quit the program\t\t="<<endl;
    cout<<"================================="<<endl;
    cout<<"Please enter an option: ";

    cin>>input;
    if(input.length()>1)
        return 'E';  // error
    option = input[0]; // keeps input from glitching due to input mismatch
    cout<<endl;

    return option; 
}

// prints list
void PrintList(const DList<ItemType>& dl) {
    if(dl.isEmpty())
        cout<<"List empty. Nothing to print!"<<endl;
    else
        dl.print();
}

// prints the length of the list
void PrintListLength(const DList<ItemType>& dl) {
    cout<<"List length: "<<dl.lengthIs()<<endl;
}

void SortList(DList<ItemType>& dl) {
    string input;
    int option;
    bool exit = false;

    if(dl.isEmpty()) {  // cannot sort empty list
        cout<<"Cannot sort an empty list!"<<endl;
        return;
    }

    while(!exit) {  // main loop
        try {  // catch input mismatch
            cout<<"===SORTING==="<<endl;
            cout<<"1. Sort Lowest to Highest"<<endl;
            cout<<"2. Sort Highest to Lowest"<<endl;
            cout<<"3. Return to Main Menu"<<endl;
            cout<<"Please enter an option: ";
            
            cin>>input;
            option = atoi(input.c_str());  // converts input to integer, catches error below

            switch(option) {
                case 1: dl.sortListUp(); exit = true; break; 
                case 2: dl.sortListDown(); exit = true; break; 
                case 3: exit = true; break;
                default:
                    cout<<endl<<"Please enter a valid option."<<endl<<endl;
                    break;
            }
        }
        catch(invalid_argument e) {  // catches failed conversion of a string to int
            cout<<endl<<"Please enter a valid option."<<endl<<endl;
            option = 0;
        }
        
    }
}

// accesses an item and calls on FindAndMove() to move to front
void AccessItem(DList<ItemType>& dl) {
    // list empty
    if(dl.isEmpty()) {
        cout<<"List is empty."<<endl;
        return; 
    }

    ItemType item;
    cout<<"===Access Item==="<<endl;
    cout<<"Enter a value: ";
    cin>>item;

    // list empty
    if(dl.isEmpty())
        cout<<"List is empty."<<endl;
    // object found and moved
    if(FindAndMove(dl, item))
        cout<<"Item "<<item<<" was found and moved!"<<endl;
    // object not found
    else
        cout<<"Item "<<item<<" was not found in list."<<endl;
    
}

// finds and moves an item in the list
// returns true if the item was moved
// returns false if the item was not found
bool FindAndMove(DList<ItemType>& dl, const ItemType item) {
    if(dl.inList(item)) {
        dl.deleteItem(item);
        dl.insertHead(item);
        return true;
    }
    else
        return false;
}


// inserts item into head
void HeadInsert(DList<ItemType>& dl) {
    ItemType item;
    bool exit = false;

    while(!exit) { 
        cout<<"===HEAD INSERT==="<<endl;
        cout<<"Enter a value: ";
        cin>>item;

        // cannot have duplicates
        if(dl.inList(item))
            cout<<"Item already found in list. Please enter a different value."<<endl<<endl;
        else {
            dl.insertHead(item);
            cout<<"Item added to list!"<<endl;
            break;
        }
    }
}

// inserts item into tail
void TailInsert(DList<ItemType>& dl) {
    ItemType item;
    bool exit = false;

    while(!exit) { 
        cout<<"===TAIL INSERT==="<<endl;
        cout<<"Enter a value: ";
        cin>>item;
        
        // cannot have duplicates
        if(dl.inList(item))
            cout<<"Item already found in list. Please enter a different value."<<endl<<endl;
        else {
            dl.appendTail(item);
            cout<<"Item added to list!"<<endl;
            break;
        }
    }
}

// deletes an item from the list
void Delete(DList<ItemType>& dl) {
    // list empty
    if(dl.isEmpty()) {
        cout<<"List is empty. Cannot delete from empty list."<<endl;
        return;
    }

    ItemType item;
    cout<<"===DELETE==="<<endl;
    cout<<"Enter a value for deletion: ";
    cin>>item;

    // checks to see if the item exists
    if(dl.inList(item)) {
        dl.deleteItem(item);
        cout<<"Item "<<item<<" was deleted!"<<endl;
    }
    else
        cout<<"Item requested for deletion cannot be found."<<endl;      
}

// complete empties list
void EmptyList(DList<ItemType>& dl) {
    // list empty
    if(dl.isEmpty()) {
        cout<<"List is empty. Cannot delete from an empty list."<<endl;
        return;
    }
    dl.makeEmpty();
}
