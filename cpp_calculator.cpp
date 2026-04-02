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


std::vector<int> order_of_execution;
std::vector<std::pair<char, int>> priority_operators;
std::vector<std::pair<char, int>> all_operators;
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


void operator_search(std::vector<char>& expression_disected, std::vector<std::pair<char, int>>& priority_operators, std::vector<std::pair<char, int>> all_operators) {

	int fwparenth_counter = 0;
	int bcparenth_counter = 0;

	for (int i = 0; i < expression_disected.size(); i++) {
		if (expression_disected[i] == char{ '(' } || expression_disected[i] == char{ ')' } || expression_disected[i] == multiplication || expression_disected[i] == division) {
			priority_operators.push_back({ expression_disected[i], i });

			const char x = expression_disected[i];

			switch (x) {
			case '(':
				fwparenth_counter++;
				break;
			case ')':
				bcparenth_counter++;
				break;
			}
		}
	}

	for (int i = 0; i < expression_disected.size(); i++) {
		if (expression_disected[i] == plus || expression_disected[i] == minus || expression_disected[i] == multiplication || expression_disected[i] == division) {
			all_operators.push_back({ expression_disected[i], i });
		}
	}
}


void arrange_priority(std::vector<char>& expression_disected, std::vector<std::pair<char, int>>& priority_operators, std::vector<std::pair<char, int>> all_operators) {
	

	for (int i = 0; i < expression_disected.size(); i++) {

		const char op = priority_operators[i].first;

		switch (op) {
			case '*' || '/':
				
				
		}
	}

}




int main()
{


	if (priority_check(expression)) {
		arrange_priority(expression_disected, priority_operators);
	}

	std::cout << '\n' << "Enter an expression: ";
	std::getline(std::cin, expression);
	

	if (expression.empty()) {
		expression = getexpression(expression);
	}


	for (char charachter : expression) {
		expression_disected.push_back(charachter);
	}

	if (priority_check(expression) == true) {
		arrange_priority(expression_disected, priority_operators);
	}

	return 0;
}
