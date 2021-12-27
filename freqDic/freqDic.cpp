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

	std::string TEST = "cat, cat. vasya; a a a& a? Pow dog\n";
	std::stringstream file(TEST);


	std::string temp;
	while (file >> temp)
	{
		temp.erase(std::remove_if(temp.begin(), temp.end(), [](auto ch) {return not std::isalpha(ch); }),temp.end());
		++(dic.try_emplace(temp, 0).first->second);
	}

	std::vector<std::pair<std::string, int>> sorted;
	sorted.reserve(dic.size());
	std::move(dic.begin(), dic.end(), std::back_inserter(sorted));
	std::sort(sorted.begin(), sorted.end(), [](auto a, auto b) {return a.second > b.second; });
	std::stringstream out;

	for (auto& [key, value] : sorted)
	{
		out << std::setw(12) << std::left << key << ": " << std::right << value << " шт.\n";
	}
	std::printf("%s", out.str().c_str());
	
}