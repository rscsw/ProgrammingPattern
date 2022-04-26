#include <iostream>

using namespace std;

template<typename T>
T sum(T a, T b)
{
	return a + b;
}

int main()
{
	cout << sum<double>(3.9, 4.9) << endl;

	return 0;
}