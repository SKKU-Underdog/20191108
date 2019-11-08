#include <iostream>
#include <deque>
using namespace std;

int arr[1000][1000];
int N,M,day=0;
deque< pair <int, int> >q;
deque<int> dayq;
void print_state(){
	cout << "****************"<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "****************"<<endl;
}

int chk_finish(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j]==0)
				return 0;
		}
	}
	return 1;
}

void spread(int i,int j,int day){
	int num_spread = 0;
	if(j+1 <M && arr[i][j+1] == 0){ //east
		q.push_back(make_pair(i,j+1));
		dayq.push_back(day+1);
		arr[i][j+1] = 1;
	}
	if(j-1 >=0&& arr[i][j-1] ==0){ //west
		q.push_back(make_pair(i,j-1));
		dayq.push_back(day+1);
		arr[i][j-1] = 1;
	} 
	if (i+1<N && arr[i+1][j] ==0 ){ //
		q.push_back(make_pair(i+1,j));
		dayq.push_back(day+1);
		arr[i+1][j] = 1;
	}
	if(i-1>=0 && arr[i-1][j]==0){ //
		q.push_back(make_pair(i-1,j));
		dayq.push_back(day+1);
		arr[i-1][j] = 1;
	}

	return;
}


int day_after(){
	int num_ripe=0;
	int day_num=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j] == 1){
				q.push_back(make_pair(i,j));
				dayq.push_back(0);
			}
		}
	}
	while(1){
		if(q.empty())
			break;
		pair<int ,int> cur = q.front();
		q.pop_front();
		day = dayq.front();
		dayq.pop_front();
		spread(cur.first,cur.second,day);	
	}
		if(chk_finish()){
			return day;
		}
		else
			return -1;
}


int main() {
	cin >> M >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> arr[i][j];
		}
	}
	if(chk_finish() == 1){
		cout << day << endl;
		return 0;
	}
	day = day_after();
	cout << day;
	return 0;
}
