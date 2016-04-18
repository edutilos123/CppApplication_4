#include "PersonTest.hpp"

namespace personTest {
    // Person::

    Person::Person() {

    }

    Person::Person(long _id, string _name, int _age, double _wage) :
    id(_id), name(_name), age(_age), wage(_wage) {

    }

    void Person::setId(long id) {
        this-> id = id;
    }

    void Person::setName(string name) {
        this-> name = name;
    }

    void Person::setAge(int age) {
        this-> age = age;
    }

    void Person::setWage(double wage) {
        this-> wage = wage;
    }

    long Person::getId() {
        return id;
    }

    string Person::getName() {
        return name;
    }

    int Person::getAge() {
        return age;
    }

    double Person::getWage() {
        return wage;
    }

    string Person::toString() {
        stringstream ss;
        ss << "name = " << name << endl
                << "age = " << age << endl
                << "wage = " << wage << endl;
        return ss.str();
    }
    // -> Person 


    //PersonManager:: 

    bool PersonManager::testIfExists(const long id) {
        for(Person p: personCon) {
            if(p.getId() == id) return true ; 
        }
        return false ; 
    }
    int PersonManager::findPos(const long id) {
        int counter = 0 ; 
        for(Person p: personCon) {
            if(p.getId() == id) return counter ; 
            counter ++ ; 
        }
        return -1 ; 
    }
    void PersonManager::addPerson(Person p) {
        if(testIfExists(p.getId())) {
            cerr << "person with id " << p.getId() << " was already registered." << endl ; 
        } else {
            personCon.push_back(p); 
        }
    }
    Person PersonManager::findPersonById(const long id) {
        Person temp {}; 
        for(Person p: personCon) {
            if(p.getId() == id) {
                temp = p ; 
                break; 
            }
        }
        return temp; 
    }
    void PersonManager::deletePerson(const long id) {
        int index = findPos(id); 
        if(index < 0) return ; 
        cout << "index = " << index << endl ; 
        personCon.erase(personCon.begin() + index); 
        cout << "size = " << personCon.size() << endl ; 
    }
    void PersonManager::updatePerson(const long id, Person newP) {
        Person temp = findPersonById(id); 
        if(temp.getId() > 0) {
            deletePerson(id); 
            temp = newP; 
            addPerson(temp); 
        }
    }
    vector<Person> PersonManager::findAll() const  {
        return personCon ; 
    }
    //-> PersonManager 

    
    //PersonTester::
    
      void PersonTester::addPerson() {
          cout << "insert id , name, age, wage of person:" << endl ; 
          long id {}; 
          string name {}; 
          int age {}; 
          double wage {}; 
          cin >> id >> name >> age >> wage ; 
          Person p {id, name, age, wage }; 
          manager.addPerson(p); 
      }
        void PersonTester::findPersonById() {
            long id {}; 
            cout << "insert id of person to be found:" << endl ; 
            cin >> id ; 
            Person found = manager.findPersonById(id); 
            if(found.getId() > 0) {
                cout << "found person = " << endl ; 
                cout << found.toString() ; 
            } else {
                cerr << "no person was found:" << endl ; 
            }
            
        }
        void PersonTester::deletePerson() {
            long id{}; 
            cout << "insert the id of person to be deleted:" << endl ; 
            cin >> id ; 
            manager.deletePerson(id); 
            cout << "hopefully person was deleted successfully:" << endl ; 
        }
        void PersonTester::updatePerson() {
            long old_id {}; 
            string name{}; 
            int age {}; 
            double wage {}; 
            cout << "insert the id of person to be updated:" << endl ; 
            cin >> old_id ; 
            cout << "insert new name, age, wage: " << endl ; 
            cin >> name >> age >> wage ; 
            Person newP {old_id , name, age, wage}; 
            manager.updatePerson(old_id, newP); 
        }
        void PersonTester::findAll() {
            cout << "all people>>" << endl ; 
            vector<Person> list = manager.findAll(); 
            for(Person p: list) cout << p.getName() << endl ; 
        }
        
        void PersonTester::go() {
           // const string \r\n = "\r\n"; 
            string menu = 
                    "1->  add person " 
                    "\r\n"
                    "2-> find person by id"  
                    "\r\n" 
                    "3 -> delete person " 
                    "\r\n" 
                    "4 -> update person " 
                    "\r\n" 
                    "5 -> find all persons" 
                    "\r\n" 
                    "other key -> break loop" 
                    "\r\n" 
                    ; 
            
            bool state = true; 
            while(state) {
                cout << menu ; 
                int answer ; 
                cin >> answer ; 
                switch(answer) {
                    case 1: 
                        addPerson(); 
                        break; 
                    case 2: 
                        findPersonById(); 
                        break; 
                    case 3: 
                        deletePerson(); 
                        break; 
                    case 4: 
                        updatePerson(); 
                        break; 
                    case 5 : 
                        findAll(); 
                        break; 
                    default : 
                        cout << "Program was terminated!" << endl ; 
                        state = false ; 
                     
                }
            }  
       
            
        }
     
    //-> PersonTester 
}


