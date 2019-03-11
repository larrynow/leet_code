#include<iostream>

#include<string>

using namespace std;

struct T {
	int a;
	T(int x) : a(x) {}
	bool operator< (const T &d) const { return a > d.a; }//bigger;
};

/*
int main() {
	
	T a(2);
	T b(10);

	cout << (a < b )<< endl;

	system("pause");
	return 0;
}*/