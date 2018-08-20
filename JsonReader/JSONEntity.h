#ifndef JSONENTITY
#define JSONENTITY
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "JSONException.h"
/**
 * @brief
 *
 */
enum JSONTYPE{ARRAY,VAR_NUMBER,VAR_STRING,VAR_BOOL,VAR_NULL,VAR_CONTAINER,OBJECT};
/**
 * @brief Base class for creating JSON Entity.
 *
 */
class JSONEntity
{
	public:
		JSONEntity();
		/**
		 * @brief Assign a JSONEntity to an other.
		 *
		 * @param entity
		 */
		virtual void assign(JSONEntity* entity);
		virtual JSONEntity& operator[](std::string s);
		virtual JSONEntity& operator[](unsigned int i);
		virtual size_t getSize();
		virtual std::vector<JSONEntity*>* getArray();
		virtual std::map<std::string,JSONEntity *> *getMap();
		virtual std::string getValue();
		virtual void print(std::ostream &O);
		/**
		 * @brief Get the Type object
		 *
		 * @return JSONTYPE
		 */
		virtual JSONTYPE getType();
		virtual int toint();
		virtual float tofloat();
		virtual double todouble();
		virtual std::string tostring();
		virtual bool tobool();
	protected:
	  JSONTYPE m_type;
};
/**
 * @brief
 * 
 * @param flow 
 * @param e 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& flow,JSONEntity& e);
#endif