#include "XMLReader.h"


XMLReader::XMLReader(string path)
{
	// if there is an error while loading XML document, pugi is internally resolving that
	try
	{
		doc.load_file(path.c_str());
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
}

//this method will get attribute names from the nodes of given tag
vector<string> XMLReader::getAttributes(string tag)
{
	vector<string> attributes;
	try
	{
		xml_node child = doc.child(tag.c_str()).first_child();

		for (xml_node node = child.first_child(); node; node = node.next_sibling())
		{
			cout << node.name() << endl;
			attributes.emplace_back(node.name()); //emplace_back for better performance
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}

	return attributes;
}

//this method will get attribute values from all the nodes of given tag
vector<vector<string>> XMLReader::getValues(string tag)
{
	vector<vector<string>> values;

	try
	{
		xml_node child = doc.child(tag.c_str());
		for (xml_node node = child.first_child(); node; node = node.next_sibling())
		{
			vector<string> row;
			for (xml_node itr = node.first_child(); itr; itr = itr.next_sibling())
			{
				row.emplace_back(itr.first_child().value());
				cout << itr.name() << " = " << itr.first_child().value() << endl;
			}
			values.emplace_back(row);
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}

	return values;
}
