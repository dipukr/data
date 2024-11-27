#include "emitter.h"
#include <iostream>

codemitter::codemitter(std::vector<ast::node*> &ast) : ast(ast) {
	this->bsp = -1;
	this->csp = -1;
	this->ip = 0;
	this->lval = false;
	this->globals.reserve(100);
	this->constants.reserve(100);
}

void codemitter::emit() {
	
}

int codemitter::emit(int opc) {

}

int codemitter::emit(int opc, int opr) {

}

void codemitter::resolve(uint32_t dest, uint32_t operand) {
	code[dest] = operand;
}

void codemitter::fixup(uint32_t chain, uint32_t operand) {
	while (chain) {
		next = code[chain];
		code[chain] = operand;
		chain = next;
	}
}

void codemitter::pushcontinuelabel(uint32_t label) {
	cstack[++csp] = label;
}

void codemitter::popcontinuelabel() {
	--csp;
}

void codemitter::pushbreaklabel(uint32_t label) {
	bstack[++bsp] = label;
}

uint32_t codemitter::popbreaklabel(uint32_t oldlbl) {
	uint32_t result = bstack[bsp];
	--bsp;
	return result;
}

int codemitter::addsym(const string &sym) {
	auto it = symtab.find(sym);
	if (it != symtab.end())
		return it->second;
	int val = symtab.size();
	symtab.insert(pair<string, int>(sym, val));
	return val;
}

int codemitter::addlit(const value &v) {
	int constantc = constants.size();
	for (int i = 0; i < constantc; ++i)
		if (constants[i] == v)
			return i;
	constants.push_back(v);
	return constantc;
}

void codemitter::visit(ast::classstat *ast) {
	
}

void codemitter::visit(ast::funcstat *ast) {
	
}

void codemitter::visit(ast::varstat *ast) {
	
}

void codemitter::visit(ast::blockstat *ast) {
	
}

void codemitter::visit(ast::ifstat *ast) {
	
}

void codemitter::visit(ast::whilestat *ast) {
	
}

void codemitter::visit(ast::repeatstat *ast) {
	
}

void codemitter::visit(ast::forstat *ast) {
	
}

void codemitter::visit(ast::foreverstat *ast) {
	
}

void codemitter::visit(ast::breakstat    *ast) {
	
}

void codemitter::visit(ast::continuestat *ast) {
	
}

void codemitter::visit(ast::returnstat *ast) {
	
}

void codemitter::visit(ast::assertstat *ast) {
	
}

void codemitter::visit(ast::exprstat *ast) {
	
}

void codemitter::visit(ast::negation *ast) {
	
}

void codemitter::visit(ast::increment *ast) {
	
}

void codemitter::visit(ast::decrement *ast) {
	
}

void codemitter::visit(ast::addition *ast) {
	
}

void codemitter::visit(ast::subtract *ast) {
	
}

void codemitter::visit(ast::multiply *ast) {
	
}

void codemitter::visit(ast::division *ast) {
	
}

void codemitter::visit(ast::modulus *ast) {
	
}

void codemitter::visit(ast::shiftleft *ast) {
	
}

void codemitter::visit(ast::shiftright *ast) {
	
}

void codemitter::visit(ast::bitwor *ast) {
	
}

void codemitter::visit(ast::bitwxor *ast) {
	
}

void codemitter::visit(ast::bitwand *ast) {
	
}

void codemitter::visit(ast::bitwnot *ast) {
	
}

void codemitter::visit(ast::equal *ast) {
	
}

void codemitter::visit(ast::notequal *ast) {
	
}

void codemitter::visit(ast::lessthan *ast) {
	
}

void codemitter::visit(ast::lessequal *ast) {
	
}

void codemitter::visit(ast::greaterthan *ast) {
	
}


void codemitter::visit(ast::greaterequal *ast) {
	
}

void codemitter::visit(ast::logor *ast) {
	
}

void codemitter::visit(ast::logand *ast) {
	
}

void codemitter::visit(ast::lognot *ast) {
	
}

void codemitter::visit(ast::dot *ast) {
	
}

void codemitter::visit(ast::call *ast) {
	
}

void codemitter::visit(ast::subscript *ast) {
	
}

void codemitter::visit(ast::assign *ast) {
	
}

void codemitter::visit(ast::null *ast) {
	
}

void codemitter::visit(ast::true1 *ast) {
	
}

void codemitter::visit(ast::false0 *ast) {
	
}

void codemitter::visit(ast::integer *ast) {
	
}

void codemitter::visit(ast::number *ast) {
	
}

void codemitter::visit(ast::string *ast) {
	
}


void codemitter::visit(ast::identifier *ast) {
	
}
