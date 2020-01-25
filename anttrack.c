#include <stdio.h>
#include <math.h>

#define R 6356.0 //in km
#define PI 3.1415926539

double haversine(double, double, double, double);
double bearing(double, double, double, double);
double elevation(double, double, double);
double toRad(double);
double toDeg(double);
double toMin(double);
double toSec(double);


int main()
{
	double testlat1 = 30;		// N
	double testlon1 = 30;		// W
	double testlat2 = 10;		// N
	double testlon2 = 10;		// W

	double testalt1 = 10;		// in m
	double testalt2 = 10;



	double d = haversine(testlat1, testlon1, testlat2, testlon2);
	printf("bearing: %f degrees\n", bearing(testlat1, testlon1, testlat2, testlon2));
	printf("distance: %f km\n", d);
	printf("elevation: %f degrees\n", elevation(testalt1, testalt2, d));
	return 0;
}

/* Haversine returns the horizontal distance
 * lat = latitude; lon = longitude; 1 ++> GC; 2 ++> plane */

double haversine(double lat1, double lon1, double lat2, double lon2) 
{
	lat1 = toRad(lat1);
	lon1 = toRad(lon1);
	lat2 = toRad(lat2);
	lon2 = toRad(lon2);
	double a = pow(sin((lat2-lat1)/2), 2.0) + 
			cos(lat1)*cos(lat2)*pow(sin((lon2-lon1)/2), 2.0);
	//printf("a = %f\n", a);
	double c = 2.0*atan2(sqrt(a), sqrt(1.0-a));
	//printf("c = %f\n", c);
	return R*c;
}

/* bearing returns the azimuthal angle
 * uses same conentions for parameters */

double bearing(double lat1, double lon1, double lat2, double lon2)
{
//	lat1 = toRad(lat1);
//	lon1 = toRad(lon1);
//	lat2 = toRad(lat2);
//	lon2 = toRad(lon2);

	double x = sin(toRad(lon2-lon1))*cos(toRad(lat2));
	printf("x = %f\n", x);
//	double y = cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(lon2-lon1);
	double y = cos(toRad(lat1))*sin(toRad(lat2))-sin(toRad(lat1))*cos(toRad(lat2))*cos(toRad(lon2-lon1));
	printf("y = %f\n", y);
//	double radBearing = atan2(x, y);

	return toDeg(atan2(y, x)) + 270;
}

/* uses simple trigonometry in order to
 * find elevation in meters */

double elevation(double GCz, double planez, double dist)
{
	return tan((planez-GCz)/dist);
}

double toRad(double degrees)
{
	return degrees*PI/180;
}

double toDeg(double radians)
{
	double deg = radians*180/PI;
//	while (deg>360) deg -= 360;
//	while (deg<0)   deg +=360;
	
	return deg;
}

double toMin(double angle) {
	int whole = (int) angle;
	decimal = angle - whole;
	printf("decimal = %f\n", decimal);
	if 
	return decimal * 60.0;
}

double toSec(double angle) {
	minutes = toMin(angle);
	int whole = (int) minutes;
	decimal = minutes - whole;
	return decimal * 60;
}

// IMPLEMENT THIS FUNCTION
/* converts the bearing into a # to send power
 * to Arduino Uno */

int servoOut()
{
	return -1;
}
