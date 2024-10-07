#pragma once

class Stack1
{
	// 成员函数
	void Init(int n = 4);
	
	// 成员变量
	int* array;
	size_t capacity;
	size_t top;
}; // 分号不能省略
