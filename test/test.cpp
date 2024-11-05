//#include <iostream>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <iomanip>
//
//using namespace std;
//
//// �ж��Ƿ�Ϊ����
//bool is_prime(int n) {
//    if (n <= 1) return false;
//    for (int i = 2; i <= sqrt(n); i++) {
//        if (n % i == 0) return false;
//    }
//    return true;
//}
//
//// �����Լ��
//int gcd(int a, int b) {
//    if (b == 0) return a;
//    return gcd(b, a % b);
//}
//
//// ��ģ��
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
//// ���� (base^exp) % mod
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
//// ���ܺ���
//void encrypt(const string& input, int e, int n, string& output) {
//    output.clear();
//    for (char ch : input) {
//        int m = static_cast<int>(ch); // ת��ΪASCII
//        int c = modular_exponentiation(m, e, n);
//        stringstream ss;
//        ss << hex << c; // ת��Ϊʮ������
//        output += ss.str() + " "; // ��ӵ����
//    }
//}
//
//// ���ܺ���
//void decrypt(const string& input, int d, int n, string& output) {
//    output.clear();
//    stringstream ss(input);
//    string token;
//    while (ss >> token) {
//        int c = strtol(token.c_str(), nullptr, 16); // ��ʮ������ת��Ϊ����
//        int m = modular_exponentiation(c, d, n);
//        output += static_cast<char>(m); // ת�����ַ�
//    }
//}
//
//int main() {
//    int p, q;
//    cout << "�������������� p �� q:\n";
//    cin >> p >> q;
//
//    if (!is_prime(p) || !is_prime(q)) {
//        cout << "����� p �� q �������������������룡\n";
//        return 1;
//    }
//
//    int n = p * q;
//    int phi_n = (p - 1) * (q - 1);
//
//    int e = 3; // ͨ��ѡ��Ϊ3
//    while (gcd(e, phi_n) != 1) {
//        e++;
//    }
//
//    int d = mod_inverse(e, phi_n);
//    if (d == -1) {
//        cout << "�޷�����˽Կ�����������룡\n";
//        return 1;
//    }
//
//    cout << "��Կ (e, n) = (" << e << ", " << n << ")\n";
//    cout << "˽Կ (d, n) = (" << d << ", " << n << ")\n";
//
//    string input;
//    cout << "������Ҫ���ܵ��ַ���:\n";
//    cin >> input;
//
//    string encrypted;
//    encrypt(input, e, n, encrypted);
//    cout << "���ܺ��ʮ�������ַ���: " << encrypted << endl;
//
//    string decrypted;
//    decrypt(encrypted, d, n, decrypted);
//    cout << "���ܺ���ַ���: " << decrypted << endl;
//
//    cout << "�����: ���ŷ���ѧ�ţ�2300110508\n"; 
//    return 0;
//}


//Stack.h#pragma once#include<stdio.h>#include<stdlib.h>#include<assert.h>#include<stdbool.h>

//typedef int STDataType; typedef struct Stack {
//	STDataType* arr;        //ջ����
//	int capacity;           //ջ�Ŀռ��С
//	int top;                //ջ��λ��}ST;
//
//	//ջ�ĳ�ʼ��void STInit(ST* ps);
//	//ջ������void StackDestroy(ST* ps);
//	//������ջvoid StackPush(ST* ps, STDataType x); //STDataType x ��������Ҫ���������
//	//���ݳ�ջvoid StackPop(ST* ps);
//	//ȡջ��Ԫ��
//	STDataType StackTop(ST* ps);
//	//��ȡջ����ЧԪ�ظ���int STSize(ST* ps);
//	//Stack.c#include"Stack.h"
//	//ջ�ĳ�ʼ��void STInit(ST* ps){
//	assert(ps);
//	ps->arr = NULL;
//	ps->capacity = 0;
//	ps->top = 0;
//}
////ջ������void STDestroy(ST* ps){
//assert(ps);
//if (ps->arr)
//free(ps->arr);
//ps->arr = NULL;
//ps->capacity = 0;
//ps->top = 0; }
////������ջvoid StackPush(ST* ps, STDataType x){
//assert(ps);
//if (ps->capacity == ps->top)           //�ռ�������Ҫ����
//{
//	int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;  //��Ŀ��������ԭ��ջΪ�գ��͸���ʼΪ4���ռ䣬����Ϊ�գ���˫������
//	STDataType* tem = (STDataType*)realloc(ps->arr, newcapacity * sizeof(ST));
//	//�ж������ռ��Ƿ�ɹ�
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
////��ջ��ʼ
//ps->arr[ps->top++] = x; }
////ջ�п�bool StackEmpty(ST* ps){
//assert(ps);
//return ps->top == 0; }
////���ݳ�ջvoid StackPop(ST* ps){
//assert(ps);
//assert(!StackEmpty(ps));
//ps->top--; }
////ȡջ��Ԫ��
//STDataType StackTop(ST* ps) {
//	assert(ps);
//	assert(!StackEmpty(ps));
//	return ps->arr[ps->top - 1];
//}
////��ȡջ����ЧԪ�ظ���int STSize(ST* ps){
//assert(ps);
//return ps->top; }
////��������#include"Stack.h"
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
//	//ѭ����ջ��ֱ��ջΪ��
//	while (!StackEmpty(&st))
//	{
//		STDataType data = StackTop(&st);
//		printf("%d ", data);
//		//��ջ
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


//2����ջʵ������ת��.
//#include "Stack.h"
//#include <stdio.h>
//
//void DecimalToBase(ST * ps, int number, int base) {
//    // ��ʼ��ջ
//    STInit(ps);
//
//    // ��������λ��ջ
//    while (number > 0) {
//        int remainder = number % base;
//        StackPush(ps, remainder);
//        number /= base;
//    }
//
//    // ��ջ�е����������ջ���õ�ת�������
//    printf("ת�����Ϊ��");
//    while (!StackEmpty(ps)) {
//        int digit = StackTop(ps);
//        StackPop(ps);
//        // ���������ʮ�����ƣ���Ҫ��10���ϵ���ת����A-F�ַ�
//        if (digit >= 10) {
//            printf("%c", 'A' + digit - 10);
//        }
//        else {
//            printf("%d", digit);
//        }
//    }
//    printf("\n");
//
//    // ����ջ
//    STDestroy(ps);
//}
//
//int main() {
//    int number, base;
//    ST stack;
//
//    printf("������Ҫת����ʮ��������");
//    scanf("%d", &number);
//    printf("������Ŀ����ƣ�2��16����");
//    scanf("%d", &base);
//
//    if (base < 2 || base > 16) {
//        printf("��������Ч�Ľ��ƣ�2��16����\n");
//        return 1;
//    }
//
//    DecimalToBase(&stack, number, base);
//    return 0;
//}
//
//
//
//3����ջʵ����׺���ʽת��׺���ʽ
//#include "Stack.h"
//#include <stdio.h>
//#include <ctype.h> // for isdigit()
//
//// ������������ȼ�
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
//// �ж��Ƿ�Ϊ������
//int isOperator(char ch) {
//    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
//}
//
//// ��׺ת��׺����
//void infixToPostfix(const char* infix, char* postfix) {
//    ST stack;
//    STInit(&stack);  // ��ʼ��ջ
//    int j = 0;       // ���ڴ�ź�׺���ʽ������
//
//    for (int i = 0; infix[i] != '\0'; i++) {
//        char ch = infix[i];
//
//        // ����ǲ�������ֱ�Ӽ����׺���ʽ
//        if (isdigit(ch)) {
//            postfix[j++] = ch;
//        }
//        // ���������ţ���ջ
//        else if (ch == '(') {
//            StackPush(&stack, ch);
//        }
//        // ���������ţ�����ջ��ֱ��������
//        else if (ch == ')') {
//            while (!StackEmpty(&stack) && StackTop(&stack) != '(') {
//                postfix[j++] = StackTop(&stack);
//                StackPop(&stack);
//            }
//            StackPop(&stack); // ����������
//        }
//        // ����������
//        else if (isOperator(ch)) {
//            while (!StackEmpty(&stack) && precedence(StackTop(&stack)) >= precedence(ch)) {
//                postfix[j++] = StackTop(&stack);
//                StackPop(&stack);
//            }
//            StackPush(&stack, ch); // ��ǰ��������ջ
//        }
//    }
//
//    // ��ջ��ʣ��Ĳ����������׺���ʽ
//    while (!StackEmpty(&stack)) {
//        postfix[j++] = StackTop(&stack);
//        StackPop(&stack);
//    }
//
//    postfix[j] = '\0'; // ������
//    STDestroy(&stack); // ����ջ
//}
//
//int main() {
//    char infix[100];
//    char postfix[100];
//
//    printf("��������׺���ʽ��");
//    scanf("%s", infix);
//
//    infixToPostfix(infix, postfix);
//    printf("��׺���ʽΪ��%s\n", postfix);
//
//    return 0;
//}
//
//4����ջʵ�ֱ��ʽ��ֵ
//#include "Stack.h"
//#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>
//
//// ִ�е�������
//int evaluateOperation(int operand1, int operand2, char operator) {
//    switch (operator) {
//    case '+': return operand1 + operand2;
//    case '-': return operand1 - operand2;
//    case '*': return operand1 * operand2;
//    case '/':
//        if (operand2 == 0) {
//            printf("���󣺳�������Ϊ0��\n");
//            exit(EXIT_FAILURE);
//        }
//        return operand1 / operand2;
//    default:
//        printf("��Ч�Ĳ�������%c\n", operator);
//        exit(EXIT_FAILURE);
//    }
//}
//
//// ��׺���ʽ��ֵ
//int evaluatePostfix(const char* postfix) {
//    ST stack;
//    STInit(&stack);
//
//    for (int i = 0; postfix[i] != '\0'; i++) {
//        char ch = postfix[i];
//
//        // ����ǲ�����������ת��Ϊ��������ջ
//        if (isdigit(ch)) {
//            StackPush(&stack, ch - '0'); // '0'��ASCII����Ϊ��׼
//        }
//        // ����ǲ�����������������������ִ������
//        else {
//            int operand2 = StackTop(&stack);
//            StackPop(&stack);
//            int operand1 = StackTop(&stack);
//            StackPop(&stack);
//
//            int result = evaluateOperation(operand1, operand2, ch);
//            StackPush(&stack, result); // ����������ջ
//        }
//    }
//
//    // ��ȡ���ս��
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
//    printf("�������׺���ʽ��");
//    scanf("%s", postfix);
//
//    int result = evaluatePostfix(postfix);
//    printf("���ʽ�ļ�����Ϊ��%d\n", result);
//
//    return 0;
//}
//
//5�����24����ֵ�������
//#include <stdio.h>
//#include <stdbool.h>
//#include <math.h>
//
//#define TARGET 24
//#define EPSILON 1e-6
//
//// �ж������������Ƿ����
//bool isEqual(double a, double b) {
//    return fabs(a - b) < EPSILON;
//}
//
//// �ݹ�ؼ����ܷ�õ�24��
//bool canReach24(double nums[], int n) {
//    if (n == 1) {
//        return isEqual(nums[0], TARGET);
//    }
//
//    double temp[4];
//    // ��������������ϲ���������
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            int t = 0;
//            // �������뱾����������ַ���������
//            for (int k = 0; k < n; k++) {
//                if (k != i && k != j) {
//                    temp[t++] = nums[k];
//                }
//            }
//
//            // ���Բ�ͬ������
//            double a = nums[i], b = nums[j];
//
//            // �ӷ�
//            temp[t] = a + b;
//            if (canReach24(temp, t + 1)) return true;
//
//            // ���� (a - b)
//            temp[t] = a - b;
//            if (canReach24(temp, t + 1)) return true;
//
//            // ���� (b - a)
//            temp[t] = b - a;
//            if (canReach24(temp, t + 1)) return true;
//
//            // �˷�
//            temp[t] = a * b;
//            if (canReach24(temp, t + 1)) return true;
//
//            // ���� (a / b)
//            if (!isEqual(b, 0)) {
//                temp[t] = a / b;
//                if (canReach24(temp, t + 1)) return true;
//            }
//
//            // ���� (b / a)
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
//    printf("�������ĸ����֣�");
//    for (int i = 0; i < 4; i++) {
//        scanf("%lf", &nums[i]);
//    }
//
//    if (canReach24(nums, 4)) {
//        printf("����ͨ������õ�24�㡣\n");
//    }
//    else {
//        printf("�޷�ͨ������õ�24�㡣\n");
//    }
//
//    return 0;
//}