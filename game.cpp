#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

string MAPA[15];
int playerW=1, playerK=1;
char x='w';

string ruchPOZIOMY(int x, string m, bool doCelu, bool pion)
{
    char pole[2]={'O',' '};
    if(pion==0){
    if (doCelu==1)     {
        m[x-1]=pole[1];
        m[x]=pole[0];}
    else if (doCelu==0){
        m[x+1]=pole[1];
        m[x]=pole[0];}
    }

    return m;
}
bool sciana(char mapa)
{
    if(mapa=='X'){
    return 1;}
    else{return 0;}
}

int main()
{
    char mapa[15][15]= //tablica[W][K]
    {
    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
    {'X','O','X',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
    {'X',' ','X',' ','X','X','X',' ','X','X','X','X','X',' ','X'},
    {'X',' ','X',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ','X'},
    {'X',' ','X',' ','X',' ','X','X','X',' ','X','X','X','X','X'},
    {'X',' ',' ',' ','X',' ','X',' ',' ',' ','X',' ',' ',' ','X'},
    {'X','X','X',' ','X','X','X',' ','X',' ','X',' ','X',' ','X'},
    {'X',' ',' ',' ',' ',' ',' ',' ','X',' ','X',' ','X',' ','X'},
    {'X',' ','X','X','X','X','X',' ','X',' ','X',' ','X','X','X'},
    {'X',' ','X',' ',' ',' ','X',' ','X',' ','X',' ',' ',' ','X'},
    {'X',' ','X',' ','X','X','X',' ','X',' ','X',' ','X',' ','X'},
    {'X',' ','X',' ',' ',' ','X',' ','X',' ','X',' ','X',' ','X'},
    {'X',' ','X','X','X',' ','X',' ','X','X','X',' ','X',' ','X'},
    {'X',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ','X','+','X'},
    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
    };

    //ladowanie mapy
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            MAPA[i]+=mapa[i][j];
        }
    }


    bool ruchPION;
    bool ruchDoCELU; //cel=dolny prawy rog
    bool freeze, first=true;
    string liniaMapy;

    do{
        if(first==false){x=getch();}//likwidacja bugu

            switch(x){
                case'w':{ruchPION=1; ruchDoCELU=0;
                         freeze=sciana((char)MAPA[playerW-1][playerK]); break;}
                case's':{ruchPION=1; ruchDoCELU=1;
                         freeze=sciana((char)MAPA[playerW+1][playerK]); break;}
                case'a':{ruchPION=0; ruchDoCELU=0;
                         freeze=sciana((char)MAPA[playerW][playerK-1]); break;}
                case'd':{ruchPION=0; ruchDoCELU=1;
                         freeze=sciana((char)MAPA[playerW][playerK+1]); break;}
                case'z':{cout<<endl<<"Zakonczono program"<<endl; return 0;}
                }

    //procedury weryfikacji
    if(freeze==false)
        {
        switch(x){
            case'w':{playerW--; break;}
            case's':{playerW++; break;}
            case'a':{playerK--; break;}
            case'd':{playerK++; break;}
            }
        }

    //procedura ruchu po zweryfikowaniu
    if(ruchPION==0 && freeze!=true){
            liniaMapy=MAPA[playerW];
            MAPA[playerW]=ruchPOZIOMY(playerK, liniaMapy, ruchDoCELU, ruchPION);
    }
    else if(ruchPION==1 && freeze!=true){
            if(ruchDoCELU==1){
            MAPA[playerW-1][playerK]=' ';
            MAPA[playerW][playerK]='O';
            }
            else if(ruchDoCELU==0){
            MAPA[playerW][playerK]='O';
            MAPA[playerW+1][playerK]=' ';
            }
    }

    //procedura odswiezania mapy
    system("cls"); freeze=false; first=false;
    for(int i=0; i<15; i++){cout<<MAPA[i]<<endl;}
    cout<<endl<<"Sterowanie: w, a, s, d. Zakoncz program: z"<<endl;

    //procedura wygrywania
    if(playerK==13 && playerW==13){cout<<endl<<"Brawo, udalo ci sie przejsc!"<<endl; getch(); return 0;}

    }while(x!='z');


    return 0;
}
