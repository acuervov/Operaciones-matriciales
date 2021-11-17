#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <papi.h>
#include <fstream>

void matrix_filler (long double * A,long double * B, long double * C, const int  N);
int code_to_be_measured (const long double * A,const  long double * B, long double * C, const int N, const int D);
void average(const long double * M, const int N);

int main (int argc, char **argv)
{
  const int N=std::atoi(argv[1]);

 long double *A=new long double [N*N];
 long double *B=new long double [N*N];
 long double *C=new long double [N*N];

  
float real_time, proc_time,mflops;
long long flpops;
float ireal_time, iproc_time,imflops;
long long iflpops;
int retval;


 for (int D=1; D<=N;D=2*D)
  {

    matrix_filler (A,B,C,N);
  
if ((retval=PAPI_flops_rate(PAPI_FP_OPS, &ireal_time,&iproc_time,&iflpops,&imflops))< PAPI_OK)
  {
    printf("Could not initialise PAPI_flops \n");
    printf("Your platform may not support floating point operation event. \n");
    printf("retval: %d\n", retval);
    exit(1);
  }
  
code_to_be_measured(A,B,C,N,D);

 if ((retval=PAPI_flops_rate(PAPI_FP_OPS, &real_time,&proc_time,&flpops,&mflops))< PAPI_OK)
   {
     printf("retval: %d\n", retval);
     exit(1);
   }

 
std::cout << D << " " << proc_time<<" "<<mflops<<std::endl;
 
 average (C, N);

 
 }
 delete []A;
 delete []B;
 delete []C;
 
    return 0; 
}





int code_to_be_measured(const long double * A,const  long double * B,long double * C, const int N, const int D)
{
  
  
  int blocksize =N/D;
  
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

  return 0; 
}

void average(const long double * M, const int N){

long double FF=0.0;
  for(int x=0;x<N;x++)  
    {
        for(int y=0;y<N;y++)  
        {
          FF += M[x*N + y];
        }
    
    }

  
 long double prom =0.0;
  prom=FF/(N*N);

      std::cout<<"# Promedio: "<< prom<<std::endl;  
 }

void matrix_filler (long double * A,long double * B,long double * C, const int  N)
{
  for (int ii = 0; ii < N;  ++ii)
    {
      for (int jj = 0; jj < N; ++jj)
        {
          A[ii*N + jj] = ii+2;
          B[ii*N + jj] = ii+1;
          C[ii*N + jj] = 0; 
        }
    }
  
}
