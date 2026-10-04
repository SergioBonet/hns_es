FiveIsland_Meadow_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_Meadow_OnLoad
	.byte 0

FiveIsland_Meadow_OnLoad::
	call_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	end

FiveIsland_Meadow_EventScript_WarehouseDoor::
	lockall
	goto_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen
	goto_if_set FLAG_LEARNED_YES_NAH_CHANSEY, FiveIsland_Meadow_EventScript_OpenWarehouseDoor
	msgbox FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded
	releaseall
	end

FiveIsland_Meadow_EventScript_OpenWarehouseDoor::
	setflag FLAG_UNLOCKED_ROCKET_WAREHOUSE
	message FiveIsland_Meadow_Text_EnteredPasswordDoorOpened
	waitmessage
	delay 60
	call FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	special DrawWholeMapView
	playse SE_PIN
	waitse
	releaseall
	end

FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen::
	msgbox FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen
	releaseall
	end

FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked::
	setmetatile 12, 21, METATILE_SeviiIslands45_RocketWarehouseDoor_Unlocked, 1
	return

FiveIsland_Meadow_EventScript_Rocket1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_49, FiveIsland_Meadow_Text_Rocket1Intro, FiveIsland_Meadow_Text_Rocket1Defeat
	msgbox FiveIsland_Meadow_Text_Rocket1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_50, FiveIsland_Meadow_Text_Rocket2Intro, FiveIsland_Meadow_Text_Rocket2Defeat
	msgbox FiveIsland_Meadow_Text_Rocket2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_51, FiveIsland_Meadow_Text_Rocket3Intro, FiveIsland_Meadow_Text_Rocket3Defeat
	msgbox FiveIsland_Meadow_Text_Rocket3PostBattle, MSGBOX_AUTOCLOSE
	end

@ Unused
FiveIsland_Meadow_Text_DoorNeedsTwoPasswords::
	.string "Para abrir la puerta parece\n"
	.string "que hacen falta dos contraseñas.$"

FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded::
	.string "{PLAYER} introdujo una contraseña.\p"
	.string "“GARON ama a NORA”.\p"
	.string "... ... ... ... ... ...\p"
	.string "Para abrir la puerta hace falta\n"
	.string "otra contraseña más...$"

FiveIsland_Meadow_Text_EnteredPasswordDoorOpened::
	.string "{PLAYER} introdujo dos contraseñas.\p"
	.string "“ARON ama a NORA”.\n"
	.string "“HO-OH es ese HO-OH”.\p"
	.string "... ... ... ... ... ...\p"
	.string "¡La puerta del ALMACÉN\n"
	.string "se ha abierto!$"

FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen::
	.string "La puerta del ALMACÉN\n"
	.string "ya está abierta.$"

FiveIsland_Meadow_Text_Rocket1Intro::
	.string "¡Ésta es una zona privada!\n"
	.string "¡Fuera de aquí!$"

FiveIsland_Meadow_Text_Rocket1Defeat::
	.string "¿Por qué me pasa esto a mí?$"

FiveIsland_Meadow_Text_Rocket1PostBattle::
	.string "Aquí no tienes nada que hacer.\n"
	.string "¡Vete a casa!$"

FiveIsland_Meadow_Text_Rocket2Intro::
	.string "Esto no es más que nuestro\n"
	.string "ALMACÉN.\p"
	.string "No entiendo qué te trae por aquí.$"

FiveIsland_Meadow_Text_Rocket2Defeat::
	.string "Esto no debía pasar…$"

FiveIsland_Meadow_Text_Rocket2PostBattle::
	.string "¿Tienes curiosidad por ver qué hay\n"
	.string "en el ALMACÉN?\p"
	.string "Yo creo que es mejor que no lo\n"
	.string "sepas. Por tu propio bien...$"

FiveIsland_Meadow_Text_Rocket3Intro::
	.string "Perderías el tiempo aunque\n"
	.string "consiguieras pasarme.$"

FiveIsland_Meadow_Text_Rocket3Defeat::
	.string "¡Oh, qué rabia me da!$"

FiveIsland_Meadow_Text_Rocket3PostBattle::
	.string "Bueno, de todas formas no vas\n"
	.string "a poder entrar sin las contraseñas.$"

