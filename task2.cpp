#include <iostream>
#include <stdio.h>
#include <map>


#define Long long long int

const Long N = 1e6;

using namespace std;

struct Node {
	int l = 0;
	int r = 0;
	int data = 0;

} seg[N];

int num = 1, n, a[N], head_num = 0;

void add(int prev, int head_num, int l, int r, int up) {

	Long mid = (l + r) / 2;
	if (mid == l && up == l) {
		seg[head_num].r = seg[prev].r;
		seg[head_num].l = num++;
		seg[num - 1].data = 1;
	}
	else if (mid + 1 == r && up == r) {
		seg[head_num].l = seg[prev].l;
		seg[head_num].r = num++;
		seg[num - 1].data = 1;
	}
	else if (up <= mid) {
		seg[head_num].r = seg[prev].r;
		seg[head_num].l = num++;
		add(seg[prev].l, seg[head_num].l, l, mid, up);
	}
	else {
		seg[head_num].l = seg[prev].l;
		seg[head_num].r = num++;
		add(seg[prev].r, seg[head_num].r, mid + 1, r, up);
	}
	int left = seg[head_num].l, right = seg[head_num].r;
	seg[head_num].data = seg[left].data + seg[right].data;
}

void update(int head_num, int l, int r, int up) {

	Long mid = (l + r) / 2;
	if (mid == l && up == l) {
		seg[head_num].l = num++;
		seg[num - 1].data = 0;
	}
	else if (mid + 1 == r && up == r) {
		seg[head_num].r = num++;
		seg[num - 1].data = 0;
	}
	else if (up <= mid) {
		seg[num] = seg[seg[head_num].l];
		seg[head_num].l = num++;

		update(seg[head_num].l, l, mid, up);
	}
	else {
		seg[num] = seg[seg[head_num].r];
		seg[head_num].r = num++;

		update(seg[head_num].r, mid + 1, r, up);

	}
	int left = seg[head_num].l, right = seg[head_num].r;
	seg[head_num].data = seg[left].data + seg[right].data;
}

Long query(int head_num, int l, int r, int ql, int qr) {
	if (ql > r || qr < l)
		return 0;
	else if (ql <= l && qr >= r)
		return seg[head_num].data;
	Long mid = (l + r) / 2;
	return query(seg[head_num].l, l, mid, ql, qr) + query(seg[head_num].r, mid + 1, r, ql, qr);
}

int main()
{
	
	cin >> n;
	map<int, int> _map;
	num = n + 1;  
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		add(head_num, head_num + 1, 0, n, i);
		update(head_num + 1, 0, n, _map[a[i]]);
		head_num++;
		_map[a[i]] = i;
	}

	int q;
	cin >> q;
	while (q--)
	{
		int left;
		int right;
		cin >> left >> right;
		cout << query(right, 0, n, left, right) << "\n";
	}

	return 0;
}





























