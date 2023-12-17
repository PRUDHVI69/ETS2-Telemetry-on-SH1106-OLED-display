# ETS2-Telemetry-on-SH1106-OLED-display
This is a modified code of silas parker where he uses 16x2 crystal lcd display instead of that this code works for SH1106 display where it shows only speed for now you can change it if you want this can be a great addon to simBuilds or custom builds


The dash_plugin.txt files contains the COM port settings and some setings of these channels so as i'm  only using speed for that display you need to tune the numbers they acts as multiplier which is good for different output devices and here are mine.

i'm using silas parker telemtry and U8g2lib as the display driver.

/* 
comport str COM3

factor_speed                flt   3.65
factor_engine_rpm           flt   0.066
factor_brake_air_pressure   flt   1.0
factor_brake_temperature    flt   1.0
factor_fuel_ratio           flt 100.0
factor_oil_pressure         flt   1.0
factor_oil_temperature      flt   1.0
factor_water_temperature    flt   1.0
factor_battery_voltage      flt   5.0

*/


The display i'm using is a SH1106 and the code only works for that display and i'll update for other displays.
