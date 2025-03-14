//
// Created by stud-17 on 2/28/25.
//
/*JSON - JavaScript Object N???
Key:Value
Key - ???
Value: string, number, bool, miniJSON?, array*/
#include <iostream>
#include <map>
#include <memory>
#include <vector>
class JSON_Node;

using JSONObject = std::map<std::string, std::shared_ptr<JSON_Node>>;
using JSONList = std::vector<std::shared_ptr<JSON_Node>>;

class JSON_Node {
private:
	enum class Type{OBJECT, LIST, STRING, NUMBER, BOOLEAN, NULL_TYPE};
	union Values {
		JSONObject* object;
		JSONList* list;
		std::string* s;
		float fValue;
		bool bValue;
	} value;
	Type type;
	auto returnObject() {
		if(type==Type::OBJECT) { return *value.object; }
		throw std::logic_error("Void return?");
	}
	auto returnList() {
		if(type==Type::LIST) { return *value.list; }
		throw std::logic_error("Void return?");
	}
	auto returnString() {
		if(type==Type::STRING) { return *value.s; }
		throw std::logic_error("Void return?");
	}
	auto returnFloat() {
		if(type==Type::NUMBER) { return value.fValue; }
		throw std::logic_error("Void return?");
	}
	auto returnBool() {
		if(type==Type::BOOLEAN) { return value.bValue; }
		throw std::logic_error("Void return?");
	}
public:
	void setObject(JSONObject* object) {
		this->value.object = object;
		type = Type::OBJECT;
	}
	void setList(JSONList* list) {
		this->value.list = list;
		type = Type::LIST;
	}
	void setString(std::string* string) {
		this->value.s = string;
		type = Type::STRING;
	}
	void setNumber(float number) {
		this->value.fValue = number;
		type = Type::NUMBER;
	}
	void setBoolean(bool boolean) {
		this->value.bValue = boolean;
		type = Type::BOOLEAN;
	}

};

