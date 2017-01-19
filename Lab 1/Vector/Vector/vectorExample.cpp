#include <iostream>
#include <vector>
#include <string>
using namespace std;

void AddIngredients(vector<string>& ingredients)
{
	ingredients.push_back("lettuce");
	ingredients.push_back("tomato");
	ingredients.push_back("mayo");
	ingredients.push_back("mustard");
	ingredients.push_back("bread");
}

void DisplayIngredients(const vector<string>& ingredients)
{
	for (int i = 0; i < ingredients.size(); i++)
	{
		cout << i << ".\t" << ingredients[i] << endl;
	}
}

int main()
{

	//Example code
	/*cout << "Array\n";
	int myNumbers[3];
	myNumbers[0] = 2;
	myNumbers[1] = 3;
	myNumbers[2] = 6;

	for (int i = 0; i < 3; i++)
	{
		cout << i << " = " << myNumbers[i] << endl;
	}

	cout << "\nVector\n";

	vector<int> myNumbers2;
	myNumbers2.push_back(2);
	myNumbers2.push_back(3);
	myNumbers2.push_back(6);

	for (int i = 0; i < myNumbers2.size(); i++)
	{
		cout << i << " = " << myNumbers2[i] << endl;
	}*/

	vector<string> ingredients;
	AddIngredients(ingredients);
	DisplayIngredients(ingredients);

	return 0;
}