#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[1000][1000];
int N,M;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int cnt;
int check_map(){
	for(int i = 0; i<M; i++){
		for(int j = 0; j<N ; j++){
			if(map[i][j] == 0) return -1;
		}
	}
	return 1;
}


int main(){
	cin >> N >> M;
	queue<pair<int,int> > q;
	queue<int> count;
	for(int i = 0; i<M ; i++){
		for(int j = 0 ; j<N; j++){
			cin >> map[i][j];
			if(map[i][j] == 1){
				q.push(make_pair(i,j));
				count.push(0);

			}
		}
	}
	if(check_map() == 1){
		cout << '0' << endl;
		return 0;
	}
	int x = 0;
	int y = 0;
	while(1){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i = 0 ; i<4 ; i++){
			if(x+dx[i] >= M || y+dy[i] >= N || x+dx[i] < 0 || y+dy[i] < 0){
				continue;
			}
			if(map[x+dx[i]][y+dy[i]] == 0){
				map[x+dx[i]][y+dy[i]] = 1;
				q.push(make_pair(x+dx[i],y+dy[i]));
				count.push(count.front()+1);
			}
		}
		if(q.empty()){
			if(check_map() == 1){
				cout << count.front() << endl;
			}
			else{
				cout << "-1"<<endl;
			}
			break;
		}
		/*
		if(check_map() == 1){
			cout << count.front() << endl;
			break;
		}*/
		count.pop();
	}
	return 0;
}
