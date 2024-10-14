#include "string.h"
#include <iostream>
using namespace std;

void TestString()
{
    // 1. 构造函数测试
    cout << "=== 构造函数测试 ===" << endl;
    jyf::string s1;
    cout << "默认构造: " << s1.c_str() << " (size: " << s1.size() << ")" << endl;

    jyf::string s2("hello");
    cout << "带参数构造: " << s2.c_str() << " (size: " << s2.size() << ")" << endl;

    jyf::string s3(s2);
    cout << "拷贝构造: " << s3.c_str() << " (size: " << s3.size() << ")" << endl;

    // 2. 赋值运算符测试
    cout << "\n=== 赋值运算符测试 ===" << endl;
    s2 = "world";
    cout << "赋值: " << s2.c_str() << " (size: " << s2.size() << ")" << endl;

    // 3. 运算符[] 测试
    cout << "\n=== 运算符[] 测试 ===" << endl;
    cout << "s2[0]: " << s2[0] << ", s2[4]: " << s2[4] << endl;

    // 4. push_back 测试
    cout << "\n=== push_back 测试 ===" << endl;
    s2.push_back('!');
    cout << "push_back: " << s2.c_str() << " (size: " << s2.size() << ")" << endl;

    // 5. append 测试
    cout << "\n=== append 测试 ===" << endl;
    s2.append(" test");
    cout << "append: " << s2.c_str() << " (size: " << s2.size() << ")" << endl;

    // 6. insert 测试
    cout << "\n=== insert 测试 ===" << endl;
    s2.insert(6, ' ');
    cout << "insert char: " << s2.c_str() << endl;

    s2.insert(12, " case");
    cout << "insert string: " << s2.c_str() << endl;

    // 7. earse 测试
    cout << "\n=== earse 测试 ===" << endl;
    s2.earse(6, 5);
    cout << "earse部分删除: " << s2.c_str() << endl;

    s2.earse(6); // 删除从位置6开始到结尾的所有字符
    cout << "earse到末尾: " << s2.c_str() << endl;

    // 8. find 测试
    cout << "\n=== find 测试 ===" << endl;
    size_t pos = s2.find('!', 0);
    cout << "find '!': " << pos << endl;
    pos = s2.find("ld", 0);
    cout << "find 'ld': " << pos << endl;

    // 9. substr 测试
    cout << "\n=== substr 测试 ===" << endl;
    jyf::string s5 = s2.substr(0, 5);
    cout << "substr(0, 5): " << s5.c_str() << endl;

    // 10. 类外比较运算符测试
    cout << "\n=== 类外比较运算符测试 ===" << endl;
    cout << "s2 == s2: " << (s2 == s2) << endl;
    cout << "s2 != s3: " << (s2 != s3) << endl;
    cout << "s3 < s2: " << (s3 < s2) << endl;
    cout << "s2 > s3: " << (s2 > s3) << endl;

    // 11. 类内 swap 测试
    cout << "\n=== swap 测试 ===" << endl;
    s2.swap(s3);
    cout << "swap后 s2: " << s2.c_str() << ", s3: " << s3.c_str() << endl;

    // 12. clear 测试
    cout << "\n=== clear 测试 ===" << endl;
    s2.clear();
    cout << "clear后 s2: " << s2.c_str() << " (size: " << s2.size() << ")" << endl;

    // 13. 类外 swap 测试
    cout << "\n=== 类外 swap 测试 ===" << endl;
    jyf::swap(s2, s3);
    cout << "类外swap后 s2: " << s2.c_str() << ", s3: " << s3.c_str() << endl;

    // 14. 类外流插入、提取运算符测试
    cout << "\n=== 流插入与提取测试 ===" << endl;
    jyf::string s6("stream test");
    cout << "输出运算符: " << s6 << endl;

    jyf::string s7;
    cout << "输入一段字符串: ";
    cin >> s7;
    cout << "输入的字符串是: " << s7 << endl;

    // 15. getline 测试
    cout << "\n=== getline 测试 ===" << endl;
    jyf::string s8;
    cout << "输入一行文字 (以逗号结束): ";
    jyf::getline(cin, s8, ',');
    cout << "输入的内容是: " << s8 << endl;
}

int main()
{
    TestString();
    return 0;
}


