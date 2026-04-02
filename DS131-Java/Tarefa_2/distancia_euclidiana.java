import java.util.Scanner;
/**
 * Construa um programa que leia do teclado dois pontos em um
 * plano (x,y) e informe a distância entre eles.
 *
 * Exercicio 3 Tarefa 2
 * Aluno: Renan Groh - GRR20250818
 *
 */
public class distancia_euclidiana {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        // Lendo o primeiro ponto (x1, y1)
        System.out.println("Digite x e y do primeiro ponto:");
        double x1 = leitor.nextDouble();
        double y1 = leitor.nextDouble();

        // Lendo o segundo ponto (x2, y2)
        System.out.println("Digite x e y do segundo ponto:");
        double x2 = leitor.nextDouble();
        double y2 = leitor.nextDouble();

        // Cálculo da distância
        double distancia = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));

        System.out.printf("A distância entre os pontos é: %.2f\n", distancia);

        leitor.close();
    }
}
