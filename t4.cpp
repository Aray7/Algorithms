#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<ll, ll> pa;
vector< pair<ll, ll> >v[1000000];
vector<ll>weight(1000000, INT_MAX);
vector<ll>parent(1000000, -1);
vector<bool>visited(1000000, 0);

void prims(ll n, ll e) {
	ll src = 0;
	set<  pa > s;
	s.insert({ 0,src });
	weight[src] = 0;
	ll u;
	ll sum = 0;
	while (!s.empty()) {
		u = s.begin()->second;
		s.erase(s.begin());
		visited[u] = 1;
		for (auto it : v[u]) {
			ll V = it.first;
			ll wei = it.second;
			if (visited[V] == 0 && weight[V] > wei) {
				if (s.find({ weight[V],V }) != s.end()) {
					s.erase({ weight[V],wei });
				}
				weight[V] = wei;
				s.insert({ weight[V],V });
				parent[V] = u;
			}
		}
	}
	sum = 0;
	for (ll i = 1; i < n; i++) {
		//cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
		sum = sum + weight[i];
	}

	cout << sum << endl;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, e;
	cin >> n >> e;
	for (ll i = 0; i < e; i++) {
		ll x, y, weight;
		cin >> x >> y >> weight;
		x--;
		y--;
		v[x].push_back({ y,weight });
		v[y].push_back({ x,weight });

	}
	prims(n, e);


}