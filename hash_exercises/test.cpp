//练习题 1：统计每个字符串的出现次数
//要求：
//给定一个字符串数组，统计每个字符串出现的次数，并输出结果。
//
//输入示例：
//{ "apple", "banana", "apple", "cherry", "date", "banana", "date", "fig" }
//
//输出示例：
//
//makefile
//复制代码
//apple : 2
//banana : 2
//cherry : 1
//date : 2
//fig : 1
//代码实现：


//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <string>
//using namespace std;
//
//void countStringOccurrences(const vector<string>& strings) {
//    unordered_map<string, int> frequencyMap;
//
//    // 统计字符串出现次数
//    for (const string& str : strings) {
//        frequencyMap[str]++;
//    }
//
//    // 输出统计结果
//    cout << "字符串出现次数：" << endl;
//    for (const auto& pair : frequencyMap) {
//        cout << pair.first << ": " << pair.second << endl;
//    }
//}
//
//int main() {
//    vector<string> input = { "apple", "banana", "apple", "cherry", "date", "banana", "date", "fig" };
//    countStringOccurrences(input);
//
//    return 0;
//}

//练习题 2：找出第一个不重复的字符串
//要求：
//给定一个字符串数组，找出第一个只出现一次的字符串。
//输入示例：
//{ "apple", "banana", "apple", "cherry", "banana", "date", "cherry" }
//输出示例：
//"date"


//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <string>
//using namespace std;
//
//string findFirstUniqueString(const vector<string>& strings) {
//    unordered_map<string, int> frequencyMap;
//
//    // 统计字符串出现次数
//    for (const string& str : strings) {
//        frequencyMap[str]++;
//    }
//
//    // 找出第一个只出现一次的字符串
//    for (const string& str : strings) {
//        if (frequencyMap[str] == 1) {
//            return str;
//        }
//    }
//
//    return "没有不重复的字符串";
//}
//
//int main() {
//    vector<string> input = { "apple", "banana", "apple", "cherry", "banana", "date", "cherry" };
//    cout << "第一个不重复的字符串是：" << findFirstUniqueString(input) << endl;
//
//    return 0;
//}

//练习题 3：合并两个数组并移除重复项
//要求：
//给定两个字符串数组，合并它们并移除重复的字符串。
//输入示例：
//数组1：{ "apple", "banana", "cherry" }
//数组2：{ "banana", "date", "fig" }
//输出示例：
//{ "apple", "banana", "cherry", "date", "fig" }


//#include <iostream>
//#include <unordered_set>
//#include <vector>
//#include <string>
//using namespace std;
//
//vector<string> mergeAndRemoveDuplicates(const vector<string>& arr1, const vector<string>& arr2) {
//    unordered_set<string> uniqueSet;
//    vector<string> result;
//
//    // 将第一个数组中的字符串插入集合
//    for (const string& str : arr1) {
//        uniqueSet.insert(str);
//    }
//
//    // 将第二个数组中的字符串插入集合
//    for (const string& str : arr2) {
//        uniqueSet.insert(str);
//    }
//
//    // 将集合中的字符串加入结果
//    for (const string& str : uniqueSet) {
//        result.push_back(str);
//    }
//
//    return result;
//}
//
//int main() {
//    vector<string> arr1 = { "apple", "banana", "cherry" };
//    vector<string> arr2 = { "banana", "date", "fig" };
//
//    vector<string> result = mergeAndRemoveDuplicates(arr1, arr2);
//
//    cout << "合并后的字符串数组：" << endl;
//    for (const string& str : result) {
//        cout << str << endl;
//    }
//
//    return 0;
//}


//练习题 4：检查两个字符串数组是否有相同的字符串
//要求：
//给定两个字符串数组，检查它们是否有公共字符串，输出 true 或 false。
//输入示例：
//数组1：{ "apple", "banana", "cherry" }
//数组2：{ "date", "fig", "banana" }
//输出示例：
//true
//
//代码实现：


#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

bool hasCommonString(const vector<string>& arr1, const vector<string>& arr2) {
    unordered_set<string> stringSet;

    // 将第一个数组中的字符串加入集合
    for (const string& str : arr1) {
        stringSet.insert(str);
    }

    // 检查第二个数组中的字符串是否存在于集合中
    for (const string& str : arr2) {
        if (stringSet.find(str) != stringSet.end()) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<string> arr1 = { "apple", "banana", "cherry" };
    vector<string> arr2 = { "date", "fig", "banana" };

    cout << "是否有公共字符串：" << (hasCommonString(arr1, arr2) ? "true" : "false") << endl;

    return 0;
}