#include <bits/stdc++.h>
#include "joc.h"
using namespace std;

//clasa la fel ca librarie, dar ce foloseste un vector de tip JocMagazin in loc de Joc
class Magazin{
private:
    int numarJocuri;
    vector<JocMagazin> jocuriMagazin;

    void sortareJocuri() {
        int i, j, n = numarJocuri;
        bool t;
        for (i=0; i < n-1; i++) {
            t=0;
            for (j=0; j < n-i-1; j++) {
                if (jocuriMagazin[j].getId() > jocuriMagazin[j+1].getId()) {
                    swap(jocuriMagazin[j], jocuriMagazin[j+1]);
                    t=1;
                }
            }
            if (t == 0)
                break;
        }
    }

public:
    //constructor
    Magazin(const vector<JocMagazin>& jocuri) : jocuriMagazin{jocuri}, numarJocuri{jocuri.size()} {}

    //copy constructor
    Magazin(const Magazin& other) : numarJocuri(other.numarJocuri), jocuriMagazin(other.jocuriMagazin) {}

    //= operator
    Magazin& operator=(const Magazin& other) {
        if (this != &other) {
            numarJocuri = other.numarJocuri;
            jocuriMagazin = other.jocuriMagazin;
        }
        return *this;
    }

    //getters
    int getNumarJocuri() const {
        return numarJocuri;
    }

    vector<JocMagazin> getJocuriMagazin() const {
        return jocuriMagazin;
    }

    //setter
    void setJocuriMagazin(const vector<JocMagazin>& jocuriNou) {
        jocuriMagazin = jocuriNou;
        numarJocuri = jocuriMagazin.size();
        sortareJocuri();
    }

    //metode specifice clasei magazin
    //acestea sunt aceleasi ca la librarie, dar modificate sa mearga cu JocMagazin
    //adauga un joc nou in librarie

    void adaugaJoc(const JocMagazin& joc) {
        jocuriMagazin.push_back(joc);
        numarJocuri++;
        sortareJocuri();
    }

    //sterge un joc din librarie doar dupa nume
    void stergeJoc(const string numeJoc) {
        for (int i=0; i<numarJocuri; i++) {
            if (jocuriMagazin[i].getNume() == numeJoc) {
                for (int j=i; j<numarJocuri-1; j++) {
                    jocuriMagazin[j] = jocuriMagazin[j+1];
                }
                numarJocuri--;
                break;
            }
        }
        sortareJocuri();
    }

    //afiseaza toate jocurile in ordinea id-ului
    void afiseazaJocuri() {
        cout<<"Librarie jocuri:\n";
        for (int i=0; i<numarJocuri; i++) {
            if (jocuriMagazin[i].getPret() > 0)
                cout<<jocuriMagazin[i].getNume()<<" | Data lansarii: "<<jocuriMagazin[i].getDataLansarii()<<
                " | Pretul jocului: "<<jocuriMagazin[i].getPret()<<" euro | ID: "<<
                jocuriMagazin[i].getId()<<'\n';
            else
                cout<<jocuriMagazin[i].getNume()<<" | Data lansarii: "<<jocuriMagazin[i].getDataLansarii()<<
                " | Pretul jocului: Gratis | ID: "<<
                jocuriMagazin[i].getId()<<'\n';
        }
    }

    //schimba detaliile unui joc
    void actualizeazaDetaliiJoc(const string numeJoc, const int idNou, const string dataLansariiNou, const double pretNou) {
        for (int i=0; i<numarJocuri; i++) {
            if (jocuriMagazin[i].getNume() == numeJoc) {
                jocuriMagazin[i].setDataLansarii(dataLansariiNou);
                jocuriMagazin[i].setId(idNou);
                jocuriMagazin[i].setPret(pretNou);
                break;
            }
        }
        sortareJocuri();
    }

    JocMagazin getJocByName(string numeJoc) {
        for (int i=0; i<numarJocuri; i++) {
            if (jocuriMagazin[i].getNume() == numeJoc) {
                return jocuriMagazin[i];
            }
        }
    
    }

};

int test3() {
    JocMagazin joc1("GTA V", 1, "17.09.2013", 59.99);
    JocMagazin joc2("Cyberpunk 2077", 2, "10.12.2020", 49.99);
    JocMagazin joc3("CS:GO", 3, "21.08.2012", 20);
    Magazin magazin({joc1, joc2, joc3});
    magazin.adaugaJoc(JocMagazin("Valorant", 4, "2.06.2020", 0.0));
    magazin.stergeJoc("GTA V");
    cout << magazin.getNumarJocuri() << endl;
    magazin.afiseazaJocuri();
    magazin.actualizeazaDetaliiJoc("CS:GO", 1, "21.08.2012", 30.00);
    magazin.afiseazaJocuri();
    return 0;
}