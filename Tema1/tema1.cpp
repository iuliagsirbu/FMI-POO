#include<bits/stdc++.h>
using namespace std;
class Autor
{
    private:
        string nume;
        string prenume;
    public:
        Autor()
        {
            //constructor de initializare
        }

        Autor(const string& nume, const string& prenume="")
        {
            //constructor de initializare cu mai multi parametrii
            this->nume = nume; //copiem numele dat ca parametru
            this->prenume = prenume; //copiem prenumele dat ca parametru
        }

        Autor(const Autor &other) 
            : nume(other.nume), prenume(other.prenume)
        {
            //constructorul de copiere pentru Autor
        }

        Autor& operator = (const Autor& other)
        {
            this->nume = other.nume; //copiem numele din obiectul other
            this->prenume = other.prenume;  //copiem prenumele din obiectul other
            return *this;
        }

        ~Autor()
        {
            //destructor
        }
        friend ostream& operator<<(ostream& os, const Autor& autor);
        friend istream& operator>>(istream& is, Autor& autor);
        
        void setNume(const string& nume)
        {
            this->nume = nume;
        }
        void setPrenume(const string& prenume)
        {
            this->prenume = prenume;
        } 
        string getNume()
        {
            return nume;
        }
        string getPrenume()
        {
            return prenume;
        }
};

ostream& operator<<(ostream& os, const Autor& autor)
{
    //operator << pentru Autor
    os<<autor.nume<<" "<<autor.prenume;
    return os;
}

istream& operator>>(istream& is, Autor& autor)
{
    //operator >> pentru Autor
    cout<<"Introduceti datele despre autor: ";
    is>>autor.nume>>autor.prenume;
    return is;
}

class Carte
{
    private:
        int aparitie;
        string titlu;
        int nrAutori;
        vector<Autor> Aut;

    public:
        Carte() 
        {
            //constructor de initializare
        }
        
        Carte(const int& aparitie, const string& titlu, const int& nrAutori, const Autor& a)
        {
            //constructor de initializare cu mai multi parametrii
            this->aparitie = aparitie;
            this->titlu = titlu;
            this->nrAutori = nrAutori;
            this->Aut.push_back(a);
        }

        Carte(const Carte& other)
            : aparitie(other.aparitie), titlu(other.titlu), nrAutori(other.nrAutori), Aut(other.Aut)
        {
            //constructorul de copiere pentru Carte
        }

        Carte& operator=(const Carte& other)
        {
            this->aparitie = other.aparitie;
            this->titlu = other.titlu;
            this->nrAutori = other.nrAutori;
            
            // this->Aut = vector<Autor>(nrAutori);
            // for(int i=0;i<nrAutori;i++)
            //     this->Aut[i] = other.Aut[i];

            this->Aut = vector<Autor>(other.Aut);
            return *this;
        }

        // Carte& operator+=(const Autor& other)
        // {
        //     Aut.push_back(other);
        //     nrAutori = nrAutori+1;
        //     return *this;
        // } 

        ~Carte()
        {
            //destructor
        }

        friend ostream& operator<<(ostream& os, const Carte& carte);
        // friend istream& operator>>(istream& is, Carte& carte);

        void setAparitie(const int& aparitie)
        {
            this->aparitie = aparitie;
        }
        void setTitlu(const string& titlu)
        {
            this->titlu = titlu;
        }
        void setnrAutori(const int& nrAutori)
        {
            this->nrAutori = nrAutori;
        }
        int getAparitie()
        {
            return aparitie;
        }
        string getTitlu()
        {
            return titlu;
        }
        int getnrAutori()
        {
            return nrAutori;
        }

        void modif(const int& pozitie, const string& numeNou)
        {
            Aut[pozitie].setNume(numeNou);
        }
};

ostream& operator<<(ostream& os, const Carte& carte)
{
    //operator << pentru Carte
    os<<carte.aparitie<<" "<<carte.titlu<<" "<<carte.nrAutori<<" ";
    for(int i=0;i<carte.nrAutori;i++)
        os<<carte.Aut[i]<<" ";
    return os;
}

// istream& operator>>(istream& is, Carte& carte)
// {
//     //operator >> pentru Carte
//     cout<<"Introduceti datele despre carte: ";
//     is>>carte.aparitie;
//     getline(is, carte.titlu);
//     is>>carte.nrAutori;
//     carte.Aut.resize(carte.nrAutori);
//     for(int i=0;i<carte.nrAutori;i++)
//     {
//         is>>carte.Aut[i];
//     }
//     return is;
// }

class Detalii
{
    private:
        int isbn;
        Carte car;
    public:
        Detalii()
        {
            //constructor de initializare
        }

        Detalii(const int& isbn, const Carte& car)
        {
            this->isbn = isbn;
            this->car = car;
        }

        ~Detalii()
        {
            //destructor
        }

        int getIsbn()
        {
            return isbn;
        }

        friend ostream& operator<<(ostream& os, const Detalii& detalii);
};

ostream& operator<<(ostream& os, const Detalii& detalii)
{
    //operator << pentru Detalii
    os<<detalii.isbn<<endl<<detalii.car;
    return os;
}

int main()
{
    cout<<"Pentru Autor"<<endl;
    Autor a1("Slavici","Ioan"), a2("Seneca"),a3;
    cin>>a3;
    cout<<a3;
    cout<<endl<<a2<<endl;
    cout<<a1.getNume()<<" "<<a1.getPrenume();

    cout<<endl<<endl<<"Pentru Carte"<<endl;

    Carte c1(1881, "Moara cu noroc", 1, a1);
    cout<<c1<<endl;
    Carte c2;
    c2 = c1;
    cout<<c2<<endl;
    cout<<c2.getTitlu()<<endl;

    cout<<endl<<endl<<"Pentru Detalii"<<endl;
    Detalii d1(1234, c1);
    cout<<d1<<endl<<d1.getIsbn();
    return 0;
}