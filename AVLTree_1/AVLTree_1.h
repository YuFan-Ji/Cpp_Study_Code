#pragma once

#include<iostream>
using namespace std;
#include<assert.h>

template<class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;   // 数据的存储
	AVLTreeNode<K, V>* _left;    // 左孩子
	AVLTreeNode<K, V>* _right;    // 右孩子
	AVLTreeNode<K, V>* _parent;    // 父结点
	int _bf;         // 平衡因子

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
		// 树为空，直接插入然后返回
		if (_root = nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			// 小于往左走
			if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first)   // 大于往右走
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
		// 链接
		if (cur->_kv.first < parent->_kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		// 通过平衡因子控制平衡

		while (parent)      // 如果parent为空，就停止
		{
			if (cur == parent->_left)
			{
				parent->_bf--;     // 如果新加入的结点在左侧，父亲平衡因子减1
			}
			else
			{
				parent->_bf++;    // 如果新加入的结点在右侧，父亲平衡因子加1
			}

			if (parent->_bf == 0)
			{
				break;      // 父亲平衡因子为0，更新结束
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 继续向上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 子树不平衡了，需要进行旋转调整
				
				// 左单旋
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

	// 左单旋
	void Rotatel(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		// 重新链接
		parent->_right = curleft;
		if (curleft) // 如果curleft存在
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

		// 更改平衡因子
		parent->_bf = cur->_bf = 0;
	}
	
private:
	Node* _root = nullptr;
};