<html>
<head>

<!--Table styling-->
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
        <table class="table table-hover"> 

        <!--Table displays current characters with their continents of origin, dynamically created-->
            <h3 class="labels">Character Continents of Origin</h3> 
            <thead>
              <tr>
                <td><b>Name</b></td>
                <td><b>Continent</b></td>
              </tr>
            </thead>

            <!-- Dynamically creating table-->
            <?php

	            //Turn on error reporting
				ini_set('display_errors', 'On');

				//Connect to the database
		 		$mysqli = new mysqli("classmysql.engr.oregonstate.edu","cs340_alltope","0944","cs340_alltope");

				if($mysqli->connect_errno){
					echo "Connection error " . $mysqli->connect_errno . " " . $mysqli->connect_error;
				}

				//Selects from relationship table via two foreign keys to characters and continents table
 	           if(!($stmt = $mysqli->prepare("
    	            SELECT characters.name, continents.name FROM is_from
        	        INNER JOIN characters ON char_id = characters.id
            	    INNER JOIN continents ON continent_id = continents.id
                	ORDER BY characters.name"))){
 	               echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
    	        }
        	    if(!$stmt->execute()){
            	    echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
	            }
    	        if(!$stmt->bind_result($cname, $continent)){
        	        echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
            	}
	            // loop through and display results
    	        while($stmt->fetch()){
        	        echo "<tr>\n<td>\n" . $cname . "\n</td>\n<td>\n" . $continent .  "\n</td>\n</tr>";
	            }
    	        $stmt->close();
            ?>
        </table>
    </div> <br> <br>



<div class="addMarginTop">
    <h3 class="labels">Add or Change Character Continent of Origin</h3>
  
    <form class="form-inline" method="post" action="addCharCont.php"> 
        <div class="form-group">
            
            <!--Dynamically populated drop down menu for characters-->
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

            <!--Dynamically populated drop down menu for Continents selection-->
            Continent: <select class="form-control" name="contName">
            
            <?php
                if(!($stmt = $mysqli->prepare("SELECT id, name FROM continents"))){
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
</body>
</html>