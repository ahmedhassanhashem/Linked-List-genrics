#include<iostream>
#include<stdio.h>
#include <string>
using namespace std;

template <class keyType, class dataType>


class List {
	private:
		class node{
			public:
				keyType key;
				dataType data;
				node *next;
	};
		typedef node *nodePointer;
		nodePointer head, cursor, prev;
		int list_size(nodePointer h);
	public:
		List();
		~List();
		bool listIsEmpty();
		bool cursorIsEmpty();
		void toFirst();
		bool atFirst();
		void toEnd();
		bool atEnd();
		void advance();
		int listSize() const;
		void updateData(const dataType &d);
		void retrieveKey(keyType &k) const;
		void retrieveData(dataType &d) const;
		void insertFirst(const keyType &k, const dataType &d);
		void insertAfter(const keyType &k, const dataType &d);
		void insertBefore(const keyType &k, const dataType &d);
		void insertEnd(const keyType &k, const dataType &d);
		void deleteNode();
		void deleteFirst();
		void deleteEnd();
		void makeListEmpty();
		bool search(const keyType &k);
		void orderInsert(const keyType &k, const dataType &d);
		void traverse();
		int recursive_list_size();	
};
