<html>
<head>

  <meta charset="utf-8">

<h1 align="center">Word of Warcraft Database</h1>
<h2 align="center">"Ancient Knowledge" Guild</h2>

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

<?php 
    //Turn on error reporting
    ini_set('display_errors', 'On');

    //Connect to the database
    $mysqli = new mysqli("classmysql.engr.oregonstate.edu","cs340_alltope","0944","cs340_alltope");
?>

<div class="container marginBottom"> <!-- CONTAINER TO WRAP ENTIRE HTML -->
    <div class="addMarginTop">
    	<table class="table table-hover"> <!--Table displayed dynamically populated table of characters-->
    		<h3 class="labels">Guild Characters</h3>
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
    		if(!($stmt = $mysqli->prepare("
                SELECT characters.name AS 'Name', characters.level AS 'Level', characters.race AS 'Race', characters.class AS 'Class', characters.iLevel AS 'iLevel', characters.guild_rank AS 'Guild Rank'
                FROM characters;"))){
    			echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
    		}
    		if(!$stmt->execute()){
    			echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    		}
    		if(!$stmt->bind_result($name, $level, $race, $class, $iLevel, $guild_rank)){
    			echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    		}
    		while($stmt->fetch()){
     			echo "<tr>\n<td>\n" . $name . "\n</td>\n<td>\n" . $level . "\n</td>\n<td>\n" . $race . "\n</td>\n<td>\n" . $class . "\n</td>\n<td>\n" . $iLevel . "\n</td>\n<td>\n" . $guild_rank . "\n</td>\n</tr>";
    		}
    		$stmt->close();
    	?>
    	</table>
    </div><br><br>

<div class="addMarginTop"> <!--Filtering option by guild rank-->
    <h3 class="labels">Filter Characters by Guild Rank</h3>

    <form class="form-inline" method="post" action="filterTable.php">         
          
            Filter By: <select class="form-control" name="selection"> 
                <option value="Alt">Alt</option>
                <option value="Initiate">Initiate</option>
                <option value="Acolyte">Acolyte</option>
                <option value="Raider">Raider</option>
                <option value="Templar">Templar</option>
                <option value="Magister">Magister</option>
                <option value="Guild Master">Guild Master</option>
            </select>

            <button class="btn btn-primary" type="submit" value ="Submit"/>Submit</button>
    </form>
</div><br><br>


<div class="addMarginTop"> <!--Radio button to select a character table to view. This displays all relationship tables-->
    <h3 class="labels">View Character Tables</h3>

   <form>
        <input type="RADIO" name="button" value="profButton" data-href="knowsTable.php" checked>&nbsp;Professions<BR></BR>
        <input type="RADIO" name="button" value="raidButton" data-href="completedTable.php">&nbsp;Raid Achievements<BR>   </BR>
        <input type="RADIO" name="button" value="mainspecButton" data-href="mainspecTable.php">&nbsp;Main Specs<BR>  </BR>
        <input type="RADIO" name="button" value="contButton" data-href="isfromTable.php">&nbsp;Continents of Origin<BR>  </BR>
       <!-- <input type="submit" value="View Table" id="btnSubmit">-->
       <button class="btn btn-primary" type="submit" value="View Table" id="btnSubmit"/>View Table</button>
    </form> 

<!--Javascript to redirect button selection to appropriate page-->
<script>
    var submit = document.getElementById('btnSubmit');
    submit.addEventListener('click', submitForm);

    function submitForm(event){
    event.preventDefault();
    event.stopPropagation();

    var href = '',
    inputs = this.parentNode.getElementsByTagName('input')
    for(var i=0;i<inputs.length;i++){
         if(inputs[i].getAttribute('name') == 'button' && inputs[i].checked){
             href = inputs[i].getAttribute('data-href');
             window.location = href;
         }
    }
}
</script>
</div><br><br>

<div class="addMarginTop"> <!--Add a character to the characters table-->
<div align = "left">
    <h3 class="labels">Add Character</h3>

    <form class="form-inline" method="post" action="addNewChar.php">         
         
            Name: <input class="form-control"type="text" name="name" />
            Level: <input class="form-control"type="text" name="level" />
          
            <!-- Dropdown populated with static race options (do not change) -->
            Race: <select class="form-control" name="race"> 
                <option value="Blood Elf">Blood Elf</option>
                <option value="Forsaken">Forsaken</option>
                <option value="Goblin">Goblin</option>
                <option value="Orc">Orc</option>
                <option value="Pandaren">Pandaren</option>
                <option value="Tauren">Tauren</option>
                <option value="Troll">Troll</option>
            </select>
       
            <!-- Dropdown populated with static class options (do not change) -->
            Class: <select class="form-control" name="class">  
                <option value="Death Knight">Death Knight</option>
                <option value="Druid">Druid</option>
                <option value="Hunter">Hunter</option>
                <option value="Mage">Mage</option>
                <option value="Paladin">Paladin</option>
                <option value="Priest">Priest</option>
                <option value="Rogue">Rogue</option>
                <option value="Shaman">Shaman</option>
                <option value="Warlock">Warlock</option>
                <option value="Warrior">Warrior</option>
                <option value="Monk">Monk</option>
            </select>
       
            Item Level: <input class="form-control"type="text" name="iLevel" /> 
               
            <!-- Dropdown populated with static guild rank options (do not change) -->
            Guild Rank: <select class="form-control" name="guild_rank">  
                <option value="Initiate">Initiate</option>
                <option value="Acolyte">Acolyte</option>
                <option value="Raider">Raider</option>
                <option value="Templar">Templar</option>
                <option value="Magister">Magister</option>
                <option value="Alt">Alt</option>
            </select>
          
            <button class="btn btn-primary" type="submit" value ="Submit"/>Submit</button>
        </div>
    </form>
</div></div><br>

<div class="addMarginTop"> <!--Delete a character from the characters table-->
    <h3 class="labels">Delete Character</h3>

    <form class="form-inline" method="post" action="deleteChar.php"> 
      
            <!--Dropdown dynamically populated with existing characters table data-->            
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
              <button class="btn btn-primary" type="submit" value ="Submit"/>Submit</button>
    </form>
</div><br>


<div class="addMarginTop"> <!--Add a new Continent to the continents table-->
    <h3 class="labels">Add New Continent</h3>
 
    <form class="form-inline" method="post" action="addContinent.php"> 
            
            Name: <input class="form-control" type="text" name="NewCont"/>   
        
        <button class="btn btn-primary" type="submit" value ="Submit"/>Submit</button>     
    </form>
</div><br>



<div class="addMarginTop"> <!--Add a new Profession to the professions table-->
    <h3 class="labels">Add New Profession</h3>
 
    <form class="form-inline" method="post" action="addProfession.php"> 
           
           Name: <input class="form-control" type="text" name="profName" />
     
        <button class="btn btn-primary" type="submit" value ="Submit"/>Submit</button>
    </form>
</div><br>



<div class="addMarginTop"> <!--Add a new Raid to the raids table-->
    <h3 class="labels">Add New Raid</h3>

    <form class="form-inline" method="post" action="addNewRaid.php"> 
            
            Name: <input class="form-control" type="text" name="raidName" />
          
       <button class="btn btn-primary" type="submit" value ="Submit"/>Submit</button>     
    </form>
</div>
<br><br><br><br>
</div>
</body>
</html>