#include <cstddef> 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>*	next;
	NodeType<ItemType>*	back;
};

template <class ItemType>		
DList<ItemType>::DList()		// Class constructor
{
    length = 0;
    head = NULL;
}

template <class ItemType>
DList<ItemType>::~DList   ()		
{
	// Post: List is empty; All items have been deallocated.
       makeEmpty();

}

template <class ItemType>
void DList<ItemType>::makeEmpty()
{
        // Post: List is empty; all items have been deallocated.
        
        while(!isEmpty())
                deleteLocation(last());
}

template <class ItemType>
void DList<ItemType>::deleteItem (ItemType item)	
{
	//  Pre :  item to be deleted is passed in via parameter 
        // Post :  item is deleted if it exists in list 
        deleteLocation(location(item));
}

template <class ItemType>
bool DList<ItemType>::inList (ItemType item) const
{
	//  Pre :  item to be located is passed in via parameter 
        // Post :  function returns bool value if item is found 
        NodeType<ItemType>* temp;    // temp var used to find item
        temp = head;

        while(temp != NULL) {
                if(temp -> info == item) { // item found
                        return true;
                }
                temp = temp -> next;
        }
        return false;


}

template <class ItemType>
bool DList<ItemType>::isEmpty() const		
{
	// Post : function returns true if list is empty, false otherwise
	return (head==NULL);
}

template <class ItemType>
void DList<ItemType>::print() const	
{
	// Pre  : List is not empty 
	// Post : Items in List have been printed to screen
        NodeType<ItemType>* temp = head; // temp node
        cout<<"==Current List=="<<endl;
        for(int i=0; i<length; i++) {
                cout<<i+1<<". "<<temp -> info<<endl;
                temp = temp -> next;
        }

}
	
template <class ItemType>
void DList<ItemType>::insertHead(ItemType item)	
{
	//  Pre : item to be inserted is passed in via parameter
        // Post : item is inserted at head of list;  Former first node is 
        //        linked back to this new one via double link;
        //        Length incremented;  Special case handled if list is empty 
        NodeType<ItemType>* newNode = new NodeType<ItemType>;
        newNode->info = item;
        newNode->back = NULL;

        // list empty
        if (head != NULL) {
                head -> back = newNode;
                newNode -> next = head;
        }
        else
                newNode->next = NULL;

        head = newNode;
        length++;
}

template <class ItemType>
void DList<ItemType>::appendTail(ItemType item)
{
	//  Pre :  item to be inserted is passed in via parameter
        // Post :  item is added to tail of list; Former last node
        //         is linked to this new one via double link 
        NodeType<ItemType>* newNode = new NodeType<ItemType>;
        newNode -> info = item;
        newNode -> next = NULL;

        // if list is not empty
        if(head != NULL) {
                newNode -> back = last();
                newNode -> back -> next = newNode;
        }

        // if list is empty
        else {
                newNode -> back = NULL;
                head = newNode;  // newNode only set to head if list is empty due to appending TAIL
        }
        length++;
}

template <class ItemType>
int DList<ItemType>::lengthIs() const	
{
	// Post : Function returns current length of list
        return length;
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::location(ItemType item) const	
{
	//  Pre : item to be located is passed in via parameter 
        // Post : function returns address of item being searched for --
        //        if not found, NULL is returned  
	NodeType<ItemType>* temp = head;    // temp var used to find item

        while(temp != NULL) {
                if(temp -> info == item) { // item found
                        return temp;
                }
                temp = temp -> next;
        }
        return NULL;
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::last() const	
{
	// Post : Function returns location of current last item in list
	if(!isEmpty()) {
                NodeType<ItemType>* temp;
                temp = head;

                while(temp -> next!=NULL)
                        temp = temp -> next;
                return temp;
        }
        else
                return NULL;
}

template <class ItemType>
void DList<ItemType>::deleteLocation (NodeType<ItemType>* delPtr)	
{
	//  Pre : Item to be deleted exits in list and its location
        //        is passed in via parameter
                   
	// Post : Location passed in is removed from list;  Length
        //        is decremented, and location is deallocated 

        // Special Cases Handled for Deleting Only One Item in List,
        // The Head Item of List, and the Tail Item of List
        
        // assuming info is deleted to prevent memory leak

        // single item
        if(length==1) {
                delete delPtr;
                delPtr = NULL;
                head = NULL;  // delPtr is the head, so head must be set to NULL
                length--;
        }

        // head deletion
        else if(delPtr==head) {
                head = delPtr -> next;
                head -> back = NULL;
                delete delPtr;
                delPtr = NULL;
                length--;
        }
        // tail deletion
        else if(delPtr==last()) {
                delPtr -> back -> next = NULL;
                delete delPtr;
                delPtr = NULL;
                length--;     
        }
        // middle deletion
        else {
                delPtr -> back -> next = delPtr -> next;
                delPtr -> next -> back = delPtr -> back;
                delete delPtr;
                delPtr = NULL;
                length--;
        }
}

template<class ItemType>
void DList<ItemType>::sortListUp()
{
        // cycle through entire list
        // add values to vector
        // sort vector through STL
        // input values back into linked list

        vector<ItemType> values(length);
        NodeType<ItemType>* temp = head;

        // input items into vector
        for(int i=0; i<length; i++) {
                values[i] = (temp->info);
                temp = temp -> next;
        }

        // sort
        sort(values.begin(), values.end());

        // input values back into list
        temp = head;
        for(int i=0; i<length; i++) {
                temp -> info = values[i];
                temp = temp -> next;
        }
}

template<class ItemType>
void DList<ItemType>::sortListDown() {
        // cycle through entire list
        // add values to vector
        // sort vector through STL
        // input values back into linked list

        vector<ItemType> values(length);
        NodeType<ItemType>* temp = head;

        // input items into vector
        for(int i=0; i<length; i++) {
                values[i] = (temp->info);
                temp = temp -> next;
        }

        // sort
        sort(values.begin(), values.end());

        // input values back into list
        temp = head;
        for(int i=length-1; i>=0; i--) {
                temp -> info = values[i];
                temp = temp -> next;
        }
}