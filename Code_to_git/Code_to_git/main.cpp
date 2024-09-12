//
//  main.cpp
//  Code_to_git
//
//  Created by Lay Achea Deth on 6/11/20.
//  Copyright © 2020 Lay Achea Deth. All rights reserved.
//

#include <iostream>
#include<vector>
#include<Algorithm>
using namespace std;

template <class T>
class BSTNode
{
    private:
        T value;
    int height;
        BSTNode *left, *right;
    public:
        BSTNode(T value)
        {
            this->value = value;
            left = NULL;
            right = NULL;
            height=1;
        }
        /*
         * Adding element to a node
         */
        void add(T& value)
        {
            if (value < this->value)
            {
                if (left)
                    left->add(value);
                else
                    left = new BSTNode(value);
            }
            else if (this->value < value)
            {
                if (right)
                    right->add(value);
                else
                    right = new BSTNode(value);
            }
        }
        /*
         * Check if node contains element
         */
        bool contains(T& value)
        {
            if (value < this->value)
            {
                if (left)
                    return left->contains(value);
            else
                   return false;
            }
            else if (this->value < value)
            {
                if (right)
                    return right->contains(value);
            else
                    return false;
            }
            else
            {
                return true;
            }
        }
        friend class BSTHashtable;
};


 
class BSTHashtable
{
    private:
        int size;
        vector<BSTNode<string>*>* bucket;
    vector<BSTNode<string>*>* buckets;
    vector<BSTNode<string>*>* bucket1;
    vector<BSTNode<string>*>* bucket2;
    vector<BSTNode<string>*>* bucket3;
    int hash2(int s){
        return s%size;
    }
        int hash(string& s)
        {
            unsigned int hashVal = 0;
            for (unsigned int i = 0; i < s.length(); i++)
                hashVal ^= (hashVal << 5) + (hashVal >> 2) + s[i];
            return hashVal % size;
        }
    
    public:
    
    int getVectorSize(){
        return size;
    }
        BSTHashtable(int vectorSize)
        {
            size = vectorSize;
            bucket = new vector<BSTNode<string>*>(size);
            buckets=new vector<BSTNode<string>*>(size);
            bucket1=new vector<BSTNode<string>*>(size);
            bucket2=new vector<BSTNode<string>*>(size);
            bucket3=new vector<BSTNode<string>*>(size);
           
        }
        /*
         * Adding string in the table
         */
      
        /*
         * Check if table contains string
         */
        bool contains(string& s)
        {
            int index = hash(s);
            if (bucket->at(index) == NULL)
                return false;
        cout<<"String \""<<s<<"\" found at index: "<<index<<endl;
            return bucket->at(index)->contains(s);
        }
        /*
         * Display Table
         */
       
        /*
         * Display BST
         */
       
    int getHeight(BSTNode<string>* node)
    {
        if(node == nullptr)
            return 0;

        return node->height;
    }
    BSTNode<string>* updateHeight(BSTNode<string>* node)
    {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        return node;
    }
    BSTNode<string>* leftRotate(BSTNode<string>* root)
    {
        BSTNode<string>* x = root->right;
        BSTNode<string>* t = x->left;

        root->right = t;
        x->left = root;

        // update height
        x = updateHeight(x);
        root = updateHeight(root);

        return x;
    }
    BSTNode<string>* rightRotate(BSTNode<string>* root)
    {
        BSTNode<string> *x = root->left;
        BSTNode<string> *t = x->right;

        root->left = t;
        x->right = root;

        // update height
        root = updateHeight(root);
        x = updateHeight(x);

        return x;
    }
    void printAll(BSTNode<string>* root)
    {
        root=nullptr;
        if(root->left != nullptr)
            printAll(root->left);

        cout<<root->value<<" ";

        if(root->right != nullptr)
            printAll(root->right);
    }
    BSTNode<string>* insert(BSTNode<string>* root, string value)
    {
        if(root == nullptr)
            return new BSTNode<string>(value);

        if(root->value < value)
            root->right = insert(root->right, value);
        else if(root->value == value)
        {
            cout<<"value: "<<value<<" No duplicate vertex allowed."<<endl;
            return root;
        }
        else
            root->left = insert(root->left, value);

        root = updateHeight(root);

        int balance_factor = getHeight(root->left) - getHeight(root->right);

        // LR rotation
        if(balance_factor > 1 && root->left->value < value)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        // RR rotation
        else if(balance_factor > 1 && root->left->value > value)
            return rightRotate(root);
        // LL rotation
        else if(balance_factor < -1 && root->right->value < value)
            return leftRotate(root);
        // RL rotation
        else if(balance_factor < -1 && root->right->value > value)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
    

    
    /* l is for left index and r is right index of the
       sub-array of arr to be sorted */
  
      
    /* UTILITY FUNCTIONS */
    /* Function to print an array */
 
};

vector<string> merge(vector<string> left, vector<string> right)
{
   vector<string> result;
   while ((int)left.size() > 0 || (int)right.size() > 0) {
      if ((int)left.size() > 0 && (int)right.size() > 0) {
         if ((string)left.front() <= (string)right.front()) {
            result.push_back((string)left.front());
            left.erase(left.begin());
         }
   else {
            result.push_back((string)right.front());
            right.erase(right.begin());
         }
      }  else if ((int)left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
               result.push_back(left[i]);
            break;
      }  else if ((int)right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
               result.push_back(right[i]);
            break;
      }
   }
   return result;
}

vector<string> mergeSort(vector<string> m)
{
   if (m.size() <= 1)
      return m;
 
   vector<string> left, right, result;
   int middle = ((int)m.size()+ 1) / 2;
 
   for (int i = 0; i < middle; i++) {
      left.push_back(m[i]);
   }

   for (int i = middle; i < (int)m.size(); i++) {
      right.push_back(m[i]);
   }
 
   left = mergeSort(left);
   right = mergeSort(right);
   result = merge(left, right);
 
   return result;
}

