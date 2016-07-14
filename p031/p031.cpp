#include <iostream>
#include <boost/timer.hpp>
#include <vector>
using namespace std;

int denoms[] = {200,100,50,20,10,5,2,1};

int make_change(int n,int index) {
	static vector<vector<int> > memo;
	static bool isdefined = false;	
	if (!isdefined) {	
		for (int i = 0; i <= n; i++) {
			vector<int> temp;
			for (int j = 0; j < sizeof(denoms)/sizeof(int); j++ ) {
				temp.push_back(0);
			}
			memo.push_back(temp);
		}	
		isdefined = true;
	}

	int sum = 0;
	if (memo[n][index]) {
		return memo[n][index];
	}
	if (index == sizeof(denoms)/sizeof(int)	-1) {
		return 1;
	}
	for (int i = 0; i*denoms[index] <= n; i++ ) {
		if (n == i * denoms[index])  {
			sum ++;
		} else {
			sum += make_change(n-i*denoms[index],index+1);
		}
	}
	memo[n][index] = sum;
	return sum;
}


int main(int argc,const char *argv[]) {

	boost::timer t;
	int amount = 200;
	
	cout << make_change(amount,0) << endl;
	cout << t.elapsed()*1000 << "ms" << endl;

}
