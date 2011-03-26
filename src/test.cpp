#include "math_vector.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
  math_vector V1, V2(1,1), V3(1,-1);
#define PRINT_VEC(v) printf("{%g,%g}",v.getX(),v.getY());
#define PRINT_EM PRINT_VEC(V1); PRINT_VEC(V2); PRINT_VEC(V3); printf("\n");
  printf("should be {0,0} {1,1} {1,-1}\n");
  PRINT_EM;

  printf("should be {3,-1} {1,1} {1,-1}\n");
  V1=V2+V3+V3;
  PRINT_EM;

  printf("should be {6,-2} {2,2} {2,-2}\n");
  V1=V1*2;
  V2=V2*2;
  V3=V3*2;
  PRINT_EM;

  printf("should be 135\n->%g\n",math_vector(1,1).getAngle());
  printf("should be 90\n->%g\n",math_vector(1,0).getAngle());
  printf("should be 45\n->%g\n",math_vector(1,-1).getAngle());
  
  printf("should be 5\n->%g\n",math_vector(3,4).getMagnitude());

  V1=math_vector::createFromPolar(0,1);
  V2=math_vector::createFromPolar(90,1);
  V3=math_vector::createFromPolar(225,1);
  printf("should be {0,-1} {1,0} {-0.707,0.707)\n");
  PRINT_EM;

  V1=V1.rightAngle();
  V3=V3.rotate(-45);
  printf("should be {-1,0} {1,0} {0,1}\n");
  PRINT_EM;

}
