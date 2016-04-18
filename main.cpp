#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
#include <assert.h>
#include "PersonTest.hpp"

using namespace std;
using namespace personTest; 


void test(); 
int main(int argc, char** argv) {
    //test(); 
    PersonTester tester{}; 
    tester.go(); 
    return 0;
}


void test() {
    //some persons 
    unique_ptr<Person> p1Ptr {new Person(1L, "foo",10 , 100.0 )}; 
    unique_ptr<Person> p2Ptr {new Person(2L, "bar", 20 , 200.0) }; 
    unique_ptr<Person> p3Ptr {new Person(3L, "bim", 30 , 300.0)}; 
    //personManager 
    unique_ptr<PersonManager> manager {new PersonManager()}; 
    //Person p1 = p1Ptr.get(); 
    manager.get()->addPerson(*(p1Ptr.get())); 
    manager.get()-> addPerson(*(p2Ptr.get())); 
    manager.get()-> addPerson(*(p3Ptr.get())); 
    
    //printing all people 
    vector<Person> c = manager.get()->findAll(); 
    for(Person p: c) 
        cout << p.toString() << endl ; 
    
    assert(c.size() == 3) ; 
    
    
    
    manager.get()-> deletePerson(1L); 
    c = manager.get() -> findAll(); 
    assert(c.size() == 2); 
    
    unique_ptr<Person> p4Ptr {new Person(2L , "new bar", 50 , 500.0)}; 
    manager.get()-> updatePerson(2L , *(p4Ptr.get())); 
    
    
    c = manager.get() -> findAll(); 
    assert(c.size() == 2) ; 
    cout << "after update " << endl ; 
    
    for(Person p: c)  cout << p.toString() << endl ; 
    
    Person single = manager.get() -> findPersonById(2L); 
    cout << "person by id == 2L" << endl ; 
    cout << single.toString() << endl ; 
    assert(single.getId() == 2L); 
    assert(single.getName() == "new bar"); 
    assert(single.getAge() > 40); 
    assert(single.getWage() > 50); 
}

