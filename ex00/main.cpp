#include "easyfind.hpp"
#include <vector>



int main(void)
{
	{
		std::vector<int> array;
		array.push_back(10);
		array.push_back(8);
		array.push_back(7);
		array.push_back(6);
		array.push_back(4);
		array.push_back(2);
		array.push_back(1);
		int to_find;
		to_find = 0;
		for (int i = 0; i < 7; i++)
		{
			to_find = i * 2;
			try
			{
				std::cout << "Search: " << to_find << '\n';
				easyfind(array, to_find);
				std::cout << "Sucsess!" << '\n' << "-----------------" << '\n';
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				std::cout << "Failure!" << '\n' << "-----------------" << '\n';
			}
		}
	}
	return (0);
}