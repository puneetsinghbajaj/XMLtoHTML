#pragma once


#include <iostream>
#include <fstream>
#include <string>
#ifndef XMLReader_h
#define XMLReader_h

#include <vector>
#include "pugixml.hpp"

using namespace pugi;
using namespace std;


// This class will load the XML document from given path
class XMLReader
{
private:
	xml_document doc;

public:
	//constructor will load the XML document from given path
	XMLReader(string path);

	// This method will get the attributes from XML file, which will be then set as Header in HTML table
	vector<string> getAttributes(string header);

	// This method will get the values for all the childs, which will be part of HTML table
	vector<vector<string>> getValues(string header);
};

#endif //XMLReader_h