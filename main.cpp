#include "mbed.h"
#include "./INA3221/INA3221.h"
#include "./DT35/DT35.h"

int main()
{
//setup
DT35 *DT35_class = new DT35(PB_4,PA_8,(0x82));;
DT35_class->DT35_initialization(3);

printf("INA3221:   FID:%d   UID:%d    Mode:%d\r\n",DT35_class->getManufacturerID(1),DT35_class->getDieID(1),DT35_class->getConfiguration(1));
    while (1) {
        printf("CH1:%dV   ", DT35_class->getBusVoltage(1, 1));
        printf("CH2:%dV   ",DT35_class->getBusVoltage(1, 2));
        printf("CH3:%dV   ",DT35_class->getBusVoltage(1, 3));
        ThisThread::sleep_for(1);
    }
}
