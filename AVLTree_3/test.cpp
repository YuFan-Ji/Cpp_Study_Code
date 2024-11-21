#include"AVLTree.h"
#include<vector>

int main()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };

	// ���ⳡ��������˫��
	//int a[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 4};

	//���ֵ����
	const int N = 10000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand());
	}


	AVLTree<int, int> t;
	for (auto e : v)
	{
		/*if (e == 18)
		{
			int x = 0;
		}*/

        t.Insert(make_pair(e, e));

		cout << "Insert: " << e << "�Ƿ�ƽ�⣺" << t.IsBalance() << endl;
	}
	
	return 0;
}