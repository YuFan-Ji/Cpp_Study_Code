#include <iostream>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int data;           // 节点数据
    TreeNode* left;     // 左子节点
    TreeNode* right;    // 右子节点

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// 创建二叉树
TreeNode* createTree() {
    // 手动创建一个简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

// 前序遍历（递归）
void preorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// 中序遍历（递归）
void inorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// 后序遍历（递归）
void postorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

int main() {
    // 创建二叉树
    TreeNode* root = createTree();

    // 前序遍历
    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    // 中序遍历
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    // 后序遍历
    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}


//（2）第二关：实现二叉树中树叶结点计数、左右子树互换。
//#include <iostream>
//using namespace std;
//
//// 定义二叉树节点结构
//struct TreeNode {
//    int data;           // 节点数据
//    TreeNode* left;     // 左子节点
//    TreeNode* right;    // 右子节点
//
//    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
//};
//
//// 创建二叉树
//TreeNode* createTree() {
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(7);
//    return root;
//}
//
//// 计算叶节点数量
//int countLeafNodes(TreeNode* node) {
//    if (node == nullptr) return 0;
//    if (node->left == nullptr && node->right == nullptr) return 1;  // 叶节点
//    return countLeafNodes(node->left) + countLeafNodes(node->right);
//}
//
//// 互换左右子树
//void swapLeftRight(TreeNode* node) {
//    if (node == nullptr) return;
//
//    // 交换左右子节点
//    TreeNode* temp = node->left;
//    node->left = node->right;
//    node->right = temp;
//
//    // 递归地对左右子节点进行交换
//    swapLeftRight(node->left);
//    swapLeftRight(node->right);
//}
//
//// 中序遍历，用于查看树结构
//void inorderTraversal(TreeNode* node) {
//    if (node == nullptr) return;
//    inorderTraversal(node->left);
//    cout << node->data << " ";
//    inorderTraversal(node->right);
//}
//
//int main() {
//    // 创建二叉树
//    TreeNode* root = createTree();
//
//    // 计算叶节点数量
//    int leafCount = countLeafNodes(root);
//    cout << "Number of leaf nodes: " << leafCount << endl;
//
//    // 交换左右子树
//    cout << "Inorder traversal before swapping: ";
//    inorderTraversal(root);
//    cout << endl;
//
//    swapLeftRight(root);
//
//    cout << "Inorder traversal after swapping: ";
//    inorderTraversal(root);
//    cout << endl;
//
//    return 0;
//}
//
//（3）第三关：设计二叉树结构，实现家族族谱树创建及相关查找
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct FamilyMember {
//    string name;        // 成员姓名
//    string gender;      // 性别
//    int birthYear;      // 出生年份
//    FamilyMember* father;  // 父亲节点
//    FamilyMember* mother;  // 母亲节点
//
//    FamilyMember(string n, string g, int b)
//        : name(n), gender(g), birthYear(b), father(nullptr), mother(nullptr) {}
//};
//
//class FamilyTree {
//private:
//    FamilyMember* root;  // 家族树的根节点
//
//public:
//    FamilyTree() : root(nullptr) {}
//
//    // 添加家族成员
//    void addFamilyMember(string name, string gender, int birthYear, string fatherName, string motherName) {
//        FamilyMember* father = findMember(fatherName);
//        FamilyMember* mother = findMember(motherName);
//
//        FamilyMember* newMember = new FamilyMember(name, gender, birthYear);
//        newMember->father = father;
//        newMember->mother = mother;
//
//        if (root == nullptr) {
//            root = newMember;
//        }
//        else {
//            if (father) {
//                father->father = newMember;
//            }
//            else if (mother) {
//                mother->mother = newMember;
//            }
//        }
//    }
//
//    // 查找家族成员
//    FamilyMember* findMember(string name) {
//        return findMemberRecursive(root, name);
//    }
//
//    FamilyMember* findMemberRecursive(FamilyMember* node, string name) {
//        if (node == nullptr) return nullptr;
//        if (node->name == name) return node;
//
//        FamilyMember* fatherSearch = findMemberRecursive(node->father, name);
//        if (fatherSearch) return fatherSearch;
//
//        return findMemberRecursive(node->mother, name);
//    }
//
//    // 输出族谱信息
//    void printFamilyTree(FamilyMember* member) {
//        if (member == nullptr) {
//            return;
//        }
//        cout << "Name: " << member->name << ", Gender: " << member->gender << ", Birth Year: " << member->birthYear << endl;
//
//        if (member->father) {
//            cout << "Father: " << member->father->name << endl;
//        }
//        if (member->mother) {
//            cout << "Mother: " << member->mother->name << endl;
//        }
//
//        printFamilyTree(member->father);
//        printFamilyTree(member->mother);
//    }
//
//    void printFamilyTree() {
//        printFamilyTree(root);
//    }
//};
//int main() {
//    FamilyTree tree;
//
//    // 添加家族成员
//    tree.addFamilyMember("John", "Male", 1945, "", "");  // 祖父
//    tree.addFamilyMember("Mary", "Female", 1950, "", "");  // 祖母
//    tree.addFamilyMember("David", "Male", 1970, "John", "Mary");  // 父亲
//    tree.addFamilyMember("Eve", "Female", 1975, "John", "Mary");  // 母亲
//    tree.addFamilyMember("Alice", "Female", 2000, "David", "Eve");  // 子女 Alice
//    tree.addFamilyMember("Bob", "Male", 2005, "David", "Eve");  // 子女 Bob
//
//    // 查找成员信息
//    FamilyMember* member = tree.findMember("Alice");
//    if (member != nullptr) {
//        cout << "Found member: " << member->name << endl;
//    }
//    else {
//        cout << "Member not found." << endl;
//    }
//
//    // 输出家族树
//    tree.printFamilyTree();
//
//    return 0;
//}
