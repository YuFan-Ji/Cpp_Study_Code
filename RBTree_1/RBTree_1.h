#pragma once
#include<iostream>

using namespace std;

enum Colour
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		: _kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};

template<class K, class V> 
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		// ��Ϊ�գ�ֱ�Ӳ���Ȼ�󷵻�
		if (_root == nullptr)
		{
			_root = new Node(kv);
			// ���ڵ�����Ǻ�ɫ
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			// С��������
			if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first)   // ����������
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		// ��������ʼ��ɫΪ��ɫ
		cur->_col = RED;

		// ����
		if (cur->_kv.first < parent->_kv.first)
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
			cout << root->_kv.first << "����������ɫ�ڵ�" << endl;
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