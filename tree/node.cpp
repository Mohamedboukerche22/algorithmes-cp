struct Node {
    int data ;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL; 
        right = NULL;
    }
};

struct TrieNode {

    TrieNode* children[26];
    bool isend;

    TrieNode(){
        isend = false;
        for(int i = 0 ; i < 26;i++){
            children[i] = NULL;
        }
    }
    
};

void insert(TrieNode* root,string word){
    TrieNode* curr = root;

    for(char c: word){
        int index = c - 'a'; 

        if(curr->children[index] == NULL){
        curr->children[index] = new TrieNode;
        }
        curr = curr->children[index];
    }
    curr->isend = true;
}

bool search(TrieNode* root, string word){

    TrieNode* curr = root;
    
    for(char c : word){
      int index = c - 'a';
      if(curr->children[index] == NULL){
        return false;
      }
     curr = curr->children[index];

    }
   return curr->isend;


}

