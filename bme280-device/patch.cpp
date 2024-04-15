// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_Sensor"
#pragma XOD require "https://github.com/adafruit/Adafruit_BME280_Library"
#pragma XOD require "https://github.com/adafruit/Adafruit_BusIO"

//Include C++ libraries
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

node {
    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = Adafruit_BME280*;
    }

    Adafruit_BME280 sensor = Adafruit_BME280();
    
    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;
        emitValue<output_DEV>(ctx, &sensor);
    }
}
