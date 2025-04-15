#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100  // ������󶥵���

// �ڽӱ�ڵ�ṹ
typedef struct Node {
    int vertex;        // �ڽӽڵ�Ķ�����
    struct Node* next; // ָ����һ���ڵ��ָ��
} Node;

// �ڽӱ����ڴ洢ͼ�����нڵ�
Node* graph[MAX_N];

// ��ӱߵ��ڽӱ�
void addEdge(int u, int v) {
    // Ϊu���㴴��һ���µ��ڽӽڵ㣬���ӵ�v
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;  // �����ڽӽڵ�Ķ���
    newNode->next = graph[u];  // ����ǰ�ڽӱ�ĵ�һ���ڵ����ӵ��½ڵ�
    graph[u] = newNode;  // ����u������ڽӱ�

    // Ϊv���㴴��һ���µ��ڽӽڵ㣬���ӵ�u������ͼ�������Ҫ������ӱߣ�
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;  // �����ڽӽڵ�Ķ���
    newNode->next = graph[v];  // ����ǰ�ڽӱ�ĵ�һ���ڵ����ӵ��½ڵ�
    graph[v] = newNode;  // ����v������ڽӱ�
}

// ���u��v�Ƿ�Ϊֱ���ھӣ����Ƿ���һ�������ӣ�
bool isDirectNeighbor(int u, int v) {
    Node* temp = graph[u];
    while (temp) {
        if (temp->vertex == v) return true;  // �ҵ�v��˵��u��v��ֱ���ھ�
        temp = temp->next;
    }
    return false;  // ���������u���ڽӱ�û���ҵ�v��˵������ֱ���ھ�
}

// �������м�ӹ�ϵ����ͨ��һ���м�ڵ���u�����Ķ��㣩
void findIndirectRelations(int n) {
    bool relations[MAX_N][MAX_N] = { false };  // �ö�ά����洢��ӹ�ϵ��Ĭ��ֵΪfalse

    // �������ж���i
    for (int i = 1; i <= n; i++) {
        Node* neighbor = graph[i];  // ��ȡ����i���ڽӽڵ�
        while (neighbor) {
            int k = neighbor->vertex;  // �ڽӽڵ�k
            Node* indirectNeighbor = graph[k];  // ��ȡ�ڵ�k���ڽӱ�
            while (indirectNeighbor) {
                int j = indirectNeighbor->vertex;  // ��ȡ�ڵ�j
                // ���j����i��������i��j����ֱ���ھӣ�˵��i��j�Ǽ���ھ�
                if (j != i && !isDirectNeighbor(i, j)) {
                    relations[i][j] = true;  // ���i��jΪ����ھ�
                }
                indirectNeighbor = indirectNeighbor->next;  // �ƶ�����һ���ڽӽڵ�
            }
            neighbor = neighbor->next;  // �ƶ�����һ���ڽӽڵ�
        }
    }

    // ������м�ӹ�ϵ
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (relations[i][j]) {
                printf("(%d, %d)\n", i, j);  // �����ӹ�ϵ�Ķ����
            }
        }
    }
}

// ������
int main() {
    int n = 5;  // ����ͼ�Ķ�����
    // ���ͼ�еı�
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(3, 4);

    printf("(1, 2) (1, 3) (1, 4) (2, 5) (3, 4)\n");

    printf("��ϵ����:\n");
    findIndirectRelations(n);  // ���Ҳ������ӹ�ϵ

    return 0;
}
