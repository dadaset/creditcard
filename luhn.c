// Peter Luhn (July 1, 1896 – August 19, 1964) was a researcher in the field of computer science and Library & Information Science for IBM, and creator of the Luhn algorithm
//, KWIC (Key Words In Context) indexing, and Selective dissemination of information ("SDI"). His inventions have found applications in diverse areas like computer science, th
//e textile industry, linguistics, and information science. He was awarded over 80 patents.

//#n digit
//as.integer(123456%%10)
//#n-1 digit
//as.integer(123456%%100/10)
//#n-2 digit
//as.integer(123456%%1000/100)
//#n-3 digit
//as.integer(123456%%10000/1000)

//#include <cs50.h>
//#include <stdio.h>

//int main(void)
//{
 //   int card_number = get_int("Insert Credit Card Number:");
 //   printf("your id is, %d\n", card_number);
//}

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Declaração de variáveis
    long cartao;
    long digitos;
    int numero_digitos = 0;

    // Obtenção do número do cartão
    do
    {
        cartao = get_long("Insira o número do cartão (sem espaços, pontos e traços): ");
    }
    while (cartao <= 0);

    digitos = cartao;

    // Descobrir o número de dígitos do cartão
    while (digitos > 0)
    {
        digitos = round(digitos / 10);
        numero_digitos++;
    }

    // Aplicação do algoritmo de Luhn
    /* "numero_atual" = número atual que está sendo validado; "total_par" = totalização dos números pares; "total_impar" = totalização dos números ímpares; "numero_par" = valida se o "número é par".
        Obs: Aqui, por número par, considera-se o penúltimo número da direita para a esquerda e os próximos números no intervalo de duas casas */
    int numero_atual;
    int total_par = 0;
    int total_impar = 0;
    int numero_par = 0;
    int iniciais_cartao = 0;

    // Identificação dos números da direita para esquerda, conforme algoritmo de Luhn
    while (cartao > 0)
    {
        numero_atual = cartao % 10;
        numero_par++;
        cartao = cartao / 10;

        // Validação de se o número é par ou ímpar para a soma da totalização (números pares não terão resto na divisão)
        if (numero_par % 2 == 0)
        {
            numero_atual = numero_atual * 2;
            if (numero_atual >= 10)
            {
                numero_atual = (numero_atual % 10) + (numero_atual / 10);
                total_par = total_par + numero_atual;
            }
            else
            {
                total_par = total_par + numero_atual;
            }
        }
        else
        {
            total_impar = total_impar + numero_atual;
        }

        // Verifica quais são as iniciais do cartão
        if (cartao < 100 && cartao >= 10)
        {
            iniciais_cartao = cartao;
        }
    }

    // Valida se o cartão atende as especificações do algoritmo de Luhn (quantidade de dígitos e se último dígito obtido na soma do algoritmo é 0)
    if (((total_par + total_impar) % 10) == 0 && numero_digitos >= 12 && numero_digitos <= 16)
    {

        // Identifica e imprime a bandeira do cartão
        if (iniciais_cartao == 34 || iniciais_cartao == 37)
        {
            printf("AMEX\n");
        }
        else if (iniciais_cartao >= 51 && iniciais_cartao <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (iniciais_cartao / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}



