#include <iostream>
#include <string>
#include <vector>
#include "./Log.h"

void helloWorld() {
	std::cout << "Hello World" << std::endl;
}

void forEach(const std::vector<int>& values, void(*func)(int)) {
	for (int value : values)
		func(value);
}

class Person {
public:
	std::string name;
	int age = 0;
	std::vector<Person*> parents = {};
	std::vector<Person*> children = {};

	Person(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
	Person(std::string name, int age, Person* mom, Person* dad) {
		this->name = name;
		this->age = age;
		addParent(mom);
		addParent(dad);
	}
	Person() {}

	void addParent(Person* parent) {
		this->parents.push_back(parent);
	}
	void addChild(Person* child) {
		this->children.push_back(child);
	}

	void listParents() {
		for (Person* parent : parents){
			std::cout << parent->name << std::endl;
			};
	}
	

	void sayHello() {
		std::cout << "Hello, my name is " << name << std::endl;
	}
};

int main(){
	Person pat("Pat", 50);
	Person shelly("Shelly", 50);
	Person hank("Hank", 60);
	Person doris("Doris", 60);
	Person suzy("Suzy", 30, &shelly, &pat);
	Person jim("Jim", 30, &doris, &hank);
	Person alex("Alex", 10, &suzy, &jim);
	jim.addChild(&alex);
	suzy.addChild(&alex);


	alex.sayHello();
	alex.listParents();
	jim.listParents();

	log(alex.age);
	
	alex.age = 11;

	log(alex.age);

	std::vector<int> myNums = {1, 1, 2, 3, 5, 8};


	typedef void(*HelloWorldFunc)();

	HelloWorldFunc myFunc = helloWorld;

	myFunc();
	myFunc();

	forEach(myNums, [](int value) { std::cout << value << std::endl; });



	return 0;
}