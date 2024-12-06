//#include <iostream>
//#include <vector>
//using namespace std;
//
//// ͼ���ڽӾ���洢
//class Graph {
//public:
//    int n; // ��������
//    vector<vector<int>> adjMatrix;
//
//    Graph(int nodes) : n(nodes) {
//        adjMatrix.resize(n, vector<int>(n, 0));
//    }
//
//    void addEdge(int u, int v, int weight) {
//        adjMatrix[u][v] = weight;
//        adjMatrix[v][u] = weight; // ����ͼ
//    }
//
//    void display() {
//        cout << "�ڽӾ���" << endl;
//        for (const auto& row : adjMatrix) {
//            for (int val : row) {
//                cout << val << " ";
//            }
//            cout << endl;
//        }
//    }
//};
//
//int main() {
//    int nodes = 5; // �ڵ�����
//    Graph g(nodes);
//
//    // ��ӱ�
//    g.addEdge(0, 1, 2);
//    g.addEdge(0, 2, 4);
//    g.addEdge(1, 2, 3);
//    g.addEdge(1, 3, 5);
//    g.addEdge(2, 4, 1);
//
//    g.display();
//
//    return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <limits.h>
//using namespace std;
//
//class Graph {
//public:
//    int n;
//    vector<vector<int>> adjMatrix;
//
//    Graph(int nodes) : n(nodes) {
//        adjMatrix.resize(n, vector<int>(n, 0));
//    }
//
//    void addEdge(int u, int v, int weight) {
//        adjMatrix[u][v] = weight;
//        adjMatrix[v][u] = weight; // ����ͼ
//    }
//
//    void dijkstra(int start) {
//        vector<int> dist(n, INT_MAX);
//        vector<bool> visited(n, false);
//        dist[start] = 0;
//
//        for (int i = 0; i < n; ++i) {
//            int u = -1;
//            for (int j = 0; j < n; ++j) {
//                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
//                    u = j;
//                }
//            }
//
//            if (dist[u] == INT_MAX) break;
//            visited[u] = true;
//
//            for (int v = 0; v < n; ++v) {
//                if (!visited[v] && adjMatrix[u][v] && dist[u] + adjMatrix[u][v] < dist[v]) {
//                    dist[v] = dist[u] + adjMatrix[u][v];
//                }
//            }
//        }
//
//        cout << "����� " << start << " ����������·�����룺" << endl;
//        for (int i = 0; i < n; ++i) {
//            cout << "�� " << i << " �ľ���: " << dist[i] << endl;
//        }
//    }
//};
//
//int main() {
//    int nodes = 5; // �ڵ�����
//    Graph g(nodes);
//
//    // ��ӱ�
//    g.addEdge(0, 1, 2);
//    g.addEdge(0, 2, 4);
//    g.addEdge(1, 2, 3);
//    g.addEdge(1, 3, 5);
//    g.addEdge(2, 4, 1);
//
//    g.dijkstra(0);
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <limits.h>
//using namespace std;
//
//class Graph {
//public:
//    int n;
//    vector<vector<int>> adjMatrix;
//
//    Graph(int nodes) : n(nodes) {
//        adjMatrix.resize(n, vector<int>(n, INT_MAX));
//        for (int i = 0; i < n; ++i) adjMatrix[i][i] = 0;
//    }
//
//    void addEdge(int u, int v, int weight) {
//        adjMatrix[u][v] = weight;
//        adjMatrix[v][u] = weight; // ����ͼ
//    }
//
//    void floyd() {
//        vector<vector<int>> dist = adjMatrix;
//
//        for (int k = 0; k < n; ++k) {
//            for (int i = 0; i < n; ++i) {
//                for (int j = 0; j < n; ++j) {
//                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
//                        dist[i][j] = dist[i][k] + dist[k][j];
//                    }
//                }
//            }
//        }
//
//        cout << "���·������" << endl;
//        for (const auto& row : dist) {
//            for (int val : row) {
//                if (val == INT_MAX) cout << "INF ";
//                else cout << val << " ";
//            }
//            cout << endl;
//        }
//    }
//};
//
//int main() {
//    int nodes = 5;
//    Graph g(nodes);
//
//    g.addEdge(0, 1, 2);
//    g.addEdge(0, 2, 4);
//    g.addEdge(1, 2, 3);
//    g.addEdge(1, 3, 5);
//    g.addEdge(2, 4, 1);
//
//    g.floyd();
//
//    return 0;
//}
//





#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class CourseGraph {
private:
    int n; // �γ�����
    vector<vector<int>> adjList; // �ڽӱ�洢�γ�ͼ
    vector<int> inDegree; // ��ȱ�������������
    map<int, int> creditHours; // ÿ�ſγ̵�ѧʱ

public:
    CourseGraph(int nodes) : n(nodes) {
        adjList.resize(n);
        inDegree.resize(n, 0);
    }

    // ��ӿγ����޹�ϵ��u -> v ��ʾ u �� v �����޿�
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    // ���ÿγ̵�ѧʱ
    void setCreditHours(int course, int hours) {
        creditHours[course] = hours;
    }

    // �������򲢺�����ѧ��
    void topologicalSortAndSchedule() {
        queue<int> q;
        vector<int> topoOrder;
        vector<int> semester(n, -1); // ÿ�ſγ̵�ѧ�ڱ��
        int currentSemester = 1; // ��ǰѧ��
        int maxCredits = 20; // ÿѧ�����ѧ������

        // ��ʼ�������Ϊ 0 �Ŀγ������
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        cout << "����������ѧ�ڰ������£�" << endl;

        // ÿ�ִ���һ��ѧ�ڵĿγ�
        while (!q.empty()) {
            int currentCredits = 0;
            vector<int> currentSemesterCourses;

            // ����ǰѧ�ڵĿγ̣�ѧ�ֲ��ܳ�������
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int u = q.front();
                if (currentCredits + creditHours[u] > maxCredits) break;
                q.pop();

                topoOrder.push_back(u);
                semester[u] = currentSemester;
                currentSemesterCourses.push_back(u);
                currentCredits += creditHours[u];

                // �� u �����к�̿γ���ȼ� 1
                for (int v : adjList[u]) {
                    inDegree[v]--;
                    if (inDegree[v] == 0) q.push(v);
                }
            }

            // �����ǰѧ�ڵĿγ̰���
            cout << "ѧ�� " << currentSemester << "��" << endl;
            for (int course : currentSemesterCourses) {
                cout << "�γ� " << course << "��" << creditHours[course] << " ѧʱ��" << endl;
            }

            currentSemester++;
        }

        // ����Ƿ����пγ̶��Ѱ���
        if (topoOrder.size() < n) {
            cout << "ͼ�д��ڻ����޷������������" << endl;
        }
    }
};

int main() {
    // ��ʼ���γ�ͼ�������� 6 �ſγ̣�
    int numCourses = 6;
    CourseGraph graph(numCourses);

    // ���ÿγ̵�ѧʱ
    graph.setCreditHours(0, 4);
    graph.setCreditHours(1, 3);
    graph.setCreditHours(2, 5);
    graph.setCreditHours(3, 6);
    graph.setCreditHours(4, 2);
    graph.setCreditHours(5, 4);

    // ������޹�ϵ
    graph.addEdge(0, 1); // �γ� 0 �ǿγ� 1 �����޿�
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    // ִ���������򲢰���ѧ��
    graph.topologicalSortAndSchedule();

    return 0;
}
