#include "point.hpp"
#include <iostream>
Point::Point(int x, int y){
    // cout<< "Constructeur par params"<<endl;
    this->x_ = x;  
    this->y_ = y;    
  
}

int Point::getX(){ 
    return x_;   
}
void Point::setX(int x){
    this->x_ = x;    
}
int Point::getY(){
  
    return y_;   
}
void Point::setY(int y){
    this->y_ = y;    
}
