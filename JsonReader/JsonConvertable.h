#ifndef JSONCONVERTABLE
#define JSONCONVERTABLE
#include "JSONEntity.h"
#include <iostream>
/**
 * @brief
 * Virtual class used to declared an object convertible from and to the json format.
 */
class JsonConvertable
{
	public:
		JsonConvertable();
		/**
		 * @brief
		 *Base function to convert the object to the json format.
		 * @return std::string
		 */
		virtual std::string toJson();
		/**
		 * @brief
		 * Base function to initialize an object from a JSONEntity.
		 * @param e 
		 */
		virtual void fromJson(JSONEntity* e);
};
#endif