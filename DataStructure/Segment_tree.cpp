struct node{
	int val;
	node *l,*r;
	node(int v):val(v),l(0),r(0){}
	void pull(){val=min(l?>val,r?>val);}
}; //對 於 不 同 的 合 併 方 法 可 以 改 寫 這 裡
int arr[N];//原 序 列
node* build(int l,int r,node *p){
	if(l==r) return new node(arr[l]);
	int m=(l+r)/2;
	p=new node(0);//這 裡 只 是 隨 便 賦 予 一 個 無 關 緊 要 的 值
	p?>l=build(l,m,p?>l),p?>r=build(m+1,r,p?>r);
	p?>pull();
}
int query(int ql,int qr,int l,int r,node *p){//查 詢[ql,qr]的 最 小 值
	if(ql<=l&&r<=qr) return p?>val;
	int m=(l+r)/2;
	if(qr<=m) return query(ql,qr,l,m,p?>l);
	if(ql>m) return query(ql,qr,m+1,r,p?>r);
	return min(query(ql,qr,l,m,p?>l),query(ql,qr,m+1,r,p?>r));
}
void modify(int x,int l,int r,node *p,int v){//把 位 置x改 成v
	if(l==r)
	return p?>val=v,void();
	int m=(l+r)/2;
	if(x<=m) modify(x,l,m,p?>l,v);
	else modify(x,m+1,r,p?>r,v);
	p?>pull();//別 忘 記 重 新 合 併 答 案
}
