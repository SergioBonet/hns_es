SevenIsland_TrainerTower_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TrainerTower_OnTransition
	.byte 0

SevenIsland_TrainerTower_OnTransition::
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerSign, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerAheadSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerAhead, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_Text_DarioIntro::
	.string "Percibí tu llegada.$"

SevenIsland_TrainerTower_Text_DarioDefeat::
	.string "Me rindo...$"

SevenIsland_TrainerTower_Text_DarioPostBattle::
	.string "Siento que te vas a encontrar\n"
	.string "con mucha gente.\p"
	.string "Establecerás cierta conexión\n"
	.string "mediante una extraña fuerza.$"

SevenIsland_TrainerTower_Text_RodetteIntro::
	.string "En alguna parte de esta isla,\n"
	.string "hay extraños POKéMON durmiendo.$"

SevenIsland_TrainerTower_Text_RodetteDefeat::
	.string "¡Tú sí que sabes entrenar POKéMON!$"

SevenIsland_TrainerTower_Text_RodettePostBattle::
	.string "En alguna parte de esta isla,\n"
	.string "hay extraños POKéMON durmiendo.\p"
	.string "¿Te estarán esperando?$"

SevenIsland_TrainerTower_Text_TrainerTowerSign::
	.string "ENTRADA A LA TORRE DESAFÍO\n"
	.string "¡A por todas, ENTRENADORES!$"

SevenIsland_TrainerTower_Text_TrainerTowerAhead::
	.string "HACIA LA TORRE DESAFÍO$"

