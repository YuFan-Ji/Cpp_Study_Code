//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstdlib>
//#include<ctime>
//using namespace std;
//
//int quick_sort(vector<int>& v, int left, int right, int key)
//{
//    int i = left, j = right;
//    int x = v[left]; 
//
//    while (i < j)
//    {
//        while (i < j && v[j] >= x) 
//        {
//            j--;
//        }
//        while (i < j && v[i] <= x)  
//        {
//            i++;
//        }
//        if (i < j)
//        {
//            swap(v[i], v[j]); 
//        }
//    }
//
//    v[left] = v[i];
//    v[i] = x; 
//
//    if (i - left + 1 == key)
//    {
//        return v[i];
//    }
//    else if (i - left + 1 < key)
//    {
//        return quick_sort(v, i + 1, right, key - (i - left + 1)); 
//    }
//    else  
//    {
//        return quick_sort(v, left, i - 1, key);  
//    }
//}
//
//int main()
//{
//    srand(time(0));
//    vector<int> v;
//    for (int i = 0; i < 50; i++)
//    {
//        v.push_back(rand() % 200);  
//    }
//
//    cout << "随机生成的50个数为：" << endl;
//    for (auto e : v)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//
//    int ret = quick_sort(v, 0, v.size() - 1, 8); 
//
//    cout << "第8小的数是： " << ret << endl;
//
//    return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//int a[100][100];
//
//void table(int k, int d)  
//{
//	if (k == d)
//		return;
//	int i, j;
//	for (i = 0; i < d; i++)
//	{
//		for (j = 0; j < d; j++)
//		{
//			a[i + d][j + d] = a[i][j];
//			a[i][j + d] = a[i][j] + d;
//			a[i + d][j] = a[i][j] + d;
//		}
//	}
//	table(k, d * 2);
//}
//
//int main()
//{
//	//输入人数
//
//	int k;
//	cin >> k;
//
//	//判断只有一个人时
//	if (k == 1)
//		a[0][0] = 0;
//	else
//		a[0][0] = 1;
//	//递归
//	table(k, 1);
//	//输出
//	for (int i = 0; i < k; i++)
//	{
//		for (int j = 0; j < k; j++)
//		{
//			cout << a[i][j] << ' ';
//		}
//		cout << endl;
//	}
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//// 计算给定排列的字典序值
//int calculateLexicographicRank(const vector<int>& arr) {
//    int n = arr.size();
//    int rank = 0;
//    vector<int> fact(n + 1, 1);  // 用于存储阶乘
//    for (int i = 2; i <= n; ++i) {
//        fact[i] = fact[i - 1] * i;
//    }
//
//    for (int i = 0; i < n; ++i) {
//        int count = 0;
//        for (int j = i + 1; j < n; ++j) {
//            if (arr[j] < arr[i]) {
//                count++;
//            }
//        }
//        rank += count * fact[n - 1 - i];
//    }
//
//    return rank;
//}
//
//// 获取下一个排列
//bool nextPermutation(vector<int>& arr) {
//    int n = arr.size();
//    int i = n - 2;
//    while (i >= 0 && arr[i] >= arr[i + 1]) {
//        i--;
//    }
//
//    if (i >= 0) {
//        int j = n - 1;
//        while (arr[j] <= arr[i]) {
//            j--;
//        }
//        swap(arr[i], arr[j]);
//        reverse(arr.begin() + i + 1, arr.end());
//        return true;
//    }
//    return false;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> arr(n);
//
//    // 输入给定的排列
//    for (int i = 0; i < n; ++i) {
//        cin >> arr[i];
//    }
//
//    // 计算字典序值
//    int rank = calculateLexicographicRank(arr);
//    cout << "它对应的编号是" << rank << endl;
//
//    // 计算并输出下一个排列
//    if (nextPermutation(arr)) {
//        for (int i = 0; i < n; ++i) {
//            cout << arr[i];
//        }
//    }
//    else {
//        cout << "没有下一个排列" << endl;
//    }
//
//    return 0;
//}



//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
//int main()
//{
//	int end = 1; // 几匹马 + 结束标志
//	int a;       // 马速度
//	cin >> end;
//	vector<int> arr_ret;// 结果
//	while (end != 0)
//	{
//		int ret = 0;
//		vector<int> tj, queen;
//
//		for (int i = 0; i < end; i++)
//		{
//			cin >> a;
//			tj.push_back(a);
//		}
//		for (int i = 0; i < end; i++)
//		{
//			cin >> a;
//			queen.push_back(a);
//		}
//
//		sort(tj.begin(), tj.end());     
//		sort(queen.begin(), queen.end());
//
//		// 贪心
//		int i = 0, j = 0;
//		while (i < end && j < end)
//		{
//			if (tj[i] > queen[j])
//			{
//				ret++;
//				i++; j++;
//			}
//			else if (tj[i] < queen[j])
//			{
//				i++;
//				ret--;
//			}
//			else
//			{
//				i++;
//				j++;
//			}
//		}
//		arr_ret.push_back(ret * 200);
//		cin >> end;
//	}
//
//	cout << endl;
//
//	for (auto e : arr_ret)
//	{
//		cout << e << endl;
//	}
//
//	return 0;
//}
//
//#include <bits/stdc++.h>
//using namespace std;
//
//int f[30], d[30], t[30], p[30], best;
//
//void calc(int n, int h) {
//    int time = 0;
//    best = -1;
//    for (int i = 1; i <= n && h - time; i++) {
//        int fish[30];
//        memset(fish, 0, sizeof(fish));
//        int totalFish = 0;
//        memset(p, 0, sizeof(p));
//
//        for (int j = 0; j < i; ++j) {
//            fish[j] = f[j];
//        }
//
//        for (int j = 0; j < h - time; ++j) {
//            int maxFish = 0, idx = -1;
//            for (int k = 0; k < i; ++k) {
//                if (fish[k] > maxFish) {
//                    maxFish = fish[k];
//                    idx = k;
//                }
//            }
//            if (idx != -1) {
//                p[idx]++;
//                fish[idx] -= d[idx];
//                totalFish += maxFish;
//            }
//            else {
//                p[0]++;
//            }
//        }
//
//        if (totalFish > best) {
//            best = totalFish;
//            memcpy(fish, p, sizeof(p));
//        }
//        time += t[i];
//    }
//}
//
//int main() {
//    int n, h;
//    cin >> n >> h;
//
//    for (int i = 0; i < n; i++) cin >> f[i];
//    for (int i = 0; i < n; i++) cin >> d[i];
//    for (int i = 0; i < n - 1; i++) cin >> t[i];
//
//    h *= 12;
//
//    calc(n, h);
//
//    for (int i = 0; i < n - 1; i++) cout << p[i] * 5 << endl;
//    cout << p[n - 1] * 5 << endl;
//    cout << "Number:" << best << endl;
//
//    return 0;
//}
//
//
//
//
///*
//输入：
//4 4
//10 15 20 17
//0 3 4 3
//1 2 3
//输出：
//240
//0
//0
//0
//Number:480
//*/



//#include <iostream>
//#include <vector>
//#include <climits>
//
//using namespace std;
//
//
//const int N = 11; 
//const int INF = INT_MAX;
//
//
//vector<pair<int, int>> graph[N];
//
//
//int dp[N];
//int path[N]; 
//
//void shortestPath() {
//    
//    for (int i = 0; i < N; i++) {
//        dp[i] = INF;
//    }
//    dp[10] = 0; 
//
//   
//    for (int i = 9; i >= 1; --i) {
//        int size = graph[i].size();
//        for (int j = 0; j < size; j++) {
//            int neighbor = graph[i][j].first;
//            int cost = graph[i][j].second;
//            if (dp[i] > cost + dp[neighbor]) {
//                dp[i] = cost + dp[neighbor];
//                path[i] = neighbor;
//            }
//        }
//    }
//
//
//    cout << "最短路径: ";
//    int node = 1;
//    while (node != 0) {
//        cout << node << " ";
//        node = path[node];
//    }
//    cout << endl;
//
//    cout << "最短距离: " << dp[1] << endl;
//}
//
//int main() {
//    
//    graph[1].push_back(make_pair(2, 4));
//    graph[1].push_back(make_pair(3, 2));
//    graph[1].push_back(make_pair(4, 3));
//
//    graph[2].push_back(make_pair(5, 10));
//    graph[2].push_back(make_pair(6, 9));
//
//    graph[3].push_back(make_pair(5, 6));
//    graph[3].push_back(make_pair(6, 7));
//    graph[3].push_back(make_pair(7, 10));
//
//    graph[4].push_back(make_pair(6, 3));
//    graph[4].push_back(make_pair(7, 8));
//
//    graph[5].push_back(make_pair(8, 4));
//    graph[5].push_back(make_pair(9, 8));
//
//    graph[6].push_back(make_pair(8, 9));
//    graph[6].push_back(make_pair(9, 6));
//
//    graph[7].push_back(make_pair(8, 5));
//    graph[7].push_back(make_pair(9, 4));
//
//    graph[8].push_back(make_pair(10, 8));
//    graph[9].push_back(make_pair(10, 4));
//
//   
//    shortestPath();
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//string X = "2300110508";
//string Y = "20220528";
//
//vector<vector<int>> computeLCS() {
//    int m = X.size(), n = Y.size();
//    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//
//    for (int i = 1; i <= m; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (X[i - 1] == Y[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1] + 1;
//            }
//            else {
//                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//            }
//        }
//    }
//    return dp;
//}
//
//set<string> findAllLCS(vector<vector<int>>& dp, int i, int j) {
//    if (i == 0 || j == 0) return { "" };
//
//    if (X[i - 1] == Y[j - 1]) {
//        set<string> lcs_set = findAllLCS(dp, i - 1, j - 1);
//        set<string> new_lcs_set;
//        for (string s : lcs_set) {
//            new_lcs_set.insert(s + X[i - 1]);
//        }
//        return new_lcs_set;
//    }
//
//    set<string> lcs_set;
//    if (dp[i - 1][j] >= dp[i][j - 1]) {
//        lcs_set = findAllLCS(dp, i - 1, j);
//    }
//    if (dp[i][j - 1] >= dp[i - 1][j]) {
//        set<string> temp_set = findAllLCS(dp, i, j - 1);
//        lcs_set.insert(temp_set.begin(), temp_set.end());
//    }
//    return lcs_set;
//}
//
//void printTable(vector<vector<int>>& dp) {
//    cout << "  ";
//    for (char c : Y) cout << c << " ";
//    cout << endl;
//
//    for (int i = 0; i <= X.size(); i++) {
//        if (i > 0) cout << X[i - 1] << " ";
//        else cout << "  ";
//
//        for (int j = 0; j <= Y.size(); j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//
//    vector<vector<int>> dp = computeLCS();
//
//    cout << "LCS 计算表：" << endl;
//    printTable(dp);
//
//    int lcs_length = dp[X.size()][Y.size()];
//    cout << "最长公共子序列的长度: " << lcs_length << endl;
//
//    set<string> all_lcs = findAllLCS(dp, X.size(), Y.size());
//
//    cout << "所有最长公共子序列：" << endl;
//    for (const string& lcs : all_lcs) {
//        cout << lcs << endl;
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <climits>
//
//using namespace std;
//
//void printOptimalParens(vector<vector<int>>& s, int i, int j) {
//    if (i == j) {
//        cout << "A" << i;
//        return;
//    }
//    cout << "(";
//    printOptimalParens(s, i, s[i][j]);
//    cout << " × ";
//    printOptimalParens(s, s[i][j] + 1, j);
//    cout << ")";
//}
//
//void matrixChainOrder(vector<int>& r) {
//    int n = r.size() - 1;
//    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));
//
//    for (int len = 2; len <= n; len++) {
//        for (int i = 1; i <= n - len + 1; i++) {
//            int j = i + len - 1;
//            dp[i][j] = INT_MAX;
//            for (int k = i; k < j; k++) {
//                int cost = dp[i][k] + dp[k + 1][j] + r[i - 1] * r[k] * r[j];
//                if (cost < dp[i][j]) {
//                    dp[i][j] = cost;
//                    s[i][j] = k;
//                }
//            }
//        }
//    }
//
//    cout << "最少乘法次数: " << dp[1][n] << endl;
//    cout << "最佳连乘次序: ";
//    printOptimalParens(s, 1, n);
//    cout << endl;
//}
//
//int main() {
//    vector<int> r = { 5, 10, 3, 12, 5, 50, 6 };
//    matrixChainOrder(r);
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Item {
//    int weight, value, index;
//    double ratio;
//};
//
//bool compare(Item a, Item b) {
//    return a.ratio > b.ratio;
//}
//
//void greedyKnapsack(vector<Item>& items, int M) {
//    sort(items.begin(), items.end(), compare);
//    vector<int> X(items.size(), 0);
//    int currentWeight = 0, totalValue = 0;
//
//    for (int i = 0; i < items.size(); i++) {
//        if (currentWeight + items[i].weight <= M) {
//            X[items[i].index] = 1;
//            currentWeight += items[i].weight;
//            totalValue += items[i].value;
//        }
//    }
//
//    cout << "贪心算法最优解: ";
//    for (int i = 0; i < X.size(); i++) cout << X[i] << " ";
//    cout << endl;
//    cout << "总价值: " << totalValue << endl;
//}
//
//void knapsack01(vector<Item>& items, int M) {
//    int n = items.size();
//    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));
//    vector<vector<int>> keep(n + 1, vector<int>(M + 1, 0));
//
//    for (int i = 1; i <= n; i++) {
//        for (int w = 0; w <= M; w++) {
//            if (items[i - 1].weight <= w) {
//                if (items[i - 1].value + dp[i - 1][w - items[i - 1].weight] > dp[i - 1][w]) {
//                    dp[i][w] = items[i - 1].value + dp[i - 1][w - items[i - 1].weight];
//                    keep[i][w] = 1;
//                }
//                else {
//                    dp[i][w] = dp[i - 1][w];
//                }
//            }
//            else {
//                dp[i][w] = dp[i - 1][w];
//            }
//        }
//    }
//
//    vector<int> X(n, 0);
//    int w = M;
//    for (int i = n; i > 0; i--) {
//        if (keep[i][w]) {
//            X[items[i - 1].index] = 1;
//            w -= items[i - 1].weight;
//        }
//    }
//
//    cout << "0/1背包最优解: ";
//    for (int i = 0; i < X.size(); i++) cout << X[i] << " ";
//    cout << endl;
//    cout << "总价值: " << dp[n][M] << endl;
//}
//
//int main() {
//    vector<Item> items = {
//        {1, 11, 0}, {11, 21, 1}, {21, 31, 2}, {23, 33, 3},
//        {33, 43, 4}, {43, 53, 5}, {45, 55, 6}, {55, 65, 7}
//    };
//
//    for (auto& item : items) item.ratio = (double)item.value / item.weight;
//
//    int M = 110;
//    greedyKnapsack(items, M);
//    knapsack01(items, M);
//
//    return 0;
//}


//#include <iostream>
//#include <queue>
//#include <unordered_set>
//#include <algorithm>
//
//using namespace std;
//
//int f(int i) {
//    return 3 * i;
//}
//
//int g(int i) {
//    return i / 2;
//}
//
//int minChanges(int start, int target) {
//    if (start == target) return 0;
//
//    queue<pair<int, int>> q;
//    unordered_set<int> visited;
//
//    q.push({ start, 0 });
//    visited.insert(start);
//
//    while (!q.empty()) {
//        int current = q.front().first;
//        int steps = q.front().second;
//        q.pop();
//
//        int next_f = f(current);
//        if (next_f == target) return steps + 1;
//        if (visited.find(next_f) == visited.end()) {
//            visited.insert(next_f);
//            q.push({ next_f, steps + 1 });
//        }
//
//        int next_g = g(current);
//        if (next_g == target) return steps + 1;
//        if (visited.find(next_g) == visited.end()) {
//            visited.insert(next_g);
//            q.push({ next_g, steps + 1 });
//        }
//    }
//
//    return -1;
//}
//
//int main() {
//    int start, target;
//    cout << "请输入起始值和目标值: ";
//    cin >> start >> target;
//
//    int result = minChanges(start, target);
//    if (result != -1) {
//        cout << "最小变化次数: " << result << endl;
//    }
//    else {
//        cout << "没有解。" << endl;
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool isValid(int node, const vector<vector<bool>>& adj, const vector<int>& selected) {
//    for (int i : selected) {
//        if (adj[node][i]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//void findMaxIndependence(int N, const vector<vector<bool>>& adj, vector<int>& selected, int& maxSize, vector<int>& bestSelection, int start) {
//    if (start == N) {
//        if (selected.size() > maxSize) {
//            maxSize = selected.size();
//            bestSelection = selected;
//        }
//        return;
//    }
//
//    if (isValid(start, adj, selected)) {
//        selected.push_back(start);
//        findMaxIndependence(N, adj, selected, maxSize, bestSelection, start + 1);
//        selected.pop_back();
//    }
//
//    findMaxIndependence(N, adj, selected, maxSize, bestSelection, start + 1);
//}
//
//int main() {
//    int N, M;
//    cout << "请输入村民人数N和好友关系数M: ";
//    cin >> N >> M;
//
//    vector<vector<bool>> adj(N, vector<bool>(N, false));
//
//    cout << "请输入好友关系的M对村民编号: " << endl;
//    for (int i = 0; i < M; ++i) {
//        int u, v;
//        cin >> u >> v;
//        adj[u - 1][v - 1] = adj[v - 1][u - 1] = true;
//    }
//
//    int maxSize = 0;
//    vector<int> bestSelection;
//    vector<int> selected;
//
//    findMaxIndependence(N, adj, selected, maxSize, bestSelection, 0);
//
//    cout << "最大监督团成员人数: " << maxSize << endl;
//    cout << "监督团成员编号: ";
//    for (int i : bestSelection) {
//        cout << i + 1 << " ";
//    }
//    cout << endl;
//
//    return 0;
//}


#include <iostream>
#include <vector>
#include <climits>
#include <functional>

using namespace std;

int minOperations(vector<int>& nums, int target) {
    int n = nums.size();
    int minOps = INT_MAX;

    // 回溯函数
    function<void(int, vector<int>, int)> dfs = [&](int current, vector<int> remaining, int opCount) {
        if (remaining.empty()) {
            if (current == target) {
                minOps = min(minOps, opCount);
            }
            return;
        }

        for (int i = 0; i < remaining.size(); ++i) {
            vector<int> newRemaining = remaining;
            newRemaining.erase(newRemaining.begin() + i);

            // 加法
            dfs(current + remaining[i], newRemaining, opCount + 1);
            // 减法
            dfs(current - remaining[i], newRemaining, opCount + 1);
            // 乘法
            dfs(current * remaining[i], newRemaining, opCount + 1);
            // 除法
            if (remaining[i] != 0 && current % remaining[i] == 0) {
                dfs(current / remaining[i], newRemaining, opCount + 1);
            }
        }
        };

    for (int i = 0; i < n; ++i) {
        vector<int> newRemaining = nums;
        newRemaining.erase(newRemaining.begin() + i);
        dfs(nums[i], newRemaining, 0);
    }

    return minOps == INT_MAX ? -1 : minOps;
}

int main() {
    int n, target;
    cout << "请输入整数个数n和目标值m: ";
    cin >> n >> target;

    vector<int> nums(n);
    cout << "请输入" << n << "个整数: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = minOperations(nums, target);
    if (result != -1) {
        cout << "最少运算方案次数: " << result << endl;
    }
    else {
        cout << "没有解。" << endl;
    }

    return 0;
}
