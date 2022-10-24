import java.util.*;
import java.util.stream.Collectors;
public class demo3 {
    public static void main(String[] args) {
        String palindrome = "Hello12345";
        ArrayList<String> list = new ArrayList<String>(Arrays.asList(palindrome.split("")));
        List<String> result = list.stream().map(((String x) -> {
            return Character.isDigit(x.charAt(0)) ? "" +
                    (Integer.parseInt(x) + 1) : x.toUpperCase();
        })).collect(Collectors.toList());
        System.out.println(String.join("", result));
    }
}