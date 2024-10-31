#pragma once

namespace key
{
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

		~BSTree()
		{
			Destroy(_root);
		}

		BSTree(const BSTree<K>& t)
		{
			_root = Copy(t._root);
		}

		BSTree<K>& operator= (BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}

		bool FindR(const K& key)
		{
			return FindR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return EraseR(_root, key);
		}

		void InOrder()
		{
			InOrder(_root);
			cout << endl;
		}



	private:
		Node* _root;

		void Destroy(Node*& root)
		{
			if (root == nullptr)
				return;

			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
			root = nullptr;
		}

		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* copyroot = new Node(root->_key);
			copyroot->_left = Copy(root->_left);
			copyroot->_right = Copy(root->_right);
			return copyroot;
		}

		bool FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (key < root->_key)
			{
				return _FindR(root->_left, key);
			}
			else if (key > root->_key)
			{
				return _FindR(root->_right, key);
			}
			else
			{
				return true;
			}
		}

		bool InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (key < root->_key)
			{
				return InsertR(root->_left, key);
			}
			else if (key > root->_key)
			{
				return InsertR(root->_right, key);
			}
			else
			{
				return false;
			}
		}

		bool EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (key < root->_key)
			{
				return EraseR(root->_left, key);
			}
			else if (key > root->_key)
			{
				return EraseR(root->_right, key);
			}
			else
			{
				Node* del = root;
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					Node* left_Max = root->_left;
					while (left_Max->_right)
					{
						left_Max = left_Max->_right;
					}

					swap(root->_key, left_Max->_key);

					EraseR(root->_left, key);

				}

				delete del;
				return true;
			}
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

	public:
		/*void TestBSTree1()
		{
			int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
			BSTree<int> t;
			for (auto e : a)
			{
				t.InsertR(e);
			}

			t.InOrder();

			t.Erase(4);
			t.InOrder();

			t.EraseR(6);
			t.InOrder();

			t.EraseR(7);
			t.InOrder();

			t.EraseR(3);
			t.InOrder();

			for (auto e : a)
			{
				t.EraseR(e);
			}
			t.InOrder();
		}*/

		void TestBSTree2()
		{
			int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
			BSTree<int> t;
			for (auto e : a)
			{
				t.InsertR(e);
			}

			BSTree<int> t1(t);

			t.InOrder();
			t1.InOrder();
		}

	};
}



/*
namespace key
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		BSTreeNode(const K& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		BSTree()
			:_root(nullptr)
		{}

		BSTree(const BSTree<K>& t)
		{
			_root = Copy(t._root);
		}

		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree()
		{
			Destroy(_root);
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
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
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else // 找到了
				{
					// 左为空
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
					}// 右为空
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
					} // 左右都不为空
					else
					{
						// 找替代节点
						Node* parent = cur;
						Node* leftMax = cur->_left;
						while (leftMax->_right)
						{
							parent = leftMax;
							leftMax = leftMax->_right;
						}

						swap(cur->_key, leftMax->_key);

						if (parent->_left == leftMax)
						{
							parent->_left = leftMax->_left;
						}
						else
						{
							parent->_right = leftMax->_left;
						}

						cur = leftMax;
					}

					delete cur;
					return true;
				}
			}

			return false;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:
		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* copyroot = new Node(root->_key);
			copyroot->_left = Copy(root->_left);
			copyroot->_right = Copy(root->_right);
			return copyroot;
		}

		void Destroy(Node*& root)
		{
			if (root == nullptr)
				return;

			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
			root = nullptr;
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				Node* del = root;

				// 1、左为空
				// 2、右为空
				// 3、左右都不为空
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					Node* leftMax = root->_left;
					while (leftMax->_right)
					{
						leftMax = leftMax->_right;
					}

					swap(root->_key, leftMax->_key);

					return _EraseR(root->_left, key);
				}

				delete del;
				return true;
			}
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else
			{
				return false;
			}
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return true;
			}
		}

		void _InOrder(Node* root)
		{
			if (root == NULL)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
	private:
		Node* _root;
	};
*/



namespace key_value
{
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		BSTree()
			:_root(nullptr)
		{}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		Node* FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key, const V& value)
		{
			return _InsertR(_root, key, value);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				Node* del = root;

				// 1、左为空
				// 2、右为空
				// 3、左右都不为空
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					Node* leftMax = root->_left;
					while (leftMax->_right)
					{
						leftMax = leftMax->_right;
					}

					swap(root->_key, leftMax->_key);

					return _EraseR(root->_left, key);
				}

				delete del;
				return true;
			}
		}

		bool _InsertR(Node*& root, const K& key, const V& value)
		{
			if (root == nullptr)
			{
				root = new Node(key, value);
				return true;
			}

			if (root->_key < key)
			{
				return _InsertR(root->_right, key, value);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key, value);
			}
			else
			{
				return false;
			}
		}

		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return nullptr;

			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return root;
			}
		}

		void _InOrder(Node* root)
		{
			if (root == NULL)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_InOrder(root->_right);
		}
	private:
		Node* _root;
	};

	void TestBSTree1()
	{
		//BSTree<string, Date> carTree;

		BSTree<string, string> dict;
		dict.InsertR("insert", "插入");
		dict.InsertR("sort", "排序");
		dict.InsertR("right", "右边");
		dict.InsertR("date", "日期");

		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.FindR(str);
			if (ret)
			{
				cout << ret->_value << endl;
			}
			else
			{
				cout << "无此单词" << endl;
			}
		}
	}

	void TestBSTree2()
	{
		// 统计水果出现的次数
		string arr[] = { "西瓜", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		BSTree<string, int> countTree;
		for (auto& str : arr)
		{
			auto ret = countTree.FindR(str);
			if (ret == nullptr)
			{
				countTree.InsertR(str, 1);
			}
			else
			{
				ret->_value++;
			}
		}

		countTree.InOrder();
	}
}