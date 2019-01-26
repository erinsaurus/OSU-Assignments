<html>

<head>

</head>
<body>

	<div class="container filters">
		<div>

		<table class="table table-hover">

    		<h3 class="labels">"Ancient Knowledge" Guild Characters</h3>
            <thead>
    		  <tr>
    			<td><b>Name</b></td>
    			<td><b>Level</b></td>
    			<td><b>Race</b></td>
    			<td><b>Class</b></td>
                  <td><b>Item Level</b></td>
                <td><b>Guild Rank</b></td>
    		  </tr>
            </thead>

			<?php
			//Turn on error reporting
			ini_set('display_errors', 'On');
			//Connects to the database
			
	 		$mysqli = new mysqli("classmysql.engr.oregonstate.edu","cs340_alltope","0944","cs340_alltope");
			if($mysqli->connect_errno){
				echo "Connection error " . $mysqli->connect_errno . " " . $mysqli->connect_error;
			}
			//insert a new character into the characters table based on the input from the user.

			If($_POST['Table'] == 'knows')) {
  			  // query to get all Doe records
  			  $query = "SELECT characters.name, professions.name FROM knows INNER JOIN characters ON char_id = characters.id INNER JOIN professions ON profession_id = professions.id";
}
			elseif($_POST['Table'] == 'completed') {
   			 // query to get all Earl records
  			  $query = "SELECT characters.name, raids.name, difficulty FROM completed INNER JOIN characters ON char_id = characters.id INNER JOIN raids ON raid_id = raids.id";
			} 
			elseif($_POST['Table'] == 'is_from') {
   			 // query to get all Earl records
  			  $query = "SELECT characters.name, continents.name FROM is_from INNER JOIN characters ON char_id = characters.id INNER JOIN continents ON continent_id = continents.id";
			}

			else {
   			 // query to get all records
   			 $query = "SELECT characters.name, specs.name FROM main_spec INNER JOIN characters ON char_id = characters.id INNER JOIN specs ON spec_id = specs.id";
}

			if(!($stmt = $mysqli->prepare($query))){
				echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;

			}
		if(!$stmt->execute()){
    			echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    		}
    		if(!$stmt->bind_result($name, $name)){
    			echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    		}
            // loop until there are no more results
    		while($stmt->fetch()){
     			echo "<tr>\n<td>\n" . $name  . $name . "\n</td>\n</tr>";
    		}
    		$stmt->close();
    		?>
	
		</div>
	
	<!-- button that will take you make to the main index page on clicking -->
		<form action="http://web.engr.oregonstate.edu/~alltope/CS340/index.php">
		<input type="submit" value="Return to Main Page"/>
		</form>


	</div>

</body>
</html>