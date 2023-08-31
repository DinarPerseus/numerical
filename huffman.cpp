#include <bits/stdc++.h>
using namespace std;

map <string,char> decode_table;
map <char,string> encode_table;

class Node{ 
public:

    char c;
    int freq;
    Node *left=NULL,*right=NULL;
    Node(char c,int freq){
        this->c=c;
        this->freq=freq;
    }
    
};


struct comp {
 
    bool operator()(Node* l, Node* r)
    {
        return (l->freq > r->freq);
    }
};


void print(Node *n,string s){
    if (n->c!='$')
    {
        //cout<<n->c<<": "<<s<<"\n";
        decode_table[s]=n->c;
        encode_table[n->c]=s;
        return;
    }
    
    print(n->left,s+'0');
    print(n->right,s+'1');

}




void HuffmanCodes(map<char,int> freq_table){

    priority_queue<Node*,vector<Node*>,comp> pq;

    for (auto x:freq_table)
    {
        pq.push(new Node(x.first,x.second));
    }
    
    Node *left,*right,*root;

    while (pq.size()>1)
    {
        
        left = pq.top();
		pq.pop();

		right = pq.top();
		pq.pop();

        root= new Node('$',left->freq+right->freq);
        root->left=left;
        root->right=right;

        pq.push(root);
 
    }


    print(pq.top(),"");
    

}



void decode(){
    string s,ts="";
    cin>>s;

    for (int i = 0; i < s.size(); i++)
    {
        ts+=s[i];
        if (decode_table[ts])
        {
            cout<<decode_table[ts];
            ts="";
        }
        
    }
    cout<<endl;
    

}


void encode(string& s){
    for (int i = 0; i < s.size(); i++)
    {
        cout<<encode_table[s[i]];
    }
    cout<<endl;
    

}


int main()
{

    freopen("secretmessage.txt", "r", stdin);
    freopen("secretmessage.txt", "w", stdout);
    map<char,int> freq_table;
	string s="Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters.";
    

    for (int i = 0; i < s.size(); i++)
    {
        freq_table[s[i]]++;
    }
    
    

	HuffmanCodes(freq_table);
    encode(s);
    decode();

	return 0;
}


