#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100  // 定义最大顶点数

// 邻接表节点结构
typedef struct Node {
    int vertex;        // 邻接节点的顶点编号
    struct Node* next; // 指向下一个节点的指针
} Node;

// 邻接表，用于存储图的所有节点
Node* graph[MAX_N];

// 添加边到邻接表
void addEdge(int u, int v) {
    // 为u顶点创建一个新的邻接节点，连接到v
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;  // 设置邻接节点的顶点
    newNode->next = graph[u];  // 将当前邻接表的第一个节点连接到新节点
    graph[u] = newNode;  // 更新u顶点的邻接表

    // 为v顶点创建一个新的邻接节点，连接到u（无向图，因此需要互相添加边）
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;  // 设置邻接节点的顶点
    newNode->next = graph[v];  // 将当前邻接表的第一个节点连接到新节点
    graph[v] = newNode;  // 更新v顶点的邻接表
}

// 检查u和v是否为直接邻居（即是否有一条边连接）
bool isDirectNeighbor(int u, int v) {
    Node* temp = graph[u];
    while (temp) {
        if (temp->vertex == v) return true;  // 找到v，说明u和v是直接邻居
        temp = temp->next;
    }
    return false;  // 如果遍历完u的邻接表都没有找到v，说明不是直接邻居
}

// 查找所有间接关系（即通过一个中间节点与u相连的顶点）
void findIndirectRelations(int n) {
    bool relations[MAX_N][MAX_N] = { false };  // 用二维数组存储间接关系，默认值为false

    // 遍历所有顶点i
    for (int i = 1; i <= n; i++) {
        Node* neighbor = graph[i];  // 获取顶点i的邻接节点
        while (neighbor) {
            int k = neighbor->vertex;  // 邻接节点k
            Node* indirectNeighbor = graph[k];  // 获取节点k的邻接表
            while (indirectNeighbor) {
                int j = indirectNeighbor->vertex;  // 获取节点j
                // 如果j不是i本身，并且i与j不是直接邻居，说明i与j是间接邻居
                if (j != i && !isDirectNeighbor(i, j)) {
                    relations[i][j] = true;  // 标记i和j为间接邻居
                }
                indirectNeighbor = indirectNeighbor->next;  // 移动到下一个邻接节点
            }
            neighbor = neighbor->next;  // 移动到下一个邻接节点
        }
    }

    // 输出所有间接关系
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (relations[i][j]) {
                printf("(%d, %d)\n", i, j);  // 输出间接关系的顶点对
            }
        }
    }
}

// 主函数
int main() {
    int n = 5;  // 定义图的顶点数
    // 添加图中的边
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(3, 4);

    printf("(1, 2) (1, 3) (1, 4) (2, 5) (3, 4)\n");

    printf("关系如下:\n");
    findIndirectRelations(n);  // 查找并输出间接关系

    return 0;
}
