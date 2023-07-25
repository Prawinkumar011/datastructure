//reverse phone number//
#include <stdio.h>

int main()
{
   int a[9];
   printf("please enter your 10-dig ph-number with a space");
   for(int i=0;i<10;i++){
       scanf("%d",&a[i]);
   }
   printf("reverse of your mobile number:");
    for(int i=9;i>=0;i--){
       printf("%d",a[i]);
   }
}
