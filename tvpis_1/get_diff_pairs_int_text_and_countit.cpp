#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;


vector<char*> get_different_pairs_in_text(const string& text) {

	size_t text_len = text.size();
	list<char*> pairs;
	vector<char*> result;
	if (text_len < 2)
        return result;

	for (auto i = 0; i < text_len - 1; i++) {

		char* new_pair = new char[3];
        new_pair[0] = text.at(i);
		new_pair[1] = text.at(i + 1);
		new_pair[2] = '\0';
		
		bool have_that_pair = false;
		for(auto item:pairs)
		{
			if (strcmp(item, new_pair) == 0) {
				have_that_pair = true;
				break;
			}
		}
		
		if (!have_that_pair)
			pairs.push_back(new_pair);
    }
	
	auto list_len = pairs.size();
	result.resize(list_len);
	for(auto i = 0;i < list_len;i++)
	{
		result[i] = pairs.back();
		pairs.pop_back();
	}
	
    return result;
}


vector<pair<char*,int>> count_unic_pairs(const string& text,vector<char*> vector_of_pairs)
{
	size_t vector_lenght = vector_of_pairs.size();
	size_t text_lenght = text.size();

	vector<pair<char*, int>> result(vector_lenght);
	for(auto i = 0;i < vector_lenght;i++)
	{
		result[i].first = vector_of_pairs[i];
	}
	
	for(auto i = 0;i < vector_lenght;i++)
	{
		for(auto j = 0;j < text_lenght-1; j++)
		{
			char a = text.at(j);
			char b = text.at(j + 1);
			if (result[i].first[0] == a && result[i].first[1] == b)
				result[i].second++;
		}
		result[i].second = result[i].second;
	}
	return result;
}


void printVectorOfPairs(vector<char*> myVector)
{
	for (auto item : myVector)
	{
		cout <<"\""<< item<<"\"" << "\n";
	}
}


void printVectorOfPairsWithCounting(vector<pair<char*,int>> myVector)
{
	for(auto item: myVector)
	{
		cout << item.first << ":" << item.second << "\n";
	}
}

int main() {
	
	auto text = "asasdfdfghjkzxcvbnmqwertyu";
	vector<char*> mylist = get_different_pairs_in_text(text);

	auto aaa = count_unic_pairs(text, mylist);
	printVectorOfPairsWithCounting(aaa);
    return 0;
}