import java.io.*;
public class FileIO {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File file = new File("10x10.txt");
		String path = file.getAbsolutePath();
		file = new File(path);
		FileReader fileIn = new FileReader(file);
		BufferedReader bufferedReader = new BufferedReader(fileIn);
		StringBuffer stringBuffer = new StringBuffer();
		String line;
		while ((line = bufferedReader.readLine()) != null) {
			stringBuffer.append(line);
			stringBuffer.append("\n");
		}
		fileIn.close();
		System.out.println("Stuff!");
		System.out.println(stringBuffer.toString());
	}

}
