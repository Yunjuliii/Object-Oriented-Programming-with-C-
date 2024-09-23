#ifndef ELEC_AS_CPP_BOOK
#define ELEC_AS_CPP_BOOK

#include <ctime>
#include <string>
#include <iostream>

struct Date {
  int day;
  int month;
  int year;

  static Date Today() {
    Date d;
    std::time_t t = time(0);
    struct tm* now = localtime(&t);
    d.day = now->tm_mday;
    d.month = now->tm_mon + 1;
    d.year = now->tm_year + 1900;
    return d;
  }
};

class Book {
 public:
  Book(const std::string& name, const std::string& author, const std::string& isbn, bool loaned = false, Date due_date = {0, 0, 0})
      : name_(name), author_(author), isbn_(isbn), loaned_(loaned), due_date_(due_date) {}

  std::string GetName() const { return name_; }
  std::string GetAuthor() const { return author_; }
  std::string GetISBN() const { return isbn_; }
  bool GetStatus() const { return loaned_; }
  Date GetDueDate() const { return due_date_; }

  bool Loan() {
    if (loaned_) return false;
    due_date_ = Date::Today();
    due_date_.month += 1;  // Add one month
    if (due_date_.month > 12) {
      due_date_.month = 1;
      due_date_.year += 1;
    }
    loaned_ = true;
    return true;
  }

  void Restore() {
    loaned_ = false;
    due_date_ = {0, 0, 0};
  }

  void Print() const {
    std::cout << std::boolalpha<<"Book: " << name_ << ", author: " << author_ << ", ISBN: " << isbn_<< ", loaned " 
    << loaned_<< ", due date: " << due_date_.day << "." << due_date_.month << "." << due_date_.year << std::endl;
  }

 private:
  std::string name_;
  std::string author_;
  std::string isbn_;
  bool loaned_;
  Date due_date_;
};

#endif