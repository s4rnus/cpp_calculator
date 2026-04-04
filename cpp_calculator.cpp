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
using Map = std::unordered_map<T, N>;


constexpr char spacebar = ' ';
constexpr char parenth = '(';
constexpr char multiplication = '*';
constexpr char division = '/';
constexpr char plus = '+';
constexpr char minus = '-';


int parenth_counter = 0;
double result;


Map<char, int> priority_operators;
PairedVector<char, int> regular_operators;
PairedVector<char, int> parenthesises;
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


void priority_operator_search(Vector<char>& expression_disected, Map<char, int>& priority_operators, PairedVector<char, int> parenthesises) {

	for (int i = 0; i < expression_disected.size(); i++) {

		char op = expression_disected[i];

		if (op == char{ '(' } || op == char{ ')' }) {

			parenthesises.push_back({ op, i });

			parenth_counter++;
		}

		else if (op == multiplication || op == division) {
			priority_operators.emplace( op, i );
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


void order_determination(String expression, Map<char, int>& priority_operators, PairedVector<char, int>& regular_operators, Vector<char>& expression_disected, PairedVector<char, int>& parenthesises) {

	if (priority_check(expression) == true) {

		if (parenth_counter == 0) {

			for (int i = 0; i < priority_operators.size(); i++) {

				order_of_execution.push_back({ priority_operators[i].first, priority_operators[i].second});

			}

			for (int i = 0; i < regular_operators.size(); i++) {

				order_of_execution.push_back(regular_operators[i]);

			}

		}
		
		else {

			while (parenth_counter > 0) {

				for (int i = 0, n = 1; i < parenth_counter; i++, n++) {

					if (parenthesises[i].first == char{ '(' } and parenthesises[n].first == char{ '(' }) {
						continue;
					}
					
					else if (parenthesises[i].first == char{ '(' } and parenthesises[n].first == char{ ')' }) {

						for (int x = parenthesises[i].second; x < parenthesises[n].second; x++) {



						}

					}


				}

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
