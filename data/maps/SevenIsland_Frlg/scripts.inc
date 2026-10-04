SevenIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_OnTransition
	.byte 0

SevenIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND
	end

SevenIsland_EventScript_IslandSign::
	msgbox SevenIsland_Text_IslandSign, MSGBOX_SIGN
	end

SevenIsland_EventScript_OldWoman::
	msgbox SevenIsland_Text_IslandsMadeInSevenDays, MSGBOX_NPC
	end

SevenIsland_EventScript_Scientist::
	msgbox SevenIsland_Text_IslandVirtuallyUntouched, MSGBOX_NPC
	end

Text_SwordsDanceTeach::
	.string "Son pocos los que vienen\n"
	.string "a esta zona.\p"
	.string "Si me pusiera a entrenar aquí,\n"
	.string "seguro que me haría superfuerte.\p"
	.string "Sí, requetefuerte-fortísimo.\p"
	.string "¿Quieres aprender el movimiento\n"
	.string "DANZA ESPADA?$"

Text_SwordsDanceDeclined::
	.string "Bueno, como quieras.$"

Text_SwordsDanceWhichMon::
	.string "¿A qué POKéMON quieres que\n"
	.string "se lo enseñe?$"

Text_SwordsDanceTaught::
	.string "Lo suyo sería que cada vez nos\n"
	.string "hiciéramos más y más fuertes, ¿eh?$"

SevenIsland_Text_IslandSign::
	.string "ISLA SÉTIMA\n"
	.string "Isla de aventura infinita.$"

SevenIsland_Text_IslandsMadeInSevenDays::
	.string "A estas islas las llamamos ARCHI7\n"
	.string "porque son siete, je.\p"
	.string "O, por lo menos, es lo que la\n"
	.string "gente joven cree.\p"
	.string "Pero en realidad es porque las\n"
	.string "islas se crearon en siete días.$"

SevenIsland_Text_IslandVirtuallyUntouched::
	.string "Esta isla es prácticamente virgen,\n"
	.string "apenas ha sufrido modificaciones.\p"
	.string "Por ello, es peligroso y difícil\n"
	.string "hacer escalada por aquí.$"

