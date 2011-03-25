#include "math_vector.h"
#include <math.h>

math_vector::math_vector(double X, double Y):x(X),y(Y){}

math_vector math_vector::createFromPolar(double angle, double magnitude){
  double x=magnitude*sin(M_PI*(angle/180));
  double y=magnitude*cos(M_PI*(angle/180));
  return math_vector(round(x*1000)/1000,-round(y*1000)/1000);
};

double math_vector::getX(){return x;}

double math_vector::getY(){return y;}

double math_vector::getAngle(){// do angle calc
  if (!x){  //if x is 0, then angle is either north (0) or south (180) 
    if (y<=0) return 0;
    else return 180;
  }
  double slope=-y/x;
  double angle=90-atan(slope)/M_PI*180;
  if (x<0) angle+=180;
  return angle;
}

double math_vector::getMagnitude(){
  return sqrt(x*x+y*y);
}

math_vector math_vector::operator+(math_vector& op){
  return math_vector(x+op.x,y+op.y);
};

math_vector math_vector::operator-(math_vector& op){
  return math_vector(x-op.x,y-op.y);
};

math_vector math_vector::operator*(double magnitude){
  return math_vector(x*magnitude,y*magnitude);
}

math_vector math_vector::operator/(double magnitude){
  if (!magnitude) magnitude=.001;  //HACK!
  return math_vector(x/magnitude,y/magnitude);
}

math_vector math_vector::rightAngle(){
  return math_vector(y,-x);
}

math_vector math_vector::rotate(double degrees){
  if (!degrees) return math_vector(x,y);
  if (degrees==270) return rightAngle();
  if (degrees==180) return (*this)*-1;
  if (degrees==90) return rightAngle()*-1;
  double angle=getAngle()+degrees;
  while (angle<0) angle+=360;
  while (angle>360) angle-=360;
  return createFromPolar(angle,getMagnitude());
}
