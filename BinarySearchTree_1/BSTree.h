#pragma once

template<class K>
struct BSTreeNode
{
	BSTreeNode(const K& key)
		: _key(key)
		, _left(nullptr)
		, _right(nullptr)
	{}
	
	K _key;
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;

public:
	BSTree()
		:_root(nullptr)
	{}

	bool Insert(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;

		if (cur == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		else
		{
			while (cur)
			{
				if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key);
			if (key < parent->_key)
			{
				parent->_left = cur;
			}
			else
			{
				parent->_right = cur;
			}
			
			return true;
		}
	}

	void InOrder()
	{
		InOrder(_root);
		cout << endl;
	}

	void InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		InOrder(root->_left);
		cout << root->_key << " ";
		InOrder(root->_right);
	}

	bool Find(const K& key)
	{
		Node* cur = _root;

		while (cur)
		{
			if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}

		return false;
	}

	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		
		while (cur)
		{
			if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_right == cur)
						{
							parent->_right = cur->_right;
						}
						else
						{
							parent->_left = cur->_right;
						}
					}
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_right == cur)
						{
							parent->_right = cur->_left;
						}
						else
						{
							parent->_left = cur->_left;
						}
					}
				}
				else
				{
					Node* parent = cur;
					Node* left_Max = cur->_left;

					while (left_Max->_right)
					{
						parent = left_Max;
						left_Max = left_Max->_right;
					}

					swap(left_Max->_key, cur->_key);

					if (parent->_right == left_Max)
					{
						parent->_right = left_Max->_left;
					}
					else
					{
						parent->_left = left_Max->_left;
					}

					cur = left_Max;
				}

				delete cur;
				return true;
			}
		}
		return false;
	}

private:
	Node* _root;
};

void test01()
{
	int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };

	BSTree<int> t;
	for (auto e : arr)
	{
		t.Insert(e);
	}

	t.InOrder();

	int a = t.Find(2);
	cout << a << endl;

	for (auto e : arr)
	{
		cout << t.Find(e) << " ";
	}
	cout << endl;

	t.Erase(4);
	t.InOrder();

	t.Erase(6);
	t.InOrder();

	t.Erase(7);
	t.InOrder();

	t.Erase(3);
	t.InOrder();

	for (auto e : arr)
	{
		t.Erase(e);
	}
	t.InOrder();

}