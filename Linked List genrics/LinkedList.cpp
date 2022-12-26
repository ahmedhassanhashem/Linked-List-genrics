#include "LinkedList.h"

using namespace std;


template <class keyType, class dataType>
List<keyType, dataType>::List(){
	head = cursor = prev = NULL;
}
template <class keyType, class dataType>
List<keyType, dataType>::~List(){
	makeListEmpty();
}
template <class keyType, class dataType>
bool List<keyType, dataType>::listIsEmpty(){
	return (head == NULL);
}
template <class keyType, class dataType>
bool List<keyType, dataType>::cursorIsEmpty(){
	return (cursor == NULL);
}
template <class keyType, class dataType>
void List<keyType, dataType>::toFirst(){
	cursor = head;
	prev = NULL;
}
template <class keyType, class dataType>
bool List<keyType, dataType>::atFirst(){
	return (cursor == head);
}
template <class keyType, class dataType>
void List<keyType, dataType>::toEnd(){
	toFirst();
	if(!listIsEmpty())
		while (cursor->next != NULL)
		advance();
}
template <class keyType, class dataType>
bool List<keyType, dataType>::atEnd(){
	if(listIsEmpty())
		return true;
	else if(cursorIsEmpty())
		return false;
	else
	return (cursor->next == NULL);
}
template <class keyType, class dataType>
void List<keyType, dataType>::advance(){
	prev = cursor;
	cursor = cursor->next;
}
template <class keyType, class dataType>
int List<keyType, dataType>::listSize() const {
	nodePointer i = head;
	int count = 0;
	while(i != NULL){
		count++;
		i = i->next;
	}
	return count;
}
template <class keyType, class dataType>
void List<keyType, dataType>::updateData(const dataType &d){
	cursor->data = d;
}
template <class keyType, class dataType>
void List<keyType, dataType>::retrieveKey(keyType &k) const {
	k = cursor->key;
}
template <class keyType, class dataType>
void List<keyType, dataType>::retrieveData(dataType &d) const {
	d = cursor->data;
}
template <class keyType, class dataType>
void List<keyType, dataType>::insertFirst(const keyType &k, const dataType &d){
	nodePointer newNode = new node;
	newNode->key = k;
	newNode->data = d;
	newNode->next = head;
	head = newNode;
	cursor = head;
	prev = NULL;
}
template <class keyType, class dataType>
void List<keyType, dataType>::insertAfter(const keyType &k, const dataType &d){
	nodePointer newNode = new node;
	newNode->key = k;
	newNode->data = d;
	newNode->next = cursor->next;
	cursor->next = newNode;
	prev = cursor;
	cursor = cursor->next;
}
template <class keyType, class dataType>
void List<keyType, dataType>::insertBefore(const keyType &k, const dataType &d){
	nodePointer newNode = new node;
	newNode->key = k;
	newNode->data = d;
	newNode->next = cursor;
	prev->next = newNode;
	cursor = newNode;
}
template <class keyType, class dataType>
void List<keyType, dataType>::insertEnd(const keyType &k, const dataType &d ){
	if(listIsEmpty())
		insertFirst(k, d);
	else
	{
		toEnd();
		insertAfter(k, d);
	}
}
template <class keyType, class dataType>
void List<keyType, dataType>::deleteNode(){
	nodePointer newNode;
	if (!cursorIsEmpty()){
		if(atFirst()){
			newNode = cursor;
			cursor = cursor->next;
			head = cursor;
			delete newNode;
		}else{
		newNode = cursor;
		cursor = cursor->next;
		prev->next = cursor;
		delete newNode;	
		}
	}	
}
template <class keyType, class dataType>
void List<keyType, dataType>::deleteFirst(){
	if(!listIsEmpty()){
		toFirst();
		deleteNode();
	}
}
template <class keyType, class dataType>
void List<keyType, dataType>::deleteEnd(){
	toEnd();
	deleteNode();
}
template <class keyType, class dataType>
void List<keyType, dataType>::makeListEmpty(){
	while (cursor != NULL){
		toFirst();
		deleteNode();
	}
}
template <class keyType, class dataType>
bool List<keyType, dataType>::search(const keyType &k){
	bool found = false;
	while(!found && !cursorIsEmpty()){
		if (k == cursor->key)
			found = true;
		else
			advance();
	}
	return found;
}
template <class keyType, class dataType>
void List<keyType, dataType>::orderInsert(const keyType &k, const dataType &d){
	toFirst();
	while(cursor != NULL && k > cursor->key)
		advance();
	if(prev == NULL)
		insertFirst(k, d);
	else
		insertBefore(k, d);
	
}
template <class keyType, class dataType>
void List<keyType, dataType>::traverse(){
	toFirst();
	cout << "[ ";
	while (!cursorIsEmpty()){
		cout << cursor-> data << " ";
		advance();
	}
	cout << "]";
}
template <class keyType, class dataType>
int List<keyType, dataType>::list_size(nodePointer h){
	if(h==NULL)
		return 0;
	else
		return 1 + list_size(h->next);
}


