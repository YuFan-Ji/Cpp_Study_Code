#include<iostream>
#include<stack>
#include<queue>
using namespace std;

#include "Stack.h"
#include "Queue.h"

void test_stack_queue()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	//这样子循环遍历栈
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	//这样子循环遍历队列
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

	deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);
	dq.push_back(5);
	dq.push_back(6);

	for (size_t i = 0; i < dq.size(); i++)
	{
		cout << dq[i] << " ";
	}
	cout << endl;
}

void test_op()
{
	srand(time(0));
	const int N = 1000000;
	vector<int> v1;
	vector<int> v2;
	v1.reserve(N);
	v2.reserve(N);

	deque<int> dq1;
	deque<int> dq2;


	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		//v1.push_back(e);
		//v2.push_back(e);
		dq1.push_back(e);
		dq2.push_back(e);
	}

	// 拷贝到vector排序，排完以后再拷贝回来
	int begin1 = clock();
	// 先拷贝到vector
	for (auto e : dq1)
	{
		v1.push_back(e);
	}

	// 排序
	sort(v1.begin(), v1.end());

	// 拷贝回去
	size_t i = 0;
	for (auto& e : dq1)
	{
		e = v1[i++];
	}

	int end1 = clock();

	int begin2 = clock();
	//sort(v2.begin(), v2.end());
	sort(dq2.begin(), dq2.end());

	int end2 = clock();
	printf("deque copy vector sort:%d\n", end1 - begin1);
	printf("deque sort:%d\n", end2 - begin2);
}

int main()
{
	//test_stack_queue();
	//test_op();
	//jyf::test_stack();
	jyf::test_queue();

}