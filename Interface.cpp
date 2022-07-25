#include "Interface.h"

Rectangle::Rectangle()
{
	
	color = "";
}

int* Rectangle::getLeftUp()
{
	return leftUp;
}

int* Rectangle::getRightDown()
{
	return rightDown;
}

void Rectangle::writeFigure(std::ofstream& stream)
{
	stream << "Left up x: " << this->leftUp[0] << " Left up y: " << this->leftUp[1] << "\n";
	stream << "Right down x: " << this->rightDown[0] << " Right down y: " << this->rightDown[1] << "\n";
	stream << "Color " << this->color << "\n";
	stream << "Density " << this->density << "\n";
	return;
}

void Rectangle::readFigure(std::ifstream& stream)
{
	this->key = rect;
	stream >> this->leftUp[0];
	stream >> this->leftUp[1];
	stream >> this->rightDown[0];
	stream >> this->rightDown[1];
	stream >> this->color;
	stream >> this->density;
}

Circle::Circle()
{
	
	color = "";
}

int* Circle::getCenter()
{
	return center;
}

int Circle::getRadius()
{
	return radius;
}

void Circle::writeFigure(std::ofstream& stream)
{
	stream << "Center: " << this->center[0] << " " << this->center[1] << "\n";
	stream << "Radius " << this->radius << "\n";
	stream << "Color " << this->color << "\n";
	stream << "Density " << this->density << "\n";
}

void Circle::readFigure(std::ifstream& stream)
{
	
	this->key = cir;
	stream >> this->center[0];
	stream >> this->center[1];
	stream >> this->radius;
	stream >> this->color;
	stream >> this->density;
}



string Figure::getColor()
{
	return color;
}

type Figure::getKey()
{
	return key;
}

Element::Element()
{
	itFigure = nullptr;
	next = nullptr;
	prev = nullptr;
}

Element::~Element()
{
	delete itFigure;
}

void Element::setItFigure(Figure* inItFigure)
{
	itFigure = inItFigure;
}

void Element::setNext(Element* inNext)
{
	next = inNext;
}

void Element::setPrev(Element* inPrev)
{
	prev = inPrev;
}

Figure* Element::getItFigure()
{
	return itFigure;
}

Element* Element::getNext()
{
	return next;
}

Element* Element::getPrev()
{
	return prev;
}

void Element::writeElement(std::ofstream& stream)
{
	switch (this->itFigure->getKey())
	{
	case rect:
	{
		((Rectangle*)this->itFigure)->writeFigure(stream);
		break;
	}
	case cir:
	{
		((Circle*)this->itFigure)->writeFigure(stream);
		break;
	}
	default:
		break;
	}
	return;
}

int Element::readElement(std::ifstream& stream)
{
	char type;
	stream >> type;
	switch (type)
	{
	case 'r':
	{
		this->itFigure = new Rectangle();
		
		break;
	}
	case 'c':
	{
		this->itFigure = new Circle();
		
		break;
	}
	default:
		return 0;
	}
	this->itFigure->readFigure(stream);
	return 1;
}

List::List()
{
	this->head = nullptr;
	this->tail = nullptr;
	size = 0;
	return;
}

List::~List()
{
	clear();
}

void List::setHead(Element* inHead)
{
	this->head = inHead;
}

void List::setTail(Element* inTail)
{
	this->tail = inTail;
}

Element* List::getHead()
{
	return head;
}

Element* List::getTail()
{
	return tail;
}

void List::pushBack(Element* newElement)
{
	newElement->setPrev(this->tail) ;
	if (this->size)
	{
		this->tail->setNext(newElement) ;
		this->tail = newElement;
	}
	else
	{
		this->tail = newElement;
		this->head = newElement;
	}
	this->size++;
	return;
}

void List::readList(std::ifstream& stream)
{
	while (!stream.eof())
	{
		Element* newElement = new Element();
		if (newElement->readElement(stream) )
		{
			this->pushBack( newElement);
		}
	}
}

void List::writeList(std::ofstream& stream)
{
	stream << "Num " << this->size << "\n";
	auto curEl = this->head;
	for (int i = 0; i < this->size; i++)
	{
		stream << i << ": ";
		curEl->writeElement( stream);
		curEl = curEl->getNext();
	}
}

void List::clear()
{
	auto curEl = this->head;
	while (curEl != nullptr)
	{
		this->setHead(this->head->getNext());
		delete curEl;
		curEl = this->head;
	}
	this->size = 0;
}
