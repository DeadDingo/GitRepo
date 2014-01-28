/**
 * Data Structures
 * Homework 2
 * 
 * Josh Harshman
 * 1.23.2014
 * */

import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;


public class Tester {

	public static void main(String[] args) throws IOException {

		String fileName1="files/testfile1";
		String fileName2="files/testfile2";
		WordProcessor wp = new WordProcessor();

		MyLinkedList allWords = wp.extractAll(fileName2);
		System.out.println("\nWriting to file, please wait...");
		wp.writeToFile(allWords, "outSort1");
		allWords.sortListOcc(); //sort the list according to word occurrence, you have to implement it.
		System.out.println("\nWriting to file, please wait...");
		wp.writeToFile(allWords,"outSort2");
		//System.out.println(allWords.toString());
	}

}
