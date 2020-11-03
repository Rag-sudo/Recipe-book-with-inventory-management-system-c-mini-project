#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct inven
{
 int Sno,w;
 char Iname[20];
}
p[10];
int main()
{
 int n,i,ch,weight;
 char iname[20];
 printf("\nHow Many Items do you want to add? : ");
 scanf("%d",&n);
 printf("-----------------------------------\n");
 for(i=0;i<n;i++)
 {
  printf("Enter the details of the item : %d",i+1);
  printf("\n-------------------------------\n");
  printf("Serial no. : ");
  scanf("%d",&p[i].Sno);
  printf("Item Name : ");
  scanf("%s",&p[i].Iname);
  printf("Weight of the item in kilograms : ");
  scanf("%d",&p[i].w);
  printf("\n----------------------------\n");
 }
 while(1)
 {
  printf("\n\t\tMENU\n");
  printf("----------------------------------------\n");
  printf("\n1.Specific Items");
  printf("\n2.Specific Weights");
  printf("\n3.All Items");
  printf("\n4.Exit");
  printf("\n----------------------------------------\n");
  printf("\nEnter Your Choice : ");
  scanf("%d",&ch);
  switch(ch)
 {
   case 1:
	  printf("Enter item Name : ");
	  scanf("%s",iname );
	  for(i=0;i<n;i++)
	  {
	   if(strcmp(p[i].Iname,iname)==0)
	   printf("\n Item Number : %d\nItem name : %s\nItem Weight : %s",p[i].Sno,p[i].Iname[20],p[i].w);
	  }
	  break;
   case 2:
	  printf("Enter Item Weight :");
	  scanf("%d",weight);
	  for(i=0;i<n;i++)
	  {
	   if(p[i].w==weight)
	   {
	    printf("Item Number : %d\n",p[i].Sno);
	    printf("item Name : %s\n",p[i].Iname);
	    printf{"Item Weight : %s\n",p[i].w);
	    printf("\n---------------------\n");
	   }
	  }
	  break;
   case 3:
	  for(i=0;i<n;i++)
	  {
	   printf("Item Number : %d\n",p[i].Sno);
	   printf("Item Name : %s\n",p[i].Iname);
	   printf("Item Weight in Kilograms : %d",p[i].w);
	   printf("\n-------------------------\n");
	  }
	  break;
   case 4:
	  exit(0);
  }
 getch();
 return 0;
}
}
