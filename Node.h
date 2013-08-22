#pragma once
#include "smartPointer.h"

template <class type>
class node
{
public:
	type data;
	sPtr<node<type>> next;

	node(): next(NULL), data(NULL) {}
	node(type x): data(x), next(NULL) {}
	node(type x, sPtr<node<type>> y): data(x), next(y) {} //technically not used in LinkedList
	
	/*~node()
	{
		delete next;
	}*/
};