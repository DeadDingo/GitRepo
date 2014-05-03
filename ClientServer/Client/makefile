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
		gcc src/interpreter.c src/comms.c src/bot.c -o bot.out
		./bot.out 127.0.0.1 #connect to localhost

only:		src/bot.c
		gcc src/interpreter.c src/comms.c src/bot.c -o bot.out

clean:		bot.out
		rm -rf bot.out

cleanrun:	bot.out
		rm -rf bot.out
		gcc src/interpreter.c src/comms.c src/bot.c -o bot.out
		./bot.out 127.0.0.1 #connect to localhost