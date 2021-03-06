// CheckIfStringSameAfterRestructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>

// Solution 1: sort the string first, and then compare if both sorted string equal.
bool checkIfStringSameAfterRestructure_bySort(std::string &str1, std::string &str2)
{
	std::sort(str1.begin(), str1.end());
	std::sort(str2.begin(), str2.end());

	return str1 == str2;
}

// Solution 2: use map to count the chars and compare the count results.
void countString(std::string &str, std::map<std::string::value_type, int> &count_map)
{
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		std::map < std::string::value_type, int>::iterator pos = count_map.find(*it);
		if (pos == count_map.end())
		{
			count_map.insert(std::map <std::string::value_type, int>::value_type(*it, 1));
		}
		else
		{
			pos->second++;
		}
	}
}

bool checkIfStringSameAfterRestructure_bymap(std::string &str1, std::string &str2)
{
	std::map<std::string::value_type, int> str1_count_map;
	std::map<std::string::value_type, int> str2_count_map;

	countString(str1, str1_count_map);
	countString(str2, str2_count_map);

	return str1_count_map == str2_count_map;	
}

// Solution 3: count the chars and compare the count results.
bool checkIfStringSameAfterRestructure_bycount(std::string &str1, std::string &str2)
{
	if (str1.length() != str2.length())
	{
		return false;
	}

	static const int MAX_CHAR_NUMBER = 256;
	int counter[MAX_CHAR_NUMBER] = { 0 };

	for (std::string::size_type i = 0; i < str1.length(); ++i)
	{
		counter[str1[i]] ++;
	}

	for (std::string::size_type i = 0; i < str2.length(); ++i)
	{
		counter[str2[i]] --;
	}

	for (std::string::size_type i = 0; i < MAX_CHAR_NUMBER; ++i)
	{
		if (counter[i] != 0)
			return false;
	}
	return true;
}


int main()
{
	std::string str1("hello");
	std::string str2("olehl");
    std::cout << checkIfStringSameAfterRestructure_bySort(str1 ,str2) <<std::endl;

	str1 = "hello";
	str2 = "olehl";
	std::cout << checkIfStringSameAfterRestructure_bymap(str1, str2) << std::endl;

	str1 = "hello";
	str2 = "olehl";
	std::cout << checkIfStringSameAfterRestructure_bycount(str1, str2) << std::endl;

	str1 = "hello";
	str2 = "olehh";
	std::cout << checkIfStringSameAfterRestructure_bySort(str1, str2) <<std::endl;

	str1 = "hello";
	str2 = "olehh";
	std::cout << checkIfStringSameAfterRestructure_bymap(str1, str2) << std::endl;

	str1 = "hello";
	str2 = "olehh";
	std::cout << checkIfStringSameAfterRestructure_bycount(str1, str2) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
