package p1;
public class Max{
	public int max(int a, int b, int c){
		return a>b?(a>c?a:c):(b>c?b:c);
	}
	public float max(float a, float b, float c){
		return a>b?(a>c?a:c):(b>c?b:c);
	}
	public int max(int a[]){
		int max=a[0];
		for(int x: a){
			max = max>x?max:x;
		}
		return max;
	}
	public int max(int a[][]){
		int max = a[0][0];
		for(int x[]: a){
			for(int y: x){
				max = max>y?max:y;
			}
		}
		return max;
	}	
}