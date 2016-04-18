#ifndef PERSONTEST_HPP
#define PERSONTEST_HPP

#include <iostream>
#include <sstream>
#include <vector>
using namespace std ; 

namespace personTest {
   //class person 
    class Person {
    private: 
        long id ; 
        string name; 
        int age; 
        double wage; 
    public: 
        Person(); 
        Person(long _id, string _name, int _age, double _wage) ; 
        void setId(long id); 
        void setName(string name); 
        void setAge(int age); 
        void setWage(double wage); 
        long getId(); 
        string getName(); 
        int getAge(); 
        double getWage(); 
        string toString(); 
    };
    
    
    class PersonManager {
    private: 
        vector<Person> personCon ; 
        bool testIfExists(const long id); 
        int findPos(const long id); 
    public: 
        void addPerson(Person p); 
        Person findPersonById(const long id)  ; 
        void deletePerson(const long id); 
        void updatePerson(const long id , Person newP); 
        vector<Person> findAll() const ; 
    };
    
    class PersonTester {
    private: 
        PersonManager manager ; 
    public: 
        void addPerson(); 
        void findPersonById(); 
        void deletePerson(); 
        void updatePerson();
        void findAll(); 
        void go(); 
    };
}

#endif /* PERSONTEST_HPP */

