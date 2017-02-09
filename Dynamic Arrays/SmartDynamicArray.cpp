#include "SmartDynamicArray.hpp"

#include "cuTEST/Menu.hpp"

SmartDynamicArray::SmartDynamicArray() : m_itemCount(0), m_arraySize(0), m_data(nullptr)
{
}

SmartDynamicArray::~SmartDynamicArray()
{
	Free();
}

bool SmartDynamicArray::Push(const string& newItem)
{
	if (m_itemCount == m_arraySize)
	{
		Resize();
	}

	m_data[m_itemCount] = newItem;
	m_itemCount++;
	return true;
}


bool SmartDynamicArray::Insert(int index, const string& newItem)
{
	if (m_itemCount == m_arraySize)
	{
		Resize();
	}
	if (index < 0 || index > this->Size())
	{
		return false;
	}

	int i = m_arraySize - 1;
	while (i > index)
	{
		m_data[i] = m_data[i - 1];
		i--;
	}
	m_data[index] = newItem;
	m_itemCount++;
	return true;
}


bool SmartDynamicArray::Extend(const SmartDynamicArray& other)
{
	Resize(this->Size() + other.Size());

	for (int j = 0; j < other.Size(); j++)
	{
		this->Push(other.Get(j));
	}
	return true;
}


bool SmartDynamicArray::Pop()
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


bool SmartDynamicArray::Remove(int index)
{
	if (index >= m_itemCount || index < 0)
	{
		return false;
	}
	else
	{
		int i = index;
		while (i < m_arraySize - 2)
		{
			m_data[i] = m_data[i + 1];
			i++;
		}
		m_data[i] = "";
		m_itemCount--;
		return true;
	}
}


string SmartDynamicArray::Get(int index) const
{
	if (index >= m_arraySize || index < 0)
	{
		return "";
	}
	else
	{
		return m_data[index]; // temp
	}
}


int SmartDynamicArray::Size() const
{
	return m_itemCount; // temp
}

int SmartDynamicArray::GetMaxSize() const
{
	return -1; // temp
}

bool SmartDynamicArray::IsFull() const
{
	if (this->Size() == m_arraySize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SmartDynamicArray::IsEmpty() const
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


string SmartDynamicArray::operator[](int index)
{
	return this->Get(index);
}

SmartDynamicArray& SmartDynamicArray::operator=(const SmartDynamicArray& other)
{
	Free();
	Resize(other.Size());
	for (int i = 0; i < m_arraySize; i++)
	{
		this->m_data[i] = other.Get(i);
	}
	return *this; // placeholder
}

bool SmartDynamicArray::operator==(const SmartDynamicArray& other)
{
	if (this->Size() != other.Size())
	{
		return false;
	}

	for (int i = 0; i < m_arraySize; i++)
	{
		if (this->Get(i) != other.Get(i))
		{
			return false;
		}
	}

	return true;
}

bool SmartDynamicArray::operator!=(const SmartDynamicArray& other)
{
	return false; // temp
}

void SmartDynamicArray::Free()
{
}

void SmartDynamicArray::Resize()
{
	Resize(m_arraySize+10);
}


void SmartDynamicArray::Resize(int newSize)
{
	string* newArray = new string[newSize];

	for (int i = 0; i < this->Size(); i++)
	{
		newArray[i] = this->m_data[i];
	}
	Free();
	m_data = newArray;
	m_arraySize = newSize;
}




