#pragma once
#include "smartLinkedList.h"

template <class type>
class stack
{
private:
	//realistically, using the built in vector may 
	//be better than a custom designed class
	LinkedList<type> s;

public:
	//bool empty();
	int size()
	{
		return s.length();
	}

	void push(type x)
	{
		s.add(x);
	}
	type pop()
	{
		return s.remove();
	}
	type peek()
	{
		return s.goTo(0);
	}
	
	void ifeq(int ln) //line number
	{
		if(pop() != 0)
		{
			jump(ln);
		}
	}
	void jump(int ln)
	{

	}

	void dup()
	{
		type obj = peek();
		push(obj);
	}
	void add()
	{
		type a = pop();
		type b = pop();
		push(a+b);
	}
};