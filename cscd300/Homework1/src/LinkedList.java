/**
 * Homework 1 - Linked Lists and HashTable
 * 
 * NOTE: Extra Credit Completed!
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


public class LinkedList<E> implements Iterable<E>, List<E>, Cloneable {
	
	private Node<E> head;
	private int size;
	
	/**
	 * LinkedList DVC
	 * 	Initializes list with dummy head node
	 * 	keeps size at zero
	 * */
	public LinkedList() {
		this.head = new Node<E>(null); //initialize with dummy head node
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
	public void addFirst(E data) {
		Node<E> cur = this.head;
		cur.next = new Node<E>(data, cur.next);
		this.size++;
	}
	
	/**
	 * addLast(Object d)
	 * 	adds node to end of list
	 * 	returns void
	 * */
	public void addLast(E data) {
		if(isEmpty()) { 
			addFirst(data);
		}
		else {
			Node<E> cur = this.head;
			while(cur.next != null) {
				cur = cur.next;
			}
			cur.next = new Node<E>(data, null);
			size++;
		}
	}
	
	/**
	 * add(Object d)
	 * 	adds a node to the end of a list
	 * 	returns boolean
	 * */
	public boolean add(E data) {
		
		if(isEmpty()) { 
			addFirst(data);
			return true;
		}
		Node<E> cur = this.head;
		while(cur.next != null) {
			cur = cur.next;
		}
		cur.next = new Node<E>(data, null);
		size++;
		return true;
		
	}
	
	/**
	 * add(int index, Object d)
	 * 	adds node at index
	 * 	returns void
	 * */
	public void add(int index, E data) {
		
		if(isEmpty()) {
			System.out.println("Empty List. Ignoring index and Adding as first node...");
			addFirst(data);
		}
		else {
			Node<E> cur = head.next; //ignores the dummy node and starts the index counter at head.next
			for(int i = 0; i < index; i++) {
				cur = cur.next;
			}
			cur.next = new Node<E>(data, cur.next);
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
	public Iterator<E> iterator() {
		return new LstItr(this.head.next); //ignores dummy head node
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
		for(Node<E> prev = this.head, cur = this.head.next; cur != null; prev = cur, cur = cur.next) {
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
		
		Node<E> cur;
		boolean flag;
		
		if(c == null) {
			throw new NullPointerException("Collection is null");
		}
		
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
	public boolean addAll(Collection<? extends E> c) {
		
		Node<E> cur = this.head;
		Node<E> tail = null;
		
		if(c == null) {
			throw new NullPointerException("Collection is null");
		}
		
		//find the end of the list
		while(cur.next != null) {
			cur = cur.next;
		}
		tail = cur;
		for(E x : c) {
			//add onto end of list
			cur.next = new Node<E>(x, null);
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
	public boolean addAll(int index, Collection<? extends E> c) {
		
		Node<E> cur = this.head.next;
		//navigate to index of list
		if(index < 0 || index > size) {
			throw new IllegalArgumentException("Index Out of bounds at " + index + "\n");
		}
		if(c == null) {
			throw new NullPointerException("Collection is null");
		}
		
		for(int i = 0; i < index; i++) {
			cur = cur.next;
		}
		for(E x : c) {
			cur.next = new Node<E>(x, cur.next);
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
		
		Node<E> cur = this.head.next;  // skip past the dummy head node
		int index = 0;
		if(c == null) {
			throw new NullPointerException("Collection is empty");
		}
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
		
		Node<E> cur = this.head.next;
		int index = 0;
		if(c == null) {
			throw new NullPointerException("Collection is empty");
		}
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
	public E get(int index) {
		
		Node<E> cur = this.head.next;
		
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
	public E set(int index, E element) {
		
		Node<E> cur = this.head.next;
		E x;
		
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
	public E remove(int index) throws IllegalArgumentException {
		if(index < 0 || index >= this.size) {
			throw new IllegalArgumentException("Index out of bounds at " + index);
		}
		Node<E> cur, prev;
		cur = this.head.next;
		prev = null;
		E data;
		
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
	 * 	finds first occurrence of object in LinkedList
	 * 	returns the index of found object
	 * 	returns -1 if no object matched
	 * */
	@Override
	public int indexOf(Object obj) {
		Node<E> cur = this.head.next;
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
	 * 	finds last occurrence of object in LinkedList
	 * 	returns the index of the discovered last occurrence
	 * 	returns -1 if no matches
	 * */
	@Override
	public int lastIndexOf(Object obj) {
		
		Node<E> cur = this.head.next;
		int last = -1; //initialize to negative.  Will change if object is matched to an index
		
		for(int index = 0; index < size && cur != null; index++) {
			if(cur.data.equals(obj)) {
				last = index;
			}
			cur = cur.next;
		}
		
		return last; //if return -1, no matches
	}

	@Override
	public ListIterator<E> listIterator() {
		return new LinkedListIterator();
	}

	@Override
	public ListIterator<E> listIterator(int index) {
		return new LinkedListIterator(index);
	}

	@Override
	public List<E> subList(int fromIndex, int toIndex) {
		
		if(fromIndex < 0 || toIndex > size)
			throw new IndexOutOfBoundsException("Index is out of bounds");
		if(fromIndex > toIndex)
			throw new IllegalArgumentException("Indicies are swapped");
		LinkedList<E> sublist = new LinkedList<E>();
		Node<E> cur = this.head.next;
		for(int i = 0; i < fromIndex; i++, cur = cur.next); // run to end of list
		for(int i = 0; i <= toIndex; i++) {
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
		Node<E> cur = this.head;
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
		for(Node<E> node = this.head; node != null; node = node.next) {
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
	private class Node<E> {
	
		protected E data; //allows storage of generic types
		protected Node<E> next;
		
		public Node() {
			data = null;
			next = null;
		}
		public Node(E data) {
			this(data, null);
		}
		public Node(E data, Node<E> next) {
			this.data = data;
			this.next = next;
		}
		public E getData() {
			return data;
		}
		public void setData(E data) {
			this.data = data;
		}
		public Node<E> getNext() {
			return next;
		}
		public void setNext(Node<E> next) {
			this.next = next;
		}
		
	} //End Node Inner Class
	
	//========================================
	//Iterator inner class
	//========================================
	
	/**
	 * LinkedList Iterator
	 * */
	public class LstItr implements Iterator<E> {
		
		private Node<E> nextNode; //points to the node we are about to access
		private int index;
		
		public LstItr(Node<E> start) {
			this.nextNode = start;
			this.index = 0;
		}
		
		@Override
		public boolean hasNext() {
			return nextNode != null;
		}

		@Override
		public E next() {
			if(!hasNext()) throw new NoSuchElementException();
			E res = nextNode.data;
			nextNode = nextNode.next;
			return res;
		}
		//Added toString() method to print out individual node data
		public String toString() {
			return " [ " + nextNode.data + " ] ";
		}

		@Override
		public void remove() {
			throw new UnsupportedOperationException();
		}
		
	}
	//end iterator inner class
	//========================================
	
	//========================================
	//LinkedListIterator inner class
	//========================================
	
	public class LinkedListIterator implements ListIterator<E> {

		private Node<E> nextNode;
		private int index;
		
		public LinkedListIterator() {
			nextNode = head.next;
			index = 0;
		}
		public LinkedListIterator(int index) {
			nextNode = head.next;
			this.index = index;
			for(int i = 0; i < index; i++) {
				nextNode = nextNode.next;
			}
		}
		@Override
		public boolean hasNext() {
			return nextNode != null;
		}

		@Override
		public E next() {
			if(!hasNext()) throw new NoSuchElementException("Element Does Not Exisit");
			E res = nextNode.data;
			nextNode = nextNode.next;
			index++;
			return res;
		}

		@Override
		public boolean hasPrevious() {
			if(index > 0) 
				return true;
			return false;
		}

		@Override
		public E previous() {
			for(int i = 0; i < (index-1); i++) {
				nextNode = nextNode.next;
			}
			return nextNode.data;
			
		}

		@Override
		public int nextIndex() {
			return index;
		}

		@Override
		public int previousIndex() {
			return index - 1;
		}
		//added toString() method
		@Override
		public String toString() {
			return " [ " + nextNode.data + " ] ";
		}

		@Override
		public void remove() {
			throw new UnsupportedOperationException("Operation Not Supported");
			
		}

		@Override
		public void set(E e) {
			throw new UnsupportedOperationException("Operation Not Supported");
			
		}

		@Override
		public void add(E e) {
			throw new UnsupportedOperationException("Operation Not Supported");
			
		}
		
	}
	
}
