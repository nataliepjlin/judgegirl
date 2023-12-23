#include "car.h"
CarStatusList carSimulation(CarStatus car, Command commands[]){
    CarStatusList result;
    result.num = 0;
    int c = 0;
    while(commands[c].t != 0 && 1 <= commands[c].t &&  commands[c].t <= 5){
        if(commands[c].t == 1){
            car.g += commands[c].v;
            c++;
            continue;
        }
        car.g -= commands[c].v;
        if(car.g < 0)/*invalid*/
            break;
        car.x += commands[c].v * (commands[c].t == 2);
        car.x -= commands[c].v * (commands[c].t == 3);
        car.y += commands[c].v * (commands[c].t == 4);
        car.y -= commands[c].v * (commands[c].t == 5);
        result.status[result.num].x = car.x;
        result.status[result.num].y = car.y;
        result.status[result.num].g = car.g;
        result.num++;
        c++;
    }
    return result;
}