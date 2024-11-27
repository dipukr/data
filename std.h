#ifndef NEEM_STD_H
#define NEEM_STD_H

#include "struct.h"
#include "value.h"
#include "map.h"

namespace neem {

void std_abs(size_t argc, value *argv, value &retval);
void std_sin(size_t argc, value *argv, value &retval);
void std_cos(size_t argc, value *argv, value &retval);
void std_tan(size_t argc, value *argv, value &retval);
void std_print(size_t argc, value *argv, value &retval);
void std_println(size_t argc, value *argv, value &retval);

struct std_string : class_def
{
	std_string();
	static class_def *cls;
	static void ctor(int argc, value *argv, value &retval);
	static void length(int argc, value *argv, value &retval);
	static void empty(int argc, value *argv, value &retval);
	static void slice(int argc, value *argv, value &retval);
};

struct std_array : class_def
{
	std_array();
	static class_def *cls;
	static class_def *get_class() {return cls;}
	static void of(int argc, value *argv, value &retval);
	static void ctor(int argc, value *argv, value &retval);
	static void size(int argc, value *argv, value &retval);
	static void literal(int argc, value *argv, value &retval);
};

struct std_map : class_def
{
	struct object : thing
	{
		map_t data;
		object() {}
		~object() {}
		virtual class_def *get_class() {return cls;}
		virtual size_t allocs() {return sizeof(object);}
	};

	std_map();
	static clas_s *cls;
	static void of(int argc, value *argv, value &retval);
	static void ctor(int argc, value *argv, value &retval);
	static void size(int argc, value *argv, value &retval);
	static void empty(int argc, value *argv, value &retval);
	static void insert(int argc, value *argv, value &retval);
	static void find(int argc, value *argv, value &retval);
	static void contains(int argc, value *argv, value &retval);
	static void literal(int argc, value *argv, value &retval);
};

}

#endif
