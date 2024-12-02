#include <iostream>
using namespace std;

#include"UnOrderedSet.h"
#include"UnOrderedMap.h"

int main()
{
	jyf::unordered_set<int> us;
	us.insert(3);
	us.insert(1);
	us.insert(3);
	us.insert(4);
	us.insert(5);
	us.insert(0);

	jyf::unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		// �����޸�key
		//*it += 10;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	jyf::unordered_map<string, string> dict;
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("left", "���"));
	dict.insert(make_pair("insert", "����"));
	dict.insert(make_pair("sort", "xxx"));

	jyf::unordered_map<string, string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		// �����޸�key
		//dit->first += 'x';
		dit->second += 'x';

		cout << dit->first << ":" << dit->second << endl;


		++dit;
	}
	cout << endl;

	dict["sort"] = "����";
	dict["insert"] = "����";
	dict["string"] = "�ַ���";
	dict["right"];

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	return 0;
}