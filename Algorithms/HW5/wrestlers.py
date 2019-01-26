#Erin Alltop
#11-1-17
#CS325 - Fall 2017
#Adapted from http://www.geeksforgeeks.org/bipartite-graph/

def giveColor(src, neighbor):
	if src.color == 'white':
		neighbor.color = 'black'
	elif src.color == 'black':
		neighbor.color = 'white'

class Graph():
	list_of_vertices = []
	color = ' '
	def __init__(self, vertex, color):
		self.vertex = vertex
		self.graph = [[0 for column in range(vertex)] \
                                for row in range(vertex)]
		Graph.list_of_vertices.append(self)
		Graph.list_of_vertices.append(vertex)
		self.color = color
 
    #returns true if graph is Bipartite
	def BabyHeels(self, src):
 
   		#adding colors to vertices
		colorArr = [-1] * self.vertex
 
        # Assign first color to source
		colorArr[src] = 1
	
        #queue to be used for BFS
		queue = []
		queue.append(src)
 
        #use BFS to check colors of vertices
		while queue:
 			u = queue.pop()

			for v in range(self.vertex):
               	# If there is an edge between two vertices and no color assigned, assign an alternate color
				if self.graph[u][v] == 1 and colorArr[v] == -1:
					colorArr[v] = 1 - colorArr[u]
					queue.append(v)
 
                #If there is an edge between two vertices and they have the same color, then return false
				elif self.graph[u][v] == 1 and colorArr[v] == colorArr[u]:
					return False

 		#of all vertices have opposite colors, return true
		return True

#open the file from the command line
import string
import sys
lines = []
data = open (sys.argv[1], "r")
f = file(sys.argv[1]).read()

#splits the text file line by line into words
for word in f.split():
	lines.append(word)
	#print word

#the number of wrestlers
numWrestlers = int(lines[0])
#print numWrestlers

#the number of rivalries
numRivalries = int(lines[numWrestlers+1])
#print numRivalries

newList = lines[numWrestlers+2:]
#print newList

#iterates through the rivalries and adds them as vertices to the graph
g = Graph(2, ' ')
it = iter(newList)
for x in it:
	g.graph = (x, next(it))

data.close() #close the file!


#These statements print out every other wrestler if 'Yes' or just 'No' if not
def altElement(lines, skip):
	print ', ' .join(lines[skip::2])

if g.BabyHeels(0):
	print "Yes"
	print "Babyfaces: ",
	altElement(newList, 0)
	print "Heels: ",
	altElement(newList, 1)
else:
	print "No"

#print g.list_of_vertices
