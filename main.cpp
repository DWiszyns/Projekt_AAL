#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>

int main(int argc, char *argv[]) {
    if(argc!=2){
       std::cout<<"Nie wystarczająca ilość argumentów"<<std::endl;
        return 1;
    }
    std::ifstream we;
    int sumOfEdges=0;
    std::vector <int> edges;
    int numberOfEdges=0;
    int edge;
    we.open(argv[1],std::fstream::in);
    while(we>>edge){
        edges.push_back(edge);
        sumOfEdges+=edge;
        ++numberOfEdges;
    }
    we.close();
    int tmpSumOfEdges=0;//that is going to be our temporary sum of edges that makes our route
    int maxSumOfEdges=0;
    sumOfEdges/=2; //our sum of edges is divided by 2 because it's maximum value that tmpSumOfEdges can achieve
    std::queue<std::pair<int,int>> pairs;
    std::queue<std::pair<std::pair<int,int>,int>> solutions;//stack of solutions
    bool end = false;
    for(int i=0;i<2*numberOfEdges;++i){
        int id=i%numberOfEdges;
        pairs.push(std::make_pair((id+1),edges[id]));
        tmpSumOfEdges+=edges[id];
        while(tmpSumOfEdges>sumOfEdges){//if it's larger than half of our whole road than our length is wrong and we need top subtract the length of first edge
           tmpSumOfEdges-=pairs.front().second;
            int verticeNumber = pairs.front().first;
            pairs.pop();
            if(verticeNumber==numberOfEdges) end =true;
        }
        if(end) break;
        if(tmpSumOfEdges==maxSumOfEdges){
            solutions.push(std::make_pair(std::make_pair(pairs.front().first,(id+2)),tmpSumOfEdges));//id+1 is the index of vertice that edge begins at, id+2 is the number it ends at

        }
        if(tmpSumOfEdges>maxSumOfEdges){
            maxSumOfEdges=tmpSumOfEdges;
            while(!solutions.empty()){
                solutions.pop();
            }
            solutions.push(std::make_pair(std::make_pair(pairs.front().first,(id+2)),tmpSumOfEdges));//id+1 is the index of vertice that edge begins at, id+2 is the number it ends at

        }

    }
    std::cout<<"Our solutions are: "<<std::endl;
   while(!solutions.empty()){
       std::cout<<solutions.front().first.first<<" "<<solutions.front().first.second<<" "<<solutions.front().second<<std::endl;
       solutions.pop();
   }
}