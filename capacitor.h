#ifndef CAPACITOR_H
#define  CAPACTIOR_H

struct _capacitor {
	double *time;
	double *voltage;
	double *current;
	double C;
};

typedef struct _capacitor Capacitor;
#endif
