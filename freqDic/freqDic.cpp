#include<iostream>
#include<fstream>
#include<unordered_map>
#include<algorithm>
#include<iterator>
#include<sstream>
#include<iomanip>




//частотный словарь
int main()
{
	std::unordered_map<std::string, int> dic;
	//std::ifstream file("input.txt");

	std::string TEST = "cat cat vasya a a a a Pow dog\n";
	std::stringstream file(TEST);


	std::string temp;
	while (file >> temp)
	{
		++(dic.try_emplace(temp, 0).first->second);
	}

	std::stringstream out;
	for (auto& [key, value] : dic)
	{
		out << std::setw(12) << std::left << key << ": " << std::right << value << " шт.\n";
	}
	printf("%s", out.str().c_str());
}