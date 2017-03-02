#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Node
{
	Node()
	{
		ptrNext = nullptr;
		ptrPrev = nullptr;
	}

	Node* ptrNext;
	Node* ptrPrev;

	int data;
};

class CoordPairLinkedList
{
public:
	CoordPairLinkedList()
	{
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount = 0;
	}

	~CoordPairLinkedList()
	{
		Free();
	}

	/* START OF STUDENT SECTION **************************************/

	/*
	  Push two items to the Linked List at a time: x and y
	*/
	void Push2(int x, int y)
	{
		Node* newNodeX = new Node;
		newNodeX->data = x;

		Node* newNodeY = new Node;
		newNodeY->data = y;

		if (m_ptrFirst == nullptr)
		{
			//		If list is empty
			m_ptrFirst = newNodeX;
			m_ptrLast = newNodeY;

			newNodeX->ptrNext = newNodeY;
			newNodeY->ptrPrev = newNodeX;

		}
		else
		{
			//		Not empty
			newNodeX->ptrPrev = m_ptrLast;
			newNodeX->ptrNext = newNodeY;
			newNodeY->ptrPrev = newNodeX;
			m_ptrLast->ptrNext = newNodeX;
			m_ptrLast = newNodeY;
		}

		m_itemCount += 2;
		// Do the thing!
	}

	/*
	  Remove a pair of items from the list at a time
	*/
	bool Pop2()
	{
		if (m_ptrLast == nullptr || m_ptrLast == m_ptrFirst)
		{
			// do nothing
			return false;
		}
		else
		{
			Node* secondFromLast = m_ptrLast->ptrPrev;
			Node* thirdFromLast = secondFromLast->ptrPrev;
			//Node* fourthFromLast = thirdFromLast->ptrPrev;

			// Remove the last two items and update the 3rd-
			// to-last item to be the new last

			if (secondFromLast == m_ptrFirst)
			{
				delete m_ptrFirst;
				delete m_ptrLast;

				m_ptrFirst = nullptr;
				m_ptrLast = nullptr;
			}
			else
			{
				delete m_ptrLast;
				delete secondFromLast;

				m_ptrLast = thirdFromLast;
				m_ptrLast->ptrNext = nullptr;
			}

			m_itemCount -= 2;
		}

		return true; // Return the appropriate value
	}

	/* END OF STUDENT SECTION **************************************/

	bool Pop()
	{
		if (m_ptrLast == nullptr)
		{
			// do nothing
			return false;
		}

		if (m_ptrLast == m_ptrFirst)
		{
			delete m_ptrLast;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;
		}
		else
		{
			// Remove the last item and update the 2nd-
			// to-last item to be the new last
			Node* penultimate = m_ptrLast->ptrPrev;
			delete m_ptrLast;
			m_ptrLast = penultimate;
			penultimate->ptrNext = nullptr;
			m_itemCount--;
		}

		return true;
	}

	void Display()
	{
		cout << endl << "Display List:" << endl;
		int counter = 0;
		Node* ptrCurrent = m_ptrFirst;
		while (ptrCurrent != nullptr)
		{
			cout << counter << ": " << ptrCurrent->data << "\t\t";
			if (counter % 3 == 0 && counter != 0) { cout << endl; }
			ptrCurrent = ptrCurrent->ptrNext;
			counter++;
		}
		cout << endl;
	}

	int Size() const
	{
		return m_itemCount;
	}

	bool IsEmpty() const
	{
		return (m_ptrFirst == nullptr);
	}

	int Get(int index) const
	{
		if (index < 0 || index >= m_itemCount)
		{
			// Return a new T item...
			return 0;
		}

		// Locate item
		Node* ptrCurrent = m_ptrFirst;
		int counter = 0;
		while (counter != index)
		{
			ptrCurrent = ptrCurrent->ptrNext;
			counter++;
		}

		return ptrCurrent->data;
	}

	int operator[](int index)
	{
		return Get(index);
	}

private:
	void Free()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	Node* m_ptrFirst;
	Node* m_ptrLast;
	int m_itemCount;
};

#endif
