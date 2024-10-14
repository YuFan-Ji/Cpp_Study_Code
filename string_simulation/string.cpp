#include"string.h"

namespace jyf
{
	const size_t string::npos = -1;

	//string();�������

	//���캯��
	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}

	//��������
	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}
	
	//��������
	//��ͳд��
	/*string::string(const string& s)
	{
		_str = new char[s._capacity + 1];
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
	}*/

	//�ִ�д��
	string::string(const string& s)
	{
		string tmp(s._str);
		swap(tmp);
	}

	//��ֵ���������
	//��ͳд��
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
	
	//�°汾
	string& string::operator=(string s)
	{
		swap(s);
		return *this;
	}

	//��size,��ֵc
	void string::resize(size_t newSize, char c)
	{
		if (newSize > _size)
		{
			// ���newSize���ڵײ�ռ��С������Ҫ���¿��ٿռ�
			if (newSize > _capacity)
			{
				reserve(newSize);
			}
			memset(_str + _size, c, newSize - _size);
		}
		_size = newSize;
		_str[newSize] = '\0';
	}

	//Ԥ���ռ�
	void string::reserve(size_t n)
	{
		// n��_capcacityС�Ͳ�����
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;

			_capacity = n;
		}
	}

	//[]����
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

	//β���ַ�
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

	//β���ַ���
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

	//���ؼӵ�
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

	//����λ�ò���
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

	//ɾ��
	void string::earse(size_t pos, size_t len)
	{
		assert(pos < _size);

		// n̫��, str̫Сpos����ȫɾ��
		if (pos + len >= _size)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else//ֻɾ��pos��һ���֣�ҪŲ����
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

	//����
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

	//���ڵĽ���
	void string::swap(string& str)
	{
		std::swap(_str, str._str);
		std::swap(_size, str._size);
		std::swap(_capacity, str._capacity);
	}

	//��ȡ�ִ�
	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size);

		//���,len�ĳ��ȴ���posλ�ÿ�ʼ֮��ĳ��ȣ��ʹ�posȡ����β
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

	//���⽻��
	void swap(string& s1, string& s2)
	{
		s1.swap(s2);
	}

	//����Ƚϵ�����
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

	//�������������룬����ȡ
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

	//getline��ȡ�ַ���
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



