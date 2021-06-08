package buildings;
public class School extends Building{
	int num_classroom;
	String grade_level;
	School(float sq_ft, int storeys, int num_classroom, String grade_level){
		super(sq_ft,storeys);
		this.num_classroom = num_classroom;
		this.grade_level = grade_level;
	}
}