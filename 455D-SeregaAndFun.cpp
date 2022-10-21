#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
template<class T> void debug(string msg, T x){cout << msg << x << endl;}

const int MAXN = 100005;
const int BLOCKSIZE = 320;

int n, q, a[MAXN];
int lastans;

struct Block{
	int freq[MAXN];
	deque<int> elementos;
};

Block blocos[BLOCKSIZE];

void update(int indexBlock){

	while(blocos[indexBlock].elementos.size() > BLOCKSIZE){
		int last = blocos[indexBlock].elementos.back();
		
		blocos[indexBlock].elementos.pop_back();
		blocos[indexBlock].freq[last]--;

		blocos[indexBlock+1].elementos.push_front(last);
		blocos[indexBlock+1].freq[last]++;
	}
}


void query1(int l, int r){
	
	int blocoL = l / BLOCKSIZE;
	int blocoR = r / BLOCKSIZE;

	int eleL = blocos[blocoL].elementos[l%BLOCKSIZE];
	int eleR = blocos[blocoR].elementos[r%BLOCKSIZE];

	blocos[blocoR].elementos.erase(blocos[blocoR].elementos.begin() + (r%BLOCKSIZE));
	blocos[blocoR].freq[eleR]--;

	blocos[blocoL].elementos.insert(blocos[blocoL].elementos.begin() + (l%BLOCKSIZE), eleR);
	blocos[blocoL].freq[eleR]++;

	for(int i=blocoL; i<blocoR; i++)
		update(i);

}

int query2(int l, int r, int k){

	int blocoL = l / BLOCKSIZE;
	int blocoR = r / BLOCKSIZE;

	int resp = 0;

	if (blocoL == blocoR){

		for(int i= l%BLOCKSIZE; i<= r%BLOCKSIZE; i++)
			if(blocos[blocoL].elementos[i] == k) resp++;
	}
	else{

		for(int i = l%BLOCKSIZE; i < BLOCKSIZE; i++)
			if(blocos[blocoL].elementos[i] == k) resp++;

		for(int i=0; i<=r%BLOCKSIZE; i++)
			if(blocos[blocoR].elementos[i] == k) resp++;

		for(int i=blocoL+1; i<blocoR; i++)
			resp += blocos[i].freq[k];
	}

	return resp;
}

void solve(){
	
	int type, l, r, k;
	scanf("%d %d %d", &type, &l, &r);
	l = ((l + lastans - 1) % n) + 1;
	r = ((r + lastans - 1) % n) + 1;

	if (l > r) swap(l, r);
	l--, r--;

	if(type == 1){
		query1(l, r);
	}
	else{
		scanf("%d", &k);
		k = ((k + lastans - 1) % n) + 1;
		lastans = query2(l, r, k);
		printf("%d\n", lastans);
	}
}

int main(){
	lastans = 0;
	
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(int i=0; i<n; i++){
		blocos[i/BLOCKSIZE].freq[a[i]]++;
		blocos[i/BLOCKSIZE].elementos.push_back(a[i]);
	}

	scanf("%d", &q);
	while(q--) solve();	
	return 0;
}
