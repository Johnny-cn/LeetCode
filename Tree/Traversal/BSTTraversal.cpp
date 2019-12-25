/*
使用非递归的方式遍历树， 包括前序中序和后序以及层次遍历
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:

/*模板：
	while (栈非空||root非空) {
		if (root非空) {
			
		}else {
			
		}
	}
*/
//Leetcode144前序， 用栈来存储每一个左子树（当前根节点也可以看做是左子树）
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        if (NULL != root) s.push(root);

        while (!s.empty()) {
            root = s.top();
            s.pop();
            v.push_back(root->val);
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
        }
        return v;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
		while (!s.empty() ||  NULL !=root) {
			if (NULL != root) {
				s.push(root);
				v.push_back(root->val);
				root = root->left;
			} else {
				root = s.top();s.pop();
				root = root->right;
			} 
		}
        return v;
    }
//Leetcode94中序
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> S;
		vector<int> v;
		TreeNode* rt = root;
		while (1) {
			if (NULL != rt) {
				S.push(rt);
				rt = rt->left;
			} else if (!S.empty(){
				rt = S.top();
				S.pop();
				v.push_back(rt->val);
				rt = rt->right;
			} else  {
				break;
			}
		}
		return v;
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> s;
		while (!s.empty() || NULL != root) {
			if (NULL != root) {
				s.push(root);
				root = root->left;
			} else {
				root = s.top(); s.pop();
				v.push_back(root->val);
				root = root->right;
			}
		}
		return v;
	}
//Leetcode145后序
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> s_1;
		stack<TreeNode*> s_2;
		vector<int> v;
		if (NULL == root) return v;
		s_1.push(root);
		while (!s_1.empty()) {
			root = s_1.top(); s_1.pop();
			if (NULL != root->left) s_1.push(root->left);
			if (NULL != root->right) s_1.push(root->right);
			s_2.push(root);
		}
		
		while (!s_2.empty()) {
			v.push_back(s_2.top());
			s_2.pop();
		}
		return v;
	}

    vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
        vector<int> v;
        TreeNode* x = NULL;  //用来记录前驱
        while (!s.empty() || NULL != root) {
            if (NULL != root) {
                s.push(root);
                root = root->left;  //定位到左侧最深左节点，
            } else {
                root = s.top();
                if (root->right == NULL || x == root->right) { //root->right == NULL ,证明没有右子书可以访问该节点， X === root->right 上一个访问的节点是当前节点的右子书（当前节点的右子书已经被访问），可以访问当前节点
                    v.push_back(root->val);
                    x = root;
                    root =NULL;
                    s.pop();
                } else {
                    root = root->right;
                }
            }
        }
        return v;
	}


//层次遍历，利用队列
	vector<int> levelOrderTraversal(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> v;
		q.enqueue(root);
		while (!q.empty()) {
			root = q.dequeue();
			v.push_back(root->val);
			if (NULL != root->left) q.enqueue(root->left);
			if (NULL != root->right) q.enqueue(root->right);
		}
		return v;
	}
};