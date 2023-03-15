///Proiectul nr.1
///Constantinescu Antonio-Gabriel
///Grupa 211
///Semi-grupa a doua

/* Nr. 5

Se considera urmatoarele clase:

Data ce contine atributele: zi(int), luna(sir de caractere de lungime fixa 20), an(int)

Medicament ce contine atributele: denumire(sir de caractere de lungime variabila), pret(float), fabricat(Data).

Farmacie ce contine atributele: denumire(sir de caractere de lungime fixa 50), nrMedicamente(int), Med(vector de obiecte de tip Medicament).



Definiti clasele si completati-le cu metode si supraincarcari de operatori pentru a permite in functia main() urmatoarele operatii:

Data d(1,”ianuarie”,2018);

Medicament m1("Parasinus",9.5, 10), m2("Aspirina", d),m3;

cin>>m3;

cout<<m1;

if (m1<m2) cout<<”m1 este fabricat inaintea m2”;

else cout<<”m2 este fabricat inaintea m1”;

Farmacie f1(“Farmac”);

f1 += m1; //adaugare medicament m1 in lista de medicamente a farmaciei

f1 = m2 + f1; //adaugare medicament m2 in lista de medicamente a farmaciei

Farmacie f2 = f1;

cout<<f2;	//afisarea tuturor medicamentelor

*/
#include<conio.h>
#include<iostream>
#include<fstream>
#include<cstring>


using namespace std;

void meniu()
{
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|  apasa 1 pentru  |  apasa 2 pentru  |  apasa 3 pentru   |  apasa 4 pentru   |  apasa 0 pentru |"<<endl;
    cout<<"|  a rula cerinta  |  cin o farmacie  | cin un medicament | a compara 2 med...|       exit      |"<<endl;
    cout<<"|-----------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|-----------------------------------*dupa apasa si enter :)*------------------------------------|"<<endl;
    cout<<"|---------------------------------------------<3------------------------------------------------|"<<endl;


}

int crearenr(int x[255],int c){
int p,q,i;
q=0;
p=1;

for(i=0;i<c-1;i++)
    p=p*10;

for(i=0;i<=c;i++){
        q=q+x[i]*p;
    p=p/10;
}

return q;

}

int convertint(char x)
{
    int r1,s;
   // char *aux;
    char b1;

    b1=x;
    r1=b1-'0';
    s=r1;

    return s;

}

int cuvtonr(char x[255]){

int v[255],c;
c=strlen(x);
    for(int i=0;i<strlen(x);i++){
        v[i]=convertint(x[i]);

}
    return crearenr(v,c);
}




int convert(char y,char x='0')
{
    int r1,r2,s;
    char *aux;
    char b1,b2;

    b1=x;
    b2=y;
    r1=b1-'0';
    r2=b2-'0';
    s=r1*10+r2;

    return s;

}

char* schimb(char y,char x='0')
{
    int r1,r2,s;
    char a[13][21];
    char *aux;
    char b1,b2;

    strcpy(a[0],"ianuarie");
    strcpy(a[1],"februarie");
    strcpy(a[2],"martie");
    strcpy(a[3],"aprilie");
    strcpy(a[4],"mai");
    strcpy(a[5],"iunie");
    strcpy(a[6],"iulie");
    strcpy(a[7],"august");
    strcpy(a[8],"septembrie");
    strcpy(a[9],"octombrie");
    strcpy(a[10],"noiembrie");
    strcpy(a[11],"decembrie");

    b1=x;
    b2=y;
    r1=b1-'0';
    r2=b2-'0';
    s=r1*10+r2;

    aux= new char (strlen(a[s-1])+1);

    strcpy(aux,a[s-1]);
    return aux;

}

int verific(char x[21])
{
    int i,aa;
    char a[13][21];
    strcpy(a[0],"ianuarie");
    strcpy(a[1],"februarie");
    strcpy(a[2],"martie");
    strcpy(a[3],"aprilie");
    strcpy(a[4],"mai");
    strcpy(a[5],"iunie");
    strcpy(a[6],"iulie");
    strcpy(a[7],"august");
    strcpy(a[8],"septembrie");
    strcpy(a[9],"octombrie");
    strcpy(a[10],"noiembrie");
    strcpy(a[11],"decembrie");


    for (i=0; i<=11; i++)
    {
        if(strcmp(x,a[i])==0)
        {
            aa=i+1;
            return aa;
        }
    }

    return 0;

}

int verific(char x[21],char y[21])
{
    int i,aa,bb;
    char a[13][21];
    strcpy(a[1],"ianuarie");
    strcpy(a[2],"februarie");
    strcpy(a[3],"martie");
    strcpy(a[4],"aprilie");
    strcpy(a[5],"mai");
    strcpy(a[6],"iunie");
    strcpy(a[7],"iulie");
    strcpy(a[8],"august");
    strcpy(a[9],"septembrie");
    strcpy(a[10],"octombrie");
    strcpy(a[11],"noiembrie");
    strcpy(a[12],"decembrie");


    for (i=0; i<=12; i++)
    {
        if(strcmp(x,a[i])==0)
            aa=i;
    }
    for (i=0; i<=12; i++)
    {
        if(strcmp(y,a[i])==0)
            bb=i;
    }


    if(aa<bb) return -1;
    if(aa==bb) return 0;
    if(aa>bb) return 1;

}
class Data
{
    int zi,an;
    char* luna;

public:
    Data();
    void ani(int);
    Data(int z,const char* l,int a);
    Data(const Data&);
    ~Data();
    Data& operator=(const Data&);
    friend istream& operator>>(istream&,Data&);
    friend ostream& operator<<(ostream&,Data&);
    int get_zi()
    {
        return zi;
    }
    char* get_luna()
    {
        return luna;
    }
    int get_an()
    {
        return an;
    }

    void set_luna(char*l)
    {
        strcpy(luna,l);
    }

};

class Medicament
{

    char* denumire;
    float pret;
    Data data;

public:
    Medicament();
    Medicament(char* n,float p,Data d);
    Medicament(char* n,float p,int d);
    Medicament(char* n,Data d);
    Medicament(const Medicament&);
    //  ~Medicament();
    Medicament& operator=(const Medicament&);
    friend int operator<( Medicament&, Medicament&);
    friend istream& operator>>(istream&,Medicament&);
    friend ostream& operator<<(ostream&,Medicament&);
    int get_zi()
    {
        return data.get_zi();
    }
    char* get_luna()
    {
        return data.get_luna();
    }
    int get_an()
    {
        return data.get_an();
    }
    char* get_denumire()
    {
        return denumire;
    }


};

class Farmacie
{

    char nu[50];
    int nrmed;
    Medicament med[501];

public:
    Farmacie();
    Farmacie(char x[50],int nrmm,Medicament medo[500]);
    Farmacie(char x[50]);
    Farmacie(const Farmacie&);
    ~Farmacie();
    Farmacie& operator=(const Farmacie&);
    Farmacie& operator+=(Medicament&);
    friend Farmacie& operator+(Medicament&,Farmacie&);
    friend istream& operator>>(istream&,Farmacie&);
    friend ostream& operator<<(ostream&,Farmacie&);


};

int main()
{


    char x;



    while(true)
    {
        meniu();
        cin>>x;


        if (x>'4' || x<'0')
        {
            cout<<"Nu ai ales o optiune existenta. Mai incearca o data"<<endl;

        }


        else if (x=='1')
        {
            ///Cerinta
            char gggg=34;
            cout<<"                                         Cerinta este:"<<endl<<endl;
            cout<<"  Nr. 5    Definiti clasele si completati-le cu metode si supraincarcari de operatori "<<endl<<"            pentru a permite in functia main() urmatoarele operatii:"<<endl<<endl;
            cout<<"            Data d(1,"<<gggg<<"ianuarie"<<gggg<<",2018);"<<endl<<endl;
            cout<<"            Medicament m1("<<gggg<<"Parasinus"<<gggg<<",9.5, 10), m2("<<gggg<<"Aspirina"<<gggg<<", d),m3;"<<endl;
            cout<<"            cin>>m3;"<<endl<<endl;
            cout<<"            cout<<m1;"<<endl<<endl;
            cout<<"            if (m1<m2) cout<<"<<gggg<<"m1 este fabricat inaintea m2"<<gggg<<";"<<endl;
            cout<<"            else cout<<"<<gggg<<"m2 este fabricat inaintea m1"<<gggg<<";"<<endl<<endl;
            cout<<"            Farmacie f1("<<gggg<<"Farmac"<<gggg<<");"<<endl<<endl;
            cout<<"            f1 += m1; //adaugare medicament m1 in lista de medicamente a farmaciei"<<endl<<endl;
            cout<<"            f1 = m2 + f1; //adaugare medicament m2 in lista de medicamente a farmaciei"<<endl<<endl;
            cout<<"            Farmacie f2 = f1;"<<endl<<endl;
            cout<<"            cout<<f2;	//afisarea tuturor medicamentelor"<<endl<<endl;





            Data d(1,"ianuarie",2018);

            Medicament m1("Parasinus",9.5, 10), m2("Aspirina", d),m3;
            cin>>m3;

            cout<<m1;

            if (m1<m2) cout<<"m1 este fabricat inaintea m2"<<endl;

            else cout<<"m2 este fabricat inaintea m1"<<endl;

            Farmacie f1("Farmac");

            f1 += m1; //adaugare medicament m1 in lista de medicamente a farmaciei

            f1 = m2 + f1; //adaugare medicament m2 in lista de medicamente a farmaciei

            Farmacie f2 = f1;

            cout<<f2;	//afisarea tuturor medicamentelor


        }
        /// cin Farmacie
        else if (x=='2')
        {
            Farmacie f;
            cin>>f;
            cout<<f;

        }
        /// cin Medicament
        else if (x=='3')
        {
            Medicament a;
            cin>>a;
            cout<<a;
        }
        /// Comparare
        else if (x=='4')
        {
            Medicament a,b;
            cout<<"Primul medicament:"<<endl;
            cin>>a;
            cout<<"Al doilea medicament:"<<endl;
            cin>>b;

            if (a<b) cout<<" Medicamentul "<<a.get_denumire()<<" este fabricat inaintea medicamentului "<<b.get_denumire()<<endl;

            else cout<<"Medicamentul "<<b.get_denumire()<<" este fabricat inaintea medicamentului "<<a.get_denumire()<<endl;
        }


        /// Exit
        else if (x=='0')
        {
            return 0;
        }
    }
}



///Data

Data::Data()
{
    zi=1;
    luna = new char[69];
    strcpy(luna,"ianuarie");
    an=2017;
}

Data::~Data()
{
    delete[] luna;
}

Data::Data(const Data& ob)
{
    zi=ob.zi;
    luna = new char[strlen(ob.luna)+1];
    strcpy(luna,ob.luna);
    an=ob.an;
}

Data& Data::operator=(const Data& ob)
{
    if(this!=&ob)
    {
        zi=ob.zi;
        luna = new char[strlen(ob.luna)+1];
        strcpy(luna,ob.luna);
        an=ob.an;
    }
    return *this;
}

void Data::ani(int z)
{
    this->an=this->an-z;
}


Data::Data(int z, const char* l,int a)
{
    zi=z;
    luna = new char[strlen(l)+1];
    strcpy(luna,l);
    an=a;
}

istream& operator>>(istream& in,Data& s)
{
    cout<<"Adauga o data de fabricare in format (zi ,enter, luna, enter, an, enter)"<<endl;

    char aux[255],auxzi[3];
    int kk,zz;
    cout<<"ziua:";
//   in>>s.zi;
    in>>auxzi;
    if (strlen(auxzi)==1)
    {
        char l1;
        l1=auxzi[0];
        s.zi=convert(l1);
    }

    if (strlen(auxzi)==2)
    {
        char l1,l2;
        l1=auxzi[0];
        l2=auxzi[1];
        s.zi=convert(l2,l1);

    }
    if (strlen(auxzi)>=3)
    {

        s.zi=100;

    }


    while (s.zi>31 || s.zi<1)
    {
        cout<<"Nice try, dar o luna are cel mult 31 de zile, Mai incearca o data"<<endl;
        cout<<"ziua:";
        in>>auxzi;
        if (strlen(auxzi)==1)
        {
            char l1;
            l1=auxzi[0];
            s.zi=convert(l1);
        }

        if (strlen(auxzi)==2)
        {
            char l1,l2;
            l1=auxzi[0];
            l2=auxzi[1];
            s.zi=convert(l2,l1);

        }
        if (strlen(auxzi)>=3)
        {

            s.zi=100;
        }
    }
    cout<<"luna:";
    in>>aux;
    if (strlen(aux)==1)
    {
        char l1;
        l1=aux[0];
        strcpy(aux,schimb(l1));
    }

    if (strlen(aux)==2)
    {
        char l1,l2;
        l1=aux[0];
        l2=aux[1];
        strcpy(aux,schimb(l2,l1));
    }

    while(s.zi==31 && (verific(aux)==4 || verific(aux)==6 || verific(aux)==9 || verific(aux)==11))
    {
        cout<<"Nice try, dar luna asta nu are 31 de zile, Mai incearca o data"<<endl;
        cout<<"Apasa 1 daca vrei sa adaugi iar ziua si 2 daca vrei doar luna, Mai incearca o data"<<endl;
        in>>kk;
        if(kk==1)
        {
            cout<<"ziua:";
            in>>auxzi;
            if (strlen(auxzi)==1)
            {
                char l1;
                l1=auxzi[0];
                s.zi=convert(l1);
            }

            if (strlen(auxzi)==2)
            {
                char l1,l2;
                l1=auxzi[0];
                l2=auxzi[1];
                s.zi=convert(l2,l1);

            }
            if (strlen(auxzi)>=3)
            {

                s.zi=100;
            }
            while (s.zi>31 || s.zi<1)
            {
                cout<<"Nice try, dar o luna are cel mult 31 de zile, Mai incearca o data"<<endl;
                in>>auxzi;
                if (strlen(auxzi)==1)
                {
                    char l1;
                    l1=auxzi[0];
                    s.zi=convert(l1);
                }

                if (strlen(auxzi)==2)
                {
                    char l1,l2;
                    l1=auxzi[0];
                    l2=auxzi[1];
                    s.zi=convert(l2,l1);

                }
                if (strlen(auxzi)>=3)
                {

                    s.zi=100;
                }
            }
            cout<<"luna:";
            in>>aux;
            if (strlen(aux)==1)
            {
                char l1;
                l1=aux[0];
                strcpy(aux,schimb(l1));
            }

            if (strlen(aux)==2)
            {
                char l1,l2;
                l1=aux[0];
                l2=aux[1];
                strcpy(aux,schimb(l2,l1));
            }
        }
        else if(kk==2)
        {
            cout<<"luna:";
            in>>aux;
            if (strlen(aux)==1)
            {
                char l1;
                l1=aux[0];
                strcpy(aux,schimb(l1));
            }

            if (strlen(aux)==2)
            {
                char l1,l2;
                l1=aux[0];
                l2=aux[1];
                strcpy(aux,schimb(l2,l1));
            }
        }
    }
    while(s.zi>28 && verific(aux)==2)
    {
        cout<<"Nice try, dar luna asta nu are 28 de zile, Mai incearca o data"<<endl;
        cout<<"Apasa 1 daca vrei sa adaugi iar ziua si 2 daca vrei doar luna, Mai incearca o data"<<endl;
        in>>kk;
        if(kk==1)
        {
            cout<<"ziua:";
            in>>auxzi;
            if (strlen(auxzi)==1)
            {
                char l1;
                l1=auxzi[0];
                s.zi=convert(l1);
            }

            if (strlen(auxzi)==2)
            {
                char l1,l2;
                l1=auxzi[0];
                l2=auxzi[1];
                s.zi=convert(l2,l1);

            }
            if (strlen(auxzi)>=3)
            {

                s.zi=100;
            }
            while (s.zi>31 || s.zi<1)
            {
                cout<<"Nice try, dar o luna are cel mult 31 de zile, Mai incearca o data"<<endl;
                in>>auxzi;
                if (strlen(auxzi)==1)
                {
                    char l1;
                    l1=auxzi[0];
                    s.zi=convert(l1);
                }

                if (strlen(auxzi)==2)
                {
                    char l1,l2;
                    l1=auxzi[0];
                    l2=auxzi[1];
                    s.zi=convert(l2,l1);

                }
                if (strlen(auxzi)>=3)
                {

                    s.zi=100;
                }
            }
            cout<<"luna:";
            in>>aux;
            if (strlen(aux)==1)
            {
                char l1;
                l1=aux[0];
                strcpy(aux,schimb(l1));
            }

            if (strlen(aux)==2)
            {
                char l1,l2;
                l1=aux[0];
                l2=aux[1];
                strcpy(aux,schimb(l2,l1));
            }
        }
        else if(kk==2)
        {
            cout<<"luna:";
            in>>aux;
            if (strlen(aux)==1)
            {
                char l1;
                l1=aux[0];
                strcpy(aux,schimb(l1));
            }

            if (strlen(aux)==2)
            {
                char l1,l2;
                l1=aux[0];
                l2=aux[1];
                strcpy(aux,schimb(l2,l1));
            }
        }
    }
    while(verific(aux)==0)
    {
        cout<<"Nice try, dar luna asta nu exista, Mai incearca o data"<<endl;
        cout<<"luna:";
        in>>aux;
        if (strlen(aux)==1)
        {
            char l1;
            l1=aux[0];
            strcpy(aux,schimb(l1));
        }

        if (strlen(aux)==2)
        {
            char l1,l2;
            l1=aux[0];
            l2=aux[1];
            strcpy(aux,schimb(l2,l1));
        }
    }
    s.luna= new char[strlen(aux)+1];
    strcpy(s.luna,aux);

    cout<<"anul:";
        int c,r,ok,oko,virgula;
     do{
    in>>aux;
    c=strlen(aux);
        oko=1;
    for(int i=0;i<1;i++){
        if(aux[i]=='-' && strlen(aux)>1)
            {
            oko=0;
            virgula=i;
            strcpy(aux+virgula,aux+virgula+1);
            virgula=c-virgula-1;
            }
      }

    c=strlen(aux);

    ok=1;
    for(int i=0;i<c;i++){
        if(isdigit(aux[i])==0)
            ok=0;
    }

    if(ok==1)
    {
        r=cuvtonr(aux);
    }

    if(oko==0){

        r=-r;
    }

    if(r>2022 || r==0)
    {
        //cout<<"Nice try, dar suntem abia in 2022, Mai incearca o data"<<endl;
            ok=0;
    }

        if(ok==0){
            cout<<"Nu ai introdus un numar valid. Mai incearca o data: ";

                    }

       }while(ok==0);



    s.an=r;



    return in;
}

ostream& operator<<(ostream& out,Data& s)
{
    out<<"Data de fabricare este: ";
    if(s.an>0)
        out<<s.zi<<" "<<s.luna<<" "<<s.an<<endl;
    else
        out<<s.zi<<" "<<s.luna<<" "<<s.an*-1<<" I.Hr"<<endl;
    return out;
}

///Medicament

Medicament::Medicament()
{
    this->denumire=new char[255];
    denumire="";
    pret=0;
    this->data=data;
}

Medicament::Medicament(char* n,float p,Data d)
{
    denumire = new char [strlen(n)+1];
    strcpy(denumire,n);
    pret=p;
    data=d;
}

Medicament::Medicament(char*n,float p, int d)
{
    denumire = new char [strlen(n)+1];
    strcpy(denumire,n);
    pret=p;
    data.ani(d);
}

Medicament::Medicament(char* n,Data d)
{
    denumire = new char [strlen(n)+1];
    strcpy(denumire,n);
    pret=0;
    data=d;
}

Medicament::Medicament(const Medicament&ob)
{
    denumire= new char[strlen(ob.denumire)+1];
    strcpy(denumire,ob.denumire);
    pret=ob.pret;
    data=ob.data;
}
/*
Medicament::~Medicament()
{
    delete[] denumire;

}
*/
Medicament& Medicament::operator=(const Medicament& ob)
{

    if(this!=&ob)
    {
        denumire = new char[strlen(ob.denumire)+1];
        pret=ob.pret;
        strcpy(denumire,ob.denumire);
        data=ob.data;
    }
    return *this;
}

istream& operator>>(istream& in,Medicament& s)
{
    char aux[255];
    int auxi[255],r,c,virgula;
    bool ok,oko;
    float floo;

    cout<<"Adauga numele Medicamentului si enter: ";
    in>>aux;
    if(aux[0]>='a' && aux[0]<='z')
        aux[0]=aux[0]-32;

    s.denumire= new char[strlen(aux)+1];
    strcpy(s.denumire,aux);
    cout<<"Adauga pretul medicamentului in lei si enter: ";
    do{
    in>>aux;
    c=strlen(aux);


    oko=1;
    for(int i=0;i<c;i++){
        if(aux[i]=='.' && strlen(aux)>2)
            {
            oko=0;
            virgula=i;
            strcpy(aux+virgula,aux+virgula+1);
            virgula=c-virgula-1;
            }
      }
    c=strlen(aux);

    //if(oko!=0){

    ok=1;
    for(int i=0;i<c;i++){
        if(isdigit(aux[i])==0)
            ok=0;
    }
    if(ok==0){
    cout<<"Nu ai introdus un pret valid. Mai incearca o data:";
    //in>>aux;
            }
    else
    {
        r=cuvtonr(aux);
    }

       }while(ok==0);
        floo=r;
    if(oko==0){

        for(int i=0;i<virgula;i++)
            floo=floo/10;
    }



    s.pret=floo;

    in>>s.data;
    return in;
}

ostream& operator<<(ostream& out,Medicament& s)
{
    out<<"* ";
    out<<s.denumire<<". ";
    if(s.pret>0)
    {
        out<<"Pretul este: ";
        out<<s.pret<<" ";
        if(s.pret>1)
            out<<"lei.";
        if(s.pret==1)
            out<<"leu.";
    }
    else
    {
        out<<"Este gratis.";
    }
    out<<" "<<s.data;
    out<<"-------------------------------------------------------------------------------------------------"<<endl;
    return out;
}

int operator<(Medicament& m1,Medicament& m2)
{
    if (m1.get_an()>m2.get_an()) return false;
    if(m1.get_an()<m2.get_an()) return true;
    if(verific(m1.get_luna(),m2.get_luna())<0) return 1;
    if(verific(m1.get_luna(),m2.get_luna())>0) return 0;
    if(m1.get_zi()<m2.get_zi())return 1;
    if(m1.get_zi()>=m2.get_zi())return 0;
}

///Farmacie

Farmacie::Farmacie()
{
    strcpy(nu,"");
    nrmed=0;
}

Farmacie::Farmacie(const Farmacie& ob)
{

    strcpy(nu,ob.nu);
    nrmed=ob.nrmed;
    for(int i = 1; i<=ob.nrmed; i ++)
    {
        med[i] = ob.med[i];
    }
}

Farmacie::~Farmacie()
{
    strcpy(nu,"");
    nrmed=0;
}

Farmacie& Farmacie::operator=(const Farmacie& ob)
{
    if(this!=&ob)
    {

        strcpy(nu,ob.nu);
        nrmed=ob.nrmed;
        for(int i = 1; i<=nrmed; i ++)
        {
            med[i] = ob.med[i];
        }
    }
    return *this;
}

Farmacie::Farmacie(char x[50],int nrmm,Medicament medo[500])
{
    strcpy(nu,x);
    nrmed=nrmm;
    for(int i = 1; i<=nrmed; i++)
    {
        med[i] = medo[i];
    }
}

Farmacie::Farmacie(char x[50])
{
    strcpy(nu,x);
    nrmed=0;
}

Farmacie& Farmacie::operator+=(Medicament &ob)
{
    nrmed++;
    med[nrmed]=ob;
}

Farmacie& operator+(Medicament& m,Farmacie& ob)
{
    ob.nrmed++;
    ob.med[ob.nrmed]=m;
    return ob;
}

istream& operator>>(istream& in,Farmacie& s)
{
    char aux[255];
    int c,r;
    bool ok;
    cout<<"Adauga numele Farmaciei si enter: ";
    in>>aux;
    if(aux[0]>='a' && aux[0]<='z')
        aux[0]=aux[0]-32;
    strcpy(s.nu,aux);
    cout<<"Adauga cate Medicamente are si enter: ";
    //in>>s.nrmed;

        do{
    in>>aux;
    c=strlen(aux);

    ok=1;
    for(int i=0;i<c;i++){
        if(isdigit(aux[i])==0)
            ok=0;
    }
    if(ok==0){
    cout<<"Nu ai introdus un numar valid. Mai incearca o data:";

            }
    else
    {
        r=cuvtonr(aux);
    }

       }while(ok==0);
    s.nrmed=r;

    for(int i=1; i<=s.nrmed; i++)
        in>>s.med[i];
    return in;

}

ostream& operator<<(ostream& out,Farmacie& s)
{
    out<<"-------------------------------------------------------------------------------------------------"<<endl;
    out<<"                               Farmacia ";
    out<<s.nu<<" "<<endl;
    if (s.nrmed!=0)
    {
        out<<"                 are ";
        out<<s.nrmed;
        if (s.nrmed>1)
        {
            out<<" medicamente,";
            out<<" iar medicamentele sunt: "<<endl<<endl;
        }
        if (s.nrmed==1)
        {
            out<<" medicament,";
            out<<" iar medicamentul este: "<<endl<<endl;
        }
    }
    if (s.nrmed==0)
    {
        out<<"                             nu are medicamente"<<endl<<endl;;
    }
    for(int i=1; i<=s.nrmed; i++)
        out<<s.med[i];
    out<<endl;
    return out;

}
///sfarsit
