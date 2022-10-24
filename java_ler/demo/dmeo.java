import java.util.*;
// import java.util.stream.Collectors;
class A{
    public int A=1;

}
class B{
    public int A=1;
    
}
class C{
    public int A=1;
    
}
public class dmeo {
    private static int k=100;
    public static void main(String[] args) {
    //    List<Object> a=new ArrayList<>{};
    List<Object> list = new ArrayList<>();
    list.add(new A());
    list.add(new B());
    list.add(new C());
    System.out.println(list.get(1) instanceof B? 1:2);
    // for(Object o :list)
    // {
        // System.out.println(o.getClass());
        // o.
    
    // }
    }
}

