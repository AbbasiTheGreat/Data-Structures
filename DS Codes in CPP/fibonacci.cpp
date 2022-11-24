#include<iostream>
using namespace std;
 
int Fibonacci(int);
 
int main()
{
   int n=7, i = 0, c;
 
   printf("Fibonacci series\n");
 
   for ( c = 1 ; c <= n ; c++ )
   {
      cout<<(Fibonacci(i))<<" "; 
      i++; 
   }
 
   return 0;
}
 
int Fibonacci(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( Fibonacci(n-1) + Fibonacci(n-2) );
}
