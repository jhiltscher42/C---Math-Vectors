#include "math_vector.h"
#include <math.h>
#include <stdio.h>

math_vector::math_vector(double X, double Y):x(X),y(Y){}

math_vector math_vector::createFromPolar(double angle, double magnitude){
  //printf("angle: %g, angle/180: %g, in radians: %g\n",angle,angle/180,M_PI*(angle/180));
  double x=magnitude*sin(M_PI*(angle/180));
  double y=magnitude*cos(M_PI*(angle/180));
  
  //  x=round(x*100000)/100000;
  //y=round(y*100000)/100000;
  //  printf("(%g,%g)\n",x,y);
  return math_vector(x,-y); //-y, to cause 0 to be north to be 0,-1
};

  //limited precision, due to PI not being able to be precisely represented, and doubles being unable to represent some really small increments
double math_vector::getX(){return round(x*100000)/100000;}
double math_vector::getY(){return round(y*100000)/100000;}

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
  //  printf("%g degrees + %g degrees\n",getAngle(),degrees);
  if (!degrees) return math_vector(x,y);
  if (degrees==270) return rightAngle();
  if (degrees==180) return (*this)*-1;
  if (degrees==90) return rightAngle()*-1;
  double angle=getAngle()+degrees;
  while (angle<0) angle+=360;
  while (angle>360) angle-=360;
  return createFromPolar(angle,getMagnitude());
}

double math_vector::cross(math_vector &op)
{
  //ret.x = y*op.z - z*op.y;
  //ret.y = z*op.x - x*op.z;
  //ret.z = x*op.y - y*op.x;
  
  double ret=x*op.y - y*op.x;

  //limited precision, due to PI not being able to be precisely represented, and doubles being unable to represent some really small increments
  ret=round(ret*100000)/100000;

  return ret;
}
