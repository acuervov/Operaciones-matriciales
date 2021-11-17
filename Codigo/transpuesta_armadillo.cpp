#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<armadillo>
#include "papi.h"

using namespace arma;

int code_to_be_measured(Mat<double> P, Mat<double> & R);
double average(Mat<double> R, const int N);

int main(int argc,char **argv){
  const int N = std::atoi(argv[1]);
  int D = 2;
  
  while(D <= N){
    Mat<double> A(D, D, fill::randu);
    Mat<double> AT = zeros<Mat<double>>(D, D);

    float real_time, proc_time,mflops;
    long long flpops;
    float ireal_time, iproc_time, imflops;
    long long iflpops;
    int retval;

    if((retval=PAPI_flops_rate(PAPI_FP_OPS,&ireal_time,&iproc_time,&iflpops,&imflops)) < PAPI_OK){
      std::cout<<"Could not initialise PAPI_flops\n";
      std::cout<<"Your platform may not support floating point operation event.\n";
      printf("retval: %d\n", retval);
      exit(1);
    }

    code_to_be_measured(A, AT);

    if((retval=PAPI_flops_rate(PAPI_FP_OPS,&real_time, &proc_time, &flpops, &mflops))<PAPI_OK){
      printf("retval: %d\n", retval);
      exit(1);
    }
    //printf("Real_time: %f Proc_time: %f Total flpops: %lld MFLOPS: %f\n", real_time, proc_time,flpops,mflops);
    std::cout<<D<<" "<<proc_time<<" "<<mflops<<std::endl;
    std::cout<<"#promedio: "<<average(AT, D)<<std::endl;
    
    D = D + D;
  }
    return 0;
}

int code_to_be_measured(Mat<double> P, Mat<double> & R){
  R = 2.3456*P.t();
  return 0;
}

double average(Mat<double> R, const int N){
  double sum = 0.0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      sum += R(j*N + i); //en armadijo utilizan el column-major ordering
    }
  }

  return sum/(N*N);
}
