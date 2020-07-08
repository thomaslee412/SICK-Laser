#ifndef DT35_H
#define DT35_H
#include "../INA3221/INA3221.h"
#include "mbed.h"
#include <cmath>

class DT35
{
    private:
        INA3221 *vSenor1;
        INA3221 *vSenor2;
        int safety_margine = 100;
        int center_distance_x = 0;
        int center_distance_y = 0;
        int sensor_distance = 0;
        int left_upper_side_distance = 0;
        int right_upper_side_distance = 0;
        int left_lower_side_distance = 0;
        int key_point_x = 4075;
        int key_point_y = 6910;
        int try_spot_center_x = 6150 - center_distance_x - safety_margine;
        int try_spot1_center_y = 3225 - center_distance_y;
        int try_spot2_center_y = 4525 - center_distance_y;
        int try_spot3_center_y = 5825 - center_distance_y;
        int try_spot4_center_y = 7125 - center_distance_y;
        int try_spot5_center_y = 8425 - center_distance_y;
        int pass_point1_center_x = 1575 - center_distance_x;
        int pass_point1_center_y = 9790 - center_distance_y;
        int pass_point2_center_y = 9520 - center_distance_y;
        int pass_point3_center_y = 9250 - center_distance_y;
        int pass_point4_center_y = 8980 - center_distance_y;
        int pass_point5_center_y = 8710 - center_distance_y;

    public:
        DT35(PinName, PinName, uint8_t, PinName, PinName, uint8_t);
        DT35(PinName, PinName, uint8_t);
        void DT35_initialization(int, int);
        void DT35_initialization(int);
        int getManufacturerID(int);
        int getDieID(int);
        int getConfiguration(int);
        int getBusVoltage(int, int);
};