#include "SmartStaticArray.hpp"

#include "cuTEST/Menu.hpp"

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
	if (index > this->Size() || index < 0)
	{
		return false;
	}
	else
	{
		int i = MAX_SIZE -1;
		while (i > index)
		{
			m_data[i] = m_data[i - 1];
			i--;
		}
		m_data[index] = newItem;
		m_itemCount++;
		return true;
	}
}


bool SmartStaticArray::Extend( const SmartStaticArray& other )
{
	if (this->Size() + other.Size() > MAX_SIZE)
	{
		return false;
	}

	for (int i = 0; i < other.Size(); i++)
	{
		this->Push(other.Get(i));
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
	if (index >= m_itemCount || index < 0)
	{
		return false;
	}
	else
	{
		int i = index;
		while (i < MAX_SIZE-2)
		{
			m_data[i] = m_data[i + 1];
			i++;
		}
		m_data[i] = "";
		m_itemCount--;
		return true;
	}
}


string SmartStaticArray::Get( int index ) const
{
	if(index >= MAX_SIZE || index < 0)
	{
		return "";
	}
	else
	{
		return m_data[index]; // temp
	}
}


int SmartStaticArray::Size() const
{
	return m_itemCount; // temp
}


bool SmartStaticArray::IsFull() const
{
	if (this->Size() == MAX_SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
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
	return this->Get(index);
}


SmartStaticArray& SmartStaticArray::operator=( const SmartStaticArray& other )
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		this->m_data[i] = other.Get(i);
	}
	this->m_itemCount = other.Size();
    return *this; // placeholder
}

bool SmartStaticArray::operator==( const SmartStaticArray& other )
{
	if (this->Size() != other.Size())
	{
		return false;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (this->Get(i) != other.Get(i))
		{
			return false;
		}
	}

	return true;
}


bool SmartStaticArray::operator!=( const SmartStaticArray& other )
{
	return !( *this == other );
}
