Route7_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route7_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route7_EventScript_Sign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route7_EventScript_Door::
	msgbox Route7_Text_LockedDoor, MSGBOX_SIGN
	end

Route7_Text_UndergroundPathSign:
	.string "¿Y este cartel?\p"
	.string "Algunos entrenadores han estado\n"
	.string "luchando en VÍA SUBTERRÁNEA.\p"
	.string "Tras numerosas quejas de los vecinos,\n"
	.string "la VÍA SUBTERRÁNEA ha sido cerrada\l"
	.string "indefinidamente.\p"
	.string "POLICÍA C. AZULONA$"

Route7_Text_LockedDoor:
	.string "Está cerrada…$"

