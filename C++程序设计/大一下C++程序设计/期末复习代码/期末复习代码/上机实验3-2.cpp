//现在两个类的部分代码：
//class Time {
//private:
//	int hour, minute, second;
//	...
//}
//class Date {
//protected:
//	int year, month, day;
//	...
//}
//
//
//定义一个 DateTime 类, 派生自上面两个类，要求实现以下功能：
//(1) 必须提供年，月，日才能创建 DateTime对象，若没提供时间则默认为0
//(2) 日期加减功能，例子：DateTime d(2024, 4, 10); d = d + t 或 d += t; 其中t是一个整数，表示秒，表示在当前的时间基础上加上t秒（若t是负数则表示减去），注意日期可能会修改。要求时间的修改在Time类实现，日期的修改在Date类实现
//(3) DateTime d; cout << d << endl 输出日期的标准格式，如 2024 - 04 - 10 15:12 : 34
//
//
//OJ测试：读入两行数据，第一行表示要创建对象的数据，第二行表示一个时间。输出运算后的日期时间标准格式。
//
//例：
//2024, 4, 20, 15, 21, 50
//20
//第一行表示要创建2024 - 4 - 20 15:21 : 50的DateTime对象，然后加上第二行的20秒，输出结果为2024 - 04 - 20 15 : 22 : 10
//
//说明：第一行的数据个数为3到6个，前面3个数据表示年月日，后面若有数据就依次表示时，分，秒
//第二行的数据有正数也有负数。(本题分数 : 40)
// 
    //#include <iostream>
    //#include <iomanip>
    //#include <vector>
    //#include <sstream>
    //using namespace std;

    //// Time类
    //class Time 
    //{
    //private:
    //    int hour, minute, second;
    //public:
    //    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    //    
    //    // 增加或减少秒数，返回溢出的天数
    //    int addSeconds(int t) 
    //    {
    //        int total = hour * 3600 + minute * 60 + second + t;
    //        int days = total / 86400;
    //        if (total < 0) 
    //        {
    //            days = (total - 86399) / 86400;
    //        }

    //        total -= days * 86400;
    //        if (total < 0) total += 86400;
    //        hour = total / 3600;
    //        minute = (total % 3600) / 60;
    //        second = total % 60;
    //        return days;
    //    }

    //    friend ostream& operator<<(ostream& os, const Time& t)
    //    {
    //        os << setw(2) << setfill('0') << t.hour << " : "
    //           << setw(2) << setfill('0') << t.minute << " : "
    //           << setw(2) << setfill('0') << t.second;
    //        return os;
    //    }
    //};

    //// Date类
    //class Date 
    //{
    //protected:
    //    int year, month, day;
    //    static const int days_in_month[13];

    //    bool isLeap(int y) const 
    //    {
    //        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    //    }

    //    int getMonthDays(int y, int m) const 
    //    {
    //        if (m == 2) return isLeap(y) ? 29 : 28;
    //        return days_in_month[m];
    //    }
    //public:

    //    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    //    // 增加或减少天数
    //    void addDays(int t) 
    //    {
    //        day += t;
    //        while (day > getMonthDays(year, month)) 
    //        {
    //            day -= getMonthDays(year, month);
    //            month++;
    //            if (month > 12) 
    //            {
    //                month = 1;
    //                year++;
    //            }
    //        }
    //        while (day <= 0) 
    //        {
    //            month--;
    //            if (month < 1)
    //            {
    //                month = 12;
    //                year--;
    //            }
    //            day += getMonthDays(year, month);
    //        }
    //    }

    //    friend ostream& operator<<(ostream& os, const Date& d) {
    //        os << setw(4) << setfill('0') << d.year << " - "
    //           << setw(2) << setfill('0') << d.month << " - "
    //           << setw(2) << setfill('0') << d.day;
    //        return os;
    //    }
    //};
    //const int Date::days_in_month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    //// DateTime类
    //class DateTime : public Date, public Time {
    //public:
    //    DateTime(int y, int m, int d, int h=0, int mi=0, int s=0)//时间默认初始为0
    //        : Date(y, m, d), Time(h, mi, s) {}

    //    // 支持 += 秒
    //    DateTime& operator+=(int t) 
    //    {
    //        int dayOffset = addSeconds(t);
    //        if (dayOffset != 0) addDays(dayOffset);
    //        return *this;
    //    }
    //    // 支持 + 秒
    //    DateTime operator+(int t) const 
    //    {
    //        DateTime tmp = *this;
    //        tmp += t;
    //        return tmp;
    //    }

    //    friend ostream& operator<<(ostream& os, const DateTime& dt)
    //    {
    //        //注意为static静态cast，因为此时仅为继承关系，属于编译时多态
    //        os << static_cast<const Date&>(dt) << " " << static_cast<const Time&>(dt);
    //        return os;
    //    }
    //};

    //// 解析输入
    //vector<int> parseLine(const string& line) 
    //{
    //    vector<int> res;
    //    stringstream ss(line);
    //    string token;
    //    while (getline(ss, token, ',')) 
    //    {
    //        int v = stoi(token);
    //        res.push_back(v);
    //    }
    //    return res;
    //}

    //int main() 
    //{
    //    string line1, line2;
    //    getline(cin, line1);
    //    getline(cin, line2);
    //    vector<int> v = parseLine(line1);
    //    int y = v[0], m = v[1], d = v[2];
    //    int h = 0, mi = 0, s = 0;
    //    if (v.size() > 3) h = v[3];
    //    if (v.size() > 4) mi = v[4];
    //    if (v.size() > 5) s = v[5];
    //    DateTime dt(y, m, d, h, mi, s);
    //    int t = stoi(line2);
    //    dt += t;
    //    cout << dt << endl;

    //    system("pause");
    //    return 0;
    //}
