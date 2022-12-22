class Solution {
public:
	vector<int> cnt;
	vector<int> res;
	int ansRoot = 0;
	int N;
	int cntNodesInSubtree(vector<vector<int>> &g, int src, int parent, int dfz) {
		ansRoot += dfz;
		int curCnt = 1;
		for (int nbrs : g[src]) {
			if (nbrs != parent) curCnt += cntNodesInSubtree(g, nbrs, src, dfz + 1);
		}
		cnt[src] = curCnt;
		return curCnt;
	}
	void fillRes(vector<vector<int>> &g, int src, int parent) {
		if (parent != -1) res[src] = res[parent] - cnt[src] + (N - cnt[src]);
		for (int nbrs : g[src]) {
			if (nbrs != parent) fillRes(g, nbrs, src);
		}
	}
	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		vector<vector<int>> g(n);
		cnt.resize(n);
		res.resize(n);
		for (auto e : edges) {
			g[e[0]].push_back(e[1]);
			g[e[1]].push_back(e[0]);
		}
		cntNodesInSubtree(g, 0, -1, 0);
		N = cnt[0];
		res[0] = ansRoot;
		fillRes(g, 0, -1);
		return res;
	}
};