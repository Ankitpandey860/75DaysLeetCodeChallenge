/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs(TreeNode* root,string &s){
        if(root==NULL){
            s+='*';
            s+=',';
            return;
        }
        s+=to_string(root->val)+',';
        dfs(root->left,s);
        dfs(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string coded="";
        dfs(root,coded);
        cout<<"serialised"<<coded<<endl;
        return coded;
    }
    TreeNode* decode(string &data,int &i){
        if(data[i]=='*'){
            i+=2;
            return NULL;
        }
        string temp="";
        while(data[i]!=','){
            temp+=data[i];
            i++;
        }
        i++;
        int val=stoi(temp);
        TreeNode* curr=new TreeNode(val);
        curr->left=decode(data,i);
        curr->right=decode(data,i);
        return curr;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return decode(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;