/**
 * Homework 3 - Recursive Maze Traversal
 * 
 * CSCD 300 - Data Structures
 * 
 * Written By Josh Harshman
 * February 2, 2014
 * 
 * 
 * */



import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.util.ArrayList;

public class RunMaze {
	
	private static final char PATH  = '+';
	private static final char TRIED = '.';
	private static final int ROWS = 6;
	private static final int COLS = 6;
	public static ArrayList<char[][]> list = new ArrayList<char[][]>(); //fast way of remembering different paths in the maze
	
	public static void main (String ... args) {
		
		char[][] maze = null;
		int startPos = 0;
		int endPos = 0;
		
		//load maze from file
		maze = readFile(getFileName());
		
		char[][] copy = dup(maze);
		char[][] copy1 = dup(maze);
		
		
		//find start position
		startPos = findStartPos(maze);
		
		//find end position
		endPos = findEndPos(maze);
		
		//print maze
		System.out.println("Orriginal Maze:");
		printMaze(maze);
		
		//find one path
		if(mazeRunner(startPos, 0, copy)) {
			printMaze(copy);
			writeFile("path1.txt", copy);
		}
		else
			System.out.println("No Paths Found");
		
		System.out.println("Now finding all paths\n=======================");
		
		//find all paths
		findAll(startPos, 0, copy1);
		
		//write list of different paths to a file
		writeList(list, "pathAll.txt");
		
		
	}//end
	
	/*
	 * Get name of file from user
	 * */
	public static File getFileName() {
		
		File file = null;
		Scanner kb = new Scanner(System.in);
		do {
			System.out.print("Enter the name of the maze file: ");
			file = new File(kb.nextLine());
		}while(!file.exists() || file.isDirectory()); //does a little validity checking
		
		kb.close();
		
		return file;
	}

	/*
	 * read the file
	 * */
	public static char[ ][ ] readFile(File fileName) {
		
		Scanner fin = null;
		String str = "";
		int i = 0;
		char[][] ara = new char[ROWS][COLS];
		try {
			fin = new Scanner(fileName);
		}catch(FileNotFoundException e) {
			e.printStackTrace();
		}
		if(fin.hasNext()) {
			while(fin.hasNext()) {
				str = fin.nextLine();
				ara[i] = str.toCharArray();
				i++;
			}
		}
		
		fin.close();
		
		return ara;
	}
	
	/*
	 * Write new file
	 * */
	public static void writeFile(String fileName, char[][] maze) {
		
		PrintWriter pw = null;
		
		try {
			pw = new PrintWriter(fileName);
			for(int i = 0; i < ROWS; i ++) {
				pw.println(maze[i]);
			}
			pw.println("------------------");
			pw.println("------------------");
		}catch(IOException e) {
			e.printStackTrace();
		}
		
		pw.close();
		
	}
	
	/*
	 * Write List of char[][] to file
	 * */
	public static void writeList(ArrayList<char[][]> list, String filename) {
		
		PrintWriter pw = null;
		
		try {
			pw = new PrintWriter(filename);
			for(int i = 0; i < list.size(); i++) {
				for(int j = 0; j < ROWS; j++) {
					pw.println(list.get(i)[j]);
				}
				pw.println("------------------");
				pw.println("------------------");
			}
		}catch(FileNotFoundException e) {
			e.printStackTrace();
		}
		pw.close();
	}
	
	/*
	 * find start position
	 * */
	public static int findStartPos(char[][] maze) {
		
		int start = -1; //set up for error checking
		
		for(int i = 0; i < ROWS; i++) {
			if(maze[i][0] == 'S')
					return i;  //start = i;
		}
		
		//if no start position.  Throw exception and end
		if(start == -1) throw new IllegalArgumentException("Maze has no start point or file did not contain a valid maze");
		
		return start;
		
	}
	
	/*
	 * find end position
	 * */
	public static int findEndPos(char[][] maze) {
		
		int end = -1;  //set up for error checking
		
		for(int i = 0; i < ROWS; i++) {
			for(int j = 0; j < COLS; j++) {
				if(maze[i][j] == 'G')
					end = i; //indicates the row number where the end exists.  to find the absolute end the program will check length
			}
		}
		
		if(end == -1) throw new IllegalArgumentException("Maze has no end point or file did not contain a valid maze");
		
		return end;
		
	}
	
	/*
	 * Duplicates passed in 2d char array
	 * */
	public static char[][] dup(char[][] maze) {
		
		char[][] copy = new char[ROWS][COLS];
		
		for(int r = 0; r < ROWS; r++) {
			for(int c = 0; c < COLS; c++) {
				copy[r][c] = maze[r][c];
			}
		}
		
		return copy;
		
	}
	
	/*
	 * print the maze to STDOUT
	 * */
	public static void printMaze(char[][] maze) {
		
		for(int r = 0; r < maze.length; r++) {
			for(int c = 0; c < maze.length; c++) {
				System.out.print(maze[r][c]  + " ");
			}
			System.out.print("\n");
		}
		
		System.out.println("-----------------------");
		System.out.println("-----------------------");
	}
	
	
	/*
	 * findAll method.
	 * Finds all paths through the maze
	 * Adds each valid path to an arraylist for easy storage
	 * */
	public static void findAll(int row, int col, char[][] maze) {
		
		//char[][] mazeCopy = dup(maze);
		
		if(row >=0 && row < maze.length && col >= 0 && col < maze[0].length) {
			
			
			if(maze[row][col] == 'G') {
				System.out.println("Maze Solved");
				printMaze(maze);
				list.add(maze);
				return;
			}
			
			if(!isValid(row, col, maze))
				return;
			
			
			maze[row][col] = PATH;
			
			char[][] mazeCopy = dup(maze);
			
			findAll(row+1, col, mazeCopy);
			findAll(row, col+1, mazeCopy);
			findAll(row-1, col, mazeCopy);
			findAll(row, col-1, mazeCopy);
			
			maze[row][col] = TRIED;
			return;
			
			
		}
		
	}
	
	/*
	 * Recursive function to find a singular path through a maze
	 * */
	public static boolean mazeRunner(int row, int col, char[][] maze) {
		
		//if outside the maze return false
		if(row >= 0 && row < maze.length && col >=0 && col < maze[0].length) {
			
			//if at end of maze return true
			if(maze[row][col] == 'G')
				return true;
			
			//check next path is valid
			if(!isValid(row, col, maze))
				return false;
			
			//mark path
			maze[row][col] = PATH;
			
			if(mazeRunner(row+1, col, maze)) return true;
			if(mazeRunner(row, col+1, maze)) return true;
			if(mazeRunner(row-1, col, maze)) return true;
			if(mazeRunner(row, col-1, maze)) return true;
			
			
			maze[row][col] = TRIED;
			
		}
		
		return false;
		//return done;
	}
	
	/*
	 * tests if next step is valid
	 * */
	public static boolean isValid(int row, int col, char [][] maze) {
		if(maze[row][col] == '.' || maze[row][col] == 'S')
			return true;
		return false;
	}
	

}
