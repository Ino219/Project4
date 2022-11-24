#include "calc.h"
#include<cmath>

using namespace Project4;
using namespace System::Windows::Forms;

double calc::calc_2(double a, String^ op, double b) {
	if (op == "+") {
		return a + b;
	}
	else if (op == "-") {
		return a - b;
	}
	else if (op == "*") {
		return a * b;
	}
	else if (op == "/") {
		return a / b;
	}
	else if (op == "%") {
		return fmod(a, b);
	}
	else {
		return 0;
	}
}

double calc::total_calc(List<double>^ list1, List<String^>^ list2) {
	double res;
		for (int i = 0; i < list1->Count - 1; i++) {
			res = calc_2(list1[i], list2[i], list1[i + 1]);
			list1[i + 1] = res;
		}
	return res;
}