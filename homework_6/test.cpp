#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include <numeric> // 引入 iota 所需的头文件


using namespace std;

// 直接插入排序
void directInsertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// 二分插入排序
void binaryInsertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int left = 0, right = i - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key) right = mid - 1;
            else left = mid + 1;
        }
        for (size_t j = i; j > left; --j) arr[j] = arr[j - 1];
        arr[left] = key;
    }
}

// 希尔排序
void shellSort(vector<int>& arr) {
    for (size_t gap = arr.size() / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < arr.size(); ++i) {
            int temp = arr[i];
            size_t j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 选择排序
void selectionSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// 堆排序辅助函数
void heapify(vector<int>& arr, size_t n, size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序
void heapSort(vector<int>& arr) {
    for (int i = arr.size() / 2 - 1; i >= 0; --i) heapify(arr, arr.size(), i);
    for (int i = arr.size() - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 冒泡排序
void bubbleSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// 快速排序辅助函数
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 快速排序
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 测试并计时（添加中文提示）
void testSortAlgorithm(vector<int> arr, void (*sortFunc)(vector<int>&), const string& name) {
    clock_t start = clock();
    sortFunc(arr);
    clock_t end = clock();
    cout << "排序算法：" << name << "，排序耗时："
        << double(end - start) / CLOCKS_PER_SEC << " 秒" << endl;
}

// 生成随机数组
vector<int> generateRandomArray(size_t n, int minVal = 0, int maxVal = 1000000) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minVal, maxVal);
    vector<int> arr(n);
    for (size_t i = 0; i < n; ++i) arr[i] = dis(gen);
    return arr;
}

// 第二关：测试基本有序数组
void testPartiallyOrderedArray() {
    size_t size = 100000; // n = 10^5
    vector<int> arr(size);
    iota(arr.begin(), arr.end(), 0); // 生成正序数组

    // 打乱约 1‰ 的元素
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, size - 1);
    for (size_t i = 0; i < size / 1000; ++i) swap(arr[dis(gen)], arr[dis(gen)]);

    cout << "测试基本有序数组的排序算法性能：" << endl;
    testSortAlgorithm(arr, directInsertionSort, "直接插入排序");
    testSortAlgorithm(arr, binaryInsertionSort, "二分插入排序");
}

// 扩展内容：寻找直接插入排序更优的阈值
void findThresholdForInsertionSort() {
    cout << "寻找直接插入排序优于二分插入排序的阈值：" << endl;
    for (size_t size = 1000; size <= 100000; size += 1000) {
        vector<int> arr = generateRandomArray(size);
        clock_t start1 = clock();
        directInsertionSort(arr);
        clock_t end1 = clock();

        arr = generateRandomArray(size);
        clock_t start2 = clock();
        binaryInsertionSort(arr);
        clock_t end2 = clock();

        if ((end1 - start1) < (end2 - start2)) {
            cout << "直接插入排序优于二分插入排序的阈值为：" << size << " 个数据" << endl;
            break;
        }
    }
}

// 主函数
int main() {
   /* vector<size_t> sizes = { 1000, 50000, 200000 };
    for (size_t size : sizes) {
        cout << "测试数组大小为：" << size << endl;
        vector<int> arr = generateRandomArray(size);
        testSortAlgorithm(arr, directInsertionSort, "直接插入排序");
        testSortAlgorithm(arr, binaryInsertionSort, "二分插入排序");
        testSortAlgorithm(arr, shellSort, "希尔排序");
        testSortAlgorithm(arr, selectionSort, "选择排序");
        testSortAlgorithm(arr, heapSort, "堆排序");
        testSortAlgorithm(arr, bubbleSort, "冒泡排序");
        testSortAlgorithm(arr, [](vector<int>& a) { quickSort(a, 0, a.size() - 1); }, "快速排序");
        cout << endl;
    }*/

    testPartiallyOrderedArray();
    findThresholdForInsertionSort();

    return 0;
}
