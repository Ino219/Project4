#pragma once

namespace Project4 {

	using namespace System;
	using namespace System::Collections::Generic;

	ref class calc
	{
	private:
		//List<double>^ val_list;
		//List<String^>^ op_list;
	public:
		double calc_2(double a, String^ op, double b);
		double total_calc(List<double>^ list1, List<String^>^ list2);
	};
}
