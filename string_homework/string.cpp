#include"string.h"


namespace bit
{
	const size_t string::npos = -1;

	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		strcpy(_str, str);

		_capacity = _size;
	}

	string::string(const string& s)
	{
		_str = new char[s._capacity + 1];
		strcpy(_str, s._str);
		
		_size = s._size;

		_capacity = s._capacity;
	}

	string& string::operator=(const string& s)
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
	}

	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	// access

	char& string::operator[](size_t index)
	{
		assert(index < _size);
		return _str[index];
	}
	const char& string::operator[](size_t index)const
	{
		assert(index < _size);
		return _str[index];
	}

	// 在pos位置上插入字符c/字符串str，并返回该字符的位置
	string& string::insert(size_t pos, char c)
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
		_str[pos] = c;

		_size++;
	}
	string& string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (pos + len > _capacity)
		{
			reserve(pos + len > 2 * _capacity ? pos + len : 2 * _capacity);
		}

		size_t end = pos + len;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}

		for (int i = 0; i < len; i++)
		{
			_str[pos + i] = str[i];
		}

		return *this;
	}

	void string::push_back(char c)
	{
		insert(_size, c);
	}

	string& string::operator+=(char c)
	{
		push_back(c);
		return *this;
	}

	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	void string::append(const char* str)
	{
		insert(_size, str);
	}

	size_t string::size()const
	{
		return _size;
	}
	size_t string::capacity()const
	{
		return _capacity;
	}
	bool string::empty()const
	{
		return _size == 0 && _capacity == 0;
	}

	void string::resize(size_t n, char c = '\0')
	{

	}

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::clear()
	{
		_str[0] = '\0';
		_size = 0;
	}

	string& string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);

		// n太大, str太小pos后面全删完
		if (pos + len >= _size)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			//删除，挪动数据
			size_t end = pos + len;
			while (end <= _size)
			{
				_str[end - len] = _str[end];
				end++;
			}
		}
		_size -= len;
		return *this;
	}

	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	// 返回c在string中第一次出现的位置

	size_t string::find(char c, size_t pos) const
	{
		assert(pos < _size);

		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == c)
			{
				return i;
			}
		}

		return npos;
	}

	// 返回子串s在string中第一次出现的位置

	size_t string::find(const char* s, size_t pos) const
	{
		assert(pos < _size);

		const char* ptr = strstr(_str + pos, s);

		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			return ptr - _str;
		}
	}

	//类外比较的重载
	bool operator== (const string& lhs, const string& rhs)
	{
		return strcmp(lhs.c_str(), rhs.c_str()) == 0;
	}

	bool operator< (const string& lhs, const string& rhs)
	{
		return strcmp(lhs.c_str(), rhs.c_str()) < 0;
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