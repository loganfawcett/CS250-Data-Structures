#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	float balance = 0.0;
	// Create a queue of floats, named transactions
	queue<float> transactions;

	// Push some + and - floats into the transactions queue.
	transactions.push(15);
	transactions.push(-30);
	transactions.push(5.75);

	// Loop through all the transactions - while the queue is empty.
	// Within the loop, whatever amount is at the front of the queue,
	// add it to the balance and then pop it off the queue.
	while (!transactions.empty())
	{
		balance =+ transactions.front();
		cout << balance << " added to account.\n";
		transactions.pop();
	}

	cout << "Final balance: $" << balance << endl;

	return 0;
}