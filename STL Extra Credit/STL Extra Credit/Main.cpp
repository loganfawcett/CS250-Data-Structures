#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

int main()
{
	list<int> colors;

	ifstream input("bird.ppm");
	// Getting header
	string header, buffer;
	getline(input, buffer);
	header += buffer+"\n";
	getline(input, buffer);
	header += buffer + "\n";
	getline(input, buffer);
	header += buffer + "\n";
	getline(input, buffer);
	header += buffer + "\n";

	// Getting colors
	int r, g, b;
	double exposure;
	cout << "Select percentage for exposure (Ex: 10 for +10%):\n";
	cin >> exposure;
	exposure = exposure / 100;
	cout << "Processing image to " << 100 + (exposure * 100) << "% exposure...";
	while (input >> r >> g >> b)
	{
//	Increases exposure by % up to 255 per color

		if(r < 255* (1 - exposure))
		{
			colors.push_back(r*(1 + exposure));
		}
		else
		{
			colors.push_back(255);
		}
		if (g < 255 * (1 - exposure))
		{
			colors.push_back(g*(1 + exposure));
		}
		else
		{
			colors.push_back(255);
		}
		if (b < 255 * (1 - exposure))
		{
			colors.push_back(b*(1 + exposure));
		}
		else
		{
			colors.push_back(255);
		}
		
	}

	input.close();



	ofstream output("different.ppm");
	output << header;
	for(list<int>::iterator it = colors.begin();
		it != colors.end();
		it ++	)
	{
		output << *it << endl;
	}

	output.close();

	return 0;
}