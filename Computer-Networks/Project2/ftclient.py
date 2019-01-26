# *********************************************************************
# ** Erin Alltop
# ** CS372 - Spring 2018
# ** Project 2
# ** This is a simple client to be used in conjunction with ftserver.c.
# ** Together they create a server-client relationship for a file
# ** transfer program. The client can view contents of a directory
# ** and files on the server over a TCP connection. 
# ** I referenced the lecture slides and Project 1 for a lot of this.
# *********************************************************************/

from socket import *
import sys
import signal

# Handler to catch the SIGINT signal and exit program
#def signal_handler(signal, frame):
#	print("\nSIGINT received. Closing connection.")
#	connectionSocket.close()
#	sys.exit(0)

# Setup the socket, bind it to the port, and begin listening for a message
def generateDataConnection(TCP_PORT):
	s = socket(AF_INET, SOCK_STREAM)
	s.bind(('', int(TCP_PORT)))
	s.listen(1)
	return s

# This function exchanges server and client handles
def getDirectory(connectionSocket):
	filename = connectionSocket.recv(100)
	while filename != "done":
		print filename
		filename = connectionSocket.recv(100)

# Get the file contents from the server.
# Continue looping until terminating work is found.
def receiveFile(connectionSocket, fileName):
    newFile = open(fileName, "w")
    print "Requesting file.."
    # grab the bufferred output from the server
    fileContents = connectionSocket.recv(1024)

    if fileContents == "File not found.":
    	print "File not found on server."
    	return
 
    # loop until terminating word is found.
    # write contents to new file
    while "__done__" not in fileContents:
        newFile.write(fileContents)
        fileContents = connectionSocket.recv(1024)
    print "transfer complete"


# I referenced the lecture slides for setting this up
def initiateContact(serverName, serverPort, command, fileName, dataPort):
	clientSocket = socket(AF_INET, SOCK_STREAM)
	clientSocket.connect((serverName, serverPort))
	clientSocket.send(command + "," + fileName + "," + serverName + "," + dataPort)
	serverReply = clientSocket.recv(1024)
	#print serverReply
	if serverReply == "Server error: Invalid command.":
		exit(1)
	print ("TCP Control Connection established.")
	return clientSocket


if __name__ == "__main__":

	# Check for correct number of arguments
	if len(sys.argv) < 5:
		print "Not enough arguments"
		exit(1)

	# assign the various arguments to their correct varibles
	if len(sys.argv) == 6:
		serverName = sys.argv[1]
		serverPort = int(sys.argv[2])
		command = sys.argv[3]
		fileName = sys.argv[4]
		dataPort = sys.argv[5]
		if command == "-l":
			print "Client error: Too many arguments."
			exit(1)

	if len(sys.argv) == 5:
		serverName = sys.argv[1]
		serverPort = int(sys.argv[2])
		command = sys.argv[3]
		dataPort = sys.argv[4]
		fileName = " "
		if command == "-g":
			print "Client error: Not enough arguments."
			exit(1)


	clientSocket = initiateContact(serverName, serverPort, command, fileName, dataPort);
	

	# Catch the SIGINT signal if received and close program
#	signal.signal(signal.SIGINT, signal_handler)

	# setup the data connection
	s = generateDataConnection(dataPort)
	print ("TCP Data Connection established.")

	# connect data connection
	while 1:
		connectionSocket, address = s.accept()
		if command == "-l":
			getDirectory(connectionSocket)
		elif command == "-g":
			receiveFile(connectionSocket, fileName)
		connectionSocket.close()
		break

	# Always close the client socket
	print "Control connection closed."
	clientSocket.close() 
