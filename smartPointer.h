#pragma once

//for non-learning purposes, boost has a good smart pointer
template <class type>
class sPtr
{
private:
	type *p;
	int r; //referenceCount
	
	void add()
	{
		r++;
	}
	int release()
	{
		return --r;
	}
	
	/*
	void swap(sPtr &first, sPtr &second)
	{
		using std::swap;
		swap(first.p, second.p);
		swap(first.r, second.r);
	}
	*/
public:
	sPtr(): p(NULL), r(1) {}
	sPtr(type *pValue): p(pValue)
	{
		add();
	}
	sPtr(const sPtr<type> & sp): p(sp.p), r(sp.r)
	{
		add();
	}
	~sPtr()
	{
		if(release() == 0)
		{
			delete p;
		}
	}

	type* get()
	{
		return p;
	}

	type& operator*()
	{
		return *p;
	}
	type* operator->()
	{
		return p;
	}
	sPtr<type>& operator=(sPtr<type> sp)
	{
		std::swap(this->p, sp.p);
		std::swap(this->r, sp.r);
		add();

		/*
		if (this != &sp) //self assignment
		{
			if(release() == 0)
			{
				delete p;
			} //this will cause an error when you take something with no references and set it equal to something

			p = sp.p;
			r = sp.r;
			add();
		}
		*/

		return *this;
	}
};