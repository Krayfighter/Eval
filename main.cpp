#include <iostream>
// #include <chrono>
#include "eval.hpp"

using namespace std;
// using namespace std::chrono;

int main() {

	// Eval equ = Eval("3*2+4/6");
	// cout << equ.get_out() << endl;

	while(1) {
		string input;
		cout << "enter equation: ";
		cin >> input;
		if(input == "exit") {
			break;
		}else {
			cout << Eval(input).get_out() << endl;
			continue;
		}
	}
	return 0;

}
