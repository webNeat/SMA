#ifndef POINT_HPP
#define POINT_HPP
class Point {
	private:
		int x_;
		int y_;
		
	public:
		Point(int = 0, int = 0);
		int getX();
		void setX(int);
		int getY();
		void setY(int);

};
#endif