//#include<iostream>
//#include<string>
//#include<windows.h>
//using namespace std;


//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//
//void Func()
//{
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const char* errmsg) {
//		cout << errmsg << endl;
//	}
//
//	cout << "yyyyyyyyy" << endl;
//}
//
//int main()
//{
//	try {
//		Func();
//	}
//	catch (int errmsg) {
//		cout << errmsg << endl;
//	}
//	catch (const char* errmsg) {
//		cout << errmsg << endl;
//	}
//
//	cout << "xxxxxxxxxx" << endl;
//
//	return 0;
//}


//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//
//void Func()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//}
//
//int main()
//{
//	try 
//	{
//		Func();
//	}
//	catch (int errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const char* errmsg) 
//	{
//		cout << errmsg << endl;
//	}
//	return 0;
//}

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		string s("Division by zero condition!");
//		throw s;
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//
//void Func()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const string errmsg)
//	{
//		cout << errmsg << endl;
//	}
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (int errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	return 0;
//}


//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//
//void Func()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const string errmsg)
//	{
//		cout << errmsg << endl;
//	}
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const string errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...)
//	{
//		cout << "其他异常！" << endl;
//	}
//	return 0;
//}


#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
using namespace std;

// 一般大型项目程序才会使用异常，下面我们模拟设计一个服务的几个模块
// 每个模块的继承都是 Exception 的派生类，每个模块可以添加自己的数据
// 最后捕获时，我们捕获基类就可以
class Exception
{
public:
    Exception(const string& errmsg, int id)
        : _errmsg(errmsg)
        , _id(id)
    {}
    virtual string what() const
    {
        return _errmsg;
    }
    int getid() const
    {
        return _id;
    }
protected:
    string _errmsg;
    int _id;
};

class SqlException : public Exception
{
public:
    SqlException(const string& errmsg, int id, const string& sql)
        : Exception(errmsg, id)
        , _sql(sql)
    {}
    virtual string what() const
    {
        string str = "SqlException:";
        str += _errmsg;
        str += "->";
        str += _sql;
        return str;
    }
private:
    const string _sql;
};

class CacheException : public Exception
{
public:
    CacheException(const string& errmsg, int id)
        : Exception(errmsg, id)
    {}
    virtual string what() const
    {
        string str = "CacheException:";
        str += _errmsg;
        return str;
    }
};

class HttpException : public Exception
{
public:
    HttpException(const string& errmsg, int id, const string& type)
        : Exception(errmsg, id)
        , _type(type)
    {}
    virtual string what() const
    {
        string str = "HttpException:";
        str += _type;
        str += ":";
        str += _errmsg;
        return str;
    }
private:
    const string _type;
};

void SQLMgr()
{
    if (rand() % 7 == 0)
    {
        throw SqlException("权限不足", 100, "select * from name = '张三'");
    }
    else
    {
        cout << "SQLMgr 调用成功" << endl;
    }
}

void CacheMgr()
{
    if (rand() % 5 == 0)
    {
        throw CacheException("权限不足", 100);
    }
    else if (rand() % 6 == 0)
    {
        throw CacheException("数据不存在", 101);
    }
    else
    {
        cout << "CacheMgr 调用成功" << endl;
    }
    SQLMgr();
}

void HttpServer()
{
    if (rand() % 3 == 0)
    {
        throw HttpException("请求资源不存在", 100, "get");
    }
    else if (rand() % 4 == 0)
    {
        throw HttpException("权限不足", 101, "post");
    }
    else
    {
        cout << "HttpServer 调用成功" << endl;
    }
    CacheMgr();
}

int main()
{
    srand(time(0));
    while (1)
    {
        this_thread::sleep_for(chrono::seconds(1));
        try {
            HttpServer();
        }
        catch (const Exception& e) // 这里捕获基类，基类对象和派生类对象都可以被捕获
        {
            cout << e.what() << endl;
        }
        catch (...)
        {
            cout << "Unknown Exception" << endl;
        }
    }

    return 0;
}
