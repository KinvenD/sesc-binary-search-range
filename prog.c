#include <stdio.h>
#include <stdlib.h>
  
  int K;

struct node{
  int value;
  struct node* next;
};

void add(struct node *noode, int value){
  if(noode->next==NULL){
    struct node *last = NULL;
    last = malloc(sizeof(struct node));
    last->value = value;
    last->next = NULL;
    noode->next = last;
  }else{
    add(noode->next, value);
  }
}

struct node* get(struct node *noode, int i){
  if(i==0){
    return noode;
  }else{
    return get(noode->next,i-1);
  }
}

int bi_s_p(int l, int p, struct node *head){
  if(l == p){
    return l;
  }
  if(get(head,l)->value == K){
    return l;
  }
  if(get(head,p)->value == K){
    return p;
  }
  if(get(head, (l+p)/2)->value >= K){
    return bi_s_p(l, (l+p)/2,head);
  }else{
    return bi_s_p((l+p)/2 + (l+p)%2, p,head);
  }
}

int main() {
  int i;
  int N;
  int min = -1;
  int max = -1;
  int t;
  scanf("%d", &N);
  scanf("%d", &K);
  scanf("%d", &i);
  struct node *header = NULL;
  header = malloc(sizeof(struct node));
  header->value = i;

  if(i==K){
      max = 0;
    }
  if(i==K && min == -1){
    min = 0;
  }
  
  for(int i = 0; i < N-1;i++){
    scanf("%d", &t);
    add(header,t);
  }
  int k = bi_s_p(0, N, header);
  //printf("%d", k);
  min = k;
  max = k;
  while(get(header,min)->value == K && min>-1){
    min--;
    //printf("%d \n", min);
  }
  min++;
  while(get(header,max)->value == K && max<N+1){
    max++;
  }
  max--;
  if(get(header,k)->value!=K){
      printf("-1 -1");
  }else{
  printf("%d %d", min, max);
  }
}
