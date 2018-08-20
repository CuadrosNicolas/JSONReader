#ifndef JSONPARSER
#define JSONPARSER
#include "JSONException.h"
#include "JSONEntity.h"
#include "JSONArray.h"
#include "JSONObject.h"
#include "JSONVariable.h"
#include <stack>
#include <fstream>
#include <iostream>
class JSONParser
{
	public:
		JSONParser(std::string file);
		JSONEntity *parse();

	  protected:
	  /**
	   * @brief
	   * Defines all states that can take the parser
	   */
		enum state
		{
			A,
			B,
			C,
			D,
			E,
			F,
			G
		};
		std::string m_file;
		std::string buffer;
		char c;
		std::stack<JSONEntity*> stack;
		state s;
		/**
		 * @brief add a jsonObject to the stack
		 *
		 */
		void createObject();
		/**
		 * @brief add a jsonArray to the stack
		 *
		 */
		void createArray();
		/**
		 * @brief add a jsonVariable to the stack
		 *
		 */
		void createVar();
		/**
		 * @brief assign a variables to the predecessor object in the stack.
		 *
		 */
		void assignVar();
		/**
		 * @brief assign a number to the predecessor object in the stack.
		 *
		 */
		void assignNumber();
		/**
		 * @brief assign a boolean to the predecessor object in the stack.
		 *
		 */
		void assignBool();
		/**
		 * @brief assign a null value to the predecessor object in the stack.
		 *
		 */
		void assignNull();
		/**
		 * @brief assign a jsonEntity to the predecessor object in the stack.
		 *
		 */
		void assign();
		/**
		 * @brief clear the string buffer.
		 *
		 */
		void cleanBuffer();
};

#endif