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
//funzioni di input per ogni dato
void ins_nome(string& n);   
void ins_tipo(string& t);   
void ins_costo(float& c);
void ins_quantita(int& q);
void ins_prezzo(float& pr);
void ins_data_scad(date& d);

void ins_prodotto(prodotto& p);             //Inserisci un prodotto

void viz_lst_prod(prodotto p[], int l);     //vizualizza tutti prodotti
void viz_prodotto(prodotto p[], int l);     //cerca prodotto specifico
void mod_prodotto(prodotto p[], int l);     //modifica prodotto
void ins_multi_prod(prodotto p[], int& l);  //inserisce piu prodotti
void canc_prod(prodotto p[], int& l);       //cancella prodotto

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
            system("cls");
            ins_prodotto(p[n]);
            n++;
            system("pause");
            break;

        case 2:
            mod_prodotto(p, n);
            system("pause");
            break;
        case 3:
            viz_prodotto(p, n);

            break;
        case 4:
            canc_prod(p, n);

            break;
        case 5:
            ins_multi_prod(p, n);
            break;
        case 6:
            viz_lst_prod(p, n);
            system("pause");
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
    //system("cls");

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
        cout << "\t\tNON CI SONO PRODOTTI NELL MAGAZZINO\n";
    for (int i = 0; i < l; i++) {
        cout << "Nome: " << p[i].nome;
        cout << "\t\t\tTipo: " << p[i].tipo << endl;
    }
    //system("pause");
    return;
}

//vizualizza prodotto specifico
void viz_prodotto(prodotto p[], int l) {
    string nom;
    system("cls");
    cout << "Nome del prodotto : ";
    cin >> nom;

    for (int i = 0; i < l; i++) {
        if (p[i].nome == nom) {
            cout << p[i].nome << endl;
            cout << "Tipo: " << p[i].tipo << endl;
            cout << "Data scadenza: " << p[i].scadenza.giorno << "/" << p[i].scadenza.mese << "/" << p[i].scadenza.anno << endl;
            cout << "Quantita: " << p[i].quantita << endl;
            cout << "Costo: " << p[i].costo << endl;
            cout << "Prezzo vendita: " << p[i].prezzo_vendita << endl;
            break;
        }
        else if (i == l - 1 && p[i].nome != nom)
            cout << "\t\tPRODOTTO NON TROVATO\n";
    }
    system("pause");
    return;
}

//Funzione che modifica il prodotto
void mod_prodotto(prodotto p[], int l) {
    string nom;
    system("cls");
    cout << "Nome del prodotto : ";
    cin >> nom;
    for (int i = 0; i < l; i++) {
        if (p[i].nome == nom) {
            ins_prodotto(p[i]);
            break;
        }
        if (i == l - 1 && p[i].nome != nom)
            cout << "PRODOTTO NON TROVATO\n";
    }
    system("pause");

    return;
}

//funzione input piu prodotti di fila
void ins_multi_prod(prodotto p[], int& l) {
    int n = 0;
    cout << "Quanti prodotti vuoi inserire: ";
    cin >> n;
    system("cls");
    for (int i = 0; i < n; i++) {
        cout << "Inserisci " << i + 1 << " prodotto\n";
        ins_prodotto(p[i]);
        system("cls");
        l++;
    }

    return;
}

//funzione che cancela il prodotto
void canc_prod(prodotto p[], int& l) {
    viz_lst_prod(p, l);
    string nom;
    int i = 0 ;
    cout << "Prodotto che vuoi cancelare: ";
    cin >> nom;
    while (p[i].nome != nom && i < l)
        i++;

    if (i = l - 1 && p[i].nome != nom)
        cout << "PRODOTTO NO TROVATO\n";
    else
        for (int j = i; j < l - 1; j++) 
            p[j] = p[j + 1];
    l--;

    return;
}