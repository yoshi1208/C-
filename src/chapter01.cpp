#include <iostream>
using namespace std;

#define SIZE 10
#define QSIZE 101


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

void e151(){

	c151 ob1,ob2;

	ob1.set_a(10);
	ob2.set_a(20);

	cout << ob1.get_a();
	cout << ob2.get_a();
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

class card{
	char ch[SIZE];
	char autho[SIZE];
	int num[SIZE];
	int tos;
public:
	void init();
	void store(char ch,char person,int count);
	void show();
};

void card::init(){
	tos =0;
}

void card::store(char title,char person,int count){
	if(tos==SIZE){
		cout << "full stack";
		return;
	}
	ch[tos] = title;
	autho[tos] = person;
	num[tos] = count;
	tos++;
}

void card::show(){
	do{
		tos--;
		cout << ch[tos] << ':';
		cout << autho[tos]<< ':' ;
		cout << num[tos] << endl ;

	}while(tos > 0);
}

void p152(){
	card ob;
	ob.init();
	ob.store('a','b',3);
	ob.store('d','d',4);
	ob.store('e','e',5);
	ob.store('f','f',6);
	ob.store('A','E',809);
	ob.show();
}

class q_type{
	int queue[SIZE];
	int head,tail;
public:
	void init();
	void q(int num);
	int deq();
};

void q_type::init(){
	head = tail =0;
}

void q_type::q(int num){
	if(tail+1==head || (tail+1==SIZE && !head)) {
		cout << "que is full\n";
		return;
	}
	tail++;
	if(tail==SIZE)tail = 0;
	queue[tail] = num;
}


int q_type::deq(){
	if(head ==tail){
		cout << "que is empty\n";
		return 0;
	}
	head++;
	if(head==SIZE) head=0;
	return queue[head];
}

void p153(){
	q_type q1,q2;

	int i;

	q1.init();
	q2.init();

	for(i=1;i<=10;i++){
		q1.q(i);
		q2.q(i*i);
	}
	for(i=1;i<=10;i++){
		cout<<"delete from que value(q1):" << q1.deq() << endl;
		cout<<"delete from que value(q2):" << q2.deq() << endl;
	}

}

char min(char a,char b);
int min(int a,int b);
double min(double a,double b);

void p173(){
	cout << "int:" << min(10,20) << endl;
	cout << "char:" << min('A','B') << endl;
	cout << "int:" << min(10.4,20.2) << endl;
}

int min(int a,int b){
	return a < b ? a:b;
}

char min(char a,char b){
	return tolower(a) < tolower(b) ? a:b;
}

double min(double a,double b){
	return a < b ? a:b;
}
