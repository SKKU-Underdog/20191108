#include <stdio.h>
#define sz 1000000
int qx[sz],qy[sz],cnt[sz];
int main(){
	int n,m,tmp,front=0,rear=0,nx,ny,one=0,total=0;
	int maze[1001][1001];
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&tmp);
			maze[i][j]=tmp;
			if(tmp==0)
				total++;
			if(tmp==1)
				one++;
			if(tmp==1){
				qx[rear]=i;
				qy[rear]=j;
				cnt[rear]=0;
				rear=(rear+1)%sz;
			}
		}
	}
	if(total==0){
		printf("0\n");
		return 0;
	}
	if(one==0){
		printf("-1\n");
		return 0;
	}	
	int dx[4]={-1,1,0,0};
	int dy[4]={0,0,-1,1};
	int dday,lastday;
	while(front<rear){
		int tx=qx[front];
		int ty=qy[front];
		dday=cnt[front];
		front=(front+1)%sz;
		for(int i=0;i<4;i++){
			nx=tx+dx[i];
			ny=ty+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]==0){
				total--;
				if(total==0){
					printf("%d\n",dday+1);
					return 0;
				}
				maze[nx][ny]=1;
				qx[rear]=nx;
				qy[rear]=ny;
				cnt[rear]=dday+1;
				rear=(rear+1)%sz;
			}
		}
	}
	printf("-1\n");
	return 0;
}
