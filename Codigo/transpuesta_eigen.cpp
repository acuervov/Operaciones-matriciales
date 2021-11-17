#include<iostream>
#include<cstdio>
#include<cstdio>
#include<eigen3/Eigen/Dense>
#include "papi.h"
#include <iomanip>

using namespace std;

double Average(const Eigen::MatrixXd M, const int N);
int code_to_be_measured(const Eigen::MatrixXd & M, Eigen::MatrixXd & MT);

int main(int argc, char **argv){
  const int N = atoi(argv[1]);
  int D = 2;
  std::cout<<std::setprecision(10);

  while(D <= N){

    Eigen::MatrixXd A(D, D), AT(D, D);

    for(int ii = 0; ii < D; ii++){
      for(int jj = 0; jj < D; jj++){
        A(ii*D + jj) = ii + jj + 0.99;
        AT(ii*D + jj) = 0.0;
      }
    }

    float real_time, proc_time,mflops;
    long long flpops;
    float ireal_time, iproc_time, imflops;
    long long iflpops;
    int retval;



    if((retval=PAPI_flops_rate(PAPI_FP_OPS,&ireal_time,&iproc_time,&iflpops,&imflops)) < PAPI_OK){
        printf("Could not initialise PAPI_flops \n");
        printf("Your platform may not support floating point operation event.\n");
        printf("retval: %d\n", retval);
        exit(1);
    }

    code_to_be_measured(A, AT);

    if((retval=PAPI_flops_rate(PAPI_FP_OPS,&real_time, &proc_time, &flpops, &mflops))<PAPI_OK){
        printf("retval: %d\n", retval);
        exit(1);
    }
    //printf("Real_time: %f Proc_time: %f Total flpops: %lld MFLOPS: %f\n", real_time, proc_time,flpops,mflops);
    //std::cout<<D<<"\t"<<real_time<<"\t"<<proc_time<<"\t"<<flpops<<"\t"<<mflops<<"\t"<<Average(A, D)<<"\n";
    std::cout<<D<<" "<<proc_time<<" "<<mflops<<std::endl;
    std::cout<<"#promedio: "<<Average(AT,D)<<std::endl;
    //printf("%.15e\n", AT(0));

    D = D + D;
  }

  return 0;
}

int code_to_be_measured(const Eigen::MatrixXd & M, Eigen::MatrixXd & MT){
  MT = 2.3456*M.transpose().eval();
  return 0;
}

double Average(const Eigen::MatrixXd M, const int N){
  double sum = 0;
  for(int ii = 0; ii < N; ii++){
    for(int jj = 0; jj < N; jj++){
      sum += M(ii*N + jj);
    }
  }
  return sum/(N*N);
}
