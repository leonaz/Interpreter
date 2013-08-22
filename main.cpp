#include <iostream>
#include <string>
#include "smartLinkedList.h"
#include "stack.h"

using namespace std;

int main()
{
	for(int i = 0; i < 10000000; i++)
	{
		/*
		stack<double> s;
		s.push(5);
		s.dup();
		s.add();
		s.pop();
		

		LinkedList<double> l;
		l.add(2);
		//no real dup functionality in the list
		l.add(2);
		double a = l.remove();
		double b = l.remove();
		l.add(a + b);
		l.remove();
		*/
		
		try
		{
			LinkedList<string> moo3;
			moo3.add("head");
			moo3.add("one");
			moo3.add("two");
			moo3.add("three");
			moo3.add("tail");

			//cout<<moo3.toString() << endl;
			//cout << moo3.length();
			//cout << moo3.remove() << endl;
			//cout<<moo3.toString() << endl;

			//cout<< moo3.goTo(0) << endl;
			//cout << moo3.remove(4) << endl;
			//cout << moo3.toString() << endl;
			
			//empty list, technically
		}
		catch (exception &e)
		{
			cout << "Exception: " << e.what() << endl;
		}
		

		//garbage collect here
	}
	
	cout << "end" << endl;
	cin.ignore(1);
	return 0;
}