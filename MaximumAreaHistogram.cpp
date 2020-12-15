#include<bits/stdc++.h>
using namespace std;

vector<int>nextSmallerRight(int *input, int n) {
	int pseudoIndex = n;
	stack<pair<int, int>> s;
	vector<int> v;
	for(int i=n-1;i>=0;i--) {
		if(s.size() == 0) {
			v.push_back(pseudoIndex);
		} else if(s.size() > 0 && s.top().first < input[i]) {
			v.push_back(s.top().second);
		} else if(s.size() > 0 && s.top().first >= input[i]) {
			while(s.size() > 0 && s.top().first >= input[i]) {
				s.pop();
			}
			if(s.size() == 0) {
				v.push_back(pseudoIndex);
			} else {
				v.push_back(s.top().second);
			}
		}
		s.push({input[i], i});
	}
	reverse(v.begin(), v.end());
	return v;
}

vector<int>nextSmallerLeft(int *input, int n) {
	int pseudoIndex = -1;
	stack<pair<int, int>> s;
	vector<int> v;
	for(int i=0;i<n;i++) {
		if(s.size() == 0) {
			v.push_back(pseudoIndex);
		} else if(s.size() > 0 && s.top().first < input[i]) {
			v.push_back(s.top().second);
		} else if(s.size() > 0 && s.top().first >= input[i]) {
			while(s.size() > 0 && s.top().first >= input[i]) {
				s.pop();
			}
			if(s.size() == 0) {
				v.push_back(pseudoIndex);
			} else {
				v.push_back(s.top().second);
			}
		}
		s.push({input[i], i});
	}
	return v;
}

int maximumArea(int *input, int n) {
	vector<int> left = nextSmallerLeft(input, n);
	vector<int> right = nextSmallerRight(input, n);
	vector<int> width, ans;
	for(int i=0;i<n;i++) {
		width.push_back(right[i] - left[i] - 1);
	}
	int max = INT_MIN;
	for(int i=0;i<n;i++) {
		ans.push_back(width[i] * input[i]);
	}
	for(int i=0;i<ans.size();i++) {
		if(ans[i] > max) {
			max = ans[i];
		}
	}
	return max;
}

int main() {
	int n, input[100];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>input[i];
	}
	int ans = maximumArea(input, n);
	cout<<ans;
	return 0;
}
