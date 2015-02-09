public class Coordinate {
	private int row, col;

	public Coordinate(int Row, int Column) {
		row = Row;
		col = Column;
	}

	public int getRow() { return this.row; }
	public int getCol() { return this.col; }

	public void setRow(int Row) { row = Row; }
	public void setCol(int Column) { col = Column; }
	public void setCoord(int Row, int Column) {
		row = Row;
		col = Column;
	}
}
