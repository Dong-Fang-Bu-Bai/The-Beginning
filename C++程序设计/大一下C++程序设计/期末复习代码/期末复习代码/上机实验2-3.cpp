////自定义数组型大整数
//
//#include <iostream>
//#include <vector>
//#include <string>
////#include <algorithm>
//using namespace std;
//
//
//class HugeInt 
//{
//private:
//    std::vector<int> digits;
//    bool isNegative;
//
//    // 去除前导零
//    void removeLeadingZeros() 
//    {
//        while (digits.size() > 1 && digits.back() == 0) 
//        {
//            digits.pop_back();
//        }
//    }
//
//public:
//
//    // 构造函数
//
//    HugeInt(const std::string& num = "0") 
//    {
//        if (num[0] == '-') {
//            isNegative = true;
//            for (int i = num.size() - 1; i > 0; --i) 
//            {
//                digits.push_back(num[i] - '0');
//            }
//        }
//        else 
//        {
//            isNegative = false;
//            for (int i = num.size() - 1; i >= 0; --i) 
//            {
//                digits.push_back(num[i] - '0');
//            }
//        }
//        removeLeadingZeros();
//    }
//
//    // 重载 * 运算符
//    HugeInt operator*(const HugeInt& other) const
//    {
//        HugeInt result;
//        result.digits.resize(digits.size() + other.digits.size());
//        result.isNegative = isNegative ^ other.isNegative;
//
//        for (size_t i = 0; i < digits.size(); ++i) 
//        {
//            int carry = 0;
//
//            for (size_t j = 0; j < other.digits.size() || carry; ++j) 
//            {
//                long long cur = result.digits[i + j] +
//                    digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + carry;
//                result.digits[i + j] = cur % 10;
//                carry = cur / 10;
//            }
//        }
//
//        result.removeLeadingZeros();
//
//        if (result.digits.size() == 1 && result.digits[0] == 0)
//        {
//            result.isNegative = false;
//        }
//
//        return result;
//    }
//
//    // 输出运算符重载
//
//    friend std::ostream& operator<<(std::ostream& os, const HugeInt& num) 
//    {
//        if (num.isNegative && !(num.digits.size() == 1 && num.digits[0] == 0)) 
//        {
//            os << '-';
//        }
//        for (int i = num.digits.size() - 1; i >= 0; --i) 
//        {
//            os << num.digits[i];
//        }
//        return os;
//    }
//
//    // 比较绝对值大小
//    bool absGreater(const HugeInt& a, const HugeInt& b) const
//    {
//        if (a.digits.size() != b.digits.size()) {
//            return a.digits.size() > b.digits.size();
//        }
//        for (int i = a.digits.size() - 1; i >= 0; --i) {
//            if (a.digits[i] != b.digits[i]) {
//                return a.digits[i] > b.digits[i];
//            }
//        }
//        return false;
//    }
//
//    // 减法辅助函数
//    HugeInt absSubtract(const HugeInt& a, const HugeInt& b) const 
//    {
//        HugeInt result;
//        result.digits.resize(std::max(a.digits.size(), b.digits.size()));
//        int borrow = 0;
//        for (size_t i = 0; i < result.digits.size(); ++i) {
//            int cur = (i < a.digits.size() ? a.digits[i] : 0) -
//                (i < b.digits.size() ? b.digits[i] : 0) - borrow;
//            if (cur < 0) {
//                cur += 10;
//                borrow = 1;
//            }
//            else {
//                borrow = 0;
//            }
//            result.digits[i] = cur;
//        }
//        result.removeLeadingZeros();
//        return result;
//    }
//
//    // 重载 / 运算符
//    HugeInt operator/(const HugeInt& other) const 
//    {
//        if (other.digits.size() == 1 && other.digits[0] == 0) 
//        {
//            throw std::runtime_error("Division by zero");
//        }
//
//        HugeInt dividend = *this;
//        dividend.isNegative = false;
//        HugeInt divisor = other;
//        divisor.isNegative = false;
//        HugeInt quotient;
//        quotient.digits.resize(dividend.digits.size());
//        HugeInt temp;
//        for (int i = dividend.digits.size() - 1; i >= 0; --i)
//        {
//            temp.digits.insert(temp.digits.begin(), dividend.digits[i]);
//            temp.removeLeadingZeros();
//            int count = 0;
//            while (absGreater(temp, divisor) || temp.digits == divisor.digits)
//            {
//                temp = absSubtract(temp, divisor);
//                ++count;
//            }
//            quotient.digits[i] = count;
//        }
//        quotient.removeLeadingZeros();
//        quotient.isNegative = isNegative ^ other.isNegative;
//        if (quotient.digits.size() == 1 && quotient.digits[0] == 0) 
//        {
//            quotient.isNegative = false;
//        }
//        return quotient;
//    }
//
//
//    // 重载 == 运算符
//    bool operator==(const HugeInt& other) const 
//    {
//        if (isNegative != other.isNegative) 
//        {
//            return false;
//        }
//        return digits == other.digits;
//    }
//
//    // 重载 != 运算符
//    bool operator!=(const HugeInt& other) const 
//    {
//        return !(*this == other);
//    }
//
//    // 重载 < 运算符
//    bool operator<(const HugeInt& other) const 
//    {
//        if (isNegative != other.isNegative)
//        {
//            return isNegative;
//        }
//        if (digits.size() != other.digits.size()) 
//        {
//            return (isNegative ? digits.size() > other.digits.size() : digits.size() < other.digits.size());
//        }
//        for (int i = digits.size() - 1; i >= 0; --i) 
//        {
//            if (digits[i] != other.digits[i]) 
//            {
//                return (isNegative ? digits[i] > other.digits[i] : digits[i] < other.digits[i]);
//            }
//        }
//        return false;
//    }
//
//    // 重载 > 运算符
//    bool operator>(const HugeInt& other) const 
//    {
//        return other < *this;
//    }
//
//    // 重载 <= 运算符
//    bool operator<=(const HugeInt& other) const
//    {
//        return !(*this > other);
//    }
//
//    // 重载 >= 运算符
//    bool operator>=(const HugeInt& other) const 
//    {
//        return !(*this < other);
//    }
//};
//
//int main()
//{
//    HugeInt a("878193738748923789467926598265");
//    HugeInt b("178267438961248961924");
//
//
//
//    cout << a <<"\t" << b << endl;
//
//    cout << a / b <<"\t" << a * b <<"\t" << endl;
//
//    system("pause");
//    return 0;
//}
//
//
//
//
