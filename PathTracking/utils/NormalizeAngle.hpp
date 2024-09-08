#ifndef CHHROBOTICS_CPP_NORMALIZEANGLE_HPP
#define CHHROBOTICS_CPP_NORMALIZEANGLE_HPP

#define PI 3.1415926

/**
 * 角度归一化
 * @param angle
 * @return
 */
double normalizeAngle(double angle) {
    while(angle>PI){
        angle-=2.0*PI;
    }
    while(angle<-PI){
        angle+=2.0*PI;
    }
    return angle;
}
#endif
