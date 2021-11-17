#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <papi.h>

void matrix_filler (long double * A,long double * B,long double * C, const int  N);
void code_to_be_measured (const long double * A, const long double * B, long double * C, const int N);
void average(const long double * M, const int N);
void Papic(const int until);

int main (int argc, char **argv)
{

int until= std::atoi (argv [1]);
Papic(until);

    return 0; 
}

void Papic(const int until)
{
 
for (int N=2; N<=until; N=2*N){
 
  long double *A=new long double [N*N];
  long double *B=new long double [N*N];
  long double *C=new long double [N*N]; 
 
matrix_filler (A,B,C,N);


float real_time, proc_time,mflops;
long long flpops;
float ireal_time, iproc_time,imflops;
long long iflpops;
int retval;


if ((retval=PAPI_flops_rate(PAPI_FP_OPS, &ireal_time,&iproc_time,&iflpops,&imflops))< PAPI_OK)
  {
    printf("Could not initialise PAPI_flops \n");
    printf("Your platform may not support floating point operation event. \n");
    printf("retval: %d\n", retval);
    exit(1);
  }
  
code_to_be_measured(A,B,C,N);

if ((retval=PAPI_flops_rate(PAPI_FP_OPS, &real_time,&proc_time,&flpops,&mflops))< PAPI_OK)
   {
     printf("retval: %d\n", retval);
     exit(1);
   }
 
std::cout << N << " " << proc_time<<" "<<mflops<<std::endl;

average(C,N);

delete [] A;
delete [] B;
delete [] C;

}

}


void code_to_be_measured(const long double * A, const long double * B, long double * C, const int N)
{

  int BO=8;
  int blocksize=0;
 if(N/BO>1){blocksize=N/BO;}
 else {blocksize=N;}

   for (int i = 0; i < N; i += blocksize) {
     for (int h=0;h < N;++h){
       for (int j = 0; j < N; j += blocksize) {
         for (int k = i; k < i + blocksize; ++k) {
           for (int l = j; l < j + blocksize; ++l) {
                C[k+(h*N)]=3.1416*C[k+(h*N)]+(A[l]*B[k+l*N]);                //C[k+N+(N*h)]=C[k+N+(N*h)]+(A[l+N]*B[k+l*N]);
       }
      }
     }
    }
   }
   
}

void average(const long double * M, const int N){

long double FF=0.0;
  for(int x=0;x<N;x++)  // loop 3 times for three lines
    {
        for(int y=0;y<N;y++)  // loop for the three elements on the line
        {
          FF+=M[x*N + y];// display the current element out of the array
        }
    }
long double prom =0.0;
 prom =FF/(N*N);
     std::cout<<" # Promedio matriz es : "<<prom<<std::endl;
 }

void matrix_filler (long double * A,long double * B,long double * C, const int  N)
{
  for (int ii = 0; ii < N;  ++ii)
    {
      for (int jj = 0; jj < N; ++jj)
        {
          A[ii*N + jj] = 1;
          B[ii*N + jj] = 1;
          C[ii*N + jj] = 0;
        }
    }
  
}
