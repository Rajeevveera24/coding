import java.io.*;
import java.util.Scanner;
public class Ex3{
	static Scanner scan = new Scanner(System.in);
	public static void main(String[] args) throws IOException,NumberFormatException{
		FileReader file_in = null;
		try{
			//Variable Declarations.....
			file_in = new FileReader("fileNames.txt");
			BufferedReader file_buff = new BufferedReader(file_in);
			int line_count=0;
			String line,file_line;

			//Inputting the word to be searched for.....
			System.out.println("Enter the word to be found");
			line = scan.nextLine();

			//Entering while loop to read the file line by line and search for the specified word.....
			while((file_line = file_buff.readLine())!=null){
				line_count++;
				String [] words = file_line.split(" ");
				for(String word : words){
					if(word.compareTo(line)==0){
						System.out.println(line_count + " " + file_line);
						break;
					}
				}
			}
		}
		catch(Exception e){
			System.out.println("Unalbe to open file 'fileNames.txt'");
			e.printStackTrace();
		}
		finally{
			if(file_in!=null){
				file_in.close();
			}
		}
	}
}