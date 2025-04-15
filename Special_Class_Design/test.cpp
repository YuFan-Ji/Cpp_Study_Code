#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#include<map>

//class HeapOnly
//{
//public:
//	void Destroy()
//	{
//		delete this;
//	}
//private:
//	~HeapOnly()
//	{
//		//...
//	}
//};
//
//int main()
//{
//	//HeapOnly hp1;
//	//static HeapOnly hp2;
//	HeapOnly* hp3 = new HeapOnly;
//	//delete hp3;
//	hp3->Destroy();
//
//	return 0;
//}

class HeapOnly
{
public:
	static HeapOnly* CreateObj()
	{
		return new HeapOnly;
	}
private:
	HeapOnly()
	{
		//...
	}

	HeapOnly(const HeapOnly& hp) = delete;
	HeapOnly& operator=(const HeapOnly& hp) = delete;
};

//int main()
//{
//	//HeapOnly hp1;
//	//static HeapOnly hp2;
//	//HeapOnly* hp3 = new HeapOnly;
//	HeapOnly* hp3 = HeapOnly::CreateObj();
//	//HeapOnly copy(*hp3);
//
//	return 0;
//}


class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		StackOnly st;
		return st;
	}
private:
	StackOnly()
	{
		//...
	}

	// 对一个类实现专属operator new
	void* operator new(size_t size) = delete;
};
//
//int main()
//{
//	//StackOnly hp1;
//	//static StackOnly hp2;
//	//StackOnly* hp3 = new StackOnly;
//	StackOnly hp3 = StackOnly::CreateObj();
//	StackOnly copy(hp3);
//
//	//  new  operator new + 构造
//	// StackOnly* hp4 = new StackOnly(hp3);
//
//	return 0;
//}



// 饿汉模式:一开始(main函数之前)就创建单例对象
// 1、如果单例对象初始化内容很多，影响启动速度
// 2、如果两个单例类，互相有依赖关系。 
// 假设有A B两个单例类，要求A先创建，B再创建，B的初始化创建依赖A
namespace hungry
{
	class Singleton
	{
	public:
		// 2、提供获取单例对象的接口函数,创建静态成员变量
		static Singleton& GetInstance()
		{
			return _sinst;
		}

		void func();

		void Add(const pair<string, string>& kv)
		{
			_dict[kv.first] = kv.second;
		}

		void Print()
		{
			for (auto& e : _dict)
			{
				cout << e.first << ":" << e.second << endl;
			}
			cout << endl;
		}

	private:
		// 1、构造函数私有
		Singleton()
		{
			// ...
		}

		// 3、防拷贝
		Singleton(const Singleton& s) = delete;
		Singleton& operator=(const Singleton& s) = delete;

		map<string, string> _dict;
		// ...

		static Singleton _sinst;
	};

	Singleton Singleton::_sinst;
}


namespace lazy
{
	class Singleton
	{
	public:
		// 2、提供获取单例对象的接口函数
		static Singleton& GetInstance()
		{
			if (_psinst == nullptr)
			{
				// 第一次调用GetInstance的时候创建单例对象
				_psinst = new Singleton;
			}

			return *_psinst;
		}

		// 一般单例不用释放。
		// 特殊场景：1、中途需要显示释放  2、程序结束时，需要做一些特殊动作（如持久化）（GC）
		static void DelInstance()
		{
			if (_psinst)
			{
				delete _psinst;
				_psinst = nullptr;
			}
		}

		void Add(const pair<string, string>& kv)
		{
			_dict[kv.first] = kv.second;
		}

		void Print()
		{
			for (auto& e : _dict)
			{
				cout << e.first << ":" << e.second << endl;
			}
			cout << endl;
		}

		class GC
		{
		public:
			~GC()
			{
				lazy::Singleton::DelInstance();
			}
		};

	private:
		// 1、构造函数私有
		Singleton()
		{
			// ...
		}

		~Singleton()
		{
			cout << "~Singleton()" << endl;

			// map数据写到文件中
			FILE* fin = fopen("map.txt", "w");
			for (auto& e : _dict)
			{
				fputs(e.first.c_str(), fin);
				fputs(":", fin);
				fputs(e.second.c_str(), fin);
				fputs("\n", fin);
			}
		}

		// 3、防拷贝
		Singleton(const Singleton& s) = delete;
		Singleton& operator=(const Singleton& s) = delete;

		map<string, string> _dict;
		// ...

		static Singleton* _psinst;
		static GC _gc;
	};

	Singleton* Singleton::_psinst = nullptr;
	Singleton::GC Singleton::_gc;
}


int main()
{

	cout << &lazy::Singleton::GetInstance() << endl;
	cout << &lazy::Singleton::GetInstance() << endl;
	cout << &lazy::Singleton::GetInstance() << endl;


	lazy::Singleton::GetInstance().Add({ "xxx", "111" });
	lazy::Singleton::GetInstance().Add({ "yyy", "222" });
	lazy::Singleton::GetInstance().Add({ "zzz", "333" });
	lazy::Singleton::GetInstance().Add({ "abc", "333" });

	lazy::Singleton::GetInstance().Print();

	//lazy::Singleton::DelInstance();

	lazy::Singleton::GetInstance().Add({ "abc", "444" });
	lazy::Singleton::GetInstance().Print();

	//lazy::Singleton::DelInstance();

	return 0;
}