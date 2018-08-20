#include "JSONEntity.h"
JSONEntity::JSONEntity()
{

}
void JSONEntity::assign(JSONEntity *entity)
{

}
 JSONEntity& JSONEntity::operator[](std::string s)
{
	throw BadAccessObject();
}
 JSONEntity & JSONEntity::operator[](unsigned int i)
{
	throw BadAccessArray();
}
size_t JSONEntity::getSize()
{
	return 0;
}
std::vector<JSONEntity *> *JSONEntity::getArray()
{
	throw NotConvertableToArray();
}
std::map<std::string, JSONEntity *> *JSONEntity::getMap()
{
	throw NotConvertableToMap();
}
std::string JSONEntity::getValue()
{
	return "";
}
void JSONEntity::print(std::ostream &O)
{
	O << this->getValue();
}
JSONTYPE JSONEntity::getType()
{
	return m_type;
}
std::ostream &operator<<(std::ostream &flow, JSONEntity &e)
{
	flow << e.getValue();
	return flow;
}

int JSONEntity::toint()
{
	if (getType() == VAR_NUMBER)
		return std::stoi(getValue());
	else
	{
		throw NotConvertableToInt();
	}
}
float JSONEntity::tofloat()
{
	if (getType() == VAR_NUMBER){
		return std::stof(getValue());
	}
	else{
		throw NotConvertableToFloat();
	}
}
double JSONEntity::todouble()
{
	if (getType() == VAR_NUMBER)
		return std::stof(getValue());
	else
		{
			throw NotConvertableToDouble();
		}
}
std::string JSONEntity::tostring()
{
	if (getType() == VAR_STRING)
		return getValue();
	else
		return "";
}
bool JSONEntity::tobool()
{
	if(getType()==VAR_BOOL)
	{
		if(getValue()=="true")
			return true;
		if(getValue()=="false")
			return false;
	}
	throw NotConvertableToBool();
}