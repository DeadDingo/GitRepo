#################################################
#						#
# MakeFile for Client				#
# Written By Josh Harshman			#
# May 2, 2014					#
#						#
# 			~voodoo			#
#						#
#################################################


bot.out:	src/bot.c
		gcc src/comms.c src/bot.c -o bot.out
		./bot.out 192.168.1.121

only:		src/bot.c
		gcc src/comms.c src/bot.c -o bot.out

clean:		
		rm -rf bot.out

cleanrun:	
		rm -rf bot.out
		gcc src/comms.c src/bot.c -o bot.out
		./bot.out 127.0.0.1 #connect to localhost