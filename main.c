#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define dis 1.418000
#define disA 1.228024023
#define disB 0.67
#define disC 0.60
#define disD 1.160474041
#define disE 1.039230485
#define disF 0.97
#define disAqua 0.9584
#define massaC 12.010700
#define massaO 15.999400
#define massaH 1.007940



struct atomo{
    int id;
    char type[3];
    double px;
    double py;
    double pz;
    int la;
    int lb;
    int lc;
};

int main()
{

    printf("Hello world!\n");
    double mC = massaC, mO = massaO, mH = massaH;
    double x, y, z;
    double x1, y1;
    double x2, y2, z2;
    double x3, y3;
    double x4 , x5, y4, y5;
    float f2, f5, f6, f7, f8, f9, ft, fa;
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, na;
    int m1, m2, m3;
    int mi, mj;
    int i, j, k, t;
    int a1, a2, a3;
    int pk, ps, r1, ph, pc;
    int p, q, r, co, ch, cb; //contador
    int aux1=1, aux2, aux3, aux4, aux5, aux6, aux7, aux8;
    int all, typeatomos=1;
    int ci, cj, di, dj;
    int la, lb, lc;
    char buffer[5000], s, st[100];
    FILE *filein, *fileout, *filesafe, *filec, *fileninput, *filedata;

    //Arquivo contendo o input
    fileninput = fopen("input", "r");
    //Arquivo contendo as coordenadas da folha de grafeno puro
    filein = fopen("initio.xyz", "r");
    //Arquivo contendo as coordenadas da Celulose
    filec = fopen("cell.xyz", "r");
    //Arquivo de saída do GO em arquivo .xyz e em data para o lammps
    fileout = fopen("GO.xyz", "w");
    filedata = fopen("data.__", "w");
    //Arquivo contendo os passos dos processos de formação do GO, informa possíveis erros
    filesafe = fopen("full", "w");

    //Input
    //#################Bem vindo###########################
    //#Não altere o nome do arquivo: Input
    //#O arquivo .xyz deve possuir o nome data.xyz

    //Porcentagem do buraco central:
    //0
    //Porcentagm de Epoxi:
    //5
    //Porcentagem de Hidroxila:
    //5
    //Porcentagem de carboxila:
    //0.0
    //Porcentagem de carbonila:
    //0.0
    //Porcentagem de buracos:
    //0.0
    //Porcentagem de agua:
    //0.0
    //Inserir Folha de Celulose? (1 Sim || 2 Não)\n");
    //2

    //Leitura do Input
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%s ",&st);
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%s ",&st);
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%s ",&st);
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%s ",&st);


    //Buraco Central
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%s ",&st);
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%f", &f7);

    //epoxi
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%s ",&st);
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%f", &f2);

    //Hidroxila
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%s ",&st);
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%f", &f6);

    //Carboxila
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%s ",&st);
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%f", &f8);

    //Carbonila
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%s ",&st);
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%f", &f9);

    //Defeitos
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%s ",&st);
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%f", &ft);

    //agua
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%s ",&st);
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%f", &fa);

    //Folha de Celulose
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%s ",&st);
    fgets(buffer, 5000, fileninput);
    sscanf(buffer, "%d", &m2);



    //Leitura do arquivo contendo as coordenadas do grafeno

    fgets(buffer, 5000, filein);
    sscanf(buffer, "%d",&n1);
    fgets(buffer, 5000, filein);
    sscanf(buffer, "%s ",&st);
    printf("%s", st);

    struct atomo org[n1];



    for(p=1;p<=n1;p++){
            fgets(buffer, 5000, filein);
            sscanf(buffer, "%s %lf %lf %lf",&s, &x, &y, &z);
            org[p].type[0] = s;
            org[p].px = x;
            org[p].py = y;
            org[p].pz = z;


    }
    j=0;
    for(p=1;p<=n1;p++){
            if(org[p].py == 0){
            j++;

    }}



    //Calcular a quantidade de funcionais de oxigênio em função do tamanho do grafeno

    i = n1/j;
    n5 = j;
    n4 = n1/2;

    f2 = n1*f2*0.01;
    f6 = n1*f6*0.01;
    ft = n1*ft*0.01;
    f7 = n1*f7*0.01;
    f8 = n1*f8*0.01/2;
    f9 = n1*f9*0.01/2;
    fa = n1*fa*0.01;

    n2 = round(f2);
    n6 = round(f6);
    t  = round(ft);
    n7 = round(f7);
    n8 = round(f8);
    n9 = round(f9);
    na = round(fa);
    n3 = n7+n8+n9;





    int random[n1];
    int hole[n1];
    int nule[n1];
    int centralhole[n1];
    int po[n7];
    int bord[n1];
    int aqua[n1];





    struct atomo imp[n4];
    struct atomo par[n4];

    struct atomo c[i][j];
    struct atomo o[n2];
    struct atomo h[n6];
    struct atomo e[n2];
    struct atomo carb[n8];
    struct atomo oc1[n8];
    struct atomo oc2[n8];
    struct atomo hc[n8];
    struct atomo cn[n9];
    struct atomo on[n9];
    struct atomo oa[na];
    struct atomo ha[na];
    struct atomo hb[na];

    //Organização da posição dos átomos obtidos na leitura do grafeno
    //impares
    p = 1;
    for(q=1;q<=n4;q++){


            x2 =  org[p].px;
            y2 =  org[p].py;
            z2 =  org[p].pz;
            imp[q].px  = x2;
            imp[q].py  = y2;
            imp[q].pz  = z2;

            p++;
            p++;


    }
    printf("\n");
    //pares
    p = 2;
    for(q=1;q<=n4;q++){

            x2 =  org[p].px;
            y2 =  org[p].py;
            z2 =  org[p].pz;
            par[q].px  = x2;
            par[q].py  = y2;
            par[q].pz  = z2;

            p++;
            p++;

    }
    printf("\n");
    //full
    p = 1;
    co = 1;
    for(q=1;q<=n1;q++){

            x2   = imp[p].px;
            y2   = imp[p].py;
            z2   = imp[p].pz;
            org[q].px   = x2;
            org[q].py   = y2;
            org[q].pz   = z2;
            p++;
            co++;
            if(co==(n5+1)){
                q = q+n5;
                co = 1;
            }
    }
    p = 1;
    co = 1;
    for(q=(n5+1);q<=n1;q++){

            x2   = par[p].px;
            y2   = par[p].py;
            z2   = par[p].pz;
            org[q].px   = x2;
            org[q].py   = y2;
            org[q].pz   = z2;
            p++;
            co++;
            if(co==(n5+1)){
                q = q+n5;
                co = 1;
            }
    }
    //Calculando o tamanho da caixa de simulação necessária de acordo com o tamanho do grafeno
    x  = org[(n5+1)].px;
    x1 = org[(n5*2)].px;
    x4 = x-(dis/2); //xlo
    x5 = x1+(dis/2); //xhi
    y  = org[1].py;
    y1 = org[n1].py;
    y4 = y-(disA/2); //ylo
    y5 = y1+(disA/2); //yhi





    //Calculando a coordenada dos átomos de carbono


    aux1 = 1;
    for(p=1;p<=i;p++){
        for(q=1;q<=j;q++){

            c[p][q].id = aux1;
            c[p][q].type[0] = 67;
            c[p][q].type[1] = 48;
            c[p][q].px = org[aux1].px;
            c[p][q].py = org[aux1].py;
            c[p][q].pz = org[aux1].pz;
            aux1++;



        }
    }

    //obtendo os índices de átomos que possuem ligação
    //bound1
    aux1 = 2;
    for(q=1;q<=j;q++){
        for(p=1;p<=i;p++){


            aux1 = p+1;
            if(aux1>i){
                aux2 = c[1][q].id;
                c[p][q].la = aux2;
                aux2 = c[p][q].id;
                c[1][q].lb = aux2;
            }
            if(aux1<=i){
            aux2 = c[aux1][q].id;
            c[p][q].la = aux2;
            aux2 = c[p][q].id;
            c[aux1][q].lb = aux2;
            }

        }
    }

    //bond3
    for(p=1;p<=i;p++){
        for(q=1;q<=j;q++){

            if((p%2 != 0) && (q%2 != 0)){
                aux1 = q+1;
                aux2 = c[p][aux1].id;
                c[p][q].lc = aux2;
                aux2 = c[p][q].id;
                c[p][aux1].lc = aux2;
            }
            if((p%2 == 0 )&& (q%2 == 0)){
                aux1 = q+1;
                if(aux1 <= j){
                aux2 = c[p][aux1].id;
                c[p][q].lc = aux2;
                aux2 = c[p][q].id;
                c[p][aux1].lc = aux2;
                }
                if(aux1 > j){
                aux2 = c[p][1].id;
                c[p][q].lc = aux2;
                aux2 = c[p][q].id;
                c[p][1].lc = aux2;
                }
            }
        }
    }
    //Escrevendo as ligações de cada átomo de carbono em um arquivo para verificação
    for(p=1;p<=i;p++){
        for(q=1;q<=j;q++){

            fprintf(filesafe, "%d (%d %d %d) \n", c[p][q].id, c[p][q].la, c[p][q].lb ,c[p][q].lc);


        }
    }




    //setando as varíaveis de ramdomização
    for(r=0;r<=n1;r++){
            random[r]=r;
            hole[r]=r;
            nule[r]=r;
            centralhole[r]=r;
            bord[r]=r;
            aqua[r]=r;
    };
    srand(time(NULL));

    //Criando um buraco central no GO, essa opção precisa ser habilitada no input
    if(n3>0){
        mi = i/2;
        mj = j/2;
        m3 = c[mi][mj].id;

        centralhole[m3]=0;
        random[m3]=0;
        hole[m3]=0;
        nule[m3]=0;
        po[1]=m3;
        ch = 1;
    }

    for(cb=1;cb<(n3);cb++){
        m3 = po[cb];
        ci = (m3/j)+1;
        cj = m3%j;
        if(cj == 0){
            ci = m3/j;
            cj = j;
        }

        la = c[ci][cj].la;
        lb = c[ci][cj].lb;
        lc = c[ci][cj].lc;




        aux7=1;
        aux8=1;


        if (centralhole[la]!=0){
            centralhole[la]=0;
            random[la]=0;
            hole[la]=0;
            nule[la]=0;
            ch++;
            po[ch]=la;
            aux7 = 0;

            if((ch+aux8)<=n3){
                aux7 = 1;
            }
        }


        if (centralhole[lb]!=0&&aux7!=0){
            centralhole[lb]=0;
            random[lb]=0;
            hole[lb]=0;
            nule[lb]=0;
            ch++;
            po[ch]=lb;
            aux7 = 0;

            if((ch+aux8)<=n3){
                aux7 = 1;
            }
        }


        if (centralhole[lc]!=0&&aux7!=0){
            centralhole[lc]=0;
            random[lc]=0;
            hole[lc]=0;
            nule[lc]=0;
            ch++;
            po[ch]=lc;

        }

        if(ch==n3){
            cb = n3+1;
        }
}

    //Criação de defeitos aleatórios
    if(t!=0){
    for(r=1;r<=t;r++){

    do{
        aux2 = (rand()%n1);

        if(hole[aux2]==0){
            aux3 = 0;
        }else{
            aux3 = 1;
        };
    }while(aux3 ==0);

    ci = (aux2/j)+1;
    cj = aux2%j;
    if(cj == 0){
        ci = aux2/j;
        cj = j;
    }


    random[aux2] = 0;
    hole[aux2] = 0;
    nule[aux2] = 0;
    aux4 = c[ci][cj].la;
    hole[aux4] = 0;
    aux4 = c[ci][cj].lb;
    hole[aux4] = 0;
    aux4 = c[ci][cj].lc;
    hole[aux4] = 0;
    }

    aux1 = 1;
    for(p=1;p<=i;p++){
        for(q=1;q<=j;q++){


            if(nule[aux1]!=0){
                a1 = c[p][q].la;
                a2 = c[p][q].lb;
                a3 = c[p][q].lc;
                if(nule[a1]==0 && nule[a2]==0 && nule[a3]==0){
                    nule[aux1] = 0;
                    t++;
                }

            }
            aux1++;
        }
    }}


    //Verificando a possibilidade de Carbono isolado da folha

    pk = 1;
    for(r1=0;r1<=n1;r1++){
        if(hole[r1]!=0){
            pc = 0;
            m3 = hole[r1];
            ci = (m3/j)+1;
            cj = m3%j;
            if(cj == 0){
                ci = m3/j;
                cj = j;
            }

            la = c[ci][cj].la;
            lb = c[ci][cj].lb;
            lc = c[ci][cj].lc;
            ph = 0;

            if(hole[la]==0)
                ph++;
            if(hole[lb]==0)
                ph++;
            if(hole[lc]==0)
                ph++;


            if(ph==2&&pk>0){
                random[r1]=0;
                hole[r1]=0;
                nule[r1]=0;
                pk = pk*(-1);
                pc = 1;
            }
            if(ph==2&&pk<0&&pc!=1){
                ps = 0;
                if(hole[la]==0&&ps==0){
                    centralhole[la]=la;
                    random[la]=la;
                    hole[la]=la;
                    nule[la]=la;
                    ps = 1;
                }
                if(hole[lb]==0&&ps==0){
                    centralhole[lb]=lb;
                    random[lb]=lb;
                    hole[lb]=lb;
                    nule[lb]=lb;
                    ps = 1;
                }
                if(hole[lc]==0&&ps==0){
                    centralhole[lc]=lc;
                    random[lc]=lc;
                    hole[lc]=lc;
                    nule[lc]=lc;
                    ps = 1;
                }
                pk = pk*(-1);

            }



        }
    }

    for(r=1;r<=n1;r++){
        if(random[r]!=0){
            m3 = random[r];
            ci = (m3/j)+1;
            cj = m3%j;
            if(cj == 0){
                ci = m3/j;
                cj = j;
            }
            la = c[ci][cj].la;
            lb = c[ci][cj].lb;
            lc = c[ci][cj].lc;
            if(centralhole[la]==0)
                bord[r] = 0;
            if(centralhole[lb]==0)
                bord[r] = 0;
            if(centralhole[lc]==0)
                bord[r] = 0;
        }
    }




    //Criando Carboxila em defeitos ou na borda
    if(n8>0)
        typeatomos = typeatomos + 4;
    for(r=1;r<=n8;r++){
        do{
           aux2 = (rand()%n1);

           if(bord[aux2]!=0||aux2==0){
              aux3 = 0;
           }else{
              aux3 = 1;
           };

        }while(aux3 ==0);
        bord[aux2] = aux2;
        random[aux2] = 0;

        ci = (aux2/j)+1;
        cj = aux2%j;
        if(cj == 0){
            ci = aux2/j;
            cj = j;
        }

        x = c[ci][cj].px;
        y = c[ci][cj].py;
        z = c[ci][cj].pz;

        carb[r].id = n1+r;
        carb[r].type[0] = 67;
        carb[r].type[1] = 120;
        carb[r].px = x;
        carb[r].py = y;
        carb[r].pz = z+dis;


        oc1[r].id = n1+n8+r;
        oc1[r].type[0] = 79;
        oc1[r].type[1] = 120;
        oc1[r].type[2] = 49;
        oc1[r].px = x+disD;
        oc1[r].py = y;
        oc1[r].pz = z+disB+dis;

        hc[r].id = n1+n8+n8+r;
        hc[r].type[0] = 72;
        hc[r].type[1] = 120;
        hc[r].px = x+disD;
        hc[r].py = y;
        hc[r].pz = z+disB+disF+dis;

        oc2[r].id = n1+n8+n8+n8+r;
        oc2[r].type[0] = 79;
        oc2[r].type[1] = 120;
        oc2[r].type[2] = 50;
        oc2[r].px = x-disE;
        oc2[r].py = y;
        oc2[r].pz = z+disC+dis;

        if(aux2%2==0){
        carb[r].pz = -(z+dis);
        oc1[r].pz = -(z+disB+dis);
        hc[r].pz = -(z+disB+disF+dis);
        oc2[r].pz = -(z+disC+dis);
        }
    }

    //Criando carbonilas em defeitos ou na borda
    if(n9>0)
        typeatomos = typeatomos + 2;
    for(r=1;r<=n9;r++){
        do{
           aux2 = (rand()%n1);

           if(bord[aux2]!=0||aux2==0){
              aux3 = 0;
           }else{
              aux3 = 1;
           };

        }while(aux3 ==0);
        bord[aux2] = aux2;
        random[aux2] = 0;

        ci = (aux2/j)+1;
        cj = aux2%j;
        if(cj == 0){
            ci = aux2/j;
            cj = j;
        }

        x = c[ci][cj].px;
        y = c[ci][cj].py;
        z = c[ci][cj].pz;

        cn[r].id = n1+(n8+n8+n8+n8)+r;
        cn[r].type[0] = 67;
        cn[r].type[1] = 110;
        cn[r].px = x;
        cn[r].py = y;
        cn[r].pz = z+dis;


        on[r].id = n1+(n8+n8+n8+n8)+n9+r;
        on[r].type[0] = 79;
        on[r].type[1] = 110;
        on[r].px = x+(disA*0.5);
        on[r].py = y;
        on[r].pz = z+(disA*0.866025403)+dis;

        if(aux2%2==0){
        cn[r].pz = -(z+dis);
        on[r].pz = -(z+disB+dis);

        }
    }


    //Sorteando átomos para receber o epoxi
    if(n2>0)
        typeatomos++;
    for(r=1;r<=n2;r++){

        do{
           aux2 = (rand()%n1);
           aux5 = aux2+n5;

           if(random[aux2]==0){
              aux3 = 0;
           }else{
              aux3 = 1;
           };
           if(random[aux5]==0){
            aux3 = 0;
           }
           if(aux5>n1){
            aux3 = 0;
           }

        }while(aux3 ==0);

        random[aux2] = 0;
        random[aux5] = 0;
        hole[aux2] = 0;
        hole[aux5] = 0;



    ci = (aux2/j)+1;
    cj = aux2%j;
    if(cj == 0){
        ci = aux2/j;
        cj = j;
    }

    x = c[ci][cj].px;
    y = c[ci][cj].py;
    z = c[ci][cj].pz;

    di = (aux5/j)+1;
    dj = aux5%j;

    if(dj == 0){
        di = aux5/j;
        dj = j;
    }

    x2 = c[di][dj].px;
    y2 = c[di][dj].py;
    z2 = c[di][dj].pz;

    x3 = (x+x2);
    y3 = (y+y2);
    x1 = x3/2;
    y1 = y3/2;

    c[ci][cj].type[1] = 101;
    c[di][dj].type[1] = 101;

    la = c[ci][cj].la;
    lb = c[ci][cj].lb;
    lc = c[ci][cj].lc;
    random[la] = 0;
    random[lb] = 0;
    random[lc] = 0;
    hole[la] = 0;
    hole[lb] = 0;
    hole[lc] = 0;

    la = c[di][dj].la;
    lb = c[di][dj].lb;
    lc = c[di][dj].lc;
    random[la] = 0;
    random[lb] = 0;
    random[lc] = 0;
    hole[la] = 0;
    hole[lb] = 0;
    hole[lc] = 0;



    e[r].id = n1+(n8+n8+n8+n8)+(n9+n9)+r;
    e[r].type[0] = 79;
    e[r].type[1] = 101;
    e[r].px = x1;
    e[r].py = y1;
    if((r%2) != 0)
        e[r].pz = (dis);
    if((r%2) == 0)
        e[r].pz = -(dis);

    fprintf(filesafe, "%d %d %d\n", r, aux2, aux5);


    };

    //Sorteando átomos para receber o Hidroxila
    if(n6>0)
        typeatomos = typeatomos + 2;
    for(r=1;r<=n6;r++){

        do{
            aux2 = (rand()%n1);

            if(random[aux2]==0){
                aux3 = 0;
            }else{
                aux3 = 1;
            };
        }while(aux3 ==0);



        ci = (aux2/j)+1;
        cj = aux2%j;
        if(cj == 0){
            ci = aux2/j;
            cj = j;
        }

        random[aux2] = 0;
        hole[aux2] = 0;
        aux4 = c[ci][cj].la;
        random[aux4] = 0;
        aux4 = c[ci][cj].lb;
        random[aux4] = 0;
        aux4 = c[ci][cj].lc;
        random[aux4] = 0;

        x = c[ci][cj].px;
        y = c[ci][cj].py;
        z = c[ci][cj].pz;

        c[ci][cj].type[1] = 104;



        o[r].id = n1+n2+(n8+n8+n8+n8)+(n9+n9)+r;
        o[r].type[0] = 79;
        o[r].type[1] = 104;
        o[r].px = x;
        o[r].py = y;
        if((r%2) != 0)
            o[r].pz = dis;
        if((r%2) == 0)
            o[r].pz = -dis;




    }

    //hidrogenio
    for(q=1;q<=n6;q++){
        x = o[q].px;
        y = o[q].py;
        z = o[q].pz;

        h[q].id = n1+n2+n6+n8+n8+n8+n8+n9+n9+q;
        h[q].type[0] = 72;
        h[q].type[1] = 104;



                h[q].px = x+(0.97*0.82);
            if((q%3) == 0)
                h[q].px = x-(0.97*0.82);
            if((q%5) == 0)
                h[q].px = x-(0.97*0.82);

        h[q].py = y;
        if(z>1){
            h[q].pz = (0.57*0.97)+z;
        };
        if(z<1){
            h[q].pz = (z+(-0.97*0.57));
        };



    }

    //Colocando água na caixa
    if(na>0)
        typeatomos = typeatomos + 3;
    for(r=1;r<=na;r++){


        do{
            aux2 = (rand()%n1);

            if(aqua[aux2]==0){
                aux3 = 0;
            }else{
                aux3 = 1;
            };
        }while(aux3 ==0);



        ci = (aux2/j)+1;
        cj = aux2%j;
        if(cj == 0){
            ci = aux2/j;
            cj = j;
        }

        aqua[aux2] = 0;


        x = c[ci][cj].px;
        y = c[ci][cj].py;
        z = c[ci][cj].pz;



        oa[r].id = n1+n2+(n8+n8+n8+n8)+(n9+n9)+n6+n6+r;
        oa[r].type[0] = 79;
        oa[r].type[1] = 97;
        oa[r].px = x;
        oa[r].py = y;
        if((r%2) != 0)
            oa[r].pz = 4*dis;
        if((r%2) == 0)
            oa[r].pz = -4*dis;

        ha[r].id = n1+n2+(n8+n8+n8+n8)+(n9+n9)+n6+n6+na+r;
        ha[r].type[0] = 72;
        ha[r].type[1] = 97;
        ha[r].type[2] = 49;
        ha[r].px = x + disAqua;
        ha[r].py = y;
        ha[r].pz = oa[r].pz;

        hb[r].id = n1+n2+(n8+n8+n8+n8)+(n9+n9)+n6+n6+na+na+r;
        hb[r].type[0] = 72;
        hb[r].type[1] = 97;
        hb[r].type[2] = 50;
        hb[r].px = x + disAqua*(sin(104.45));
        hb[r].py = y;
        hb[r].pz = oa[r].pz + disAqua*(cos(104.45));



    }



    //Inserindo Celulose na caixa, deve ser habilitado no input.

    fgets(buffer, 5000, filec);
    sscanf(buffer, "%d",&m1);
    fgets(buffer, 5000, filec);
    sscanf(buffer, "%s ",&st);

    struct atomo cell[m1];


    for(p=1;p<=m1;p++){
            fgets(buffer, 5000, filec);
            sscanf(buffer, "%s %lf %lf %lf",&s, &x, &y, &z);
            cell[p].id = n1+n2+n6+n6+(n8+n8+n8+n8)+(n9+n9)+p;
            cell[p].type[0] = s;
            cell[p].type[1] = 99;
            cell[p].px = x-1.009;
            cell[p].py = y-0.368;
            cell[p].pz = z-10.746;
                if(p>=105&&p<129)
                    cell[p].type[2] = 120;
                if(p>=145&&p<=168)
                    cell[p].type[2] = 120;


    }






    //################################# Escrevendo arquivos de saída #########################################################

    all = n1+n6+n6+n2-t-n7+(n8+n8+n8)+(n9)+m1+na+na+na;
    if(m2==1){
        fprintf(fileout, "%d\n", all);
        fprintf(fileout, " #PDB  21.27   17.1923  100.0  90   90 90\n");
        typeatomos = typeatomos+5;
    }else{
        all = all - m1;
        fprintf(fileout, "%d\n", all);
        fprintf(fileout, "#PDB  21.27   17.1923  100.0  90   90 90\n");
    }
    //data
    fprintf(filedata, "generated by John\n");
    fprintf(filedata, " %d atoms\n", all);
    fprintf(filedata, " 0 bonds\n");
    fprintf(filedata, " 0 angles\n");
    fprintf(filedata, " 0 dihedrals\n");
    fprintf(filedata, " 0 impropers\n");
    fprintf(filedata, " %d atom types\n", typeatomos);
    fprintf(filedata, " 0 bond types\n");
    fprintf(filedata, " 0 angle types\n");
    fprintf(filedata, " 0 dihedral types\n");
    fprintf(filedata, " 0 improper types\n");

    //caixa
    fprintf(filedata, "%lf %lf   xlo xhi\n", x4, x5);
    fprintf(filedata, "%lf %lf   ylo yhi\n", y4, y5);
    fprintf(filedata, "-50.0000 50.0000  zlo zhi\n");

    //pair coeffs
    fprintf(filedata, "\n");
    fprintf(filedata, "# Pair Coeffs\n");
    fprintf(filedata, "#\n");
    k = 1;
    fprintf(filedata, "# %d  %c\n", k, c[1][1].type[0]);
    if(m2==1){
        k++;
        fprintf(filedata, "# %d  %c%c\n", k, cell[1].type[0], cell[1].type[1]);
    }
    if(n9>0){
        k++;
        fprintf(filedata, "# %d  %c%c\n", k, cn[1].type[0], cn[1].type[1]);
    }
    if(n8>0){
        k++;
        fprintf(filedata, "# %d  %c%c\n", k, carb[1].type[0], carb[1].type[1]);
    }
    if(na>0){
        k++;
        fprintf(filedata, "# %d  %c%c%c\n", k, ha[1].type[0], ha[1].type[1], ha[1].type[2]);
    }
    if(na>0){
        k++;
        fprintf(filedata, "# %d  %c%c%c\n", k, hb[1].type[0], hb[1].type[1], hb[1].type[2]);
    }
    if(m2==1){
        k++;
        fprintf(filedata, "# %d  %c%c\n", k, cell[49].type[0], cell[49].type[1]);
    }
    if(m2==1){
        k++;
        fprintf(filedata, "# %d  %c%c%c\n", k, cell[105].type[0], cell[105].type[1], cell[105].type[2]);
    }
    if(n6>0){
        k++;
        fprintf(filedata, "# %d  %c%c\n", k, h[1].type[0], h[1].type[1]);
    }
    if(n8>0){
        k++;
        fprintf(filedata, "# %d  %c%c\n", k, hc[1].type[0], hc[1].type[1]);
    }
    if(na>0){
        k++;
        fprintf(filedata, "# %d  %c%c\n", k, oa[1].type[0], oa[1].type[1]);
    }
    if(m2==1){
        k++;
        fprintf(filedata, "# %d  %c%c\n", k, cell[129].type[0], cell[129].type[1]);
    }
    if(m2==1){
        k++;
        fprintf(filedata, "# %d  %c%c%c\n", k, cell[145].type[0], cell[145].type[1], cell[145].type[2]);
    }
    if(n2>0){
        k++;
        fprintf(filedata, "# %d  %c%c\n", k, e[1].type[0], e[1].type[1]);
    }
    if(n6>0){
        k++;
        fprintf(filedata, "# %d  %c%c\n", k, o[1].type[0], o[1].type[1]);
    }
    if(n9>0){
        k++;
        fprintf(filedata, "# %d  %c%c\n", k, on[1].type[0], on[1].type[1]);
    }
    if(n8>0){
        k++;
        fprintf(filedata, "# %d  %c%c%c\n", k, oc1[1].type[0], oc1[1].type[1], oc1[1].type[2]);
    }
    if(n8>0){
        k++;
        fprintf(filedata, "# %d  %c%c%c\n", k, oc2[1].type[0], oc2[1].type[1], oc2[1].type[2]);
    }

    //Masses

    fprintf(filedata, "\n");
    fprintf(filedata, " Masses\n");
    fprintf(filedata, "\n");
    k = 1;
    fprintf(filedata, " %d %lf # %c\n", k, mC, c[1][1].type[0]);
    if(m2==1){
        k++;
        fprintf(filedata, " %d %lf # %c%c\n", k, mC, cell[1].type[0], cell[1].type[1]);
    }
    if(n9>0){
        k++;
        fprintf(filedata, " %d %lf # %c%c\n", k, mC, cn[1].type[0], cn[1].type[1]);
    }
    if(n8>0){
        k++;
        fprintf(filedata, " %d %lf # %c%c\n", k, mC, carb[1].type[0], carb[1].type[1]);
    }
    if(na>0){
        k++;
        fprintf(filedata, " %d %lf # %c%c%c\n", k, mH, ha[1].type[0], ha[1].type[1], ha[1].type[2]);
    }
    if(na>0){
        k++;
        fprintf(filedata, " %d %lf # %c%c%c\n", k, mH, hb[1].type[0], hb[1].type[1], hb[1].type[2]);
    }
    if(m2==1){
        k++;
        fprintf(filedata, " %d %lf # %c%c\n", k, mH, cell[49].type[0], cell[49].type[1]);
    }
    if(m2==1){
        k++;
        fprintf(filedata, " %d %lf # %c%c%c\n", k, mH, cell[105].type[0], cell[105].type[1], cell[105].type[2]);
    }
    if(n6>0){
        k++;
        fprintf(filedata, " %d %lf # %c%c\n", k, mH, h[1].type[0], h[1].type[1]);
    }
    if(n8>0){
        k++;
        fprintf(filedata, " %d %lf # %c%c\n", k, mH, hc[1].type[0], hc[1].type[1]);
    }
    if(na>0){
        k++;
        fprintf(filedata,  " %d %lf # %c%c\n", k, mO, oa[1].type[0], oa[1].type[1]);
    }
    if(m2==1){
        k++;
        fprintf(filedata, " %d %lf # %c%c\n", k, mO, cell[129].type[0], cell[129].type[1]);
    }
    if(m2==1){
        k++;
        fprintf(filedata, " %d %lf # %c%c%c\n", k, mO, cell[145].type[0], cell[145].type[1], cell[145].type[2]);
    }
    if(n2>0){
        k++;
        fprintf(filedata, " %d %lf # %c%c\n", k, mO, e[1].type[0], e[1].type[1]);
    }
    if(n6>0){
        k++;
        fprintf(filedata,  " %d %lf # %c%c\n", k, mO, o[1].type[0], o[1].type[1]);
    }
    if(n9>0){
        k++;
        fprintf(filedata,  " %d %lf # %c%c\n", k, mO, on[1].type[0], on[1].type[1]);
    }
    if(n8>0){
        k++;
        fprintf(filedata,  " %d %lf # %c%c\n", k, mO, oc1[1].type[0], oc1[1].type[1], oc1[1].type[2]);
    }
    if(n8>0){
        k++;
        fprintf(filedata,  " %d %lf # %c%c\n", k, mO, oc2[1].type[0], oc2[1].type[1], oc2[1].type[2]);
    }



    // Atoms
    fprintf(filedata, "\n");
    fprintf(filedata, "\n");
    fprintf(filedata, "\n");
    fprintf(filedata, " Atoms # full\n");
    fprintf(filedata, "\n");
    k = 1;
    aux6 = 1;

    //Carbono
    aux1 = 1;
    for(p=1;p<=i;p++){
        for(q=1;q<=j;q++){
            if(nule[aux1]!=0){
                if(c[p][q].type[1] == '0'){
                    fprintf(fileout," %c        %lf        %lf        %lf\n",   c[p][q].type[0], c[p][q].px, c[p][q].py, c[p][q].pz);
                    fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c\n", k, aux6, c[p][q].px, c[p][q].py, c[p][q].pz, c[p][q].type[0]);
                    k++;
                }else{
                    fprintf(fileout," %c%c        %lf        %lf        %lf\n",   c[p][q].type[0], c[p][q].type[1], c[p][q].px, c[p][q].py, c[p][q].pz);
                    fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c\n", k, aux6, c[p][q].px, c[p][q].py, c[p][q].pz, c[p][q].type[0]);
                    k++;
                }
            }
            aux1++;

        }
    }

    //Cellulose Cc
    if(m2==1){
        aux6++;
        //carb(Cc)
        for(r=1;r<=48;r++){
            fprintf(fileout," %c%c        %lf        %lf        %lf\n",   cell[r].type[0], cell[r].type[1],  cell[r].px, cell[r].py, cell[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c\n", k, aux6, cell[r].px, cell[r].py, cell[r].pz, cell[r].type[0], cell[r].type[1]);
            k++;
        }
    }

    //Carbonila
    if(n9>0){
        aux6++;
        //carb(Cn)
        for(r=1;r<=n9;r++){
            fprintf(fileout," %c%c        %lf        %lf        %lf\n",   cn[r].type[0], cn[r].type[1],  cn[r].px, cn[r].py, cn[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c\n", k, aux6, cn[r].px, cn[r].py, cn[r].pz, cn[r].type[0], cn[r].type[1]);
            k++;
        }
    }
    if(n8>0){
        aux6++;
        //carb(Cx)
        for(r=1;r<=n8;r++){
            fprintf(fileout," %c%c        %lf        %lf        %lf\n",   carb[r].type[0], carb[r].type[1], carb[r].px, carb[r].py, carb[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c\n", k, aux6, carb[r].px, carb[r].py, carb[r].pz, carb[r].type[0], carb[r].type[1]);
            k++;
        }
    }

    //Cellulose Hc
    if(m2==1){
        aux6++;
        //H(Hc)
        for(r=49;r<=104;r++){
            fprintf(fileout," %c%c        %lf        %lf        %lf\n",   cell[r].type[0], cell[r].type[1],  cell[r].px, cell[r].py, cell[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c\n", k, aux6, cell[r].px, cell[r].py, cell[r].pz, cell[r].type[0], cell[r].type[1]);
            k++;
        }
    }
    if(m2==1){
        aux6++;
        //H(Hcx)
        for(r=105;r<=128;r++){
            fprintf(fileout," %c%c%c        %lf        %lf        %lf\n",   cell[r].type[0], cell[r].type[1], cell[r].type[2],  cell[r].px, cell[r].py, cell[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c%c\n", k, aux6, cell[r].px, cell[r].py, cell[r].pz, cell[r].type[0], cell[r].type[1], cell[r].type[2]);
            k++;
        }
    }

    if(na>0){
        aux6++;
        //Hidrogenio(Ha)
        for(q=1;q<=na;q++){
            fprintf(fileout," %c%c%c        %lf        %lf        %lf\n",   ha[q].type[0], ha[q].type[1], ha[q].type[2],  ha[q].px, ha[q].py, ha[q].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c%c\n", k, aux6, ha[q].px, ha[q].py, ha[q].pz, ha[q].type[0], ha[q].type[1], ha[q].type[2]);
            k++;
        }
        aux6++;

        //Hidrogenio(Hb)
        for(q=1;q<=na;q++){
            fprintf(fileout," %c%c%c        %lf        %lf        %lf\n",   hb[q].type[0], hb[q].type[1], hb[q].type[2], hb[q].px, hb[q].py, hb[q].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c%c\n", k, aux6, hb[q].px, hb[q].py, hb[q].pz, hb[q].type[0], hb[q].type[1], hb[q].type[2]);
            k++;
        }
	}
    if(n6>0){
        aux6++;
        //Hidroxila(H)
        for(q=1;q<=n6;q++){
            fprintf(fileout," %c%c        %lf        %lf        %lf\n",   h[q].type[0], h[q].type[1],  h[q].px, h[q].py, h[q].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c\n", k, aux6, h[q].px, h[q].py, h[q].pz, h[q].type[0], h[q].type[1]);
            k++;
        }
    }
    if(n8>0){
        aux6++;
        //Hidro(hc)
        for(r=1;r<=n8;r++){
            fprintf(fileout," %c%c        %lf        %lf        %lf\n",   hc[r].type[0], hc[r].type[1],  hc[r].px, hc[r].py, hc[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c\n", k, aux6, hc[r].px, hc[r].py, hc[r].pz, hc[r].type[0], hc[r].type[1]);
            k++;
        }
    }
    if(na>0){
        aux6++;
        //Oxigenio(Oa)
        for(q=1;q<=na;q++){
            fprintf(fileout," %c%c        %lf        %lf        %lf\n",   oa[q].type[0], oa[q].type[1],  oa[q].px, oa[q].py, oa[q].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c\n", k, aux6, oa[q].px, oa[q].py, oa[q].pz, oa[q].type[0], oa[q].type[1]);
            k++;
        }
    }

    //Cellulose Oc
    if(m2==1){
        aux6++;
        //Oxi(Oc)
        for(r=129;r<=144;r++){
            fprintf(fileout," %c%c        %lf        %lf        %lf\n",   cell[r].type[0], cell[r].type[1],  cell[r].px, cell[r].py, cell[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c\n", k, aux6, cell[r].px, cell[r].py, cell[r].pz, cell[r].type[0], cell[r].type[1]);
            k++;
        }
    }
    if(m2==1){
        aux6++;
        //Oxi(Ocx)
        for(r=145;r<=168;r++){
            fprintf(fileout," %c%c%c        %lf        %lf        %lf\n",   cell[r].type[0], cell[r].type[1], cell[r].type[2],  cell[r].px, cell[r].py, cell[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c%c\n", k, aux6, cell[r].px, cell[r].py, cell[r].pz, cell[r].type[0], cell[r].type[1], cell[r].type[2]);
            k++;
        }
    }

    if(n2>0){
        aux6++;
        //Epoxi(Oe)
        for(r=1;r<=n2;r++){
            fprintf(fileout," %c%c        %lf        %lf        %lf\n",   e[r].type[0], e[r].type[1],  e[r].px, e[r].py, e[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c\n", k, aux6, e[r].px, e[r].py, e[r].pz, e[r].type[0], e[r].type[1]);
            k++;
        }
    }
    if(n6>0){
        aux6++;
        //Hidroxila(Oh)
        for(r=1;r<=n6;r++){
            fprintf(fileout," %c%c        %lf        %lf        %lf\n",   o[r].type[0], o[r].type[1],  o[r].px, o[r].py, o[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c\n", k, aux6, o[r].px, o[r].py, o[r].pz, o[r].type[0], o[r].type[1]);
            k++;
        }
    }
    if(n9>0){
        aux6++;
        //Oxi(On)
        for(r=1;r<=n9;r++){
            fprintf(fileout," %c%c        %lf        %lf        %lf\n",   on[r].type[0], on[r].type[1],  on[r].px, on[r].py, on[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c\n", k, aux6, on[r].px, on[r].py, on[r].pz, on[r].type[0], on[r].type[1]);
            k++;
        }
    }
    if(n8>0){
        aux6++;
        //Oxi(Oc1)
        for(r=1;r<=n8;r++){
            fprintf(fileout," %c%c%c        %lf        %lf        %lf\n",   oc1[r].type[0], oc1[r].type[1], oc1[r].type[2],  oc1[r].px, oc1[r].py, oc1[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c%c\n", k, aux6, oc1[r].px, oc1[r].py, oc1[r].pz, oc1[r].type[0], oc1[r].type[1], oc1[r].type[2]);
            k++;
        }
        aux6++;
        //Och(Oc2)
        for(r=1;r<=n8;r++){
            fprintf(fileout," %c%c%c        %lf        %lf        %lf\n",   oc2[r].type[0], oc2[r].type[1], oc2[r].type[2],  oc2[r].px, oc2[r].py, oc2[r].pz);
            fprintf(filedata, "%d 1 %d 0.000000 %lf %lf %lf # %c%c%c\n", k, aux6, oc2[r].px, oc2[r].py, oc2[r].pz, oc2[r].type[0], oc2[r].type[1], oc2[r].type[2]);
            k++;
        }
    }
    //Verificando se o numero total de átomos está certo
    if((k-1)!=all){
        printf("Numero total de atomos incorreto\n");
        printf("%d", k-1-all);
    }else{
        printf("End\n");
    }














    return 0;
}
