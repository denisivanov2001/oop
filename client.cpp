#include <iostream>
#include <fstream>
#include "Interface.h"
using namespace std;
int main()
{
	ifstream read;
	ofstream write;
	read.open("1.txt");
	write.open("2.txt");
	List* clientList = new List();
	
	clientList->readList( read);
	write << "List:\n";
	clientList->writeList( write);
<<<<<<< HEAD
	write << "Sorted:\n";
	clientList = clientList->sort();
	clientList->writeList(write);
=======
	write << "Rectangle:\n";
	clientList->writeRect(write);
	write << "Circle:\n";
	clientList->writeCir(write);
>>>>>>> ignore
	write << "Delete list:\n";
	clientList->clear();
	clientList->writeList( write);
	read.close();
	write.close();
	return 1;
}