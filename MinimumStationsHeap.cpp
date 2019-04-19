#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * sample input
    8
    1 6
    4 5
    3 4
    1 4
    4 6
    4 7
    3 6
    5 8 
 */

class Timing{
	public:
	int arr;
	int dep;
};

class mycomparator{
	bool reverse;
	public:
	mycomparator(bool reverse=false){
		this->reverse = reverse;
	}
	bool operator() (const Timing &a,const Timing &b){
		return reverse?(a.arr > b.arr):(a.arr < b.arr);
	}
};

int main() {
	// your code goes here
	int k=0;
	cout<<"Enter array size between 1 and 100:";
	cin>>k;
	
	cout<<"Enter arrival times and departure times:";
	
	Timing t[k];
	priority_queue<int,vector<int>,greater<int>> q;//min heap
	int minStations=0, currStations=0;
	if(k>0 && k<=100){
		for(int i=0;i <k;i++){
			cin>>t[i].arr>>t[i].dep;
		}
		sort(t,t+k-1,mycomparator());
		for(int i=0;i<k;i++){
			cout<<"\n"<<t[i].arr<<" arrived";
			while(!q.empty() && q.top()<=t[i].arr){
				currStations--;
				int temp = q.top();
				q.pop();
				cout<<"\n"<<temp<<" left";
			}
			q.push(t[i].dep);
			
			currStations++;
			if(minStations<currStations)
				minStations = currStations;
		}
		while(!q.empty()){
			cout<<"\n"<<q.top()<<" left";
			q.pop();
		}
		cout<<"\n min stations: "<<minStations<<endl;
	}
	
	return 0;
}