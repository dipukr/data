#pragma once
#include <string>
#include <vector>
#include "astnode.h"

class code_emitter : private statement_visitor, expression_visitor
{
	
	code_emitter(vector<statement*> &statements);
	void emit();

	void visit(ast::classstat    *ast) override;
	void visit(ast::funcstat     *ast) override;
	void visit(ast::varstat      *ast) override;
	void visit(ast::blockstat    *ast) override;
	void visit(ast::ifstat       *ast) override;
	void visit(ast::whilestat    *ast) override;
	void visit(ast::repeatstat   *ast) override;
	void visit(ast::forstat      *ast) override;
	void visit(ast::foreverstat  *ast) override;
	void visit(ast::breakstat    *ast) override;
	void visit(ast::continuestat *ast) override;
	void visit(ast::returnstat   *ast) override;
	void visit(ast::assertstat   *ast) override;
	void visit(ast::exprstat     *ast) override;
	void visit(ast::negation     *ast) override;
	void visit(ast::increment    *ast) override;
	void visit(ast::decrement    *ast) override;
	void visit(ast::addition     *ast) override;
	void visit(ast::subtract     *ast) override;
	void visit(ast::multiply     *ast) override;
	void visit(ast::division     *ast) override;
	void visit(ast::modulus      *ast) override;
	void visit(ast::shiftleft    *ast) override;
	void visit(ast::shiftright   *ast) override;
	void visit(ast::bitwor       *ast) override;
	void visit(ast::bitwxor      *ast) override;
	void visit(ast::bitwand      *ast) override;
	void visit(ast::bitwnot      *ast) override;
	void visit(ast::equal        *ast) override;
	void visit(ast::notequal     *ast) override;
	void visit(ast::lessthan     *ast) override;
	void visit(ast::lessequal    *ast) override;
	void visit(ast::greaterthan  *ast) override;
	void visit(ast::greaterequal *ast) override;
	void visit(ast::logor        *ast) override;
	void visit(ast::logand       *ast) override;
	void visit(ast::lognot       *ast) override;
	void visit(ast::dot          *ast) override;
	void visit(ast::call         *ast) override;
	void visit(ast::subscript    *ast) override;
	void visit(ast::assign       *ast) override;
	void visit(ast::null         *ast) override;
	void visit(ast::true1        *ast) override;
	void visit(ast::false0       *ast) override;
	void visit(ast::integer      *ast) override;
	void visit(ast::number       *ast) override;
	void visit(ast::string       *ast) override;
	void visit(ast::identifier   *ast) override;
	
	int codemitter::addsym(const string &sym);
	int codemitter::addlit(const value &v);
	
	void emit(uint16_t opcode);
	void emit(uint16_t opcode, uint16_t operand);
	void fixup(uint32_t chain, uint32_t operand);
	void resolve(uint32_t dest, uint32_t operand);
	void pushcontinuelabel(uint32_t label);
	void popcontinuelabel();
	void pushbreaklabel(uint32_t label);
	uint32_t popbreaklabel(uint32_t oldlbl);

	std::vector<ast::node*> ast;

	bool lval;

	uint32_t bsp;
	uint32_t csp;

	uint32_t *bstack;
	uint32_t *cstack;

	std::vector<uint16_t> init;
	std::vector<uint16_t> code;
	std::vector<value> globals;
	std::vector<value> constants;
	std::map<std::string, int> symtab;
};
