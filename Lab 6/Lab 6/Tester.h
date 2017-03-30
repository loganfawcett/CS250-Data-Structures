#include <iostream>
#include <string>
using namespace std;

#include "SortedList.h"

class Tester
{
public:
	void Start()
	{
		TestGetAt();
		TestPush();
		TestSize();
	}
private:
	bool TestGetAt()
	{
		int correct = 0;
		int possible = 0;



		SortedList<int> s1;
		try
		{
			possible++;
			s1.GetAt(0);
		}
		catch (const out_of_range& ex)
		{
			correct++;
		}

		s1.SortedPush(4);
		possible++;
		if (s1.GetAt(0) == 4)
		{
			correct++;
		}

		try
		{
			possible++;
			s1.GetAt(1);
		}
		catch (const out_of_range& ex)
		{
			correct++;
		}

		s1.SortedPush(5);
		s1.SortedPush(6);
		possible++;
		if (s1.GetAt(1) == 5)
		{
			correct++;
		}


		if (correct == possible)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool TestPush()
	{
		int correct = 0;
		int possible = 0;


		SortedList<int> s1;
		possible++;
		s1.SortedPush(3);
		if (s1.GetAt(0) == 3)
		{
			correct++;
		}

		possible++;
		s1.SortedPush(4);
		if (s1.GetAt(1) == 4)
		{
			correct++;
		}

		possible++;
		s1.SortedPush(4);
		if (s1.GetAt(1) == 4 && s1.GetAt(2) == 4)
		{
			correct++;
		}

		possible++;
		s1.SortedPush(1);
		if (s1.GetAt(1) == 1)
		{
			correct++;
		}


		if (correct == possible)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool TestSize()
	{
		// Test 1
		SortedList<int> s1;
		if (s1.Size() != 0)
		{
			cout << "Test failed: Size is not 0." << endl;
			return false;
		}

		// Test 2
		SortedList<int> s2;
		s2.SortedPush(3);
		if (s2.Size() != 1)
		{
			cout << "Test failed: Size is not 1." << endl;
			return false;
		}

		// Test 3
		SortedList<int> s3;
		s3.SortedPush(3);
		s3.SortedPush(4);
		s3.SortedPush(5);
		if (s2.Size() != 3)
		{
			cout << "Test failed: Size is not 3." << endl;
			return false;
		}

		cout << "All tests passed" << endl;
		return true;
	}
};