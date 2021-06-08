import java.io.*;
public class Ex2{
	public static void main(String[] args) throws IOException,NumberFormatException{
		FileReader file_in = null;
		try{
			file_in = new FileReader("fileNames.txt");
			BufferedReader file_buff = new BufferedReader(file_in);
			String line;
			int count_char = 0,count_word=0,count_num=0,count_line=0;
			while((line=file_buff.readLine())!=null){
				count_char+=line.length();
				String words[] = line.split(" ");
				for(String word : words){
					try{
						Double d = Double.parseDouble(word);
						count_num++;
					}
					catch(NumberFormatException e){
						count_word++;
					}
				}
				count_line++;
			}
			System.out.println("Characters: "+count_char);
			System.out.println("Numbers: "+count_num);
			System.out.println("Words: "+count_word);
			System.out.println("Lines: "+count_line);
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