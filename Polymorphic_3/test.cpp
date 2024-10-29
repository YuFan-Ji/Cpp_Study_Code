#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//
//class A
//{
//public:
//	virtual void func1()
//	{
//		cout << "A::func1" << endl;
//	}
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	virtual void func1()
//	{
//		cout << "B::func1" << endl;
//	}
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	virtual void func1()
//	{
//		cout << "C::func1" << endl;
//	}
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	virtual void func1()
//	{
//		cout << "D::func1" << endl;
//	}
//public:
//	int _d;
//};



class A
{
public:
	virtual void func1()
	{
		cout << "A::func1" << endl;
	}
public:
	int _a;
};

class B : virtual public A
{
public:
	virtual void func1()
	{
		cout << "B::func1" << endl;
	}

	virtual void func2()
	{
		cout << "B::func2" << endl;
	}
public:
	int _b;
};

class C : virtual public A
{
public:
	virtual void func1()
	{
		cout << "C::func1" << endl;
	}

	virtual void func2()
	{
		cout << "C::func2" << endl;
	}
public:
	int _c;
};

class D : public B, public C
{
public:
	virtual void func1()
	{
		cout << "D::func1" << endl;
	}
public:
	int _d;
};
////////////////////

//class A
//{
//public:
//	virtual void func1()
//	{
//		cout << "A::func1" << endl;
//	}
//public:
//	int _a;
//};
//
////class B : public A
//class B : virtual public A
//{
//public:
//	virtual void func1()
//	{
//		cout << "B::func1" << endl;
//	}
//
//	virtual void func2()
//	{
//		cout << "B::func2" << endl;
//	}
//public:
//	int _b;
//};
//
////class C : public A
//class C : virtual public A
//{
//public:
//	virtual void func1()
//	{
//		cout << "C::func1" << endl;
//	}
//
//	virtual void func2()
//	{
//		cout << "C::func2" << endl;
//	}
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	virtual void func1()
//	{
//		cout << "D::func1" << endl;
//	}
//
//	virtual void func3()
//	{
//		cout << "D::func3" << endl;
//	}
//public:
//	int _d;
//};

//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	return 0;
//}

// 纯虚函数：间接强制派生类重写虚函数
//class Car
//{
//public:
//	inline virtual void Drive() = 0;
//
//	int Func();
//
//	// virtual static  void Func1()
//	// {}
//};
//
//int Car::Func()
//{
//	int a = 0;
//	int b = 2;
//	return a + b;
//}
//
//class Benz :public Car
//{
//public:
//	inline virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	inline virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//
//class BYD :public Car
//{
//public:
//	inline virtual void Drive()
//	{
//		cout << "BYD-build year dream" << endl;
//	}
//};
//
//void Func(Car* p)
//{
//	p->Drive();
//	p->Func();
//}
//
//int main()
//{
//	Func(new Benz);
//	Func(new BMW);
//	Func(new BYD);
//
//	return 0;
//}

//class Car
//{
//public:
//	Car()
//		:_a(0)
//	{}
//
//	inline virtual void Drive()
//	{}
//
//private:
//	int _a = 0;
//};
//
//
//
//class Benz :public Car
//{
//public:
//	inline virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//
//
//void Func(Car* p)
//{
//	p->Drive();
//}
//
//int main()
//{
//	//Car c;
//	TestBSTree1();
//
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<int> add(vector<int>& a1, vector<int>& a2)
{
	if (a1.size() < a2.size()) return add(a2, a1);

	vector<int> a;

	int t = 0;
	for (int i = 0; i < a1.size(); i++)
	{
		t += a1[i];
		if (i < a2.size()) t += a2[i];
		a.push_back(t % 10);
		t /= 10;
	}

	if (t) a.push_back(t);

	return a;
}


//class Solution {
//public://450-231
//	int subarraysDivByK(vector<int>& nums, int k)
//	{
//		// 哈希表模拟前缀和数组
//		unordered_map<int, int> hash;
//
//		//使用前缀和数组
//		int sum = 0, ret = 0;
//		for (auto e : nums)
//		{
//			sum += e;
//			int r = (sum % k + k) % k;
//			if (hash.count(r)) ret += hash[r];
//			else hash[sum]++;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int> arr = { 4,5,0,-2,-3,1 };
//	Solution s;
//	int aaaaaa = s.subarraysDivByK(arr, 5);
//	return 0;
//}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> a1, a2;
	for (int i = s1.size() - 1; i >= 0; i--) a1.push_back(s1[i] - '0');
	for (int i = s2.size() - 1; i >= 0; i--) a2.push_back(s2[i] - '0');
	auto&& a = add(a1, a2);
	for (int i = a.size() - 1; i >= 0; i--) printf("%d", a[i]);
	return 0;
}