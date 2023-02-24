#ifndef TO_DO_LIST
#define TO_DO_LIST
using namespace std;
#include "ListInterface.h"
#include "Node.h"
template<class ItemType>
class ToDoList : public BagInterface<ItemType> {
private:
	Node<ItemType>* headPtr;
	int ItemCount;
public:
	ToDoList();
	ToDoList(const ToDoList&);
	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(const ItemType& newEntry);
	void clear();
	ItemType getEntry(int position) const;
	ItemType replace(int position, const ItemType& newEntry);
	~ToDoList();
};
#include "ToDoList.cpp" 
#endif