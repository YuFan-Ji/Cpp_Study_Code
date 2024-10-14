#include"string.h"

namespace jyf
{
	const size_t string::npos = -1;

	//string();构造相关

	//构造函数
	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}

	//析构函数
	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}
	
	//拷贝构造
	//传统写法
	/*string::string(const string& s)
	{
		_str = new char[s._capacity + 1];
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
	}*/

	//现代写法
	string::string(const string& s)
	{
		string tmp(s._str);
		swap(tmp);
	}

	//赋值运算符重载
	//传统写法
	/*string& string::operator=(const string& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);

			_size = s._size;
			_capacity = s._capacity;
		}

		return *this;
	}*/
	
	//新版本
	string& string::operator=(string s)
	{
		swap(s);
		return *this;
	}

	//改size,赋值c
	void string::resize(size_t newSize, char c)
	{
		if (newSize > _size)
		{
			// 如果newSize大于底层空间大小，则需要重新开辟空间
			if (newSize > _capacity)
			{
				reserve(newSize);
			}
			memset(_str + _size, c, newSize - _size);
		}
		_size = newSize;
		_str[newSize] = '\0';
	}

	//预开空间
	void string::reserve(size_t n)
	{
		// n比_capcacity小就不开了
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;

			_capacity = n;
		}
	}

	//[]遍历
	char string::operator[](size_t i)
	{
		assert(i < _size);
		return _str[i];
	}

	const char string::operator[](size_t i) const
	{
		assert(i < _size);
		return _str[i];
	}

	//尾插字符
	void string::push_back(char ch)
	{
		/*if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}

		_str[_size] = ch;
		_size++;*/

		insert(_size, ch);
	}

	//尾插字符串
	void string::append(const char* str)
	{
		/*size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len > _capacity ? _size + len : 2 * _capacity);
		}
		
		strcpy(_str + _size, str);
		_size += len;*/

		insert(_size, str);
	}

	//重载加等
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	//任意位置插入
	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);

		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = ch;

		_size++;
	}

	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);

		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}

		size_t end = _size + len;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}

		for (int i = 0; i < len; i++)
		{
			_str[pos + i] = str[i];
		}

		_size += len;
	}

	//删除
	void string::earse(size_t pos, size_t len)
	{
		assert(pos < _size);

		// n太大, str太小pos后面全删完
		if (pos + len >= _size)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else//只删除pos后一部分，要挪数据
		{
			size_t end = pos + len;
			while (end <= _size)
			{
				_str[end - len] = _str[end];
				end++;
			}

			_size -= len;
		}
	}

	//查找
	size_t string::find(char ch, size_t pos)
	{
		assert(pos < _size);
		
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}

		return npos;
	}

	size_t string::find(const char* str, size_t pos)
	{
		assert(pos < _size);

		const char* ptr = strstr(_str + pos, str);

		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			return ptr - _str;
		}
	}

	//类内的交换
	void string::swap(string& str)
	{
		std::swap(_str, str._str);
		std::swap(_size, str._size);
		std::swap(_capacity, str._capacity);
	}

	//获取字串
	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size);

		//如果,len的长度大于pos位置开始之后的长度，就从pos取到结尾
		if (len > _size - pos)
		{
			len = _size - pos;
		}

		jyf::string sub;
		sub.reserve(len);
		
		for (int i = 0; i < len; i++)
		{
			sub += _str[pos + i];
		}

		return sub;
	}
	////////////////////////////////////////////////////////////////////////

	//类外交换
	void swap(string& s1, string& s2)
	{
		s1.swap(s2);
	}

	//类外比较的重载
	bool operator== (const string& lhs, const string& rhs)
	{
		return strcmp(lhs.c_str(), rhs.c_str()) == 0;
	}

	bool operator!= (const string& lhs, const string& rhs)
	{
		return !(lhs == rhs);
	}

	bool operator> (const string& lhs, const string& rhs)
	{
		return !(lhs <= rhs);
	}

	bool operator>= (const string& lhs, const string& rhs)
	{
		return !(lhs < rhs);
	}

	bool operator< (const string& lhs, const string& rhs) 
	{
		return strcmp(lhs.c_str(), rhs.c_str()) < 0;
	}

	bool operator<= (const string& lhs, const string& rhs)
	{
		return lhs < rhs || lhs == rhs;
	}

	//类外重载流插入，流提取
	ostream& operator<< (ostream& os, const string& str)
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			os << str[i];
		}
		return os;
	}

	istream& operator>> (istream& is, string& str)
	{
		str.clear();

		char ch = is.get();

		while (ch != ' ' && ch != '\n')
		{
			str += ch;
			ch = is.get();
		}

		return is;
	}

	//getline获取字符串
	istream& getline(istream& is, string& str, char delim)
	{
		str.clear();

		int i = 0;
		char buff[256];

		char ch;
		ch = is.get();
		while (ch != delim)
		{
			buff[i++] = ch;

			if (i == 255)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}

			ch = is.get();
		}

		if (i > 0)
		{
			buff[i] = '\0';
			str += buff;
		}

		return is;
	}
}



