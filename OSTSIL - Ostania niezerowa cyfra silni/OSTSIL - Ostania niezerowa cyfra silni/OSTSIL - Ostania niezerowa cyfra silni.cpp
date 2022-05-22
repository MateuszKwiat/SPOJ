// https://pl.spoj.com/problems/OSTSIL/

#include <iostream>

int factorial(int n);

int oncs(int n);

int shrink(int n);

int main()
{
	int tests;
	int value;

	std::cin >> tests;
	int* oncs_arr = new int[tests];

	for (int i = 0; i < tests; i++)
	{
		std::cin >> value;
		oncs_arr[i] = oncs(value);
	}

	for (int i = 0; i < tests; i++)
		std::cout << oncs_arr[i] << std::endl;

}

int factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

int shrink(int n) { return n / 10; }

int oncs(int n)
{
	int facto = factorial(n);

	if (facto % 10 != 0)
		return facto % 10;
	else
		while (true)
		{
			facto = shrink(facto);
			if (facto % 10 != 0)
				return facto % 10;
			else
				continue;
		}
}