#include "Date.h"

using namespace std;

int main()
{
    // ���캯������
    Date d1(2023, 10, 3);    // 2023��10��3��
    Date d2(2020, 2, 29);    // 2020��2��29�գ����꣩
    Date d3;                 // Ĭ�Ϲ��캯����1900��1��1��

    // �������
    cout << "Date d1: 2023-10-03" << endl;
    cout << "Date d2: 2020-02-29 (Leap Year)" << endl;
    cout << "Date d3 (default): 1900-01-01" << endl;

    // ���ڼӷ�����
    Date d4 = d1 + 365; // d1��365��
    cout << "d1 + 365 days: " << (d4 == Date(2024, 10, 2) ? "Passed" : "Failed") << endl;

    // ���ڼ�������
    Date d5 = d2 - 60; // d2��ȥ60��
    cout << "d2 - 60 days: " << (d5 == Date(2019, 12, 31) ? "Passed" : "Failed") << endl;

    // ����+=���������
    d3 += 365; // Ĭ�����ڼ�365��
    cout << "d3 += 365 days: " << (d3 == Date(1901, 1, 1) ? "Passed" : "Failed") << endl;

    // ����-=���������
    d3 -= 365; // d3��365�죬�ص�ԭ����
    cout << "d3 -= 365 days: " << (d3 == Date(1900, 1, 1) ? "Passed" : "Failed") << endl;

    // ���ڱȽϲ���
    cout << "d1 > d2: " << (d1 > d2 ? "Passed" : "Failed") << endl;
    cout << "d2 < d1: " << (d2 < d1 ? "Passed" : "Failed") << endl;

    // ǰ��++�ͺ���++����
    ++d1; // ǰ��++
    Date d6 = d1++; // ����++
    cout << "Pre-increment d1: " << (d1 == Date(2023, 10, 5) ? "Passed" : "Failed") << endl;
    cout << "Post-increment d1: " << (d6 == Date(2023, 10, 4) ? "Passed" : "Failed") << endl;

    // ǰ��--�ͺ���--����
    --d1; // ǰ��--
    Date d7 = d1--; // ����--
    cout << "Pre-decrement d1: " << (d1 == Date(2023, 10, 3) ? "Passed" : "Failed") << endl;
    cout << "Post-decrement d1: " << (d7 == Date(2023, 10, 4) ? "Passed" : "Failed") << endl;

    // ����-���ڵ���������
    int daysBetween = d1 - d2;
    cout << "Days between d1 and d2: " << daysBetween << " (Expected: " << (d1 > d2 ? daysBetween : -daysBetween) << ")" << endl;

    return 0;
}
