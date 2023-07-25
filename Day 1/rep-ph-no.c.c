//program to get mobile number and to find no of repeatation

#include<stdio.h>
int main() 
{ 
    
    int arr[10];
   
 
    int visited[10];

    long inp;
    int i=9;
    printf("Enter your mobile number: ");
    scanf("%ld",&inp);
  while(inp > 0) //do till num greater than  0
    {
        int mod =inp % 10;  //split last digit from number
         //print the digit. 
        
        arr[i]=mod;
        i--;
        inp = inp / 10;    //divide num by 10. num /= 10 also a valid one 
    }
    
    // int visited[9];
 
    for(int j=0; j < 10; j++){
        
        // only if unvisited
        if(visited[j] == 0){
            int count = 1;
          
            for(int k = j+1; k < 10; k++) { 
				// if appears again in the array 
				if(arr[j] == arr[k]) 
				{ // increase count & mark index visited 
					count++; 
					visited[k] = 1; 
				} 
			} 
			
            if(count > 1)
                printf("%d repeats %d times\n",arr[j],count);
        }
    }
  return 0; 
}
