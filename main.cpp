#include <iostream>
#include <vector>

using namespace std;

struct Term {
	char sign;
	float num;
	Term(char s, float n) {
		sign = s;
		num = n;
	}
};

class Equation {
	vector<Term> content;
	int iter = 0;
	public:
		add(char sign, float num) {
			content.pushback(Term(sign, num));
		}
}

int main()
{
	cout << "Hello World";

	return 0;
}
