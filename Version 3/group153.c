#include <stdio.h>
#include <stdlib.h>
#define num_cars 4

typedef struct{
  char name[30];
  float rentrate;
  int available;
}car;

car cars[num_cars]={
{"Range Rover",70.0,1},
{"Rolls Royce",90.0,1},
{"Bugatti",100.0,1},
{"Ferrari",120.0,1}
};\

void displayavailablecars(){
printf("\nAvailable Cars\n");
for(int i=0;i<num_cars;i++){
    if (cars[i].available){
        printf("%d.%s  -$%.2f/per day\n",i+1,cars[i].name,cars[i].rentrate);
    }
}
}
void displayrentedcars(){
printf("\nRented cars\n");
for(int i=0;i<num_cars;i++){
    if(!cars[i].available){
        printf("%d.%s \n",i+1,cars[i].name);
    }
}
}


void rentcar(int num,int days,char name[40]){
    if(days<=0){
        printf("\nInvalid Days\n");
        return;
    }
    if(cars[num].available){
        cars[num].available=0;
        printf("\nCongratulations!! %s\nYou have sucessfully rented %s for %ddays.\nTotal cost=$%.2f \n",name,cars[num].name,days,cars[num].rentrate*days);
    }else{
    printf("%s is not available\n",cars[num].name);
    }
}



void returncar(int num){
if(!cars[num].available){
  cars[num].available=1;
printf("You have sucessfully Returned %s\n Thank you for working with us\n",cars[num].name);
}else{
printf("\n%s is already available\n",cars[num].name);
}
}

int main()
{
        int choice,carnum,days;
        
        char name[40];
    printf("Please Enter Your name: ");
   fgets(name,40,stdin);
  printf("\n*\nWelcome to Group 15 car rentals\n**\n");
  while(1){
    printf("\n1.View Available cars\n2.Rent a Car\n3.Return a Car\n4.Exit\nEnter your service for today: ");
    scanf("%d",&choice);

    switch(choice){
case 1:
    displayavailablecars();
    break;
case 2:
    displayavailablecars();
    printf("select a car of choice (1-%d): ",num_cars);
    scanf("%d",&carnum);
    if(carnum>=1 && carnum<=num_cars){
        printf("Enter number of days: ");
        scanf("%d",&days);
        if(days>=1){
        rentcar(carnum-1,days,name);
        }else{
        printf("\nEnter correct number of days!!\n");
        }
    }else{
    printf("\ninvalid selection\n");
    }
    break;
case 3:
    displayrentedcars();
    printf("\nEnter car number to return (1-%d): ",num_cars);
    scanf("%d",&carnum);
    if(carnum>=1 && carnum<=num_cars){
        returncar(carnum-1);
    }else{
    printf("\nInvalid Selection");
    }
    break;

case 4:
    printf("\nGoodbye!! %s\n",name);
    return 0;
    default :
    printf("\nInvalid selection");
    }
  }
    return 0;
}