#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define SIZE 255

class c211{
	int a;
public:
	c211();
	~c211();
	void show();
};

c211::c211(){
	cout << "read constructor function" << endl;
	a =10;
}

c211::~c211(){
	cout << "read destructor function" <<endl;
}

void c211::show(){
	cout << a << endl;
}

void e211(){
	c211 ob;
	ob.show();
}

class strtype{
	char *p;
	int len;
public:
	strtype();
	~strtype();
	void set(char *ptr);
	void show();
};

strtype::strtype(){
	p =(char *)malloc(SIZE);
	if(!p){
		cout << "memory set error";
		exit(1);
	}
	*p = '\n';
	len =0;
}

strtype::~strtype(){
	cout << "release p\n";
	free(p);
}

void strtype::set(char *ptr){
	if(strlen(ptr)>= SIZE){
		cout << "too big\n";
		return;
	}
	strcpy(p,ptr);
	len = strlen(p);
}

void strtype::show(){
	cout << p << "---length:" << len;
	cout << endl;
}

void e212(){
	strtype s1,s2;

	s1.set("this is a test.");
	s2.set("i like c++");
	s1.show();
	s2.show();

}

class p211{
	int queue[SIZE];
	int head,tail;
public:
	p211();
	void q(int num);
	int deq();
};

p211::p211(){
	head = tail =0;
}

void p211::q(int num){
	if(tail+1==head || (tail+1==SIZE && !head)) {
		cout << "que is full\n";
		return;
	}
	tail++;
	if(tail==SIZE)tail = 0;
	queue[tail] = num;
}


int p211::deq(){
	if(head ==tail){
		cout << "que is empty\n";
		return 0;
	}
	head++;
	if(head==SIZE) head=0;
	return queue[head];
}
