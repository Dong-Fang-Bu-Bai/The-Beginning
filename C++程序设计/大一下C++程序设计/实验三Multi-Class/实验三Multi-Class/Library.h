#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>//提供字符串操作功能
#include <vector>//提供动态数组容器

class BookRecord {
private:
    std::string book_id;         // 书籍ID
    std::string book_title;      // 书籍标题
    std::string author_first_name; // 作者名
    std::string author_last_name;  // 作者姓
    int year_published;          // 出版年份
    int total_copies;            // 总副本数
    int available_copies;        // 可借副本数

public:
    BookRecord(const std::string& id, const std::string& title,
        const std::string& author, int year, int copies);
    ~BookRecord();

    std::string getBookId() const;  // 获取书籍ID
    void display() const;           // 显示书籍信息
    void borrowCopy();              // 借出副本
    void returnCopy();              // 归还副本
};

class Borrower {
private:
    std::string borrower_id;       // 借阅者ID
    std::string first_name;        // 借阅者名
    std::string last_name;         // 借阅者姓
    int books_loaned;              // 已借书籍数量
    std::vector<std::string> loaned_book_ids; // 已借书籍ID列表

public:
    Borrower(const std::string& id, const std::string& name,
        int loan_count, const std::vector<std::string>& book_ids);
    ~Borrower();

    void display() const;                          // 显示借阅者信息
    const std::vector<std::string>& getLoanedBookIds() const; // 获取已借书籍ID列表
};

class Catalogue {
private:
    int total_book_records;               // 总书籍记录数
    std::vector<BookRecord> book_records; // 书籍记录列表

public:
    Catalogue();
    ~Catalogue();

    void addBookRecord(const BookRecord& record); // 添加书籍记录
    void display() const;                         // 显示目录信息
    BookRecord* findBookById(const std::string& id); // 通过ID查找书籍
    int getTotalBookRecords() const;              // 获取总书籍记录数
};

class Library {
private:
    int total_books_on_loan;    // 总借出书籍数
    int total_borrowers;        // 总借阅者数
    Catalogue catalogue;        // 书籍目录
    std::vector<Borrower> borrowers; // 借阅者列表

    void processBookLoans();    // 处理借书记录

public:
    Library();
    ~Library();

    void initializeFromInput();     // 从输入初始化
    void displayBookStats() const;  // 显示书籍统计
    void displayBorrowerStats() const; // 显示借阅者统计
};

#endif // LIBRARY_H