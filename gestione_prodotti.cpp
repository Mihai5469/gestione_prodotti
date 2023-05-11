// gestione_prodotti.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//Mihai Iachimovschi
//10/05/2023
//programma che gestisce gli prodotti del supermercato

#include <iostream>
#include <string>

using namespace std;

struct date {
    int giorno = 0;
    int mese = 0;
    int anno = 0;
} ;

struct prodotto {
    string nome;
    string tipo;
    date scadenza;
    float prezzo_vendita = 0;
    int quantita = 0;
    float costo = 0;

};

void menu();
void ins_nome(string& n);
void ins_tipo(string& t);
void ins_costo(float& c);
void ins_quantita(int& q);
void ins_prezzo(float& pr);
void ins_data_scad(date& d);

void ins_prodotto(prodotto& p);                 //Inserisci un prodotto

void viz_lst_prod(prodotto p[], int l);      //vizualizza tutti prodotti
void viz_prodotto(prodotto p[], int l);          //cerca prodotto specifico

int main()
{
    prodotto p[100];
    bool chiudi = false;
    int opt = 0;
    int n = 0;

    while (!chiudi) {
        menu();
        cout << "\nInserisci opzione:\t";
        cin >> opt;
        

        switch (opt)
        {
        case 0:
            chiudi = true;
            break;

        case 1:
            ins_prodotto(p[n]);
            n++;
            break;

        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            viz_lst_prod(p, n);
            break;
        }
        

        system("cls");
        
    }
        
    system("pause");
}

//Menu principoale che ci d le opzioni del programma
void menu() {

    cout << "\t\tMENU PRINCIPALE\n";
    cout << "1) Inserisci prodotto\t\t2) Modifica prodotto\n";
    cout << "3) Visualizza prodotto\t\t4) Cancela prodotto\n";
    cout << "5) Inserisci piu prodotti\t6) Vizualizza tutti prodotti";
    cout << "\n0) EXIT\n";

    return;
}

//Inserimento nome
void ins_nome(string& n) {
    cout << "Nome prodotto:\t";
    cin >> n;
    return;
}

//Inserisci il tipo di prodotto
void ins_tipo(string& t) {
    cout << "Tipo prodotto:\t";
    cin >> t;

    return;
}

//Inserisci il costo del prodotto
void ins_costo(float& c) {
    cout << "Costo del prodotto:\t";
    cin >> c;
    return;
}

//Inserisci la quantita dell prodotto
void ins_quantita(int& q) {
    cout << "Quantita del prodotto:\t";
    cin >> q;
    return;
}

//Iserisci il prezzo del prodotto
void ins_prezzo(float& pr) {
    cout << "Prezzo vendita:\t";
    cin >> pr;

    return;
}

//Inserimento data scadenza
void ins_data_scad(date& d) {
    cout << "Scade il:\n";
    cout << "\tGiorno: ";
    cin >> d.giorno;
    cout << "\tMese: ";
    cin >> d.mese;
    cout << "\tAnno: ";
    cin >> d.anno;

    return;
}



void ins_prodotto(prodotto& p) {
    system("cls");

    ins_nome(p.nome);
    ins_tipo(p.tipo);
    ins_data_scad(p.scadenza);
    ins_quantita(p.quantita);
    ins_costo(p.costo);
    ins_prezzo(p.prezzo_vendita);

    return;
}

//vizualizza nome e tipo prodotti
void viz_lst_prod(prodotto p[], int l) {
    system("cls");
    if (l == 0)
        cout << "\t\tNON CI SONO PRODOTTI NELL MAGAZINO\n";
    for (int i = 0; i < l; i++) {
        cout << "Nome: " << p[i].nome;
        cout << "\t\t\tTipo: " << p[i].tipo << endl;
    }
    system("pause");
    return;
}

void viz_prodotto(prodotto p[], int l) {

    return;
}