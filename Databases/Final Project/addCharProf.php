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
			//Add profession to a character
			if(!($stmt = $mysqli->prepare("INSERT INTO knows (char_id, profession_id) VALUES (?,?)"))){
				echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
			}
			if(!($stmt->bind_param("ii",$_POST['charName'],$_POST['profName']))){
			    echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
			}
			if(!$stmt->execute()){
			    echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
			} else {
			    echo "Sucessfully added " . $stmt->affected_rows . " row to known professions table.";
			}
		?>
		</div><br><br>
	
	<!--Return to previous page-->
	<form action="http://web.engr.oregonstate.edu/~alltope/CS340/knowsTable.php">
	<input type="submit" value="Return to Previous Page"/>
	</form>
	</div>
</body>
</html>
