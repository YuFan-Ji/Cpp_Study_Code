//��ϰ�� 1��ͳ��ÿ���ַ����ĳ��ִ���
//Ҫ��
//����һ���ַ������飬ͳ��ÿ���ַ������ֵĴ���������������
//
//����ʾ����
//{ "apple", "banana", "apple", "cherry", "date", "banana", "date", "fig" }
//
//���ʾ����
//
//makefile
//���ƴ���
//apple : 2
//banana : 2
//cherry : 1
//date : 2
//fig : 1
//����ʵ�֣�


//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <string>
//using namespace std;
//
//void countStringOccurrences(const vector<string>& strings) {
//    unordered_map<string, int> frequencyMap;
//
//    // ͳ���ַ������ִ���
//    for (const string& str : strings) {
//        frequencyMap[str]++;
//    }
//
//    // ���ͳ�ƽ��
//    cout << "�ַ������ִ�����" << endl;
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

//��ϰ�� 2���ҳ���һ�����ظ����ַ���
//Ҫ��
//����һ���ַ������飬�ҳ���һ��ֻ����һ�ε��ַ�����
//����ʾ����
//{ "apple", "banana", "apple", "cherry", "banana", "date", "cherry" }
//���ʾ����
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
//    // ͳ���ַ������ִ���
//    for (const string& str : strings) {
//        frequencyMap[str]++;
//    }
//
//    // �ҳ���һ��ֻ����һ�ε��ַ���
//    for (const string& str : strings) {
//        if (frequencyMap[str] == 1) {
//            return str;
//        }
//    }
//
//    return "û�в��ظ����ַ���";
//}
//
//int main() {
//    vector<string> input = { "apple", "banana", "apple", "cherry", "banana", "date", "cherry" };
//    cout << "��һ�����ظ����ַ����ǣ�" << findFirstUniqueString(input) << endl;
//
//    return 0;
//}

//��ϰ�� 3���ϲ��������鲢�Ƴ��ظ���
//Ҫ��
//���������ַ������飬�ϲ����ǲ��Ƴ��ظ����ַ�����
//����ʾ����
//����1��{ "apple", "banana", "cherry" }
//����2��{ "banana", "date", "fig" }
//���ʾ����
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
//    // ����һ�������е��ַ������뼯��
//    for (const string& str : arr1) {
//        uniqueSet.insert(str);
//    }
//
//    // ���ڶ��������е��ַ������뼯��
//    for (const string& str : arr2) {
//        uniqueSet.insert(str);
//    }
//
//    // �������е��ַ���������
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
//    cout << "�ϲ�����ַ������飺" << endl;
//    for (const string& str : result) {
//        cout << str << endl;
//    }
//
//    return 0;
//}


//��ϰ�� 4����������ַ��������Ƿ�����ͬ���ַ���
//Ҫ��
//���������ַ������飬��������Ƿ��й����ַ�������� true �� false��
//����ʾ����
//����1��{ "apple", "banana", "cherry" }
//����2��{ "date", "fig", "banana" }
//���ʾ����
//true
//
//����ʵ�֣�


#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

bool hasCommonString(const vector<string>& arr1, const vector<string>& arr2) {
    unordered_set<string> stringSet;

    // ����һ�������е��ַ������뼯��
    for (const string& str : arr1) {
        stringSet.insert(str);
    }

    // ���ڶ��������е��ַ����Ƿ�����ڼ�����
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

    cout << "�Ƿ��й����ַ�����" << (hasCommonString(arr1, arr2) ? "true" : "false") << endl;

    return 0;
}