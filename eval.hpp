#include <iostream>
#include <string>
#include <algorithm>
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

class GenX {};

// Equation evaluator class
class Equation {
	vector<Term> content;
	int iter = 0;
	public:
		Equation(vector<Term> ncontent = vector<Term>()) {content = ncontent;}
		void add(char sign, double num) {content.push_back(Term(sign, num));}
		void init();
		void print();
		Equation rtrunk();
		vector<Term> *get_content() {return &content;};
		int size() {return content.size();}
};
void Equation::init() {
	content = vector<Term>();
	add('+', 0.0);
}
void Equation::print() {
	for(int i = 0; i < content.size(); i++) {
		cout << (char)content.at(i).sign << (int)content.at(i).num << endl;
	}
}
Equation Equation::rtrunk() {
	vector<Term> ncontent;
	for(int i = 1; i < content.size(); i++) {
		ncontent.push_back(content[i]);
	}
	return Equation(ncontent=ncontent);
}


// Main (top-level) evaluation class
class Eval: Equation {
	Equation equ = Equation();
	double output = 0;
	double solve(Equation equ);
	public:
		Eval(string str);
		double get_out() {return output;}
};
Eval::Eval(string str) {
	vector<string> tmp = {""};
	char ops[4] = {'+', '-', '*', '/'};

	for(int i = 0; i < str.size(); i++) {
		if(find(begin(ops), end(ops), str[i]) != end(ops)) {
			if(tmp.at(0) != "") {
				tmp.push_back(string(1, str[i]));
			}else {
				tmp.at(0) = string(1, str[i]);
			}
		}else {
			tmp.at(tmp.size()-1) += str[i];}
		}	
	Equation out = Equation();
	out.init();

	char sign;
	string snum;
	double num;

	for(string var: tmp) {

		sign = var[0];
		for(int i = 1; i < var.size(); i++) {snum += var[i];}
		try {
			num = stod(snum);
		}catch(invalid_argument Err) {
			try {
				num = stoi(snum);
			}catch(invalid_argument err) {}
		}
		out.add(sign, num);
		sign = char();
		snum = "";
	}
	equ = out;

	output = solve(equ);
}
double Eval::solve(Equation _equ) {

	vector<Term> *cnt = _equ.get_content();

	// spaghetti code
	switch(cnt->at(1).sign) {
		case '+': {if(cnt->size() < 3) {return (double)(cnt->at(0).num + cnt->at(1).num);}
			else {return (double)(cnt->at(0).num + solve(_equ.rtrunk()));}}break;
		case '-': {if(cnt->size() < 3) {return (double)(cnt->at(0).num - cnt->at(1).num);}
			else {return (double)(cnt->at(0).num - solve(_equ.rtrunk()));}}break;
		case '*': {if(cnt->size() < 3) {return (double)(cnt->at(0).num * cnt->at(1).num);}
			else {return (double)(cnt->at(0).num * solve(_equ.rtrunk()));}}break;
		case '/': {if(cnt->size() < 3) {return (double)(cnt->at(0).num / cnt->at(1).num);}
			else {return (double)(cnt->at(0).num / solve(_equ.rtrunk()));}}break;
		default: 
			throw(GenX());
	}
}