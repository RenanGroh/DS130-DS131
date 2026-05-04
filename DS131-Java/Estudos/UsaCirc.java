import java.util.InputMismatchException;
import java.util.Scanner;

public class UsaCirc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite o raio: ");
        try {
            double raio = sc.nextDouble();
            Circunferencia c = new Circunferencia(raio);
            System.out.println("A Area da circ. é=" + c.area());
        } catch (InputMismatchException e) {
            System.out.println("O valor digitado não é um valor válido");
        } finally {
            System.out.println("fim do programa");
            sc.close();
        }
    }
}
