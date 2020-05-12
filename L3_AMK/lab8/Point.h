#pragma once
#include <iostream>
#include <string>

// Tego pliku nie można modyfikować.
class Point{
public:
	Point(int x, int y);
	virtual ~Point();
	virtual std::string info() const;
private:
	int x;
	int y;
};

