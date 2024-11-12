//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//// �γ���Ϣ�Ľṹ��
//struct Course {
//    string courseName;
//    int courseId;
//};
//
//// ��������ıȽϺ���
//bool compareByCourseName(const Course& a, const Course& b) {
//    return a.courseName < b.courseName;
//}
//
//// �۰�����㷨
//int binarySearch(const vector<Course>& orderedList, const string& key) {
//    int left = 0, right = orderedList.size() - 1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (orderedList[mid].courseName == key)
//            return mid;  // �ҵ���������
//        else if (orderedList[mid].courseName < key)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    return -1;  // δ�ҵ�����-1
//}
//
//// ��������
//int main() {
//    // ��ʼ���γ���Ϣ���Ա�
//    vector<Course> courseList = {
//        {"Data Structures", 101},
//        {"Algorithms", 102},
//        {"Computer Networks", 103},
//        {"Operating Systems", 104},
//        {"Databases", 105}
//    };
//
//    // �����Ա��γ��������򣬹��������
//    sort(courseList.begin(), courseList.end(), compareByCourseName);
//
//    // ��ʾ�����Ŀγ���Ϣ
//    cout << "Sorted Course List:" << endl;
//    for (const auto& course : courseList) {
//        cout << course.courseName << " (ID: " << course.courseId << ")" << endl;
//    }
//
//    // �����۰���Ҳ���
//    string searchKey = "Algorithms";
//    int result = binarySearch(courseList, searchKey);
//    if (result != -1) {
//        cout << "Course '" << searchKey << "' found at index " << result
//            << " with Course ID: " << courseList[result].courseId << endl;
//    }
//    else {
//        cout << "Course '" << searchKey << "' not found." << endl;
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// �γ���Ϣ�Ľṹ��
//struct Course {
//    string courseName;
//    int courseId;
//};
//
//// �����������Ľڵ�ṹ
//struct TreeNode {
//    Course course;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(const Course& c) : course(c), left(nullptr), right(nullptr) {}
//};
//
//// ���뺯�������γ̲��뵽������������
//TreeNode* insert(TreeNode* root, const Course& course) {
//    if (root == nullptr) {
//        return new TreeNode(course);  // ����Ϊ�գ������½ڵ�
//    }
//    if (course.courseName < root->course.courseName) {
//        root->left = insert(root->left, course);
//    }
//    else if (course.courseName > root->course.courseName) {
//        root->right = insert(root->right, course);
//    }
//    return root;  // �������ͬ�������루����γ�����Ψһ��
//}
//
//// ���Һ������ڶ����������в��ҿγ�
//TreeNode* search(TreeNode* root, const string& key) {
//    if (root == nullptr || root->course.courseName == key) {
//        return root;  // �ҵ����ؽڵ�ָ�룬û�ҵ����ؿ�ָ��
//    }
//    if (key < root->course.courseName) {
//        return search(root->left, key);
//    }
//    else {
//        return search(root->right, key);
//    }
//}
//
//// ��������
//int main() {
//    // ��ʼ���γ���Ϣ���Ա�
//    Course courseList[] = {
//        {"Data Structures", 101},
//        {"Algorithms", 102},
//        {"Computer Networks", 103},
//        {"Operating Systems", 104},
//        {"Databases", 105}
//    };
//
//    // ��������������
//    TreeNode* root = nullptr;
//    for (const auto& course : courseList) {
//        root = insert(root, course);
//    }
//
//    // ���Բ��ҹ���
//    string searchKey = "Algorithms";
//    TreeNode* result = search(root, searchKey);
//    if (result != nullptr) {
//        cout << "Course '" << searchKey << "' found with Course ID: "
//            << result->course.courseId << endl;
//    }
//    else {
//        cout << "Course '" << searchKey << "' not found." << endl;
//    }
//
//    // ���Ҳ����ڵĿγ�
//    searchKey = "Machine Learning";
//    result = search(root, searchKey);
//    if (result != nullptr) {
//        cout << "Course '" << searchKey << "' found with Course ID: "
//            << result->course.courseId << endl;
//    }
//    else {
//        cout << "Course '" << searchKey << "' not found." << endl;
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//const int TABLE_SIZE = 10; // ��ϣ���С
//
//// �γ���Ϣ�Ľṹ��
//struct Course {
//    string courseName;
//    int courseId;
//    bool isOccupied = false;  // �Ƿ��пγ���Ϣ
//};
//
//// ��ϣ����
//int hashFunction(const string& courseName) {
//    int hash = 0;
//    for (char ch : courseName) {
//        hash = (hash * 31 + ch) % TABLE_SIZE;
//    }
//    return hash;
//}
//
//// ���뺯�������ŵ�ַ�������ͻ
//void insertCourse(vector<Course>& hashTable, const Course& course) {
//    int index = hashFunction(course.courseName);
//    int originalIndex = index;
//
//    while (hashTable[index].isOccupied) {
//        index = (index + 1) % TABLE_SIZE;  // ���ŵ�ַ��������̽��
//        if (index == originalIndex) {
//            cout << "��ϣ���������޷�����γ̣�" << course.courseName << endl;
//            return;
//        }
//    }
//
//    hashTable[index] = course;
//    hashTable[index].isOccupied = true;
//}
//
//// ���Һ���
//int searchCourse(const vector<Course>& hashTable, const string& courseName) {
//    int index = hashFunction(courseName);
//    int originalIndex = index;
//
//    while (hashTable[index].isOccupied) {
//        if (hashTable[index].courseName == courseName) {
//            return index;  // �ҵ���������
//        }
//        index = (index + 1) % TABLE_SIZE;
//        if (index == originalIndex) break;  // ����һȦδ�ҵ�
//    }
//    return -1;  // δ�ҵ�
//}
//
//// ��������
//int main() {
//    vector<Course> hashTable(TABLE_SIZE);
//
//    // ��ʼ���γ���Ϣ
//    Course courseList[] = {
//        {"���ݽṹ", 101},
//        {"�㷨", 102},
//        {"���������", 103},
//        {"����ϵͳ", 104},
//        {"���ݿ�", 105}
//    };
//
//    // ����γ���Ϣ����ϣ��
//    for (const auto& course : courseList) {
//        insertCourse(hashTable, course);
//    }
//
//    // ���ҿγ�
//    string searchKey = "�㷨";
//    int result = searchCourse(hashTable, searchKey);
//    if (result != -1) {
//        cout << "�γ� '" << searchKey << "' �ҵ����γ�ID��" << hashTable[result].courseId << endl;
//    }
//    else {
//        cout << "�γ� '" << searchKey << "' δ�ҵ���" << endl;
//    }
//
//    // ���Ҳ����ڵĿγ�
//    searchKey = "����ѧϰ";
//    result = searchCourse(hashTable, searchKey);
//    if (result != -1) {
//        cout << "�γ� '" << searchKey << "' �ҵ����γ�ID��" << hashTable[result].courseId << endl;
//    }
//    else {
//        cout << "�γ� '" << searchKey << "' δ�ҵ���" << endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//const int TABLE_SIZE = 10; // ��ϣ���С
//
//// �γ���Ϣ�Ľṹ��
//struct Course {
//    string courseName;
//    int courseId;
//    bool isOccupied;  // �Ƿ�ռ�ø�λ��
//    bool isDeleted;   // �Ƿ��ѱ�ɾ��
//
//    // �ṩ���캯������ʼ���γ����ƺͿγ� ID
//    Course(string name = "", int id = 0)
//        : courseName(name), courseId(id), isOccupied(false), isDeleted(false) {}
//};
//
//// ��ϣ���������ݿγ���������ɢ��ֵ
//int hashFunction(const string& courseName) {
//    int hash = 0;
//    for (char ch : courseName) {
//        hash = (hash * 31 + ch) % TABLE_SIZE;  // ʹ��31��Ϊ������������ײ
//    }
//    return hash;
//}
//
//// ���뺯����ʹ�ÿ��ŵ�ַ��������̽�⣩�����ͻ
//void insertCourse(vector<Course>& hashTable, const Course& course) {
//    int index = hashFunction(course.courseName);
//    int originalIndex = index;
//
//    // ����̽�⣬�ҵ���λ����ɾ����λ��
//    while (hashTable[index].isOccupied && !hashTable[index].isDeleted) {
//        index = (index + 1) % TABLE_SIZE;  // ����̽��
//        if (index == originalIndex) {
//            cout << "��ϣ���������޷�����γ̣�" << course.courseName << endl;
//            return;
//        }
//    }
//
//    // ����γ���Ϣ
//    hashTable[index] = course;
//    hashTable[index].isOccupied = true;
//    hashTable[index].isDeleted = false;
//}
//
//// ���Һ������ڹ�ϣ���в��ҿγ�
//int searchCourse(const vector<Course>& hashTable, const string& courseName) {
//    int index = hashFunction(courseName);
//    int originalIndex = index;
//
//    // ����̽�⣬�ҵ�ƥ��Ŀγ̻��λ
//    while (hashTable[index].isOccupied) {
//        if (!hashTable[index].isDeleted && hashTable[index].courseName == courseName) {
//            return index;  // �ҵ���������
//        }
//        index = (index + 1) % TABLE_SIZE;
//        if (index == originalIndex) break;  // ����һȦδ�ҵ�
//    }
//    return -1;  // δ�ҵ�
//}
//
//// ��������
//int main() {
//    vector<Course> hashTable(TABLE_SIZE);
//
//    // ��ʼ���γ���Ϣ
//    vector<Course> courseList = {
//        Course("���ݽṹ", 101),
//        Course("�㷨", 102),
//        Course("���������", 103),
//        Course("����ϵͳ", 104),
//        Course("���ݿ�", 105)
//    };
//
//    // ����γ���Ϣ����ϣ��
//    for (const auto& course : courseList) {
//        insertCourse(hashTable, course);
//    }
//
//    // ���ҿγ�
//    string searchKey = "�㷨";
//    int result = searchCourse(hashTable, searchKey);
//    if (result != -1) {
//        cout << "�γ� '" << searchKey << "' �ҵ����γ�ID��" << hashTable[result].courseId << endl;
//    }
//    else {
//        cout << "�γ� '" << searchKey << "' δ�ҵ���" << endl;
//    }
//
//    // ���Ҳ����ڵĿγ�
//    searchKey = "����ѧϰ";
//    result = searchCourse(hashTable, searchKey);
//    if (result != -1) {
//        cout << "�γ� '" << searchKey << "' �ҵ����γ�ID��" << hashTable[result].courseId << endl;
//    }
//    else {
//        cout << "�γ� '" << searchKey << "' δ�ҵ���" << endl;
//    }
//
//    return 0;
//}


#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

const int TABLE_SIZE = 10; // ��ϣ���С

// �γ���Ϣ�Ľṹ��
struct Course {
    string courseName;
    int courseId;

    Course(string name = "", int id = 0) : courseName(name), courseId(id) {}
};

// ��ϣ���������ݿγ���������ɢ��ֵ
int hashFunction(const string& courseName) {
    int hash = 0;
    for (char ch : courseName) {
        hash = (hash * 31 + ch) % TABLE_SIZE;  // ʹ��31��Ϊ������������ײ
    }
    return hash;
}

// ��ϣ���࣬ʹ������ַ�������ͻ
class HashTable {
private:
    vector<list<Course>> table;  // ÿ��Ͱ��һ������
public:
    HashTable(int size) : table(size) {}

    // ����γ̵���ϣ��
    void insert(const Course& course) {
        int index = hashFunction(course.courseName);
        table[index].push_back(course);
    }

    // ���ҿγ̣����ؿγ�ID�����δ�ҵ�����-1
    int search(const string& courseName) {
        int index = hashFunction(courseName);
        for (const auto& course : table[index]) {
            if (course.courseName == courseName) {
                return course.courseId;
            }
        }
        return -1;  // ���û���ҵ��γ�
    }

    // ��ӡ��ϣ��
    void printTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "λ�� " << i << ": ";
            if (table[i].empty()) {
                cout << "��";
            }
            else {
                for (const auto& course : table[i]) {
                    cout << course.courseName << "(" << course.courseId << ") ";
                }
            }
            cout << endl;
        }
    }
};

// ��������
int main() {
    HashTable hashTable(TABLE_SIZE);

    // ��ʼ���γ���Ϣ
    vector<Course> courseList = {
        Course("���ݽṹ", 101),
        Course("�㷨", 102),
        Course("���������", 103),
        Course("����ϵͳ", 104),
        Course("���ݿ�", 105)
    };

    // ����γ���Ϣ����ϣ��
    for (const auto& course : courseList) {
        hashTable.insert(course);
    }

    // ��ӡ��ϣ��
    cout << "��ϣ�����ݣ�" << endl;
    hashTable.printTable();

    // ���ҿγ�
    string searchKey = "�㷨";
    int result = hashTable.search(searchKey);
    if (result != -1) {
        cout << "�γ� '" << searchKey << "' �ҵ����γ�ID��" << result << endl;
    }
    else {
        cout << "�γ� '" << searchKey << "' δ�ҵ���" << endl;
    }

    // ���Ҳ����ڵĿγ�
    searchKey = "����ѧϰ";
    result = hashTable.search(searchKey);
    if (result != -1) {
        cout << "�γ� '" << searchKey << "' �ҵ����γ�ID��" << result << endl;
    }
    else {
        cout << "�γ� '" << searchKey << "' δ�ҵ���" << endl;
    }

    return 0;
}
