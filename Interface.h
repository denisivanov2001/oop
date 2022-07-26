#pragma once
#include <string>
#include <fstream>
#include <math.h>
#include <corecrt_math_defines.h>
using namespace std;
enum type { rect, cir,tri };
class Figure
{
protected:
	type key;
	std::string color;
	double density;
public:
	 string getColor();
	 type getKey();
	virtual void writeFigure(std::ofstream& stream)=0;
	virtual void readFigure(std::ifstream& stream)=0;
	virtual double perimetr() = 0;
};
class Rectangle :public Figure
{
	
	int leftUp[2];
	int rightDown[2];
public:
	Rectangle();
	int* getLeftUp();
	int* getRightDown();
	void writeFigure(std::ofstream& stream);
	void readFigure(std::ifstream& stream);
	double perimetr();
};
class Circle : public Figure
{
	
	int center[2];
	int radius;
	
public:
	Circle();
	int* getCenter();
	int getRadius();
	void writeFigure(std::ofstream& stream);
	void readFigure(std::ifstream& stream);
	double perimetr();
};
class Triangle : public Figure
{
	int first[2];
	int second[2];
	int third[2];
public:
	Triangle();
	int* getFirst();
	int* getSecond();
	int* getThird();
	void writeFigure(std::ofstream& stream);
	void readFigure(std::ifstream& stream);
	double perimetr();
};

class Element
{
	Figure* itFigure;
	Element* next;
	Element* prev;
public:
	Element();
	~Element();
	void setItFigure(Figure* inItFigure);
	void setNext(Element* inNext);
	void setPrev(Element* inPrev);
	Figure* getItFigure( );
	Element* getNext( );
	Element* getPrev();
	void writeElement(std::ofstream& stream);
	int readElement(std::ifstream& stream);
	int equ(Element* second);
};


class List
{
	int size = 0;
	Element* head;
	Element* tail;
public:
	List();
	~List();
	void setHead(Element* inHead);
	void setTail(Element* inTail);
	Element* getHead();
	Element* getTail();
	void pushBack(Element* newElement);
	void pushFirst(Element* newElement);
	void readList(std::ifstream& stream);
	void writeList(std::ofstream& stream);
	void writeRect(std::ofstream& stream);
	void writeCir(std::ofstream& stream);
	void writeTri(std::ofstream& stream);
	void clear();
	List* sort();
};