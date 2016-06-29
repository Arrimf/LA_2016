#pragma once
#include <iostream>
#include <fstream>
//#include <string>

class Point {
	double m_x;
	double m_y;
	friend class Circle;
	friend class Rect;
	friend Point& operator-= (Point&, const Point&);
	friend Point& operator-= (Point&, double);
	friend Point operator- (const Point&, const double);
	friend Point operator- (const Point&, const Point&);
	friend Point operator+ (const double, const Point&);

public:
	friend double Distance(const Point&, const Point&);
	inline const double GetX()const { return m_x; }
	inline const double GetY()const { return m_y; }
	double OffsetZ()const;
	explicit Point(double = 0, double = 0);
	Point(const Point&) = default;
	Point(Point&&) = default;
	

	Point& operator= (const Point&);
	Point& operator= (Point&&) = default;

	Point& operator+= (const Point&);
	Point& operator+= (const double);

	Point operator+ (const double)const;
	Point operator+ (const Point&)const;
	Point operator- ();
	Point operator+ ();
	bool operator< (const Point&)const;

	bool operator==(const Point&)const;
	friend std::ostream& operator<<(std::ostream&, const Point&);
	friend std::ostream& operator<<(std::ostream&, const Point*);
	//inline Point& operator*(Point*poi) { return *poi; };
	//friend std::ofstream& operator<< (std::ofstream&, const Point&);

};

