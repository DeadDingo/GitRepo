/**
 * Data Structures
 * Homework 2
 * 
 * Josh Harshman
 * 1.23.2014
 * */

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.ArrayList;

/*
 * Each WordItem object represents a word extracted from the text file.
 * It has three fields. String word stores the literal English word.
 * int count records the number of occurrence for that word in text file.
 * ArrayList atLines records a list of line numbers at which the word appears in
 * the original text file. 
 * NOTE: line number in this Arraylist 'atLines' should be unique, no duplicates.
 * 
 * 
 *  
 */

public class WordItem implements Comparable {
	private String word;
	private int count;
	private ArrayList<Integer> atLines;
	
	public WordItem(String word, int c, int atLine) {
		this.word = word;
		this.count = c;
		this.atLines = new ArrayList<Integer>();
		atLines.add(atLine);
	}
	
	//compare Count.  Does what name implies.  Aids in sorting by Occurrence
	public int compareCount(Object other) {
		WordItem obj = (WordItem)other;
		if(this.getCount() == obj.getCount()) {
			return 0;
		}
		if(this.getCount() < obj.getCount()) {
			return -1;
		}
		return 1;
	}
		
	@Override
	//implement this method
	public int compareTo(Object other) {
		
		WordItem obj = (WordItem)other;
		
		if(this.getWord().compareTo(obj.getWord()) > 0) {
			return 11;
		}
		if(this.getWord().compareTo(obj.getWord()) < 0) {
			return -1;
		}
		
		return 0;
	}
	
	//
	public String getWord() {
		return this.word;
	}
	

	//
	public int getCount() {
		return this.count;
	}
	
	//added method setCount.  Allows modification to object variable
	public void setCount(int count) {
		this.count = count;
	}
	
	//added method modLines.  Allows modification to object variable
	public void modLines(int line) {
		atLines.add(line);
	}
	
	//added method checkLines.  Checks for duplicate line variables in array list
	public boolean checkLines(int line) {
		for(int i = 0; i < atLines.size(); i++) {
			if(line == atLines.get(i))
				return true;
		}
		return false;
	}
	
	@Override
	public boolean equals(Object obj) {
		
		WordItem wrd = (WordItem)obj;
		
		if(this.getWord().equals(wrd.getWord())) {
			return true;
		}
        return false;
    }
	
	@Override
	public String toString() {
		String ret = "";
		ret += word + ":" + this.count + "->" +
				this.atLines.toString();
		return ret;
	}
	
}//end of class
