//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//// 将十进制数转换为任意进制
//string decimalToBase(int decimalNumber, int base) {
//    if (base < 2 || base > 36) {
//        throw invalid_argument("Base must be between 2 and 36.");
//    }
//
//    string result;
//    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//
//    int number = abs(decimalNumber); // 处理负数
//    while (number > 0) {
//        result += digits[number % base];
//        number /= base;
//    }
//
//    if (decimalNumber < 0) result += '-'; // 添加负号
//
//    reverse(result.begin(), result.end());
//    return result.empty() ? "0" : result;
//}
//
//// 将任意进制数转换为十进制
//int baseToDecimal(const string& number, int base) {
//    if (base < 2 || base > 36) {
//        throw invalid_argument("Base must be between 2 and 36.");
//    }
//
//    int result = 0;
//    int sign = 1;
//    size_t startIndex = 0;
//
//    // 处理负号
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
//        // 十进制转任意进制
//        string converted = decimalToBase(decimalNumber, base);
//        cout << decimalNumber << " in base " << base << " is: " << converted << endl;
//
//        // 任意进制转十进制
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



// 将字符转换为对应的数值（支持0-9和A-Z）
int charToValue(char c) {
    if (std::isdigit(c)) return c - '0';
    if (std::isalpha(c)) return std::toupper(c) - 'A' + 10;
    throw std::invalid_argument("输入包含无效字符！");
}

// 将数值转换为对应的字符（支持0-9和A-Z）
char valueToChar(int value) {
    if (value >= 0 && value <= 9) return '0' + value;
    if (value >= 10 && value < 36) return 'A' + value - 10;
    throw std::invalid_argument("数值超出支持范围！");
}

// 任意进制转换为十进制
long long toDecimal(const std::string& input, int base) {
    if (base < 2 || base > 36) throw std::invalid_argument("输入的进制超出范围（2-36）！");
    long long result = 0;
    for (char c : input) {
        int value = charToValue(c);
        if (value >= base) throw std::invalid_argument("数字超出输入进制的有效范围！");
        result = result * base + value;
    }
    return result;
}

// 十进制转换为任意进制
std::string fromDecimal(long long number, int base) {
    if (base < 2 || base > 36) throw std::invalid_argument("目标进制超出范围（2-36）！");
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

// 任意进制之间的转换
std::string convertBase(const std::string& input, int fromBase, int toBase) {
    long long decimalValue = toDecimal(input, fromBase);
    return fromDecimal(decimalValue, toBase);
}

int main() {
    try {
        std::string number;
        int fromBase, toBase;

        std::cout << "========== 任意进制转换程序 ==========\n";
        std::cout << "支持的进制范围：2 到 36\n\n";

        // 输入数字
        std::cout << "请输入待转换的数字（例如：1011、1A3F 等）：";
        std::cin >> number;

        // 输入原进制
        std::cout << "请输入该数字的原进制（2-36）：";
        std::cin >> fromBase;

        // 输入目标进制
        std::cout << "请输入目标进制（2-36）：";
        std::cin >> toBase;

        // 执行转换
        std::string result = convertBase(number, fromBase, toBase);
        std::cout << "\n========== 转换结果 ==========\n";
        std::cout << "原数字：" << number << "（" << fromBase << "进制）\n";
        std::cout << "转换后：" << result << "（" << toBase << "进制）\n";
        std::cout << "=================================\n";

    }
    catch (const std::exception& e) {
        std::cerr << "\n错误：" << e.what() << "\n";
        std::cerr << "请检查输入是否符合要求，重新运行程序！\n";
    }

    return 0;
}
