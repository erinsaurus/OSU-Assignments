<html>
<head>
<style>
table {
    font-family: arial, sans-serif;
    border-collapse: collapse;
    width: 50%;
}

td, th {
    border: 1px solid #dddddd;
    text-align: left;
    padding: 8px;
}

tr:nth-child(even) {
    background-color: #dddddd;
}
</style>
</head>
<body>
    <div class="addMarginTop">
        <table class="table table-hover"> <!--Table displays all of the characters and their professions in the game. Many-to-Many relationship-->
            <h3 class="labels">Character Professions</h3>
            <thead>
              <tr>
                <td><b>Name</b></td>
                <td><b>Profession</b></td>
              </tr>
            </thead>

         <?php
            //Turn on error reporting
			ini_set('display_errors', 'On');

			//Connect to the database
	 		$mysqli = new mysqli("classmysql.engr.oregonstate.edu","cs340_alltope","0944","cs340_alltope");

			if($mysqli->connect_errno){
				echo "Connection error " . $mysqli->connect_errno . " " . $mysqli->connect_error;
			}
			//Select character and profession names from knows relationship table, joining respective tables. Order by character name.
            if(!($stmt = $mysqli->prepare("
                SELECT characters.name, professions.name FROM knows
                INNER JOIN characters ON char_id = characters.id
                INNER JOIN professions ON profession_id = professions.id
                ORDER BY characters.name"))){
                echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
            }
            if(!$stmt->execute()){
                echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
            }
            if(!$stmt->bind_result($name, $profession)){
                echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
            }
            while($stmt->fetch()){
                echo "<tr>\n<td>\n" . $name . "\n</td>\n<td>\n" . $profession .  "\n</td>\n</tr>";
            }
            $stmt->close();
         ?>

        </table>
    </div> <br> <br>

    
<div class="addMarginTop"> <!--Add a profession to be known by a character-->
    <h3 class="labels">Add Profession to Character</h3>
    <form class="form-inline" method="post" action="addCharProf.php"> 
        <div class="form-group">

            <!--Dropdown menu is dynamically populated from characters table-->
            Character: <select class="form-control" name="charName">
            
            <?php
                if(!($stmt = $mysqli->prepare("SELECT id, name FROM characters"))){
                    echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
                }
                if(!$stmt->execute()){
                    echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
                }
                if(!$stmt->bind_result($id, $name)){
                    echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
                }
                while($stmt->fetch()){
                    echo '<option value=" '. $id . ' "> ' . $name . '</option>\n';
                }
                $stmt->close();
            ?>
            </select>

            <!--Dropdown menu is dynamically populated from characters table-->
            Profession: <select class="form-control" name="profName">
            
            <?php
                if(!($stmt = $mysqli->prepare("SELECT id, name FROM professions"))){
                    echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
                }
                if(!$stmt->execute()){
                    echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
                }
                if(!$stmt->bind_result($id, $name)){
                    echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
                }
                while($stmt->fetch()){
                    echo '<option value=" '. $id . ' "> ' . $name . '</option>\n';
                }
                $stmt->close();
            ?>
            </select><br><br>

       <div class="form-group">        
            <button class="btn btn-primary" type="submit" value ="Submit"/>Submit</button>
        </div> 
      </form>
      </div>


	<!--Return to main page-->
	<form action="http://web.engr.oregonstate.edu/~alltope/CS340/index.php">
	<input type="submit" value="Return to Main Page"/>
	</form>
	</div>
</body>
</html>