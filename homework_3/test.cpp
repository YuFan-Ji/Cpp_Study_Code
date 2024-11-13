#include <iostream>
using namespace std;

// ����������ڵ�ṹ
struct TreeNode {
    int data;           // �ڵ�����
    TreeNode* left;     // ���ӽڵ�
    TreeNode* right;    // ���ӽڵ�

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// ����������
TreeNode* createTree() {
    // �ֶ�����һ���򵥵Ķ�����
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

// ǰ��������ݹ飩
void preorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// ����������ݹ飩
void inorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// ����������ݹ飩
void postorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

int main() {
    // ����������
    TreeNode* root = createTree();

    // ǰ�����
    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    // �������
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    // �������
    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}


//��2���ڶ��أ�ʵ�ֶ���������Ҷ����������������������
//#include <iostream>
//using namespace std;
//
//// ����������ڵ�ṹ
//struct TreeNode {
//    int data;           // �ڵ�����
//    TreeNode* left;     // ���ӽڵ�
//    TreeNode* right;    // ���ӽڵ�
//
//    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
//};
//
//// ����������
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
//// ����Ҷ�ڵ�����
//int countLeafNodes(TreeNode* node) {
//    if (node == nullptr) return 0;
//    if (node->left == nullptr && node->right == nullptr) return 1;  // Ҷ�ڵ�
//    return countLeafNodes(node->left) + countLeafNodes(node->right);
//}
//
//// ������������
//void swapLeftRight(TreeNode* node) {
//    if (node == nullptr) return;
//
//    // ���������ӽڵ�
//    TreeNode* temp = node->left;
//    node->left = node->right;
//    node->right = temp;
//
//    // �ݹ�ض������ӽڵ���н���
//    swapLeftRight(node->left);
//    swapLeftRight(node->right);
//}
//
//// ������������ڲ鿴���ṹ
//void inorderTraversal(TreeNode* node) {
//    if (node == nullptr) return;
//    inorderTraversal(node->left);
//    cout << node->data << " ";
//    inorderTraversal(node->right);
//}
//
//int main() {
//    // ����������
//    TreeNode* root = createTree();
//
//    // ����Ҷ�ڵ�����
//    int leafCount = countLeafNodes(root);
//    cout << "Number of leaf nodes: " << leafCount << endl;
//
//    // ������������
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
//��3�������أ���ƶ������ṹ��ʵ�ּ�����������������ز���
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct FamilyMember {
//    string name;        // ��Ա����
//    string gender;      // �Ա�
//    int birthYear;      // �������
//    FamilyMember* father;  // ���׽ڵ�
//    FamilyMember* mother;  // ĸ�׽ڵ�
//
//    FamilyMember(string n, string g, int b)
//        : name(n), gender(g), birthYear(b), father(nullptr), mother(nullptr) {}
//};
//
//class FamilyTree {
//private:
//    FamilyMember* root;  // �������ĸ��ڵ�
//
//public:
//    FamilyTree() : root(nullptr) {}
//
//    // ��Ӽ����Ա
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
//    // ���Ҽ����Ա
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
//    // ���������Ϣ
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
//    // ��Ӽ����Ա
//    tree.addFamilyMember("John", "Male", 1945, "", "");  // �游
//    tree.addFamilyMember("Mary", "Female", 1950, "", "");  // ��ĸ
//    tree.addFamilyMember("David", "Male", 1970, "John", "Mary");  // ����
//    tree.addFamilyMember("Eve", "Female", 1975, "John", "Mary");  // ĸ��
//    tree.addFamilyMember("Alice", "Female", 2000, "David", "Eve");  // ��Ů Alice
//    tree.addFamilyMember("Bob", "Male", 2005, "David", "Eve");  // ��Ů Bob
//
//    // ���ҳ�Ա��Ϣ
//    FamilyMember* member = tree.findMember("Alice");
//    if (member != nullptr) {
//        cout << "Found member: " << member->name << endl;
//    }
//    else {
//        cout << "Member not found." << endl;
//    }
//
//    // ���������
//    tree.printFamilyTree();
//
//    return 0;
//}
