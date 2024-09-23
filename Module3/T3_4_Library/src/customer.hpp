#ifndef ELEC_AS_CPP_CUSTOMER
#define ELEC_AS_CPP_CUSTOMER

#include <string>
#include <vector>

#include "book.hpp"
#include <iostream>

class Customer {
 public:
  Customer(const std::string& name, const std::string& id)
      : name_(name), id_(id) {}

  std::string GetName() const { return name_; }
  std::string GetID() const { return id_; }
  int GetLoanAmount() const { return books_.size(); }
  std::vector<Book> GetLoans() const { return books_; }

  bool LoanBook(Book& b) {
    if (b.Loan()) {
      books_.push_back(b);
      return true;
    }
    return false;
  }

  void ReturnBook(Book& b) {
    for (auto it = books_.begin(); it != books_.end(); ++it) {
      if (it->GetISBN() == b.GetISBN()) {
        b.Restore();
        books_.erase(it);
        break;
      }
    }
  }

  void Print() const {
    std::cout << "Customer: " << name_ << ", " << id_ << ", has " << books_.size() << " books on loan:"<<std::endl;
    for (const auto& book : books_) {
      std::cout << "- ";
      book.Print();
    }
  }

 private:
  std::string name_;
  std::string id_;
  std::vector<Book> books_;
};

#endif