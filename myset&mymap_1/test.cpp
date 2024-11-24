#include"mymap.h"
#include"myset.h"

#include<iostream>
using namespace std;



int main()
{
	jyf::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(2, 2));

	jyf::map<int, int>::iterator mit = m.begin();

	while (mit != m.end())
	{
		//mit->first = 1;
		mit->second = 2;

		cout << mit->first << ":" << mit->second << endl;
		++mit;
	}
	cout << endl;

	for (const auto& kv : m)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	jyf::set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(2);
	s.insert(12);
	s.insert(22);
	s.insert(332);
	s.insert(7);
	
	auto it = s.begin();
	while (it != s.end())
	{
		// Ӧ޸
		if (*it % 2 == 0)
		{
			*it += 10;
		}

		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (const auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}