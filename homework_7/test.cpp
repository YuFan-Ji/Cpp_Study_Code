//#include <iostream>
//#include <vector>
//using namespace std;
//
//// 图的邻接矩阵存储
//class Graph {
//public:
//    int n; // 顶点数量
//    vector<vector<int>> adjMatrix;
//
//    Graph(int nodes) : n(nodes) {
//        adjMatrix.resize(n, vector<int>(n, 0));
//    }
//
//    void addEdge(int u, int v, int weight) {
//        adjMatrix[u][v] = weight;
//        adjMatrix[v][u] = weight; // 无向图
//    }
//
//    void display() {
//        cout << "邻接矩阵：" << endl;
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
//    int nodes = 5; // 节点数量
//    Graph g(nodes);
//
//    // 添加边
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
//        adjMatrix[v][u] = weight; // 无向图
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
//        cout << "从起点 " << start << " 到各点的最短路径距离：" << endl;
//        for (int i = 0; i < n; ++i) {
//            cout << "到 " << i << " 的距离: " << dist[i] << endl;
//        }
//    }
//};
//
//int main() {
//    int nodes = 5; // 节点数量
//    Graph g(nodes);
//
//    // 添加边
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
//        adjMatrix[v][u] = weight; // 无向图
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
//        cout << "最短路径矩阵：" << endl;
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
    int n; // 课程数量
    vector<vector<int>> adjList; // 邻接表存储课程图
    vector<int> inDegree; // 入度表，用于拓扑排序
    map<int, int> creditHours; // 每门课程的学时

public:
    CourseGraph(int nodes) : n(nodes) {
        adjList.resize(n);
        inDegree.resize(n, 0);
    }

    // 添加课程先修关系：u -> v 表示 u 是 v 的先修课
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    // 设置课程的学时
    void setCreditHours(int course, int hours) {
        creditHours[course] = hours;
    }

    // 拓扑排序并合理安排学期
    void topologicalSortAndSchedule() {
        queue<int> q;
        vector<int> topoOrder;
        vector<int> semester(n, -1); // 每门课程的学期编号
        int currentSemester = 1; // 当前学期
        int maxCredits = 20; // 每学期最大学分限制

        // 初始化：入度为 0 的课程入队列
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        cout << "拓扑排序与学期安排如下：" << endl;

        // 每轮处理一个学期的课程
        while (!q.empty()) {
            int currentCredits = 0;
            vector<int> currentSemesterCourses;

            // 处理当前学期的课程，学分不能超出限制
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int u = q.front();
                if (currentCredits + creditHours[u] > maxCredits) break;
                q.pop();

                topoOrder.push_back(u);
                semester[u] = currentSemester;
                currentSemesterCourses.push_back(u);
                currentCredits += creditHours[u];

                // 将 u 的所有后继课程入度减 1
                for (int v : adjList[u]) {
                    inDegree[v]--;
                    if (inDegree[v] == 0) q.push(v);
                }
            }

            // 输出当前学期的课程安排
            cout << "学期 " << currentSemester << "：" << endl;
            for (int course : currentSemesterCourses) {
                cout << "课程 " << course << "（" << creditHours[course] << " 学时）" << endl;
            }

            currentSemester++;
        }

        // 检查是否所有课程都已安排
        if (topoOrder.size() < n) {
            cout << "图中存在环，无法完成拓扑排序！" << endl;
        }
    }
};

int main() {
    // 初始化课程图（假设有 6 门课程）
    int numCourses = 6;
    CourseGraph graph(numCourses);

    // 设置课程的学时
    graph.setCreditHours(0, 4);
    graph.setCreditHours(1, 3);
    graph.setCreditHours(2, 5);
    graph.setCreditHours(3, 6);
    graph.setCreditHours(4, 2);
    graph.setCreditHours(5, 4);

    // 添加先修关系
    graph.addEdge(0, 1); // 课程 0 是课程 1 的先修课
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    // 执行拓扑排序并安排学期
    graph.topologicalSortAndSchedule();

    return 0;
}
