#include <iostream>
#include <exception>
#include <vector>
#include <string>
using namespace std;


struct FoodException : public exception
{
	FoodException(const string& message)
	{
		m_message = message;
	}

	const char* what()
	{
		return m_message.c_str();
	}

private:
	string m_message;
};

void Eat(string food)
{
	if (food == "cat")
	{
		throw FoodException("Cannot eat " + food + "!");
	}
	cout << "Ate " << food << endl;
}

int main()
{
	string food;
	cout << "Enter food: ";
	cin >> food;

	try
	{
		Eat(food);
	}
	catch (FoodException ex)
	{
		cout << "FoodException: " << ex.what() << endl;
	}

	return 0;
}