#include <iostream>
using namespace std;

class myarray 
{ 
public: 
   myarray(int size); 
   ~myarray() { delete data; cout << "des" << endl; };
   long sum(); 
   int average_value(); 
   void show_myarray(); 
   int add_value(int); 


private: 
   int *data; 
   int size; 
   int index; 
}; 

myarray::myarray(int size) 
{ 
   data = new int [size]; 
   if (data == NULL) 
   { 
      cerr<< "Error memory ---- exit program" << endl; 
      exit(1); 
   } 
   myarray:: size = size; 
   myarray::index = 0; 
} 
long myarray::sum() 
{ 
   long sum = 0; 
   for (int i = 0; i < index; i++) sum += data[i]; 
   return(sum); 
} 
int myarray::average_value() 
{ 
   long sum = 0; 
   for (int i = 0; i < index; i++) sum += data[i]; 
   return (sum / index); 
} 
void myarray::show_myarray() 
{ 
   for (int i = 0; i < index; i++) cout << data[i] << ' '; 
   cout << endl; 
} 
int myarray::add_value(int value) 
{ 
   if (index == size) return(-1); // массив полон 
   else 
   { 
      data[index] = value; 
      index++; 
      return(0); // успешно 
   } 
} 


int main() 
{ 
   myarray numbers (100); // массив из 100 эл-тов 
   int i; 
   for (i = 0; i < 50; i++) numbers.add_value(i); 
   numbers.show_myarray(); 
   cout << "Sum = " << numbers.sum () << endl; 
   cout << "Average =  " << numbers.average_value() << endl; 
   return 0;
} 
