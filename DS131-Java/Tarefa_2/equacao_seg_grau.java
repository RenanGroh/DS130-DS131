import java.util.Scanner;

/**
 * Construa um programa que calcule as raízes de uma 
 * equação do segundo grau.
 *
 * Exercicio 4 Tarefa 2
 * Aluno: Renan Groh - GRR20250818
 *
 */
public class equacao_seg_grau {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        System.out.println("Digite os coeficientes a, b e c:");
        double a = leitor.nextDouble();
        double b = leitor.nextDouble();
        double c = leitor.nextDouble();

        // Cálculo do Delta: Δ = b² - 4ac
        double delta = Math.pow(b, 2) - (4 * a * c);

        // Cálculo das raízes: x = (-b ± √Δ) / 2a
        double x1 = (-b + Math.sqrt(delta)) / (2 * a);
        double x2 = (-b - Math.sqrt(delta)) / (2 * a);

        System.out.println("Resultado: x1 = " + x1 + " e x2 = " + x2);

        leitor.close();
    }
}
