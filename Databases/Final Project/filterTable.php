<html>
<head>
<!DOCTYPE html>
<html lang="en">
  <meta charset="utf-8">
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
        <table class="table table-hover"> <!--Displays the filtered character table-->
            <h3 class="labels">Filtered Character Table</h3>
            <thead>
              <tr>
                <td><b>Name</b></td>
                <td><b>Level</b></td>
                <td><b>Race</b></td>
                <td><b>Class</b></td>
                <td><b>iLevel</b></td>
                <td><b>Guild Rank</b></td>
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
            //Create table filtered by guild_rank and user input
            if(!($stmt = $mysqli->prepare("
                SELECT characters.name, characters.level, characters.race, characters.class, characters.iLevel, characters.guild_rank FROM characters
                WHERE characters.guild_rank = ?"))){
                echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
            }
            if(!($stmt->bind_param("s",$_POST['selection']))){
                            echo "Bind failed: "  . $stmt->errno . " " . $stmt->error;
                }
            if(!$stmt->execute()){
                echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
            }
            if(!$stmt->bind_result($name, $level, $race, $class, $iLevel, $guild_rank)){
                echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
            }
            while($stmt->fetch()){
                echo "<tr>\n<td>\n" . $name . "\n</td>\n<td>\n" . $level . "\n</td>\n<td>\n" . $race . "\n</td>\n<td>\n" . $class . "\n</td>\n<td>\n" . $iLevel . "\n</td>\n<td>\n". $guild_rank .  "\n</td>\n</tr>";
            }
            $stmt->close();
            ?>
        </table>
    </div> <br> <br>

    <!--Return to main page-->
    <form action="http://web.engr.oregonstate.edu/~alltope/CS340/index.php">
    <input type="submit" value="Return to Main Page"/>
    </form>
    </div>
</body>
</html>


