#include <iostream>
using namespace std;

#define SIZE 10

class c151{
	int a;
public:
	void set_a(int num);
	int get_a();
};

void c151::set_a(int num){
	a = num;
}

int c151::get_a(){
	return a;
}


class stack{
	char stck[SIZE];
	int tos;
public:
	void init();
	void push(char ch);
	char pop();
};

void stack::init(){
	tos = 0;
}

void stack::push(char ch){
	if(tos==SIZE){
		cout << "full stack";
		return;
	}
	stck[tos] = ch;
	tos++;
}

char stack::pop(){
	if(tos==0){
		cout << "stack is empty ";
		return 0;
	}
	tos--;
	return stck[tos];
}

void e151();
void e154();

int main(){
	//e151();
	e154();
}

void e151(){

	c151 ob1,ob2;

	ob1.set_a(10);
	ob2.set_a(20);

	cout << ob1.get_a();
	cout << ob2.get_a();
}

void e154(){
	stack s1,s2;
	int i;

	s1.init();
	s2.init();

	s1.push('a');
	s1.push('b');
	s1.push('c');

	s2.push('x');
	s2.push('y');
	s2.push('z');

	for(i=0;i<3;i++) cout << "s1 pop :" << s1.pop() << endl;
	for(i=0;i<3;i++) cout << "s2 pop :" << s2.pop() << endl;

}






