#include "StudentTable.hpp"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/* DONE */ StudentTable::StudentTable()
{
    m_collisionMethod = LINEAR; // default
    for ( int i = 0; i < TABLE_SIZE; i++ )
    {
        // Initialize students
        m_students[i].key = -1;
        m_students[i].value = "";
    }
}

/* DONE */ void StudentTable::SetCollisionMethod( CollisionMethod cm )
{
    cout << "Collision method: " << cm << endl << endl;
    m_collisionMethod = cm;
	count = 0;
}

/* Insert
Take in the studentId (key) and name (value), and
use your hash function to figure out an index
for this new value.
Then, set the values of the Student object in the array.
*/
void StudentTable::Insert( int studentId, const string& name )
{
	
    // Generate index from the studentId
	int index;
	if (m_collisionMethod == LINEAR)
	{
		index = LinearProbe(studentId);
	}
	else if (m_collisionMethod == QUADRATIC)
	{
		int addValue = 0;
		index = QuadraticProbe(studentId, addValue);
	}
	else if (m_collisionMethod == DOUBLE)
	{
		index = HashFunction(studentId);
	}

    // Insert into the m_students array
	m_students[index].value = name;
	m_students[index].key = studentId;
}

/* DONE */ void StudentTable::Output( const string& filename )
{
    cout << "Output table to: " << filename << endl << endl;
	//cout << "Count: " << count << endl;

    ofstream output( filename );
    for ( int i = 0; i < TABLE_SIZE; i++ )
    {
        output << i << ".";
        if ( i < 10 )
        {
            output << "   ";
        }
        else if ( i < 100 )
        {
            output << "  ";
        }
        else
        {
            output << " ";
        }

        if ( m_students[i].key != -1 )
        {
            output << "Student ID: " << m_students[i].key << " \t Student Name: " << m_students[i].value;
        }
        output << endl;
    }
    output.close();
}

/* HashFunction
Take in the key and generate an index.
This function should handle collisions, and
the returned index should be the index of an
available "slot" in the array.

Use an if statement to decide which collision
method to use.

if ( m_collisionMethod == LINEAR ) // ...
*/
int StudentTable::HashFunction( int key )
{
	int index = key % 11;
	count++;
	while (m_students[index].value != "")
	{
		index += HashFunction2(key);
		count++;
		if (index >= TABLE_SIZE)
		{
			index -= TABLE_SIZE;
		}
	}
	return index;
}

/* Linear probing
    You can use my function prototype or write your own.
*/
int StudentTable::LinearProbe( int key )
{
	int index = key % TABLE_SIZE;
	count++;
	while (m_students[index].value != "")
	{
		if (index >= TABLE_SIZE)
		{
			index = 0;
		}
		index++;
		count++;
	}
	return index;
}

/* Quadratic probing
    You can use my function prototype or write your own.
*/
int StudentTable::QuadraticProbe( int key, int& addValue )
{
	int index = (key % TABLE_SIZE) + addValue * addValue;
	count++;
	if (m_students[index].value == "")
	{
		return index;
	}
	else
	{
		addValue++;
		return QuadraticProbe(key, addValue);
	}
}

/* Double hashing
    You can use my function prototype or write your own.
*/
int StudentTable::HashFunction2( int key )
{
	return 7 - (key % 7);
	count++;
}