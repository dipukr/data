#include <string.h>
#include <stdio.h>
#include "hash.h"
#include "struct.h"

namespace neem {

hash_table::hash_table()
{
	this->count = 0;
	this->bucketc = 10;
	this->buckets = new node*[bucketc];
	for (auto i(0); i < bucketc; ++i)
		buckets[i] = nullptr;
}

size_t hash_table::hash(const char *key)
{
	size_t h = 0;
	size_t len = strlen(key);
	for (int i(0); i < len; ++i)
		h = 31 * h + key[i];
	return (h & 0x7fffffff);
}

int hash_table::hash(const value &val)
{
	if (val.type == Data::STR)
		return hash(val.str->data.cstr());
	return val.i64;
}

bool hash_table::insert(const value &key, const value &val)
{
	if (contains(key)) return false;
	node *n = new node;
	n->key = key;
	n->val = val;
	int i = hash(key) % bucketc;
	n->next = buckets[i];
	buckets[i] = n;
	count++;
	return true;
}

value hash_table::find(const value &key)
{
	int i = hash(key) % bucketc;
	for (node *it = buckets[i]; it != nullptr; it = it->next)
		if (it->key == key)
			return it->val;
	return value::null_value;
}

bool hash_table::contains(const value &key)
{
	int i = hash(key) % bucketc;
	for (node *it = buckets[i]; it != nullptr; it = it->next)
		if (it->key == key)
			return true;
	return false;
}

size_t hash_table::size() const
{
	return count;
}

bool empty() const
{
	return count == 0;
}

}
