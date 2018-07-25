#include "rectangle.h"
#include <iostream>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "please specify the input file" << endl;
		exit(0);
	}
	//read file
	string filename = argv[1];
	string raw = "";
	string line;
	ifstream myfile (filename);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			raw += line;
		}
		myfile.close();
	}
	else 
	{
		cout << "Unable to open file"; 
		exit(0);
	}

	Document document;
	document.Parse(raw.c_str());
	assert(document.IsObject());
	assert(document.HasMember("rects"));
	assert(document["rects"].IsArray());

	const auto& rects = document["rects"];
	for (auto itr = rects.Begin(); itr != rects.End(); ++itr){
		assert(itr->HasMember("x"));
		assert(itr->HasMember("y"));
		assert(itr->HasMember("w"));
		assert(itr->HasMember("h"));
		cout << " x: " << (*itr)["x"].GetInt();
		cout << " y: " << (*itr)["y"].GetInt();
		cout << " w: " << (*itr)["w"].GetInt();
		cout << " h: " << (*itr)["h"].GetInt();
		cout << endl;
	}
  
	Rectangle rec(5, 3, 30, 15);
	Rectangle big(15, 13, 10, 10);

	std::cout << rec.stringify();
	std::cout << big.stringify();
	auto inter = rec.intersection(big);
	std::cout << inter.stringify();
    return 0;
}
