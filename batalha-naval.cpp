#include <iostream>
#include <ctime>
using namespace std;
//inicializando a matriz mostrada aos jogadores
void inicializa(char mat[10][10])
{
     for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            mat[i][j]= '~';
        }
    }
}
//função que imprime a matriz mostrada aos jogadores a cada posição aberta
void imprime (char mat[10][10])
{    cout<<endl;
     cout<< "    0  1  2  3  4  5  6  7  8  9  "<<endl;
     for(int i=0; i<10; i++)
    {
        cout<<i<< " ";
        for(int j=0; j<10; j++)
        {
            cout << "  " << mat[i][j];
        }
        cout << endl;
    }
}
//inicializando a matriz resposta apenas com posições vazias
void inicializaresp(char matresp[10][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            matresp[i][j]='o';
        }
    }
}
//função para adicionar o navio de menor tamanho na matriz resposta
void navio1(char matresp[10][10], int e, int r)
{
    int cont=0;
    for(int p=0; p<100; p++){
      if(cont==3){
       break;
      }
        e=rand()%10;
        r=rand()%10;
        if(matresp[e][r]=='o' && (matresp[e][r-1]=='o' && matresp[e][r+1]=='o' && matresp[e+1][r]=='o' && matresp[e+1][r+1]=='o' && matresp[e+1][r-1]=='o' && matresp[e-1][r]=='o' && matresp[e-1][r+1]=='o' && matresp[e-1][r-1]=='o'))
        {   matresp[e][r]='i';
            cont++;}
    }
}
//função para adicionar o navio de tamanho dois na matriz resposta
void navio2(char matresp[10][10], int e, int r)
{
    int cont=0, posicao;
    for (int p=0; p<1000;p++){

    if(cont==3){
     break;}

    e = rand()%10;
    r = rand()%10;

    if(e!=0){
    if(r!=9){
    if(matresp[e][r]=='o'){

      posicao=rand()%2;
    if(posicao==0){
        if(matresp[e][r-1]=='o' && matresp[e][r+1]=='o' && matresp[e][r+2]=='o' &&
            matresp[e-1][r]=='o' && matresp[e-1][r-1]=='o' && matresp[e-1][r+1]=='o' && matresp[e-1][r+2]=='o' &&
            matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' && matresp[e+1][r+1]=='o' && matresp[e+1][r+2]=='o'){
             matresp[e][r]='i';
             r++;
             matresp [e][r] = 'i';
             cont++;
            }
    }
    else {
        if(matresp[e][r-1]=='o' && matresp[e][r+1]=='o' &&
           matresp[e-1][r]=='o' && matresp[e-1][r-1]=='o' && matresp[e-1][r+1]=='o' &&
           matresp[e-2][r]=='o' && matresp[e-2][r-1]=='o' && matresp[e-2][r+1]=='o' &&
           matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' && matresp[e+1][r+1]=='o'){
            matresp[e][r]='i';
            e--;
            matresp [e][r] = 'i';
           cont++;
           }}}
    }
    else if( r==9)
    {
      if(matresp[e][r-1]=='o' &&
           matresp[e-1][r]=='o' && matresp[e-1][r-1]=='o' &&
           matresp[e-2][r]=='o' && matresp[e-2][r-1]=='o' &&
           matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' ){
            matresp[e][r]='i';
            e--;
            matresp [e][r] = 'i';
           cont++;}}
    }
    else if(e==0 &&  r!=9){
        if(matresp[e][r-1]=='o' && matresp[e][r+1]=='o' && matresp[e][r+2]=='o' &&
            matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' && matresp[e+1][r+1]=='o' && matresp[e+1][r+2]=='o'){
            matresp[e][r]='i';
             r++;
             matresp [e][r] = 'i';
             cont++;
            }}
     else if(e==0 && r==9){
     if(matresp[e][r-1]=='o' && matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' &&
        matresp[e+2][r]=='o' && matresp[e+2][r-1]=='o'){
      matresp[e][r]='i';
      e++;
      matresp[e][r]='i';
      cont++;
     }
    }

}
}

//função para adicionar o navio de tamanho três na matriz resposta
void navio3(char matresp[10][10], int e, int r)
{   int cont=0;
    for (int p=0; p<1000;p++){
    if(cont==3){
     break;
    }

    e = rand()%10;
    r = rand()%10;

    if(e!=0 && e!=1){
    if(r!=8 && r!=9){
    if(matresp[e][r]=='o'){

    int posicao;
    posicao = rand()%2;
    if(posicao==0)
    {
        if(matresp[e][r-1]=='o' && matresp[e][r+1]=='o' && matresp[e][r+2]=='o' && matresp[e][r+3]=='o' &&
            matresp[e-1][r]=='o' && matresp[e-1][r-1]=='o' && matresp[e-1][r+1]=='o' && matresp[e-1][r+2]=='o' && matresp[e-1][r+3]=='o' &&
            matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' && matresp[e+1][r+1]=='o' && matresp[e+1][r+2]=='o' && matresp[e+1][r+3]=='o' ){
        matresp[e][r]='i';
        r++;
        matresp[e][r]='i';
        r++;
        matresp[e][r]='i';
        cont++;
        }
    }
    else if(posicao==1){
                if(matresp[e][r-1]=='o' && matresp[e][r+1]=='o' &&
           matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' && matresp[e+1][r+1]=='o' &&
           matresp[e-1][r]=='o' && matresp[e-1][r-1]=='o' && matresp[e-1][r+1]=='o' &&
           matresp[e-2][r]=='o' && matresp[e-2][r-1]=='o' && matresp[e-2][r+1]=='o' &&
           matresp[e-3][r]=='o' && matresp[e-3][r-1]=='o' && matresp[e-3][r+1]=='o'){
        matresp[e][r]='i';
        e--;
        matresp[e][r]='i';
        e--;
        matresp[e][r]='i';
        cont++;}}
    }
    }
    else if(r==8){
        if(matresp[e][r-1]=='o' && matresp[e][r+1]=='o' &&
           matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' && matresp[e+1][r+1]=='o' &&
           matresp[e-1][r]=='o' && matresp[e-1][r-1]=='o' && matresp[e-1][r+1]=='o' &&
           matresp[e-2][r]=='o' && matresp[e-2][r-1]=='o' && matresp[e-2][r+1]=='o' &&
           matresp[e-3][r]=='o' && matresp[e-3][r-1]=='o' && matresp[e-3][r+1]=='o'){
        matresp[e][r]='i';
        e--;
        matresp[e][r]='i';
        e--;
        matresp[e][r]='i';
        cont++;}}
        else if(r==9){
            if(matresp[e][r-1]=='o' && matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' &&
               matresp[e-1][r]=='o' && matresp[e-1][r-1]=='o' &&
               matresp[e-2][r]=='o' && matresp[e-2][r-1]=='o' &&
               matresp[e-3][r]=='o' && matresp[e-3][r-1]=='o'){
               matresp[e][r]='i';
               e--;
               matresp[e][r]='i';
               e--;
               matresp[e][r]='i';
               cont++; }}

}
   else if((e==0 || e==1) && (r!=8 && r!=9)){
         if(matresp[e][r-1]=='o' && matresp[e][r+1]=='o' && matresp[e][r+2]=='o' && matresp[e][r+3]=='o' &&
            matresp[e-1][r]=='o' && matresp[e-1][r-1]=='o' && matresp[e-1][r+1]=='o' && matresp[e-1][r+2]=='o' && matresp[e-1][r+3]=='o' &&
            matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' && matresp[e+1][r+1]=='o' && matresp[e+1][r+2]=='o' && matresp[e+1][r+3]=='o' ){
        matresp[e][r]='i';
        r++;
        matresp[e][r]='i';
        r++;
        matresp[e][r]='i';
        cont++;}}
   else if((e==0 || e==1) && (r==8)){
    if(matresp[e][r-1]=='o' && matresp[e][r+1]=='o' &&
           matresp[e-1][r]=='o' && matresp[e-1][r-1]=='o' && matresp[e-1][r+1]=='o' &&
           matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' && matresp[e+1][r+1]=='o' &&
           matresp[e+2][r]=='o' && matresp[e+2][r-1]=='o' && matresp[e+2][r+1]=='o' &&
           matresp[e+3][r]=='o' && matresp[e+3][r-1]=='o' && matresp[e+3][r+1]=='o'){
        matresp[e][r]='i';
        e++;
        matresp[e][r]='i';
        e++;
        matresp[e][r]='i';
        cont++;}}
    else if((e==0 || e==1) && (r==9)){
      if(matresp[e][r-1]=='o' &&  matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' &&
               matresp[e+1][r]=='o' && matresp[e+1][r-1]=='o' &&
               matresp[e+2][r]=='o' && matresp[e+2][r-1]=='o' &&
               matresp[e+3][r]=='o' && matresp[e+3][r-1]=='o'){
               matresp[e][r]='i';
               e++;
               matresp[e][r]='i';
               e++;
               matresp[e][r]='i';
               cont++;  }
}
    }
}
void imprimetabuleiro(char matresp[10][10])
{       cout<<endl;
        cout<< "   0  1  2  3  4  5  6  7  8  9  "<<endl;
        for(int i=0; i<10; i++){
            cout<<i<< "  ";
        for(int j=0; j<10; j++)
        {
            cout << matresp[i][j]<< "  ";
        }
        cout <<endl;
     }
}

//funçaõ para conferir se todos os navio foram achados, para poder finalizar a partida
int confere(char mat[10][10], char matresp[10][10])
{
    int contconfere=0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++){
            if( mat[i][j]=='i' && matresp[i][j]=='i')
            contconfere++;
        }
    }
    if(contconfere==18)
        return 10;
        else
            return 9;
}

//função para verificar as posições nas bordas do tabuleiro, para atribuir 5 ou 2 pontos
int verificar (char mat[10][10], char matresp[10][10], int i, int j){
   if(i==0 && j!=0 && j!=9){
    if(mat[i][j]=='i'){
      if(mat[i][j+1]!='i' && mat[i][j-1]!='i' && mat[i+1][j]!='i')
        return 3;
      else
        return 4;}
    else if(mat[i][j]=='o')
        return 0;}

    if(i==0 && j==0){
        if(mat[i][j]=='i'){
        if(mat[i][j+1]!='i' && mat[i+1][j]!='i')
            return 3;
        else
            return 4;}
     else if(mat[i][j]=='o')
        return 0;}

     if(i==0 && j==9){
        if(mat[i][j]=='i'){
          if(mat[i][j-1]!='i' && mat[i+1][j]!='i')
            return 3;
          else
            return 4;}
          else if(mat[i][j]=='o')
            return 0;}
    if(i!=0 && i!=9 && j==0){
        if(mat[i][j]=='i'){
            if(mat[i][j+1]!='i' && mat[i-1][j]!='i' && mat[i+1][j]!='i')
                return 3;
            else
                return 4;}
        else if(mat[i][j]=='o')
            return 0;}
      if(i==9 && j==0){
         if(mat[i][j]=='i'){
           if(mat[i][j+1]!='i' && mat[i-1][j]!='i')
             return 3;
           else
             return 4;}
           else if(mat[i][j]=='o')
            return 0;}

     if(i==9 && j!=0 && j!=9){
        if(mat[i][j]=='i'){
            if(mat[i][j+1]!='i' && mat[i][j-1]!='i' && mat[i-1][j]!='i')
                return 3;
            else
                return 4;}
        else if(mat[i][j]=='o')
            return 0;}
     if(i==9 && j==9){
         if(mat[i][j]=='i'){
            if( mat[i][j-1]!='i' && mat[i-1][j]!='i')
                return 3;
            else
                return 4;}
         else if(mat[i][j]=='o')
            return 0;}
     if(i!=9 && i!=0 && j==9){
         if(mat[i][j]=='i'){
            if(mat[i][j-1]!='i' && mat[i-1][j]!='i' && mat[i+1][j]!='i')
                return 3;
            else
                return 4;}
        else if(mat[i][j]=='o')
            return 0;}

}

//função responsável para mostrar se o barco na horizontal foi afundado
void afundabarcoh(char mat[10][10], char matresp[10][10], int i, int j){
    if(j!=0 && j!=9){
    if((matresp[i][j+1]=='o' && matresp[i][j-1]=='o' && matresp[i+1][j]=='o' && matresp[i-1][j]=='o'))
                cout<< "BARCO AFUNDADO!!"<<endl;
    else if(matresp[i][j+1]=='o'){
        if(mat[i][j-1]=='i' && matresp[i][j-2]=='o')
            cout<< "BARCO AFUNDADO!!"<<endl;
        if (mat[i][j-1]=='i' && mat[i][j-2]=='i' && matresp[i][j-3]=='o')
            cout<< "BARCO AFUNDADO!!"<<endl;   }
    else if(matresp[i][j-1]=='o'){
        if(mat[i][j+1]=='i' && matresp[i][j+2]=='o')
            cout<< "BARCO AFUNDADO!!"<<endl;
        if (mat[i][j+1]=='i' && mat[i][j+2]=='i' && matresp[i][j+3]=='o')
            cout<< "BARCO AFUNDADO!!"<<endl;  }
    else if(matresp[i][j+2]=='o' && matresp[i][j-2]=='o'){
        if(mat[i][j+1]=='i' && mat[i][j-i]=='i')
            cout<< "BARCO AFUNDADO!!"<<endl;}
    }
    else if(j==9){
        if(i==0){
            if(matresp[i][j-1]=='o' && matresp[i+1][j]=='o')
            cout<< "BARCO AFUNDADO!!"<<endl;
         else if(matresp[i][j-2]=='o' && mat[i][j-1]=='i')
                cout<< "BARCO AFUNDADO!!"<<endl;
            if (mat[i][j-1]=='i' && mat[i][j-2]=='i' && matresp[i][j-3]=='o')
                cout<< "BARCO AFUNDADO!!"<<endl;}

        else if(i==9){
            if(matresp[i][j-1]=='o' && matresp[i-1][j]=='o')
            cout<< "BARCO AFUNDADO!!"<<endl;
            else if(matresp[i][j-2]=='o' && mat[i][j-1]=='i')
                cout<< "BARCO AFUNDADO!!"<<endl;
                if (mat[i][j-1]=='i' && mat[i][j-2]=='i' && matresp[i][j-3]=='o')
                cout<< "BARCO AFUNDADO!!"<<endl;}

        else{
         if(( matresp[i][j-1]=='o' && matresp[i+1][j]=='o' && matresp[i-1][j]=='o'))
                cout<< "BARCO AFUNDADO!!"<<endl;
        else if(matresp[i][j-2]=='o' && mat[i][j-1]=='i')
                cout<< "BARCO AFUNDADO!!"<<endl;
                if (mat[i][j-1]=='i' && mat[i][j-2]=='i' && matresp[i][j-3]=='o')
                cout<< "BARCO AFUNDADO!!"<<endl;}}

    else if(j==0){
        if(i==0){
            if(matresp[i][j+1]=='o' && matresp[i+1][j]=='o')
            cout<< "BARCO AFUNDADO!!"<<endl;
            else if(mat[i][j+1]=='i' && matresp[i][j+2]=='o')
                cout<< "BARCO AFUNDADO!!"<<endl;
                else if(matresp[i][j+3]=='o' && mat[i][j+1]=='i' && mat[i][j+2]=='i')
                cout<< "BARCO AFUNDADO!!"<<endl;}

        else if(i==9){
            if(matresp[i][j+1]=='o' && matresp[i-1][j]=='o')
            cout<< "BARCO AFUNDADO!!"<<endl;
            else if(mat[i][j+1]=='i' && matresp[i][j+2]=='o')
                cout<< "BARCO AFUNDADO!!"<<endl;
                if (mat[i][j+1]=='i' && mat[i][j+2]=='i' && matresp[i][j+3]=='o')
                cout<< "BARCO AFUNDADO!!"<<endl;}
        else{
            if(( matresp[i][j+1]=='o' && matresp[i+1][j]=='o' && matresp[i-1][j]=='o'))
                cout<< "BARCO AFUNDADO!!"<<endl;
            else if(matresp[i][j+2]=='o' && mat[i][j+1]=='i')
                cout<< "BARCO AFUNDADO!!"<<endl;
                if (mat[i][j+1]=='i' && mat[i][j+2]=='i' && matresp[i][j+3]=='o')
                cout<< "BARCO AFUNDADO!!"<<endl;}}
}

//função responsável para mostrar se o barco na vertical foi afundado
void afundabarcov(char mat[10][10], char matresp[10][10], int i, int j){
    if(i!=0 && i!=9 ){
    if(matresp[i+1][j]=='o'){
        if(mat[i-1][j]=='i' && matresp[i-2][j]!='i')
            cout<< "BARCO AFUNDADO!!"<<endl;
        if (mat[i-1][j]=='i' && mat[i-2][j]=='i' && matresp[i-3][j]!='i')
            cout<< "BARCO AFUNDADO!!"<<endl;   }
    else if(matresp[i-1][j]!='i'){
        if(mat[i+1][j]=='i' && matresp[i+2][j]!='i')
            cout<< "BARCO AFUNDADO!!"<<endl;
        if (mat[i+1][j]=='i' && mat[i+2][j]=='i' && matresp[i+3][j]!='i')
            cout<< "BARCO AFUNDADO!!"<<endl;  }
    else if(matresp[i+2][j]=='o' && matresp[i-2][j]!='i'){
        if(mat[i+1][j]=='i' && mat[i-1][j]=='i')
            cout<< "BARCO AFUNDADO!!"<<endl;}}

    else if(i==0 ){
       if(mat[i+1][j]=='i' && matresp[i+2][j]=='o')
            cout<< "BARCO AFUNDADO!!"<<endl;
        if(mat[i+1][j]=='i' && mat[i+2][j]=='i' && matresp[i+3][j]=='o' )
            cout<< "BARCO AFUNDADO!!"<<endl;}

    else if(i==9){
        if(mat[i-1][j]=='i' && matresp[i-2][j]=='o')
            cout<< "BARCO AFUNDADO!!"<<endl;
        if (mat[i-1][j]=='i' && mat[i-2][j]=='i' && matresp[i-3][j]=='o')
            cout<< "BARCO AFUNDADO!!"<<endl;}
}

//função para a jogada dos participantes
int jogada(char mat[10][10], char matresp[10][10], char dificuldade){
    int pontos1=0, pontos2=0, i, j, retorno1, retorno2, retverifica;
     for(int k=0; k<100; k++){
     cout<< "Jogador 1, digite a posicao do seu tiro, primeiro o numero da linha e depois o da coluna."<<endl;
     cin>>i>>j;
     //caso a posição seja inválida, entrará no while
            while((i<0 || i>9) || (j<0 || j>9)|| (mat[i][j]!='~')){
            if((i<0 || i>9) || (j<0 || j>9))
                cout<< "Posicao inavlida, digite numeros validos (de 0 a 9)!"<<endl;
            else if(mat[i][j]!='~')
                cout<< "Somente posicoes vazias sao validas, digite uma posicao que apresente '~'."<<endl;
            cin>>i>>j;}

     cout<<endl;
     mat[i][j] = matresp[i][j];
     if(mat[i][j]=='i'){

           if(dificuldade=='F'){
            cout<< "Voce acertou um navio, parabens!! Acumulou mais 5 pontos."<<endl;
            pontos1+=5;
            cout<< "Saldo equivalente a: "<<pontos1<< " pontos."<<endl;
            afundabarcoh(mat, matresp, i, j);
            afundabarcov(mat, matresp, i, j);
             }

           else if(dificuldade=='M' || dificuldade=='D'){
           if(i==0 || i==9 || j==0 || j==9){
            //Chama a função para verificar as bordas.
            retverifica=verificar(mat, matresp, i, j);
              if(retverifica==3){
                cout<< "Voce acertou um navio, parabens!! Acumulou mais 5 pontos."<<endl;
                pontos1+=5;
                cout<< "Saldo equivalente a: "<<pontos1<< " pontos."<<endl;
                if(dificuldade=='M'){
                    afundabarcoh(mat, matresp, i, j);
                    afundabarcov(mat, matresp, i, j);}}
              else if(retverifica==4){
                cout<< "Voce acertou a continuacao de um navio!! Acumulou apenas mais 2 pontos."<<endl;
                pontos1+=2;
                cout<< "Saldo equivalente a: "<<pontos1<< " pontos."<<endl;
                if(dificuldade=='M'){
                    afundabarcoh(mat, matresp, i, j);
                    afundabarcov(mat, matresp, i, j);}}
              else if(retverifica==0){
                cout<< "Que pena, nenhuma embarcacao encontrada."<<endl;
                pontos1+=0;
                cout<< "Saldo equivalente a: "<<pontos1<< " pontos."<<endl;}}

            else{
            if(mat[i][j+1]!='i' && mat[i][j-1]!='i'&& mat[i+1][j]!='i' && mat[i-1][j]!='i'){
            cout<< "Voce acertou um navio, parabens!! Acumulou mais 5 pontos."<<endl;
            pontos1+=5;
            cout<< "Saldo equivalente a: "<<pontos1<< " pontos."<<endl;
            if(dificuldade=='M'){
                afundabarcoh(mat, matresp, i, j);
                afundabarcov(mat, matresp, i, j);}}

            else {
            cout<< "Voce acertou a continuacao de um navio!! Acumulou apenas mais 2 pontos."<<endl;
            pontos1+=2;
            cout<< "Saldo equivalente a: "<<pontos1<< " pontos."<<endl;
            if(dificuldade=='M'){
                afundabarcoh(mat, matresp, i, j);
                afundabarcov(mat, matresp, i, j);}}}}}


     else if(mat[i][j]=='o'){
            cout<< "Que pena, nenhuma embarcacao encontrada."<<endl;
            pontos1+=0;
            cout<< "Saldo equivalente a: "<<pontos1<< " pontos."<<endl;}

     imprime(mat);
     retorno1=confere(mat, matresp);
     //Se o retorno for 10, quer dizer que todos os barcos foram encontrados, e a partir disso os pontos são contabilizados para decidir o ganhador.
     if(retorno1==10){
            if(pontos1>pontos2){
                cout<< "PARABENS!! JOGADOR 1 VENCEU A PARTIDA!! SALDO FINAL: "<<pontos1<<endl;;
                return 2;}
            else if(pontos2>pontos1){
                cout<< "PARABENS!! JOGADOR 2 VENCEU A PARTIDA!! SALDO FINAL: "<<pontos2<< endl;
                return 3;}
            else
                cout<< "DEU EMPATE!! AMBOS OS JOGADORES ACUMULARAM A MESMA QUANTIDADE DE PONTOS EQUIVALENTE A: "<<pontos1<< "   COM ISSO, NINGUEM GANHOU A PARTIDA!!";
                break;
        }
     cout<<endl;

     cout<< "Jogador 2, digite a posicao do seu tiro, primeiro o numero da linha e depois o da coluna."<<endl;
     cin>>i>>j;
     //caso a posição seja inválida, entrará no while
            while((i<0 || i>9) || (j<0 || j>9) || (mat[i][j]!='~')){
           if((i<0 || i>9) || (j<0 || j>9))
                cout<< "Posicao inavlida, digite numeros validos (de 0 a 9)!"<<endl;
            else if(mat[i][j]!='~')
                cout<< "Somente posicoes vazias sao validas, digite uma posicao que apresente '~'."<<endl;
            cin>>i>>j;}

    cout<<endl;
    mat[i][j] = matresp[i][j];
    if(mat[i][j]=='i'){

             if(dificuldade=='F'){
            cout<< "Voce acertou um navio, parabens!! Acumulou mais 5 pontos."<<endl;
            pontos2+=5;
            cout<< "Saldo equivalente a: "<<pontos2<< " pontos."<<endl;
            afundabarcoh(mat, matresp, i, j);
            afundabarcov(mat, matresp, i, j);
             }
            else if(dificuldade=='M' || dificuldade=='D'){
            if(i==0 || i==9 || j==0 || j==9){
            //Chama a função para verificar as bordas.
            retverifica=verificar(mat, matresp, i, j);
            if(retverifica==3){
                cout<< "Voce acertou um navio, parabens!! Acumulou mais 5 pontos."<<endl;
                pontos2+=5;
                cout<< "Saldo equivalente a: "<<pontos2<< " pontos."<<endl;
                if(dificuldade=='M'){
                afundabarcoh(mat, matresp, i, j);
                afundabarcov(mat, matresp, i, j);}}
              else if(retverifica==4){
                cout<< "Voce acertou a continuacao de um navio!! Acumulou apenas mais 2 pontos."<<endl;
                pontos2+=2;
                cout<< "Saldo equivalente a: "<<pontos2<< " pontos."<<endl;
                if(dificuldade=='M'){
                afundabarcoh(mat, matresp, i, j);
                afundabarcov(mat, matresp, i, j);}}
              else if(retverifica==0){
                cout<< "Que pena, nenhuma embarcacao encontrada."<<endl;
                pontos2+=0;
                cout<< "Saldo equivalente a: "<<pontos2<< " pontos."<<endl;}}

            else{
            if(mat[i][j+1]!='i' && mat[i][j-1]!='i' && mat[i+1][j]!='i' && mat[i-1][j]!='i'){
            cout<< "Voce acertou um navio, parabens!! Acumulou mais 5 pontos."<<endl;
            pontos2+=5;
            cout<< "Saldo equivalente a: "<<pontos2<<" pontos."<<endl;
            if(dificuldade=='M'){
            afundabarcoh(mat, matresp, i, j);
            afundabarcov(mat, matresp, i, j);}}

            else{
            cout<< "Voce acertou a continuacao de um navio!! Acumulou apenas mais 2 pontos."<<endl;
            pontos2+=2;
            cout<< "Saldo equivalente a: "<<pontos2<< " pontos."<<endl;
            if(dificuldade=='M'){
                afundabarcoh(mat, matresp, i, j);
                afundabarcov(mat, matresp, i, j);}}}}}

     else if(mat[i][j]=='o'){
            cout<< "Que pena, nenhuma embarcacao encontrada."<<endl;
            pontos2+=0;
            cout<< "Saldo equivalente a: "<<pontos2<< " pontos."<<endl;}

     imprime(mat);
     retorno2=confere(mat, matresp);
     //Se o retorno for 10, quer dizer que todos os barcos foram encontrados, e a partir disso os pontos são contabilizados para decidir o ganhador.
     if(retorno2==10){
           if(pontos1>pontos2){
                cout<< "PARABENS!! JOGADOR 1 VENCEU A PARTIDA!! SALDO FINAL: "<<pontos1<< endl;
                return 2;}
           else if(pontos2>pontos1){
                cout<< "PARABENS!! JOGADOR 2 VENCEU A PARTIDA!! SALDO FINAL: "<<pontos2<< endl;
                return 3;}
           else
                cout<< "DEU EMPATE!! AMBOS OS JOGADORES ACUMULARAM A MESMA QUANTIDADE DE PONTOS EQUIVALENTE A: "<<pontos1<< "   COM ISSO, NINGUEM GANHOU A PARTIDA!!";
                break;}
    }
}
int main()
{
    char mat[10][10], matresp[10][10];
     int e , r;
     //inicialização do jogo, com as devidas informações.
     cout<< "  ~~~~~~~BATALHA NAVAL~~~~~~~~"<<endl;

     cout<< endl;
     cout<< "INFORMACOES SOBRE O JOGO:"<<endl;
     cout<< "O objetivo e encontrar os navios no tabuleiro, representados com 'i'."<<endl;
     cout<< "Com isso, os competidores jogarao alternadamente e quem finalizar com mais pontos vencera."<<endl;
     cout<<"So e valido acertar o tiro em posicoes vazias representadas com '~' "<<endl;
     cout<< "Existem nove barcos de tres tamanhos distintos para serem encontrados e eles nunca estarao grudados uns nos outros."<<endl;
     cout<<endl;
     cout<< "NESSE JOGO, TEMOS TRES NIVEIS DE DIFICULDADE EXPLICADOS ABAIXO:"<<endl;
     cout<< "No nivel facil, qualquer acerto computa 5 pontos e quando o barco e afundado, isso e mostrado para voces. "<<endl;
     cout<< "No nivel medio, voce recebe menos pontos se acertar a continuacao de um barco, porem ainda e mostrado quando o barco afunda."<<endl;
     cout<< "No ultimo nivel de dificuldade, alem de computar menos pontos para a continuacao de um barco, nao e mostrado quando este e afundado."<<endl;
     cout<< "BOA PARTIDA!!"<<endl;
     int continuar, partvencidas1=0, partvencidas2=0, retornoganho;
     char dificuldade;
     for(int i=0; i<10; i++){
         inicializa(mat);
         imprime(mat);
         inicializaresp(matresp);
         srand(time(NULL));
         navio3(matresp, e, r);
         navio2(matresp,e, r);
         navio1(matresp, e, r);
         //imprimetabuleiro(matresp);
         cout<<endl;
         cout<< "Ola jogadores, digite o nivel de dificuldade da partida de voces, F para facil, M para medio e D para dificil. "<<endl;
         cin>>dificuldade;
         while(dificuldade!= 'F' && dificuldade!='M' && dificuldade!='D'){
            cout<< "Opcao invalida, digite apenas uma das letras indicadas anteriormente."<<endl;
            cin>>dificuldade;
         }
         retornoganho=jogada(mat, matresp, dificuldade);
         //se a funcao retornar 2, o jogador 1 ganhou, caso retornar 3, o jogador 2 ganhou. Se retornar diferente desses dois valores, nenhum jogador ganhou efetivamente.
         if(retornoganho==2){
            partvencidas1++;
            cout<< "PARTIDAS VENCIDAS DO JOGADOR 1: "<<partvencidas1<<endl;
            cout<< "PARTIDAS VENCIDAS DO JOGADOR 2: "<<partvencidas2;}
         else if(retornoganho==3){
            partvencidas2++;
            cout<< "PARTIDAS VENCIDAS DO JOGADOR 1: "<<partvencidas1<<endl;
            cout<< "PARTIDAS VENCIDAS DO JOGADOR 2: "<<partvencidas2;}
            else{
               cout<< "PARTIDAS VENCIDAS DO JOGADOR 1: "<<partvencidas1<<endl;
                cout<< "PARTIDAS VENCIDAS DO JOGADOR 2: "<<partvencidas2;
            }
         cout<< endl;
         cout<< "FIM DE JOGO"<<endl;
         cout<<endl;
         cout<< "Se desejar jogar novamente, digite o numero zero. Caso queira parar por aqui digite o numero um."<<endl;
         cin>>continuar;
         if(continuar==1){
            partvencidas1=0, partvencidas2=0;
            break;}
            }
    return 0;
}
