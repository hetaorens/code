//类 面包
public class Bread {
	final private int addHeight = 1;

	Bread() {
		System.out.println("在屋子里有一种魔法面包,这块面包只要吃一片就可以长高1cm");
	}

	public void eat(Person a) {
		a.grow_taller(addHeight);
		System.out.println(a.getName() + "吃了一片面包。");
		System.out.println("吃了一片面包后," + a.getName() + "惊了");
	}

}