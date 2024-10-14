#include "string.h"
#include <iostream>
using namespace std;

void TestString()
{
    // 1. ���캯������
    cout << "=== ���캯������ ===" << endl;
    jyf::string s1;
    cout << "Ĭ�Ϲ���: " << s1.c_str() << " (size: " << s1.size() << ")" << endl;

    jyf::string s2("hello");
    cout << "����������: " << s2.c_str() << " (size: " << s2.size() << ")" << endl;

    jyf::string s3(s2);
    cout << "��������: " << s3.c_str() << " (size: " << s3.size() << ")" << endl;

    // 2. ��ֵ���������
    cout << "\n=== ��ֵ��������� ===" << endl;
    s2 = "world";
    cout << "��ֵ: " << s2.c_str() << " (size: " << s2.size() << ")" << endl;

    // 3. �����[] ����
    cout << "\n=== �����[] ���� ===" << endl;
    cout << "s2[0]: " << s2[0] << ", s2[4]: " << s2[4] << endl;

    // 4. push_back ����
    cout << "\n=== push_back ���� ===" << endl;
    s2.push_back('!');
    cout << "push_back: " << s2.c_str() << " (size: " << s2.size() << ")" << endl;

    // 5. append ����
    cout << "\n=== append ���� ===" << endl;
    s2.append(" test");
    cout << "append: " << s2.c_str() << " (size: " << s2.size() << ")" << endl;

    // 6. insert ����
    cout << "\n=== insert ���� ===" << endl;
    s2.insert(6, ' ');
    cout << "insert char: " << s2.c_str() << endl;

    s2.insert(12, " case");
    cout << "insert string: " << s2.c_str() << endl;

    // 7. earse ����
    cout << "\n=== earse ���� ===" << endl;
    s2.earse(6, 5);
    cout << "earse����ɾ��: " << s2.c_str() << endl;

    s2.earse(6); // ɾ����λ��6��ʼ����β�������ַ�
    cout << "earse��ĩβ: " << s2.c_str() << endl;

    // 8. find ����
    cout << "\n=== find ���� ===" << endl;
    size_t pos = s2.find('!', 0);
    cout << "find '!': " << pos << endl;
    pos = s2.find("ld", 0);
    cout << "find 'ld': " << pos << endl;

    // 9. substr ����
    cout << "\n=== substr ���� ===" << endl;
    jyf::string s5 = s2.substr(0, 5);
    cout << "substr(0, 5): " << s5.c_str() << endl;

    // 10. ����Ƚ����������
    cout << "\n=== ����Ƚ���������� ===" << endl;
    cout << "s2 == s2: " << (s2 == s2) << endl;
    cout << "s2 != s3: " << (s2 != s3) << endl;
    cout << "s3 < s2: " << (s3 < s2) << endl;
    cout << "s2 > s3: " << (s2 > s3) << endl;

    // 11. ���� swap ����
    cout << "\n=== swap ���� ===" << endl;
    s2.swap(s3);
    cout << "swap�� s2: " << s2.c_str() << ", s3: " << s3.c_str() << endl;

    // 12. clear ����
    cout << "\n=== clear ���� ===" << endl;
    s2.clear();
    cout << "clear�� s2: " << s2.c_str() << " (size: " << s2.size() << ")" << endl;

    // 13. ���� swap ����
    cout << "\n=== ���� swap ���� ===" << endl;
    jyf::swap(s2, s3);
    cout << "����swap�� s2: " << s2.c_str() << ", s3: " << s3.c_str() << endl;

    // 14. ���������롢��ȡ���������
    cout << "\n=== ����������ȡ���� ===" << endl;
    jyf::string s6("stream test");
    cout << "��������: " << s6 << endl;

    jyf::string s7;
    cout << "����һ���ַ���: ";
    cin >> s7;
    cout << "������ַ�����: " << s7 << endl;

    // 15. getline ����
    cout << "\n=== getline ���� ===" << endl;
    jyf::string s8;
    cout << "����һ������ (�Զ��Ž���): ";
    jyf::getline(cin, s8, ',');
    cout << "�����������: " << s8 << endl;
}

int main()
{
    TestString();
    return 0;
}


