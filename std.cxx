#include <cmath>
#include <cstdio>
#include "std.h"
#include "error.h"
#include "machine.h"

namespace neem {

class_t* std_string::cls = nullptr;
class_t* std_array::cls = nullptr;
class_t* std_map::cls = nullptr;	

void std_abs(size_t argc, value *argv, value &retval)
{
	machine::match(argc, 1);
	value v = argv[0];
	switch (v.type) {
	case DataType::I64: retval = value(std::abs(v.i64)); break;
	case DataType::F64: retval = value(std::abs(v.f64)); break;
	default: machine::report(ERROR_NUMERIC_TYPE);
	}
}

void std_sin(size_t argc, value *argv, value &retval)
{
	machine::match(argc, 1);
	value v = argv[0];
	switch (v.type) {
	case DataType::I64: retval = value(std::sin(v.i64)); break;
	case DataType::F64: retval = value(std::sin(v.f64)); break;
	default: machine::report(ERROR_NUMERIC_TYPE);
	}
}

void std_cos(size_t argc, value *argv, value &retval)
{
	machine::match(argc, 1);
	value v = argv[0];
	switch (v.type) {
	case DataType::I64: retval = value(std::cos(v.i64)); break;
	case DataType::F64: retval = value(std::cos(v.f64)); break;
	default: machine::report(ERROR_NUMERIC_TYPE);
	}
}

void std_tan(size_t argc, value *argv, value &retval)
{
	machine::match(argc, 1);
	value v = argv[0];
	switch (v.type) {
	case DataType::I64: retval = value(std::tan(v.i64)); break;
	case DataType::F64: retval = value(std::tan(v.f64)); break;
	default: machine::report(ERROR_NUMERIC_TYPE);
	}
}

void std_print(size_t argc, value *argv, value &retval)
{
	retval = value(int64_t(argc));
	for (int i = 0; i < argc; ++i)
		machine::print(stdout, argv[i]);
}

void std_println(size_t argc, value *argv, value &retval)
{
	retval = value(int64_t(argc));
	for (int i = 0; i < argc; ++i)
		machine::print(stdout, argv[i]);
	std::printf("\n");
}



std_string::std_string() : class_def("String")
{
	std_string::cls = this;
	register_native("String", ctor);
	register_native("length", length);
	register_native("empty", empty);
	register_native("slice", slice);
}

void std_string::ctor(size_t argc, value *argv, value &retval)   {}

void std_string::length(size_t argc, value *argv, value &retval)
{
	machine::match(argc, 0);
	//retval = value(argv[1].str->length());
}

void std_string::empty(size_t argc, value *argv, value &retval)
{
	machine::match(argc, 0);
	//retval = value(argv[1].str->empty());	
}

void std_string::slice(size_t argc, value *argv, value &retval)
{

}

std_array::std_array() : class_definition("Array")
{
	std_array::cls = this;
	register_native("of", of);
	register_native("Array", ctor);
	register_native("size", size);
	register_native("literal", literal);
}

void std_array::of(size_t argc, value *argv, value &retval)
{
	
}

void std_array::ctor(size_t argc, value *argv, value &retval)
{
	//if (argc == 0)
	//	retval = value(new array());
	//else if (argc == 1 && argv->type == DataType::I64)
	//	retval = value(new array(argv->i64));
	//else machine::except(Error::InvalidArrayArg);
}

void std_array::size(size_t argc, value *argv, value &retval)
{
	machine::match(argc, 0);
	//retval = value(argv[1].arr->size());
}

void std_array::literal(size_t argc, value *argv, value &retval)
{
}

std_map::std_map() : class_def("Map")
{
	std_map::cls = this;
	register_native("of", of);
	register_native("Map", ctor);
	register_native("empty", empty);
	register_native("size", size);
	register_native("insert", insert);
	register_native("find", find);
	register_native("contains", contains);
	register_native("literal", literal);
}

void std_map::of(size_t argc, value *argv, value &retval) {}
void std_map::ctor(size_t argc, value *argv, value &retval) {}
void std_map::empty(size_t argc, value *argv, value &retval) {}
void std_map::size(size_t argc, value *argv, value &retval) {}
void std_map::insert(size_t argc, value *argv, value &retval) {}
void std_map::find(size_t argc, value *argv, value &retval) {}
void std_map::contains(size_t argc, value *argv, value &retval) {}
void std_map::literal(size_t argc, value *argv, value &retval) {}

}

