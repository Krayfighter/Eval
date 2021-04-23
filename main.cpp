#include <iostream>
#include <vector>
#include <exception>
#include <string>
// for finding item in array
#include <algorithm>
#include <iterator>

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
		Equation(vector<Term> ncontent = vector<Term>()) {content = vector<Term>();}
		void add(char sign, double num) {content.push_back(Term(sign, num));}
		void init() {
			content = vector<Term>();
			add('+', 0.0);
		}
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
		vector<Term> *get_content() {return &content;};
		// void from_string(string nequ) {
		// 	vector<string> tmp;
		// 	int word = 0;
		// 	for(int iter = 0; iter < nequ.size(); ++iter) {
		// 		switch(nequ[iter]) {
		// 			case '+': {
		// 				word++;
		// 				tmp.push_back("");
		// 				tmp[word] += nequ[iter];
		// 			}break;
		// 			case '-': {
		// 				word++;
		// 				tmp.push_back("");
		// 				tmp[word] += nequ[iter];
		// 			}break;
		// 			case '*': {
		// 				word++;
		// 				tmp.push_back("");
		// 				tmp[word] += nequ[iter];
		// 			}break;
		// 			case '/': {
		// 				word++;
		// 				tmp.push_back("");
		// 				tmp[word] += nequ[iter];
		// 			}break;
		// 			default: {
		// 				tmp[word] += nequ[iter];
		// 			}break;
		// 		}
		// 	}
		// 	init();
		// 	char _sign;
		// 	string _snum;
		// 	int _num;
		// 	for(string var : tmp) {

		// 		_sign = var[0];
		// 		for(int o = 1; o < var.size(); o++) {_snum += var[o];}
		// 		_num = stod(_snum);
		// 		add(_sign, _num);

		// 		_sign = char();
		// 		_snum = "";

		// 	}
		// }
};

Equation from_string(string str) {

	Equation out = Equation();
	out.init();

	vector<string> tmp;
	char ops[4] = {'+', '-', '*', '/'};
	int word = 0;
	
	tmp.push_back("");

	for(char var : str) {
		if(find(begin(ops), end(ops), 'i') != end(ops)) {
			tmp.push_back(string(1, var));
		}
	}

}

double solve(Equation equ) {

	vector<Term> *cnt = equ.get_content();

	switch(cnt->at(1).sign) {
		case '+': {
			if(cnt->size() < 3) {return (double)(cnt->at(0).num + cnt->at(1).num);}
			else {return (double)(cnt->at(0).num + solve(equ.rtrunk()));}
		}break;
		case '-': {
			if(cnt->size() < 3) {return (double)(cnt->at(0).num - cnt->at(1).num);}
			else {return (double)(cnt->at(0).num - solve(equ.rtrunk()));}
		}break;
		case '*': {
			if(cnt->size() < 3) {return (double)(cnt->at(0).num * cnt->at(1).num);}
			else {return (double)(cnt->at(0).num * solve(equ.rtrunk()));}
		}break;
		case '/': {
			if(cnt->size() < 3) {return (double)(cnt->at(0).num / cnt->at(1).num);}
			else {return (double)(cnt->at(0).num / solve(equ.rtrunk()));}
		}break;
		default: {
			throw(GenX());
		}break;
	}

}

int main() {

	Equation equ;
	// equ.from_string("-3*2");
	// equ.init();
	// equ.add('-', 3.0);
	// equ.add('*', 2.0);

	double out = solve(equ);
	cout << out << endl;

}
