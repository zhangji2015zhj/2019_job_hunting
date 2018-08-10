#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
/*

//模板 
template <typename T_Out>
void split(const std::string &s, char delim, T_Out result)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
	{
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}
*/

/*

// #include <string>
// #include <sstream>

struct split
{
	enum empties_t
	{
		empties_ok,
		no_empties
	};
};

template <typename Container>
Container &split(
	Container &result,
	const typename Container::value_type &s,
	typename Container::value_type::value_type delimiter,
	split::empties_t empties = split::empties_ok)
{
	result.clear();
	std::istringstream ss(s);
	while (!ss.eof())
	{
		typename Container::value_type field;
		getline(ss, field, delimiter);
		if ((empties == split::no_empties) && field.empty())
			continue;
		result.push_back(field);
	}
	return result;
}

*/

template <typename Container>
Container &split(
	Container &result,
	const typename Container::value_type &s,
	typename Container::value_type::value_type delimiter,
	split::empties_t empties = split::empties_ok)
{
	result.clear();
	std::istringstream ss(s);
	while (!ss.eof())
	{
		typename Container::value_type field;
		getline(ss, field, delimiter);
		if ((empties == split::no_empties) && field.empty())
			continue;
		result.push_back(field);
	}
	return result;
}


////split

using namespace std;

int main()
{
	string sentence = "and i dsf.. .. good";
	istringstream iss(sentence);
	copy(istream_iterator<string>(iss), istream_iterator<string>(),
		 ostream_iterator<string>(cout, "\n"));

	vector<string> tokens;
	copy(istream_iterator<string>(iss),
		 istream_iterator<string>(),
		 back_inserter(tokens));

	vector<string> tokens1{istream_iterator<string>{iss},
						   istream_iterator<string>{}};

	list<string> vec;
	//split(vec,sentence,'.',split::no_empties);


	return 0;
}