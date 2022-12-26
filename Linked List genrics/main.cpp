#include <iostream>
#include <stdio.h>
#include <string>
#include "LinkedList.cpp"

using namespace std;


int main(){
	
	List<int, string> a;
	int i = 1; string s = "ahmed";
	a.insertFirst(i, s);
	a.insertFirst(i, s);
	a.traverse();

	
	
}
