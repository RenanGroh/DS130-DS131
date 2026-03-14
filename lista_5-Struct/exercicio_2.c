/**
 * Escreva um programa que simule contas bancárias, com as seguintes especificações:
 * 1. Ao iniciar o programa vamos criar contas bancárias para três clientes.
 *      1.1 Cada conta terá o nome e o CPF do cliente associado a ela.
 *      1.2 No ato da criação da conta o cliente precisará fazer um depósito inicial.
 * 2. Após as contas serem criadas, o sistema deverá possibilitar realizações de saques
 * ou depósitos nas contas.
 *      2.1 Sempre que uma operação de saque ou depósito seja realizada, o sistema
 * deverá imprimir o nome do titular e o saldo final da conta.
 */

typedef struct {
    char name[100];
    int cpf;
    float balance;
} bankAccount;

#include <stdio.h>
#include <string.h>

void create_account(bankAccount *account) {
    printf("--- Abertura de Conta ---\n");
    printf("Nome do titular: ");
    scanf(" %[^\n]", account->name); // Lê com espaços até o Enter
    
    printf("CPF: ");
    scanf("%d", &account->cpf);
    
    printf("Valor do deposito inicial: ");
    scanf("%f", &account->balance);
    
    printf("Conta criada com sucesso para %s!\n", account->name);
}

void deposit(bankAccount *account, float value) {
    account->balance += value;
    printf("Titular: %s | Saldo Final: R$ %.2f\n", account->name, account->balance);
}

void withdraw(bankAccount *account, float value) {
    account->balance -= value;
    printf("Titular: %s | Saldo Final: R$ %.2f\n", account->name, account->balance);

}

int main() {
    bankAccount accounts[10];

    create_account(&accounts[0]);
    deposit(&accounts[0], 100);
    withdraw(&accounts[0], 50);

    return 0;
}