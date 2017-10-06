#include <iostream>
#include <string>
#include <utility>
#include <omp.h>
#include <fstream>

int total = 0 ;

void inicializaCombinacao(int *conjunto,int N, int *V , int M)
{
    for(int i = 1 ; i <= N ; i++) conjunto[i-1] = i;
    for(int i = 1 ; i <= M ; i++) V[i-1] = i;
}

void combina(int *conjunto, int N, int *V, int M , int r , int next){
    if( r == M )
    {
        for(int i = 0 ; i < M ; i++)
            std::cout << conjunto[V[i]] ;
        std::cout << "\n";
        total++;
    }
    else
    {
        for ( int i = next ; i < r + (N-M) + 1 ; i++)
        {
            V[r] = i ;
            combina(conjunto , N , V , M , r+1 , i+1);
        }
    }
}

std::string strReplace(std::string str,char c,char r)
{
    for(char& current : str)
    {
        if(current == c)
            current = r;
    }
    return str;
}

void save(int N,double tempo){
    std::string file = "../Combinacao/Resultado.csv";

    std::ofstream arquivo(file,std::ios_base::out | std::ios_base::app);

    arquivo << N <<  ";" << strReplace(std::to_string(tempo),'.',',') << "\n";

    arquivo.close();
}

int main()
{
    int cont = 0;
    while(++cont)
    {
        std::cout << cont << "\n";
        double global_start = omp_get_wtime();
        total = 0;
        int N = cont ;
        int M = (N/2)+1;
        int *conjunto = new int[N];
        int *V = new int[M];
        inicializaCombinacao(conjunto,N,V,M);
        combina(conjunto,N,V,M,0,0);
        double tempo = omp_get_wtime() - global_start;
        std::cout << "\n Numero de combinações: " << total << "\n";
        std::cout << "\n Tempo Total: " << tempo << "\n\n";
        save(N,tempo);
    }
}
