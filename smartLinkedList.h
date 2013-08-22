#pragma once
#include "Node.h"
#include "smartPointer.h"
#include <string>
#include <sstream>
#include <stdexcept>

template <class type>
class LinkedList
{
private:
	int size;
	sPtr<node<type>> head; 

public:
	LinkedList(): head(NULL), size(0) {}

	/// <summary>Removes the object at index and relinks the list. Synonymous to a stack's pop().</summary>
	/// <returns>The object removed.</returns>
	type remove(int index = 0) //pop
	{
		if(index > size - 1)
			throw std::out_of_range("Index to be deleted greater than size");

		type obj = head->data;
		if(index == 0)
			head = head->next;

		else
		{
			sPtr<node<type>> temp = head;
			bool test = true;
			for(int i = 0; i < index - 1; i++)
			{
				//0 based, so, i = index - 1 -> data to be removed
				//i = index - 2 -> data to be repointed to i = index
				temp = temp->next;
			}
			obj = temp->next->data;
			temp->next = temp->next->next;
		}
		size--;
		return obj;
	}
	
	/// <summary>Iterates to the specified index from the head of the list and returns the node.</summary>
	/// <param name="Index">Index of the object to be returned</param>
	/// <returns>The object at the specified index, will return null on error.</returns>
	type goTo(int index) //peek, essentially
	{
		if(index > size - 1)
			throw std::out_of_range("Index greater than size");

		sPtr<node<type>> temp = head;

		for(int i = 0; i < index; i++)
			temp = temp->next;

		return temp->data;
	}

	/// <summary>Inserts an object at the specified index.</summary>
	/// <param name="Object">Object to be inserted.</param>
	/// <param name="Index">Index of the object to be inserted at. 0 is the head.</param>
	/// <returns>True if successful, false otherwise.</returns>
	bool add(type obj, int index = 0)
	{
		if(index > size)
			throw std::out_of_range("Index to be added at greater than size");

		sPtr<node<type>> temp(new node<type>(obj));

		if(index == 0)
		{
			temp->next = head;
			head = temp;
			size++;
			return true;
		}
		else
		{
			sPtr<node<type>> p = head;

			for(int i = 0; i<index-1; i++)
				p = p->next;
		
			temp->next = p->next;
			p->next = temp;

			size++;
			return true;
		}
	}

	/// <summary>Returns a formatted string that holds the contents of the list.</summary>
	/// <returns>A ', ' delimited string.</returns>
	std::string toString()
	{
		std::stringstream value;
		sPtr<node<type>> i = head;
		while(i.get() != NULL)
		{
			value << i->data;
			if(i->next.get() != NULL)
				value << ", ";
			i = i->next;
		}
		return value.str();
	}

	int length()
	{
		return size;
	}
};