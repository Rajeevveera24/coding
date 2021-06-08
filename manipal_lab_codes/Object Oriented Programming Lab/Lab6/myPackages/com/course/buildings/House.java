package buildings;
public class House extends Building{
	int bedroom,bath;
	House(float sq_ft, int storeys, int bedroom, int bath){
		super(sq_ft,storeys);
		this.bedroom = bedroom;
		this.bath = bath;
	}
}
