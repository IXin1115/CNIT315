#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"
#include"cJSON.h"

int main(){
  char *usr_zipcode = malloc(5 * sizeof(*usr_zipcode));
  printf("Welcome to Weather Tracker\nPlease Enter Your Area Zipcode:");
   scanf("%s",usr_zipcode);//Store user entered zipcode
   APIcall(usr_zipcode);//Make API call and generate a xml file with the location information
   readJson();

   DisplayData();


  int cases, next,initial,days,input2,again2;
   initial = 5;
   next = 10;
   
   do {
   	 
   	 printf("\nPlease choose from the following options");
   	 printf("\n1. Display the average temperature for next 24 hours:");
   	 printf("\n2. Display the informaion for next 5 times");
   	 printf("\n3. Search the weather you want.");
   	 printf("\n4. Display the mode temperature.");
   	 printf("\n5. horizontal compare.");
   	 printf("\n6. search the max weather.");
   	 printf("\n7. Exit the program\n");
   	 
  	 printf("\nYour choice: ");
  	 scanf("%d", &cases);
  	 
  	 if(cases >=1&& cases <=7)
  	 {
  	 
   	 switch (cases)
  	 {
   		case 1:
   		CalculateAverageTemp();
   		break;
   		
   		case 2:
   	 	if(next<= 40)
   	 	{
   		DisplayNext(initial, next);
   		initial +=5;
   		next+=5;
   		}
   		else
   		{
   			printf("There are no more data to be displayed\n");
   		}
   		break;
   		
   		case 3:
   		CheckWeather();
   		break;
   		
   		case 4:
   		modeTemperature();
   		break;
   		
   		case 5:
   		
   		printf("\n input the days you want to compare.");
   		scanf("%d",&days);
   		horizontalCompare(days);
   		break;
   		
   		case 6:
	   	do{
	   
	   	printf("Please input the range(number of days)to find the highest temperature(up to 5 days which includes today): ");
	   	scanf("%d",&input2);
	   	if(input2<0 ||input2>5){
	   	printf("Invalid input! Do you want to have another try? (1 for try again, other numbers back to the main menu.");
	  	scanf("%d", &again2);
			if(again2==1){
		   	break;
		}	
	 	}
	   
	   
		}while(again2==1);
	   	findMaxTemperature(input2);
   		break;
   		
   		
   		case 7:
   		printf("Bye!!!\n");
   		exit(0);
   		break;
   	}
   	
   	}
   	else
   	{
   		printf("Please enter a valid option(1-7)!!!!!!!!\n");
   	}
   		
  	 
 	}while(cases != 7);
   
    return 0;
    
   
  
}
