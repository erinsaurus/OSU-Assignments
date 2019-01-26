INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Asahhealer'),
    (SELECT raids.id FROM raids WHERE id = 1),
    'Heroic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Asahhealer'),
    (SELECT raids.id FROM raids WHERE id = 1),
    'Mythic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Asahhealer'),
    (SELECT raids.id FROM raids WHERE id = 6),
    'Heroic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Phaige'),
    (SELECT raids.id FROM raids WHERE id = 7),
    'Mythic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Phaige'),
    (SELECT raids.id FROM raids WHERE id = 5),
    'Mythic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Phaige'),
    (SELECT raids.id FROM raids WHERE id = 6),
    'Mythic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Dapi'),
    (SELECT raids.id FROM raids WHERE id = 3),
    'Normal'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Dapi'),
    (SELECT raids.id FROM raids WHERE id = 2),
    'Normal'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Dapi'),
    (SELECT raids.id FROM raids WHERE id = 7),
    'Raid Finder'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Elasmet'),
    (SELECT raids.id FROM raids WHERE id = 1),
    'Mythic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Elasmet'),
    (SELECT raids.id FROM raids WHERE id = 2),
    'Heroic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Elasmet'),
    (SELECT raids.id FROM raids WHERE id = 3),
    'Heroic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Elasmet'),
    (SELECT raids.id FROM raids WHERE id = 4),
    'Mythic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Elasmet'),
    (SELECT raids.id FROM raids WHERE id = 5),
    'Raid Finder'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Rubebarlow'),
    (SELECT raids.id FROM raids WHERE id = 6),
    'Normal'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Rubebarlow'),
    (SELECT raids.id FROM raids WHERE id = 5),
    'Normal'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Derithius'),
    (SELECT raids.id FROM raids WHERE id = 1),
    'Raid Finder'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Johnevous'),
    (SELECT raids.id FROM raids WHERE id = 2),
    'Normal'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Johnevous'),
    (SELECT raids.id FROM raids WHERE id = 7),
    'Mythic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Johnevous'),
    (SELECT raids.id FROM raids WHERE id = 6),
    'Heroic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Johnevous'),
    (SELECT raids.id FROM raids WHERE id = 3),
    'Heroic'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Kizirk'),
    (SELECT raids.id FROM raids WHERE id = 2),
    'Raid Finder'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Kizirk'),
    (SELECT raids.id FROM raids WHERE id = 3),
    'Raid Finder'
);

INSERT INTO completed (char_id, raid_id, difficulty)
VALUES (
	(SELECT characters.id FROM characters WHERE name = 'Kizirk'),
    (SELECT raids.id FROM raids WHERE id = 4),
    'Normal'
);