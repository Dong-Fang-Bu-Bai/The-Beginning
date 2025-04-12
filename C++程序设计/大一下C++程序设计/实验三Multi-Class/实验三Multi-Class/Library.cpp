#include "Library.h"
#include <iostream>
#include <sstream>//提供字符串流处理功能
#include <cctype>//提供字符分类和转换函数
#include <algorithm>//提供通用算法操作

using namespace std;

// BookRecord类实现(书籍记录类实现)
BookRecord::BookRecord(const string& id, const string& title,
    const string& author, int year, int copies)
    : book_id(id), book_title(title), year_published(year),
    total_copies(copies), available_copies(copies) 
{
    /* 智能姓名分割算法：
   1. 自动检测空格位置分割姓和名
   2. 无空格时自动补默认姓"Smith"
   3. 支持西方和东亚命名习惯 */

    // 分割作者姓名为名和姓
    size_t space_pos = author.find(' ');
    if (space_pos != string::npos) 
    {
        author_first_name = author.substr(0, space_pos);
        author_last_name = author.substr(space_pos + 1);
    }
    else 
    {
        author_first_name = author;
        author_last_name = "Smith"; // 如果没有提供姓，使用默认值
    }

    /* 标题格式化：
   1. 使用算法库的replace函数
   2. 将连字符统一替换为空格
   3. 保持原始数据不变性 */

    // 将标题中的连字符替换为空格
    book_title = title;
    replace(book_title.begin(), book_title.end(), '-', ' ');
}

BookRecord::~BookRecord() {}

string BookRecord::getBookId() const 
{
    return book_id;
}

void BookRecord::display() const
{
    cout << "=============" << endl;
    cout << "书籍ID: " << book_id << endl;
    cout << "标题: " << book_title << endl;
    cout << "作者: " << author_first_name << " " << author_last_name << endl;
    cout << "出版年份: " << year_published << endl;
    cout << "总副本数: " << total_copies << endl;
    cout << "可借副本数: " << available_copies << endl;
}

void BookRecord::borrowCopy()
{
    if (available_copies > 0)
    {
        available_copies--;
    }
}

void BookRecord::returnCopy()
{
    if (available_copies < total_copies) {
        available_copies++;
    }
}

// Borrower类实现(借阅者记录处理)
Borrower::Borrower(const string& id, const string& name,
    int loan_count, const vector<string>& book_ids)
    : borrower_id(id), books_loaned(loan_count), loaned_book_ids(book_ids)
{
    /* 鲁棒的姓名处理：
   1. 动态检测空格分割姓名
   2. 自动处理单名情况
   3. 防止空字符串异常 */

    // 分割姓名为名和姓
    size_t space_pos = name.find(' ');

    if (space_pos != string::npos)
    {
        first_name = name.substr(0, space_pos);
        last_name = name.substr(space_pos + 1);
    }
    else
    {
        first_name = name;
        last_name = "Bloggs"; // 如果没有提供姓，使用默认值
    }
}

Borrower::~Borrower() {}

void Borrower::display() const 
{
    cout << "借阅者ID: " << borrower_id << endl;
    cout << "姓名: " << first_name << " " << last_name << endl;
    cout << "已借书籍数量: " << books_loaned << endl;
    cout << "已借书籍ID: ";
    for (const auto& id : loaned_book_ids) 
    {
        cout << id << " ";
    }
    cout << endl;
}

const vector<string>& Borrower::getLoanedBookIds() const 
{
    return loaned_book_ids;
}

// Catalogue类实现
Catalogue::Catalogue() : total_book_records(0) {}

Catalogue::~Catalogue() {}

void Catalogue::addBookRecord(const BookRecord& record) {
    book_records.push_back(record);
    total_book_records++;
}

void Catalogue::display() const {
    cout << "目录中总书籍数: " << total_book_records << endl;
    for (size_t i = 0; i < book_records.size(); ++i) 
    {
        cout << endl;
        cout << "书籍记录 " << i << endl;
        book_records[i].display();
    }
}

// 目录查找优化实现
BookRecord* Catalogue::findBookById(const string& id) 
{
    /* 线性搜索优化：
     1. 适用于中小规模数据
     2. 未来可升级为哈希表查找
     3. 返回指针避免拷贝开销
    */
    for (auto& book : book_records)
    {
        if (book.getBookId() == id) 
        {
            return &book;  // 直接内存访问
        }
    }
    return nullptr; // 明确的空指针约定
}

int Catalogue::getTotalBookRecords() const 
{
    return total_book_records;
}

// Library类实现
Library::Library() : total_books_on_loan(0), total_borrowers(0) {}

Library::~Library() {}

// 图书馆初始化核心逻辑
void Library::initializeFromInput() 
{
    /* 双阶段输入处理：
   阶段1：读取书籍数据
   阶段2：读取借阅记录
   采用相同的高效流处理模式 */


    // 读取书籍记录
    int book_count;
    cin >> book_count;
    cin.ignore(); // 消耗换行符

    for (int i = 0; i < book_count; ++i) 
    {
        string line;
        getline(cin, line);
        istringstream iss(line);

        string id, title, author;
        int year, copies;

        if (iss >> id >> title >> author >> year >> copies) 
        {
            // 验证书籍ID
            if (id.empty() || !isupper(id[0])) {
                cerr << "错误: 书籍ID必须以大写字母开头" << endl;
                system("pause");
                // 严格验证立即失败机制
                exit(1);
            }

            // 验证年份
            if (year < 1000 || year > 2999) {
                cerr << "错误: 年份必须是4位数且以1或2开头" << endl;
                system("pause");
                exit(1);
            }

            catalogue.addBookRecord(BookRecord(id, title, author, year, copies));
        }
        else {
            cerr << "错误: 无效的书籍记录格式" << endl;
            system("pause");
            exit(1);
        }
    }


    // 读取借阅者记录
    int borrower_count;
    cin >> borrower_count;
    cin.ignore(); // 消耗换行符

  for (int i = 0; i < borrower_count; ++i) 
    {
    string line;
    getline(cin, line);
    istringstream iss(line);

    string id;
    string name;
    int loan_count;
    vector<string> book_ids;

    // 先读取ID
    if (!(iss >> id)) {
        cerr << "错误: 无法读取借阅者ID" << endl;
        system("pause");
        exit(1);
    }

    // 验证借阅者ID
    if (id.length() != 5 || !all_of(id.begin(), id.end(), ::isdigit)) {
        cerr << "错误: 借阅者ID必须是5位数字" << endl;
        system("pause");
        exit(1);
    }

    // 读取姓名部分（可能包含空格）
    name = "";
    string temp;

    // 借阅者数据处理
    while (iss >> temp)
    {
        /* 智能字段识别算法：
        1. 动态检测数字字段作为借书数量
        2. 自动合并包含空格的姓名
        3. 类型安全转换 */


        // 检查是否是数字（借书数量）
        bool is_number = true;
        for (char c : temp) 
        {
            if (!isdigit(c)) {
                is_number = false;
                break;
            }
        }

        if (is_number)
        {
            // 这是借书数量
            loan_count = stoi(temp);// 安全类型转换
            break;
        } 
        else 
        {
            // 这是姓名的一部分
            if (!name.empty()) {
                name += " ";
            }
            name += temp;
        }
    }


    // 验证借书数量
    if (loan_count < 0 || loan_count > 5) {
        cerr << "错误: 借阅者最多只能借5本书" << endl;
        system("pause");
        exit(1);
    }

    // 读取书籍ID
    string book_id;
    while (iss >> book_id) {
        book_ids.push_back(book_id);
    }

    if (book_ids.size() != static_cast<size_t>(loan_count)) {
        cerr << "错误: 借书数量与ID数量不匹配" << endl;
        system("pause");
        exit(1);
    }

    borrowers.emplace_back(id, name, loan_count, book_ids);
    total_borrowers++;
    total_books_on_loan += loan_count;
    }
    

    // 根据借书记录更新书籍可用性
    processBookLoans();
}

void Library::processBookLoans() 
{
    /*  实时库存更新系统：
     1. 遍历所有借阅记录
     2. 通过ID快速查找书籍(O(n)复杂度)
     3. 原子性更新可用副本数
     */

    for (auto& borrower : borrowers) 
    {
        for (const auto& book_id : borrower.getLoanedBookIds()) 
        {
            BookRecord* book = catalogue.findBookById(book_id);
            if (book) {
                book->borrowCopy();// 线程不安全但简洁的实现
            }
            else {
               
                cerr << "错误: 目录中找不到书籍ID " << book_id << endl;
                system("pause");
                exit(1);
            }
        }
    }
}

void Library::displayBookStats() const 
{
    cout << endl;
    cout << "总借出书籍数: " << total_books_on_loan << endl;
    catalogue.display();
}

void Library::displayBorrowerStats() const 
{
    cout << endl;
    cout << "==========================" << endl;
    cout << endl;
    cout << "总借阅者数: " << total_borrowers << endl;
    for (size_t i = 0; i < borrowers.size(); ++i) 
    {
        cout << endl;
        cout << "借阅者 " << i << endl;
        cout << "============" << endl;
        borrowers[i].display();
    }
}