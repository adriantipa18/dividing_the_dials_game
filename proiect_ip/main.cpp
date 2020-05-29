#include <iostream>
#include <fstream>
#include <winbgim.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>

using namespace std;

ifstream f1("easy.in");

#define FUNDAL BLACK

DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeith = GetSystemMetrics(SM_CYSCREEN);



int stanga,sus,width,height,latura, numar,mute=1,retry=0,culoareselectata=0;
bool gata;
bool castigator;

int culoare=2, nr, nr1=8, m=0, n=5, c;
int ok=1;
void joc_easy(int retry);
void joc_medium(int retry);
void joc_hard(int retry);
void joc_medium2(int retry);
void casuta();
void meniu_principal();
int vectorfrecventa[10];
void tabelav()
{
    for(int i=2; i<=9; i++)
        vectorfrecventa[i]=8;
}
void tabelav1()
{
    for(int i=2; i<=5; i++)
        vectorfrecventa[i]=16;
}
void tabela()
{
    int culoarescor=2;
    setcolor(BLACK);
    int x=175;
    for(int i=2; i<=9; i++)
    {
        setfillstyle(SOLID_FILL, culoarescor++);
        setcolor(BLACK);
        circle(1250, x, 25);
        fillellipse(1250, x, 25, 25);
        x+=75;
    }

}
void tabela1()
{
    int culoarescor=2;
    setcolor(BLACK);
    int x=325;
    for(int i=2; i<=5; i++)
    {
        setfillstyle(SOLID_FILL, culoarescor++);
        setcolor(BLACK);
        circle(1250, x, 25);
        fillellipse(1250, x, 25, 25);
        x+=75;
    }

}
void scorplus(int i)
{
    vectorfrecventa[i]++;
    cout<<"pozitia"<<i<<"+1"<<endl;
    if(vectorfrecventa[i]==0)
    {
        setfillstyle(SOLID_FILL, i);
        setcolor(BLACK);
        circle(1250, 175+(i-2)*75, 25);
        fillellipse(1250, 175+(i-2)*75, 25, 25);
        line(1225,150+(i-2)*75, 1275, 200+(i-2)*75);
        line(1225,200+(i-2)*75, 1275, 150+(i-2)*75);
    }
    else if(vectorfrecventa[i]<0)
    {
        setfillstyle(SOLID_FILL, i);
        setcolor(BLACK);
        circle(1250, 175+(i-2)*75, 25);
        fillellipse(1250, 175+(i-2)*75, 25, 25);
        line(1225,150+(i-2)*75, 1275, 200+(i-2)*75);
        line(1225,200+(i-2)*75, 1275, 150+(i-2)*75);

    }
    else
    {
        setfillstyle(SOLID_FILL, i);
        setcolor(BLACK);
        circle(1250, 175+(i-2)*75, 25);
        fillellipse(1250, 175+(i-2)*75, 25, 25);
    }

}
void scorminus(int i)
{
    vectorfrecventa[i]--;
    cout<<"pozitia"<<i<<"-1"<<endl;
    if(vectorfrecventa[i]==0)
    {
        setfillstyle(SOLID_FILL, i);
        setcolor(BLACK);
        circle(1250, 175+(i-2)*75, 25);
        fillellipse(1250, 175+(i-2)*75, 25, 25);
        line(1225,150+(i-2)*75, 1275, 200+(i-2)*75);
        line(1225,200+(i-2)*75, 1275, 150+(i-2)*75);
    }
    else if(vectorfrecventa[i]<0)
    {
        setfillstyle(SOLID_FILL, i);
        setcolor(BLACK);
        circle(1250, 175+(i-2)*75, 25);
        fillellipse(1250, 175+(i-2)*75, 25, 25);
        line(1225,150+(i-2)*75, 1275, 200+(i-2)*75);
        line(1225,200+(i-2)*75, 1275, 150+(i-2)*75);
    }
    else
    {
        setfillstyle(SOLID_FILL, i);
        setcolor(BLACK);
        circle(1250, 175+(i-2)*75, 25);
        fillellipse(1250, 175+(i-2)*75, 25, 25);

    }
}
void scorplus1(int i)
{
    vectorfrecventa[i]++;
    cout<<"pozitia"<<i<<"+1"<<endl;
    if(vectorfrecventa[i]==0)
    {
        setfillstyle(SOLID_FILL, i);
        setcolor(BLACK);
        circle(1250, 325+(i-2)*75, 25);
        fillellipse(1250, 325+(i-2)*75, 25, 25);
        line(1225,300+(i-2)*75, 1275, 350+(i-2)*75);
        line(1225,350+(i-2)*75, 1275, 300+(i-2)*75);
    }
    else if(vectorfrecventa[i]<0)
    {
        setfillstyle(SOLID_FILL, i);
        setcolor(BLACK);
        circle(1250, 325+(i-2)*75, 25);
        fillellipse(1250, 325+(i-2)*75, 25, 25);
        line(1225,300+(i-2)*75, 1275, 350+(i-2)*75);
        line(1225,350+(i-2)*75, 1275, 300+(i-2)*75);

    }
    else
    {
        setfillstyle(SOLID_FILL, i);
        setcolor(BLACK);
        circle(1250, 325+(i-2)*75, 25);
        fillellipse(1250, 325+(i-2)*75, 25, 25);
    }

}
void scorminus1(int i)
{
    vectorfrecventa[i]--;
    cout<<"pozitia"<<i<<"-1"<<endl;
    if(vectorfrecventa[i]==0)
    {
        setfillstyle(SOLID_FILL, i);
        setcolor(BLACK);
        circle(1250, 325+(i-2)*75, 25);
        fillellipse(1250, 325+(i-2)*75, 25, 25);
        line(1225,300+(i-2)*75, 1275, 350+(i-2)*75);
        line(1225,350+(i-2)*75, 1275, 300+(i-2)*75);
    }
    else if(vectorfrecventa[i]<0)
    {
        setfillstyle(SOLID_FILL, i);
        setcolor(BLACK);
        circle(1250, 325+(i-2)*75, 25);
        fillellipse(1250, 325+(i-2)*75, 25, 25);
        line(1225,300+(i-2)*75, 1275, 350+(i-2)*75);
        line(1225,350+(i-2)*75, 1275, 300+(i-2)*75);
    }
    else
    {
        setfillstyle(SOLID_FILL, i);
        setcolor(BLACK);
        circle(1250, 325+(i-2)*75, 25);
        fillellipse(1250, 325+(i-2)*75, 25, 25);

    }
}
int TablaDeJoc[8][8];

struct easy
{
    int Matrice_puncte[8][8];
    int Matrice_completa[8][8];
} ve[10],vm[26],vh[9],vm2[21];

int elve;
void citire_easymode()
{
    ifstream f1("easy.in");
    int n=8,x,y,k=9,contor=2;
    while(k)
    {
        contor=2;
        elve++;
        while(n)
        {
            f1>>x>>y;
            ve[elve].Matrice_puncte[x][y]=contor++;
            n--;
        }
        n=8;
        for(int c=1; c<=8; c++)
            for(int j=1; j<=8; j++)
                f1>>ve[elve].Matrice_completa[c][j];
        k--;
    }
}

void afiseazaE(int k)
{
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
            cout<<ve[k].Matrice_puncte[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
            cout<<ve[k].Matrice_completa[i][j]<<" ";
        cout<<endl;
    }
}
int elmm;
void citire_mediummode()
{
    ifstream f2("medium.in");
    int n=16,x,y,k=25,contor=2;
    while(k)
    {
        elmm++;
        contor=2;
        n=16;
        while(n!=8)
        {
            f2>>x>>y;
            vm[elmm].Matrice_puncte[x][y]=contor++;
            n--;
        }
        while(n)
        {
            f2>>x>>y;
            vm[elmm].Matrice_puncte[x][y]=1;
            n--;
        }
        for(int c=1; c<=8; c++)
            for(int j=1; j<=8; j++)
                f2>>vm[elmm].Matrice_completa[c][j];
        k--;
    }
    f2.close();
}

void afiseazaM(int k)
{

    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
            cout<<vm[k].Matrice_puncte[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
            cout<<vm[k].Matrice_completa[i][j]<<" ";
        cout<<endl;
    }
}

int elhm;
void citire_hardmode()
{
    ifstream f3("hard.in");
    int n=24,x,y,k=9,contor=2;
    while(k)
    {
        elhm++;
        contor=2;
        while(n!=16)
        {
            f3>>x>>y;
            vh[elhm].Matrice_puncte[x][y]=contor++;
            n--;
        }
        while(n!=8)
        {
            f3>>x>>y;
            vh[elhm].Matrice_puncte[x][y]=1;
            n--;
        }
        while(n)
        {
            f3>>x>>y;
            vh[elhm].Matrice_puncte[x][y]=10;
            n--;
        }
        n=24;
        for(int c=1; c<=8; c++)
            for(int j=1; j<=8; j++)
                f3>>vh[elhm].Matrice_completa[c][j];
        k--;
    }
    f3.close();
}
int elmm2;
void citire_mediummode2()
{
    ifstream f4("medium2.in");
    int n=8,x,y,k=20,contor=2;
    while(k)
    {
        elmm2++;
        contor=2;
        n=8;
        while(n!=4)
        {
            f4>>x>>y;
            vm2[elmm2].Matrice_puncte[x][y]=contor++;
            n--;
        }
        while(n)
        {
            f4>>x>>y;
            vm2[elmm2].Matrice_puncte[x][y]=1;
            n--;
        }
        for(int c=1; c<=8; c++)
            for(int j=1; j<=8; j++)
                f4>>vm2[elmm2].Matrice_completa[c][j];
        k--;
    }
    f4.close();
}
void afiseazaM2(int k)
{

    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
            cout<<vm2[k].Matrice_puncte[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
            cout<<vm2[k].Matrice_completa[i][j]<<" ";
        cout<<endl;
    }
}
void afiseazaH(int k)
{
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
            cout<<vh[k].Matrice_puncte[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
            cout<<vh[k].Matrice_completa[i][j]<<" ";
        cout<<endl;
    }
}

void inapoi();
void meniu_joaca();
void mini_meniu();
void meniu_8();
void meniu_4();
void exitgame();

void desen()
{
    int i,j;
    numar=8;
    width=560;
    height=560;
    latura=width/numar;
    sus=(getmaxy()-width)/2;
    stanga=(getmaxx()-height)/2;
    setbkcolor(FUNDAL);
    clearviewport();
    setcolor(BLUE);
    for (i=1; i<=numar; i++)
        for (j=1; j<=numar; j++)
            rectangle(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*i,sus+latura*j);
    mini_meniu();
}

void colorare_puncte_easy(int k)
{
    int x1, x2, y1, y2, x3, y3, x4, y4, linia, coloana;
    int color=2;
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            if(ve[k].Matrice_puncte[i][j]!=0)
            {
                linia=i;
                coloana=j;
                x1=stanga+latura*(coloana-1);
                y1=sus+latura*(linia-1);
                x2=x1+latura;
                y2=y1;
                x3=x1;
                y3=y1+latura;
                x4=x2;
                y4=y3;
                setfillstyle(SOLID_FILL, color);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                color++;
            }
}

void colorare_puncte_medium(int k)
{
    int x1, x2, y1, y2, x3, y3, x4, y4, linia, coloana;
    int color=2;
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            if(vm[k].Matrice_puncte[i][j]>=2)
            {
                linia=i;
                coloana=j;
                x1=stanga+latura*(coloana-1);
                y1=sus+latura*(linia-1);
                x2=x1+latura;
                y2=y1;
                x3=x1;
                y3=y1+latura;
                x4=x2;
                y4=y3;
                setfillstyle(SOLID_FILL, color);
                color++;
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }
}
void colorare_puncte_hard(int k)
{
    int x1, x2, y1, y2, x3, y3, x4, y4, linia, coloana;
    int color=2;
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            if(vh[k].Matrice_puncte[i][j]>=2 &&vh[k].Matrice_puncte[i][j]!=10 )
            {
                linia=i;
                coloana=j;
                x1=stanga+latura*(coloana-1);
                y1=sus+latura*(linia-1);
                x2=x1+latura;
                y2=y1;
                x3=x1;
                y3=y1+latura;
                x4=x2;
                y4=y3;
                setfillstyle(SOLID_FILL, color);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                color++;
            }
}
void colorare_puncte_medium2(int k)
{
    int x1, x2, y1, y2, x3, y3, x4, y4, linia, coloana;
    int color=2;
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            if(vm2[k].Matrice_puncte[i][j]>=2)
            {
                linia=i;
                coloana=j;
                x1=stanga+latura*(coloana-1);
                y1=sus+latura*(linia-1);
                x2=x1+latura;
                y2=y1;
                x3=x1;
                y3=y1+latura;
                x4=x2;
                y4=y3;
                setfillstyle(SOLID_FILL, color);
                color++;
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }
}
void desenare_puncte_medium2(int k)
{
    int x1, x2, y1, y2, x3, y3, x4, y4, linia, coloana;
    setcolor(BLUE);
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            if(vm2[k].Matrice_puncte[i][j]==1)
            {
                linia=i;
                coloana=j;
                x1=stanga+latura*(coloana-1);
                y1=sus+latura*(linia-1);
                x2=x1+latura;
                y2=y1;
                x3=x1;
                y3=y1+latura;
                x4=x2;
                y4=y3;
                setfillstyle(LTSLASH_FILL, BLUE);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }
}
void desenare_puncte_medium(int k)
{
    int x1, x2, y1, y2, x3, y3, x4, y4, linia, coloana;
    setcolor(BLUE);
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            if(vm[k].Matrice_puncte[i][j]==1)
            {
                linia=i;
                coloana=j;
                x1=stanga+latura*(coloana-1);
                y1=sus+latura*(linia-1);
                x2=x1+latura;
                y2=y1;
                x3=x1;
                y3=y1+latura;
                x4=x2;
                y4=y3;
                setfillstyle(LTSLASH_FILL, BLUE);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }
}
void desenare_puncte_hard(int k)
{
    int x1, x2, y1, y2, x3, y3, x4, y4, linia, coloana;
    setcolor(BLUE);
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            if(vh[k].Matrice_puncte[i][j]==1)
            {
                linia=i;
                coloana=j;
                x1=stanga+latura*(coloana-1);
                y1=sus+latura*(linia-1);
                x2=x1+latura;
                y2=y1;
                x3=x1;
                y3=y1+latura;
                x4=x2;
                y4=y3;
                setfillstyle(LTSLASH_FILL, BLUE);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }
            else if(vh[k].Matrice_puncte[i][j]==10)
            {
                linia=i;
                coloana=j;
                x1=stanga+latura*(coloana-1);
                y1=sus+latura*(linia-1);
                x2=x1+latura;
                y2=y1;
                x3=x1;
                y3=y1+latura;
                x4=x2;
                y4=y3;
                setfillstyle(XHATCH_FILL, BLUE);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }
}
void cerc_culoare(int culoareselectata)
{
    if(vectorfrecventa[culoareselectata]<=0)
    {
        setcolor(BLACK);
        settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
        outtextxy(490, 50, "Culoarea selectata: ");
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        circle(1100, 70, 30);
        fillellipse(1100,70, 30, 30);
        setcolor(DARKGRAY);
        settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
        outtextxy(500, 50, "Selectati alta culoare!");
    }
    else
    {
        setcolor(BLACK);
        settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
        outtextxy(500, 50, "Selectati alta culoare!");
        setcolor(DARKGRAY);
        settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
        outtextxy(490, 50, "Culoarea selectata: ");
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, culoareselectata);
        circle(1100, 70, 30);
        fillellipse(1100,70, 30, 30);
    }

}

void inima(int n, int c)
{
    int x, y, raza;
    x=y=40;
    raza=10;
    int nr=0;
    while(nr!=n)
    {
        setcolor(c);
        circle(x,y,raza);
        circle(x+2*raza, y, raza);
        line(x-raza, y, x+raza, 70);
        line(x+raza*3, y, x+raza, 70);
        setfillstyle(SOLID_FILL, c);
        floodfill(x, y, c);
        floodfill(x+2*raza, y, c);
        floodfill(x+raza, 60, c);
        nr++;
        x=x+5*raza;
    }

}
void final_easy();
void final_medium();
void final_hard();
void final_medium2();

int culoaretabel(int x,int y)
{
    if(x>=1225&&x<=1275&&y>=150&&y<=200)
        if(vectorfrecventa[2]>0)
            return 2;
        else
            return 0;
    if(x>=1225&&x<=1275&&y>=225&&y<=275)
        if(vectorfrecventa[3]>0)
            return 3;
        else
            return 0;
    if(x>=1225&&x<=1275&&y>=300&&y<=350)
        if(vectorfrecventa[4]>0)
            return 4;
        else
            return 0;
    if(x>=1225&&x<=1275&&y>=375&&y<=425)
        if(vectorfrecventa[5]>0)
            return 5;
        else
            return 0;
    if(x>=1225&&x<=1275&&y>=450&&y<=500)
        if(vectorfrecventa[6]>0)
            return 6;
        else
            return 0;
    if(x>=1225&&x<=1275&&y>=525&&y<=575)
        if(vectorfrecventa[7]>0)
            return 7;
        else
            return 0;
    if(x>=1225&&x<=1275&&y>=600&&y<=650)
        if(vectorfrecventa[8]>0)
            return 8;
        else
            return 0;
    if(x>=1225&&x<=1275&&y>=675&&y<=725)
        if(vectorfrecventa[9]>0)
            return 9;
        else
            return 0;

}
int culoaretabel1(int x,int y)
{
    if(x>=1225&&x<=1275&&y>=300&&y<=350)
        if(vectorfrecventa[2]>0)
            return 2;
        else
            return 0;
    if(x>=1225&&x<=1275&&y>=375&&y<=425)
        if(vectorfrecventa[3]>0)
            return 3;
        else
            return 0;
    if(x>=1225&&x<=1275&&y>=450&&y<=500)
        if(vectorfrecventa[4]>0)
            return 4;
        else
            return 0;
    if(x>=1225&&x<=1275&&y>=525&&y<=575)
        if(vectorfrecventa[5]>0)
            return 5;
        else
            return 0;

}
void reguli_usor();
void reguli_mediu();
void reguli_dificil();

void punerePiesa_easy(int k)
{
    int x,y;
    int x1, x2, y1, y2, x3, y3, x4, y4, linia, coloana;
    c=culoare;
    if(m==0)
        inima(n, RED);
    if(m==5)
        gata=true;
    else
    {

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(x>=70 && x<=230 && y>=170 && y<=230)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();

            }
            else if(x>=70 && x<=230 && y>=290 && y<=350)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_easy(0);

            }
            else if(x>=70 && x<=230 && y>=410 && y<=470)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                reguli_usor();

            }
            else if(x>=70 && x<=230 && y>=530 && y<=590)
            {
                if(mute==1)
                {
                    mute=0;
                    setcolor(WHITE);
                    line(70, 560, 230, 560);
                }
                else
                {
                    mute=1;
                    setcolor(BLACK);
                    line(70, 560, 230, 560);
                    setcolor(WHITE);
                    arc(100, 560, 90, 270, 30);
                    line(100, 530, 200, 530);
                    line(100, 590, 200, 590);
                    arc(200, 560, 270, 90, 30);
                    setcolor(WHITE);
                    settextstyle(6, HORIZ_DIR, 3);
                    outtextxy(95, 550, "SUNET");
                }
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
            }
            else if(x>=70 && x<=230 && y>=650 && y<=710)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_joaca();
            }
            else if(x>=1225&&x<=1275&&y>=150&&y<=800)
            {
                culoareselectata=culoaretabel(x,y);
                cerc_culoare(culoareselectata);
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
            else if (x>=stanga && x<=stanga+width && y>=sus&&y<=sus+height)
            {
                linia=(y-sus)/latura+1;
                coloana=(x-stanga)/latura+1;
                if (TablaDeJoc[linia][coloana]==0)
                {
                    nr++;
                    TablaDeJoc[linia][coloana]=culoareselectata;
                    if(ve[k].Matrice_puncte[linia][coloana]!=0)
                        {
                            if(culoareselectata==0)
                                TablaDeJoc[linia][coloana]=ve[k].Matrice_puncte[linia][coloana];
                                culoareselectata=ve[k].Matrice_puncte[linia][coloana];

                        }
                    scorminus(culoareselectata);
                    cerc_culoare(culoareselectata);
                    c=culoareselectata;
                    cout<<culoareselectata<<endl;
                    if(culoareselectata==c)
                    {
                        if(ve[k].Matrice_completa[linia][coloana]!=(c-1))
                        {
                            m++;
                            inima(n,BLACK);
                            inima(n-m,RED);
                            if(mute)
                                PlaySound(TEXT("error.wav"),NULL,SND_SYNC);
                        }
                        else if(mute)
                            PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                    }
                    if(culoareselectata)
                    {
                        setcolor(BLACK);
                        x1=stanga+latura*(coloana-1);
                        y1=sus+latura*(linia-1);
                        x2=x1+latura;
                        y2=y1;
                        x3=x1;
                        y3=y1+latura;
                        x4=x2;
                        y4=y3;
                        int puncte[]= {x1, y1, x3, y3, x4, y4, x2, y2, x1, y1};
                        setfillstyle(SOLID_FILL, culoareselectata);
                        fillpoly(5, puncte);
                    }
                    if(ve[k].Matrice_puncte[linia][coloana]!=0)
                    {
                        setcolor(BLACK);
                        setfillstyle(SOLID_FILL, BLACK);
                        circle((x1+x4)/2,(y1+y4)/2, 20);
                        fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                    }
                }
                else
                {
                    if(ve[k].Matrice_puncte[linia][coloana]==0)
                    {
                        scorplus(TablaDeJoc[linia][coloana]);
                        if(mute)
                            PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                        nr--;
                        setcolor(BLACK);
                        TablaDeJoc[linia][coloana]=0;
                        x1=stanga+latura*(coloana-1);
                        y1=sus+latura*(linia-1);
                        x2=x1+latura;
                        y2=y1;
                        x3=x1;
                        y3=y1+latura;
                        x4=x2;
                        y4=y3;
                        int puncte[]= {x1, y1, x3, y3, x4, y4, x2, y2, x1, y1};
                        setcolor(BLUE);
                        rectangle(x1, y1, x3, y3);
                        setfillstyle(SOLID_FILL, FUNDAL);
                        fillpoly(5, puncte);

                    }
                    else
                    {
                        if(vectorfrecventa[ve[k].Matrice_puncte[linia][coloana]]>0)
                            culoareselectata=ve[k].Matrice_puncte[linia][coloana];
                            cerc_culoare(culoareselectata);
                    }
                }
            }
        }
    }
}
void exemplu();
void punerePiesa_mediu(int k)
{
    int x,y;
    int x1, x2, y1, y2, x3, y3, x4, y4, linia, coloana;
    c=culoare;
    if(m==0)
        inima(n, RED);
    if(m==5)
        gata=true;
    else
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(x>=70 && x<=230 && y>=170 && y<=230)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();

            }
            else if(x>=70 && x<=230 && y>=290 && y<=350)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium(0);

            }
            else if(x>=70 && x<=230 && y>=410 && y<=470)
            {
                if(mute==1)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                reguli_mediu();
            }
            else if(x>=70 && x<=230 && y>=530 && y<=590)
            {
                if(mute==1)
                {
                    mute=0;
                    setcolor(WHITE);
                    line(70, 560, 230, 560);
                }
                else
                {
                    mute=1;
                    setcolor(BLACK);
                    line(70, 560, 230, 560);
                    setcolor(WHITE);
                    arc(100, 560, 90, 270, 30);
                    line(100, 530, 200, 530);
                    line(100, 590, 200, 590);
                    arc(200, 560, 270, 90, 30);
                    setcolor(WHITE);
                    settextstyle(6, HORIZ_DIR, 3);
                    outtextxy(95, 550, "SUNET");
                }
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
            }
            else if(x>=70 && x<=230 && y>=650 && y<=710)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_joaca();
            }
            if(x>=1225&&x<=1275&&y>=150&&y<=800)
            {
                culoareselectata=culoaretabel(x,y);
                cerc_culoare(culoareselectata);
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
            else if (x>=stanga && x<=stanga+width && y>=sus&&y<=sus+height)
            {
                linia=(y-sus)/latura+1;
                coloana=(x-stanga)/latura+1;
                if (TablaDeJoc[linia][coloana]==0)
                {
                    nr++;
                    //if(culoareselectata!=0)
                    TablaDeJoc[linia][coloana]=culoareselectata;
                    if(vm[k].Matrice_puncte[linia][coloana]>=2)
                        {
                            if(culoareselectata==0)
                                TablaDeJoc[linia][coloana]=vm[k].Matrice_puncte[linia][coloana];
                                culoareselectata=vm[k].Matrice_puncte[linia][coloana];

                        }
                    scorminus(culoareselectata);
                    cerc_culoare(culoareselectata);
                    c=culoareselectata;
                    cout<<culoareselectata;
                    if(culoareselectata==c)
                    {
                        if(vm[k].Matrice_completa[linia][coloana]!=(c-1))
                        {
                            if(mute)
                                PlaySound(TEXT("error.wav"),NULL,SND_SYNC);
                            m++;
                            inima(n,BLACK);
                            inima(n-m,RED);
                        }
                        else if(mute)
                            PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                    }
                    if(culoareselectata)
                    {
                        setcolor(BLACK);
                        x1=stanga+latura*(coloana-1);
                        y1=sus+latura*(linia-1);
                        x2=x1+latura;
                        y2=y1;
                        x3=x1;
                        y3=y1+latura;
                        x4=x2;
                        y4=y3;
                        int puncte[]= {x1, y1, x3, y3, x4, y4, x2, y2, x1, y1};
                        setfillstyle(SOLID_FILL, culoareselectata);
                        fillpoly(5, puncte);

                    if(vm[k].Matrice_puncte[linia][coloana]>=2)
                    {
                        setfillstyle(SOLID_FILL, BLACK);
                        circle((x1+x4)/2,(y1+y4)/2, 20);
                        fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                    }
                    else if(vm[k].Matrice_puncte[linia][coloana]==1)
                    {
                        setfillstyle(LTSLASH_FILL, 14);
                        setcolor(BLACK);
                        circle((x1+x4)/2,(y1+y4)/2, 20);
                        fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                    }}
                }
                else
                {
                    if(vm[k].Matrice_puncte[linia][coloana]==0)
                    {
                        scorplus(TablaDeJoc[linia][coloana]);
                        if(mute)
                            PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                        nr--;
                        setcolor(BLACK);
                        TablaDeJoc[linia][coloana]=0;
                        x1=stanga+latura*(coloana-1);
                        y1=sus+latura*(linia-1);
                        x2=x1+latura;
                        y2=y1;
                        x3=x1;
                        y3=y1+latura;
                        x4=x2;
                        y4=y3;
                        int puncte[]= {x1, y1, x3, y3, x4, y4, x2, y2, x1, y1};
                        setcolor(BLUE);
                        rectangle(x1, y1, x3, y3);
                        setfillstyle(SOLID_FILL, FUNDAL);
                        fillpoly(5, puncte);
                    }
                    else
                    {
                        if(vm[k].Matrice_puncte[linia][coloana]==1)
                        {
                            scorplus(TablaDeJoc[linia][coloana]);
                            nr--;
                            setcolor(BLACK);
                            TablaDeJoc[linia][coloana]=0;
                            x1=stanga+latura*(coloana-1);
                            y1=sus+latura*(linia-1);
                            x2=x1+latura;
                            y2=y1;
                            x3=x1;
                            y3=y1+latura;
                            x4=x2;
                            y4=y3;
                            int puncte[]= {x1, y1, x3, y3, x4, y4, x2, y2, x1, y1};
                            setcolor(BLUE);
                            rectangle(x1, y1, x3, y3);
                            setfillstyle(SOLID_FILL, FUNDAL);
                            fillpoly(5, puncte);
                            setfillstyle(LTSLASH_FILL, 1);
                            setcolor(BLUE);
                            circle((x1+x4)/2,(y1+y4)/2, 20);
                            fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                        }
                        else
                        {
                                if(vectorfrecventa[vm[k].Matrice_puncte[linia][coloana]]>0)
                                    culoareselectata=vm[k].Matrice_puncte[linia][coloana];
                                cerc_culoare(culoareselectata);

                        }
                    }
                }
            }
        }
    }
}
void punerePiesa_hard(int k)
{
    int x,y;
    int x1, x2, y1, y2, x3, y3, x4, y4, linia, coloana;
    c=culoare;
    if(m==0)
        inima(n, RED);
    if(m==5)
        gata=true;
    else
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(x>=70 && x<=230 && y>=170 && y<=230)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();

            }
            else if(x>=70 && x<=230 && y>=290 && y<=350)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_hard(0);

            }
            else if(x>=70 && x<=230 && y>=410 && y<=470)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                reguli_dificil();
            }
            else if(x>=70 && x<=230 && y>=530 && y<=590)
            {
                if(mute==1)
                {
                    mute=0;
                    setcolor(WHITE);
                    line(70, 560, 230, 560);
                }
                else
                {
                    mute=1;
                    setcolor(BLACK);
                    line(70, 560, 230, 560);
                    setcolor(WHITE);
                    arc(100, 560, 90, 270, 30);
                    line(100, 530, 200, 530);
                    line(100, 590, 200, 590);
                    arc(200, 560, 270, 90, 30);
                    setcolor(WHITE);
                    settextstyle(6, HORIZ_DIR, 3);
                    outtextxy(95, 550, "SUNET");
                }
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
            }
            else if(x>=70 && x<=230 && y>=650 && y<=710)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_joaca();
            }
            if(x>=1225&&x<=1275&&y>=150&&y<=800)
            {
                culoareselectata=culoaretabel(x,y);
                cerc_culoare(culoareselectata);
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
            else if (x>=stanga && x<=stanga+width && y>=sus&&y<=sus+height)
            {
                linia=(y-sus)/latura+1;
                coloana=(x-stanga)/latura+1;
                if (TablaDeJoc[linia][coloana]==0)
                {
                    nr++;
                    TablaDeJoc[linia][coloana]=culoareselectata;
                    if(vh[k].Matrice_puncte[linia][coloana]>=2&&vh[k].Matrice_puncte[linia][coloana]!=10)
                        {
                            if(culoareselectata==0)
                                TablaDeJoc[linia][coloana]=vh[k].Matrice_puncte[linia][coloana];
                                culoareselectata=vh[k].Matrice_puncte[linia][coloana];

                        }
                    scorminus(culoareselectata);
                    cerc_culoare(culoareselectata);
                    c=culoareselectata;
                    cout<<culoareselectata;
                    if(culoareselectata==c)
                    {
                        if(vh[k].Matrice_completa[linia][coloana]!=(c-1))
                        {
                            if(mute)
                                PlaySound(TEXT("error.wav"),NULL,SND_SYNC);
                            m++;
                            inima(n,BLACK);
                            inima(n-m,RED);
                        }
                        else if(mute)
                            PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                    }
                    if(culoareselectata)
                    {
                        setcolor(BLACK);
                        x1=stanga+latura*(coloana-1);
                        y1=sus+latura*(linia-1);
                        x2=x1+latura;
                        y2=y1;
                        x3=x1;
                        y3=y1+latura;
                        x4=x2;
                        y4=y3;
                        int puncte[]= {x1, y1, x3, y3, x4, y4, x2, y2, x1, y1};
                        setfillstyle(SOLID_FILL, culoareselectata);
                        fillpoly(5, puncte);

                    if(vh[k].Matrice_puncte[linia][coloana]>=2&&vh[k].Matrice_puncte[linia][coloana]!=10)
                    {
                        setfillstyle(SOLID_FILL, BLACK);
                        circle((x1+x4)/2,(y1+y4)/2, 20);
                        fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                    }
                    else if(vh[k].Matrice_puncte[linia][coloana]==1)
                    {
                        setfillstyle(LTSLASH_FILL, 14);
                        setcolor(BLACK);
                        circle((x1+x4)/2,(y1+y4)/2, 20);
                        fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                    }
                    else if(vh[k].Matrice_puncte[linia][coloana]==10)
                    {
                        setfillstyle(XHATCH_FILL, 14);
                        setcolor(BLACK);
                        circle((x1+x4)/2,(y1+y4)/2, 20);
                        fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                    }}
                }
                else
                {
                    if(vh[k].Matrice_puncte[linia][coloana]==0)
                    {
                        scorplus(TablaDeJoc[linia][coloana]);
                        if(mute)
                            PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                        nr--;
                        setcolor(BLACK);
                        TablaDeJoc[linia][coloana]=0;
                        x1=stanga+latura*(coloana-1);
                        y1=sus+latura*(linia-1);
                        x2=x1+latura;
                        y2=y1;
                        x3=x1;
                        y3=y1+latura;
                        x4=x2;
                        y4=y3;
                        int puncte[]= {x1, y1, x3, y3, x4, y4, x2, y2, x1, y1};
                        setcolor(BLUE);
                        rectangle(x1, y1, x3, y3);
                        setfillstyle(SOLID_FILL, FUNDAL);
                        fillpoly(5, puncte);
                    }
                    else
                    {
                        if(vh[k].Matrice_puncte[linia][coloana]==1 || vh[k].Matrice_puncte[linia][coloana]==10)
                        {
                            scorplus(TablaDeJoc[linia][coloana]);
                            nr--;
                            setcolor(BLACK);
                            TablaDeJoc[linia][coloana]=0;
                            x1=stanga+latura*(coloana-1);
                            y1=sus+latura*(linia-1);
                            x2=x1+latura;
                            y2=y1;
                            x3=x1;
                            y3=y1+latura;
                            x4=x2;
                            y4=y3;
                            int puncte[]= {x1, y1, x3, y3, x4, y4, x2, y2, x1, y1};
                            setcolor(BLUE);
                            rectangle(x1, y1, x3, y3);
                            setfillstyle(SOLID_FILL, FUNDAL);
                            fillpoly(5, puncte);
                            if(vh[k].Matrice_puncte[linia][coloana]==1 )
                            {
                                setfillstyle(LTSLASH_FILL, 1);
                                setcolor(BLUE);
                                circle((x1+x4)/2,(y1+y4)/2, 20);
                                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                            }
                            else
                            {
                                setfillstyle(XHATCH_FILL, 1);
                                setcolor(BLUE);
                                circle((x1+x4)/2,(y1+y4)/2, 20);
                                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                            }
                        }
                        else
                        {
                            if(vectorfrecventa[vh[k].Matrice_puncte[linia][coloana]]>0)
                                culoareselectata=vh[k].Matrice_puncte[linia][coloana];
                            cerc_culoare(culoareselectata);
                        }
                    }
                }
            }
        }
    }
}

void punerePiesa_mediu2(int k)
{
    int x,y;
    int x1, x2, y1, y2, x3, y3, x4, y4, linia, coloana;
    c=culoare;
    if(m==0)
        inima(n, RED);
    if(m==5)
        gata=true;
    else
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(x>=70 && x<=230 && y>=170 && y<=230)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_4();

            }
            else if(x>=70 && x<=230 && y>=290 && y<=350)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium2(0);

            }
            else if(x>=70 && x<=230 && y>=410 && y<=470)
            {
                if(mute==1)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                exemplu();
            }
            else if(x>=70 && x<=230 && y>=530 && y<=590)
            {
                if(mute==1)
                {
                    mute=0;
                    setcolor(WHITE);
                    line(70, 560, 230, 560);
                }
                else
                {
                    mute=1;
                    setcolor(BLACK);
                    line(70, 560, 230, 560);
                    setcolor(WHITE);
                    arc(100, 560, 90, 270, 30);
                    line(100, 530, 200, 530);
                    line(100, 590, 200, 590);
                    arc(200, 560, 270, 90, 30);
                    setcolor(WHITE);
                    settextstyle(6, HORIZ_DIR, 3);
                    outtextxy(95, 550, "SUNET");
                }
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
            }
            else if(x>=70 && x<=230 && y>=650 && y<=710)
            {
                if(mute)
                    PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_4();
            }
            if(x>=1225&&x<=1275&&y>=300&&y<=575)
            {
                culoareselectata=culoaretabel1(x,y);
                cerc_culoare(culoareselectata);
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
            else if (x>=stanga && x<=stanga+width && y>=sus&&y<=sus+height)
            {
                linia=(y-sus)/latura+1;
                coloana=(x-stanga)/latura+1;
                if (TablaDeJoc[linia][coloana]==0)
                {
                    nr++;
                    TablaDeJoc[linia][coloana]=culoareselectata;
                    if(vm2[k].Matrice_puncte[linia][coloana]>=2)
                        {
                            if(culoareselectata==0)
                                TablaDeJoc[linia][coloana]=vm2[k].Matrice_puncte[linia][coloana];
                                culoareselectata=vm2[k].Matrice_puncte[linia][coloana];

                        }
                    scorminus1(culoareselectata);
                    cerc_culoare(culoareselectata);
                    c=culoareselectata;
                    cout<<culoareselectata;
                    if(culoareselectata==c)
                    {
                        if(vm2[k].Matrice_completa[linia][coloana]!=(c-1))
                        {
                            if(mute)
                                PlaySound(TEXT("error.wav"),NULL,SND_SYNC);
                            m++;
                            inima(n,BLACK);
                            inima(n-m,RED);
                        }
                        else if(mute)
                            PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                    }
                    if(culoareselectata)
                    {
                        setcolor(BLACK);
                        x1=stanga+latura*(coloana-1);
                        y1=sus+latura*(linia-1);
                        x2=x1+latura;
                        y2=y1;
                        x3=x1;
                        y3=y1+latura;
                        x4=x2;
                        y4=y3;
                        int puncte[]= {x1, y1, x3, y3, x4, y4, x2, y2, x1, y1};
                        setfillstyle(SOLID_FILL, culoareselectata);
                        fillpoly(5, puncte);

                    if(vm2[k].Matrice_puncte[linia][coloana]>=2)
                    {
                        setfillstyle(SOLID_FILL, BLACK);
                        circle((x1+x4)/2,(y1+y4)/2, 20);
                        fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                    }
                    else if(vm2[k].Matrice_puncte[linia][coloana]==1)
                    {
                        setfillstyle(LTSLASH_FILL, 14);
                        setcolor(BLACK);
                        circle((x1+x4)/2,(y1+y4)/2, 20);
                        fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                    }}
                }
                else
                {
                    if(vm2[k].Matrice_puncte[linia][coloana]==0)
                    {
                        scorplus1(TablaDeJoc[linia][coloana]);
                        if(mute)
                            PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                        nr--;
                        setcolor(BLACK);
                        TablaDeJoc[linia][coloana]=0;
                        x1=stanga+latura*(coloana-1);
                        y1=sus+latura*(linia-1);
                        x2=x1+latura;
                        y2=y1;
                        x3=x1;
                        y3=y1+latura;
                        x4=x2;
                        y4=y3;
                        int puncte[]= {x1, y1, x3, y3, x4, y4, x2, y2, x1, y1};
                        setcolor(BLUE);
                        rectangle(x1, y1, x3, y3);
                        setfillstyle(SOLID_FILL, FUNDAL);
                        fillpoly(5, puncte);
                    }
                    else
                    {
                        if(vm2[k].Matrice_puncte[linia][coloana]==1)
                        {
                            scorplus1(TablaDeJoc[linia][coloana]);
                            nr--;
                            setcolor(BLACK);
                            TablaDeJoc[linia][coloana]=0;
                            x1=stanga+latura*(coloana-1);
                            y1=sus+latura*(linia-1);
                            x2=x1+latura;
                            y2=y1;
                            x3=x1;
                            y3=y1+latura;
                            x4=x2;
                            y4=y3;
                            int puncte[]= {x1, y1, x3, y3, x4, y4, x2, y2, x1, y1};
                            setcolor(BLUE);
                            rectangle(x1, y1, x3, y3);
                            setfillstyle(SOLID_FILL, FUNDAL);
                            fillpoly(5, puncte);
                            setfillstyle(LTSLASH_FILL, 1);
                            setcolor(BLUE);
                            circle((x1+x4)/2,(y1+y4)/2, 20);
                            fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                        }
                        else
                        {
                            {
                                if(vectorfrecventa[vm2[k].Matrice_puncte[linia][coloana]]>0)
                                    culoareselectata=vm2[k].Matrice_puncte[linia][coloana];
                            }
                            cerc_culoare(culoareselectata);
                        }
                    }
                }
            }
        }
    }
}
void final_easy(int retry)
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("c.jpg",640,150,870,300);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(250, 90, "NE PARE RAU! ATI PIERDUT!");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    pieslice(450, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(250, 500, 50, 50);
    fillellipse(450, 500, 50, 50);
    int puncte1[]= {250, 450, 250, 550, 450, 550, 450, 450, 250, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte1);
    setcolor(WHITE);
    arc(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    arc(450, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(230, 480, "DIN NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    pieslice(850, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(650, 500, 50, 50);
    int puncte2[]= {650, 450, 650, 550, 850, 550, 850, 450, 650, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    arc(850, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(630, 480, "JOC NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    pieslice(1250, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(1050, 500, 50, 50);
    int puncte3[]= {1050, 450, 1050, 550, 1250, 550, 1250, 450, 1050, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte3);
    setcolor(WHITE);
    arc(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    arc(1250, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(1060, 480, "MENIU");

    if(mute)
        PlaySound(TEXT("gameover.wav"),NULL,SND_SYNC);

    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            //if(mute)

            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=200 && x<=500 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_easy(retry);
                retry=0;
                ok=0;
            }
            else if(x>=600 && x<=900 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_easy(0);
                ok=0;
            }
            else if(x>=1000 && x<=1300 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
        }
    }
}


void final_medium(int retry)
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("c.jpg",640,150,870,300);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(250, 90, "NE PARE RAU! ATI PIERDUT!");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    pieslice(450, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(250, 500, 50, 50);
    fillellipse(450, 500, 50, 50);
    int puncte1[]= {250, 450, 250, 550, 450, 550, 450, 450, 250, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte1);
    setcolor(WHITE);
    arc(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    arc(450, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(230, 480, "DIN NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    pieslice(850, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(650, 500, 50, 50);
    int puncte2[]= {650, 450, 650, 550, 850, 550, 850, 450, 650, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    arc(850, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(630, 480, "JOC NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    pieslice(1250, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(1050, 500, 50, 50);
    int puncte3[]= {1050, 450, 1050, 550, 1250, 550, 1250, 450, 1050, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte3);
    setcolor(WHITE);
    arc(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    arc(1250, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(1060, 480, "MENIU");

    if(mute)
        PlaySound(TEXT("gameover.wav"),NULL,SND_SYNC);

    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            //if(mute)

            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=200 && x<=500 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium(retry);
                retry=0;
                ok=0;
            }
            else if(x>=600 && x<=900 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium(0);
                ok=0;
            }
            else if(x>=1000 && x<=1300 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
        }
    }
}

void final_hard(int retry)
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("c.jpg",640,150,870,300);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(250, 90, "NE PARE RAU! ATI PIERDUT!");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    pieslice(450, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(250, 500, 50, 50);
    fillellipse(450, 500, 50, 50);
    int puncte1[]= {250, 450, 250, 550, 450, 550, 450, 450, 250, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte1);
    setcolor(WHITE);
    arc(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    arc(450, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(230, 480, "DIN NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    pieslice(850, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(650, 500, 50, 50);
    int puncte2[]= {650, 450, 650, 550, 850, 550, 850, 450, 650, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    arc(850, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(630, 480, "JOC NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    pieslice(1250, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(1050, 500, 50, 50);
    int puncte3[]= {1050, 450, 1050, 550, 1250, 550, 1250, 450, 1050, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte3);
    setcolor(WHITE);
    arc(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    arc(1250, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(1060, 480, "MENIU");

    if(mute)
        PlaySound(TEXT("gameover.wav"),NULL,SND_SYNC);

    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=200 && x<=500 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_hard(retry);
                retry=0;
                ok=0;
            }
            else if(x>=600 && x<=900 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_hard(0);
                ok=0;
            }
            else if(x>=1000 && x<=1300 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
        }
    }
}

void final_medium2(int retry)
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("c.jpg",640,150,870,300);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(250, 90, "NE PARE RAU! ATI PIERDUT!");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    pieslice(450, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(250, 500, 50, 50);
    fillellipse(450, 500, 50, 50);
    int puncte1[]= {250, 450, 250, 550, 450, 550, 450, 450, 250, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte1);
    setcolor(WHITE);
    arc(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    arc(450, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(230, 480, "DIN NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    pieslice(850, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(650, 500, 50, 50);
    int puncte2[]= {650, 450, 650, 550, 850, 550, 850, 450, 650, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    arc(850, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(630, 480, "JOC NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    pieslice(1250, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(1050, 500, 50, 50);
    int puncte3[]= {1050, 450, 1050, 550, 1250, 550, 1250, 450, 1050, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte3);
    setcolor(WHITE);
    arc(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    arc(1250, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(1060, 480, "MENIU");

    if(mute)
        PlaySound(TEXT("gameover.wav"),NULL,SND_SYNC);

    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            //if(mute)

            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=200 && x<=500 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium2(retry);
                retry=0;
                ok=0;
            }
            else if(x>=600 && x<=900 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium2(0);
                ok=0;
            }
            else if(x>=1000 && x<=1300 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_4();
                ok=0;
            }
        }
    }
}

void final_castigator_easy(int retry)
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("5.jpg",0,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(250, 90, "FELICITARI! ATI CASTIGAT!");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    pieslice(450, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(250, 500, 50, 50);
    fillellipse(450, 500, 50, 50);
    int puncte1[]= {250, 450, 250, 550, 450, 550, 450, 450, 250, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte1);
    setcolor(WHITE);
    arc(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    arc(450, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(230, 480, "DIN NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    pieslice(850, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(650, 500, 50, 50);
    int puncte2[]= {650, 450, 650, 550, 850, 550, 850, 450, 650, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    arc(850, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(630, 480, "JOC NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    pieslice(1250, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(1050, 500, 50, 50);
    int puncte3[]= {1050, 450, 1050, 550, 1250, 550, 1250, 450, 1050, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte3);
    setcolor(WHITE);
    arc(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    arc(1250, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(1060, 480, "MENIU");

    if(mute)
        PlaySound(TEXT("winning.wav"),NULL,SND_SYNC);

    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=200 && x<=500 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_easy(retry);
                retry=0;
                ok=0;
            }
            else if(x>=600 && x<=900 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_easy(0);
                ok=0;
            }
            else if(x>=1000 && x<=1300 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
        }
    }

}

void final_castigator_medium(int retry)
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("5.jpg",0,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(250, 90, "FELICITARI! ATI CASTIGAT!");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    pieslice(450, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(250, 500, 50, 50);
    fillellipse(450, 500, 50, 50);
    int puncte1[]= {250, 450, 250, 550, 450, 550, 450, 450, 250, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte1);
    setcolor(WHITE);
    arc(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    arc(450, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(230, 480, "DIN NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    pieslice(850, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(650, 500, 50, 50);
    int puncte2[]= {650, 450, 650, 550, 850, 550, 850, 450, 650, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    arc(850, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(630, 480, "JOC NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    pieslice(1250, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(1050, 500, 50, 50);
    int puncte3[]= {1050, 450, 1050, 550, 1250, 550, 1250, 450, 1050, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte3);
    setcolor(WHITE);
    arc(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    arc(1250, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(1060, 480, "MENIU");

    if(mute)
        PlaySound(TEXT("winning.wav"),NULL,SND_SYNC);

    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=200 && x<=500 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium(retry);
                retry=0;
                ok=0;
            }
            else if(x>=600 && x<=900 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium(0);
                ok=0;
            }
            else if(x>=1000 && x<=1300 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
        }
    }

}

void final_castigator_hard(int retry)
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("5.jpg",0,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(250, 90, "FELICITARI! ATI CASTIGAT!");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    pieslice(450, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(250, 500, 50, 50);
    fillellipse(450, 500, 50, 50);
    int puncte1[]= {250, 450, 250, 550, 450, 550, 450, 450, 250, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte1);
    setcolor(WHITE);
    arc(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    arc(450, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(230, 480, "DIN NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    pieslice(850, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(650, 500, 50, 50);
    int puncte2[]= {650, 450, 650, 550, 850, 550, 850, 450, 650, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    arc(850, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(630, 480, "JOC NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    pieslice(1250, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(1050, 500, 50, 50);
    int puncte3[]= {1050, 450, 1050, 550, 1250, 550, 1250, 450, 1050, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte3);
    setcolor(WHITE);
    arc(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    arc(1250, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(1060, 480, "MENIU");

    if(mute)
        PlaySound(TEXT("winning.wav"),NULL,SND_SYNC);

    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=200 && x<=500 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_hard(retry);
                retry=0;
                ok=0;
            }
            else if(x>=600 && x<=900 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_hard(0);
                ok=0;
            }
            else if(x>=1000 && x<=1300 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
        }
    }

}

void final_castigator_medium2(int retry)
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("5.jpg",0,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(250, 90, "FELICITARI! ATI CASTIGAT!");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    pieslice(450, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(250, 500, 50, 50);
    fillellipse(450, 500, 50, 50);
    int puncte1[]= {250, 450, 250, 550, 450, 550, 450, 450, 250, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte1);
    setcolor(WHITE);
    arc(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    arc(450, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(230, 480, "DIN NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    pieslice(850, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(650, 500, 50, 50);
    int puncte2[]= {650, 450, 650, 550, 850, 550, 850, 450, 650, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    arc(850, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(630, 480, "JOC NOU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    pieslice(1250, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(1050, 500, 50, 50);
    int puncte3[]= {1050, 450, 1050, 550, 1250, 550, 1250, 450, 1050, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte3);
    setcolor(WHITE);
    arc(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    arc(1250, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(1060, 480, "MENIU");

    if(mute)
        PlaySound(TEXT("winning.wav"),NULL,SND_SYNC);

    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=200 && x<=500 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium2(retry);
                retry=0;
                ok=0;
            }
            else if(x>=600 && x<=900 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium2(0);
                ok=0;
            }
            else if(x>=1000 && x<=1300 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_4();
                ok=0;
            }
        }
    }

}

void joc_easy(int retry)
{
    culoareselectata=0;
    nr=0;
    m=0;
    n=5;
    c=0;
    ok=1;
    mute=1;
    int k;
    if(retry==0)
        k=rand()%9+1;
    else
    {
        k=retry;
        retry=0;
    }
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            TablaDeJoc[i][j]=0;
    readimagefile("c.jpg",0,0,1536,864);
    desen();
    tabelav();
    tabela();
    setcolor(DARKGRAY);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
    outtextxy(500, 50, "Selectati culoarea!");
    setcolor(BLACK);

    casuta();

    colorare_puncte_easy(k);
    afiseazaE(k);
    gata=false;
    castigator=false;
    do
    {
        punerePiesa_easy(k);
        if(nr==64)
        {
            gata=true;
            castigator=true;
        }

    }
    while (!gata);
    if(!castigator)
        final_easy(k);
    else
        final_castigator_easy(k);

}

void joc_medium(int retry)
{
    culoareselectata=0;
    nr=0;
    m=0;
    n=5;
    c=0;
    ok=1;
    mute=1;
    int k;
    if(retry==0)
        k=rand()%25+1;
    else
    {
        k=retry;
        retry=0;
    }
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            TablaDeJoc[i][j]=0;
    desen();
    tabelav();
    tabela();
    setcolor(DARKGRAY);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
    outtextxy(500, 50, "Selectati culoarea!");
    setcolor(BLACK);
    colorare_puncte_medium(k);
    desenare_puncte_medium(k);
    casuta();
    afiseazaM(k);
    gata=false;
    castigator=false;
    do
    {
        punerePiesa_mediu(k);
        if(nr==64)
        {
            gata=true;
            castigator=true;
        }
    }
    while (!gata);
    if(!castigator)
        final_medium(k);
    else
        final_castigator_medium(k);
}

void joc_hard(int retry)
{
    culoareselectata=0;
    nr=0;
    m=0;
    n=5;
    c=0;
    ok=1;
    mute=1;
    int k;
    if(retry==0)
        k=rand()%8+1;
    else
    {
        k=retry;
        retry=0;
    }
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            TablaDeJoc[i][j]=0;
    desen();
    tabelav();
    tabela();
    setcolor(DARKGRAY);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
    outtextxy(500, 50, "Selectati culoarea!");
    setcolor(BLACK);
    colorare_puncte_hard(k);
    desenare_puncte_hard(k);
    casuta();
    afiseazaH(k);
    gata=false;
    castigator=false;
    do
    {
        punerePiesa_hard(k);
        if(nr==64)
        {
            gata=true;
            castigator=true;
        }
    }
    while (!gata);
    if(!castigator)
        final_hard(k);
    else
        final_castigator_hard(k);
}
void joc_medium2(int retry)
{
    culoareselectata=0;
    nr=0;
    m=0;
    n=5;
    c=0;
    ok=1;
    mute=1;
    int k;
    if(retry==0)
        k=rand()%20+1;
    else
        k=retry;
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            TablaDeJoc[i][j]=0;
    readimagefile("c.jpg",0,0,1536,864);
    desen();
    tabelav1();
    tabela1();
    setcolor(DARKGRAY);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
    outtextxy(500, 50, "Selectati culoarea!");
    setcolor(BLACK);
    colorare_puncte_medium2(k);
    desenare_puncte_medium2(k);
    casuta();
    afiseazaM2(k);
    gata=false;
    castigator=false;
    do
    {
        punerePiesa_mediu2(k);
        if(nr==64)
        {
            gata=true;
            castigator=true;
        }

    }
    while (!gata);
    if(!castigator)
        final_medium2(k);
    else
        final_castigator_medium2(k);

}
void inapoi();
void meniu();

void meniu_joaca()
{
    int x,y,ok=1;
    cleardevice();
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    readimagefile("b.jpg",0,0,1536,864);
    outtextxy(30, 90, "JOACA - ALEGE DIFICULTATEA");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(120, 280, "USOR");
    setlinestyle(0, 0, 2);
    arc(100, 300, 90, 270, 50);
    line(100,250, 300, 250);
    line(100, 350, 300, 350);
    arc(300, 300, 270, 90, 50);

    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(105, 480, "MEDIU");
    setlinestyle(0, 0, 2);
    arc(100, 500, 90, 270, 50);
    line(100,450, 300, 450);
    line(100, 550, 300, 550);
    arc(300, 500, 270, 90, 50);

    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(100, 680, "DIFICIL");
    setlinestyle(0, 0, 2);
    arc(100, 700, 90, 270, 50);
    line(100,650, 300, 650);
    line(100, 750, 300, 750);
    arc(300, 700, 270, 90, 50);
    inapoi();
    casuta();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            //if(mute)

            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            cout<<x<<" "<<y<<" ";

            if(x>=50 && x<=350 && y>=250 && y<=350)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_easy(0);
                ok=0;
            }
            else if(x>=50 && x<=350 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium(0);
                ok=0;
            }
            else if(x>=50 && x<=350 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_hard(0);
                ok=0;
            }
            else if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void exitgame()
{
    int x,y;
    initwindow(500,300,"MULTUMIM!",500,300);//ultimele 2 valori; 800,300 coordonatele coltului stanga sus, stanga ta
    readimagefile("1.jpg",0,0, 500, 300);
    setcolor(DARKGRAY);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(30, 50, "Va multumim !");
    PlaySound(TEXT("exit.wav"),NULL,SND_SYNC);
    exit(0);
}
void meniu();
void pasul1_8();
void pasul1_4();
void meniu_8();
void meniu_4();

void meniu_principal()
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("6.jpg",0,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "IMPARTIREA PE CADRANE");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(100, 300, 90, 270, 50);
    line(100,250, 300, 250);
    line(100, 350, 300, 350);
    pieslice(300, 300, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(100, 300, 50, 50);
    fillellipse(300, 300, 50, 50);
    int puncte[]= {100, 250, 100, 350, 300, 350, 300, 250, 100, 250};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte);
    setcolor(WHITE);
    arc(100, 300, 90, 270, 50);
    line(100,250, 300, 250);
    line(100, 350, 300, 350);
    arc(300, 300, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(125, 280, "JOC 1");


    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(100, 500, 90, 270, 50);
    line(100,450, 300, 450);
    line(100, 550, 300, 550);
    pieslice(300, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(100, 500, 50, 50);
    int puncte1[]= {100, 450, 100, 550, 300, 550, 300, 450, 100, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte1);
    setcolor(WHITE);
    arc(100, 500, 90, 270, 50);
    line(100,450, 300, 450);
    line(100, 550, 300, 550);
    arc(300, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(125, 480, "JOC 2");


    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(100, 700, 90, 270, 50);
    line(100,650, 300, 650);
    line(100, 750, 300, 750);
    pieslice(300, 700, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(100, 700, 50, 50);
    fillellipse(300, 700, 50, 50);
    int puncte2[]= {100, 650, 100, 750, 300, 750, 300, 650, 100, 650};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(100, 700, 90, 270, 50);
    line(100,650, 300, 650);
    line(100, 750, 300, 750);
    arc(300, 700, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(105, 680, "IESIRE");
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            cout<<x<<" "<<y<<" ";

            if(x>=50 && x<=350 && y>=250 && y<=350)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
            else if(x>=50 && x<=350 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_4();
                ok=0;
            }
            else if(x>=50 && x<=350 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                exitgame();
                ok=0;
            }
        }
    }

}

void meniu_8()
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("a.jpg",0,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "IMPARTIREA PE 8 CADRANE");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(100, 300, 90, 270, 50);
    line(100,250, 300, 250);
    line(100, 350, 300, 350);
    pieslice(300, 300, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(100, 300, 50, 50);
    fillellipse(300, 300, 50, 50);
    int puncte[]= {100, 250, 100, 350, 300, 350, 300, 250, 100, 250};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte);
    setcolor(WHITE);
    arc(100, 300, 90, 270, 50);
    line(100,250, 300, 250);
    line(100, 350, 300, 350);
    arc(300, 300, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(100, 280, "JOACA");


    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(100, 500, 90, 270, 50);
    line(100,450, 300, 450);
    line(100, 550, 300, 550);
    pieslice(300, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(100, 500, 50, 50);
    int puncte1[]= {100, 450, 100, 550, 300, 550, 300, 450, 100, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte1);
    setcolor(WHITE);
    arc(100, 500, 90, 270, 50);
    line(100,450, 300, 450);
    line(100, 550, 300, 550);
    arc(300, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(95, 480, "REGULI");


    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(100, 700, 90, 270, 50);
    line(100,650, 300, 650);
    line(100, 750, 300, 750);
    pieslice(300, 700, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(100, 700, 50, 50);
    fillellipse(300, 700, 50, 50);
    int puncte2[]= {100, 650, 100, 750, 300, 750, 300, 650, 100, 650};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(100, 700, 90, 270, 50);
    line(100,650, 300, 650);
    line(100, 750, 300, 750);
    arc(300, 700, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(105, 680, "INAPOI");
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            cout<<x<<" "<<y<<" ";

            if(x>=50 && x<=350 && y>=250 && y<=350)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_joaca();
                ok=0;
            }
            else if(x>=50 && x<=350 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul1_8();
                ok=0;
            }
            else if(x>=50 && x<=350 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }

}

void meniu_4()
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("a.jpg",0,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "IMPARTIREA PE 4 CADRANE");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();
    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(100, 300, 90, 270, 50);
    line(100,250, 300, 250);
    line(100, 350, 300, 350);
    pieslice(300, 300, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(100, 300, 50, 50);
    fillellipse(300, 300, 50, 50);
    int puncte[]= {100, 250, 100, 350, 300, 350, 300, 250, 100, 250};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte);
    setcolor(WHITE);
    arc(100, 300, 90, 270, 50);
    line(100,250, 300, 250);
    line(100, 350, 300, 350);
    arc(300, 300, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(100, 280, "JOACA");


    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(100, 500, 90, 270, 50);
    line(100,450, 300, 450);
    line(100, 550, 300, 550);
    pieslice(300, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(100, 500, 50, 50);
    int puncte1[]= {100, 450, 100, 550, 300, 550, 300, 450, 100, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte1);
    setcolor(WHITE);
    arc(100, 500, 90, 270, 50);
    line(100,450, 300, 450);
    line(100, 550, 300, 550);
    arc(300, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(95, 480, "REGULI");


    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(100, 700, 90, 270, 50);
    line(100,650, 300, 650);
    line(100, 750, 300, 750);
    pieslice(300, 700, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(100, 700, 50, 50);
    fillellipse(300, 700, 50, 50);
    int puncte2[]= {100, 650, 100, 750, 300, 750, 300, 650, 100, 650};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(100, 700, 90, 270, 50);
    line(100,650, 300, 650);
    line(100, 750, 300, 750);
    arc(300, 700, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(105, 680, "INAPOI");
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            cout<<x<<" "<<y<<" ";

            if(x>=50 && x<=350 && y>=250 && y<=350)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium2(0);
                ok=0;
            }
            else if(x>=50 && x<=350 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul1_4();
                ok=0;
            }
            else if(x>=50 && x<=350 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }

}


void inapoi()
{
    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(1200, 700, 90, 270, 50);
    line(1200,650, 1400, 650);
    line(1200, 750, 1400, 750);
    pieslice(1400, 700, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(1200, 700, 50, 50);
    fillellipse(1400, 700, 50, 50);
    int puncte3[]= {1200, 650, 1200, 750, 1400, 750, 1400, 650, 1200, 650};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte3);
    setcolor(WHITE);
    arc(1200, 700, 90, 270, 50);
    line(1200,650, 1400, 650);
    line(1200, 750, 1400, 750);
    arc(1400, 700, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(1200, 680, "INAPOI");
}

void mini_meniu()
{
    setcolor(WHITE);
    arc(100, 200, 90, 270, 30);
    line(100, 170, 200, 170);
    line(100, 230, 200, 230);
    arc(200, 200, 270, 90, 30);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 3);
    outtextxy(97, 189, "MENIU");

    setcolor(WHITE);
    arc(100, 320, 90, 270, 30);
    line(100, 290, 200, 290);
    line(100, 350, 200, 350);
    arc(200, 320, 270, 90, 30);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 3);
    outtextxy(80, 310, "JOC NOU");

    setcolor(WHITE);
    arc(100, 440, 90, 270, 30);
    line(100, 410, 200, 410);
    line(100, 470, 200, 470);
    arc(200, 440, 270, 90, 30);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 3);
    outtextxy(90, 430, "REGULI");

    setcolor(WHITE);
    arc(100, 560, 90, 270, 30);
    line(100, 530, 200, 530);
    line(100, 590, 200, 590);
    arc(200, 560, 270, 90, 30);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 3);
    outtextxy(95, 550, "SUNET");

    setcolor(WHITE);
    arc(100, 680, 90, 270, 30);
    line(100, 650, 200, 650);
    line(100, 710, 200, 710);
    arc(200, 680, 270, 90, 30);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 3);
    outtextxy(100, 670, "INAPOI");
}

void pasul2_8();
void pasul3_8();
void pasul4_8();
void pasul5_8();
void pasul2_4();
void pasul3_4();
void pasul4_4();
void pasul5_4();

void sageata_urm()
{
    setcolor(WHITE);
    line(1350, 500, 1420, 500);
    line(1350, 470, 1420, 470);
    line(1420, 470, 1420, 450);
    line(1420, 500, 1420, 520);
    line(1420, 450, 1470, 485);
    line(1420, 520, 1470, 485);
    settextstyle(6, HORIZ_DIR, 2);
    outtextxy(1350, 475, "URM.");
}

void sageata_ant()
{
    setcolor(WHITE);
    line(70, 500, 140, 500);
    line(70, 470, 140, 470);
    line(70, 470, 70, 450);
    line(70, 500, 70, 520);
    line(70, 450, 20, 485);
    line(70, 520, 20, 485);
    settextstyle(6, HORIZ_DIR, 2);
    outtextxy(70, 475, "ANT.");
}

void meniu_buton()
{
    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(1200, 700, 90, 270, 50);
    line(1200,650, 1400, 650);
    line(1200, 750, 1400, 750);
    pieslice(1400, 700, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(1200, 700, 50, 50);
    fillellipse(1400, 700, 50, 50);
    int puncte3[]= {1200, 650, 1200, 750, 1400, 750, 1400, 650, 1200, 650};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte3);
    setcolor(WHITE);
    arc(1200, 700, 90, 270, 50);
    line(1200,650, 1400, 650);
    line(1200, 750, 1400, 750);
    arc(1400, 700, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(1200, 680, "MENIU");
}

void pasul1_8()
{
    int x, y,ok=1;
    cleardevice();
    readimagefile("8.jpg",0,0,1000,856);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 1");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(100, 450, "Selectati culoarea");

    line(550, 474, 580, 474);
    line(580, 474, 565, 464);
    line(580, 474, 565, 484);

    int culoarescor=2;
    setcolor(BLACK);
    int xc=200;
    for(int i=2; i<=9; i++)
    {
        setfillstyle(SOLID_FILL, culoarescor++);
        setcolor(BLACK);
        circle(700, xc, 26);
        fillellipse(700, xc, 25, 26);
        xc+=75;
    }

    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(800, 450, "SAU");

    int i,j;
    int x1, y1, x4, y4;
    latura=70;
    int color=2;
    for (i=1; i<=4; i++)
        for (j=1; j<=2; j++)
        {
            setcolor(BLUE);
            rectangle(1000+latura*(i-1),400+ latura*(j-1),1000+latura*i,400+latura*j);
            x1=1000+latura*(i-1);
            y1=400+latura*(j-1);
            x4=1000+latura*i;
            y4=400+latura*j;
            setcolor(BLACK);
            setfillstyle(SOLID_FILL, color++);
            circle((x1+x4)/2,(y1+y4)/2, 20);
            fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
        }
    sageata_urm();
    meniu_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
            else if(x>=1350 && x<=1470 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul2_8();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void pasul2_8()
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("2.jpg",100,400,1500,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 2");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(300, 200, "Incepeti prin a selecta patratul cu bila");
    outtextxy(370, 300, "de culoarea aleasa, colorandu-l.");

    setcolor(BLUE);
    rectangle(550, 450, 620, 520);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, 2);
    circle(585,485, 20);
    fillellipse(585,485, 20, 20);

    setcolor(WHITE);
    line(700, 485, 730, 485);
    line(730, 485, 715, 475);
    line(730, 485, 715, 495);

    rectangle(780, 450, 850, 520);
    setcolor(BLACK);
    int puncte[]= {780, 450, 780, 520, 850, 520, 850, 450, 780, 450};
    setfillstyle(SOLID_FILL, 2);
    fillpoly(5, puncte);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(815, 485, 20);
    fillellipse(815,485, 20, 20);

    sageata_ant();

    sageata_urm();

    meniu_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
            else if(x>=1350 && x<=1470 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul3_8();
                ok=0;
            }
            else if(x>=20 && x<=140 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul1_8();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void pasul3_8()
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("4.jpg",400,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 3");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(150, 200, "Scopul jocului este sa formati 8 cadrane continui");
    outtextxy(230, 300, "de cate 8 patratele, in care sa se afle cate o bila");
    outtextxy(300, 400, "de fiecare fel, pentru fiecare culoare");

    sageata_ant();
    sageata_urm();

    meniu_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
            else if(x>=1350 && x<=1470 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul4_8();
                ok=0;
            }
            else if(x>=20 && x<=140 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul2_8();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void reguli_usor();
void reguli_mediu();
void reguli_dificil();

void pasul4_8()
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("5.jpg",0,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 4");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(350, 200, "Cadranul trebuie sa fie format ");
    outtextxy(430, 300, "din 8 patratele adiacente");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    pieslice(450, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(250, 500, 50, 50);
    int puncte1[]= {250, 450, 250, 550, 450, 550, 450, 450, 250, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte1);
    setcolor(WHITE);
    arc(250, 500, 90, 270, 50);
    line(250,450, 450, 450);
    line(250, 550, 450, 550);
    arc(450, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(265, 480, "USOR");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    pieslice(850, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(650, 500, 50, 50);
    int puncte2[]= {650, 450, 650, 550, 850, 550, 850, 450, 650, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    arc(850, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(655, 480, "MEDIU");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    pieslice(1250, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(1050, 500, 50, 50);
    int puncte3[]= {1050, 450, 1050, 550, 1250, 550, 1250, 450, 1050, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte3);
    setcolor(WHITE);
    arc(1050, 500, 90, 270, 50);
    line(1050,450, 1250, 450);
    line(1050, 550, 1250, 550);
    arc(1250, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(1045, 480, "DIFICIL");

    sageata_ant();
    sageata_urm();

    meniu_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
            else if(x>=1350 && x<=1470 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul5_8();
                ok=0;
            }
            else if(x>=200 && x<=500 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                reguli_usor();
                ok=0;
            }
            else if(x>=600 && x<=900 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                reguli_mediu();
                ok=0;
            }
            else if(x>=1000 && x<=1300 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                reguli_dificil();
                ok=0;
            }
            else if(x>=20 && x<=140 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul3_8();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void pasul4_buton()
{
    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(1200, 700, 90, 270, 50);
    line(1200,650, 1400, 650);
    line(1200, 750, 1400, 750);
    pieslice(1400, 700, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(1200, 700, 50, 50);
    fillellipse(1400, 700, 50, 50);
    int puncte3[]= {1200, 650, 1200, 750, 1400, 750, 1400, 650, 1200, 650};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte3);
    setcolor(WHITE);
    arc(1200, 700, 90, 270, 50);
    line(1200,650, 1400, 650);
    line(1200, 750, 1400, 750);
    arc(1400, 700, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(1190, 680, "PASUL 4");
}

void colorare_patrat(int x1, int y1, int x4, int y4, int c)
{
    setcolor(BLACK);
    int x2=x1+latura;
    int y2=y1;
    int x3=x1;
    int y3=y1+latura;
    int puncte[]= {x1, y1, x3, y3, x4, y4, x2, y2, x1, y1};
    setfillstyle(SOLID_FILL, c);
    fillpoly(5, puncte);
}

void reguli_usor()
{
    int x,y,ok=1;
    cleardevice();
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 4 - CADRAN USOR");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    int i,j;
    int x1, y1, x4, y4;
    latura=70;
    for (i=1; i<=8; i++)
        for (j=1; j<=8; j++)
        {
            setcolor(BLUE);
            rectangle(400+latura*(i-1),200+ latura*(j-1),400+latura*i,200+latura*j);
            x1=400+latura*(i-1);
            y1=200+latura*(j-1);
            x4=400+latura*i;
            y4=200+latura*j;
            if(i==2 && j==3)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==4 && j==6)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==3 && j==3)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==3 && j==4)
            {
                colorare_patrat(x1, y1, x4, y4,2);
                setcolor(BLACK);
                setfillstyle(SOLID_FILL, BLACK);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }
            if(i==3 && j==5)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==3 && j==6)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==2 && j==6)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==4 && j==5)
                colorare_patrat(x1, y1, x4, y4,2);

        }

    sageata_urm();

    pasul4_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul4_8();
                ok=0;
            }
            else if(x>=1350 && x<=1470 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                reguli_mediu();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void reguli_mediu()
{
    int x,y,ok=1;
    cleardevice();
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 4 - CADRAN MEDIU");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    int i,j;
    int x1, y1, x4, y4;
    latura=70;
    for (i=1; i<=8; i++)
        for (j=1; j<=8; j++)
        {
            setcolor(BLUE);
            rectangle(400+latura*(i-1),200+ latura*(j-1),400+latura*i,200+latura*j);
            x1=400+latura*(i-1);
            y1=200+latura*(j-1);
            x4=400+latura*i;
            y4=200+latura*j;
            if(i==2 && j==4)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==3 && j==4)
            {
                colorare_patrat(x1, y1, x4, y4,2);
                setfillstyle(LTSLASH_FILL, 14);
                setcolor(BLACK);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }
            if(i==4 && j==4)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==5 && j==4)
            {
                colorare_patrat(x1, y1, x4, y4,2);
                setcolor(BLACK);
                setfillstyle(SOLID_FILL, BLACK);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }
            if(i==4 && j==5)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==4 && j==6)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==4 && j==7)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==5 && j==5)
                colorare_patrat(x1, y1, x4, y4,2);

        }

    sageata_ant();
    sageata_urm();

    pasul4_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul4_8();
                ok=0;
            }
            else if(x>=1350 && x<=1470 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                reguli_dificil();
                ok=0;
            }
            else if(x>=20 && x<=140 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                reguli_usor();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void reguli_dificil()
{
    int x,y,ok=1;
    cleardevice();
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 4 - CADRAN DIFICIL");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    int i,j;
    int x1, y1, x4, y4;
    latura=70;
    for (i=1; i<=8; i++)
        for (j=1; j<=8; j++)
        {
            setcolor(BLUE);
            rectangle(400+latura*(i-1),200+ latura*(j-1),400+latura*i,200+latura*j);
            x1=400+latura*(i-1);
            y1=200+latura*(j-1);
            x4=400+latura*i;
            y4=200+latura*j;
            if(i==1 && j==1)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==1 && j==2)
            {
                colorare_patrat(x1, y1, x4, y4,2);
                setfillstyle(LTSLASH_FILL, 14);
                setcolor(BLACK);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }
            if(i==2 && j==2)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==3 && j==2)
            {
                colorare_patrat(x1, y1, x4, y4,2);
                setcolor(BLACK);
                setfillstyle(SOLID_FILL, BLACK);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }
            if(i==4 && j==2)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==4 && j==3)
                colorare_patrat(x1, y1, x4, y4,2);
            if(i==4 && j==4)
            {
                colorare_patrat(x1, y1, x4, y4,2);
                setfillstyle(XHATCH_FILL, 14);
                setcolor(BLACK);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }
            if(i==3 && j==4)
                colorare_patrat(x1, y1, x4, y4,2);

        }

    sageata_ant();
    pasul4_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            //if(mute)

            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul4_8();
                ok=0;
            }
            else if(x>=20 && x<=140 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                reguli_mediu();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void pasul5_8()
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("3.jpg",0,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 5");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(650, 400, 90, 270, 50);
    line(650,350, 850, 350);
    line(650, 450, 850, 450);
    pieslice(850, 400, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(650, 400, 50, 50);
    int puncte2[]= {650, 350, 650, 450, 850, 450, 850, 350, 650, 350};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(650, 400, 90, 270, 50);
    line(650,350, 850, 350);
    line(650, 450, 850, 450);
    arc(850, 400, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(650, 380, "JUCATI");

    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(630, 500, "SUCCES!");

    sageata_ant();
    meniu_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_8();
                ok=0;
            }
            else if(x>=20 && x<=140 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul4_8();
                ok=0;
            }
            else if(x>=600 && x<=900 && y>=350 && y<=450)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_joaca();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void pasul1_4()
{
    int x, y,ok=1;
    cleardevice();
    readimagefile("8.jpg",0,0,1000,856);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 1");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(100, 450, "Selectati culoarea");

    line(550, 474, 580, 474);
    line(580, 474, 565, 464);
    line(580, 474, 565, 484);

    int culoarescor=2;
    setcolor(BLACK);
    int xc=350;
    for(int i=2; i<=5; i++)
    {
        setfillstyle(SOLID_FILL, culoarescor++);
        setcolor(BLACK);
        circle(700, xc, 26);
        fillellipse(700, xc, 25, 26);
        xc+=75;
    }

    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(800, 450, "SAU");

    int i,j;
    int x1, y1, x4, y4;
    latura=70;
    int color=2;
    for (i=1; i<=2; i++)
        for (j=1; j<=2; j++)
        {
            setcolor(BLUE);
            rectangle(1000+latura*(i-1),400+ latura*(j-1),1000+latura*i,400+latura*j);
            x1=1000+latura*(i-1);
            y1=400+latura*(j-1);
            x4=1000+latura*i;
            y4=400+latura*j;
            setcolor(BLACK);
            setfillstyle(SOLID_FILL, color++);
            circle((x1+x4)/2,(y1+y4)/2, 20);
            fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
        }
    sageata_urm();
    meniu_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            //if(mute)

            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_4();
                ok=0;
            }
            else if(x>=1350 && x<=1470 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul2_4();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void pasul2_4()
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("2.jpg",100,400,1500,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 2");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(300, 200, "Incepeti prin a selecta patratul cu bila");
    outtextxy(370, 300, "de culoarea aleasa, colorandu-l.");

    setcolor(BLUE);
    rectangle(550, 450, 620, 520);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, 2);
    circle(585,485, 20);
    fillellipse(585,485, 20, 20);

    setcolor(WHITE);
    line(700, 485, 730, 485);
    line(730, 485, 715, 475);
    line(730, 485, 715, 495);

    rectangle(780, 450, 850, 520);
    setcolor(BLACK);
    int puncte[]= {780, 450, 780, 520, 850, 520, 850, 450, 780, 450};
    setfillstyle(SOLID_FILL, 2);
    fillpoly(5, puncte);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(815, 485, 20);
    fillellipse(815,485, 20, 20);

    sageata_ant();

    sageata_urm();

    meniu_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            //if(mute)

            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_4();
                ok=0;
            }
            else if(x>=1350 && x<=1470 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul3_4();
                ok=0;
            }
            else if(x>=20 && x<=140 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul1_4();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void pasul3_4()
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("4.jpg",400,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 3");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(150, 200, "Scopul jocului este sa formati 4 cadrane continui,");
    outtextxy(150, 300, "de cate 16 patratele, si identice (de aceeasi forma)");
    outtextxy(250, 400, "care sa contina cate o bila de fiecare fel,");
    outtextxy(450, 500, "pentru fiecare culoare");

    sageata_ant();
    sageata_urm();

    meniu_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_4();
                ok=0;
            }
            else if(x>=1350 && x<=1470 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul4_4();
                ok=0;
            }
            else if(x>=20 && x<=140 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul2_4();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void exemplu();

void pasul4_4()
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("5.jpg",0,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 4");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(350, 200, "Cadranul trebuie sa fie format ");
    outtextxy(430, 300, "din 16 patratele adiacente");

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    pieslice(850, 500, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(650, 500, 50, 50);
    int puncte2[]= {650, 450, 650, 550, 850, 550, 850, 450, 650, 450};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(650, 500, 90, 270, 50);
    line(650,450, 850, 450);
    line(650, 550, 850, 550);
    arc(850, 500, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(650, 480, "MODEL");

    sageata_ant();
    sageata_urm();

    meniu_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_4();
                ok=0;
            }
            else if(x>=1350 && x<=1470 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul5_4();
                ok=0;
            }
            else if(x>=600 && x<=900 && y>=450 && y<=650)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                exemplu();
                ok=0;
            }
            else if(x>=20 && x<=140 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul3_4();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void exemplu()
{
    int x,y,ok=1;
    cleardevice();
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 4 - EXEMPLU");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    int i,j;
    int x1, y1, x4, y4;
    latura=70;
    for (i=1; i<=8; i++)
        for (j=1; j<=8; j++)
        {
            setcolor(BLUE);
            rectangle(400+latura*(i-1),200+ latura*(j-1),400+latura*i,200+latura*j);
            x1=400+latura*(i-1);
            y1=200+latura*(j-1);
            x4=400+latura*i;
            y4=200+latura*j;
            if(i>=1 && i<=4 && j>=1 && j<=4)
            {
                colorare_patrat(x1, y1, x4, y4,2);
                if(i==2 && j==4)
                {
                    setfillstyle(LTSLASH_FILL, 14);
                    setcolor(BLACK);
                    circle((x1+x4)/2,(y1+y4)/2, 20);
                    fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                }
                if(i==1 && j==2)
                {
                    setcolor(BLACK);
                    setfillstyle(SOLID_FILL, BLACK);
                    circle((x1+x4)/2,(y1+y4)/2, 20);
                    fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                }
            }
            if(i>=5 && i<=8 && j>=1 && j<=4)
            {
                colorare_patrat(x1, y1, x4, y4,3);
                if(i==6 && j==3)
                {
                    setfillstyle(LTSLASH_FILL, 14);
                    setcolor(BLACK);
                    circle((x1+x4)/2,(y1+y4)/2, 20);
                    fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                }
                if(i==8 && j==2)
                {
                    setcolor(BLACK);
                    setfillstyle(SOLID_FILL, BLACK);
                    circle((x1+x4)/2,(y1+y4)/2, 20);
                    fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                }
            }
            if(i>=1 && i<=4 && j>=5 && j<=8)
            {
                colorare_patrat(x1, y1, x4, y4,4);
                if(i==2 && j==7)
                {
                    setfillstyle(LTSLASH_FILL, 14);
                    setcolor(BLACK);
                    circle((x1+x4)/2,(y1+y4)/2, 20);
                    fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                }
                if(i==4 && j==5)
                {
                    setcolor(BLACK);
                    setfillstyle(SOLID_FILL, BLACK);
                    circle((x1+x4)/2,(y1+y4)/2, 20);
                    fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                }
            }
            if(i>=5 && i<=8 && j>=5 && j<=8)
            {
                colorare_patrat(x1, y1, x4, y4,5);
                if(i==7 && j==8)
                {
                    setfillstyle(LTSLASH_FILL, 14);
                    setcolor(BLACK);
                    circle((x1+x4)/2,(y1+y4)/2, 20);
                    fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                }
                if(i==5 && j==7)
                {
                    setcolor(BLACK);
                    setfillstyle(SOLID_FILL, BLACK);
                    circle((x1+x4)/2,(y1+y4)/2, 20);
                    fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
                }
            }
            if(i==2 && j==4)
            {
                colorare_patrat(x1, y1, x4, y4,2);
                setfillstyle(LTSLASH_FILL, 14);
                setcolor(BLACK);
                circle((x1+x4)/2,(y1+y4)/2, 20);
                fillellipse((x1+x4)/2,(y1+y4)/2, 20, 20);
            }

        }

    pasul4_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul4_4();
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void pasul5_4()
{
    int x,y,ok=1;
    cleardevice();
    readimagefile("3.jpg",0,0,1536,864);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(30, 90, "PASUL 5");

    setlinestyle(0, 0, 2);
    line(20, 150, 1500, 150);

    casuta();

    setlinestyle(0, 0, 2);
    setcolor(BLACK);
    pieslice(650, 400, 90, 270, 50);
    line(650,350, 850, 350);
    line(650, 450, 850, 450);
    pieslice(850, 400, 270, 90, 50);
    setfillstyle(SOLID_FILL, 0);
    fillellipse(650, 400, 50, 50);
    int puncte2[]= {650, 350, 650, 450, 850, 450, 850, 350, 650, 350};
    setfillstyle(SOLID_FILL, BLACK);
    fillpoly(5, puncte2);
    setcolor(WHITE);
    arc(650, 400, 90, 270, 50);
    line(650,350, 850, 350);
    line(650, 450, 850, 450);
    arc(850, 400, 270, 90, 50);
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(650, 380, "JUCATI");

    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(630, 500, "SUCCES!");

    sageata_ant();
    meniu_buton();
    while(ok)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=950 && x<=1450 && y>=650 && y<=850)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_4();
                ok=0;
            }
            else if(x>=20 && x<=140 && y>=470 && y<=520)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                pasul4_4();
                ok=0;
            }
            else if(x>=600 && x<=900 && y>=350 && y<=450)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                joc_medium2(0);
                ok=0;
            }
            else if(x>=1370 && x<=1470 && y>=13 && y<=113)
            {
                PlaySound(TEXT("popsound.wav"),NULL,SND_SYNC);
                meniu_principal();
                ok=0;
            }
        }
    }
}

void casuta()
{
    setcolor(BLACK);
    rectangle(1400, 60, 1440, 90);
    rectangle(1415, 75, 1425, 90);
    rectangle(1430, 35, 1438, 50);
    line(1420, 30, 1385, 60);
    line(1420, 30, 1455, 60);
    line(1385, 60, 1455, 60);
    circle(1420, 63, 50);
    setfillstyle(SOLID_FILL, 12);
    fillellipse(1420, 63, 50, 50);
    int puncte[]= {1400, 60, 1400, 90, 1415, 90, 1415, 75, 1425, 75, 1425, 90, 1440, 90, 1440, 60, 1400, 60};
    setfillstyle(SOLID_FILL, 0);
    fillpoly(9, puncte);
    int puncte1[]= {1420, 30, 1385, 60, 1455, 60, 1420, 30};
    setfillstyle(SOLID_FILL, 0);
    fillpoly(4, puncte1);
    int puncte2[]= {1430, 35, 1430, 50, 1438, 50, 1438, 35, 1430, 35};
    setfillstyle(SOLID_FILL, 0);
    fillpoly(5, puncte2);

}


int main()
{
    srand(time(NULL));
    citire_easymode();
    citire_mediummode();
    citire_hardmode();
    citire_mediummode2();
    cout<<endl;
    cout<<screenWidth<<endl<<screenHeith<<endl;
    initwindow(screenWidth,screenHeith);
    meniu_principal();
    cout<<endl;
    getch();
    closegraph();
    return 0;
}
