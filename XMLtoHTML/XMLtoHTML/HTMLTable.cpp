#include "HTMLTable.h"

// set headers to the table
void HTMLTable::setHeaders(const vector<string>& headers)
{
	try
	{
		this->headers = headers;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
}

// Add rows to the table
void HTMLTable::addRow(const vector<string>& row)
{
	try
	{
		rows.emplace_back(row);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
}

// Writes a row of the table, using the given tag for the table data. 
//The tag may be td for table data or th for table header.
void HTMLTable::writeRow(ostream& out, string tag, vector<string> row)
{
	try
	{
		out << "<tr>\n";
		for (int rowIndex = 0; rowIndex < headers.size(); rowIndex++)
		{
			out << "<" << tag << "> "
				<< row[rowIndex] << " </" << tag << "> ";
		}
		out << "\n</tr>\n";
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
}

// Overloaded stream output operator <<
ostream& operator << (ostream& out, HTMLTable htmlTable)
{
	try
	{
		out << "<table border = \"1\">\n";

		// Write the headers
		htmlTable.writeRow(out, "th", htmlTable.headers);

		// Write the rows of the table
		for (unsigned int r = 0; r < htmlTable.rows.size(); r++)
		{
			htmlTable.writeRow(out, "td", htmlTable.rows[r]);
		}

		// Write end tag for table
		out << "</table>\n";
		return out;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
}