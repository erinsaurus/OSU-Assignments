INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Dapi', 110, 'Forsaken', 'Mage', 
		(SELECT id FROM specs WHERE name = 'DPS'),
		869, 'Templar',
        (SELECT id FROM continents WHERE name = 'Eastern Kingdoms'),
        (SELECT id FROM professions WHERE name = 'Alchemy'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Elasmet', 110, 'Troll', 'Rogue', 
		(SELECT id FROM specs WHERE name = 'DPS'),
		850, 'Templar',
        (SELECT id FROM continents WHERE name = 'Kalimdor'),
        (SELECT id FROM professions WHERE name = 'Leatherworking'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Phaige', 110, 'Forsaken', 'Mage', 
		(SELECT id FROM specs WHERE name = 'DPS'),
		900, 'Guild Master',
        (SELECT id FROM continents WHERE name = 'Eastern Kingdoms'),
        (SELECT id FROM professions WHERE name = 'Enchanting'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Rubebarlow', 110, 'Blood Elf', 'Priest',
       (SELECT id FROM specs WHERE name = 'Healer'),
      	899, 'Magister',
        (SELECT id FROM continents WHERE name = 'Eastern Kingdoms'),
        (SELECT id FROM professions WHERE name = 'Engineering'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Derithius', 110, 'Tauren', 'Death Knight',
       (SELECT id FROM specs WHERE name = 'Tank'),
      	657, 'Magister',
        (SELECT id FROM continents WHERE name = 'Eastern Kingdoms'),
        (SELECT id FROM professions WHERE name = 'Leatherworking'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Johnevous', 110, 'Blood Elf', 'Paladin', 
  		(SELECT id FROM specs WHERE name = 'Tank'),
      	875, 'Magister',
        (SELECT id FROM continents WHERE name = 'Eastern Kingdoms'),
        (SELECT id FROM professions WHERE name = 'Tailoring'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Nosamu', 110, 'Orc', 'Warlock',
       (SELECT id FROM specs WHERE name = 'DPS'),
      	850, 'Raider',
        (SELECT id FROM continents WHERE name = 'Draenor'),
        (SELECT id FROM professions WHERE name = 'Mining'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Kizirk', 110, 'Forsaken', 'Warlock',
       (SELECT id FROM specs WHERE name = 'DPS'),
      	713, 'Templar',
        (SELECT id FROM continents WHERE name = 'Draenor'),
        (SELECT id FROM professions WHERE name = 'Skinning'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Kathrynea', 106, 'Pandaren', 'Monk',
       (SELECT id FROM specs WHERE name = 'DPS'),
      	742, 'Templar',
        (SELECT id FROM continents WHERE name = 'Pandaria'),
        (SELECT id FROM professions WHERE name = 'Cooking'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Umad', 100, 'Tauren', 'Druid'
       (SELECT id FROM specs WHERE name = 'Tank'),
      	613, 'Templar',
        (SELECT id FROM continents WHERE name = 'Kalimdor'),
        (SELECT id FROM professions WHERE name = 'First Aid'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Manaskar', 85, 'Troll', 'Mage',
       (SELECT id FROM specs WHERE name = 'DPS'),
      	383, 'Acolyte',
        (SELECT id FROM continents WHERE name = 'Kalimdor'),
        (SELECT id FROM professions WHERE name = 'Blacksmithing'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Delke', 91, 'Goblin', 'Shaman',
       (SELECT id FROM specs WHERE name = 'Healer'),
      	506, 'Acolyte',
        (SELECT id FROM continents WHERE name = 'Kalimdor'),
        (SELECT id FROM professions WHERE name = 'Engineering'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Sheepa', 90, 'Gobin', 'Mage',
       (SELECT id FROM specs WHERE name = 'DPS'),
      	205, 'Acolyte',
        (SELECT id FROM continents WHERE name = 'Kalimdor'),
        (SELECT id FROM professions WHERE name = 'Cooking'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Bowtusk', 94, 'Troll', 'Hunter',
       (SELECT id FROM specs WHERE name = 'DPS'),
      	557, 'Initiate',
        (SELECT id FROM continents WHERE name = 'Kalimdor'),
        (SELECT id FROM professions WHERE name = 'Fishing'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Bluetrane', 43, 'Pandaren', 'Hunter',
       (SELECT id FROM specs WHERE name = 'DPS'),
      	38, 'Initiate',
        (SELECT id FROM continents WHERE name = 'Pandaria'),
        (SELECT id FROM professions WHERE name = 'Archaeology'));

INSERT INTO characters (name, level, race, class, main_spec, iLevel, guild_rank, continent, profession)
VALUES ('Sarduc', 110, 'Tauren', 'Shaman',
       (SELECT id FROM specs WHERE name = 'Healer'),
      	892, 'Magister',
        (SELECT id FROM continents WHERE name = 'Kalimdor'),
        (SELECT id FROM professions WHERE name = 'Archaeology'));