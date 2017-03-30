#ifndef _SORTEDLIST_HPP
#define _SORTEDLIST_HPP

#include <iostream>

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
			while (n > GetAt(counter))
			{
				ptrCurrent = ptrCurrent->ptrNext;
				counter++;
			}

			newNode->ptrNext = ptrCurrent;
			newNode->ptrPrev = ptrCurrent->ptrPrev;
			ptrCurrent->ptrPrev = newNode;
		}

		size++;
	}

	int GetAt(int index)
	{
		//	Error Checking.
		if (index < 0 || index == size)
		{
			throw out_of_range("Index is out of range");
		}
		Node<T>* ptrCurrent = ptrFirst;
		int counter = 0;
		//	Traverse list to find index.
		while (counter < index)
		{
			ptrCurrent = ptrCurrent->ptrNext;
			counter++;
		}
		//	Return data at index.
		return ptrCurrent->data;
	}

private:
	Node<T>* ptrFirst;
	int size = 0;

		friend class Tester;
};

#endif