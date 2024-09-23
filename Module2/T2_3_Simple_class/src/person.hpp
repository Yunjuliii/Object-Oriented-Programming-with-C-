#ifndef AALTO_ELEC_CPP_PERSON
#define AALTO_ELEC_CPP_PERSON

// declare your Person class here
#include <string>
class Person{
public:
    Person(const std::string& Name, const int Birthyear);
    const std::string& GetName() const;
    int GetAge(int year);
private:
    std::string Name_;
    int Birthyear_;

};

#endif