import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class FileIO {
	public static String loadMaze(String location) throws IOException {
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
		bufferedReader.close();
		return stringBuffer.toString();
	}
}
