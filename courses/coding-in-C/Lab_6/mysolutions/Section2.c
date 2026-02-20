#include <stdio.h>
#include <string.h> 
struct car{
    float fuel_level;
    float max_fuel_level;
    char model[50];
  };
int refuel(struct car *c, float fuel){
    c->fuel_level += fuel;
    if ((c->fuel_level) < c->max_fuel_level){
        
        printf("New fuel level : %f\n", c->fuel_level);
    }else{
        printf("Fuel level is too high to add requestet fuel.\n");
        float excess_fuel = c->fuel_level - c->max_fuel_level;
        c->fuel_level = 1;
        printf("Excess fuel: %f\nYour tank is now full.", excess_fuel);
    }

};

int main(void) {
    struct car c1;
    c1.fuel_level = 0.08;
    c1.max_fuel_level = 1;
    strcpy(c1.model, "BMW");
    printf("Fuel level : %f\n", c1.fuel_level);
    printf("Max fuel level : %f\n", c1.max_fuel_level);
    printf("Model : %s\n", c1.model);
    refuel(&c1, 1);
}
   