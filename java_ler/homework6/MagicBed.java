//类 魔法床

public class MagicBed {
	final private int addHeight = 50;

	MagicBed() {
		System.out.println("在屋子里有一张魔法床,睡一觉可以长高50cm");
	}

	public void sleep(Person a) {
		a.grow_taller(addHeight);
		System.out.println(a.getName() + "睡在了一张魔法床上面");
		System.out.println("睡起来以后," + a.getName() + "惊了");
	}

}