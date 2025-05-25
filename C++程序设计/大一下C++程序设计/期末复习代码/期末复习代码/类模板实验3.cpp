//#include <iostream>
////#include <stdexcept>
//using namespace std;
//
//template <typename T>
//class Vector 
//{
//private:
//    T* v;
//    int len;
//public:
//    Vector(int size);
//    ~Vector();
//    Vector(const Vector& other);  // 拷贝构造函数
//    T& operator[](int i) const;
//    Vector& operator=(const Vector&);
//    Vector operator+(const Vector&) const;
//    Vector operator-(const Vector&) const;
//    T operator*(const Vector&) const;
//
//    template <typename U>
//    friend ostream& operator<<(ostream& output, const Vector<U>&);
//
//    template <typename U>
//    friend istream& operator>>(istream& input, Vector<U>&);
//};
//
//// 构造函数
//template <typename T>
//Vector<T>::Vector(int size) 
//{
//    if (size <= 0 || size >= 2147483647) 
//    {
//        cout << "The size of " << size << " is overflow!\n";
//        abort();
//    }
//
//    v = new T[size];
//    len = size;
//
//    // 初始化元素为0
//    for (int i = 0; i < len; ++i) 
//    {
//        v[i] = T();
//    }
//}
//
//// 拷贝构造函数
//template <typename T>
//Vector<T>::Vector(const Vector& other) : len(other.len) 
//{
//    v = new T[len];
//    for (int i = 0; i < len; ++i) 
//    {
//        v[i] = other.v[i];
//    }
//}
//
//// 析构函数
//template <typename T>
//Vector<T>::~Vector() 
//{
//    delete[] v;
//}
//
//// 下标运算符
//template <typename T>
//T& Vector<T>::operator[](int i) const 
//{
//    if (i < 0 || i >= len) 
//    {
//        throw out_of_range("Index out of range");
//    }
//    return v[i];
//}
//
//// 赋值运算符
//template <typename T>
//Vector<T>& Vector<T>::operator=(const Vector& other) {
//    if (this != &other) {
//        delete[] v;
//        len = other.len;
//        v = new T[len];
//        for (int i = 0; i < len; ++i) {
//            v[i] = other.v[i];
//        }
//    }
//    return *this;
//}
//
//// 向量加法
//template <typename T>
//Vector<T> Vector<T>::operator+(const Vector& other) const {
//    if (len != other.len) {
//        throw invalid_argument("Vectors must be of the same length for addition");
//    }
//    Vector<T> result(len);
//    for (int i = 0; i < len; ++i) {
//        result.v[i] = v[i] + other.v[i];
//    }
//    return result;
//}
//
//// 向量减法
//template <typename T>
//Vector<T> Vector<T>::operator-(const Vector& other) const {
//    if (len != other.len) {
//        throw invalid_argument("Vectors must be of the same length for subtraction");
//    }
//    Vector<T> result(len);
//    for (int i = 0; i < len; ++i) {
//        result.v[i] = v[i] - other.v[i];
//    }
//    return result;
//}
//
//// 点积
//template <typename T>
//T Vector<T>::operator*(const Vector& other) const
//{
//    if (len != other.len) 
//    {
//        throw invalid_argument("Vectors must be of the same length for dot product");
//    }
//
//    T result = T();
//
//    for (int i = 0; i < len; ++i) 
//    {
//        result += v[i] * other.v[i];
//    }
//    return result;
//}
//
//// 输出运算符
//template <typename T>
//ostream& operator<<(ostream& output, const Vector<T>& vec) {
//    output << "(";
//    for (int i = 0; i < vec.len; ++i) {
//        output << vec.v[i];
//        if (i != vec.len - 1) {
//            output << ", ";
//        }
//    }
//    output << ")";
//    return output;
//}
//
//// 输入运算符
//template <typename T>
//istream& operator>>(istream& input, Vector<T>& vec) {
//    for (int i = 0; i < vec.len; ++i) {
//        input >> vec.v[i];
//    }
//    return input;
//}
//
//int main() {
//    // 测试int类型的Vector
//    {
//        cout << "Testing Vector<int>:\n";
//        int k1, k2, k3;
//
//        cout << "Input the length of Vector A:\n";
//        cin >> k1;
//        Vector<int> A(k1);
//        cout << "Input the elements of Vector A:\n";
//        cin >> A;
//
//        cout << "Input the length of Vector B:\n";
//        cin >> k2;
//        Vector<int> B(k2);
//        cout << "Input the elements of Vector B:\n";
//        cin >> B;
//
//        cout << "Input the length of Vector C:\n";
//        cin >> k3;
//        Vector<int> C(k3);
//        cout << "Input the elements of Vector C:\n";
//        cin >> C;
//
//        cout << "A=" << A << endl;
//        cout << "B=" << B << endl;
//
//        C = A + B;
//        cout << "A+B=" << A << "+" << B << "=" << C << endl;
//
//        C = A - B;
//        cout << "A-B=" << A << "-" << B << "=" << C << endl;
//
//        int t = A * B;
//        cout << "A*B=" << A << "*" << B << "=" << t << endl;
//    }
//
//    // 测试double类型的Vector
//    {
//        cout << "\nTesting Vector<double>:\n";
//        int k1, k2, k3;
//
//        cout << "Input the length of Vector A:\n";
//        cin >> k1;
//        Vector<double> A(k1);
//        cout << "Input the elements of Vector A:\n";
//        cin >> A;
//
//        cout << "Input the length of Vector B:\n";
//        cin >> k2;
//        Vector<double> B(k2);
//        cout << "Input the elements of Vector B:\n";
//        cin >> B;
//
//        cout << "Input the length of Vector C:\n";
//        cin >> k3;
//        Vector<double> C(k3);
//        cout << "Input the elements of Vector C:\n";
//        cin >> C;
//
//        cout << "A=" << A << endl;
//        cout << "B=" << B << endl;
//
//        C = A + B;
//        cout << "A+B=" << A << "+" << B << "=" << C << endl;
//
//        C = A - B;
//        cout << "A-B=" << A << "-" << B << "=" << C << endl;
//
//        double t = A * B;
//        cout << "A*B=" << A << "*" << B << "=" << t << endl;
//    }
//
//
//    system("pause");
//    return 0;
//}