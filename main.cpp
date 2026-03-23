#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

enum Type{VAR, NOT, AND, OR, IMP, EQU, LPAREN, RPAREN};
struct Token { Type type; char c; };
struct Var { char c; bool bit; };

bool BitWiser(Type type, bool a, bool b) {
	switch (type)
	{
	case AND: return a && b;
	case OR: return a || b;
	case IMP: return !a || b;
	case EQU: return a == b;

	default:
		return false;
	}
}

bool EvaluateRPN(vector<Token>& ptokens, vector<Var>& vars) {

	vector<bool> stack;
	for (unsigned int i = 0; i < ptokens.size(); i++) {
		if (ptokens[i].type == VAR) {
			for (auto& v : vars) {
				if (ptokens[i].c == v.c) { stack.push_back(v.bit); break; };
			}
 
		}
		else if (ptokens[i].type == NOT) {
			bool bit = stack.back();
			stack.pop_back(); stack.push_back(!bit);

		}
		else {

			bool b = stack.back(); stack.pop_back();
			bool a = stack.back(); stack.pop_back();
			stack.push_back(BitWiser(ptokens[i].type, a, b));

		}

	}
	return stack.back();
}

int Precedence(Type type) {

	switch (type) {

	case NOT: return 4;
	case AND: return 3;
	case OR: return 2;
	case IMP: return 1;
	case EQU: return 0;
	default: return -1;

	}

}

vector<Token> RPN(const vector<Token>& tokens) {

	vector<Token> output;
	vector<Token> stack;

	for (auto& token : tokens) {

		if (token.type == VAR)output.push_back(token);
		else if (token.type == NOT || token.type == AND || token.type == OR || token.type == IMP || token.type == EQU) {

			while (!stack.empty() && Precedence(stack.back().type) >= Precedence(token.type)) {

				output.push_back(stack.back());
				stack.pop_back();


			}
			stack.push_back(token);

		}
		else if (token.type == LPAREN)stack.push_back(token);
		else if (token.type == RPAREN) {

			while (!stack.empty() && stack.back().type != LPAREN) {
				output.push_back(stack.back());
				stack.pop_back();

			}
			stack.pop_back();

		}
	}


	while (!stack.empty()) {
		output.push_back(stack.back());
		stack.pop_back();

	}

	return output;

}

vector<Token> Tokenize(string expr) {
	
	vector<Token> tokens = {};

	for (unsigned int i = 0; i < expr.size(); i++) {

		char c = expr[i];

		if (isblank(c))continue;
		else if (isalpha(c))tokens.push_back({ VAR, c });
        else if (c == '~')tokens.push_back({ NOT, 0 });
		else if (c == '&')tokens.push_back({ AND, 0 });
		else if (c == '|')tokens.push_back({ OR, 0 });
		else if (c == '(')tokens.push_back({ LPAREN, 0 });
		else if (c == ')')tokens.push_back({ RPAREN, 0 });
        else if (c == '-' && i + 1 < expr.size() && expr[i + 1] == '>') { tokens.push_back({ IMP, 0 }); i++; }
		else if (c == '=' && i + 1 < expr.size() && expr[i + 1] == '=') { tokens.push_back({ EQU, 0 }); i++; }

		


	}

	return tokens;


}

int main() {

	string expr;
	getline(cin, expr);
	cout << endl;

	auto tokens = Tokenize(expr);
	auto ptokens = RPN(tokens);

	set<char> temp_varlist = {};
	for (auto& var : ptokens) {
		if (var.type == VAR)temp_varlist.insert(var.c);
	}

	vector<char>varlist(temp_varlist.begin(), temp_varlist.end());

	for (auto& var : varlist) {
		cout << var << " ";
	}
	
	cout << "   Final" << endl;

	for (unsigned int i = 0; i < (1 << varlist.size()); i++) {
		vector<Var>vars = {};
		for (unsigned int j = 0; j < varlist.size(); j++) {

			vars.push_back({ varlist[j], static_cast<bool>((i >> j) & 1) });
			cout << vars[j].bit << " ";

		}


		
		cout << " | " << EvaluateRPN(ptokens, vars) << endl;


	}


	return 0;
}
