import java.util.Scanner;

public class SwapName {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite seu nome e sobrenome: ");
        String fullName = scanner.nextLine(); // Lê a linha inteira

        // O método .split(" ") divide a frase em um array de palavras
        String[] words = fullName.split(" ");

        System.out.print("Resultado: ");
        // Percorremos o array 'palavras' de trás para frente
        for (int i = words.length - 1; i >= 0; i--) {
            System.out.print(words[i] + " ");
        }

        System.out.println();
        scanner.close();
    }
}
