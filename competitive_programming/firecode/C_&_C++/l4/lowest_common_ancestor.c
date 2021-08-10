// Given a binary tree and the data values of two tree nodes, implement a function to find and 
// return the LCA (Lowest Common Ancestor) node of the two nodes. 
// a and b are the data values of the two input nodes. 
// Assume that nodes with the values a and b will surely exist in the tree.

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper functions(if needed) above.
treeNode* find_lca(treeNode* root, int a, int b) {
   if(!root){
       return NULL;
   }
   if(root->value == a || root->value == b){
       return root;
   }
   treeNode *leftTemp = find_lca(root->left, a, b);
   treeNode *rightTemp = find_lca(root->right, a, b);
   
   if(leftTemp && rightTemp){
       return root;
   }
   if(!leftTemp && !rightTemp){
       return NULL;
   }
   if(!rightTemp){
       return leftTemp;
   }
   if(!leftTemp){
       return rightTemp;
   }
   return NULL;
}