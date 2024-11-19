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
	typedef AVLTreeNode Node;
public:
	bool insert(const pair<K, V>& kv)
	{
		// ��Ϊ�գ�ֱ�Ӳ���Ȼ�󷵻�
		if (_root = nullptr)
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
				if (parent->_bf == 2 || cur->_bf == 1)
				{
					Rotatel(parent);
				}
			}
			else
			{
				assert(false);
			}
		}

		return true;
	}

	// ����
	void Rotatel(Node* parent)
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
			if (ppnode->_left = parent)
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
	
private:
	Node* _root = nullptr;
};