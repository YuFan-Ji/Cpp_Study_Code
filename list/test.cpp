#include<list>
#include<vector>
#include<algorithm>

void test01()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_front(30);
	lt.push_front(88);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_back();
	lt.pop_back();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_front();
	lt.pop_front();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test02()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//list�Ŀռ䲻�������ģ�+5 �������ҵ�list�е�5��λ�ã�����д�������ᱨ���
	//lt.insert(lt.begin() + 5, 10);

	list<int>::iterator it = lt.begin();
	
	while (it != lt.end())
	{
		it++;
	}

	lt.insert(it, 89);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//����insert������������ʧЧ����Ϊ��������list��ǣ�����ݣ�it��ָ����߼�λ��Ҳ�������ı�
	//�����û�ҵ��᷵��last��λ��

	it = find(lt.begin(), lt.end(), 3);
	if (it != lt.end())
	{
		lt.insert(it, 30);

		// insert�Ժ�it��ʧЧ
		*it *= 100;
	}
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//���Ƕ���erase��ʹ�ù����������ʧЧ
	it = find(lt.begin(), lt.end(), 2);
	if (it != lt.end())
	{
		lt.erase(it);

		// erase�Ժ�itʧЧ�����Ŀռ��Ѿ�û�ˣ�����һ��Ұָ��
		//*it *= 100;
	}
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//Ҫ���������⣬������iterator������ֵ���գ�����it��ֵ
	it = lt.begin();
	
	//�������ǵ������ѣ�ɾ��list��ż��
	while (it != lt.end())
	{
		if (*it % 2 == 0)
		{
			//��������
			it = lt.erase(it);
		}
		else
			it++;

	}
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test03()
{
	list<int> lt;
	lt.push_back(5);
	lt.push_back(4);
	lt.push_back(3);
	lt.push_back(2);
	lt.push_back(1);

	//���е�sort�����ԣ���Ϊ���е������ǿ��ţ���������������������������������������˫��
	//sort(lt.begin(), lt.end());

	//��˿����ṩ��һ�ֵײ�Ϊ�鲢���������
	lt.sort();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//list�л����������ã����������ģ����к�����Ķ�������
	reverse(lt.begin(), lt.end());
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.reverse();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_op()
{
	srand(time(0));
	const int N = 5000000;
	vector<int> v;
	v.reserve(N);
	list<int> lt1;
	list<int> lt2;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		lt2.push_back(e);
		lt1.push_back(e);
	}

	// ������vector���������Ժ��ٿ�������
	int begin1 = clock();
	// �ȿ�����vector
	for (auto e : lt1)
	{
		v.push_back(e);
	}

	// ����
	sort(v.begin(), v.end());

	// ������ȥ
	size_t i = 0;
	for (auto& e : lt1)
	{
		e = v[i++];
	}

	int end1 = clock();

	int begin2 = clock();
	lt2.sort();
	int end2 = clock();

	printf("vector sort:%d\n", end1 - begin1);
	printf("list sort:%d\n", end2 - begin2);
}

void test04()
{
	int myints[] = { 17,89,7,14 };
	/*std::list<int> mylist(myints, myints + 4);

	//remove��ɾ���ض���ֵ���ҵ��˾�ɾ����û�ҵ���ʲôҲ����
	mylist.remove(890);

	for (auto e : mylist)
	{
		cout << e << " ";
	}
	cout << endl*/;

	//unique��ȥ�أ�һ��Ҫ��������Ҫȥ��Ч�ʸ�
	//mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
	//// 15.3,  72.25, 72.25, 73.0,  73.35

	//mylist.unique();           //  2.72,  3.14, 12.15, 12.77
	//// 15.3,  72.25, 73.0,  73.35



	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;

	// set some initial values:
	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4

	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);   // mylist2: 10 20 30

	for (auto e : mylist1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : mylist2)
	{
		cout << e << " ";
	}
	cout << endl << endl;

	it = mylist1.begin();
	++it;                         // points to 2

	//ת���Ǵ�iterator��λ�ã�ת����һ��list ������/��i��λ��/һ���������䣩
	// ȫ��ת��
	mylist1.splice(it, mylist2);

	// ����ת��
	//mylist1.splice(it, mylist2, ++mylist2.begin());
	//mylist1.splice(it, mylist2, ++mylist2.begin(), mylist2.end());

	//ת���Լ�
	//mylist1.splice(mylist1.begin(), mylist1, ++mylist1.begin(), mylist1.end());

	for (auto e : mylist1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : mylist2)
	{
		cout << e << " ";
	}
	cout << endl;
}

#include"list.h"

int main()
{
	//�÷����ԣ�
	
	//test01();
	//test02();
	//test03();
	//test_op();
	//test04();

	//ģ��ʵ�ֲ���
	//jyf::test_list01();
	//jyf::test_list02();
	//jyf::test_list03();
	jyf::test_list04();
	return 0;
}