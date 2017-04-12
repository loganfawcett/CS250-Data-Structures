/*
Edit this file
*/

#include "StudentCode.hpp"

/*
Using StudentCode.cpp for reference,
implement the Queue's POP function.
This queue is a linked list type of structure;
you will have to directly modify the private
member variables of the Queue class in the
.hpp file.
*/
bool Queue::Pop()
{
	if (IsEmpty())
	{
		return false;
	}
	else if(m_ptrFirst == m_ptrLast)
	{
		delete m_ptrLast;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
		return true;
	}
	else
	{
		Node* ptrSecond = m_ptrFirst->ptrNext;
		ptrSecond->ptrPrev = nullptr;
		delete m_ptrFirst;
		m_ptrFirst = ptrSecond;
		m_itemCount--;
	}
}
