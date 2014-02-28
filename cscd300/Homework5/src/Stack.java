/**
 * Stack.java
 * 
 * Written By Josh Harshman
 * February 24, 2014
 * 
 * */

public interface Stack<E> {
	
	public int size();
	
	public boolean isEmpty();
	
	public E top() throws EmptyStackException;

	public void push(E element);
	
	public E pop() throws EmptyStackException;

}
