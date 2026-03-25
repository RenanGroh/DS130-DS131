# Lista de exercícios - Introdução

## 1. Instalar o ambiente Java na sua máquina ou na máquina do laboratório.
 Testar executando o comando
 java –version
 javac -help
## 2. Leia o texto das páginas 24 a 26 (Livro Jandl)
## 3. Visitar a documentação da API Java em:
- http://download.oracle.com/javase/7/docs/api/
- Navegar pelos links.
## 4. Descreva qual a diferença entre JRE e JDK.
## 5. O Java é uma linguagem compilada ou interpretada? Explique.
## 6. Altere o programa “MeuPrograma” para exibir uma mensagem diferente
- Altere seu programa para imprimir duas linhas de texto usando duas linhas de código System.out.
- Sabendo que os caracteres \n representam uma quebra de linhas, imprima duas linhas de texto usando uma única linha de código System.out.
## 7. Compile e execute o programa abaixo:
```java
class Eco
{
    public static void main (String args[])
    {
        for (int i = 0; i < args.length; i++)
        System.out.println (args[i]);
        System.out.println ();
    }
}
```
Descreva o que o programa faz.

## 8. (Tarefa 01) Crie um programa “Nome” que leia um nome completo na linha de comando e imprima-o ao contrário.

Por exemplo, a linha de comando java Nome Rafael Wandresen deve imprimir:

```
Wandresen

Rafael
```

### 9. (Tarefa 01) Implemente um programa que receba da linha de comando 3 argumentos. O primeiro e o segundo argumento são números reais e o terceiro argumento é a operação. Teste o seu programa com os seguintes casos de testes:

```java 
java Calculadora 3 4 +
7.0
java Calculadora 3 4 –
-1.0
java Calculadora 3 4 /
0.75
java
```

## 10. Leia, implemente e execute o programa abaixo e explique o que ele faz:

```java
import java.lang.String;
import java.lang.Integer;
class ExercicioIII
{
public static void main (String args[])
    {
        String strA, strB;
        int intA, intB, intC;
        strA = args[0];
        strB = args[1];
        intA = Integer.parseInt (strA);
        intB = Integer.parseInt (strB);
        System.out.println (strA + strB);
        System.out.println (intA + intB);
    }
}
```

## 11. Leia, implemente e execute o programa abaixo e explique o que ele faz:

```java
import java.util.Scanner;
class ExercicioIV
{
public static void main (String args[])
    {
        if (args.length != 0)
        {
            System.out.println ("Este programa nao possui argumentos!");
            System.exit (1);
        }
        Scanner s = new Scanner (System.in);
        System.out.print ("Dado A: ");
        int a = s.nextInt();
        System.out.print ("Dado B: ");
        int b = s.nextInt();
        if (a >= b)
        System.out.println ("Resultado: " + a);
        else
        System.out.println ("Resultado: " + b);
    }
}
```

## 12. Responda as perguntas da página 26 do livro “Java: Guia do Programador. Jandl Junior, Peter.”