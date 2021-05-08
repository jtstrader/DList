# Move to Front
This project created an implementation of a doubly-linked list (DList) that moves accessed items to the front of the list.

# DList Attributes
The DList class contains many methods in order to perform a wide assortment of operations with the
doubly linked list. Along with plenty of public methods to access from client files, the DList class
contains private variables NodeType<ItemType>* head and int length, as well as private methods:
    NodeType<ItemType>* location(ItemType item) const;
    NodeType<ItemType>* last() const; 
    void deleteLocation (NodeType<ItemType>* delPtr);
These methods are used by the public methods in the DList class to access the location of an item, find
the last node of the list, and delete an item with a given location. The DList class' main purpose is to
create a doubly linked list that allows the user to store data that points to other values in both the
forward and backward directions (besides the head and tail, as the head's back pointer is NULL and the tail's
next pointer is NULL). It is templated to allow multiple different values for comparison and insertion.

# DList Functions

- DList(): constructor of the DList class, creates a head node and sets length to 0
- ~DList(): destructor of the DList class, calls on makeEmpty() to clear the list when object goes out of scop
- void makeEmpty(): a function that calls on deleteLocation(DList<ItemType>* delPtr), and uses the last() function 
to pass in the pointer. It will use a while loop to delete all last items until the whole list is deallocated.  
- void deleteItem(): a function that calls on deleteLocation with location(ItemType item) as a parameter
- bool inList(ItemType item): checks to see if an item is in the list by searching for the item passed as a parameter.
- bool isEmpty(): returns true is length is 0, and false otherwise
- void print(): prints the entire list to the screen
- void insertHead(ItemType item): inserts an item at the head of the list
- void appendTail(ItemType item): inserts an item at the end of the list
- void sortListUp(): puts values into a vector and sorts from STL, then inputs the sorted list back into the DList (low-high)
- void sortListDown(): puts values into a vector and sorts from STL, then inputs the sorted list back into the DList (high-low)
- int lengthIs(): getter function for the private variable length
- NodeType<ItemType>* location(ItemType item): the same function as inList(), but returns a pointer of the object where the item was found
- NodeType<ItemType>* last(): returns the last node of the list
- void deleteLocation(NodeType<ItemType>* delPtr): deletes the location of the pointer passed in from the list. 4 cases needed:
  1. the list has a single item
  2. deleting the head
  3. deleting the tail
  4. deleting a "middle" value (item between head and tail)

# Move to Front Algorithm

The Move to Front algorithm's purpose is to optimize searching through a list. The move to front algorithm makes searching lists 
very efficient by pushing the most accessed data to the front of the list. If data were being accessed randomly from the list 
than it is most likely that the move to front algorithm would not be as efficient as other search methods as it truly shines when 
the same values are chosen over and over, keeping them at the front of the list allowing the user/the computer to have easy and 
quick access to them.

# Client File Methods

- void HeadInsert(DList<ItemType>& dl):
  - runs an insert head menu for the user to input a value and then inserts a head into
    the list. Does not allow duplicates to be entered into the list, so will call on inList()
    to confirm there are no duplicates
- void TailInsert(DList<ItemType>& dl):
  - runs an insert tail menu for the user to input a value and then inserts a tail into
    the list. Does not allow duplicates to be entered into the list, so will call on inList()
    to confirm there are no duplicates
- void SortList(DList<ItemType>& dl):
  - open the sorting menu that takes in user input to select their sorting option. Will call
    on the sort functions of the DList class
- void AccessItem(DList<ItemType>& dl):
  - takes an item and passes it through FindAndMove(DList<ItemType>& dl) to move the item.
  - print the item to the screen as well and tell the user the item was found if FindAndMove returns true
  - print item not found if FindAndMove returns false
- bool FindAndMove(DList<ItemType>& dl, const ItemType item):
  - boolean return function that searches for the item in the list. If not found, return false, if found
    return true. If the item is found, call deleteItem() from the DList class to remove the item and then
    append it to head
- void Delete(DList<ItemType>& dl):
  - creates a deletion menu for the user to input an item to delete. If the item is not found the function
    will tell the user that the item was not found. Otherwise, the item is deleted and the function confirms
    that the item is deleted through a cout
- void EmptyList(DList<ItemType>& dl):
  - calls on the makeEmpty() function of the DList class to empty the list and allow for a fresh new start
- void PrintList(const DList<ItemType>& dl):
  - calls on the print() function of the DList class to print the list
- void PrintListLength(const DList<ItemType>& dl):
  - calls on the lengthIs() function of the DList class to print the length of the list
- char menu():
  - menu function that creates the menu for the main method and returns a char value. Takes in input as a
    string and throws and error if the length of the string is greater than 1 (more than a single character
    inputted into the menu) or if the char does not exist in the switch of main()
- int main():
  - main method. Contains the main switch that takes in input from menu() to run the different methods of
    the program. Exits on input 'Q' 
