#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<list>
#include<map>
using namespace std;


//class string
//{
//public:
//	char& operator[] (size_t pos)
//	{
//		assert(pos < _size);
//		return _str[pos];
//	}
//private:
//  char buff[16];
//	char* _str;
//	size_t _size;
//	size_t _capacity;
//};


// C++20开始支持
//void func1(auto x);

//auto func3()
//{
//	auto y = func4();
//	return y;
//}
//
//auto func2()
//{
//	auto x = func3();
//	//...
//	return x;
//}

//int main()
//{
//	//auto ret1 = func2();
//	string s1("hello world");
//
//	// 下标+[]
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		s1[i]++;
//	}
//
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	// 迭代器 -- 像指针一样的对象
//	string::iterator it1 = s1.begin();
//	while (it1 != s1.end())
//	{
//		(*it1)--;
//
//		++it1;
//	}
//	cout << endl;
//
//	it1 = s1.begin();
//	while (it1 != s1.end())
//	{
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//
//	int i = 0;
//	int j = i;
//	// 自动推导类型 C++11
//	auto z = i;   // int
//	auto x = 1.1; // double
//	auto p = &i;  // int*
//	int& r1 = i;
//	auto r2 = r1;  // int
//	auto& r3 = r1; // int&
//	//auto r4;       // 报错
//
//	//list<int>::iterator it = lt.begin();
//	auto it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// auto语法糖
//	// 简化代码，替代写起来长的类型
//	std::map<std::string, std::string> dict;
//	//std::map<std::string, std::string>::iterator dit = dict.begin();
//	auto dit = dict.begin();
//

//auto fun(int i)
//{
//	return i + 1;
//}
//
//
//int main()
//{
//	auto t1 = 1;
//	auto t2 = 1.1;
//	
//	auto t3 = &t1;
//	auto& t4 = t2;
//	//auto t4;
//	// 
//	// 	auto s = fun(1);
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//
//	list<int>::iterator it = lt.begin();
//
//	auto it2 = lt.begin();
//
//	string sl("hellow world");
//	/*for (auto ch : sl)
//	{
//		cout << ch;
//	}
//	cout << endl;*/
//
//	for (auto x : lt)
//	{
//		cout << x;
//	}
//	cout << endl;
//	for (auto x : lt)
//	{
//		x++;
//		cout << x;
//	}
//	cout << endl;
//	for (auto x : lt)
//	{
//		cout << x;
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	std::string st;
//	st = "hellow world";
//
//	auto it = st.begin();
//	
//	while (it != st.end())
//	{
//		cout << *it;
//		++it;
//	}
//	cout << endl;
//}

//int main()
//{
//	std::string st = "hellow world";
//
//	std::string::reverse_iterator it = st.rbegin();
//
//	while (it != st.rend())
//	{
//		cout << *it;
//		//相当于反向++了
//		++it;
//	}
//	cout << endl;
//
//	return 0;
//}
//
//class string
//{
//public:
//	char& operator[](string st)
//	{
//
//	}
//private:
//	char* ptr;
//	size_t size;
//	size_t capacity;
//};

//int main()
//{
//	try
//	{
//		string s1("hello world11111");
//		cout << s1.size() << endl;
//		cout << s1.length() << endl;
//		cout << s1.max_size() << endl;
//		cout << s1.capacity() << endl;
//		cout << endl << endl;
//
//		s1.clear();
//		cout << s1.size() << endl;
//		cout << s1.capacity() << endl;
//
//		//s1[20];
//
//		s1.at(20);
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	string st = "hellow world";
//	for (size_t i = 0; i < st.size(); i++)
//	{
//		st.at(i) += 1;
//		cout << st.at(i);
//	}
//	cout << endl;
//}

//int main()
//{
//	
//	string s1("hello world11111");
//
//	char c = s1.back();
//	cout << c << endl;
//
//	s1.back() = '2';
//	cout << s1 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s = "Hello";
//	s.append("World", 1, 3);
//	s.append(100, 'c');
//	cout << s << endl;
//
//	string s3("hello");
//	s3 += ',';
//	s3 += "world";
//	cout << s3 << endl;
//}

//int main()
//{
//	string st1 = "hellow world";
//	cout << st1 << endl;
//	
//	st1.insert(6, " happy i am");
//	cout << st1 << endl;
//
//	string st2 = "abcdefg";
//	st1.insert(2, st2, 1, 2);
//	cout << st1 << endl;
//
//	st1.insert(3, 5, 'z');
//	cout << st1 << endl;
//
//	st1.insert(st1.begin() + 5, st2.begin(), st2.begin() + 2);
//	cout << st1 << endl;
//
//	cout << endl;
//	st1.erase(0, 10);
//	cout << st1 << endl;
//
//	st1.erase();
//	cout << st1 << endl;
//
//	string st3 = "aabbcc", st4 = "gghhjj";
//	cout << st3 << st4 << endl;
//
//	st3.swap(st4);
//	cout << st3 << st4 << endl;
//
//	swap(st3, st4);
//	cout << st3 << st4 << endl;
//	return 0;
//}
//
//int main()
//{
//	
//	string s1;
//	// 提前开空间，避免扩容
//	s1.reserve(200);
//	return 0;
//}

//int main()
//{
//	string s1("11111111111111111111");
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	// 删除
//	// n < size
//	s1.resize(15);
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	// 插入
//	// size < n < capacity
//	s1.resize(25, 'x');
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	// n > capacity
//	s1.resize(40, 'x');
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;
//
//	string s2("Test.cpp");
//	FILE* fout = fopen(s2.c_str(), "r");
//	char ch = fgetc(fout);
//	while (ch != EOF)
//	{
//		cout << ch;
//		ch = fgetc(fout);
//	}
//
//	/*const char* p1 = "xxxxx";
//	int* p2 = nullptr;
//	cout << (void*)p1 << endl;
//	cout << p2 << endl;*/
//
//	string s3("test.cpp.zip");
//	size_t pos = s3.rfind('.');
//	if (pos != string::npos)
//	{
//		string sub = s3.substr(pos);
//		cout << sub << endl;
//	}
//
//	// 
//	std::string str("Please, replace the vowels in this sentence by asterisks.");
//	std::size_t found = str.find_first_not_of("aeiou");
//	while (found != std::string::npos)
//	{
//		str[found] = '*';
//		found = str.find_first_not_of("aeiou", found + 1);
//	}
//
//	std::cout << str << '\n';
//
//	return 0;
//}


//int main()
//{
//	string s1 = "hellow world";
//
//	string s2 = s1.substr(7, 1);
//	cout << s2 << endl;
//
//	s2 = s1.substr(7);
//	cout << s2 << endl;
//
//	return 0;
//}

//int main()
//{
//	std::string firstlevel("com");
//	std::string secondlevel("cplusplus");
//	std::string scheme("http://");
//	std::string hostname;
//	std::string url;
//
//	hostname = "www." + secondlevel + '.' + firstlevel;
//	url = scheme + hostname;
//
//	std::cout << url << '\n';
//
//	return 0;
//}

int main()
{
    string str;
    //cin >> str;
    //getline(cin, str, '#');
    getline(cin, str);

    return 0;
}

