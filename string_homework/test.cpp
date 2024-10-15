//#include<iostream>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//
//    string addStrings(string& num1, string& num2)
//    {
//        string ret;
//        int next = 0;
//
//        int end1 = num1.size() - 1;
//        int end2 = num2.size() - 1;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int n1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int n2 = end2 >= 0 ? num2[end2] - '0' : 0;
//
//            int sum = n1 + n2 + next;
//            ret.push_back(sum % 10 + '0');
//            next = next / 10;
//            end1--;
//            end2--;
//        }
//
//        if (next == 1)
//        {
//            ret.push_back('1');
//        }
//
//        reverse(ret.begin(), ret.end());
//
//        return ret;
//    }
//
//    string multiply(string num1, string num2)
//    {
//        if (num1 == "0" || num2 == "0")
//        {
//            return "0";
//        }
//
//        string ans = "0";
//        int next = 0;
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//
//        for (int i = end1; i >= 0; i--)
//        {
//            string cur;
//            for (int j = end1; j > i; j--)
//                cur.push_back('0');
//
//            int x = num1[i] - '0';
//            for (int j = end2; j >= 0; j--)
//            {
//                int y = num2[j] - '0';
//                int sum = 0;
//                sum = x * y + next;
//
//                cur.push_back(sum % 10 + '0');
//                next = sum / 10;
//            }
//
//            while (next != 0)
//            {
//                cur.push_back(next % 10 + '0');
//                next /= 10;
//            }
//
//            reverse(cur.begin(), cur.end());
//            ans = addStrings(ans, cur);
//
//        }
//        return ans;
//    }
//};
//
//int main()
//{
//    Solution s;
//    string sss = s.multiply("123", "456");
//    return 0;
//}