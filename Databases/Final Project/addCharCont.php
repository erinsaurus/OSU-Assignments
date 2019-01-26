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
				//Associate a character with a continent -- If the character ID is a duplicate, replace entry with new continent
				if(!($stmt = $mysqli->prepare("INSERT INTO is_from (char_id, continent_id) VALUES (?,?)
					ON DUPLICATE KEY UPDATE continent_id = VALUES(continent_id)"))){
					echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
				}
				if(!($stmt->bind_param("ii",$_POST['charName'],$_POST['contName']))){
				    echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
				}	
				if(!$stmt->execute()){
				    echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
				} else {
				    echo "Sucessfully added or updated row to known continent of origin table.";
				}
			?>
		</div><br><br>
	
	<!--Return to previous page-->
	<form action="http://web.engr.oregonstate.edu/~alltope/CS340/isfromTable.php">
	<input type="submit" value="Return to Previous Page"/>
	</form>
	</div>
</body>
</html>
