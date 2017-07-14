#ifndef _FILEIO_H__
#define _FILEIO_H__

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>

#include "../dataStructure/dataStructure.h"
#include "../misc/misc.h"
using namespace dataStructure;

namespace fileIO
{

// file is like
/*
4, 5, [[2,4],[3,1]]
*/

void int_int_int_sparse_matrix(std::string fileName, int &m, int &n, std::vector<Point> &mat);

// file is like
/*
a vector and a integer number
[4, 5, 6], 10
*/
void vector_int(std::string fileName, std::vector<int> &vec, int &m);

} //namespace;

#endif
