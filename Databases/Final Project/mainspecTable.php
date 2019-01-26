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
        <table class="table table-hover"> <!--This table displays characters and their main specs, dynamically populated-->
            <h3 class="labels">Character Main Specs</h3>
            <thead>
              <tr>
                <td><b>Name</b></td>
                <td><b>Main Spec</b></td>
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
			//Select and display characters and their specs, joining characters and specs table into the main_spec table
            if(!($stmt = $mysqli->prepare("
                SELECT characters.name, specs.name FROM main_spec
                INNER JOIN characters ON char_id = characters.id
                INNER JOIN specs ON spec_id = specs.id
                ORDER BY specs.name"))){
                echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
            }
            if(!$stmt->execute()){
                echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
            }
            if(!$stmt->bind_result($cname, $spec)){
                echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
            }
            // loop until there are no more results
            while($stmt->fetch()){
                echo "<tr>\n<td>\n" . $cname . "\n</td>\n<td>\n" . $spec .  "\n</td>\n</tr>";
            }
            $stmt->close();
        ?>

        </table>
    </div> <br> <br>

<!--Add or change the main spec of a character-->
<div class="addMarginTop">
    <h3 class="labels">Add or Change Main Spec</h3>
    <form class="form-inline" method="post" action="addUpdateMainSpec.php"> 
        <div class="form-group">
            
            <!--Dynamically populate drop down menu of characters for selection-->
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

          <!--Dynamically populate drop down menu of specs for selection-->
            Main Spec: <select class="form-control" name="main_spec">
            
            <?php
                if(!($stmt = $mysqli->prepare("SELECT id, name FROM specs"))){
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
         <br><br>

      <div class="form-group">             
          <button class="btn btn-primary" type="submit" value ="Submit"/>Submit</button>
      </div> 

    </form>
    </div>

	<!--Return to main page-->
	<form action="http://web.engr.oregonstate.edu/~alltope/CS340/index.php">
	<input type="submit" value="Return to Main Page"/>
	</form>
	</body>
	</html>