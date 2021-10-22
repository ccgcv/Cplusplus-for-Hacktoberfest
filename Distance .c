CR, [20.10.21 13:45]
/*Program to read two input each representing the distances between two points in the Eucliean space,store these in structural variables and add the two distance values.
Name: Sherin Alosious
Class:ECE B
Roll no:37*/
#include<stdio.h>
int main()
{
struct euclidian
{
int distance;
  }
  d,d1;
{
 int sum=0;
   printf("\nEnter the distance between first two points:");
   scanf("%d",&d.distance);
   printf("\nEnter the distance between another two points:");
   scanf("%d",&d1.distance);
   sum=d.distance+d1.distance;
   printf("\nTotal distance = %d",sum);
   return 0;
    }
}
