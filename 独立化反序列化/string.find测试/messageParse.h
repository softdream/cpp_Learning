#ifndef __MESSAGE_PARSE_H_
#define __MESSAGE_PARSE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>

#include <cstdlib>
#include <vector>
#include <map>

#include <algorithm>

namespace serialize {

class Serialize
{

	struct ElementInfo {
		int type;
		int length;
		std::string name;
	};
	typedef struct ElementInfo ElementInfo;

public:
	Serialize();
	~Serialize();

	void setReadPath(const std::string &path);
	void setWritePath( const std::string &path );

	//private:
	bool read();
	bool write();

	void elementsPrintTest() const;
	void elementsInfoPrintTest() const;

private:
	bool findDataElement(const std::string &temp, const int position, const int typeLength, const int type);
	bool findArrayDataElement(const std::string &temp, const int position, const int typeLength, const int type);
	bool findSelfDefinedDataElment(const std::string &temp, const std::string &data);

	bool writeHead();
	bool writeConstructors( const std::pair<std::string, std::vector<ElementInfo>> &it );
	bool writeCopyConstructors(const std::pair<std::string, std::vector<ElementInfo>> &it);
	bool writeELements( const std::pair<std::string, std::vector<ElementInfo>> &it );

	bool writeSerialize( const std::pair<std::string, std::vector<ElementInfo>> &it );
	bool writeDeSerialize( const std::pair<std::string, std::vector<ElementInfo>> &it );

private:
	std::string readPath;
	std::string writePath;

	std::ifstream infile;
	std::ofstream outfile;

	std::vector<std::string> elementsVec;

	std::vector<ElementInfo> elementsInfo;
	//std::vector<std::vector<ElementInfo>> elementsInfoVec;
	std::map<std::string, std::vector<ElementInfo>> elementsInfoVec;
};

Serialize::Serialize()
{


}

Serialize::~Serialize()
{


}
void Serialize::setReadPath(const std::string &path)
{
	readPath = path;
}

void Serialize::setWritePath(const std::string &path)
{
	writePath = path;
}

void Serialize::elementsPrintTest() const
{
	if (!elementsVec.empty()) {
		std::cout << "---------- Messages Number ---------" << std::endl;
		for (auto it : elementsVec) {
			std::cout << it << std::endl;
		}
		std::cout << "------- End of Message Number ------" << std::endl;
	}
}

void Serialize::elementsInfoPrintTest() const
{
	if (!elementsInfoVec.empty()) {
		for (auto it : elementsInfoVec) {
			std::cout << "==========================" << std::endl;
			std::cout << "Data Type: " << it.first << std::endl;
			for (auto item : it.second) {
				std::cout << "name: " << item.name << std::endl;
				std::cout << "type: " << item.type << std::endl;
				std::cout << "length: " << item.length << std::endl;
				std::cout << "-----------------------" << std::endl;
			}
		}
	}
}

bool Serialize::findDataElement(const std::string &temp, const int position, const int typeLength, const int type)
{
	int semicolon = temp.find(";");
	if (semicolon != -1) {
		std::string data = temp.substr(position + typeLength, semicolon - position - typeLength);
		std::cout << "data: " << data << std::endl;

		ElementInfo eI;

		eI.length = -1;
		eI.name = data;
		eI.type = type;

		elementsInfo.push_back(eI);
	}
	else return false;

	return true;

}
bool Serialize::findArrayDataElement(const std::string &temp, const int position, const int typeLength, const int type)
{
	ElementInfo eI;
	eI.type = type;

	int brace = temp.find("]");
	if (brace != -1) {
		std::string length = temp.substr(position + typeLength, brace - position - typeLength);
		std::cout << "length: " << length << ", " << std::stoi(length) << std::endl;
		eI.length = std::stoi(length);

		int semicolon = temp.find(";");
		if (semicolon != -1) {
			std::string data = temp.substr(brace + 2, semicolon - brace - 2);
			std::cout << "data: " << data << std::endl;
			eI.name = data;
		}
		else return false;
	}
	else return false;

	elementsInfo.push_back(eI);
	return true;
}

bool Serialize::findSelfDefinedDataElment(const std::string &temp, const std::string &data)
{
	auto it = elementsInfoVec.find(data);
	if (it != elementsInfoVec.end()) {
		for (auto item : it->second) {
			elementsInfo.push_back(item);
		}
	}
	return true;
}

bool Serialize::read()
{
	infile.open(readPath, std::ios::in);
	if (!infile.is_open()) {
		std::cerr << "Message File is Not Opened ..." << std::endl;
		return false;
	}

	std::string temp;
	std::string element;

	while (std::getline(infile, temp)) {
		std::cout << "temp:  " << temp << std::endl;

		//------------- find the data name --------------//
		int keyWord = temp.find("message");
		if (keyWord != -1) {
			std::cout << "KeyWord Position: " << keyWord << std::endl;

			//std::string element;
			int brace = temp.find("{");
			if (brace == -1) {
				element = temp.substr(keyWord + 7);
			}
			else {
				element = temp.substr(keyWord + 7, brace - keyWord - 7);
			}
			std::cout << "element: " << element << std::endl;
			elementsVec.push_back(element);
		}
		//------------ find the data type and it's name -------------//
		int typeInt8 = temp.find("int8 ");
		if (typeInt8 != -1) {
			findDataElement(temp, typeInt8, 5, 1);
		}

		int typeInt16 = temp.find("int16 ");
		if (typeInt16 != -1) {
			findDataElement(temp, typeInt16, 6, 2);
		}

		int typeInt32 = temp.find("int32 ");
		if (typeInt32 != -1) {
			findDataElement(temp, typeInt32, 6, 3);
		}

		int typeInt64 = temp.find("int64 ");
		if (typeInt64 != -1) {
			findDataElement(temp, typeInt64, 6, 4);
		}

		int typeFloat32 = temp.find("float32 ");
		if (typeFloat32 != -1) {
			findDataElement(temp, typeFloat32, 8, 5);
		}

		int typeFloat64 = temp.find("float64 ");
		if (typeFloat64 != -1) {
			findDataElement(temp, typeFloat64, 8, 6);
		}

		int typeInt8Array = temp.find("int8[");
		if (typeInt8Array != -1) {
			findArrayDataElement(temp, typeInt8Array, 5, 7);
		}
		int typeInt16Array = temp.find("int16[");
		if (typeInt16Array != -1) {
			findArrayDataElement(temp, typeInt16Array, 6, 8);
		}

		int typeInt32Array = temp.find("int32[");
		if (typeInt32Array != -1) {
			findArrayDataElement(temp, typeInt32Array, 6, 9);
		}

		int typeInt64Array = temp.find("int64[");
		if (typeInt64Array != -1) {
			findArrayDataElement(temp, typeInt64Array, 6, 10);
		}

		int typeFloat32Array = temp.find("float32[");
		if (typeFloat32Array != -1) {
			findArrayDataElement(temp, typeFloat32Array, 8, 11);
		}

		int typeFloat64Array = temp.find("float64[");
		if (typeFloat64Array != -1) {
			findArrayDataElement(temp, typeFloat64Array, 8, 12);
		}

		//------------- find sefl-defined data -------------//
		if (!elementsVec.empty()) {
			if (temp.find("message") == -1) {
				for (auto it : elementsVec) {
					int pose = temp.find(it);
					if (pose != -1) {
						std::cout << "it = " << it << std::endl;
						findSelfDefinedDataElment( temp, it );
					}
				}
			}
		}

		if (temp.find("}") != -1) {
			std::cout << "end of " + element << std::endl;
			elementsInfoVec.insert(std::make_pair(element, elementsInfo));
			elementsInfo.clear();
		}

	}

	infile.close();

	return true;
}

bool Serialize::writeELements(const std::pair<std::string, std::vector<ElementInfo>> &it)
{
	if (it.second.empty()) return false;

	for (auto item : it.second) {
		switch (item.type) {
			case 1:outfile << "\tchar " << item.name <<std::endl; break;
			case 2:outfile << "\tshort " << item.name<<std::endl; break;
			case 3:outfile << "\tint " << item.name << std::endl; break;
			case 4:outfile << "\tlong " << item.name << std::endl; break;
			case 5:outfile << "\tfloat " << item.name << std::endl; break;
			case 6:outfile << "\tdouble " << item.name <<std::endl; break;
			case 7: outfile << "\tchar " << item.name << "["<<item.length<<"]"<<std::endl; break;
			case 8: outfile << "\tshort " << item.name << "[" << item.length << "]" << std::endl; break;
			case 9: outfile << "\tint " << item.name << "[" << item.length << "]" << std::endl; break;
			case 10: outfile << "\tlong " << item.name << "[" << item.length << "]" << std::endl; break;
			case 11: outfile << "\tfloat " << item.name << "[" << item.length << "]" << std::endl; break;
			case 12: outfile << "\tdouble " << item.name << "[" << item.length << "]" << std::endl; break;
			default: break;
		}
	}
	outfile << std::endl;

	return true;
}

bool Serialize::writeHead()
{
	std::string head = writePath.substr( 0, head.find( ".h" ) );
	std::transform( head.begin(), head.end(), head.begin(), ::toupper );
	std::cout << "head: " << head << std::endl;

	// -------------- Write Header --------------- //
	outfile << "#ifndef __" << head << "_H_" << std::endl;
	outfile << "#define __" << head << "_H_" << std::endl << std::endl;

	outfile << "#include <stdint.h>" << std::endl;

	outfile << "#include <string>" << std::endl;

	outfile << "#include <memory>" << std::endl;

	outfile << "#include <algorithm>" << std::endl;

	//outfile <<"namespace message {"

	return true;
}

bool Serialize::writeConstructors(const std::pair<std::string, std::vector<ElementInfo>> &it)
{
	std::cout << "Data Type: " << it.first << std::endl;
	
	// ----------- Default Constructor ------------//
	std::vector<ElementInfo> arrayVec, eleVec;
	if (!it.second.empty()) {
		for (auto item : it.second) {
			if (item.length == -1) eleVec.push_back( item );
			else arrayVec.push_back(item);
		}
	}

	outfile << "\t" << it.first << "() ";
	if( !eleVec.empty() || !arrayVec.empty() ) outfile << " : ";

	if (!eleVec.empty()) {
		for (auto item = eleVec.begin(); item != eleVec.end(); item ++) {
			outfile << item->name << "(0), ";
			if (item == eleVec.end()) {
				outfile << item->name << "(0)" << std::endl;
			}
		}
	}
	outfile << "\t{" << std::endl;
	if (!arrayVec.empty()) {
		for (auto item : arrayVec)
			outfile << "\tmemset( " << item.name << ", 0, sizeof " << item.name << " )" << std::endl;
	}
	outfile << "\t}" << std::endl;

	// ------------ Constructor -----------//
	outfile << "\t" << it.first << "( ";
	if (!eleVec.empty()) {
		for (auto item : eleVec) {
			switch (item.type) {
				case 1:outfile << "char " << item.name << "_, "; break;
				case 2:outfile << "short " << item.name << "_, "; break;
				case 3:outfile << "int " << item.name << "_, "; break;
				case 4:outfile << "long " << item.name << "_, "; break;
				case 5:outfile << "float " << item.name << "_, "; break;
				case 6:outfile << "double " << item.name << "_, "; break;
				default: break;
			}
		}
	}

	if (!arrayVec.empty()) {
		for (auto item : arrayVec) {
			switch (item.type) {
				case 7: outfile << "std::initializer_list<char> &&" << item.name << "_,"; break;
				case 8: outfile << "std::initializer_list<short> &&" << item.name << "_,"; break;
				case 9: outfile << "std::initializer_list<int> &&" << item.name << "_,"; break;
				case 10: outfile << "std::initializer_list<long> &&" << item.name << "_,"; break;
				case 11: outfile << "std::initializer_list<float> &&" << item.name << "_,"; break;
				case 12: outfile << "std::initializer_list<double> &&" << item.name << "_,"; break;
				default: break;
			}
		}
		outfile << ")" << std::endl;
	}
	else outfile << ")" << std::endl;

	if (!eleVec.empty() || !arrayVec.empty()) outfile << " : ";

	if (!eleVec.empty()) {
		for (auto item = eleVec.begin(); item != eleVec.end(); item++) {
			outfile << item->name << "( " << item->name << "_ ), ";
			if (item == eleVec.end() && arrayVec.empty()) {
				outfile << item->name << "( " << item->name << "_ )"<<std::endl;
			}
			else if (item == eleVec.end() && !arrayVec.empty()) {
				outfile << item->name << "( " << item->name << "_ ), ";
			}
		}
	}

	if (!arrayVec.empty()) {
		for (auto item = arrayVec.begin(); item != arrayVec.end(); item++) {
			outfile << item->name << "( " << item->name << "_ ), ";
			if (item == arrayVec.end()) {
				outfile << item->name << "( " << item->name << "_ )" << std::endl;
			}
		}
	}

	outfile << "\t{" << std::endl << std::endl;
	outfile << "\t}" << std::endl;

	// ------------ DeConstructor -------------//
	outfile << "\t~" << it.first << "()" << std::endl;
	outfile << "\t{" << std::endl;
	outfile << std::endl;
	outfile << "\t}" << std::endl;

	return true;
}

bool Serialize::writeCopyConstructors(const std::pair<std::string, std::vector<ElementInfo>> &it)
{
	std::cout << "Data Type: " << it.first << std::endl;

	std::vector<ElementInfo> arrayVec, eleVec;
	if (it.second.empty()) return false;

	for (auto item : it.second) {
		if (item.length == -1) eleVec.push_back(item);
		else arrayVec.push_back(item);
	}

	// ----------- Copy Constructor ------------//
	outfile << "\t" << it.first << "( const " << it.first << " &other )";
	if (!eleVec.empty() || !arrayVec.empty()) outfile << " : ";

	if (!eleVec.empty()) {
		for (auto item = eleVec.begin(); item != eleVec.end(); item++) {
			outfile << item->name << "( other." << item->name << " ), ";
			if (item == eleVec.end()) {
				outfile << item->name << "( other." << item->name << " )" << std::endl;
			}
		}
	}

	outfile << "\t{" << std::endl;

	if (!arrayVec.empty()) {
		for (auto item = arrayVec.begin(); item != arrayVec.end(); item++) {
			switch (item->type) {
				case 7: outfile << "\t\tmemcpy( &" << item->name << ", other." << item->name << ", " << item->length << " * 1 );" << std::endl; break;
				case 8: outfile << "\t\tmemcpy( &" << item->name << ", other." << item->name << ", " << item->length << " * 2 );" << std::endl; break;
				case 9: outfile << "\t\tmemcpy( &" << item->name << ", other." << item->name << ", " << item->length << " * 4 );" << std::endl; break;
				case 10: outfile << "\t\tmemcpy( &" << item->name << ", other." << item->name << ", " << item->length << " * 8 );" << std::endl; break;
				case 11: outfile << "\t\tmemcpy( &" << item->name << ", other." << item->name << ", " << item->length << " * 4 );" << std::endl; break;
				case 12: outfile << "\t\tmemcpy( &" << item->name << ", other." << item->name << ", " << item->length << " * 8 );" << std::endl; break;
				default: break;
			}
			
		}
	}

	outfile << "\t}" << std::endl;

	// ----------- Copy Assignment ------------//
	outfile << "\t" << it.first << "& operator=( const " << it.first << " &rhs )" << std::endl;
	outfile << "\t{" << std::endl;
	if (!eleVec.empty()) {
		for (auto item : eleVec) {
			outfile << item.name << " = rhs." << item.name << std::endl;
		}
	}
	if (!arrayVec.empty()) {
		for (auto item = arrayVec.begin(); item != arrayVec.end(); item++) {
			switch (item->type) {
			case 7: outfile << "\t\tmemcpy( &" << item->name << ", other." << item->name << ", " << item->length << " * 1 );" << std::endl; break;
			case 8: outfile << "\t\tmemcpy( &" << item->name << ", other." << item->name << ", " << item->length << " * 2 );" << std::endl; break;
			case 9: outfile << "\t\tmemcpy( &" << item->name << ", other." << item->name << ", " << item->length << " * 4 );" << std::endl; break;
			case 10: outfile << "\t\tmemcpy( &" << item->name << ", other." << item->name << ", " << item->length << " * 8 );" << std::endl; break;
			case 11: outfile << "\t\tmemcpy( &" << item->name << ", other." << item->name << ", " << item->length << " * 4 );" << std::endl; break;
			case 12: outfile << "\t\tmemcpy( &" << item->name << ", other." << item->name << ", " << item->length << " * 8 );" << std::endl; break;
			default: break;
			}

		}
	}

	outfile << "\t}" << std::endl <<std::endl;

	return true;
}

bool Serialize::writeSerialize(const std::pair<std::string, std::vector<ElementInfo>> &it)
{
	if (!it.second.empty()) return false;

	outfile << "\tint serialize( char *buff )" << std::endl;
	outfile << "\t{" << std::endl;
	outfile << "\t\tint pose = 0;" << std::endl;

	for (auto item : it.second) {
		if (item.type == 1) { //int8
			outfile << "\t\tmemcpy( &buff[pose], &" << item.name << ", 1 );" << std::endl;
			outfile << "\t\tpose += 1;" << std::endl;
		}
		else if (item.type == 2) { // int16
			outfile << "\t\tmemcpy( &buff[pose], &" << item.name << ", 2 );" << std::endl;
			outfile << "\t\tpose += 2;" << std::endl;
		}
		else if (item.type == 3) { // int32
			outfile << "\t\tmemcpy( &buff[pose], &" << item.name << ", 4 );" << std::endl;
			outfile << "\t\tpose += 4;" << std::endl;
		}
		else if (item.type == 4) { //int64
			outfile << "\t\tmemcpy( &buff[pose], &" << item.name << ", 8 );" << std::endl;
			outfile << "\t\tpose += 8;" << std::endl;
		}
		else if (item.type == 5) {
			outfile << "\t\tmemcpy( &buff[pose], &" << item.name << ", 4 );" << std::endl;
			outfile << "\t\tpose += 4;" << std::endl;
		}
		else if (item.type == 6) {
			outfile << "\t\tmemcpy( &buff[pose], &" << item.name << ", 8 );" << std::endl;
			outfile << "\t\tpose += 8;" << std::endl;
		}
		else if (item.type == 7) {
			outfile << "\t\tmemcpy( &buff[pose], &" << item.name << ", " << item.length << " );" << std::endl;
			outfile << "\t\tpose += " << item.length << std::endl;
		}
		else if (item.type == 8) {
			outfile << "\t\tmemcpy( &buff[pose], &" << item.name << ", " << item.length << " * 2 );" << std::endl;
			outfile << "\t\tpose += " << item.length << " * 2;" << std::endl;
		}
		else if (item.type == 9) {
			outfile << "\t\tmemcpy( &buff[pose], &" << item.name << ", " << item.length << " * 4 );" << std::endl;
			outfile << "\t\tpose += " << item.length << " * 4;" << std::endl;
		}
		else if (item.type == 10) {
			outfile << "\t\tmemcpy( &buff[pose], &" << item.name << ", " << item.length << " * 8 );" << std::endl;
			outfile << "\t\tpose += " << item.length << " * 8;" << std::endl;
		}
		else if (item.type == 11) {
			outfile << "\t\tmemcpy( &buff[pose], &" << item.name << ", " << item.length << " * 4 );" << std::endl;
			outfile << "\t\tpose += " << item.length << " * 4;" << std::endl;
		}
		else if (item.type == 12) {
			outfile << "\t\tmemcpy( &buff[pose], &" << item.name << ", " << item.length << " * 8 );" << std::endl;
			outfile << "\t\tpose += " << item.length << " * 8;" << std::endl;
		}
	}

	outfile << "\t\treturn pose;" << std::endl;
	outfile << "\t}" << std::endl;

	return true;
}

bool Serialize::writeDeSerialize(const std::pair<std::string, std::vector<ElementInfo>> &it)
{
	if (!it.second.empty()) return false;

	//outfile << "\t" << it.first << " deSerialize( char *buff )" << std::endl;
	outfile << "\t" << "void deSerialize( char *buff )" << std::endl;
	outfile << "\t{" << std::endl;
	outfile << "\t\tint pose = 0;" << std::endl;
	//outfile << "\t\t" << it.first << " data;" << std::endl;

	for (auto item : it.second) {
		if (item.type == 1) {
			outfile << "\t\tmemcpy( &" << item.name << ", buff[pose], 1 );" << std::endl;
			outfile << "\t\tpose += 1;" << std::endl;
		}
		else if (item.type == 2) {
			outfile << "\t\tmemcpy( &" << item.name << ", buff[pose], 2 );" << std::endl;
			outfile << "\t\tpose += 2;" << std::endl;
		}
		else if (item.type == 3) {
			outfile << "\t\tmemcpy( &" << item.name << ", buff[pose], 4 );" << std::endl;
			outfile << "\t\tpose += 4;" << std::endl;
		}
		else if (item.type == 4) {
			outfile << "\t\tmemcpy( &" << item.name << ", buff[pose], 8 );" << std::endl;
			outfile << "\t\tpose += 8;" << std::endl;
		}
		else if (item.type == 5) {
			outfile << "\t\tmemcpy( &" << item.name << ", buff[pose], 4 );" << std::endl;
			outfile << "\t\tpose += 4;" << std::endl;
		}
		else if (item.type == 6) {
			outfile << "\t\tmemcpy( &" << item.name << ", buff[pose], 8 );" << std::endl;
			outfile << "\t\tpose += 8;" << std::endl;
		}
		else if (item.type == 7) {
			outfile << "\t\tmemcpy( &" << item.name << ", buff[pose]," << item.length << " );" << std::endl;
			outfile << "\t\tpose += "<< item.length << std::endl;
		}
		else if (item.type == 8) {
			outfile << "\t\tmemcpy( &" << item.name << ", buff[pose]," << item.length << " * 2 );" << std::endl;
			outfile << "\t\tpose += " << item.length << " * 2;" << std::endl;
		}
		else if (item.type == 9) {
			outfile << "\t\tmemcpy( &" << item.name << ", buff[pose]," << item.length << " * 4 );" << std::endl;
			outfile << "\t\tpose += " << item.length << " * 4;" << std::endl;
		}
		else if (item.type == 10) {
			outfile << "\t\tmemcpy( &" << item.name << ", buff[pose]," << item.length << " * 8 );" << std::endl;
			outfile << "\t\tpose += " << item.length << " * 8;" << std::endl;
		}
		else if (item.type == 11) {
			outfile << "\t\tmemcpy( &" << item.name << ", buff[pose]," << item.length << " * 4 );" << std::endl;
			outfile << "\t\tpose += " << item.length << " * 4;" << std::endl;
		}
		else if (item.type == 12) {
			outfile << "\t\tmemcpy( &" << item.name << ", buff[pose]," << item.length << " * 8 );" << std::endl;
			outfile << "\t\tpose += " << item.length << " * 8;" << std::endl;
		}
	}

	outfile << "\t}" << std::endl;

	return true;
}

bool Serialize::write()
{
	outfile.open( writePath, std::ios::out | std::ios::trunc );
	if (!outfile.is_open()) {
		std::cerr << "Open File Failed ..." << std::endl;
		return false;
	}

	writeHead();

	for (auto it : elementsInfoVec) {
		// write structure
		outfile << "struct " << it.first << std::endl;
		outfile << "{" << std::endl;
		writeELements( it );
		writeConstructors( it );
		writeCopyConstructors( it );
		writeSerialize( it );
		writeDeSerialize( it );

		outfile << "};" << std::endl;
		outfile << "typedef struct " << it.first << " " << it.first << std::endl;
	}

	outfile << std::endl;
	outfile << "#endif" << std::endl;

	return true;
}

}

#endif