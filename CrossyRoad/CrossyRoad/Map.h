#ifndef _MAP_H_
#define _MAP_H_
#include "Library.h"

class MAP {
private:
	int width;	// 115
	int height;	// 36
	char map[38][116];
public:
	MAP();
	void printMapScreen();
	void printSubMapScreen();
};


#endif