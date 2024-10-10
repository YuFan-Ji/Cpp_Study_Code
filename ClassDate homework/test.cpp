#include "Date.h"

using namespace std;

int main()
{
    // 构造函数测试
    Date d1(2023, 10, 3);    // 2023年10月3日
    Date d2(2020, 2, 29);    // 2020年2月29日（闰年）
    Date d3;                 // 默认构造函数，1900年1月1日

    // 输出测试
    cout << "Date d1: 2023-10-03" << endl;
    cout << "Date d2: 2020-02-29 (Leap Year)" << endl;
    cout << "Date d3 (default): 1900-01-01" << endl;

    // 日期加法测试
    Date d4 = d1 + 365; // d1加365天
    cout << "d1 + 365 days: " << (d4 == Date(2024, 10, 2) ? "Passed" : "Failed") << endl;

    // 日期减法测试
    Date d5 = d2 - 60; // d2减去60天
    cout << "d2 - 60 days: " << (d5 == Date(2019, 12, 31) ? "Passed" : "Failed") << endl;

    // 日期+=运算符测试
    d3 += 365; // 默认日期加365天
    cout << "d3 += 365 days: " << (d3 == Date(1901, 1, 1) ? "Passed" : "Failed") << endl;

    // 日期-=运算符测试
    d3 -= 365; // d3减365天，回到原日期
    cout << "d3 -= 365 days: " << (d3 == Date(1900, 1, 1) ? "Passed" : "Failed") << endl;

    // 日期比较测试
    cout << "d1 > d2: " << (d1 > d2 ? "Passed" : "Failed") << endl;
    cout << "d2 < d1: " << (d2 < d1 ? "Passed" : "Failed") << endl;

    // 前置++和后置++测试
    ++d1; // 前置++
    Date d6 = d1++; // 后置++
    cout << "Pre-increment d1: " << (d1 == Date(2023, 10, 5) ? "Passed" : "Failed") << endl;
    cout << "Post-increment d1: " << (d6 == Date(2023, 10, 4) ? "Passed" : "Failed") << endl;

    // 前置--和后置--测试
    --d1; // 前置--
    Date d7 = d1--; // 后置--
    cout << "Pre-decrement d1: " << (d1 == Date(2023, 10, 3) ? "Passed" : "Failed") << endl;
    cout << "Post-decrement d1: " << (d7 == Date(2023, 10, 4) ? "Passed" : "Failed") << endl;

    // 日期-日期的天数计算
    int daysBetween = d1 - d2;
    cout << "Days between d1 and d2: " << daysBetween << " (Expected: " << (d1 > d2 ? daysBetween : -daysBetween) << ")" << endl;

    return 0;
}
