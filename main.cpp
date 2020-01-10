//Petcu Cristiana Diana, grupa 253
#include <iostream>

using namespace std;

class formular_inscriere
{
protected:
    string nume;
    float medie_bac;
public:
        formular_inscriere();
        formular_inscriere(string, float);//const de initializare cu un nr dat
        formular_inscriere(const formular_inscriere&);//const de copiere
        virtual~formular_inscriere();//destructor
        formular_inscriere& operator=(const formular_inscriere &);
        friend ostream& operator<<(ostream&, formular_inscriere&);
        friend istream& operator>>(istream&, formular_inscriere&);
        virtual void citire();
        virtual void afisare();
};

class formular_id : public formular_inscriere
{
    protected:
    float nota_mate;
public:
    formular_id();
    formular_id(string, float, float);
    formular_id(const formular_id&);
    friend ostream& operator<<(ostream&, formular_id&);
    friend istream& operator>>(istream&, formular_id&);
    void citire();
    void afisare();

};



class formular_fac_2 :public formular_inscriere
{
protected:
    string program_studii;
    float medie_absolvire;
public:
    formular_fac_2();
    formular_fac_2(string, float,string,float);
    formular_fac_2(const formular_fac_2&);
    friend ostream& operator<<(ostream&, formular_fac_2&);
    friend istream& operator>>(istream&, formular_fac_2&);
    void citire();
    void afisare();

};


class dosar
{
protected:
    int nr;
    int cod_leg_if;
    string cod_leg_id;
    string cod_leg_fac2;
public:
    dosar();
    dosar(int, int, string, string);
    dosar(const dosar&);
    friend ostream& operator<<(ostream&, dosar&);
    friend istream& operator>>(istream&, dosar&);
    void citire();
    void afisare();

};
formular_inscriere :: formular_inscriere()
{
    nume="";
    medie_bac=5;
}

formular_inscriere :: formular_inscriere(string num, float medie)
{
   nume=num;
   medie_bac=medie;
}

formular_inscriere :: formular_inscriere(const formular_inscriere& ob)
{
    if(nume!="")
        nume=ob.nume;
    else
        nume="";
    medie_bac=ob.medie_bac;
}
formular_inscriere :: ~formular_inscriere()
{
    cout<<"";
}
formular_inscriere& formular_inscriere :: operator=(const formular_inscriere& ob)
{
    if(this!=&ob)
    {
        nume=ob.nume;
        medie_bac=ob.medie_bac;
    }
    return *this;
}

void formular_inscriere :: citire()
{
    cout<<"Care este numele candidatului?";
    cin>>nume;
    cout<<"Care este media obtinuta la examenul de bac?";
    cin>>medie_bac;

}

void formular_inscriere :: afisare()
{
    cout<<"Numele candidatului este: ";
    cout<<nume;
    cout<<endl<<"Media obtinuta la bac este: ";
    cout<<medie_bac;
}

istream& operator>>(istream& in, formular_inscriere& ob)
{
    cout<<"Care este numele candidatului?";
    in>>ob.nume;
    cout<<"Care este media obtinuta la examenul de bac?";
    in>>ob.medie_bac;


    return in;
}

ostream& operator<<(ostream& out, formular_inscriere& ob)
{
    out<<"Numele candidatului este: ";
    out<<ob.nume;
    out<<endl<<"Media obtinuta la bac este: ";
    out<<ob.medie_bac;

    return out;
}


formular_id :: formular_id()
{
    nota_mate=5;
}

formular_id :: formular_id(string num, float medie, float nota) : formular_inscriere(num, medie)
{
    nota_mate=nota;
}

formular_id :: formular_id(const formular_id& ob)
{
   nume=ob.nume;
   medie_bac=ob.medie_bac;
   nota_mate=ob.nota_mate;
}

/*formular_id :: ~formular_id()
{
    cout<<"Distrugere obiect";
}*/

/*formular_id& formular_id :: operator=(const formular_id& ob)
{
    if(this!=&ob)
    {
    nume=ob.nume;
    medie_bac=ob.medie_bac;
   nota_mate=ob.nota_mate;
    }
    return *this;
}*/

void formular_id :: citire()
{
    cout<<"Care este numele candidatului?";
    cin>>nume;
    cout<<"Care este media obtinuta la examenul de bac?";
    cin>>medie_bac;
    cout<<"Care este nota la mate?";
    cin>>nota_mate;
}

void formular_id :: afisare()
{
    cout<<"Numele candidatului este: ";
    cout<<nume;
    cout<<endl<<"Media obtinuta la bac este: ";
    cout<<medie_bac;
    cout<<endl<<"Nota la mate este: ";
    cout<<nota_mate;
}



formular_fac_2 :: formular_fac_2()
{
    program_studii="";
    medie_absolvire=5;
}

formular_fac_2 :: formular_fac_2(string num, float medie, string prog, float med) : formular_inscriere(num, medie)
{
    program_studii=prog;
    medie_absolvire=med;
}

formular_fac_2 :: formular_fac_2(const formular_fac_2& ob)
{
   nume=ob.nume;
   medie_bac=ob.medie_bac;
   program_studii=ob.program_studii;
   medie_absolvire=ob.medie_absolvire;
}

/*formular_fac_2 :: ~formular_fac_2()
{
    cout<<"Distrugere obiect";
}*/

/*formular_fac_2& formular_fac_2 :: operator=(const formular_fac_2& ob)
{
    if(this!=&ob)
    {
   nume=ob.nume;
   medie_bac=ob.medie_bac;
   program_studii=ob.program_studii;
   medie_absolvire=ob.medie_absolvire;
    }
    return *this;
}*/

void formular_fac_2 :: citire()
{
    cout<<"Care este numele candidatului?";
    cin>>nume;
    cout<<"Care este media obtinuta la examenul de bac?";
    cin>>medie_bac;
    cout<<"Care este programul de studii?";
    cin>>program_studii;
    cout<<"Care este media de absolvire?:";
    cin>>medie_absolvire;
}

void formular_fac_2 :: afisare()
{
    cout<<"Numele candidatului este: ";
    cout<<nume;
    cout<<endl<<"Media obtinuta la bac este: ";
    cout<<medie_bac;
    cout<<endl<<"Programul de studii este: ";
    cout<<program_studii;
    cout<<endl<<"Media de absolvire este";
    cout<<medie_absolvire;
}
/*

dosar :: dosar()
{
    nr_inregistrare=1;
    cod_legitimatie=0;
    cod_leg_id="";
    cod_leg_fac2="";
}

dosar :: dosar(int a, float b, string c, string c)
{
   nume=num;
   medie_bac=medie;
}

formular_inscriere :: formular_inscriere(const formular_inscriere& ob)
{
    if(nume!="")
        nume=ob.nume;
    else
        nume="";
    medie_bac=ob.medie_bac;
}
formular_inscriere :: ~formular_inscriere()
{
    cout<<"Distrugere obiect";
}
formular_inscriere& formular_inscriere :: operator=(const formular_inscriere& ob)
{
    if(this!=&ob)
    {
        nume=ob.nume;
        medie_bac=ob.medie_bac;
    }
    return *this;
}

void formular_inscriere :: citire()
{
    cout<<"Care este numele candidatului?";
    cin>>nume;
    cout<<"Care este media obtinuta la examenul de bac?;
    cin>>medie_bac;

}

void formular_inscriere :: afisare()
{
    cout<<"Numele candidatului este: ";
    cout<<nume;
    cout<<endl<<"Media obtinuta la bac este: ";
    cout<<medie_bac;
}

istream& operator>>(istream& in, formular_inscriere& ob)
{
    cout<<"Care este numele candidatului?";
    in>>ob.nume;
    cout<<"Care este media obtinuta la examenul de bac?;
    in>>ob.medie_bac;


    return in;
}

ostream& operator<<(ostream& out, formular_inscriere& ob)
{
    out<<"Numele candidatului este: ";
    out<<nume;
    out<<endl<<"Media obtinuta la bac este: ";
    out<<medie_bac;

    return out;
}

*/


int main()
    {
        int cand;
        cout<<"Introduceti nr de candidati: ";
        cin>>cand; int i;
        formular_inscriere a,v[100];
        formular_id b,w[100];
        formular_fac_2 c,q[100];
        int nr1=1,nr2=1,nr3=1;
        for(i=1;i<=cand;i++)
        {
            cout<<"Candidatul nr: "<<i;
            cout<<endl<<"Introduceti 1 pentru invatamant frecventa, 2 pentru invatamant distanata, 3 pt a doua fac"<<endl;
            int x;
            cin>>x;
            if(x==1)
            {
                 a.citire(); v[nr1]=a; nr1++;
            }

            if(x==2)
                b.citire(); w[nr2]=b; nr2++;
            if(x==3)
                c.citire(); q[nr3]=c; nr3++;
        }
nr1--;nr2--;nr3--;
        cout<<endl<<"Candidatii cu invatamant frecventa:"<<endl;
        if(nr1!=1)
        {for(i=1;i<=nr1;i++)
            v[i].afisare();}

        cout<<endl<<"Candidatii cu invatamant distanta:"<<endl;
        if(nr2!=1)
        {for(i=1;i<=nr2;i++)
            w[i].afisare();}

        cout<<endl<<"Candidatii cu a doua fac:"<<endl;
        if(nr3!=1)
        {for(i=1;i<=nr3;i++)
            q[i].afisare();}

        return 0;
    }



