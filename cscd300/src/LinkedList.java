/**
 * Homework 1 - Linked Lists and HashTable
 * 
 * Written By Josh Harshman
 * All Rights Reserved 1/10/2014
 * 
 * */

import java.io.Serializable;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;


public class LinkedList implements List, Serializable, Cloneable {
	
	private Node head;
	private int size;
	
	/**
	 * isEmpty(void)
	 * 	tests for null list
	 * 	returns true or false
	 * */
	public boolean isEmpty() {
		return(this.head == null);
	}
	/**
	 * addFirst(Object d)
	 * 	adds node to beginning of list
	 * 	returns void
	 * */
	public void addFirst(Object data) {
		this.head = new Node(data, this.head);
		this.size++;
	}
	/**
	 * addLast(Object d)
	 * 	adds node to end of list
	 * 	returns void
	 * */
	public void addLast(Object data) {
		if(isEmpty()) {
			addFirst(data);
		}
		else {
			Node cur = head;
			while(cur.next != null) {
				cur = cur.getNext();
			}
			cur.next = new Node(data, null);
			this.size++;
		}
	}
	/**
	 * add(Object d)
	 * 	adds a node to the end of a list
	 * 	returns boolean
	 * */
	public boolean add(Object data) {
		
		if(isEmpty()) {
			addFirst(data);
			return true;
		}
		Node cur = head;
		while(cur.next != null) {
			cur = cur.getNext();
		}
		cur.next = new Node(data, null);
		this.size++;
		return true;
		
	}
	/**
	 * add(int index, Object d)
	 * 	adds node at index
	 * 	returns void
	 * */
	public void add(int index, Object data) {
		
		if(isEmpty()) {
			System.out.println("Empty List.  Adding as first node...");
			addFirst(data);
		}
		else {
			Node cur = head;
			int i = 0;
			while(cur.next != null || i != index) {
				cur = cur.getNext();
				i++;
			}
			
		}
	}
	
	

	/**
	 * Other Methods... handle this later..
	 * */
	@Override
	public int size() {
		// TODO Auto-generated method stub
		return 0;
	}
	@Override
	public boolean contains(Object o) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public Iterator iterator() {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public Object[] toArray() {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public Object[] toArray(Object[] a) {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public boolean remove(Object o) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public boolean containsAll(Collection c) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public boolean addAll(Collection c) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public boolean addAll(int index, Collection c) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public boolean removeAll(Collection c) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public boolean retainAll(Collection c) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public void clear() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public Object get(int index) {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public Object set(int index, Object element) {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public Object remove(int index) {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public int indexOf(Object o) {
		// TODO Auto-generated method stub
		return 0;
	}
	@Override
	public int lastIndexOf(Object o) {
		// TODO Auto-generated method stub
		return 0;
	}
	@Override
	public ListIterator listIterator() {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public ListIterator listIterator(int index) {
		// TODO Auto-generated method stub
		return null;
	}
	@Override
	public List subList(int fromIndex, int toIndex) {
		// TODO Auto-generated method stub
		return null;
	}
	
	
	/**
	 * Node Inner Class
	 * Defines the Node Object
	 * */
	private class Node {
	
		protected Object data; //allows storage of generic types
		protected Node next;
		
		public Node(Object data) {
			this(data, null);
		}
		public Node(Object data, Node next) {
			this.data = data;
			this.next = next;
		}
		public Object getData() {
			return data;
		}
		public void setData(Object data) {
			this.data = data;
		}
		public Node getNext() {
			return next;
		}
		public void setNext(Node next) {
			this.next = next;
		}
	} //End Node Inner Class
	
}
