#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `Adafruit_BME280` class instance
        auto sensor = getValue<input_DEV>(ctx);
        emitValue<output_PRESS>(ctx, sensor->readPressure());
        emitValue<output_DONE>(ctx, 1);
    }
}


