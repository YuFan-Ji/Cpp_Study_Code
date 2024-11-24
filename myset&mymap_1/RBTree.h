#pragma once

#include<iostream>

using namespace std;



enum Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	Colour _col;
	T _data;

	RBTreeNode(const T& data)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
		, _data(data)
	{}
};

template<class T>
struct __TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T> Self;
	Node* _node;

	__TreeIterator(Node* node)
		:_node(node)
	{}

	T& operator* ()
	{
		return _node->_data;
	}

	T* operator-> ()
	{
		return &(_node->_data);
	}

	bool operator!= (const Self& s)
	{
		return _node != s._node;
	}

	Self& operator++ ()
	{
		if (_node->_right != nullptr)
		{
			Node* curleft = _node->_right;
			while (curleft->_left)
			{
				curleft = curleft->_left;
			}
			_node = curleft;
		}
		else
		{
			// �Һ����Ǹ�������Ǹ����Ƚڵ㣬������һ��Ҫ���ʵĽڵ�
			Node* cur = _node;
			Node* parent = _node->_parent;

			while (parent)
			{
				if (parent->_left == cur)
				{
					break;
				}
				else
				{
					cur = parent;
					parent = parent->_parent;
				}
			}

			_node = parent;
		}

		return *this;
	}

	Self& operator--()
	{

	}

};

template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __TreeIterator<T> iterator;

	iterator begin()
	{
		Node* leftMin = _root;
		while (leftMin && leftMin->_left)
		{
			leftMin = leftMin->_left;
		}
		return iterator(leftMin);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		KeyOfT kot;
		while (cur)
		{
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}


	bool Insert(const T& data)
	{
		// ��Ϊ�գ�ֱ�Ӳ���Ȼ�󷵻�
		if (_root == nullptr)
		{
			_root = new Node(data);
			// ���ڵ�����Ǻ�ɫ
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		KeyOfT kot;

		while (cur)
		{
			// С��������
			if (kot(data) < kot(cur->_data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kot(data) > kot(cur->_data))   // ����������
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(data);
		// ��������ʼ��ɫΪ��ɫ
		cur->_col = RED;

		// ����
		if (kot(cur->_data) < kot(parent->_data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		// �������parent�Ǻ�ɫ�����ô����ͽ�����

		// ���һ��curΪ�죬parentΪ�죬grandfatherΪ�ڣ�uncle��ȷ��
		// ��whileѭ������Ϊ����Ҫ���ϵ����ϵ���
		while (parent && parent->_col == RED)
		{
			// ��������Ҫ�ҵ�grandfather
			Node* grandfather = parent->_parent;

			// ������ͨ��grandfather�ҵ�uncle

			//���parent��grandfather->_left
			if (parent == grandfather->_left)
			{
				// ˵��uncle���ұ�
				Node* uncle = grandfather->_right;

				// uncle������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					// ���������������ʼ������ɫ
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϵ���
					cur = grandfather;
					parent = cur->_parent;

					// �����ߵ�������һ�����⣬�����ǰparent���Ǹ���
					// ����parent�Ǻ�ɫ������Ҫ������Ϊ��ɫ��
					// ����ʽ�ǣ���ѭ���󣬱�����_root->_col��Ϊ��ɫ
				}
				else    // uncle������ �� uncle������Ϊ��ɫ
				{
					// �ж�Ҫ������ת

					// �ҵ���
					if (cur == parent->_left)
					{
						//     g
						//   p
						// c
						RotateR(grandfather);
						// ������ɫ
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else // ����˫��
					{
						//     g
						//   p
						//		c
						RotateL(parent);
						RotateR(grandfather);
						// ������ɫ
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					// ��ת��ɫ��ͽ����ˣ����ﲻ�����Ҳ���ԣ������жϾͻ��˳�
					break;
				}
			}
			else //(parent == grandfather->_right)  // ���parent��grandfather->_right
			{
				// ˵��uncle�����
				Node* uncle = grandfather->_left;

				// uncle������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					// ���������������ʼ������ɫ
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϵ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else    // uncle������ �� uncle������Ϊ��ɫ
				{
					// �ж�Ҫ������ת

					// ����
					if (cur == parent->_right)
					{
						// g
						//	  p
						//       c
						RotateL(grandfather);
						// ������ɫ
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else // ����˫��
					{
						// g
						//	  p
						// c
						RotateR(parent);
						RotateL(grandfather);
						// ������ɫ
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}

		// ���ﱣ֤��Ϊ��ɫ
		_root->_col = BLACK;

		return true;
	}

	// ����
	void RotateL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		// ��������
		parent->_right = curleft;
		if (curleft) // ���curleft����
		{
			curleft->_parent = parent;
		}

		cur->_left = parent;

		Node* ppnode = parent->_parent;
		parent->_parent = cur;

		if (ppnode == nullptr)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}

			cur->_parent = ppnode;
		}
	}

	// �ҵ���
	void RotateR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;

		parent->_left = curright;

		if (curright)
		{
			curright->_parent = parent;
		}

		cur->_right = parent;

		Node* ppnode = parent->_parent;
		parent->_parent = cur;
		if (ppnode == nullptr)
		{
			cur->_parent = nullptr;
			_root = cur;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}
			cur->_parent = ppnode;
		}
	}

	// ����Ƿ񹹽���ȷ
	bool CheckColour(Node* root, int blacknum, int benchmark)
	{
		if (root == nullptr)
		{
			if (blacknum != benchmark)
				return false;

			return true;
		}

		if (root->_col == BLACK)
		{
			++blacknum;
		}

		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << kot(root->data) << "����������ɫ�ڵ�" << endl;
			return false;
		}

		return CheckColour(root->_left, blacknum, benchmark)
			&& CheckColour(root->_right, blacknum, benchmark);
	}

	bool IsBalance()
	{
		return IsBalance(_root);
	}

	bool IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		if (root->_col != BLACK)
		{
			return false;
		}

		// ��׼ֵ
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;

			cur = cur->_left;
		}

		return CheckColour(root, 0, benchmark);
	}

private:
	Node* _root = nullptr;
};