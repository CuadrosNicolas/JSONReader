#include "JSONArray.h"
JSONArray::JSONArray()
{
	m_type = JSONTYPE::ARRAY;
}
std::vector<JSONEntity *> *JSONArray::getArray()
{
	return &value;
}
std::string JSONArray::getValue()
{
	std::string out;
	out += "[";
	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i]->getType() == JSONTYPE::VAR_STRING)
			out += "\"" + value[i]->getValue() + "\",";
		else
			out += value[i]->getValue() + ",";
	}
	out[out.size() - 1] = ']';
	return out;
}
size_t JSONArray::getSize()
{
	return value.size();
}
void JSONArray::assign(JSONEntity *entity)
{
	value.push_back(entity);
}
JSONEntity &JSONArray::operator[](std::string s)
{
	return *this;
}
JSONEntity & JSONArray::operator[](unsigned int i)
{
	return *value[i];
}