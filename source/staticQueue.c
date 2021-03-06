#include "../include/includes.h"

void initQueue(queue* q, int tamanho){
	q->start = -1;
	q->end = -1;
	q->tam = tamanho;
}

int emptyQueue(queue* q){
	return q->end == -1 && q->start == -1;
}

int fullQueue(queue *q){
	return q->end == q->start - 1;
}

void push(queue* q, item_type x){
	if(fullQueue(q)){
		printf("Full Queue!!\n");
		return;
	}
	if(emptyQueue(q))
		q->start += 1;
	q->end = (q->end + 1) % q->tam;
	q->body[q->end] = x;
}

item_type front(queue* q){
	return q->body[q->start];
}

item_type pop(queue* q){
	player lixo;
	lixo.ID = -1;
	if(emptyQueue(q))
		return lixo;

	item_type return_ = q->body[q->start];
	if(q->start == q->end){
		q->start = -1;
		q->end = -1;
	}else{
		q->start = (q->start + 1) % q->tam;
	}
	q->start = q->start % q->tam;
	return return_;
}

void clearQueue(queue* q){
	q->start = -1;
	q->end = -1;
}
/*
void printQueue(queue* q){
	int i;
	if(emptyQueue(q)){
		printf("Empty Queue!");
	}else{
		for(i = q->start; i != q->end + 1; i = (i + 1 % q->tam))
			printf("%d ", q->body[i]);
		printf("\n");
	}
}
*/
