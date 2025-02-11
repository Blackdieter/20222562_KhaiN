#include <stdio.h>
#include <math.h>

typedef struct 
{
    float kp;
    float ki;
    float kd;
    float error;
    float integral;
    float output_min;
    float output_max;
} PIDController;

void PID_init(PIDController *pid, float kp, float ki, float kd,float output_min, float output_max){
    pid->kp=kp;
    pid->ki=ki;
    pid->kd=kd;
    pid->error=0.0f;
    pid->integral=0.0f;
    pid->output_max=output_max;
    pid->output_min=output_min;
}



int main(){

}