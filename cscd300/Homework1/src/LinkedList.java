/**
 * Homework 1 - Linked Lists and HashTable
 * 
 * Written By Josh Harshman
 * All Rights Reserved 1/10/2014
 * 
 * */

import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.NoSuchElementException;


public class LinkedList implements Iterable<Object>, List<Object>, Cloneable {
	
	private Node head;
	private int size;
	
	/**
	 * LinkedList DVC
	 * 	Initializes list with dummy head node
	 * 	keeps size at zero
	 * */
	public LinkedList() {
		this.head = new Node(null); //initialize with dummy head node
		this.size = 0;
	}
	
	/**
	 * isEmpty(void)
	 * 	tests for null list
	 * 	returns boolean
	 * */
	public boolean isEmpty() {
		return(this.head.next == null); //means there is nothing after the dummy head node
	}
	
	/**
	 * addFirst(Object d)
	 * 	adds node to beginning of list
	 * 	returns void
	 * */
	public void addFirst(Object data) {
		Node cur = this.head;
		cur.next = new Node(data, cur.next);
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
			Node cur = this.head;
			while(cur.next != null) {
				cur = cur.next;
			}
			cur.next = new Node(data, null);
			size++;
		}
	}
	
	/**
	 * add(Object d)
	 * 	adds a node to the end of a list
	 * 	returns boolean
	 * */
	public boolean add(Object data) {
		
		if(isEmpty()) { //edge case
			addFirst(data);
			return true;
		}
		Node cur = this.head;
		while(cur.next != null) {
			cur = cur.next;
		}
		cur.next = new Node(data, null);
		size++;
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
			Node cur = head.next; //ignores the dummy node and starts the index counter at head.next
			for(int i = 0; i < index; i++) {
				cur = cur.next;
			}
			cur.next = new Node(data, cur.next);
			size++;
		}
	}
	
	/**
	 * int size(void)
	 * 	returns the number of nodes in the list
	 * */
	@Override
	public int size() {
		return size;
	}
	
	/**
	 * boolean contains(Object obj)
	 * 	searches for the node containing specified object
	 * 	returns boolean
	 * */
	@Override
	public boolean contains(Object obj) {
		for(Object x : this) {
			if(x.equals(obj)) {
				return true;
			}
		}
		return false;
	}

	/**
	 * Iterator<E> iterator(void)
	 * 	returns a new linkedlist iterator
	 * */
	@Override
	public Iterator<Object> iterator() {
		return new LinkedListIterator(this.head.next); //ignores dummy head node
	}

	/**
	 * Unsupported Operation
	 * */
	@Override
	public Object[] toArray() {
		throw new UnsupportedOperationException();
	}

	/**
	 * Unsupported Operation
	 * */
	@Override
	public <T> T[] toArray(T[] a) {
		throw new UnsupportedOperationException();
	}

	/**
	 * boolean remove(Object obj)
	 * 	removes first instance of node specified by object
	 * 	returns boolean
	 * */
	@Override
	public boolean remove(Object obj) {
		if(isEmpty() || obj == null) {
			return false;
		}
		for(Node prev = this.head, cur = this.head.next; cur != null; prev = cur, cur = cur.next) {
			if(cur.data.equals(obj)) {
				prev.next = cur.next;
				this.size--;
				return true;
			}
		}
		return false;
	}

	/**
	 * boolean containsAll(Collection<?> c)
	 * 	tests to see if collection is equal to the list
	 * 	returns boolean
	 * */
	@Override
	public boolean containsAll(Collection<?> c) {
		
		Node cur;
		boolean flag;
		
		for(Object x : c) {
			cur = this.head.next;
			flag = false;
			while(cur != null) { //fixed!
				if(cur.data.equals(x)) {
					flag = true;
				}
				cur = cur.next;
			}
			if(!flag)
				return false;
		}
		return true;
	}

	@Override
	public boolean addAll(Collection<? extends Object> c) {
		
		Node cur = this.head;
		Node tail = null;
		
		//find the end of the list
		while(cur.next != null) {
			cur = cur.next;
		}
		tail = cur;
		for(Object x : c) {
			//add onto end of list
			cur.next = new Node(x, null);
			this.size++;
			cur = cur.next;
		}
		if(!cur.data.equals(tail.data)) {
			return true; //shows that the tail of the list has changed 
		}
		return false;
	}

	/**
	 * addAll(int index, Collection<? extends Object c)
	 * 	inserts a collection at a specific index of the list
	 * 	throws IllegalArgumentException if index is out of bounds
	 * 	returns true after list is inserted
	 * */
	@Override
	public boolean addAll(int index, Collection<? extends Object> c) {
		
		Node cur = this.head.next;
		//navigate to index of list
		if(index < 0 || index > size) {
			throw new IllegalArgumentException("Index Out of bounds at " + index + "\n");
		}
		
		for(int i = 0; i < index; i++) {
			cur = cur.next;
		}
		for(Object x : c) {
			cur.next = new Node(x, cur.next);
			this.size++;
			cur = cur.next;
		}
		
		return true;
	}

	/**
	 * boolean removeAll(Collection<?> c)
	 * 	Removes from list all contained in the collection
	 * 	operations handled by ON/OFF Flags
	 * 	returns boolean
	 * */
	@Override
	public boolean removeAll(Collection<?> c) {
		
		Node cur = this.head.next;  // skip past the dummy head node
		int index = 0;
		boolean rem = false; //removal flag
		while(cur != null) {
			for(Object x : c) {
				if(cur.data.equals(x)) {
					rem = true;
					break;
				}
				rem = false;
			}
			if(rem) {
				remove(cur.data);
			}
			cur = cur.next;
			index++;
		}
		return true;
	}

	/**
	 * boolean retainAll(Collection<?> c)
	 * 	retains only the elements in the linked list that are present in the collection
	 * 	removes all other nodes containing data that is not in the collection
	 * 	operations handled by "ON/OFF" flags
	 * 	returns boolean
	 * */
	@Override
	public boolean retainAll(Collection<?> c) {
		
		Node cur = this.head.next;
		int index = 0;
		boolean rem = false;
		while(cur != null) {
			
			for(Object x : c) {
				if(cur.data.equals(x)) {
					rem = false;
					break;
				}
				rem = true;
				
			}
			if(rem) {
				remove(cur.data);
			}
			
			cur = cur.next;
			index++;
		}
		return true;
	}

	/**
	 * clear(void)
	 * 	clears list by losing the head node's next pointer
	 * 	resets size to zero
	 * */
	@Override
	public void clear() {
		head.setNext(null);
		size = 0;
	}

	/**
	 * Object get(int index)
	 * 	"gets" the data in the node specified by the index
	 * 	throws IllegalArgumentException if index is invalid for size of list
	 * 	returns Object
	 * */
	@Override
	public Object get(int index) {
		
		Node cur = this.head.next;
		
		if(index < 0 || index >= size) {
			throw new IllegalArgumentException("Index Out of Bounds of List: " + index);
		}
		for(int i = 0; i < index && cur.next != null; i++) {
			cur = cur.next;
		}
		if(cur.data == null) {
			return null;
		}
		return cur.data;
	}

	/**
	 * Object set(int index, Object element)
	 * 	modifies the data element at the specified node
	 * 	the node is specified by the index parameter
	 * 	throws IllegalArgumentException if index is invalid for size of list
	 * 	returns Object
	 * */
	@Override
	public Object set(int index, Object element) {
		
		Node cur = this.head.next;
		Object x;
		
		if(index < 0 || index >= size) {
			throw new IllegalArgumentException("Index Out of Bounds " + index);
		}
		for(int i = 0; i < index && cur.next != null; i++) {
			cur = cur.next;
		}
		x = cur.data;
		cur.data = element; //over-write existing data
		return x;
	}

	/**
	 * Object remove(int index)
	 * 	Removes node at specified index
	 * 	throws IllegalArgumentException for index out of bounds of list size
	 * 	returns removed node's data element
	 * */
	@Override
	public Object remove(int index) throws IllegalArgumentException {
		if(index < 0 || index >= this.size) {
			throw new IllegalArgumentException("Index out of bounds at " + index);
		}
		Node cur, prev;
		cur = this.head.next;
		prev = null;
		Object data;
		
		if(index == 0) {
			data = this.head.next.data;
			this.head.next = this.head.next.next;
			this.size--;
			return data;
		}
		
		for(int i = 0; i < index; i++) {
			prev = cur;
			cur = cur.next;
		}
		prev.next = cur.next;
		this.size--;
		return cur.data;
	}

	/**
	 * int indexOf(Object obj)
	 * */
	@Override
	public int indexOf(Object obj) {
		Node cur = this.head.next;
		for(int index = 0; index < size && cur != null; index++) {
			if(cur.data.equals(obj)) {
				return index;
			}
			cur = cur.next;
		}
		return -1; //indicates failure to locate
	}

	/**
	 * int lastIndexOf(Object obj)
	 * 	finds last occurrence of object in linkedlist
	 * 	returns the index of the discovered last occurrence
	 * */
	@Override
	public int lastIndexOf(Object obj) {
		
		Node cur = this.head.next;
		int last = -1; //initialize to negative.  Will change if object is matched to an index
		
		for(int index = 0; index < size && cur != null; index++) {
			if(cur.data.equals(obj)) {
				last = index;
			}
		}
		
		return last; //if return -1, no matches
	}

	@Override
	public ListIterator<Object> listIterator() {
		// TODO Auto-generated method stub
		//implement another inner class to handle this
		return null;
	}

	@Override
	public ListIterator<Object> listIterator(int index) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public List<Object> subList(int fromIndex, int toIndex) {
		//initialize sublist
		LinkedList sublist = new LinkedList();
		Node cur = this.head;
		for(int i = 0; i <= toIndex && i >= fromIndex; i++) {
			sublist.add(cur.data);
			cur = cur.next;
		}
		return sublist;
	}
	/**
	 * toString(void)
	 * runs through list and returns a string object to print
	 * */
	@Override
	public String toString() {
		String result = "Contents:\n";
		Node cur = this.head;
		int i = 0;
		while(cur != null) {
			if(i % 4 == 0) {
				result += "\n";
			}
			result +=  " [ " + cur.data + " ] --> ";
			cur = cur.next;
			i++;
		}
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if(this == obj) {
			return true;
		}
		return false;
	}
	@Override
	public int hashCode() {
		final int PRIME = 31;
		int result = 1;
		for(Node node = this.head; node != null; node = node.next) {
			result = PRIME * result + node.hashCode();
		}
		return result;
	}
	
	
	
	//=========================================
	//Node Inner Class
	//=========================================

	/**
	 * Node Inner Class
	 * Defines the Node Object
	 * Change access to private.  Encapsulate inside LinkedList
	 * */
	private class Node {
	
		protected Object data; //allows storage of generic types
		protected Node next;
		
		public Node() {
			data = null;
			next = null;
		}
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
		private LinkedList getOuterType() {
			return LinkedList.this;
		}
		
	} //End Node Inner Class
	
	//========================================
	//Iterator inner class
	//========================================
	
	/**
	 * LinkedList Iterator
	 * */
	public class LinkedListIterator implements Iterator<Object> {
		
		private Node nextNode; //points to the node we are about to access
		private int index;
		
		public LinkedListIterator(Node start) {
			this.nextNode = start;
			this.index = 0;
		}
		
		@Override
		public boolean hasNext() {
			return nextNode != null;
		}

		@Override
		public Object next() {
			if(!hasNext()) throw new NoSuchElementException();
			Object res = nextNode.data;
			nextNode = nextNode.next;
			return res;
		}

		@Override
		public void remove() {
			throw new UnsupportedOperationException();
		}
		
	}
	//end iterator inner class
	//========================================
	
}
