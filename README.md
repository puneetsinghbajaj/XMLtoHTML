# XMLtoHTML
Program which gets XML attributes and create a HTML table

Usage 
XMLtoHTML.exe <XML file path>

Areas of improvement:
	- Current setup only supports unicode, can be made to support more encodings
	- current only setup to handle only 1 level
	- better error handling
	- Generic parser - Usable code
	- make more robust - use reccursive method in getAttributes
  
  Why Pugi is used - less complicated and its a trader off b/w performance and complexity
	- Single file use
	- Best suited for C++
	- Xerses - complexity
  
