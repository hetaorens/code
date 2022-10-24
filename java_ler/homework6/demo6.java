//运行代码段
public class demo6 {
	public static void main(String[] args) {
		/*
		 * 故事背景
		 * 练习 1. 小明在屋子里发现好多面包，这种面 包只要吃下去一片
		 * 就可以长高 1 厘米。 尝试 写程序描述上述故事。要求在程序中
		 * 创建 3 种 对象：魔法屋，面包以及小明。 练习 2. 光靠吃面包
		 * 个子长得太慢了！小明在这座房子的地下室里又发现了一台古怪的
		 * 机器，上面有个小门，门上的牌子写道：“警 告：每次 50 厘米，
		 * 不可反悔！”，于是他钻 进了这台魔法机器。。。几分钟后他惊奇
		 * 地发 现自己已经变成了一个高个子，身高超过了190 厘米！
		 */
		Person xiaoming = new Person("小明", 140);
		MagicHouse mh = new MagicHouse();
		mh.inHouse(xiaoming);
		xiaoming.displayHeight();

		Bread br = ((Bread) mh.furnitures.get(0));
		br.eat(xiaoming);
		xiaoming.displayHeight();
		br.eat(xiaoming);
		xiaoming.displayHeight();

		MagicBed mb = ((MagicBed) mh.furnitures.get(1));
		mb.sleep(xiaoming);
		xiaoming.displayHeight();

	}
}
