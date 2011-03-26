#ifndef MATH_VECTOR
#define MATH_VECTOR

class math_vector{
 protected:
  double x,y;
 public:
  math_vector(double X=0, double Y=0);
  static math_vector createFromPolar(double angle, double magnitude);
  double getX();
  double getY();
  double getAngle();
  double getMagnitude();
 
  math_vector operator+(math_vector& op);
  math_vector operator-(math_vector& op);
  math_vector operator*(double magnitude);
  math_vector operator/(double magnitude);

  double cross(math_vector& op);

  math_vector rotate(double degrees);
  math_vector rightAngle();  //for historical reasons, goes counterclockwise
};


#endif
