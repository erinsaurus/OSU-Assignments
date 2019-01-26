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
			//Update main_spec relationship table --- if entry with char_id already exists, replace it with new spec_id value
			if(!($stmt = $mysqli->prepare("INSERT INTO main_spec (char_id, spec_id) VALUES (?,?)
				ON DUPLICATE KEY UPDATE spec_id = VALUES(spec_id)"))){
				echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
			}
			if(!($stmt->bind_param("ss",$_POST['charName'],$_POST['main_spec']))){
			    echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
			}
			if(!$stmt->execute()){
			    echo "Execute failed: "  . $stmt->errno . " " . $stmt->error;
			} else {
			    echo "Successfully added or updated row in Main_Spec table.";
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