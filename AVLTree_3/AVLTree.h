#pragma once

#include<iostream>
using namespace std;
#include<assert.h>

template<class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;   // ���ݵĴ洢
	AVLTreeNode<K, V>* _left;    // ����
	AVLTreeNode<K, V>* _right;    // �Һ���
	AVLTreeNode<K, V>* _parent;    // �����
	int _bf;         // ƽ������

	AVLTreeNode(const pair<K, V>& kv)
		: _kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		// ��Ϊ�գ�ֱ�Ӳ���Ȼ�󷵻�
		if (_root == nullptr)
		{
			_root = new Node(kv);
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

		// ͨ��ƽ�����ӿ���ƽ��

		while (parent)      // ���parentΪ�գ���ֹͣ
		{
			if (cur == parent->_left)
			{
				parent->_bf--;     // ����¼���Ľ������࣬����ƽ�����Ӽ�1
			}
			else
			{
				parent->_bf++;    // ����¼���Ľ�����Ҳ࣬����ƽ�����Ӽ�1
			}

			if (parent->_bf == 0)
			{
				break;      // ����ƽ������Ϊ0�����½���
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// �������ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ������ƽ���ˣ���Ҫ������ת����

				// ����
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				// �ҵ���
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				// ����˫��
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				// ����˫��
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				break;
			}
		}

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

		// ����ƽ������
		parent->_bf = cur->_bf = 0;
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

		// �ı�ƽ������
		parent->_bf = cur->_bf = 0;
	}

	// ����˫��
	void RotateRL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		int bf = curleft->_bf;

		// ����
		RotateR(cur);
		// ����
		RotateL(parent);

		// ����ƽ������
		if (bf == 0)
		{
			parent->_bf = 0;
			cur->_bf = 0;
			curleft->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			cur->_bf = 0;
			curleft->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			cur->_bf = 1;
			curleft->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	// ����˫��
	void RotateLR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		int bf = curright->_bf;

		RotateL(cur);
		RotateR(parent);

		// ����ƽ������
		if (bf == 0)
		{
			parent->_bf = 0;
			cur->_bf = 0;
			curright->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			cur->_bf = -1;
			curright->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			cur->_bf = 0;
			curright->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	int Height()
	{
		return Height(_root);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool IsBalance()
	{
		return IsBalance(_root);
	}

	// �ж��Ƿ�ƽ��
	bool IsBalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		if (rightHeight - leftHeight != root->_bf)
		{
			cout << "ƽ�������쳣��" << root->_kv.first << "->" << root->_bf << endl;
		}

		return abs(rightHeight - leftHeight) < 2
			&& IsBalance(root->_left)
			&& IsBalance(root->_right);
	}

private:
	Node* _root = nullptr;
};