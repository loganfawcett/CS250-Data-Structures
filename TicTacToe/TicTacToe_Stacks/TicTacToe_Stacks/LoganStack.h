#ifndef LOGANSTACK
#define LOGANSTACK

#include <exception>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
	Node()
	{
		m_ptrNext = nullptr;
		m_ptrPrev = nullptr;
	}

	T m_data;

	Node<T>* m_ptrNext;
	Node<T>* m_ptrPrev;
};

template <typename T>
class LoganStack
{
public:
	LoganStack()
	{
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
	}

	virtual ~LoganStack()
	{
		while (m_ptrFirst != nullptr)
		{
			pop();
		}
	}

	void push(T data)
	{
		//	Error checking
		try
		{
			Node<T>* newNode = new Node<T>();
			newNode->m_data = data;

			if (m_ptrFirst == nullptr)
			{
				// Empty list
				m_ptrFirst = newNode;
				m_ptrLast = newNode;
			}
			else
			{
				// Not empty, new node is the new last
				m_ptrLast->m_ptrNext = newNode;
				newNode->m_ptrPrev = m_ptrLast;

				// Update pointer
				m_ptrLast = newNode;
			}

			m_itemCount++;
		}
		catch (const bad_alloc& ex)
		{
			throw string("Greater than 10 entries");
		}
	}

	void pop()
	{
		//	Error checking
		if (m_ptrLast == nullptr)
		{
			throw out_of_range("Last pointer is nullptr");
		}

		if (m_ptrFirst == m_ptrLast)
		{
			delete m_ptrLast;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;
			return;
		}

		// Keep track of 2nd-to-last item
		Node<T>* ptrPenultimate = m_ptrLast->m_ptrPrev;

		// Update 2nd-to-last item's next ptr
		ptrPenultimate->m_ptrNext = nullptr;

		// Clear out data at last element
		delete m_ptrLast;

		// Update last pointer
		m_ptrLast = ptrPenultimate;

		m_itemCount--;
	}

	T top()
	{
		//	Error checking
		if (m_ptrLast == nullptr)
		{
			throw out_of_range("Last pointer is nullptr");
		}

		return m_ptrLast->m_data;
	}

	int size()
	{
		return m_itemCount;
	}

protected:
	int m_itemCount;
	Node<T>* m_ptrFirst;
	Node<T>* m_ptrLast;
};


#endif