//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//// 课程信息的结构体
//struct Course {
//    string courseName;
//    int courseId;
//};
//
//// 用于排序的比较函数
//bool compareByCourseName(const Course& a, const Course& b) {
//    return a.courseName < b.courseName;
//}
//
//// 折半查找算法
//int binarySearch(const vector<Course>& orderedList, const string& key) {
//    int left = 0, right = orderedList.size() - 1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (orderedList[mid].courseName == key)
//            return mid;  // 找到返回索引
//        else if (orderedList[mid].courseName < key)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    return -1;  // 未找到返回-1
//}
//
//// 测试用例
//int main() {
//    // 初始化课程信息线性表
//    vector<Course> courseList = {
//        {"Data Structures", 101},
//        {"Algorithms", 102},
//        {"Computer Networks", 103},
//        {"Operating Systems", 104},
//        {"Databases", 105}
//    };
//
//    // 将线性表按课程名称排序，构建有序表
//    sort(courseList.begin(), courseList.end(), compareByCourseName);
//
//    // 显示排序后的课程信息
//    cout << "Sorted Course List:" << endl;
//    for (const auto& course : courseList) {
//        cout << course.courseName << " (ID: " << course.courseId << ")" << endl;
//    }
//
//    // 进行折半查找测试
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
//// 课程信息的结构体
//struct Course {
//    string courseName;
//    int courseId;
//};
//
//// 二叉排序树的节点结构
//struct TreeNode {
//    Course course;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(const Course& c) : course(c), left(nullptr), right(nullptr) {}
//};
//
//// 插入函数：将课程插入到二叉排序树中
//TreeNode* insert(TreeNode* root, const Course& course) {
//    if (root == nullptr) {
//        return new TreeNode(course);  // 若树为空，创建新节点
//    }
//    if (course.courseName < root->course.courseName) {
//        root->left = insert(root->left, course);
//    }
//    else if (course.courseName > root->course.courseName) {
//        root->right = insert(root->right, course);
//    }
//    return root;  // 如果键相同，不插入（假设课程名称唯一）
//}
//
//// 查找函数：在二叉排序树中查找课程
//TreeNode* search(TreeNode* root, const string& key) {
//    if (root == nullptr || root->course.courseName == key) {
//        return root;  // 找到返回节点指针，没找到返回空指针
//    }
//    if (key < root->course.courseName) {
//        return search(root->left, key);
//    }
//    else {
//        return search(root->right, key);
//    }
//}
//
//// 测试用例
//int main() {
//    // 初始化课程信息线性表
//    Course courseList[] = {
//        {"Data Structures", 101},
//        {"Algorithms", 102},
//        {"Computer Networks", 103},
//        {"Operating Systems", 104},
//        {"Databases", 105}
//    };
//
//    // 创建二叉排序树
//    TreeNode* root = nullptr;
//    for (const auto& course : courseList) {
//        root = insert(root, course);
//    }
//
//    // 测试查找功能
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
//    // 查找不存在的课程
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
//const int TABLE_SIZE = 10; // 哈希表大小
//
//// 课程信息的结构体
//struct Course {
//    string courseName;
//    int courseId;
//    bool isOccupied = false;  // 是否有课程信息
//};
//
//// 哈希函数
//int hashFunction(const string& courseName) {
//    int hash = 0;
//    for (char ch : courseName) {
//        hash = (hash * 31 + ch) % TABLE_SIZE;
//    }
//    return hash;
//}
//
//// 插入函数：开放地址法解决冲突
//void insertCourse(vector<Course>& hashTable, const Course& course) {
//    int index = hashFunction(course.courseName);
//    int originalIndex = index;
//
//    while (hashTable[index].isOccupied) {
//        index = (index + 1) % TABLE_SIZE;  // 开放地址法：线性探测
//        if (index == originalIndex) {
//            cout << "哈希表已满，无法插入课程：" << course.courseName << endl;
//            return;
//        }
//    }
//
//    hashTable[index] = course;
//    hashTable[index].isOccupied = true;
//}
//
//// 查找函数
//int searchCourse(const vector<Course>& hashTable, const string& courseName) {
//    int index = hashFunction(courseName);
//    int originalIndex = index;
//
//    while (hashTable[index].isOccupied) {
//        if (hashTable[index].courseName == courseName) {
//            return index;  // 找到返回索引
//        }
//        index = (index + 1) % TABLE_SIZE;
//        if (index == originalIndex) break;  // 查找一圈未找到
//    }
//    return -1;  // 未找到
//}
//
//// 测试用例
//int main() {
//    vector<Course> hashTable(TABLE_SIZE);
//
//    // 初始化课程信息
//    Course courseList[] = {
//        {"数据结构", 101},
//        {"算法", 102},
//        {"计算机网络", 103},
//        {"操作系统", 104},
//        {"数据库", 105}
//    };
//
//    // 插入课程信息到哈希表
//    for (const auto& course : courseList) {
//        insertCourse(hashTable, course);
//    }
//
//    // 查找课程
//    string searchKey = "算法";
//    int result = searchCourse(hashTable, searchKey);
//    if (result != -1) {
//        cout << "课程 '" << searchKey << "' 找到，课程ID：" << hashTable[result].courseId << endl;
//    }
//    else {
//        cout << "课程 '" << searchKey << "' 未找到。" << endl;
//    }
//
//    // 查找不存在的课程
//    searchKey = "机器学习";
//    result = searchCourse(hashTable, searchKey);
//    if (result != -1) {
//        cout << "课程 '" << searchKey << "' 找到，课程ID：" << hashTable[result].courseId << endl;
//    }
//    else {
//        cout << "课程 '" << searchKey << "' 未找到。" << endl;
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
//const int TABLE_SIZE = 10; // 哈希表大小
//
//// 课程信息的结构体
//struct Course {
//    string courseName;
//    int courseId;
//    bool isOccupied;  // 是否占用该位置
//    bool isDeleted;   // 是否已被删除
//
//    // 提供构造函数，初始化课程名称和课程 ID
//    Course(string name = "", int id = 0)
//        : courseName(name), courseId(id), isOccupied(false), isDeleted(false) {}
//};
//
//// 哈希函数：根据课程名称生成散列值
//int hashFunction(const string& courseName) {
//    int hash = 0;
//    for (char ch : courseName) {
//        hash = (hash * 31 + ch) % TABLE_SIZE;  // 使用31作为乘数来减少碰撞
//    }
//    return hash;
//}
//
//// 插入函数：使用开放地址法（线性探测）解决冲突
//void insertCourse(vector<Course>& hashTable, const Course& course) {
//    int index = hashFunction(course.courseName);
//    int originalIndex = index;
//
//    // 线性探测，找到空位或已删除的位置
//    while (hashTable[index].isOccupied && !hashTable[index].isDeleted) {
//        index = (index + 1) % TABLE_SIZE;  // 线性探测
//        if (index == originalIndex) {
//            cout << "哈希表已满，无法插入课程：" << course.courseName << endl;
//            return;
//        }
//    }
//
//    // 插入课程信息
//    hashTable[index] = course;
//    hashTable[index].isOccupied = true;
//    hashTable[index].isDeleted = false;
//}
//
//// 查找函数：在哈希表中查找课程
//int searchCourse(const vector<Course>& hashTable, const string& courseName) {
//    int index = hashFunction(courseName);
//    int originalIndex = index;
//
//    // 线性探测，找到匹配的课程或空位
//    while (hashTable[index].isOccupied) {
//        if (!hashTable[index].isDeleted && hashTable[index].courseName == courseName) {
//            return index;  // 找到返回索引
//        }
//        index = (index + 1) % TABLE_SIZE;
//        if (index == originalIndex) break;  // 查找一圈未找到
//    }
//    return -1;  // 未找到
//}
//
//// 测试用例
//int main() {
//    vector<Course> hashTable(TABLE_SIZE);
//
//    // 初始化课程信息
//    vector<Course> courseList = {
//        Course("数据结构", 101),
//        Course("算法", 102),
//        Course("计算机网络", 103),
//        Course("操作系统", 104),
//        Course("数据库", 105)
//    };
//
//    // 插入课程信息到哈希表
//    for (const auto& course : courseList) {
//        insertCourse(hashTable, course);
//    }
//
//    // 查找课程
//    string searchKey = "算法";
//    int result = searchCourse(hashTable, searchKey);
//    if (result != -1) {
//        cout << "课程 '" << searchKey << "' 找到，课程ID：" << hashTable[result].courseId << endl;
//    }
//    else {
//        cout << "课程 '" << searchKey << "' 未找到。" << endl;
//    }
//
//    // 查找不存在的课程
//    searchKey = "机器学习";
//    result = searchCourse(hashTable, searchKey);
//    if (result != -1) {
//        cout << "课程 '" << searchKey << "' 找到，课程ID：" << hashTable[result].courseId << endl;
//    }
//    else {
//        cout << "课程 '" << searchKey << "' 未找到。" << endl;
//    }
//
//    return 0;
//}


#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

const int TABLE_SIZE = 10; // 哈希表大小

// 课程信息的结构体
struct Course {
    string courseName;
    int courseId;

    Course(string name = "", int id = 0) : courseName(name), courseId(id) {}
};

// 哈希函数：根据课程名称生成散列值
int hashFunction(const string& courseName) {
    int hash = 0;
    for (char ch : courseName) {
        hash = (hash * 31 + ch) % TABLE_SIZE;  // 使用31作为乘数来减少碰撞
    }
    return hash;
}

// 哈希表类，使用链地址法处理冲突
class HashTable {
private:
    vector<list<Course>> table;  // 每个桶是一个链表
public:
    HashTable(int size) : table(size) {}

    // 插入课程到哈希表
    void insert(const Course& course) {
        int index = hashFunction(course.courseName);
        table[index].push_back(course);
    }

    // 查找课程，返回课程ID，如果未找到返回-1
    int search(const string& courseName) {
        int index = hashFunction(courseName);
        for (const auto& course : table[index]) {
            if (course.courseName == courseName) {
                return course.courseId;
            }
        }
        return -1;  // 如果没有找到课程
    }

    // 打印哈希表
    void printTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "位置 " << i << ": ";
            if (table[i].empty()) {
                cout << "空";
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

// 测试用例
int main() {
    HashTable hashTable(TABLE_SIZE);

    // 初始化课程信息
    vector<Course> courseList = {
        Course("数据结构", 101),
        Course("算法", 102),
        Course("计算机网络", 103),
        Course("操作系统", 104),
        Course("数据库", 105)
    };

    // 插入课程信息到哈希表
    for (const auto& course : courseList) {
        hashTable.insert(course);
    }

    // 打印哈希表
    cout << "哈希表内容：" << endl;
    hashTable.printTable();

    // 查找课程
    string searchKey = "算法";
    int result = hashTable.search(searchKey);
    if (result != -1) {
        cout << "课程 '" << searchKey << "' 找到，课程ID：" << result << endl;
    }
    else {
        cout << "课程 '" << searchKey << "' 未找到。" << endl;
    }

    // 查找不存在的课程
    searchKey = "机器学习";
    result = hashTable.search(searchKey);
    if (result != -1) {
        cout << "课程 '" << searchKey << "' 找到，课程ID：" << result << endl;
    }
    else {
        cout << "课程 '" << searchKey << "' 未找到。" << endl;
    }

    return 0;
}
