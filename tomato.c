#include<stdio.h>
#define QSIZE 1000000
#define SIZE 1000

int queue[QSIZE][2];
int front,rear;
int map[SIZE][SIZE];

int IsEmpty(){
	if(rear-front == 0)
		return 1;
	else
		return 0;
}

int IsFull(){
	if(((rear+1)-front)%QSIZE == 0)
		return 1;
	else
		return 0;
}



int enqueue(int x,int y){
	if(!IsFull()){
	
		queue[rear][0] = x;
		queue[rear][1] = y;
		rear = (rear+1)%QSIZE;

		return 1;
	}

	return 0;
}

int main(){

	int x,y;
	int i,j;
	int qx,qy;
	int max;
	int flag;
	int chgx[4]={1,0,-1,0},chgy[4]={0,1,0,-1};

	scanf("%d %d",&y,&x);
	front = 0;
	rear = 0;

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j] == 1){
				enqueue(i,j);
			}
		}
	}

	while(!IsEmpty()){
		qx = queue[front][0];
		qy = queue[front][1];
		front = (front+1)%QSIZE;

		for(i=0;i<4;i++){
			if(qx+chgx[i] >= 0 && qx+chgx[i] < x && qy+chgy[i] >=0 && qy+chgy[i] < y && map[qx+chgx[i]][qy+chgy[i]] == 0){
				map[qx+chgx[i]][qy+chgy[i]] = map[qx][qy] +1;
				enqueue(qx+chgx[i],qy+chgy[i]);
			}
		}
	}

	max = -1;
	flag = 0;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(map[i][j] == -1)
				continue;
			if(map[i][j] == 0){
				flag = 1;
				break;
			}
			if(max < map[i][j])
				max = map[i][j];
		}
		if(flag)
			break;
	}

	if(flag){
		printf("-1");
	}

	else{
		printf("%d",max-1);
	}

	return 0;
}
