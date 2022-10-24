//类 人
public class Person {
	private int height;
	private String name;
	Person(String n, int h) {
		name = n;
		height = h;
	}
	public String getName() {
		return name;
	}
	public int getHeight() {
		return height;
	}
	public void grow_taller(int ad) {
		height += ad;
	}
	public void setName(String a) {
		name = a;
	}
	public void setHeight(int n) {
		height = n;
	}
	public void displayHeight() {
		System.out.println(name + "现在身高:" + height + "cm");
	}
}
