#include <iostream>
#include <exception>
#include <vector>
#include <string>
using namespace std;

string vBGA[10];

void RiskeyInsert(int index, string value)
{
	if (index < 0 || index >= 10)
	{
		throw out_of_range("Index is out of range");
	}
	vBGA[index] = value;
}

float Division(float a, float b) throw(string)
{
	if (b = 0)
	{
		throw string("No division by zero!");
	}
	return a / b;
}

int main()
{
	int index;
	string value;

	cout << "Index and value: ";
	cin >> index >> value;

	try
	{
		RiskeyInsert(index, value);
	}
	catch (const out_of_range& ex)
	{
		cout << "Error, out_of_range: " << ex.what() << endl;
	}

	float a = 5, b = 0;

	try
	{
		float result = Division(a, b);
	}
	catch (string message)
	{
		cout << "ERROR: " << message << endl;
	}




	vector<int> myVector;
	myVector.push_back(20);

	try
	{
		cout << myVector.at(2) << endl;
	}
	catch (const out_of_range& ex)
	{
		cout << "Error!" << endl;
		cout << ex.what() << endl;
	}

}