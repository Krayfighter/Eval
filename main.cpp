#include <iostream>
#include <vector>

using namespace std;

struct Term {
	char sign;
	double num;
	Term(char s, double n) {
		sign = s;
		num = n;
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
				cout << content[i].sign << content[i].num << endl;
			}
		}
		Equation rtrunk() {
			vector<Term> ncontent;
			for(int i = 1; i < content.size(); i++) {ncontent.push_back(Term(content[i].sign, content[i].num));}
			return Equation(ncontent = ncontent);
		}
};

int main() {

	Equation equ;
	equ.add('-', 3.0);
	equ.add('*', 2.0);

	equ = equ.rtrunk();
	equ.print();

}
