<html>
<head>
</head>
<body>
	<div class="container filters">
		<div>
			<?php
				//Turn on error reporting
				ini_set('display_errors', 'On');

				//Connect to the database
				 $mysqli = new mysqli("classmysql.engr.oregonstate.edu","cs340_alltope","0944","cs340_alltope");

				if($mysqli->connect_errno){
					echo "Connection error " . $mysqli->connect_errno . " " . $mysqli->connect_error;
				}
				//insert a new character into the characters table
				if(!($stmt = $mysqli->prepare("INSERT INTO characters (name, level, race, class, iLevel, guild_rank) VALUES (?,?,?,?,?,?)"))){
					echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
				}
				if(!($stmt->bind_param("sissis",$_POST['name'],$_POST['level'],$_POST['race'],$_POST['class'],$_POST['iLevel'],$_POST['guild_rank']))){
				    echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
				}
				if(!$stmt->execute()){
				    echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
				} else {
				    echo "Successfully added " . $stmt->affected_rows . " row to character table.";
				}
			?>
		</div><br><br>
	
	<!--Return to main page-->
	<form action="http://web.engr.oregonstate.edu/~alltope/CS340/index.php">
	<input type="submit" value="Return to Main Page"/>
	</form>
	</div>
</body>
</html>