#include <iostream>
using namespace std;
class Derived2;
class Base {
	int a;
	public:
	
	Base(int num):a(num){}
	template <typename T>
	void show(T *obj,void (T::*func)()) {
		(obj->*func)();
	}
};

class Derived2 {
	public:
	
	Derived2 (int num) {}
	void run () {
		std::cout<<"Hello World!"<<endl;
	}
};

class Derived : public Base {
	public:
	
	Derived (int num): Base(num) {}
	void run () {
		std::cout<<"Hello World!"<<endl;
	}
};


int main() {
	Base b(8);
	Derived2 cb(8);
	b.show(&cb, &Derived2::run);
	
	Derived cd(6);
	b.show(&cd, &Derived::run);

	// your code goes here
	return 0;
}
