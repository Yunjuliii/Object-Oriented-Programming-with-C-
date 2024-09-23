#include "person.hpp"


Person::Person(const std::string& Name, const int Birthyear)
    : Name_(Name),Birthyear_(Birthyear){

    }

const std::string& Person::GetName() const
{
    return Name_;
}

int Person::GetAge(int year)
{
    int Age = year - Birthyear_;
    return Age;
}

// define your Person class' functions here

