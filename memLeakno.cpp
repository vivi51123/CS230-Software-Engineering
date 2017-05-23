#include <iostream>
#include <string>

typedef std::string string;

class Dog {
    private:
	int _age;
	string _kind;
    public:
	void set_age(int age){ _age = age;}
	void set_kind(string kind){_kind = kind;}
	int get_age() {return _age;}
	string get_kind(){return _kind;}
	Dog();
	~Dog();
	
	friend std::ostream& operator<<(std::ostream& os, const Dog &d);
};

Dog::Dog() {
    _age = 0;
    _kind = "nothing";
}

Dog::~Dog() {
    std::cout << "dog deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Dog &d) {
    os << "Age: " << d._age << std::endl << "Kind: " << d._kind << std::endl;
    return os;
}

int main() {
    Dog *d = new Dog();
    d->set_age(10);
    d->set_kind("Corgi");
    std::cout << *d;
    delete d; //If you comment out this line, you get a mem leak
    //Vagrind will report no errors if line is left as is
    //Valgrind will report memleak error if line 40 is commented out
}