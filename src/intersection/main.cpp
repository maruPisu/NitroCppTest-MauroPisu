#include "rectangle.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;

int main(int argc, char *argv[]){
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
	if(!document.IsObject())
	{
		//malformed json
		cout << "malformed json" << endl;
		exit(0);
	}
	if(!document.HasMember("rects"))
	{
		//root element missing
		cout << "rects element missing" << endl;
		exit(0);
	}
	if(!document["rects"].IsArray())
	{
		//root element should be array
		cout << "rects should be an array" << endl;
		exit(0);
	}

	std::vector<Rectangle> rectangles;

	//read rectangles
	int currentLabel = 0;
	cout << "Input:\n";
	const auto& rects = document["rects"];
	for (auto itr = rects.Begin(); itr != rects.End(); ++itr)
	{
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
			//everything is fine. create the rectangle
			Rectangle insertRectangle{
				(*itr)["x"].GetInt(), 
				(*itr)["y"].GetInt(), 
				(*itr)["w"].GetInt(), 
				(*itr)["h"].GetInt(),
				to_string(++currentLabel)};
				
			if(!insertRectangle.isEmpty()){
				rectangles.push_back(insertRectangle);
				cout << "\t" << insertRectangle.getLabel() << ": Rectangle at " << insertRectangle.stringify();
			}
		}
		if(currentLabel >= 10 )
		{
			// ignore rectangles after the tenth
			break;
		}
	}

	cout << "\nIntersections:\n";
	auto intersections = Rectangle::intersect(rectangles);
	for(auto intersection: intersections){
		cout << "\tBetween Rectangles " << intersection.stringifyInvolved();
		cout << " at " << intersection.area.stringify();
	}
    return 0;
}
