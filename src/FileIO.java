import java.io.*;
public class FileIO {
	
	private String location;
	
	public FileIO(String str) {
		location = str;
	}
	
	public String loadMaze() throws IOException {
		File file = new File(location);
		String path = file.getAbsolutePath();
		file = new File(path);
		BufferedReader bufferedReader = new BufferedReader(new FileReader(file));

		StringBuffer stringBuffer = new StringBuffer();
		String line;
		
		while ((line = bufferedReader.readLine()) != null) {
			stringBuffer.append(line);
			stringBuffer.append("\n");
		}
		//System.out.println(stringBuffer.toString());
		bufferedReader.close();
		return stringBuffer.toString();
	}
	
	public void printString() {
	}
	
	public static void main(String[] args) {
	}
}
