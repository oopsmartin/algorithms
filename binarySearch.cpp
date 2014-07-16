#include <stdio.h>

tydef struct binTreeNode
{
   int val;
   binTreeNode * p_left;
   binTreeNode * p_right;
};

binTreeNode* binSearch(binTreeNode* node,int val)
{
   if(node==NULL)
      return NULL;
   else
   {
      if(node->val==val)
          return node;
      else
         if(node->val>val)
            node = binSearch(node->p_left,val);
         else
            node = binSearch(node->p_right,val);
   }
}

binTreeNode* binGenerate(binTreeNode* node,int val)
{
   if(node==NULL)
   {
      node = malloc(sizeof(binTreeNode));
      node->p_right = node->p_left = NULL;
      node->val = val;
      return node;
   }
   else
   {       
      binTreeNode* tmp = NULL;
      if(node->val>val)
      {
         if(node->p_left==NULL)
         {
            tmp = malloc(sizeof(binTreeNode));
            tmp->p_left = tmp->p_right = NULL;
            tmp->val = val;
         }
         else
            node = binGenerate(node->p_left,val);
      }         
      else
   }
}
int main()
{
       
}
