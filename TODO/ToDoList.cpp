#include "ToDoList.h"
template<class ItemType>
ToDoList<ItemType>::ToDoList() {
    itemCount = 0;
    headPtr = nullptr;
}
template<class ItemType>
ToDoList<ItemType>::ToDoList(const ToDoList& rhs) {
    itemCount = rhs.itemCount;
    maxItems = rhs.maxItems;
    if (rhs.headPtr == nullptr) {
        headPtr = nullptr;
        return this;
    }

    headPtr = new Node<ItemType>(rhs.headPtr->getItem());
    Node<ItemType>* newNodePtr = headPtr;
    Node<ItemType>* tmpPtr = rhs.headPtr;
    Node<ItemType>* curPtr = tmpPtr;

    for (int i = 1; i <= itemCount && curPtr != nullptr; i++) {
        newNodePtr->setItem = new Node<ItemType>(curPtr->getNext()->getItem());
        curPtr = curPtr->getNext();
        newNodePtr = newNodePtr->getNext();
    }
}

template<class ItemType>
bool ToDoList<ItemType>::isEmpty() const {
    return itemCount == 0;
}
template<class ItemType>
int ToDoList<ItemType>::getLength() const {
    return itemCount;
}

template<class ItemType>
bool ToDoList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    Node<ItemType>* newNodePtr = new Node<ItemType>(); //create new node
    Node<ItemType>* curPtr = headPtr; 
    Node<ItemType>* tmpPtr = headPtr;     // holds headptr
    newNodePtr->setItem(newEntry); // new node contains new item
    if (newPosition <= 0) {
        cout << "Position cannot be less than or equal to zero." << endl;
        return false;
    }
    if (newPosition > ItemCount) {
        cout << "Position outside of list bounds." << endl;
        return false;
    }
    if (newPosition == 1) {
        newNodePtr->setNext(tmpPtr);
        headPtr = newNodePtr;
    }
    for (int i = 2; i <= ItemCount && curPtr != nullptr; i++) {
        curPtr = curPtr->getNext();
        if (i == newPosition) {
            newNodePtr->setNext(curPtr);
            tmpPtr->setNext(newNodePtr);
            curPtr = nullptr;
        }
        else tmpPtr = tmpPtr->getNext();
    }
    itemCount++;
    return true;
}

template<class ItemType>
bool ToDoList<ItemType>::remove(const ItemType& anEntry) {
    bool found = false;
    Node<ItemType>* curPtr = headPtr; // Holds pos
    Node<ItemType>* tmpPtr = headPtr; // Holds node to delete or other movable

    // Can't search an empty list
    if (isEmpty()) return found;
    //find object, first try
    if (curPtr->getItem() == anEntry) {
        found = true;
        headPtr = curPtr->getNext();
    }
    // guard clause in for loop statement
    for (int i = 2; i <= ItemCount && !found && (curPtr != nullptr); i++) {
        curPtr = curPtr->getNext();
        //find object
        if (curPtr->getItem() == anEntry) {
            tmpPtr->setNext(curPtr->getNext);
            found = true;
        }
        else tmpPtr = tmpPtr->getNext();
    }
    
    if (found) {
        // if found, we've already allocated prev node via tmpPtr
        // now just to delete curPtr's node
        // prepare to disconnect first node
        Node<ItemType>* nodeToDeletePtr = curPtr;
            
        // return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        itemCount--;
    }
    return found;
}
template<class ItemType>
void ToDoList<ItemType>::clear() {
    Node<ItemType>* curPtr = headPtr; // Holds pos
    while(!isEmpty()) {
        remove(curPtr->getItem());
        curPtr = headPtr;
    }
    cout << "The list has been completed." << endl;
}

template<class ItemType>
ItemType ToDoList<ItemType>::getEntry(int position)const {
    Node<ItemType>* curPtr = headPtr; // Holds pos
    // Prefer descriptive throws
    if (isEmpty()) throw "Empty List, cannot return items.";
    if (position < 0) throw "Position cannot be less than or equal to zero.";
    if (position > ItemCount) throw "Position outside of list bounds.";
    else for (int i = 1; i <= ItemCount; i++) {
        if (i == position) return curPtr->getItem();
        else curPtr = curPtr->getNext();
    }
}

template<class ItemType>
ItemType ToDoList<ItemType>::replace(int position, const ItemType& newEntry) {
    if (isEmpty()) insert(1, newEntry);
    if (position > ItemCount) throw "Position outside of list bounds.";
    else {
        remove(getEntry(position));
        insert(position, newEntry);

    }

}


template<class ItemType>
ToDoList<ItemType>::~ToDoList() {
    Node<ItemType>* curPtr = headPtr; // Holds pos
    while (!isEmpty()) {
        remove(curPtr->getItem());
        curPtr = headPtr;
    }
    ItemCount = 0;
    headPtr = nullptr;
}