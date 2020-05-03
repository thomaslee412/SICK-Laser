#include "mbed.h"
#include "INA3221.h"
// main() runs in its own thread in the OS
INA3221 vSenor(PB_9,PB_8,(0x82));
INA3221 vSenor2(PB_3,PB_10,(0x81));
int main()
{
//setup

vSenor.SetMode(INA3221_MODE_BUS_CONTINUOUS);
vSenor.EnableChannel(1);//ch1
vSenor.DisableChannel(2);//ch2
vSenor.DisableChannel(3);//ch3

vSenor2.SetMode(INA3221_MODE_BUS_CONTINUOUS);
vSenor2.DisableChannel(1);//ch1
vSenor2.EnableChannel(2);//ch2

//printf("INA3221\r\nFID:%d   UID:%d    Mode:%d\r\n",vSenor.GetManufacturerID(),vSenor.GetDieID(),vSenor.GetConfiguration());
printf("INA3221_2\r\nFID:%d   UID:%d    Mode:%d\r\n",vSenor2.GetManufacturerID(),vSenor2.GetDieID(),vSenor2.GetConfiguration());
//printf("INA3221\nFID:%d\nUID:%d\nMode:%d\n",vSenor.GetManufacturerID(),vSenor.GetDieID(),vSenor.GetConfiguration());
    while (true) {
        printf("CH1:%6.2fV   ",vSenor.GetBusVoltage(1));
        //printf("CH2:%6.2fV   ",vSenor.GetBusVoltage(2));
        //printf("CH3:%6.2fV   ",vSenor.GetBusVoltage(3));
        //printf("CH4:%6.2fV\r\n",vSenor2.GetBusVoltage(1));
        printf("CH5:%6.2fV\r\n",vSenor2.GetBusVoltage(2));
        wait(0.1);
    }
}
