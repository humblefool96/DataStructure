#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair


vector<pair<ll,ll> > vect[100000];
bool vis[100000];
ll dis[100000];
ll nodes,edges;

void dijkstra(ll s){
    dis[s] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
    pq.push(mp(0,s));
    while(!pq.empty()){
        pair<ll,ll> f = pq.top();
        ll p = f.second;
        pq.pop();
        if(vis[p])  continue;
        vis[p] = true;
        for(ll i = 0; i < vect[p].size(); i++){
            ll d = vect[p][i].first;
            ll wei = vect[p][i].second;
            if(dis[p] + wei < dis[d]){
                dis[d] = dis[p] + wei;
                pq.push(mp(dis[d],d));
            }
        }

    }
}

int main() {
	cin>>nodes>>edges;
	ll x,y,w;
	for(int i=0;i<edges;i++){
	    cin>>x>>y>>w;
	    vect[x].pb(mp(y,w));
	   // vect[y].pb(mp(x,w));
	}

    memset(vis, false, sizeof vis);
    memset(dis, 1000000, sizeof dis);

	dijkstra(1);
	for (ll i = 2; i <= nodes; i++) cout<<dis[i]<<" ";
	return 0;
}

