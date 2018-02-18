
/*Eric Serrano    
Vigenearey Phriang
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int *arrPtr;


int main(){

    int x, i, length;
      
    printf("How many numbers do you wish to calculate\n");// caculates how many numbers will be used
    scanf("%d", &length);

    printf("%d\n", length);  
 
    int array[length];
      
  
    puts(" Enter the numbers:");
    for (i=0; i<length; i++)
    {
    scanf("%d", &x);
    array[i]=x;
    }
    arrPtr=array;

pid_t childA, childB;
    
    childA = fork();
    
    if(childA == 0)//first child 
         getMax(arrPtr, length); 
    else {
        childB= fork();
        
        if(childB ==0){//second child
        getMin(arrPtr, length);
            
        }
        else//parent process
            getAvg(arrPtr, length);
        
    }
    
      
return 0;
}

int getMax(int *arrPtr, int length){
    
    int max = arrPtr[0];
    
    int i=0;    
    for( i = 1; length > i; i++)
    {
        if(arrPtr[i] > max)
            max = arrPtr[i];
    }
    printf("the max value is %d\n", max);
    return max;
}

int getMin(int *arrPtr, int length){
    int min = arrPtr[0];
    
    int i=0;
    for( i = 1; length > i; i++)
    {
        if(arrPtr[i]<min)
        {
            min = arrPtr[i];
        }
    }
        printf("the min value is %d\n", min);
    
    return min;
    
}
int  getAvg(int *arrPtr, int length){                                                                         
      int avg = arrPtr[0];                                                                                      
      int divided_avg;                                                                                                          
      int i=0;                                                                                                  
      for( i = 1; length > i; i++)                                                                              
      {                                                                                       
             avg = avg + arrPtr[i];                                                                                 
      }     
          divided_avg = avg/i;                                                                                       
          printf("the avg value is %d\n", divided_avg);                                                                 
                                                                                                               
      return divided_avg;                                                                                                                        
  }   
