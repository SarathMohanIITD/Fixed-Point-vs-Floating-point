#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include "../include/fixedarithemetic.h" // For float to fixed conversion
#include "../include/timer.h" // Including function to calculate time
const int shift = 8; //Setting the Fixed Point

void main()
{   
    int i,n=2; 
    FILE *fp; // Initializing file pointer
    fp = fopen("src/plotdata.dat","w+");
    srand(n); // Setting different seed values in each iteration
    double a = rand()*10.0; //Scale factor
    while(n<=500){
        //Dynamic initialization of 2D array
        double **arr1 = (double **)malloc(n * sizeof(double *)); //Array 1
    	for (i=0; i<n; i++)
         	arr1[i] = (double *)malloc(n * sizeof(double));  
    	
    	double **arr2 = (double **)malloc(n * sizeof(double *)); // Array 2 
    	for (i=0; i<n; i++)
        	arr2[i] = (double *)malloc(n * sizeof(double));
    	
    	double **result = (double **)malloc(n * sizeof(double *));  //Result 	
    	for (i=0; i<n; i++)
         	result[i] = (double *)malloc(n * sizeof(double));         	
        
        long long **temp1 = (long long **)malloc(n * sizeof(long long *));   //Temp array to store Fixed point Array 1	
    	for (i=0; i<n; i++)
         	temp1[i] = (long long *)malloc(n * sizeof(long long)); 
         	
        long long **temp2 = (long long **)malloc(n * sizeof(long long *));   //Temp array to store Fixed point Array 2	
    	for (i=0; i<n; i++)
         	temp2[i] = (long long *)malloc(n * sizeof(long long));                        
  
        // Generating Floating point number using rand()
        for(int i =0;i < n;i++){
            for(int j =0;j<n;j++){
                    arr1[i][j]=(float)rand()/(float)(RAND_MAX)* a; 
                    arr2[i][j]=(float)rand()/(float)(RAND_MAX)* a;
                }
        }
        
        // Floating point Matix Multiplication
        clock_t start1 = clock();         // Start timer 1
        for(int i =0;i <n;i++){
            for(int j =0;j<n;j++){
                double sum=0.0;
                for(int k=0;k<n;k++){
                    sum+=arr1[i][k] * arr2[k][j];
                }
                result[i][j]=sum;
            }
        }
        clock_t stop1 = clock();           //Stop timer 1      
        double time_spent1 = calctime(start1,stop1); // Function to calculate time      
        
        //Fixed Point Matrix Multiplication   
        	//Conversion of floating point to fixed point     
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp1[i][j]=DoubleToFixed(arr1[i][j],shift); 
                temp2[i][j]=DoubleToFixed(arr2[i][j],shift);
            }
        }
        clock_t start2 = clock();                 // Start timer 2
        for(int i =0;i <n;i++){
            for(int j =0;j<n;j++){
                long long sum=0;
                for(int k=0;k<n;k++){
		    long long c = MulFixed(temp1[i][k],temp2[k][j],shift);
                    sum = AddFixed(sum,c,shift);
                }
                result[i][j]=FixedToDouble(sum,shift);    
            }
        }
        clock_t stop2 = clock();                   //Stop timer 2
        double time_spent2 = calctime(start2,stop2);
        fprintf(fp,"%d\t%f\t%f\n",n,time_spent1,time_spent2); //Writting to a file
        if(n==2)	n=0;
        n+=50;   
    }
    fclose(fp);
}




