/**
 * Data Structures
 * Homework 2
 * 
 * Josh Harshman
 * 1.23.2014
 * */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
//import java.util.Iterator;
//import java.util.LinkedList;


/*
 *The WordProcessor class would extract words from the raw text file(a.k.a tokenization).
 *After extracted one word, it either creates a new WordItem object and insert
 *the object into LinkedLis at a proper location, or it calls a method in MyLinkedList to increment 
 *the word occurrence and to update line-number list if a word has already been existing.
 *
 *The class also provides File I/O methods. Write the resultant string or list back to a file.
 *
 */
public class WordProcessor {
	
	private static MyLinkedList ll = new MyLinkedList();
	private static int lines = 1; //line counter
	//private final String fileName="files/testfile1";
	
	//give you a taste about how to do fileIO
	public ArrayList<String> fileRead(String name) throws IOException {
		ArrayList<String> lines = new ArrayList<String>();
		
		FileReader fileReader = new FileReader(name);
        BufferedReader bufferedReader = new BufferedReader(fileReader);
        String aline = null;
        //read in the rest of rows
        //readLine() returns striped string, that discards any line-termination chars
        while ((aline = bufferedReader.readLine()) != null) {
        	aline = aline.trim();
        	if(aline.length() > 0)
        		lines.add(aline); //skip empty lines
        }
        fileReader.close();
		return lines;
	}
	
	/**
	 * extractLine Method
	 *  - Extracts valid English words from passed in line
	 * */
	public MyLinkedList extractLine(String aline) {
		
		int len = 0;
		int start = 0;
		int inword = 0; //flag
		int index;
		String word = "";
		char c;
		
		WordItem wrd = null;
		
		index = 0;
		while(index < aline.length()) {
			c = aline.charAt(index);
			if(Character.isLetter(c)) {
				if(inword == 0) {
					inword = 1;
					start = index;
				}
				len++;
			}
			else if(inword == 1) {
				word = aline.substring(start, start+len);
				word = word.toLowerCase();
				
				wrd = new WordItem(word, 1, lines);
			
				addWord(wrd);
				inword = 0;
				len = 0;
			}
			
			index++;
		}
		if(inword == 1) {
			word = aline.substring(start, start+len);
			word = word.toLowerCase();
			
			wrd = new WordItem(word, 1, lines);
			addWord(wrd);
			
		}
		lines++;
		return ll;
		
	}//end of extract
	
	/**
	 * extractAll Method
	 * - Utilizes fileRead method and extractLine method
	 * */
	public MyLinkedList extractAll(String fileName) throws IOException {
		
		ArrayList<String> list = null;
		
		try {
			list = fileRead(fileName);
		}catch(FileNotFoundException e) {
			e.printStackTrace();
		}
		
		for(String x : list) {
			ll = extractLine(x); //Solved issue with global  linked list variable.  not clean but functions well.
			if(lines % 200 == 0)
				System.out.println(lines + " Lines Processed");
			if(lines % 3000 == 0)
				System.out.println("C is a lot faster than this");
		}
		
		return ll;
		
	}//end extractAll
	
	/**
	 * addWord method
	 * - Utilized by extractLine method.
	 * - Aids the modularity of the code
	 * */
	public static void addWord(WordItem word) {
		
		String w = word.getWord();
		
		//System.out.println("Processing token '" + word.getWord() + "' @ line " + lines);

		if(w.length() == 1) {
			if(w.equals("a") || w.equals("i")) {
				if(! ll.containWord(w, lines)) {
					//System.out.println("Adding word '" + word.getWord() + "'");
					ll.addOrdered(word);
					//ll.add(word);
				}
			}
			else {
				//System.out.println("Throwing away garbage token '" + word.getWord() + "'");
			}
		}
		else {
			if(! ll.containWord(w, lines)) {
				//System.out.println("Adding word '" + word.getWord() + "'");
				ll.addOrdered(word);
				//ll.add(word);
			}
		}
		
	}
	
	public void writeToFile(MyLinkedList alist, String fileName) {
		FileWriter fileWriter = null;
        try {
            String content = alist.toString();
            File newTextFile = new File(fileName);
            fileWriter = new FileWriter(newTextFile);
            fileWriter.write(content);
            fileWriter.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        } finally {
            try {
                fileWriter.close();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
	}//
	
}//end of class
	

