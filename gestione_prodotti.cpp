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

int main()
{
    prodotto p[100];
    bool chiudi = false;
    int opt = 0;

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

            break;
        }

        system("cls");
    }
        


}

void menu() {

    cout << "\t\tMENU PRINCIPALE\n";
    cout << "1) Inserisci prodotto\t\t2) Modifica prodotto\n";
    cout << "3) Visualiza prodotto\t\t4) Cancela prodotto\n";
    cout << "5) Inserisci piu prodotti\t0) EXIT\n";

    return;
}

void ins_prodotto(prodotto& p) {
    system("cls");

    cout << "Nome prodotto:\t";
    cin >> p.nome;
    cout << "Tipo prodotto:\t";
    cin >> p.tipo;
    cout << "Costo del prodotto:\t";
    cin >> p.costo;
    cout << "Quantita del prodotto:\t";
    cin >> p.quantita;
    cout << "Prezzo vendita:\t";
    cin >> p.prezzo_vendita;
    return;
}
