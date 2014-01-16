/**
 * LinkedList Tester Class
 * 
 * 
 * Written By Josh Harshman
 * All Rights Reserved 1/10/2014
 * 
 * */

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class LinkedListTester {

	public static void main(String ...args) {
		
		int choice = 0;
		int index, result;
		String r;
		Object obj;
		
		//initialize LinkedList reference
		LinkedList ll = new LinkedList();
		LinkedList sublist;
		
		Scanner kb = new Scanner(System.in);
		
		//Make a random collection of objects
		List<Object> collection1 = new ArrayList<Object>();
		collection1.add("Collection Item 1");
		collection1.add("Collection Item 2");
		collection1.add("Collection Item 3");
		collection1.add("Collection Item 4");
		
		do {
			
			promptMenu();
			choice = kb.nextInt();
			
			switch(choice) {
			case 1 :
				ll.add("TestSimpleAdd");
				break;
			case 2 :
				System.out.print("Enter index to insert test value: ");
				index = kb.nextInt();
				try {
					ll.add(index, "TestAddIndex");
				}catch(NullPointerException e) {
					e.printStackTrace();
				}
				break;
			case 3 :
				ll.addAll(collection1);
				break;
			case 4 :
				System.out.println("Max index to insert without failure is: " + (ll.size() - 1));
				System.out.print("Enter index: ");
				index = kb.nextInt();
				ll.addAll(index, collection1);
				break;
			case 5 :
				ll.addFirst("TestAddFirst");
				break;
			case 6 :
				ll.addLast("TestAddLast");
				break;
			case 7 :
				ll.clear();
				System.out.println("List Cleared...");
				break;
			case 8 :
				if(ll.contains("TestSimpleAdd")) {
					System.out.println("Contain Query Comes back true");
				}
				else {
					System.out.println("Contain Query Comes back false");
				}
				break;
			case 9 :
				try {
				if(ll.containsAll(collection1))
					System.out.println("Contains All in Collection");
				else {
					System.out.println("Does not contain in all in collection");
				}
				}catch(NullPointerException e) {
					e.printStackTrace();
				}
				break;
			case 10 :
				//test equals method
				if(ll.get(0).equals("TestAddFirst")) {
					System.out.println("Equals query comes back true");
				}
				else {
					System.out.println("Equals query comes back false");
				}
				break;
			case 11 :
				System.out.println(ll.get(0));
				break;
			case 12 :
				System.out.println("HashCode: " + ll.hashCode());
				break;
			case 13 :
				result = ll.indexOf("TestAddFirst");
				System.out.println("Resulting object at Index: " + result);
				break;
			case 14 :
				r = (ll.isEmpty())?"Is Empty":"Is Not Empty";
				System.out.println(r);
				break;
			case 15 :
				//Iterator()
				break;
			case 16 :
				result = ll.lastIndexOf("TestSimpleAdd");
				System.out.println("result: " + result);
				break;
			case 17 :
				//listiterator()
				break;
			case 18 :
				//listiterator(index)
				break;
			case 19 :
				System.out.print("Enter index: ");
				index = kb.nextInt();
				obj = ll.remove(index);
				System.out.println("Resulting Object: " + obj);
				break;
			case 20 :
				if(ll.remove("TestSimpleAdd")) {
					System.out.println("Node Object Removed From List");
				}
				else {
					System.out.println("Object does not exist in list");
				}
				break;
			case 21 :
				if(ll.removeAll(collection1)) {
					System.out.println("All nodes present in collection removed from list");
				}
				break;
			case 22 :
				if(ll.retainAll(collection1)) {
					System.out.println("All nodes present in collection are retained in list");
				}
				break;
			case 23 :
				System.out.print("Enter index: ");
				index = kb.nextInt();
				obj = ll.set(index, "ModifiedContent");
				break;
			case 24 :
				System.out.println("Size of list: " + ll.size());
				break;
			case 25 :
				//sublist
				break;
			case 26 :
				System.out.println(ll.toString());
				break;
				
			}
			
		}while(choice != 27);
		
		//upon clean program exit
		kb.close();
		System.out.println("Have a nice day! ^.^\n");
		
	}
	public static void promptMenu() {
		System.out.println("\nMain Menu");
		System.out.println("----------------------------------------");
		System.out.println("1.	Execute add(Object obj) function");
		System.out.println("2.	Execute add(int index, E element) function");
		System.out.println("3.	Execute addAll(Collection<E> c) function");
		System.out.println("4.	Execute addAll(int index, Collection<E> c) function");
		System.out.println("5.	Execute addFirst(E e) function");
		System.out.println("6.	Execute addLast(E e) function");
		System.out.println("7.	Execute clear() function");
		System.out.println("8.	Execute contains(Object obj) function");
		System.out.println("9.	Execute containsAll(Collection...) function");
		System.out.println("10.	Execute equals(Object obj) function");
		System.out.println("11.	Execute get(int index) function");
		System.out.println("12.	Execute hashCode() function");
		System.out.println("13.	Execute indexOf(Object obj) function");
		System.out.println("14.	Execute isEmpty() function");
		System.out.println("15.	Execute iterator() function");
		System.out.println("16.	Execute lastIndexOf() function");
		System.out.println("17.	Execute listIterator() function");
		System.out.println("18.	Execute listIterator(int index) function");
		System.out.println("19.	Execute remove(int index) function");
		System.out.println("20.	Execute remove(Object obj) function");
		System.out.println("21.	Execute removeAll(Collection<E> c) function");
		System.out.println("22.	Execute retainAll(Collection<E> c) function");
		System.out.println("23.	Execute set(int index, Object element) function");
		System.out.println("24.	Execute size() function");
		System.out.println("25.	Execute sublist(int fromIndex, int toIndex) function");
		System.out.println("26.	Execute toString() function");
		System.out.println("27.	Quit");
		System.out.println("----------------------------------------");
		System.out.print("~~>");
		
	}
	
}