/**
 * LinkedList Tester Class
 * 
 * NOTE:  The extra credit has been attempted and completed.
 * 
 * Written By Josh Harshman
 * All Rights Reserved 1/10/2014
 * 
 * */

import java.util.Scanner;

public class LinkedListTester {

	public static void main(String ...args) {
		
		int choice = 0;
		
		Scanner kb = new Scanner(System.in);
		
		do {
			
			promptMenu();
			choice = kb.nextInt();
			
			switch(choice) {
			case 1 :
				//Execute menu item number 1
				break;
			case 2 :
				break;
			case 3 :
				break;
		
			}
			
		}while(choice != 9);
		
		//upon clean program exit
		kb.close();
		System.out.println("Have a nice day! ^.^\n");
		
	}
	public static void promptMenu() {
		System.out.println("\nMain Menu");
		System.out.println("----------------------------------------");
		System.out.println("1. ");
		System.out.println("2. ");
		System.out.println("3. ");
		System.out.println("----------------------------------------");
		System.out.print("~~>");
		
	}
	
}