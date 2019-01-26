#!/bin/python

"""
  Erin Alltop
  Project 1 - CS372 - Spring 2018
  This program is a simple server client that connects to a 
  corresponding client (chatclient.c)
  I used the lecture notes and a few other references in creating this program
  https://stackoverflow.com/questions/46872870/how-to-loop-until-input-is-the-right-length
  https://www.cyberciti.biz/faq/python-raw_input-examples/

  I used lecture notes from CS344 for handling and capturing the SIGINT
"""

from socket import *
import sys
import signal

# Handler to catch the SIGINT signal and exit program
def signal_handler(signal, frame):
	print("\nSIGINT received. Closing connection.")
	connectionSocket.close()
	sys.exit(0)

# This function exchanges server and client handles
def getClientHandle(connectionSocket, serverHandle):
	clientHandle = connectionSocket.recv(1024)
	connectionSocket.send(serverHandle)
	return clientHandle

# Receive the message from the client
def receiveMsg(connectionSocket):
	rMsg = connectionSocket.recv(500)
	return rMsg

# Send the message to the client
def sendMsg(connectionSocket, serverMsg):
	connectionSocket.send(serverMsg)

# Run chat application until "/quit" is received
def chatApp(connectionSocket, clientHandle, serverHandle):
	serverMsg = ""
	while 1:
		#clientMsg = connectionSocket.recv(500)
		clientMsg = receiveMsg(connectionSocket)

		#strip the newline character from the client's message
		clientMsg = clientMsg.rstrip()

		if "\quit" in clientMsg:
			print ("%s has closed the connection from the client." % clientHandle)
			print ("Hi %s! Waiting for a chat partner..." % serverHandle)
			break

		# print client message
		print ("{}> {}".format(clientHandle, clientMsg))

		serverMsg = ""
		while len(serverMsg) == 0 or len(serverMsg) > 500:
			serverMsg = raw_input("{}> ".format(serverHandle))

		if "\quit" in serverMsg:
			print ("Connection closed. Goodbye %s!" % clientHandle)
			print ("Hi %s! Waiting for a chat partner..." % serverHandle)
			break

		#connectionSocket.send(serverMsg)
		sendMsg(connectionSocket, serverMsg)

# Setup the socket, bind it to the port, and begin listening for a message
def generateConnection(TCP_PORT):
	s = socket(AF_INET, SOCK_STREAM)
	s.bind(('', int(TCP_PORT)))
	s.listen(1)
	return s

if __name__ == "__main__":

	# Check for corrrect number of arguments
	if len(sys.argv) != 2:
		print "Usage: ./chatserve [port]"
		exit(1)

	# Catch the SIGINT signal if received and close program
	signal.signal(signal.SIGINT, signal_handler)

	# Assign the user-generated port to TCP_PORT
	TCP_PORT = sys.argv[1]
	s = generateConnection(TCP_PORT)

	
	# Ask the user for their handle. Must be 10 character or less
	# I referenced this resource for assistance with the user input:
	# https://stackoverflow.com/questions/46872870/how-to-loop-until-input-is-the-right-length
	# https://www.cyberciti.biz/faq/python-raw_input-examples/
	serverHandle = ""
	while len(serverHandle) == 0 or len(serverHandle) > 10:
		serverHandle = raw_input("Please enter a handle up to 10 characters: ")
	print ("Hi %s! Waiting for a chat partner..." % serverHandle)

	# Connect and loop server until SIGINT is received
	# I referenced the lecture slide example for this part
	while 1:
		connectionSocket, address = s.accept()

		# Exchange user handles for chat
		clientHandle = getClientHandle(connectionSocket, serverHandle)
		print ("Connection successful! Chat initiated with %s." % clientHandle)

		# Start up the chat application
		chatApp(connectionSocket, clientHandle, serverHandle)

		connectionSocket.close()
