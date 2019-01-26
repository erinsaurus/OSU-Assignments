<html>
<head>
</head>
<body>
	<div class="container filters">
		<div>

			<?php
			//Connect to the database
			  $mysqli = new mysqli("classmysql.engr.oregonstate.edu","cs340_alltope","0944","cs340_alltope");
			if($mysqli->connect_errno){
				echo "Connection error " . $mysqli->connect_errno . " " . $mysqli->connect_error;
			}
			//Add a raid achievement to a character
			if(!($stmt = $mysqli->prepare("INSERT INTO completed (char_id, raid_id, difficulty) VALUES (?,?,?)"))){
				echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
			}
			if(!($stmt->bind_param("iis",$_POST['CharName'],$_POST['raidAch'],$_POST['difficulty']))){
			    echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
			}
			if(!$stmt->execute()){
			    echo "Oops! That is a duplicate value. Go back and try again."; //Give an error message if there is a duplicate unique key combination
			} else {
			    echo "Sucessfully added " . $stmt->affected_rows . " row to completed raid achievements table.";
			}
			?>
	
		</div><br><br>
	
	<!--Return to previous page-->
	<form action="http://web.engr.oregonstate.edu/~alltope/CS340/mainspecTable.php">
	<input type="submit" value="Return to Previous Page"/>
	</form>
	</div>
</body>
</html>