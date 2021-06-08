import java.io.*;
public class Ex4{
	public static void main(String[] args) throws IOException{
		FileReader file_read = null;
		FileWriter file_write = null;
		try{
			file_read = new FileReader(args[0]);
			file_write = new FileWriter(args[1]);
			int byt;
			while((byt = file_read.read())!=-1){
				file_write.write(byt);
			}
			System.out.println("Contents of " + args[0] + " have been copied to " + args[1] + ".\nOpen " + args[1] + " to view the changes made in it.");
		}
		catch(IOException e){
			e.printStackTrace();
		}
		finally{
			if(file_read!=null){
				file_read.close();
			}
			if(file_write!=null){
				file_write.close();
			}
		}
	}
}