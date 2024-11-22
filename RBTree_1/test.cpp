#include"RBTree_1.h"

#include<vector>


int main()
{
	const int N = 10000000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	RBTree<int, int> rbt;
	for (auto e : v)
	{
		rbt.Insert(make_pair(e, e));
	}
	cout << rbt.IsBalance() << endl;

	return 0;
}