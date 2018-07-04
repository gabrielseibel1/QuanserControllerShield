#include <iostream>
#include "PIDController.h"

PIDController::PIDController(float kp, float ki, float kd) {
    Kp = kp;
    Ki = ki;
    Kd = kd;

    max_limit = 0;
    min_limit = 0;

    integrated = 0;
    last_sample = 0;
}


void PIDController::set_max_limit(float value){
    max_limit = value;
}

void PIDController::set_min_limit(float value){
    min_limit = value;
}

void PIDController::set_point(float new_point) {
    point = new_point;
}

float PIDController::compute(float delta, float sample) {
    float p, i, d, error, voltage_out;

    error = point - sample;

    p = error;
    i = integrated + error * delta;
    d = (last_sample - sample) / delta;

    last_sample = sample;
    integrated = i;

    voltage_out = p * Kp + i * Ki + d * Kd;
    voltage_out = (voltage_out > max_limit) ? max_limit : voltage_out;
    voltage_out = (voltage_out < min_limit) ? min_limit : voltage_out;

    return voltage_out;
}