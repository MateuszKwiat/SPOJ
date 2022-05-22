#include <iostream>
#include <vector>
#include <cctype>

std::string decypher(std::string);


int main()
{
	std::string password;
	std::vector<std::string> passwords_array;

	while (std::cin >> password && password != "0")
	{
		password = decypher(password);
		passwords_array.push_back(password);
	}

	for (auto x : passwords_array)
		std::cout << x << std::endl;
}

// over-engineered af, but I really wanted to use iterators
std::string decypher(std::string password)
{
	std::string dec_pass;
	int j = 0;
	auto i = password.begin();
	i++;

	for (j = 1; i != password.end(); i++, j++)
	{
		if (j % 2 != 0)
		{
			if (*i == 'G')
			{
				if (*(i - 1) == 'A')
					dec_pass.push_back(tolower(*(i - 1) + 25));
				else
					dec_pass.push_back(tolower(*(i - 1) - 1));
			}
			else if (*i == 'H')
			{
				if (*(i - 1) >= 'L')
					dec_pass.push_back(tolower(*(i - 1) - 11));
				else
					dec_pass.push_back(tolower(*(i - 1) + 15));

			}
		}
		else
		{
			continue;
		}
	}

	return dec_pass;
}