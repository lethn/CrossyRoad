#include"DOG.h"
#include"cstring"
DOG::DOG() {
	shape[0] = new char[11];
	string s = "o'')}____//";
	strcpy(shape[0], s.c_str());
	s = " `_/      )";
	shape[1] = new char[11];
	strcpy(shape[1], s.c_str());
	s = " (_(_/-(_/ ";
	shape[2] = new char[11];
	strcpy(shape[2], s.c_str());
}
DOG::DOG(int x ,int y):ENEMY(x,y) {
	shape[0] = new char[11];
	string s = "o'')}____//";
	strcpy(shape[0], s.c_str());
	s = " `_/      )";
	shape[1] = new char[11];
	strcpy(shape[1], s.c_str());
	s = " (_(_/-(_/ ";
	shape[2] = new char[11];
	strcpy(shape[2], s.c_str());
}