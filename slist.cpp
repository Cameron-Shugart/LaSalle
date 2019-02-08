#include "slist.h"
#include "math.h"
#include <"iostream">
/*

Class Library File

*/
using namespace std;
slist::slist() {
	length = 0;
}

slist::~slist() {
	clear();
}


void slist::add(void* value) {
	if(!isEmpty()) {
		Node* cur = head;
		for(int x = 1; x < size(); x++) {
			cur = cur->next;
		}
		Node* n = new Node;
		n->value = value;
		cur->next = n;
		length++;
	}
	else {
		head = new Node;
		head->value = value; 
		head->next = new Node();
		length++;
	}
}	


void slist::clear() {
	Node* current = head;
	Node* previous = head;
	for(int i=0; i<length; i++) {
		delete previous;
		previous = current; 
		current = current -> next;
	}
	length = 0;
}

bool slist::equals(slist list) {				
	if(size() == list.size()) {
		for(int x = 0; x < size(); x++) {
			if(get(x) != list.get(x)) {
				return false;
			}
		}
	}
	else return false;
	return true;

}

void* slist::get(int index) {		
	Node* cur = head;
	for(int x = 0; x < index; x++) {
		cur = cur->next;
	}
	return cur->value;

}


void slist::insert(int index, void* value) {		
	Node* cur = head;
	for(int x = 0; x < index; x++) {
		cur = cur->next;
	}
	Node* insert;
	insert->value = value;
	insert->next = cur->next;
	cur->next = insert;
}

void slist::exchg (int index1, int index2) {
	Node* nullnode = NULL;
	Node* nullnode2 = NULL;
	for (int i = 0; i < index1; i++)
		 nullnode = nullnode -> next;
	for (int j = 0; j < index2; j++)
		 nullnode2 = nullnode2 -> next;
	Node* nullnode3 = nullnode;
	nullnode = nullnode2;
	nullnode2 = nullnode3;
	
}

bool slist::isEmpty() {
	if (length!=0) {
		return false;
	}
	return true;
}

void slist::remove(int index) {			
	Node* cur = head;
	Node* prev = head;
	for(int x = 0; x < index; x++) {
		cur = cur->next;
	}
	for(int x = 0; x < index; x++) {
		prev = prev->next;
	}
	prev->next = cur->next;
	delete cur;
}

void slist::set(int index, void* value) {		
	Node* cur = head;
	for(int x = 0; x < index; x++) {
		cur = cur->next;
	}
	cur->value = value;
}

int slist::size() {
	return length;
}

slist slist::subList(int start, int length)	{ 
	Node* cur = head;
	slist val;
	for(int x = 0; x < start; x++) {
		cur = cur->next;
	}
	for(int x = 0; x < length; x++) {
		val.add(cur->value);
		cur = cur->next;
	}
	return val;
}

string slist::toString(){
	Node* curr = head;
	std::cout << length + "/n";
	for(int x=0; x<length; x++) {
		std::cout << curr;
		curr = curr -> next;
	}
}






// Constructor

// Destructor

// add(value)				//Adds a new value to the end of this list.

// clear()					//Removes all elements from this list.

// equals(list)				//Returns true if the two lists contain the same elements in the same order.

//get(index)				//Returns the element at the specified index in this list.

//insert(index, value)		//Inserts the element into this list before the specified index.

//exchg(index1, index2)		//Switches the payload data of specified indexex.

// isEmpty()				//Returns true if this list contains no elements.

// remove(index)			//Removes the element at the specified index from this list.

// set(index, value)		//Replaces the element at the specified index in this list with a new value.

// size()					//Returns the number of elements in this list.

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

// toString()				//Converts the list to a printable string representation.
