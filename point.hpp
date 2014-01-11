#ifndef POINT_HPP
#define POINT_HPP
using namespace std;
class Point {
	private:
		int x_;
		int y_;
		
	public:
		Point();
		Point(int, int);
		int getX();
		void setX(int);
		int getY();
		void setY(int);

};
#endif