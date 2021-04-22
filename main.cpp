#include <iostream>
#include <vector>
#include <exception>

using namespace std;

struct Term {
	char sign;
	double num;
	Term(char s, double n) {
		sign = s;
		num = n;
	}
};

class GenX: public exception {
	virtual const char* what() const throw() {
		return "general runtime exception occured";
	}
};

class Equation {
	vector<Term> content;
	int iter = 0;
	public:
		Equation(vector<Term> ncontent = vector<Term>()) {content = ncontent;}
		void add(char sign, double num) {content.push_back(Term(sign, num));}
		void print() {
			for(int i = 0; i < content.size(); i++) {
				cout << (char)content.at(i).sign << (int)content.at(i).num << endl;
			}
		}
		Equation rtrunk() {
			vector<Term> ncontent;
			for(int i = 1; i < content.size(); i++) {ncontent.push_back(Term(content[i].sign, content[i].num));}
			return Equation(ncontent=ncontent);
		}
};

double solve(Equation equ) {
	switch(equ.at(1).sign) {
		case '+': {
			if(equ.size() < 3) {return (double)(equ.at(0).num + equ.at(1).num);}
		}break;
		case '-': {
			// 
		}break;
		case '*': {
			// 
		}break;
		case '/': {
			// 
		}break;
		default: {
			raise(GenX);
		}
	}
}

int main() {

	Equation equ;
	equ.add('-', 3.0);
	equ.add('*', 2.0);

	equ = equ.rtrunk();
	equ.print();

}
