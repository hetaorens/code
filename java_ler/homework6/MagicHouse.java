//类 魔法屋
import java.util.*;
public class MagicHouse {
	public List<Object> furnitures = new ArrayList<>();

	MagicHouse() {
		System.out.println("远处的一栋大house\n" +
				"上面有一个大广告牌写着:“魔法屋,\n" +
				"让你增高不再是梦想！！！”");
		furnitures.add(new Bread());
		furnitures.add(new MagicBed());

	}

	public void inHouse(Person a) {

		System.out.println(a.getName() + "走进了一间魔法屋");
	}

}
