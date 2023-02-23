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
bool ToDoList<ItemType>::insert(const ItemType& newEntry) {
    Node<ItemType>* newNodePtr = new Node<ItemType>(); //create new node
    newNodePtr->setItem(newEntry); // new node contains new item
    newNodePtr->setNext(headPtr); // new node points to chain
    headPtr = newNodePtr; // new node is now first node
    itemCount++;
    return true;
}

template<class ItemType>
bool ToDoList<ItemType>::remove(const ItemType& anEntry) {
    bool found = false;
    Node<ItemType>* curPtr = headPtr; // temporary pointer
    Node<ItemType>* tempPtr = curPtr;

    //find object, first try
    if (curPtr->getItem() == anEntry) {
        found = true;
    }
    for (int i = 1; i < ItemCount+1 && !found && (curPtr != nullptr); i++) {
        curPtr = curPtr->getNext();
        //find object
        if (curPtr->getItem() == anEntry) {
            found = true;
        }
        else {
            curPtr = curPtr->getNext();
            tempPtr = tempPtr->getNext();
        }
    }
    //swap with first item
    // This section needs an update as the swaps need to iterate
    // from the last item until they reach the item in question. 
        if (found) {
            // curPtr will be at the node to remove, 
            // we want a tempPtr at the previous item,
            // and then we can set the previous items next to the item after curPtr
            // effectively removing it without changing order
            tempPtr->setNext(curPtr->getNext());
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
ToDoList<ItemType>::~ToDoList() {
    Node<ItemType>* curPtr = headPtr;
    while (curPtr != nullptr) {
        Node<ItemType>* deletePtr = curPtr->getNext();
        delete deletePtr;
    }
}