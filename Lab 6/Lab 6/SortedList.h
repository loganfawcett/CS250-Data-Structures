#ifndef _SORTEDLIST_HPP
#define _SORTEDLIST_HPP

#include <iostream>
#include <exception>

template <typename T>
class Node
{
public:
	Node()
	{
		ptrNext = nullptr;
		ptrPrev = nullptr;
	}

	Node<T>* ptrNext;
	Node<T>* ptrPrev;

	T data;
};

template <typename T>
class SortedList
{
public:
	int Size()
	{
		return size;
	}

	void SortedPush(int n)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = n;

		if (ptrFirst == nullptr)
		{
			//Empty list
			ptrFirst = newNode;
		}
		else
		{
			Node<T>* ptrCurrent = ptrFirst;
			int counter = 0;
			if (counter < size && n < GetAt(counter))
			{
				newNode->ptrNext = ptrFirst;
				ptrFirst = newNode;
			}

			while (counter < size && n > GetAt(counter))
			{
				if (ptrCurrent->ptrNext == nullptr)
				{
					ptrCurrent->ptrNext = newNode;
					newNode->ptrPrev = ptrCurrent;
					newNode->ptrNext = nullptr;
				}
				else
				{
					ptrCurrent = ptrCurrent->ptrNext;
				}
				counter++;
			}

			if (counter > size)
			{
				newNode->ptrPrev = ptrCurrent->ptrPrev;
				ptrCurrent->ptrPrev = newNode;
			}

			
			//newNode->ptrNext = ptrCurrent;
			
		}

		size++;
		Display();
	}

	int GetAt(int index)
	{
		//	Error Checking.
		if (index < 0 || index >= size)
		{
			throw out_of_range("Index is out of range");
		}
		else if (index == 0)
		{
			return ptrFirst->data;
		}
		Node<T>* ptrCurrent = ptrFirst;
		int counter = 0;
		//	Traverse list to find index.
		while (counter < index && ptrCurrent->ptrNext != nullptr )
		{
			ptrCurrent = ptrCurrent->ptrNext;
			counter++;
		}
		//	Return data at index.
		return ptrCurrent->data;
	}

	void Display()
	{
		int i = 0;
		while (i < size)
		{
			try
			{
				cout << GetAt(i);
			}
			catch (const out_of_range& ex)
			{
			}

			i++;
		}
		cout << endl;
	}

private:
	Node<T>* ptrFirst;
	int size = 0;

		friend class Tester;
};

#endif