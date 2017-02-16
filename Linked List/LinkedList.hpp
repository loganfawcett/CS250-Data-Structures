#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node
{
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
class LinkedList
{
    public:
    LinkedList() // done
    {
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount = 0;
    }

    ~LinkedList() // done
    {
        Free();
    }

    void Push( const T& newItem )
    {
		Node<T>* newNode = new Node<T>;
		newNode->data = newItem;
		
		if (m_ptrFirst == nullptr)
		{
			//Empty list
			m_ptrFirst = newNode;
			m_ptrLast = newNode;
		}
		else
		{
			// Not empty
			newNode->ptrPrev = m_ptrLast;
			m_ptrLast->ptrNext = newNode;
			m_ptrLast = newNode;
		}

		m_itemCount++;
    }

    bool Insert( int index, const T& newItem )
    {
		//	Error Checking.
		if (index < 0 || index > m_itemCount)
		{
			return false; //	Return new T item.
		}
		else if (index == m_itemCount)
		{
			this->Push(newItem);
			return true;
		}
		else
		{
			//	Create traversal pointer
			Node<T>* ptrCurrent = m_ptrFirst;
			int counter = 0;
			//	Traverse list to find index.
			while (counter < index)
			{
				ptrCurrent = ptrCurrent->ptrNext;
				counter++;
			}

			Node<T>* ptrNew = new Node<T>;
			ptrNew->data = newItem;

			ptrNew->ptrNext = ptrCurrent;
			ptrNew->ptrPrev = ptrCurrent->ptrPrev;
			ptrNew->ptrPrev->ptrNext = ptrNew;
			ptrCurrent->ptrPrev = ptrNew;

			m_itemCount++;
			return true;
		}



    }

    void Extend( const LinkedList& other )
    {
		Node<T>* ptrCurrent = other.m_ptrFirst;
		int count = 0;

		while (count < other.Size())
		{
			this->Push(other.Get(count));
			count++;
		}
    }

    bool Pop()
    {
		if (IsEmpty())
		{
			return false;
		}

		if (Size() > 1)
		{
			m_ptrLast = m_ptrLast->ptrPrev;
			delete m_ptrLast->ptrNext;
			m_ptrLast->ptrNext = nullptr;
			m_itemCount--;
			return true;
		}
		else
		{
			delete m_ptrFirst;
			m_ptrFirst = m_ptrLast = nullptr;
			m_itemCount--;
			return true;
		}
    }

    bool Remove( int index )
    {
		//	Error Checking.
		if (index < 0 || index >= m_itemCount)
		{
			return false; //	Return new T item.
		}
		else if (m_itemCount == 1)
		{
			return this->Pop();
		}
		else if (index == 0)
		{
			m_ptrFirst = m_ptrFirst->ptrNext;
			delete m_ptrFirst->ptrPrev;
			m_itemCount--;
			return true;
		}
		else
		{
			//	Create traversal pointer
			Node<T>* ptrCurrent = m_ptrFirst;
			int counter = 0;
			//	Traverse list to find index.
			while (counter < index)
			{
				ptrCurrent = ptrCurrent->ptrNext;
				counter++;
			}

			ptrCurrent->ptrPrev->ptrNext = ptrCurrent->ptrNext;
			ptrCurrent->ptrNext->ptrPrev = ptrCurrent->ptrPrev;
			delete ptrCurrent;
			m_itemCount--;
			return true;
		}
    }

    T Get( int index ) const
    {
		//	Error Checking.
		if (index < 0 || index >= m_itemCount)
		{
			return T(); //	Return new T item.
		}
		Node<T>* ptrCurrent = m_ptrFirst;
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

    int Size() const // done
    {
        return m_itemCount;
    }

    bool IsEmpty() const // done
    {
        return ( m_ptrFirst == nullptr );
    }

    T operator[]( int index ) // done
    {
        return Get( index );
    }

    LinkedList& operator=( const LinkedList& other )
    {
		Free();
		Node<T>* ptrCurrent = other.m_ptrFirst;
		int count = 0;

		while (count < other.Size())
		{
			this->Push(other.Get(count));
			count++;
		}
		return *this;
    }

    bool operator==( const LinkedList& other )
    {
		if (this->Size() != other.Size())
		{
			return false;
		}

		//	Create traversal pointer
		Node<T>* ptrCurrent = this->m_ptrFirst;
		Node<T>* ptrOther = other.m_ptrFirst;
		int counter = 0;
		//	Traverse list to find index.
		while (counter < this->Size())
		{
			if (ptrCurrent->data != ptrOther->data)
			{
				return false;
			}
			ptrCurrent = ptrCurrent->ptrNext;
			ptrOther = ptrOther->ptrNext;
			counter++;
		}
		return true;
    }

    bool operator!=( const LinkedList& other )
    {
        return !( (*this) == other );
    }

    private:
    void Free() // done
    {
        while ( !IsEmpty() )
        {
            Pop();
        }
    }

    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;
    int m_itemCount = 0;
};

#endif
