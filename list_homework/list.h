#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

namespace bite
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T()) : _val(val), _pPre(nullptr), _pNext(nullptr) {}
        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };

    //List的迭代器类
    template<class T, class Ref, class Ptr>
    class ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
    public:
        ListIterator(PNode pNode = nullptr) : _pNode(pNode) {}
        ListIterator(const Self& l) : _pNode(l._pNode) {}

        Ref operator*() { return _pNode->_val; }
        Ptr operator->() { return &_pNode->_val; }

        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }
        Self operator++(int)
        {
            Self tmp(*this);
            _pNode = _pNode->_pNext;
            return tmp;
        }
        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }
        Self operator--(int)
        {
            Self tmp(*this);
            _pNode = _pNode->_pPre;
            return tmp;
        }
        bool operator!=(const Self& l) { return _pNode != l._pNode; }
        bool operator==(const Self& l) { return _pNode == l._pNode; }

        PNode _pNode;
    };

    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;

        ///////////////////////////////////////////////////////////////
        // List的构造
        void CreateHead()
        {
            _pHead = new Node;
            _pHead->_pNext = _pHead;
            _pHead->_pPre = _pHead;
            _size = 0;
        }

        list() { CreateHead(); }
        list(int n, const T& value = T())
        {
            CreateHead();
            while (n--) { push_back(value); }
        }
        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            CreateHead();
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }

        list(const list<T>& l)
        {
            CreateHead();
            for (auto it = l.begin(); it != l.end(); it++)
            {
                push_back(*it);
            }
        }

        list<T>& operator=(list<T> l)
        {
            swap(l);
            return *this;
        }

        ~list()
        {
            clear();
            delete _pHead;
            _pHead = nullptr;
        }

        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin() { return _pHead->_pNext; }
        iterator end() { return _pHead; }

        const_iterator begin() const { return _pHead->_pNext; }
        const_iterator end() const { return _pHead; }

        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size() const { return _size; }
        bool empty() const { return _size == 0; }

        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            assert(_size > 0);
            return _pHead->_pNext->_val;
        }

        const T& front() const
        {
            assert(_size > 0);
            return _pHead->_pNext->_val;
        }

        T& back()
        {
            assert(_size > 0);
            return _pHead->_pPre->_val;
        }

        const T& back() const
        {
            assert(_size > 0);
            return _pHead->_pPre->_val;
        }

        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) { insert(end(), val); }
        void pop_back() { erase(--end()); }
        void push_front(const T& val) { insert(begin(), val); }
        void pop_front() { erase(begin()); }

        iterator insert(iterator pos, const T& val)
        {
            Node* newnode = new Node(val);
            Node* pcur = pos._pNode;
            Node* prev = pcur->_pPre;

            newnode->_pPre = prev;
            newnode->_pNext = pcur;
            prev->_pNext = newnode;
            pcur->_pPre = newnode;

            _size++;
            return newnode;
        }

        iterator erase(iterator pos)
        {
            assert(pos != end());
            Node* pcur = pos._pNode;
            Node* prev = pcur->_pPre;
            Node* next = pcur->_pNext;

            prev->_pNext = next;
            next->_pPre = prev;
            delete pcur;
            _size--;

            return next;
        }

        void clear()
        {
            iterator it = begin();
            while (it != end())
            {
                it = erase(it);
            }
            _size = 0;
        }

        void swap(list<T>& l)
        {
            std::swap(_pHead, l._pHead);
            std::swap(_size, l._size);
        }

    private:
        PNode _pHead;
        size_t _size;
    };

    void test_list01() {
        bite::list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);

        bite::list<int>::iterator it = lt.begin();

        while (it != lt.end()) {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        for (auto& e : lt) {
            cout << e << " ";
        }
        cout << endl;
    }

    class A {
    public:
        A(int a = 0, int b = 0) : _a(a), _b(b) {}
        int _a;
        int _b;
    };

    void test_list02() {
        bite::list<A> lt;
        lt.push_back(A(1, 1));
        lt.push_back(A(2, 2));
        lt.push_back(A(3, 3));
        lt.push_back(A(4, 4));

        bite::list<A>::iterator it = lt.begin();
        while (it != lt.end()) {
            cout << (*it)._a << " " << (*it)._b << endl;
            ++it;
        }
        cout << endl;

        it = lt.begin();
        while (it != lt.end()) {
            cout << it->_a << " " << it->_b << endl;
            ++it;
        }
        cout << endl;
    }

    void test_list03() {
        bite::list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_front(5);
        lt.push_front(6);
        lt.push_front(7);
        lt.push_front(8);

        for (auto e : lt) {
            cout << e << " ";
        }
        cout << endl;

        lt.pop_front();
        lt.pop_back();

        for (auto e : lt) {
            cout << e << " ";
        }
        cout << endl;

        lt.clear();
        lt.push_back(10);
        lt.push_back(20);
        lt.push_back(30);
        lt.push_back(40);

        for (auto e : lt) {
            cout << e << " ";
        }
        cout << endl;

        cout << lt.size() << endl;
    }

    void test_list04() {
        bite::list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        for (auto e : lt) {
            cout << e << " ";
        }
        cout << endl;

        bite::list<int> lt1(lt);
        for (auto e : lt1) {
            cout << e << " ";
        }
        cout << endl;

        bite::list<int> lt2;
        lt2.push_back(10);
        lt2.push_back(20);
        lt2.push_back(30);
        lt2.push_back(40);

        for (auto e : lt2) {
            cout << e << " ";
        }
        cout << endl;

        lt1 = lt2;

        for (auto e : lt1) {
            cout << e << " ";
        }
        cout << endl;
    }

}
