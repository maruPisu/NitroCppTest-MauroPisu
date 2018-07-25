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
		cout << "Unable to open file " << filename << endl;
		exit(0);
	}

	Document document;
	document.Parse(raw.c_str());
	if(!document.IsObject()){
		//malformed json
		cout << "malformed json" << endl;
		exit(0);
	}
	if(!document.HasMember("rects")){
		//root element missing
		cout << "rects element missing" << endl;
		exit(0);
	}
	if(!document["rects"].IsArray()){
		//root element should be array
		cout << "rects should be an array" << endl;
		exit(0);
	}

	std::vector<Rectangle> rectangles;

	cout << "Input:\n";
	const auto& rects = document["rects"];
	for (auto itr = rects.Begin(); itr != rects.End(); ++itr){
		if(
			!itr->HasMember("x") ||
			!itr->HasMember("y") ||
			!itr->HasMember("w") ||
			!itr->HasMember("h"))
		{
			//this rectangle is malformed
			continue;
		}

		if(
			(*itr)["x"].IsInt() &&
			(*itr)["y"].IsInt() &&
			(*itr)["w"].IsInt() &&
			(*itr)["h"].IsInt())
		{
			rectangles.push_back({
				(*itr)["x"].GetInt(), 
				(*itr)["y"].GetInt(), 
				(*itr)["w"].GetInt(), 
				(*itr)["h"].GetInt()
			});
			std::cout << rectangles.back().stringify();
		}
	}

	cout << "Output:\n";
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
