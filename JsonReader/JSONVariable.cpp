#include "JSONVariable.h"
		  JSONVariable::JSONVariable(std::string s,JSONTYPE T)
		  {
			  name = s;
			  m_type = T;
			  value = NULL;
		  }
		  JSONVariable::JSONVariable()
		  {

		  }
void JSONVariable::assign(JSONEntity *entity)
{
		value = entity;
}

JSONEntity &JSONVariable::operator[](std::string s)
{
	return *this;
}
JSONEntity & JSONVariable::operator[](unsigned int i)
{
	return *this;
}
size_t JSONVariable::getSize()
{
	return 1;
}

std::string JSONVariable::getValue()
{
	if (value == NULL)
		return name;
	else
		return value->getValue();
}