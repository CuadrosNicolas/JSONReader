#include "JSONObject.h"
JSONObject::JSONObject()
{
	m_type = JSONTYPE::OBJECT;
}
void JSONObject::assign(JSONEntity *entity)
{
	value[((JSONVariable *)entity)->name] = ((JSONVariable *)entity)->value;
}

JSONEntity &JSONObject::operator[](std::string s)
{
	return *value[s];
}
JSONEntity &JSONObject::operator[](unsigned int i)
{
	return *this;
}
std::map<std::string, JSONEntity *> *JSONObject::getMap()
{
	return &value;
}
std::string JSONObject::getValue()
{
	std::map<std::string, JSONEntity *>::iterator it;
	std::string out;
	out += "{";
	for (it = value.begin(); it != value.end(); it++)
	{
		out += "\"" + it->first + "\" : ";
		if (value[it->first]->getType() == JSONTYPE::VAR_STRING)
		{
			out += "\"" + value[it->first]->getValue() + "\",";
		}
		else
		{
			out += " " + value[it->first]->getValue() + ",";
		}
	}
	out[out.size() - 1] = '}';
	return out;
}
size_t JSONObject::getSize()
{
	return value.size();
}