#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	for (int i = 4; i < 96; i++)
	{
		cout << "w[" << i << "] = new Wall(0.0f, 0.0f, 0.0f, 0.0f);" << endl;
	}
	return 0;
}