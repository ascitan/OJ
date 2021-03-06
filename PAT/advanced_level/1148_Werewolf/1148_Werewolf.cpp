/*
逻辑题

参考思路:
https://www.liuchuo.net/archives/6494

参考柳神的博客，先假设狼人，再考虑liar，这样会比较简单
如果先假设liar，在考虑狼人，逻辑会很复杂，输出也麻烦

1. 首先填入每个人所说的话 claim[], 即几号选手是 好人/狼人
2. 假设 i 和 j 是狼人, 新建一个数组, 将好人设为 1 狼人设为 -1
3. 然后遍历每个人所说的话 claim[]

   如 3 号选手说 4 号选手是狼人，即 claim[3] = -4, 而 4 号选手在我们的假设中不是狼人，那么3号选手说谎了(其实这里不应该用说谎，用 incorrect 会比较好)

4. 遍历完 claim[] 后，统计liar，若仅有2个liar，且一个是狼人一个是好人，那么这就是一个Solution，退出
5. 如果没有 Solution，那么输出 No Solution
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	vector<int> claim(n+1);
	for(int i = 1; i <= n; i++ ){
		cin>>claim[i];
	}

	for( int i = 1; i <= n; i++ ){
		for( int j = i + 1; j <= n; j++ ){
			vector<int> player(n+1, 1);
			player[i] = player[j] = -1;
			vector<int> liar;

			for( int k = 1; k <= n; k++ ){
				int p1 = claim[k];
				int p2 = player[ abs(p1) ];
				if( p1 * p2 < 0 ){
					liar.push_back(k);
				}
			}

			if( liar.size() == 2 ){
				int p1 = liar[0];
				int p2 = liar[1];
				if( player[p1] * player[p2] == -1 ){
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
			}
		}
	}
	cout<<"No Solution\n";

	return 0;
}
