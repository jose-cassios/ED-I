#include <iostream>
#include <string>

using namespace std;

struct Cell
{
    int value;
    
    Cell *prox;
};

struct List
{
    Cell *head;
};

void inserir(List *list, int value)
{
    Cell *newCell = new Cell;
    newCell->value = value;

    if (list->head == nullptr)
    {
        newCell->prox = list->head;
        list->head = newCell;
        return;
    }

    Cell *aux = list->head;

    while (aux->prox != nullptr && newCell->value > aux->prox->value)
    {
        aux = aux->prox;
    }

    if (newCell->value <= aux->value)
    {
        newCell->prox = aux;
        aux = newCell;
        list->head = newCell;
        return;
    }
    newCell->prox = aux->prox;
    aux->prox = newCell;

}

void mostrar(List list)
{
    cout << "\n";
    Cell *aux = list.head;
    while (aux != nullptr)
    {
        cout << aux->value << " -> ";
        aux = aux->prox;
    }
    cout << "Null\n";

}

void remover(List *list, int value)
{
    Cell *aux = list->head;

    if (aux != nullptr){
        if (list->head->value == value)
        {
            list->head = aux->prox;
            delete aux;
            return;
        }
        
        while (aux->prox != nullptr){
            if (aux->prox->value == value)
            {
                Cell *celDelete = aux->prox;

                aux->prox = aux->prox->prox;
                delete celDelete;
                return;
            }
            aux = aux->prox;
        }
    }

    cout << "\nElemento não encontrado\n";

    /* while (aux->prox != nullptr){
        if (aux->prox->value == value)
        {
            aux->prox = aux->prox->prox;
            list->head = aux;
            delete aux;
            return;
        }
        aux = aux->prox;
    } */
    
}

void liberar(List *list)
{
    cout << "\nLiberando a lista\n\n";
    Cell *aux = list->head;

    while (aux != nullptr)
    {
        Cell *temp = aux;
        aux = aux->prox;
        delete temp;
    }
}

int readValue(string msg){
    int value;
    cout << endl << msg;
    cin >> value;

    return value;
}

int main() 
{
    List lista;
    lista.head = nullptr;

    int opc;
    do
    {
        cout << "\n1 - Inserir\n2 - Mostrar\n3 - Remover\n0 - Sair\n>:";
        cin >> opc;

        switch (opc)
        {
        case 1:
            inserir(&lista, readValue("Digite o valor a ser inserido: "));
            break;
        case 2:
            mostrar(lista);
            break;
        case 3:
            remover(&lista, readValue("Digite o valor a ser removido: "));
            break;
        case 0:
            liberar(&lista);
            break;
        
        default:
            cout << "\n\nInválido\n\n";
            break;
        } 
    } while (opc != 0);
    
    
    return 0;
}