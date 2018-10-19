#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int *a, *b, *c;
int n, nth;

void *soma(void *arg){
    int tid=(int)arg;
    int i;
    for(i=tid;i<n;i+=nth){
        c[i]=a[i]+b[i];
    }
}

void print_v(int *v,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    n=atoi(argv[1]);
    nth=atoi(argv[2]);
    int i;
    pthread_t *t=(pthread_t*)malloc(nth*sizeof(pthread_t));

    a=(int*) malloc(n*sizeof(int));
    b=(int*) malloc(n*sizeof(int));
    c=(int*) malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        a[i]=rand()%n;
        b[i]=rand()%n;
    }
    for(i=0;i<nth;i++){
        pthread_create(&t[i],NULL,soma,(void*)i);
    }
    for(i=0;i<nth;i++){
        pthread_join(t[i],NULL);
    }
    print_v(a,n);
    print_v(b,n);
    print_v(c,n);
}
