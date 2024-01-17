#pragma once
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <iostream>

inline double naStopnie(double radiany) {
	return radiany * (180.0 / M_PI);
}

inline double naRadiany(double stopnie) {
	return stopnie * (M_PI / 180.0);
}

inline float naStopnie(float radiany) {
	return radiany * (180.0f / M_PI);
}

inline float naRadiany(float stopnie) {
	return stopnie * (M_PI / 180.0f);
}
