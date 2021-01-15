#include"MyLinkedList.h"
#include<set>

int main() {
	MyLinkedList mylist= MyLinkedList();
	mylist.addAtHead(1);
	mylist.addAtTail(3);
	mylist.addAtIndex(1, 2);
	mylist.deleteAtIndex(0);
	int r = mylist.get(0);

}