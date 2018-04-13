#include<stdio.h>
#include<pthread.h>


#define SIZE 25

int fib_arr[SIZE]; 
void *fibonachi(void *n); 

int main(int argc,char *argcv[] ){

 int num;
 int x;

 pthread_attr_t attr;

 if(argc !=2){
  printf("Please insert one command line argument\n");
  return -1;
 }
 num=atoi(argcv[1]); 

 if(num<0){
  printf("To Countinue please enter non-negative number\n");
 }
 else{
  pthread_attr_init(&attr);
  pthread_t tid; 
  pthread_create(&tid,&attr,fibonachi,num); 
  pthread_join(tid,NULL);

  printf(" - Programs Out put - \n");
  printf("\n");
  printf("Set of Fibonachi numbers.........\n");

  for(x=0; x<num; x++){

   printf("%d ",fib_arr[x]);
  }
  printf("\n");
  
 }
 return 0;
}

void *fibonachi(void *n){

 int x = 0;
 int y = 1;
 int fibn=0;
 int i;
 
 for(i=1; i<=n; i++){
  fib_arr[i-1]=fibn;
  fib_arr[i-1]=fibn;
  fib=x+y;
  x=y;
  y=fibn;
}
pthread_exit(0);
}
