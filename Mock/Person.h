#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
    std::string name;
    int age;

    Person() : name(""), age(0) {}

    Person(const std::string& name, int age) : name(name), age(age) {}

    bool operator==(const Person& other) const {
        return (name == other.name) && (age == other.age);
    }
};

#endif

