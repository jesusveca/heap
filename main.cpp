#include <vector>
#include <iostream>

using namespace std;


int Parent(int i){return i/2;}


void heapify(vector<int>& vect, int i, int tam){
    int l = (i * 2) + 1;
    int r = (i * 2) + 2;
    int larg = i;
    
    if ((l <= tam) && (vect[l] > vect[i]))      larg = l;
    if ((r <= tam) && (vect[r] > vect[larg]))   larg = r;
    if (larg != i){
        swap(vect[i], vect[larg]);
        heapify(vect, larg, tam);
    }
}

void build_max_heap(vector<int>& vect){
    for (int i = ((vect.size()/2)-1); i >= 0; i=i-1) heapify(vect, i, vect.size()-1);
}

void heapsort(vector<int>& vect){
    build_max_heap(vect);
    int tam = vect.size()-1;
    for (int i = vect.size()-1; i >= 1; i=i-1) {
        swap(vect[0], vect[i]);
        tam=tam-1;
        heapify(vect, 0, tam);
    }
}

///////
//////
int heap_maximum(vector<int>& vect){
    return vect[0];
}

int heap_extract_max(vector<int>& vect){
    if (vect.size()<1)
        cout<<"heap underflow";
    int max=vect[0];
    vect[0]=vect[vect.size()];
    vect.resize(vect.size()-1);
    heapify(vect, 0, vect.size());
    return max;
}

void heap_increase_key(vector<int>& vect,int i, int key){
    if (key<vect[i])
        cout<<"new key is smaller than current key";
    vect[i]=key;
    while(i>1 && vect[Parent(i)]<vect[i]){
        int aux=vect[i];
        vect[i]=vect[Parent(i)];
        vect[Parent(i)]=aux;
        i=Parent(i);
//        swap(vect[i],vect[Parent(i)]);
//        i=Parent(i);
    }
}

void max_heap_insert(vector<int>& vect,int key){
    vect.resize(vect.size()+1);
    vect[vect.size()]=999999999;
    heap_increase_key(vect, vect.size(), key);
}


//////
//////

int main() {
    int valor=0;
    vector<int> vect;

    vect.push_back(15);    vect.push_back(13);    vect.push_back(9);
    vect.push_back(5);     vect.push_back(12);    vect.push_back(8);
    vect.push_back(7);     vect.push_back(4);     vect.push_back(0);
    vect.push_back(6);     vect.push_back(2);     vect.push_back(1);
//
//    cout<<"Desordenado : "<<endl;
//    
//    for (int i=0;i<vect.size();i++)     cout<<vect[i]<<" ";
//    
//    cout<<endl<<endl;
//    cout<<"Ordenado : "<<endl;
//    heapsort(vect);
//    
//    for (int i=0;i<vect.size();i++)     cout<<vect[i]<<" ";
//    cout<<endl;
//    cout<<endl;
//    cout<<endl;
//    cout<<endl;
    
    
    int extr=heap_extract_max(vect);
    cout<<"E es :"<<extr<<endl;
    cout<<endl;
    cout<<endl;
    
    for(int i=0;i<vect.size();i++)
    {
        cout<<vect[i]<<", ";
    }
    
    
    
    cout<<endl;
    cout<<endl;
    heap_increase_key(vect,8,99); heap_increase_key(vect,2,44);
    int max=heap_maximum(vect);
    cout<<"maximo :"<<max<<endl;

    cout<<endl;
    cout<<endl;

    for(int i=0;i<vect.size();i++)
    {
        cout<<vect[i]<<", ";
    }
    
    return 0;
}