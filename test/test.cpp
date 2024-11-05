//#include <iostream>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <iomanip>
//
//using namespace std;
//
//// 判断是否为质数
//bool is_prime(int n) {
//    if (n <= 1) return false;
//    for (int i = 2; i <= sqrt(n); i++) {
//        if (n % i == 0) return false;
//    }
//    return true;
//}
//
//// 求最大公约数
//int gcd(int a, int b) {
//    if (b == 0) return a;
//    return gcd(b, a % b);
//}
//
//// 求模逆
//int mod_inverse(int a, int m) {
//    a = a % m;
//    for (int x = 1; x < m; x++) {
//        if ((a * x) % m == 1) {
//            return x;
//        }
//    }
//    return -1;
//}
//
//// 计算 (base^exp) % mod
//int modular_exponentiation(int base, int exp, int mod) {
//    int result = 1;
//    while (exp > 0) {
//        if (exp % 2 == 1) {
//            result = (result * base) % mod;
//        }
//        base = (base * base) % mod;
//        exp /= 2;
//    }
//    return result;
//}
//
//// 加密函数
//void encrypt(const string& input, int e, int n, string& output) {
//    output.clear();
//    for (char ch : input) {
//        int m = static_cast<int>(ch); // 转换为ASCII
//        int c = modular_exponentiation(m, e, n);
//        stringstream ss;
//        ss << hex << c; // 转换为十六进制
//        output += ss.str() + " "; // 添加到输出
//    }
//}
//
//// 解密函数
//void decrypt(const string& input, int d, int n, string& output) {
//    output.clear();
//    stringstream ss(input);
//    string token;
//    while (ss >> token) {
//        int c = strtol(token.c_str(), nullptr, 16); // 从十六进制转换为整数
//        int m = modular_exponentiation(c, d, n);
//        output += static_cast<char>(m); // 转换回字符
//    }
//}
//
//int main() {
//    int p, q;
//    cout << "请输入两个质数 p 和 q:\n";
//    cin >> p >> q;
//
//    if (!is_prime(p) || !is_prime(q)) {
//        cout << "输入的 p 和 q 不是质数，请重新输入！\n";
//        return 1;
//    }
//
//    int n = p * q;
//    int phi_n = (p - 1) * (q - 1);
//
//    int e = 3; // 通常选择为3
//    while (gcd(e, phi_n) != 1) {
//        e++;
//    }
//
//    int d = mod_inverse(e, phi_n);
//    if (d == -1) {
//        cout << "无法计算私钥，请重新输入！\n";
//        return 1;
//    }
//
//    cout << "公钥 (e, n) = (" << e << ", " << n << ")\n";
//    cout << "私钥 (d, n) = (" << d << ", " << n << ")\n";
//
//    string input;
//    cout << "请输入要加密的字符串:\n";
//    cin >> input;
//
//    string encrypted;
//    encrypt(input, e, n, encrypted);
//    cout << "加密后的十六进制字符串: " << encrypted << endl;
//
//    string decrypted;
//    decrypt(encrypted, d, n, decrypted);
//    cout << "解密后的字符串: " << decrypted << endl;
//
//    cout << "设计者: 计昱帆，学号：2300110508\n"; 
//    return 0;
//}


//Stack.h#pragma once#include<stdio.h>#include<stdlib.h>#include<assert.h>#include<stdbool.h>

//typedef int STDataType; typedef struct Stack {
//	STDataType* arr;        //栈数组
//	int capacity;           //栈的空间大小
//	int top;                //栈顶位置}ST;
//
//	//栈的初始化void STInit(ST* ps);
//	//栈的销毁void StackDestroy(ST* ps);
//	//数据入栈void StackPush(ST* ps, STDataType x); //STDataType x 是我们需要插入的数据
//	//数据出栈void StackPop(ST* ps);
//	//取栈顶元素
//	STDataType StackTop(ST* ps);
//	//获取栈中有效元素个数int STSize(ST* ps);
//	//Stack.c#include"Stack.h"
//	//栈的初始化void STInit(ST* ps){
//	assert(ps);
//	ps->arr = NULL;
//	ps->capacity = 0;
//	ps->top = 0;
//}
////栈的销毁void STDestroy(ST* ps){
//assert(ps);
//if (ps->arr)
//free(ps->arr);
//ps->arr = NULL;
//ps->capacity = 0;
//ps->top = 0; }
////数据入栈void StackPush(ST* ps, STDataType x){
//assert(ps);
//if (ps->capacity == ps->top)           //空间满了需要扩容
//{
//	int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;  //三目运算符如果原本栈为空，就赋初始为4个空间，若不为空，则双倍扩容
//	STDataType* tem = (STDataType*)realloc(ps->arr, newcapacity * sizeof(ST));
//	//判断所开空间是否成功
//	if (tem == NULL)
//	{
//		perror("realloc fail!");
//		exit(1);
//	}
//
//	ps->arr = tem;
//	ps->capacity = newcapacity;
//}
//
////入栈开始
//ps->arr[ps->top++] = x; }
////栈判空bool StackEmpty(ST* ps){
//assert(ps);
//return ps->top == 0; }
////数据出栈void StackPop(ST* ps){
//assert(ps);
//assert(!StackEmpty(ps));
//ps->top--; }
////取栈顶元素
//STDataType StackTop(ST* ps) {
//	assert(ps);
//	assert(!StackEmpty(ps));
//	return ps->arr[ps->top - 1];
//}
////获取栈中有效元素个数int STSize(ST* ps){
//assert(ps);
//return ps->top; }
////测试样例#include"Stack.h"
//void STTest() {
//	ST st;
//	STInit(&st);
//	//////////////////////////
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//	printf("size: %d\n", STSize(&st));//4
//	//StackPush(&st, 5);
//
//	//StackPop(&st);
//
//	//循环出栈，直到栈为空
//	while (!StackEmpty(&st))
//	{
//		STDataType data = StackTop(&st);
//		printf("%d ", data);
//		//出栈
//		StackPop(&st);
//	}
//	printf("size: %d\n", STSize(&st));//0
//
//
//	///////////////////////
//	STDestroy(&st);
//}
//int main() {
//	STTest();
//	return 0;
//}


//2、用栈实现数制转换.
//#include "Stack.h"
//#include <stdio.h>
//
//void DecimalToBase(ST * ps, int number, int base) {
//    // 初始化栈
//    STInit(ps);
//
//    // 将数字逐位入栈
//    while (number > 0) {
//        int remainder = number % base;
//        StackPush(ps, remainder);
//        number /= base;
//    }
//
//    // 将栈中的数据逐个出栈，得到转换后的数
//    printf("转换结果为：");
//    while (!StackEmpty(ps)) {
//        int digit = StackTop(ps);
//        StackPop(ps);
//        // 如果基数是十六进制，需要将10以上的数转换成A-F字符
//        if (digit >= 10) {
//            printf("%c", 'A' + digit - 10);
//        }
//        else {
//            printf("%d", digit);
//        }
//    }
//    printf("\n");
//
//    // 销毁栈
//    STDestroy(ps);
//}
//
//int main() {
//    int number, base;
//    ST stack;
//
//    printf("请输入要转换的十进制数：");
//    scanf("%d", &number);
//    printf("请输入目标进制（2到16）：");
//    scanf("%d", &base);
//
//    if (base < 2 || base > 16) {
//        printf("请输入有效的进制（2到16）！\n");
//        return 1;
//    }
//
//    DecimalToBase(&stack, number, base);
//    return 0;
//}
//
//
//
//3、用栈实现中缀表达式转后缀表达式
//#include "Stack.h"
//#include <stdio.h>
//#include <ctype.h> // for isdigit()
//
//// 定义操作符优先级
//int precedence(char op) {
//    if (op == '+' || op == '-') {
//        return 1;
//    }
//    else if (op == '*' || op == '/') {
//        return 2;
//    }
//    return 0;
//}
//
//// 判断是否为操作符
//int isOperator(char ch) {
//    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
//}
//
//// 中缀转后缀函数
//void infixToPostfix(const char* infix, char* postfix) {
//    ST stack;
//    STInit(&stack);  // 初始化栈
//    int j = 0;       // 用于存放后缀表达式的索引
//
//    for (int i = 0; infix[i] != '\0'; i++) {
//        char ch = infix[i];
//
//        // 如果是操作数，直接加入后缀表达式
//        if (isdigit(ch)) {
//            postfix[j++] = ch;
//        }
//        // 遇到左括号，入栈
//        else if (ch == '(') {
//            StackPush(&stack, ch);
//        }
//        // 遇到右括号，弹出栈顶直到左括号
//        else if (ch == ')') {
//            while (!StackEmpty(&stack) && StackTop(&stack) != '(') {
//                postfix[j++] = StackTop(&stack);
//                StackPop(&stack);
//            }
//            StackPop(&stack); // 弹出左括号
//        }
//        // 遇到操作符
//        else if (isOperator(ch)) {
//            while (!StackEmpty(&stack) && precedence(StackTop(&stack)) >= precedence(ch)) {
//                postfix[j++] = StackTop(&stack);
//                StackPop(&stack);
//            }
//            StackPush(&stack, ch); // 当前操作符入栈
//        }
//    }
//
//    // 将栈中剩余的操作符加入后缀表达式
//    while (!StackEmpty(&stack)) {
//        postfix[j++] = StackTop(&stack);
//        StackPop(&stack);
//    }
//
//    postfix[j] = '\0'; // 结束符
//    STDestroy(&stack); // 销毁栈
//}
//
//int main() {
//    char infix[100];
//    char postfix[100];
//
//    printf("请输入中缀表达式：");
//    scanf("%s", infix);
//
//    infixToPostfix(infix, postfix);
//    printf("后缀表达式为：%s\n", postfix);
//
//    return 0;
//}
//
//4、用栈实现表达式求值
//#include "Stack.h"
//#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>
//
//// 执行单次运算
//int evaluateOperation(int operand1, int operand2, char operator) {
//    switch (operator) {
//    case '+': return operand1 + operand2;
//    case '-': return operand1 - operand2;
//    case '*': return operand1 * operand2;
//    case '/':
//        if (operand2 == 0) {
//            printf("错误：除数不能为0！\n");
//            exit(EXIT_FAILURE);
//        }
//        return operand1 / operand2;
//    default:
//        printf("无效的操作符：%c\n", operator);
//        exit(EXIT_FAILURE);
//    }
//}
//
//// 后缀表达式求值
//int evaluatePostfix(const char* postfix) {
//    ST stack;
//    STInit(&stack);
//
//    for (int i = 0; postfix[i] != '\0'; i++) {
//        char ch = postfix[i];
//
//        // 如果是操作数，将其转换为整数并入栈
//        if (isdigit(ch)) {
//            StackPush(&stack, ch - '0'); // '0'的ASCII码作为基准
//        }
//        // 如果是操作符，弹出两个操作数并执行运算
//        else {
//            int operand2 = StackTop(&stack);
//            StackPop(&stack);
//            int operand1 = StackTop(&stack);
//            StackPop(&stack);
//
//            int result = evaluateOperation(operand1, operand2, ch);
//            StackPush(&stack, result); // 将运算结果入栈
//        }
//    }
//
//    // 获取最终结果
//    int finalResult = StackTop(&stack);
//    StackPop(&stack);
//
//    STDestroy(&stack);
//    return finalResult;
//}
//
//int main() {
//    char postfix[100];
//
//    printf("请输入后缀表达式：");
//    scanf("%s", postfix);
//
//    int result = evaluatePostfix(postfix);
//    printf("表达式的计算结果为：%d\n", result);
//
//    return 0;
//}
//
//5、完成24点求值或计算器
//#include <stdio.h>
//#include <stdbool.h>
//#include <math.h>
//
//#define TARGET 24
//#define EPSILON 1e-6
//
//// 判断两个浮点数是否相等
//bool isEqual(double a, double b) {
//    return fabs(a - b) < EPSILON;
//}
//
//// 递归地计算能否得到24点
//bool canReach24(double nums[], int n) {
//    if (n == 1) {
//        return isEqual(nums[0], TARGET);
//    }
//
//    double temp[4];
//    // 遍历所有数字组合并进行运算
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            int t = 0;
//            // 将不参与本轮运算的数字放入新数组
//            for (int k = 0; k < n; k++) {
//                if (k != i && k != j) {
//                    temp[t++] = nums[k];
//                }
//            }
//
//            // 尝试不同的运算
//            double a = nums[i], b = nums[j];
//
//            // 加法
//            temp[t] = a + b;
//            if (canReach24(temp, t + 1)) return true;
//
//            // 减法 (a - b)
//            temp[t] = a - b;
//            if (canReach24(temp, t + 1)) return true;
//
//            // 减法 (b - a)
//            temp[t] = b - a;
//            if (canReach24(temp, t + 1)) return true;
//
//            // 乘法
//            temp[t] = a * b;
//            if (canReach24(temp, t + 1)) return true;
//
//            // 除法 (a / b)
//            if (!isEqual(b, 0)) {
//                temp[t] = a / b;
//                if (canReach24(temp, t + 1)) return true;
//            }
//
//            // 除法 (b / a)
//            if (!isEqual(a, 0)) {
//                temp[t] = b / a;
//                if (canReach24(temp, t + 1)) return true;
//            }
//        }
//    }
//    return false;
//}
//
//int main() {
//    double nums[4];
//    printf("请输入四个数字：");
//    for (int i = 0; i < 4; i++) {
//        scanf("%lf", &nums[i]);
//    }
//
//    if (canReach24(nums, 4)) {
//        printf("可以通过运算得到24点。\n");
//    }
//    else {
//        printf("无法通过运算得到24点。\n");
//    }
//
//    return 0;
//}