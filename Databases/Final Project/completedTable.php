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
        <table class="table table-hover"> <!--Table displays all characters and their raid achievements. Many-to-Many relationship-->
            <h3 class="labels">Character Raid Achievements</h3>
            <thead>
              <tr>
                <td><b>Name</b></td>
                <td><b>Raid</b></td>
                <td><b>Difficulty</b></td>
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
			//display character and raid names from 'completed' relationship table. Joins respective tables and orders by character name
            if(!($stmt = $mysqli->prepare("
                SELECT characters.name, raids.name, difficulty FROM completed
                INNER JOIN characters ON char_id = characters.id
                INNER JOIN raids ON raid_id = raids.id
                ORDER BY characters.name"))){
                echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
            }
            if(!$stmt->execute()){
                echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
            }
            if(!$stmt->bind_result($cname, $rname, $difficulty)){
                echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
            }
            while($stmt->fetch()){
                echo "<tr>\n<td>\n" . $cname . "\n</td>\n<td>\n" . $rname . "\n</td>\n<td>\n" . $difficulty .  "\n</td>\n</tr>";
            }
            $stmt->close();
            ?>

        </table>
    </div> <br> <br>

<div class="addMarginTop">
    <h3 class="labels">Add Raid Achievement to Character</h3>
    <form class="form-inline" method="post" action="addCharRaidAch.php"> 
        <div class="form-group">
            
            <!--Dropdown menu is dynamically populated from characters table-->
            Character: <select class="form-control" name="CharName">
            
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

            <!--Dropdown menu is dynamically populated from raids table-->
            Raid: <select class="form-control" name="raidAch">
            
            <?php
                if(!($stmt = $mysqli->prepare("SELECT id, name FROM raids"))){
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

            <!--Dropdown menu with static values for raid difficulties (do not change)-->
            Difficulty: <select class="form-control" name="difficulty">  
                <option value="Raid Finder">Raid Finder</option>
                <option value="Normal">Normal</option>
                <option value="Heroic">Heroic</option>
                <option value="Mythic">Mythic</option>
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