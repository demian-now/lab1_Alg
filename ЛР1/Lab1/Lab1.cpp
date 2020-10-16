#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	BiList Test;
	for (int i = 0; i < 3; i++)
		Test.push_back(i);
	Test.print_to_console();
	Test.reverse();
	Test.print_to_console();
	cout << " " << Test.at(0);
}
