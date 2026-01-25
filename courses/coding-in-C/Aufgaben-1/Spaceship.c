#include <stdio.h>

void main() {
    char class [20];
    int crew_count;
    int days;
    long long distance = 6767676767;
    float lightspeed = 0.67;
    float fuel_capacity = 9876.544;
    
    printf("%-30s\n", "Enter class:");
    scanf("%s", class);
    printf("%-30s\n", "Enter crew count:");
    scanf("%d", &crew_count);
    printf("%-30s\n", "Enter days in space:");
    scanf("%d", &days);
    printf("Class: %30s\n", class);
    printf("Crew Count: %30d\n", crew_count);
    printf("Days in Space: %30d\n", days);
    printf("Distance travelled: %30lld\n", distance);
    printf("% Of light Speed: %30f\n", lightspeed);
    printf("Fuel Capacity: %30f\n", fuel_capacity);  
    getchar();
    
}