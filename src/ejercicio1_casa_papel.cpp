#include <iostream>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;

class HashTable{
private:
	int buckets;
	list<double> *table;
public:
	HashTable(int b){
		buckets = b;
		table = new list<double>[buckets];
	}
	void insert(int p, double d);
	void deletes(int p);
	double retorna(int p);
	void print();

};


void HashTable::insert(int p,double d){
 table[p].push_back(d);
}
void HashTable::deletes(int p){
table[p].clear();
}
void HashTable::print(){
	for (int i = 0; i < buckets; ++i) {
         cout << "| Bucket " << i << " | ";
         for (auto j: table[i]) {
			cout << "-> | " << j << " | ";
		}
         cout << endl;
	}
}
double HashTable::retorna(int p){
	double hola = 0;
	for (auto j: table[p]) {
		hola = j;
	}
	return hola;
}
int main() {

	HashTable hs(10);
	list<double> deque;

	for (int i = 0; i < 10; ++i) {
		hs.insert(i,rand()%50+1);
	}
	hs.print();

	cout << "INSERTADO ELEMENTOS EN ORDEN " << endl;
	for (int i = 0;  i < 10; ++i) {
		deque.push_back(hs.retorna(i));
	}

	deque.sort(greater<double>());


	for(double x: deque){
		cout << "Elementos " << x << endl;
	}
}
