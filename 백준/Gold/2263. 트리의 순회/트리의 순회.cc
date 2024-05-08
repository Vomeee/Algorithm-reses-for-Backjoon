#include <iostream>
#include <vector>

using namespace std;

vector<int> res;

void func(const vector<int>& inorder, const vector<int>& postorder, int in_start, int in_end, int post_start, int post_end)
{
	if (post_start > post_end) return;

	// 루트 노드는 포스트오더의 마지막 요소
	int root = postorder[post_end];
	res.push_back(root);

	// 인오더에서 루트 노드 찾기
	int rootIndex = 0;
	for (int i = in_start; i <= in_end; i++) {
		if (inorder[i] == root) {
			rootIndex = i;
			break;
		}
	}

	

	// 재귀 호출
 // 재귀 호출
	func(inorder, postorder, in_start, rootIndex - 1, post_start, post_start + rootIndex - in_start - 1); // 왼쪽 서브트리
	func(inorder, postorder, rootIndex + 1, in_end, post_start + rootIndex - in_start, post_end - 1); // 오른쪽 서브트리
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> f_inorder(n);
	vector<int> f_postorder(n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		f_inorder[i] = temp;
	}
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		f_postorder[i] = temp;
	}

	func(f_inorder, f_postorder, 0, n - 1, 0, n - 1);

	for (int i : res)
	{
		cout << i << ' ';
	}
}