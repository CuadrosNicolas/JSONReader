#include "JSONParser.h"
void JSONParser::cleanBuffer()
{
	for (size_t i =0;i<buffer.length();i++)
	{
		if(isspace(buffer[i]))
		{
			buffer = buffer.substr(0,i);
			return;
		}
	}
}
JSONParser::JSONParser(std::string file)
{
	m_file = file;
}
void JSONParser::createObject()
{
	stack.push(new JSONObject());
}
void JSONParser::createArray()
{
	stack.push(new JSONArray());
}
void JSONParser::createVar()
{
	stack.push(new JSONVariable(buffer, JSONTYPE::VAR_CONTAINER));
	buffer = "";
}
void JSONParser::assignVar()
{
	JSONEntity *temp = stack.top();
	temp->assign(new JSONVariable(buffer, JSONTYPE::VAR_STRING));
	buffer = "";
	if (stack.top()->getType() == JSONTYPE::VAR_CONTAINER)
		assign();
}
void JSONParser::assignNumber()
{
	JSONEntity *temp = stack.top();
	temp->assign(new JSONVariable(buffer, JSONTYPE::VAR_NUMBER));
	buffer = "";
	if (temp->getType() == JSONTYPE::VAR_CONTAINER)
		assign();
}
void JSONParser::assignBool()
{
	JSONEntity *temp = stack.top();
	temp->assign(new JSONVariable(buffer, JSONTYPE::VAR_BOOL));
	buffer = "";
	if (temp->getType() == JSONTYPE::VAR_CONTAINER)
		assign();
}
void JSONParser::assignNull()
{
	JSONEntity *temp = stack.top();
	temp->assign(new JSONVariable(buffer, JSONTYPE::VAR_NULL));
	buffer = "";
	if (temp->getType() == JSONTYPE::VAR_CONTAINER)
		assign();
}
void JSONParser::assign()
{
	JSONEntity* temp = stack.top();
	stack.pop();
	stack.top()->assign(temp);
	buffer = "";
	if (stack.top()->getType() == JSONTYPE::VAR_CONTAINER)
		assign();
}
JSONEntity *JSONParser::parse()
{
	stack.push(NULL);
	std::ifstream input(m_file);
	std::string line;
	s=state::A;
	while(std::getline(input,line))
	{
		for(size_t i = 0;i<line.size();i++)
		{
			c = line[i];
			try
			{
				switch(s)
				{
					case state::A:
						if(c=='{')
						{
							createObject();
						}
						if(c=='[')
						{
							createArray();
						}
						if(c=='\"')
						{
							s=state::B;
						}
						if ((c >= '0' and c <= '9') || c == 'n' || c == 'f' || c == 't')
						{
							buffer += c;
							s = state::G;
						}
						if(c=='}' || c==']' or c==',')
						{
							assign();
						}
						break;
					case state::B:

						if(c=='\"')
						{
							createVar();
							s = state::C;
						}
						else
						{
							buffer += c;
						}

					break;

					case state::C:

						if(c==':')
						{
							s = state::D;
						}
						if (c == '}' or c == ']' or c == ',')
						{
							std::cout << buffer << std::endl;
							assignVar();
							s = state::A;
						}
						break;
					case state::D:

						if (c == '\"')
						{
							s = state::E;
						}
						if (c == '{')
						{
							createObject();
							s = state::A;
						}
						if (c == '[')
						{
							createArray();
							s = state::A;
						}
						if( (c>='0' and c<='9') || c=='n' || c=='f' || c=='t')
						{
							buffer+= c;
							s = state::G;
						}
						break;
					case state::G:

						if (c == '}' or c == ']' or c == ',')
						{
							cleanBuffer();
							if(buffer=="null")
							{
								assignNull();
							}
							else if (buffer == "false" || buffer == "true")
							{
								assignBool();
							}
							else
							{
								assignNumber();
							}
							s = state::A;
						}
						else
						{
							buffer += c;
						}

						break;
					case state::E:

						if (c == '\"')
						{
							s = state::F;
						}
						else
						{
							buffer += c;
						}
					break;
					case state::F:

						if (c == '}' or c == ']' or c==',')
						{
							assignVar();
							s = state::A;
						}

						break;
				}
			}
			catch(std::bad_alloc)
			{
				std::cout << "\nBAD ALLOC :" << buffer << std::endl;
			}
		}
	}
	JSONEntity *temp = stack.top();
	return temp;

}
