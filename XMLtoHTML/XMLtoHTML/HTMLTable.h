#ifndef HTMLTable_h
#define HTMLTable_h

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// This class allows a 2-dimensional table expressed as a vectors of vector of strings to be transformed into HTML form.
class HTMLTable
{
private:
	vector<string> headers;
	vector<vector<string>> rows;

	// Helper method for writing an HTML row in a table
	void writeRow(ostream& out, string tag, vector<string> row);

public:
	// Set headers for the table columns
	void setHeaders(const vector<string>& headers);

	// Add rows to the table
	void addRow(const vector<string>& row);

	// Write the table into HTML form onto an output stream
	friend ostream& operator << (ostream& out, HTMLTable htmlTable);
};

#endif //HTMLTable_h