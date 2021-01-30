#include<stdio.h>

typedef struct Object
{
    char name[10];
    int value;
    int weight;
    double valuePerWeight;
    int quantity;
}Object;

int main(){
    FILE * fpointer = fopen("BAG.INP", "r");

    int numOfObject, maxWeight;
    fscanf(fpointer,"%d %d", &numOfObject, &maxWeight); //Scan number of object and maximum weight
    Object list[numOfObject];

    //Calculate value per weight
    for(int i = 0; i < numOfObject; i++){
        fscanf(fpointer,"%d %d %s", &list[i].weight , &list[i].value, list[i].name);
        list[i].valuePerWeight = (double)list[i].value / list[i].weight;
    }
    fclose(fpointer);

    //Sort list object to decreasing order
    for(int i = 0; i < numOfObject; i++){
        for(int j = i; j <numOfObject; j++){
            if(list[i].valuePerWeight < list[j].valuePerWeight){
                Object temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    //Calculate the total value and quantity of each object
    int valueSum = 0;
    for(int i = 0; i < numOfObject; i++){
        list[i].quantity = maxWeight / list[i].weight;
        valueSum += list[i].value * list[i].quantity;
        maxWeight = maxWeight % list[i].weight;
    }
    printf("%d\n", valueSum);

    //Print out the name and quantity of objects used
    for(int i = 0; i < numOfObject; i++){
        if(list[i].quantity != 0)
            printf("%s %d\n", list[i].name, list[i].quantity);
    }

    return 0;
}