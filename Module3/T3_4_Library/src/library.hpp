#ifndef ELEC_AS_CPP_LIBRARY
#define ELEC_AS_CPP_LIBRARY

#include <string>
#include <vector>

#include "book.hpp"
#include "customer.hpp"

class Library {
 public:
  Library(const std::string& name) : name_(name) {}

  std::string GetName() const { return name_; }
  std::vector<Book>& GetBooks() { return books_; }
  std::vector<Customer>& GetCustomers() { return customers_; }

  Book FindBookByName(const std::string& name) const {
    for (const auto& book : books_) {
      if (book.GetName() == name) {
        return book;
      }
    }
    return Book("", "", "");
  }

  std::vector<Book> FindBooksByAuthor(const std::string& author) const {
    std::vector<Book> result;
    for (const auto& book : books_) {
      if (book.GetAuthor() == author) {
        result.push_back(book);
      }
    }
    return result;
  }

  std::vector<Book> FindAllLoanedBooks() const {
    std::vector<Book> result;
    for (const auto& book : books_) {
      if (book.GetStatus()) {
        result.push_back(book);
      }
    }
    return result;
  }

  Customer FindCustomer(const std::string& id) const {
    for (const auto& customer : customers_) {
      if (customer.GetID() == id) {
        return customer;
      }
    }
    return Customer("", "");
  }

 private:
  std::string name_;
  std::vector<Book> books_;
  std::vector<Customer> customers_;
};

#endif