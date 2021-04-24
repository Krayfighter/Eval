#include <iostream>
#include "eval.hpp"

using namespace std;


int main() {

	Eval equ = Eval("-3*2+4/6");
	cout << equ.get_out() << endl;

}
