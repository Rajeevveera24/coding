#include <stdio.h>
#include <math.h>

float abso(float a){
	return a>0?(a):(-1*a);
}

float function(float x){
	return (x-1);
}

float solve(float val, float range[], float step){
	float close = range[0];
	float minError = abso(function(close) - val);

	for(float i=close; i<=range[1]; i += step){
		if( abso(function(i) - val) < minError){
			minError = abso(function(i) - val);
			close = i;
		}
	}
	return close;
}

int main(int argc, char const *argv[])
{
	float range[2], val, step;
	scanf("%f %f %f %f", &val, &range[0], &range[1], &step);
	float close = solve(val, range, step);
	printf("Closest solution is %0.5f with value of %0.5f\n", close, function(close));
	return 0;
}