#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;



#define SIZE 10


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


class c221{
	int a,b;
public:
	c221(int x,int y);
	void show();
};

c221::c221(int x,int y){
	cout <<"call constructor\n";
	a=x;
	b=y;
}

void c221::show(){
	cout << a << ' ' << b << endl;
}

void e221(){
	c221 ob(4,7);
	ob.show();
}

class c222{
	char stck[SIZE];
	int tos;
	char who;
public:
	c222(char c);
	void push(char ch);
	char pop();
};

c222::c222(char c){
	tos =0;
	who =c;
	cout << "create stack" << who << endl;
}

void c222::push(char ch){
	if(tos==SIZE){
		cout << "stack" << who << "is full\n";
		return;
	}
	stck[tos] = ch;
	tos++;
}

char c222::pop(){
	if(tos==0){
		cout << "stack"<< who << " is empty----" ;
		return 0;
	}
	tos--;
	cout << "stack "<< who << " pop : ";
	return stck[tos];
}

void e222(){
	c222 s1('A'),s2('B');

	int i;

	s1.push('a');
	s1.push('b');
	s1.push('c');
	s2.push('x');
	s2.push('y');
	s2.push('z');

	for(i=0;i<5;i++) cout << s1.pop() << endl;
	for(i=0;i<5;i++) cout << s2.pop() << endl;

}

class c223{
	char *p;
	int len;
public:
	c223(char *ptr);
	~c223();
	void show();
};

c223::c223(char *ptr){
	len = strlen(ptr);
	p = (char *)malloc (len+1);
	if(!p){
		cout << "memory set error\n";
		exit(1);
	}
	strcpy(p,ptr);
}

c223::~c223(){
	cout << "release p\n";
	free(p);
}

void c223::show(){
	cout << p  <<" - length : "<< len <<endl;
}

void e223(){
	c223 s1("this is a test."),s2("i like a c++");
	s1.show();
	s2.show();

}


//base class
class c23b{
	int i;
public:
	void set_i(int n);
	int get_i();
};

class c23d: public c23b{
	int j;
public:
	void set_j(int n);
	int mul();
};

void c23b::set_i(int n){
	i = n;
}

int c23b::get_i(){
	return i;
}

void c23d::set_j(int n){
	j = n;
}

int c23d::mul(){
	return j * get_i();
}

void e23(){
	c23d ob;

	ob.set_i(10);
	ob.set_j(4);

	cout << ob.mul() << endl;

}

enum yn{no,yes};
enum color{red,yellow,green,orange};
void out(enum yn x);

char *c[] = {"red","yellow","green","orange"};

class fruit{
public:
	enum yn annual;
	enum yn perennial;
	enum yn tree;
	enum yn tropical;
	enum color clr;
	char name[40];
};

class Apple:public fruit{
	enum yn cooking;
	enum yn crunchy;
	enum yn eating;
public:
	void seta(char *n,enum color c,enum yn ck, enum yn crchy,enum yn e);
	void show();
};

class Orange:public fruit{
	enum yn juice;
	enum yn sour;
	enum yn eating;
public:
	void seto(char *n,enum color c,enum yn j, enum yn sr,enum yn e);
	void show();
};


void Apple::seta(char *n,enum color c,enum yn ck, enum yn crchy,enum yn e){
	strcpy(name,n);
	annual = no;
	perennial = yes;
	tree = yes;
	tropical = no;
	clr = c;
	cooking = ck;
	crunchy = crchy;
	eating = e;
}

void Orange::seto(char *n,enum color c,enum yn j, enum yn sr,enum yn e){
	strcpy(name,n);
	annual = no;
	perennial = yes;
	tree = yes;
	tropical = yes;
	clr = c;
	juice = j;
	sour = sr;
	eating = e;
}

void Apple::show(){
	cout << name;

//	out(annual);
//	out(perennial);
//	out(tree);
//	out(tropical);
//	cout << c[clr];
//	out(cooking);
//	out(crunchy);
//	out(eating);
	cout << endl;
}

void Orange::show(){
	cout << name << endl;
//	out(annual);
//	out(perennial);
//	out(tree);
//	out(tropical);
//	c[clr];
//	out(juice);
//	out(sour);
//	out(eating);
	cout << endl;

}

void e231(){
	Apple a1,a2;
	Orange o1,o2;

	a1.seta("sample1",red,no,yes,yes);
	a2.seta("sample2",red,yes,no,yes);
	o1.seto("sample3",orange,no,no,yes);
	o2.seto("sample4",orange,yes,yes,no);

	a1.show();
	a2.show();
	o1.show();
	o2.show();

}

class area_c1{
public:
	double height;
	double width;
};

class rectangle:public area_c1{
public:
	rectangle(double h,double w);
	double area();
};

class isosceles:public area_c1{
public:
	isosceles(double h,double w);
	double area();
};

rectangle::rectangle(double h,double w){
	height = h;
	width = w;
}

isosceles::isosceles(double h,double w){
	height = h;
	width = w;
}

double rectangle::area(){
	return width * height;
}

double isosceles::area(){
	return 0.5 * width *height;
}

void p231(){
	rectangle b(10.0,5.0);
	isosceles i(4.0,6.0);

	cout << "rectangle:" << b.area() << endl;
	cout << "isosceles:" << i.area() << endl;


}

class c24{
	int a;
public:
	c24(int x);
	int get();
};

c24::c24(int x){
	a = x;
}

int c24::get(){
	return a;
}

void e24(){
	c24 ob(120);	//Create object
	c24 *p;			//Create object with pointer

	p = &ob;		//Store the address of ob to p


	cout << "value with object: " << ob.get();
	cout << "\n";
	cout << "value with pointer" << p->get();

}

struct s251{
	s251(double b,char *n);
	void show();
private:
	double balance;
	char name[40];
};

s251::s251(double b,char *n){
	balance = b;
	strcpy(name,n);
}

void s251::show(){
	cout << "name :"<< name;
	cout << " & : " << balance;
}


void e251(){
	s251 acc1(100.24,"aaaaa");
	s251 acc2(23.34,"bbbbb");

	acc1.show();
	acc2.show();
}

struct s253{
	s253(char *ptr);
	~s253();
	void show();
private:
	char *p;
	int len;
};

s253::s253(char *ptr){
	len = strlen(ptr);
	p = (char *)malloc(len+1);
	if(!p){
		cout << "memory allocation error\n";
		exit(1);
	}

	strcpy(p,ptr);
}

s253::~s253(){
	cout << "release p\n";
	free(p);
}

void s253::show(){
	cout << p << "- length : " << len;
	cout << endl;
}

void e253(){
	s253 s1("This is a test."),s2("I like a c++");

	s1.show();
	s2.show();

}

class c261{
	int i,j;
public:
	c261(int a,int b);
	int divisible();
};

c261::c261(int a,int b){
	i = a;
	j = b;
}

//インライン化
inline int c261::divisible(){
	return !(i%j);
}

void e261(){

	c261 ob1(10,2), ob2(10,3);

	if(ob1.divisible()) cout << "ok";
	if(ob2.divisible()) cout << "ok";
}

inline int f262(int a,int b){
	cout << "int:::";
	return a < b ? a:b;
}

inline long f262(long a,long b){
	cout << "long:::";
	return a<b?a:b;
}

inline double f262(double a,double b){
	cout << "double:::";
	return a<b? a:b;
}

void e262(){
	cout << f262(-10,10) << endl;
	cout << f262(-10.01,10.23) << endl;
	cout << f262(-10L,12L) << endl;
}

void inline f262(){
	int i;

	//ループ処理を含む関数はインライン化されない可能性がある。
	for(i=0;i<10;i++) cout << i;
}

void p262(){
	f262();
}

class c271{
	int i,j;
public:
	c271(int a,int b){ i = a;j=b;}
	int divisible(){ return !(i%j);}
};


void e271(){

	c271 ob1(10,3), ob2(10,2);

	if(ob1.divisible()) cout << "ok";
	if(ob2.divisible()) cout << "ok";

}


class c271b{
	int a;
public:
	c271b(){
		cout << "read constructor function" << endl;
		a =10;
	}
	~c271b(){cout << "read destructor function" <<endl;}
	void show(){cout << a << endl;}
};

void p271(){
	c271b ob;
	ob.show();
}
