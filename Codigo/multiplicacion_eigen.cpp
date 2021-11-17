#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<eigen3/Eigen/Dense>
#include "papi.h"

int code_to_be_measured(Eigen::MatrixXd P, Eigen::MatrixXd Q, Eigen::MatrixXd & R);
double Average(Eigen::MatrixXd R, const int M);

int main(int argc,char **argv){
  const int N = std::atoi(argv[1]);
  int D = 2;
  int l = 5;
  
  while(D <= N){
    srand(l);
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(D,D); 
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(D,D);
    Eigen::MatrixXd C(D, D);
    
    for(int ii = 0; ii < D; ii++){
      for(int jj = 0; jj < D; jj++){
        C(ii*D + jj) = 0.0;
      }
    }

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

    code_to_be_measured(A, B, C);

    if((retval=PAPI_flops_rate(PAPI_FP_OPS,&real_time, &proc_time, &flpops, &mflops))<PAPI_OK){
      printf("retval: %d\n", retval);
      exit(1);
    }
    //printf("Real_time: %f Proc_time: %f Total flpops: %lld MFLOPS: %f\n", real_time, proc_time,flpops,mflops);
    std::cout<<D<<" "<<proc_time<<" "<<mflops<<std::endl;
    std::cout<<"#promedio: "<<Average(C,D)<<std::endl;
    D = D + D;
    l = l + 1;
  }
  return 0;
}

int code_to_be_measured(Eigen::MatrixXd P, Eigen::MatrixXd Q, Eigen::MatrixXd & R){
  R = (P * Q).eval();
  return 0;
}

double Average(Eigen::MatrixXd R, const int M){
  double sum = 0;
  for(int ii = 0; ii < M; ii++){
    for(int jj = 0; jj < M; jj++){
      sum += R(ii*M + jj);
    }
  }
  return sum/(M*M);
}
