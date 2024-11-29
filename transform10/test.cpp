//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//// ��ʮ������ת��Ϊ�������
//string decimalToBase(int decimalNumber, int base) {
//    if (base < 2 || base > 36) {
//        throw invalid_argument("Base must be between 2 and 36.");
//    }
//
//    string result;
//    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//
//    int number = abs(decimalNumber); // ������
//    while (number > 0) {
//        result += digits[number % base];
//        number /= base;
//    }
//
//    if (decimalNumber < 0) result += '-'; // ��Ӹ���
//
//    reverse(result.begin(), result.end());
//    return result.empty() ? "0" : result;
//}
//
//// �����������ת��Ϊʮ����
//int baseToDecimal(const string& number, int base) {
//    if (base < 2 || base > 36) {
//        throw invalid_argument("Base must be between 2 and 36.");
//    }
//
//    int result = 0;
//    int sign = 1;
//    size_t startIndex = 0;
//
//    // ������
//    if (!number.empty() && number[0] == '-') {
//        sign = -1;
//        startIndex = 1;
//    }
//
//    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    for (size_t i = startIndex; i < number.size(); ++i) {
//        char c = toupper(number[i]);
//        int value = digits.find(c);
//        if (value == string::npos || value >= base) {
//            throw invalid_argument("Invalid character in the number for the given base.");
//        }
//        result = result * base + value;
//    }
//
//    return result * sign;
//}
//
//int main() {
//    try {
//        int decimalNumber = 255;
//        int base = 16;
//
//        // ʮ����ת�������
//        string converted = decimalToBase(decimalNumber, base);
//        cout << decimalNumber << " in base " << base << " is: " << converted << endl;
//
//        // �������תʮ����
//        string numberInBase = "FF";
//        int original = baseToDecimal(numberInBase, base);
//        cout << numberInBase << " in base " << base << " is: " << original << " in decimal." << endl;
//
//    }
//    catch (const exception& e) {
//        cerr << "Error: " << e.what() << endl;
//    }
//
//    return 0;
//}



#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>



// ���ַ�ת��Ϊ��Ӧ����ֵ��֧��0-9��A-Z��
int charToValue(char c) {
    if (std::isdigit(c)) return c - '0';
    if (std::isalpha(c)) return std::toupper(c) - 'A' + 10;
    throw std::invalid_argument("���������Ч�ַ���");
}

// ����ֵת��Ϊ��Ӧ���ַ���֧��0-9��A-Z��
char valueToChar(int value) {
    if (value >= 0 && value <= 9) return '0' + value;
    if (value >= 10 && value < 36) return 'A' + value - 10;
    throw std::invalid_argument("��ֵ����֧�ַ�Χ��");
}

// �������ת��Ϊʮ����
long long toDecimal(const std::string& input, int base) {
    if (base < 2 || base > 36) throw std::invalid_argument("����Ľ��Ƴ�����Χ��2-36����");
    long long result = 0;
    for (char c : input) {
        int value = charToValue(c);
        if (value >= base) throw std::invalid_argument("���ֳ���������Ƶ���Ч��Χ��");
        result = result * base + value;
    }
    return result;
}

// ʮ����ת��Ϊ�������
std::string fromDecimal(long long number, int base) {
    if (base < 2 || base > 36) throw std::invalid_argument("Ŀ����Ƴ�����Χ��2-36����");
    if (number == 0) return "0";
    std::string result;
    bool isNegative = number < 0;
    number = std::abs(number);
    while (number > 0) {
        result.push_back(valueToChar(number % base));
        number /= base;
    }
    if (isNegative) result.push_back('-');
    std::reverse(result.begin(), result.end());
    return result;
}

// �������֮���ת��
std::string convertBase(const std::string& input, int fromBase, int toBase) {
    long long decimalValue = toDecimal(input, fromBase);
    return fromDecimal(decimalValue, toBase);
}

int main() {
    try {
        std::string number;
        int fromBase, toBase;

        std::cout << "========== �������ת������ ==========\n";
        std::cout << "֧�ֵĽ��Ʒ�Χ��2 �� 36\n\n";

        // ��������
        std::cout << "�������ת�������֣����磺1011��1A3F �ȣ���";
        std::cin >> number;

        // ����ԭ����
        std::cout << "����������ֵ�ԭ���ƣ�2-36����";
        std::cin >> fromBase;

        // ����Ŀ�����
        std::cout << "������Ŀ����ƣ�2-36����";
        std::cin >> toBase;

        // ִ��ת��
        std::string result = convertBase(number, fromBase, toBase);
        std::cout << "\n========== ת����� ==========\n";
        std::cout << "ԭ���֣�" << number << "��" << fromBase << "���ƣ�\n";
        std::cout << "ת����" << result << "��" << toBase << "���ƣ�\n";
        std::cout << "=================================\n";

    }
    catch (const std::exception& e) {
        std::cerr << "\n����" << e.what() << "\n";
        std::cerr << "���������Ƿ����Ҫ���������г���\n";
    }

    return 0;
}
