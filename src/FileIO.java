import java.io.*;
public class FileIO {
	
	private String line;
	
	public void loadMaze(String location) throws IOException {
		File file = new File(location);
		String path = file.getAbsolutePath();
		file = new File(path);
		FileReader fileIn = new FileReader(file);
		BufferedReader bufferedReader = new BufferedReader(fileIn);
		StringBuffer stringBuffer = new StringBuffer();
		while ((this.line = bufferedReader.readLine()) != null) {
			stringBuffer.append(this.line);
			stringBuffer.append("\n");
		}
		fileIn.close();
	}
	
	public void printString() {
		System.out.println(this.line);
	}
	
	public static void main(String[] args) {
	}
}
