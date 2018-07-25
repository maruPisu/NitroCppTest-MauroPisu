#include "rectangle.h"
#include <iostream>
#include <fstream>
#include <vector>
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

	std::vector<Rectangle> rectangles;

	cout << "Input:\n";
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

		rectangles.push_back({
			(*itr)["x"].GetInt(), 
			(*itr)["y"].GetInt(), 
			(*itr)["w"].GetInt(), 
			(*itr)["h"].GetInt()
		});
		std::cout << rectangles.back().stringify() << endl;
	}

	for (auto it1 = rectangles.begin(); (it1 != rectangles.end()); it1++)
	{
		for (auto it2 = it1 + 1; (it2 != rectangles.end()); it2++)
		{
			auto inter = it1->intersection(*it2);
			std::cout << inter.stringify();
		}
	}
    return 0;
}
