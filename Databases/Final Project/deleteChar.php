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
				//delete character from the character table
				if(!($stmt = $mysqli->prepare("DELETE FROM characters WHERE id = ?"))){
					echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
				}
				if(!($stmt->bind_param("i",$_POST['charName']))){
				    echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
				}
				if(!$stmt->execute()){
				    echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
				} else {
				    echo "Successfully deleted " . $stmt->affected_rows . " character from Characters table.";
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

