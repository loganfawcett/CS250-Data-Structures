#include "SmartStaticArray.hpp"

SmartStaticArray::SmartStaticArray()
{
	m_itemCount = 0;
}

bool SmartStaticArray::Push( const string& newItem )
{
	if (m_itemCount == MAX_SIZE)
	{
		return false;
	}
	else
	{
		m_data[m_itemCount] = newItem;
		m_itemCount++;
		return true;
	}
}


bool SmartStaticArray::Insert( int index, const string& newItem )
{
	if (index >= this->Size() || index < 0)
	{
		return false;
	}
	else
	{
		int i = MAX_SIZE-1;
		while (i > index && m_data[index] != "")
		{
			m_data[i]= m_data[i-1];
			i++;
		}
		m_data[index] = newItem;
		m_itemCount++;
		return true;
	}
}


bool SmartStaticArray::Extend( const SmartStaticArray& other )
{
	for (int i = 0; i < other.Size(); i++)
	{
		this->Push(other.Get(i));
		if (this->Size() == MAX_SIZE)
		{
			return false;
		}
	}
	return true;
}


bool SmartStaticArray::Pop()
{
	if (m_itemCount == 0)
	{
		return false;
	}
	else
	{
		m_itemCount--;
		return true;
	}
}


bool SmartStaticArray::Remove( int index )
{
	if (index <= this->Size() || index < 0)
	{
		return false;
	}
	else
	{
		int i = index;
		while (i > index && m_data[index] != "")
		{
			m_data[i] = m_data[i + 1];
			i--;
		}
		m_itemCount--;
		return true;
	}
}


string SmartStaticArray::Get( int index ) const
{
	return m_data[index]; // temp
}


int SmartStaticArray::Size() const
{
	return m_itemCount; // temp
}


bool SmartStaticArray::IsFull() const
{
	return false; // temp
}

bool SmartStaticArray::IsEmpty() const
{
	if (this->Size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


string SmartStaticArray::operator[]( int index )
{
	return "temp"; // temp
}


SmartStaticArray& SmartStaticArray::operator=( const SmartStaticArray& other )
{
    SmartStaticArray blorp; // temp
    return blorp; // temp
}

bool SmartStaticArray::operator==( const SmartStaticArray& other )
{
	return false; // temp
}
