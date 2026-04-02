#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>


const char spacebar = { ' ' };
const char parenth = { '(' };
const char multiplication = { '*' };
const char division = { '/' };
const char plus = { '+' };
const char minus = { '-' };


static int fwparenth_counter = 0;
static int bcparenth_counter = 0;


std::vector<std::pair<char, int>> priority_operators;
std::vector<std::pair<char, int>> regular_operators;
std::vector<std::pair<char, int>> numbers;
std::vector<int> order_of_execution;
std::string expression;
static double result;


std::string getexpression(std::string expression) {

	while (expression.empty()) {
		std::cout << '\n' << "Enter an expression: ";
		std::getline(std::cin, expression);
	}
	return expression;

}


std::vector<char> expression_disected(expression.begin(), expression.end());


bool priority_check(std::string expression) {
	return expression.find(parenth) != std::string::npos || expression.find(multiplication) != std::string::npos || expression.find(division) != std::string::npos;
}


void priority_operator_search(std::vector<char>& expression_disected, std::vector<std::pair<char, int>>& priority_operators) {

	for (int i = 0; i < expression_disected.size(); i++) {
		if (expression_disected[i] == char{ '(' } || expression_disected[i] == char{ ')' } || expression_disected[i] == multiplication || expression_disected[i] == division) {

			const char x = expression_disected[i];

			switch (x) {
			case '(':
				fwparenth_counter++;
				break;
			case ')':
				bcparenth_counter++;
				break;
			}

			priority_operators.push_back({ expression_disected[i], i });
			expression_disected.erase(expression_disected.begin() + i);
		}
	}
}


void regular_operator_search(std::vector<char>& expression_disected, std::vector<std::pair<char, int>> regular_operators) {

	for (int i = 0; i < expression_disected.size(); i++) {
		if (expression_disected[i] == plus || expression_disected[i] == minus) {

			regular_operators.push_back({ expression_disected[i], i });
			expression_disected.erase(expression_disected.begin() + i);
		}
	}
}


void order_determination(std::vector<char>& expression_disected, std::vector<std::pair<char, int>>& priority_operators, std::vector<std::pair<char, int>> all_operators) {}


int main()
{

	std::cout << '\n' << "Enter an expression: ";
	std::getline(std::cin, expression);
	

	if (expression.empty()) {
		expression = getexpression(expression);
	}

	return 0;
}
