/**
 * InfixToPostfix class
 * 
 * Written By Josh Harshman
 * February 23, 2014
 * 
 * - Contains:
 *  	main()
 *  	isOperand(char o, Map m)
 *  	convert(String s, Map m)
 *  	evaluate(String s, Map m)
 *  	populate(void)
 *  	generate(void)
 *  	getFile(void)
 * 
 * */

import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class InfixToPostfix {
	
	static final String P_ERROR = "Parenthesis Match Error";
	static final String E_ERROR = "Empty Infix Expression Error";
	
	static Map<Character, Integer> out_stack = new HashMap<Character, Integer>(); //HashMap to establish arithmetic precedence outside of stack
	static Map<Character, Integer> in_stack = new HashMap<Character, Integer>(); //HashMap to establish arithmetic precedence inside the stack
	
	public static void main(String ...args) {
		
		Map<Character, Double> map = null; //HashMap for initial input file
				
		//read in input and map it to hash table
		try {
			map = populate();
		}catch(IOException e) {
			e.printStackTrace();
		}
		
		//populate the precedence HashMaps
		generate();
		
		//read in the prefixes.  Convert and evaluate in while loop
		System.out.print("Load infix file: ");
		try {
			BufferedReader in = new BufferedReader(new FileReader(getFile()));
			String line = "";
			while((line = in.readLine()) != null) {
				
				
				if(!match(line)) {
					System.out.println(line + " --> " + P_ERROR);
					continue;
				}
				
				//convert
				String expression = convert(line, map);
				
				if(expression.equals("")) {
					System.out.println(line + " --> " + E_ERROR);
					continue;
				}
				
				System.out.println(line + " --> " + expression);
				
				//evaluate
				evaluate(expression, map);
				
				
			}
			in.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch(IOException e) {
			e.printStackTrace();
		}
		
		
	}
	
	/*
	 * isOperand(char operand) method
	 * - checks if passed in operand is present in the HashMap
	 * - returns boolean
	 * */
	static boolean isOperand(char operand, Map<Character, Double> map) {
		if(map.containsKey(operand))
				return true;
		return false;
	}
	
	/*
	 * convert(String infix) method
	 * - Converts passed in infix expression to a post-fix expression
	 * */
	static String convert(String infix, Map<Character, Double> map) {
		
		ArrayStack<Character> as = new ArrayStack<Character>(infix.length()); //creates a stack the size of the infix expression
		
		String post_expression = "";
		int index = 0;
		
		while(index < infix.length()) { //while there are elements in the array
		
			char current = infix.charAt(index);
			
			if(current == ' ') {
				index++;
				continue;
			}
			if(isOperand(current, map)) {
				//write to post-fix expression
				post_expression += current;
			}
			else if(current == '(') {
				as.push(current);
			}
			else if(current == ')') {
				while(as.top() != '(') {
					post_expression += as.pop();
				}
				as.pop(); //popped '(' and throw it away
			}
			
			else { //handle arithmetic operators
				
				while(!as.isEmpty() && in_stack.get(as.top()) > out_stack.get(current)) {
					post_expression += as.pop();
				}
				as.push(current);
			}
			
			index++;
			
		}//end while-loop
		
		while(!as.isEmpty()) {
			post_expression += as.pop();
		}
		
		return post_expression;
		
	}
	
	/*
	 * evaluate(String postfix) method
	 * - evaluates the post-fix expression
	 * */
	static void evaluate(String postfix, Map<Character, Double> map) {
		
		ArrayStack as = new ArrayStack(postfix.length());
		
		int index = 0;
		double temp = 0.00;
		
		while(index < postfix.length()) {
			
			char current = postfix.charAt(index);
			
			if(isOperand(current, map)) {
				as.push(current);
			}
			else {
				//pop and append
				char a = (char) as.pop();
				//pop and append
				char b = (char) as.pop();
				//evaluate and push
				switch(current) {
				case '+' :
					temp = map.get(a) + map.get(b);
					break;
				case '-' :
					temp = map.get(a) - map.get(b);
					break;
				case '*' :
					temp = map.get(a) * map.get(b);
					break;
				case '/' :
					temp = map.get(a) / map.get(b);
					break;
				case '%' :
					temp = map.get(a) % map.get(b);
					break;
				}
				map.put('z', temp);
				as.push('z');
			}
			
			index++;
		}
		if(as.size() == 1) {
			as.pop(); //this is the final result
		}
		else {
			System.out.println("There is an error");
		}
		
		
	}
	
	/*
	 * populate() method
	 * - populates HashMap and returns it
	 * */
	static Map<Character, Double> populate() throws IOException{
		Map<Character, Double> map = new HashMap<Character, Double>();
		System.out.print("Load Map File: ");
		BufferedReader in = new BufferedReader(new FileReader(getFile()));
		String line = "";
		while((line = in.readLine()) != null) {
			String parts[] = line.split(" = ");
			char c = parts[0].charAt(0);
			map.put(c, Double.parseDouble(parts[1].trim()));
		}
		in.close();
		
		return map;
		
	}
	
	/*
	 * generate() method
	 * - populates both in and out precedence maps
	 * */
	static void generate() {
		
		//populate out_stack Map
		out_stack.put('(', 100);
		out_stack.put('(', 0);
		out_stack.put('^', 6);
		out_stack.put('*', 3);
		out_stack.put('/', 3);
		out_stack.put('%', 3);
		out_stack.put('+', 1);
		out_stack.put('-', 1);
		
		//populate in_stack Map
		in_stack.put('(', 0);
		in_stack.put(')', null);
		in_stack.put('^', 5);
		in_stack.put('*', 4);
		in_stack.put('/', 4);
		in_stack.put('%', 4);
		in_stack.put('+', 2);
		in_stack.put('-', 2);
		
	}
	
	/*
	 * getFile() method
	 * - returns String representation of a possible file
	 * */
	static String getFile() {
		Scanner kb = new Scanner(System.in);
		return kb.nextLine();
	}
	
	/*
	 * match() method
	 * - returns boolean if parenthesis are valid
	 * */
	static boolean match(String s) {
		
		ParenMatch p = new ParenMatch();
		
		return p.parenMatch(s);
		
	}

}
