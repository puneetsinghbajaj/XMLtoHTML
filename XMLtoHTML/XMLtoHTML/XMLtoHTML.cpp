/*
This program creates a file in HTML, writes a table to the file, and opens it for viewing
Notes:
*/

#include <filesystem>

#include "HTMLTable.h"
#include "XMLReader.h"

using namespace std;
namespace fs = std::filesystem;

int main(int argc, const char* argv[])
{
	try
	{
		HTMLTable hTable;
		string path(argv[1]);
		XMLReader xml(path.c_str());

		hTable.setHeaders(xml.getAttributes("CATALOG"));

		auto rows = xml.getValues("CATALOG");
		for (int i = 0; i < rows.size(); i++)
		{
			hTable.addRow(rows[i]);
		}

		// Open a file and write the HTML code to the file
		// fs::temp_directory_path().string() for cross platform 
		ofstream outFile(fs::temp_directory_path().string() + "\\table.html");
		outFile << hTable;
		outFile.close();

		// Write the same HTML code to the screen for ease of viewing
		cout << hTable;

		// Use the default browser to view generated HTML table
		system((fs::temp_directory_path().string() + "\\table.html").c_str());

		cin.get();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}

	return 0;
}