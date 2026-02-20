#include <stdio.h>
#include <string.h>


struct SensorData {
    float time;
    double probability;
};

struct Sensor {
    int id;
    double threshold;
    struct SensorData data[3001]; 
    int object_detention[3001]; 
};
int ObjectDetection(struct Sensor *s, int index, double threshold);
int main(){
    struct Sensor s1, s2;
    
    ObjectDetection(&s1, 1, 0.8);
    ObjectDetection(&s2, 2, 0.7);
    printf("Fused Signal : ");
    int check = 0;
     for (int i = 0; i < 3000; i++){
        if(s1.object_detention[i] == 1 && s2.object_detention[i] == 1){
            if(check == 0){
            printf("Start: %f ", s1.data[i].time);
            check = 1;
            
            
            }
        }else if(check == 1){
            printf("Ende: %f ", s1.data[i-1].time);
            check = 0;
        }
    }
}


int ObjectDetection(struct Sensor *s, int index, double threshold){
    char filename[256];
    snprintf(filename, sizeof(filename), "C:\\Users\\yasin\\Programmieren1\\courses\\coding-in-C\\Lab_6\\sensor%d.txt", index);
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Fehler beim Öffnen der Datei f%d.\n", index);
        return 1;
    }
    s->id = index;
    s->threshold = threshold;
    printf("Sensor %d Detections:\n", s->id);
    int check = 0;
    for(int i = 0; i < 3000; i++){
        
        fscanf (f, "%f %lf", &s->data[i].time, &s->data[i].probability);
        //printf("Time: %f\n", s->data[i].time);
        //printf("Probability: %lf\n", s->data[i].probability);
        if(s->data[i].probability > s->threshold){
            s->object_detention[i] = 1;
            if (check == 0){
                printf("Start detection: %f\n", s->data[i].time);
                check = 1;
            }
        }else{
            s->object_detention[i] = 0;
            if(check == 1){
                printf("End detection: %f\n", s->data[i - 1].time);
                check = 0;
             }
            }
    }
    fclose(f);
    return s->object_detention[3000];
}