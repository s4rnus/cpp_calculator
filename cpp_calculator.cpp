#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


using String = std::string;

template<typename T>
using Vector = std::vector<T>;

template<typename T, typename N>
using PairedVector = std::vector<std::pair<T, N>>;

template<typename T, typename N>
using Map = std::unordered_map<T, N>


constexpr char spacebar = ' ';
constexpr char parenth = '(';
constexpr char multiplication = '*';
constexpr char division = '/';
constexpr char plus = '+';
constexpr char minus = '-';


int fwparenth_counter = 0;
int bcparenth_counter = 0;
double result;


PairedVector<char, int> priority_operators;
PairedVector<char, int> regular_operators;
PairedVector<char, int> order_of_execution;
Vector<char> expression_disected;

String expression;

//тут функции-драйверы для математики
//
//тут функции-драйверы для математики

String getexpression(String expression) {

	while (expression.empty()) {
		std::cout << '\n' << "Enter an expression: ";
		std::getline(std::cin, expression);
	}
	return expression;
}


Vector<char> disect_expression(const String& expression) {
	Vector<char> expressions_disected(expression.begin(), expression.end());
	return expression_disected;
}


bool priority_check(String expression) {
	return expression.find(parenth) != String::npos || expression.find(multiplication) != String::npos || expression.find(division) != String::npos;
}


void priority_operator_search(Vector<char>& expression_disected, PairedVector<char, int>& priority_operators) {

	for (int i = 0; i < expression_disected.size(); i++) {
		char op = expression_disected[i];
		if (op == char{ '(' } || op == char{ ')' } || op == multiplication || op == division) {

			priority_operators.push_back({ op, i });

			switch (op) {
			case '(':
				fwparenth_counter++;
				break;
			case ')':
				bcparenth_counter++;
				break;
			}
		}
	}
}


void regular_operator_search(Vector<char>& expression_disected, PairedVector<char, int>& regular_operators) {

	for (int i = 0; i < expression_disected.size(); i++) {
		char op = expression_disected[i];
		if (op == plus || op == minus) {

			regular_operators.push_back({ op, i });
		}
	}
}


void order_determination(String expression, PairedVector<char, int>& priority_operators, PairedVector<char, int>& regular_operators, Vector<char>& expression_disected) {

	if (priority_check(expression) == true) {

		if (fwparenth_counter == 0) {

			for (int i = 0; i < priority_operators.size(); i++) {

				order_of_execution.push_back(priority_operators[i]);

			}

			for (int i = 0; i < regular_operators.size(); i++) {

				order_of_execution.push_back(regular_operators[i]);

			}

		}
		
		else {

			while (fwparenth_counter > 0) {

				for ()

			}

		}

	}

}


int main()
{

	std::cout << '\n' << "Enter an expression: ";
	std::getline(std::cin, expression);
	

	if (expression.empty()) {
		expression = getexpression(expression);
	}

	return 0;
}
