#include "Entry.h"

Entry::Entry() : key(), value() {}
Entry::Entry(const string& k, const int& v) { key = k; value = v; }