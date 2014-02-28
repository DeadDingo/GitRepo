
public class ParenMatch {
	
	public boolean parenMatch(String in) {
		ArrayStack<Character> stk = new ArrayStack<Character>();
		for(int i = 0; i < in.length(); i ++) {
			char cur = in.charAt(i);
			if( isOpen(cur) )
				stk.push(cur);
			else if( isClose(cur) ) {
				if( stk.isEmpty() )
					return false;
				if( ! isMatch(stk.pop(), cur) )
					return false;
			}
		}//end of for
		if( stk.isEmpty() )
			return true;
		else
			return false;
		
	}
	
	private boolean isOpen(char c) {
		return c == '(' || c == '{' || c == '[' ;
	}
	
	private boolean isClose(char c) {
		return c == ')' || c == '}' || c == ']' ;
	}
	
	private boolean isMatch(char c1, char c2) {
		//We assume in this method c2 is one of closing parens
		if(c2 == ')')
			return c1 == '(';
		if(c2 == ']')
			return c1 == '[';
		if(c2 == '}')
			return c1 == '{';
		return false;
	}

	/*
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String arr[] = {"( )(( )){([( )])}	", 
				        "((( )(( )){([( )])}",
				        ")(( )){([( )])}",
				        "({[ ])}",
				        "("
		};
		
		ParenMatch matcher = new ParenMatch();
		
		for( String s: arr) {
			boolean match = matcher.parenMatch( s );
			System.out.println("For input string:" + s + " is matched or not?--> " + match);
		}
	}
	 */
}

