// 1.2-ReverseString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>

// solution 1: create new string by reading the source string backward.
void reverse_by_newstring(char *str)
{
	int str_len = strlen(str);
	char *target_str = new char[str_len + 1];
	
	for (int i = str_len - 1, j = 0; i >= 0; --i, ++j)
	{
		target_str[j] = str[i];
	}
	target_str[str_len] = '\0';

	memcpy(str, target_str, str_len + 1);
}

// solution 2: switch position char by char.
void reverse_by_switch_char(char *str)
{
	int str_len = strlen(str);


	int head_index = 0;
	int tail_index = str_len - 1;

	for (; head_index < tail_index; ++head_index, --tail_index)
	{
		str[str_len] = str[head_index];
		str[head_index] = str[tail_index];
		str[tail_index] = str[str_len];
	}
	str[str_len] = '\0';	
}

int main()
{
	char test_string[] = "hello world!";
	reverse_by_newstring(test_string);
	std::cout << test_string << std::endl;

	reverse_by_switch_char(test_string);
	std::cout << test_string << std::endl;	
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
