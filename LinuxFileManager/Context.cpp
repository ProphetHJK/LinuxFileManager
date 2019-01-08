#include"Context.h"
Context::Context()
{
	str = "";
}
void Context::setStr(string tmp)
{
	str = tmp;
}
string *Context::getStr()
{
	return &str;
}
long Context::getSize()
{
	return sizeof(str)*1024;
}