#ifndef _FILEIO_CPP__
#define _FILEIO_CPP__

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>

#include "../dataStructure/dataStructure.h"
using namespace dataStructure;

namespace fileIO
{

// file is like
/*
4, 5, [[2,4],[3,1]]
*/

void int_int_int_sparse_matrix(std::string fileName, int &m, int &n, std::vector<Point> &mat)
{
	std::fstream fin(fileName.c_str());

	int counter = 0;

	std::string str;
	Point p;

	while (fin.good())
	{
		getline(fin, str, ',');
		str.erase(std::remove_if(str.begin(), str.end(), [&](const char c) { return c == '[' || c == ']' || c == ' '; }), str.end());
		int num = std::stoi(str);
		if (num >= 0 && num < INT_MAX)
		{
			if (counter == 0)
				m = num;
			else if (counter == 1)
				n = num;

			else
			{
				if (counter % 2 == 0)
					p.x = num;
				else
				{
					p.y = num;
					mat.push_back(p);
				}
			}

			++counter;
		}
	}

	fin.close();
	fin.clear();
}

void vector_int(std::string fileName, std::vector<int> &vec, int &m)
{
	std::fstream fin(fileName.c_str());

	std::string str;
	while (fin.good())
	{
		std::getline(fin, str, ',');
		str.erase(std::remove_if(str.begin(), str.end(),
								 [&](char c) { return c == ',' || c == '[' || c == ']' || c == ' '; }));
		int num = std::stoi(str);
		vec.push_back(num);
	}
	m = vec.back();
	vec.pop_back();

	fin.close();
	fin.clear();
}

} //namespace;

#endif
