DROP TABLE IF EXISTS `continents`;
DROP TABLE IF EXISTS `professions`;
DROP TABLE IF EXISTS `raids`;
DROP TABLE IF EXISTS `characters`;
DROP TABLE IF EXISTS `specs`;

DROP TABLE IF EXISTS `main_spec`;
DROP TABLE IF EXISTS `completed`;
DROP TABLE IF EXISTS `is_from`;
DROP TABLE IF EXISTS `knows`;

CREATE TABLE continents (
	id int NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	PRIMARY KEY(id)
)ENGINE = InnoDB;

CREATE TABLE professions (
	id int NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	level int NOT NULL,
	PRIMARY KEY(id)
)ENGINE = InnoDB;

CREATE TABLE races (
	id int NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	perk varchar(255) DEFAULT NULL,
	PRIMARY KEY(id)
)ENGINE = InnoDB;

CREATE TABLE classes (
	id int NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	healer BIT NOT NULL,
	dps BIT NOT NULL,
	tank BIT NOT NULL,
	PRIMARY KEY(id)
)ENGINE = InnoDB;

CREATE TABLE characters (
	id int NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL UNIQUE,
	level int NOT NULL,
	race int DEFAULT NULL,
	class int DEFAULT NULL,
	iLevel int DEFAULT NULL,
	guild_rank varchar(255) DEFAULT NULL,
	continent int DEFAULT NULL,
	profession int DEFAULT NULL,
	PRIMARY KEY(id),
	FOREIGN KEY(race) REFERENCES races(id),
	FOREIGN KEY(class) REFERENCES classes(id),
	FOREIGN KEY(continent) REFERENCES continents(id),
	FOREIGN KEY(profession) REFERENCES professions(id)
)ENGINE = InnoDB;


CREATE TABLE raids (
	id int NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	PRIMARY KEY(id)
)ENGINE = InnoDB;

CREATE TABLE char_class (
	char_id int NOT NULL,
	class_id int NOT NULL,
	PRIMARY KEY(char_id, class_id),
	FOREIGN KEY(char_id) REFERENCES characters(id) ON DELETE CASCADE,
	FOREIGN KEY(class_id) REFERENCES classes(id) ON DELETE CASCADE
)ENGINE = InnoDB;

CREATE TABLE char_race (
	char_id int NOT NULL,
	race_id int NOT NULL,
	PRIMARY KEY(char_id, race_id),
	FOREIGN KEY(char_id) REFERENCES characters(id) ON DELETE CASCADE,
	FOREIGN KEY(race_id) REFERENCES races(id) ON DELETE CASCADE
)ENGINE = InnoDB;

CREATE TABLE completed (
	char_id int NOT NULL,
	raid_id int NOT NULL,
    difficulty varchar(255),
	FOREIGN KEY(char_id) REFERENCES characters(id) ON DELETE CASCADE,
	FOREIGN KEY(raid_id) REFERENCES raids(id) ON DELETE CASCADE
)ENGINE = InnoDB;

CREATE TABLE class_race (
	class_id int NOT NULL,
	race_id int NOT NULL,
	PRIMARY KEY(class_id, race_id),
	FOREIGN KEY(class_id) REFERENCES classes(id) ON DELETE CASCADE,
	FOREIGN KEY(race_id) REFERENCES races(id) ON DELETE CASCADE
)ENGINE = InnoDB;

CREATE TABLE knows (
	char_id int NOT NULL,
	profession_id int NOT NULL,
	PRIMARY KEY(char_id, profession_id),
	FOREIGN KEY(char_id) REFERENCES characters(id) ON DELETE CASCADE,
	FOREIGN KEY(profession_id) REFERENCES professions(id) ON DELETE CASCADE
)ENGINE = InnoDB;

CREATE TABLE is_from (
	char_id int NOT NULL,
	continent_id int NOT NULL,
	PRIMARY KEY(char_id, continent_id),
	FOREIGN KEY(char_id) REFERENCES characters(id) ON DELETE CASCADE,
	FOREIGN KEY(continent_id) REFERENCES continents(id) ON DELETE CASCADE
)ENGINE = InnoDB;


CREATE TABLE main_spec (
	char_id int NOT NULL,
	spec_id int NOT NULL,
	PRIMARY KEY(char_id, spec_id),
	FOREIGN KEY(char_id) REFERENCES characters(id) ON DELETE CASCADE,
	FOREIGN KEY(spec_id) REFERENCES specs(id) ON DELETE CASCADE
)ENGINE = InnoDB;

CREATE TABLE specs (
	id int NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	PRIMARY KEY(id)
)ENGINE = InnoDB;



INSERT INTO characters (name, level, race, class, iLevel, guild_rank, continent, profession, prof_level)
VALUES ('Elasmet', 110, 
       (SELECT id FROM races WHERE name = 'Troll'),
       (SELECT id FROM classes WHERE name = 'Rogue'),
      	850, 'Templar',
        (SELECT id FROM continents WHERE name = 'Kalimdor'),
        (SELECT id FROM professions WHERE name = 'Leatherworking'),
        800);


DROP TABLE IF EXISTS `characters`;

CREATE TABLE characters (
	id int NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	level int NOT NULL,
	race varchar(255) NOT NULL,
	class varchar(255) NOT NULL,
    main_spec int DEFAULT NULL,
	iLevel int DEFAULT NULL,
	guild_rank varchar(255) DEFAULT NULL,
	continent int DEFAULT NULL,
	profession int DEFAULT NULL,
	PRIMARY KEY(id),
	FOREIGN KEY(continent) REFERENCES continents(id),
	FOREIGN KEY(main_spec) REFERENCES spec(id),
	FOREIGN KEY(profession) REFERENCES professions(id)
)ENGINE = InnoDB;

---SELECT FROM RELATIONSHIP TABLE

SELECT characters.name, professions.name FROM knows
INNER JOIN characters ON char_id = characters.id
INNER JOIN professions ON profession_id = professions.id;

---INSERT INTO RELATIONSHIP TABLE

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES ((SELECT id FROM characters WHERE name = 'TheDude'),
        (SELECT id FROM raids WHERE name = 'Hellfire Citadel'),
        'Normal');

----UPDATE MAIN_SPEC TABLE OR ADD IF NOT EXISTS 

INSERT INTO main_spec (char_id, spec_id) VALUES 
((SELECT id FROM characters WHERE name = 'Phaige'),
(SELECT id FROM specs WHERE name = 'Healer'))
ON DUPLICATE KEY UPDATE spec_id = (SELECT id FROM specs WHERE name = 'Healer');


-----PHP FOR CREATE TABLES

	<?php
			//Turn on error reporting
			ini_set('display_errors', 'On');
			//Connects to the database
			
	 		$mysqli = new mysqli("classmysql.engr.oregonstate.edu","cs340_alltope","0944","cs340_alltope");
			if($mysqli->connect_errno){
				echo "Connection error " . $mysqli->connect_errno . " " . $mysqli->connect_error;
			}
			//insert a new character into the characters table based on the input from the user.

			If($_POST['value'] == 'knows')) {
  			  // query to get all Doe records
  			  $query = "SELECT characters.name, professions.name FROM knows INNER JOIN characters ON char_id = characters.id INNER JOIN professions ON profession_id = professions.id";
}
			elseif($_POST['value'] == 'completed') {
   			 // query to get all Earl records
  			  $query = "SELECT characters.name, raids.name, difficulty FROM completed INNER JOIN characters ON char_id = characters.id INNER JOIN raids ON raid_id = raids.id";
			} 
			elseif($_POST['value'] == 'is_from') {
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