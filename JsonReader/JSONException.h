#ifndef JSONEXCEPTION
#define JSONEXCEPTION
#include <iostream>
#include <exception>
/**
 * @brief
 * Declaration of all possible exception that can occure
 * while using a JSONEntity or JSONParser
 */
struct BadFormatedFile : public std::exception
{
	const char *what() const throw()
	{
		return "The json file is not well formated.";
	}
};
struct BadAccessArray : public std::exception
{
	const char *what() const throw()
	{
		return "This json entity can't use the array accessor because it is not an array.";
	}
};
struct BadAccessObject : public std::exception
{
	const char *what() const throw()
	{
		return "This json entity can't use the object accessor because it is not an object.";
	}
};
struct NotConvertableToArray : public std::exception
{
	const char *what() const throw()
	{
		return "This json entity can't be converted into an array.";
	}
};
 struct NotConvertableToMap : public std::exception
{
	const char *what() const throw()
	{
		return "This json entity can't be converted into a map.";
	}
};
 struct NotConvertableToBool : public std::exception
{
	const char *what() const throw()
	{
		return "This json entity can't be converted into a boolean.";
	}
};
struct NotConvertableToInt : public std::exception
{
	const char *what() const throw()
	{
		return "This json entity can't be converted into an int.";
	}
};
struct NotConvertableToFloat : public std::exception
{
	const char *what() const throw()
	{
		return "This json entity can't be converted into a float.";
	}
};
struct NotConvertableToDouble : public std::exception
{
	const char *what() const throw()
	{
		return "This json entity can't be converted into a double.";
	}
};
#endif