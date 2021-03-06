#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1002

int parent[MAX_N], rnk[MAX_N];

void begin_sets(int n){
  for(int i=1;i<=n;i++){
    parent[i]=i; rnk[i]=1;
  }
}

int find_set(int v){
  if(parent[v]==v) return v;
  return parent[v]=find_set(parent[v]);
}

void union_sets(int v, int w){
  int vSet=find_set(v), wSet=find_set(w);
  if(vSet==wSet) return;

  if(rnk[wSet]>rnk[vSet]) swap(vSet, wSet);
  parent[wSet]=vSet;
  rnk[vSet]+=rnk[wSet];
}