/**
 * LinkedList Tester Class
 * 
 * NOTE: Extra Credit Completed
 * 
 * Written By Josh Harshman
 * All Rights Reserved 1/10/2014
 * 
 * */

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.Scanner;


public class LinkedListTester {

	public static void main(String ...args) {
		
		int choice = 0;
		int index, fromIndex, result;
		String r;
		Object obj;
		
		//initialize LinkedList references
		LinkedList<Object> ll = new LinkedList<Object>();
		LinkedList<Object> sub = new LinkedList<Object>();
		
		//List Iterators
		Iterator<Object> it = null;
		ListIterator<Object> li = null;
		
		Scanner kb = new Scanner(System.in);
		
		//Random Collection of Objects
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
				index = getIndex(ll.size());
				ll.add(index, "TestAddIndex");
				break;
			case 3 :
				try {
					ll.addAll(collection1);
				}catch(NullPointerException e) {
					e.printStackTrace();
				}
				break;
			case 4 :
				index = getIndex(ll.size());
				try {
					ll.addAll(index, collection1);
				}catch(NullPointerException e) {
					e.printStackTrace();
				}catch(IllegalArgumentException e) {
					e.printStackTrace();
				}
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
					System.out.println("Contains Query Comes back true");
				}
				else {
					System.out.println("Contains Query Comes back false");
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
				try {
					if(ll.get(0).equals("TestAddFirst")) {
						System.out.println("Equals query comes back true");
					}
					else {
						System.out.println("Equals query comes back false");
					}
				}catch(IllegalArgumentException e) {
					System.out.println("List is empty");
					e.printStackTrace();
				}
				
				break;
			case 11 :
				index = getIndex(ll.size());
				try {
					System.out.println(ll.get(index));
				}catch(IllegalArgumentException e) {
					e.printStackTrace();
				}
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
				it = ll.iterator();
				System.out.println("Walking the list with an iterator: ");
				while(it.hasNext()) {
					System.out.println(it.toString());
					it.next();
				}
				break;
			case 16 :
				result = ll.lastIndexOf("TestSimpleAdd");
				if(result == -1) {
					System.out.println("No Matches");
				}
				else {
					System.out.println("result: " + result);
				}
				break;
			case 17 :
				li = ll.listIterator();
				while(li.hasNext()) {
					System.out.println(li.toString());
					li.next();
				}
				break;
			case 18 :
				index = getIndex(ll.size());
				li = ll.listIterator(index);
				while(li.hasNext()) {
					System.out.println(li.toString());
					li.next();
				}
				break;
			case 19 :
				try {
					index = getIndex(ll.size());
					obj = ll.remove(index);
					System.out.println("Resulting Object: " + obj);
				}catch(IllegalArgumentException e) {
					e.printStackTrace();
				}
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
				try {
					if(ll.removeAll(collection1)) {
					System.out.println("All nodes present in collection (if any) removed from list");
					}
				}catch(NullPointerException e) {
					e.printStackTrace();
				}
				break;
			case 22 :
				try {
					if(ll.retainAll(collection1)) {
					System.out.println("All nodes present in collection (if any) are retained in list");
					}
				}catch(NullPointerException e) {
					e.printStackTrace();
				}
				break;
			case 23 :
				try {
					index = getIndex(ll.size());
					obj = ll.set(index, "ModifiedContent");
				}catch(IllegalArgumentException e) {
					e.printStackTrace();
				}
				
				break;
			case 24 :
				System.out.println("Size of list: " + ll.size());
				break;
			case 25 :
				fromIndex = getIndex(ll.size());
				index = getIndex(ll.size());
				try {
					sub = (LinkedList<Object>) ll.subList(fromIndex, index);
				}catch(IndexOutOfBoundsException e) {
					e.printStackTrace();
				}catch(IllegalArgumentException e) {
					e.printStackTrace();
				}catch(NullPointerException e) {
					System.out.println("Original List is Empty");
					e.printStackTrace();
				}
				System.out.println(sub.toString());
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
	/**
	 * getIndex()
	 * 	helper method.  Helps with modularity of program
	 * 	prompts for input of index until valid index entered
	 * 	returns index
	 * NOTE:  For some reason, closing the scanner will end up in a no such element exception
	 * */
	public static int getIndex(int LinkedListSize) {
		int index;
		Scanner kb = new Scanner(System.in);
		System.out.println("Max Index available for insert: " + (LinkedListSize - 1));
		do {
			System.out.print("Enter Index: ");
			index = kb.nextInt();
		}while(index < 0 || index > LinkedListSize);
		return index;
	}
	
}