FiveIsland_LostCave_Room1_Frlg_MapScripts::
	.byte 0

FiveIsland_LostCave_Room1_EventScript_Lawson::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAWSON, FiveIsland_LostCave_Room1_Text_LawsonIntro, FiveIsland_LostCave_Room1_Text_LawsonDefeat
	msgbox FiveIsland_LostCave_Room1_Text_LawsonPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_LostCave_Room1_Text_LawsonIntro::
	.string "¡Ay, mamaíta, qué miedo!\p"
	.string "Yo pensaba que en estas ruinas tan\n"
	.string "antiguas no había nada de nada,\l"
	.string "¡pero creo que hay fantasmas!$"

FiveIsland_LostCave_Room1_Text_LawsonDefeat::
	.string "¡Aaaaah!\n"
	.string "¡Piedad!$"

FiveIsland_LostCave_Room1_Text_LawsonPostBattle::
	.string "Estoy intentando salir de aquí,\n"
	.string "pero siempre llego al mismo sitio.\p"
	.string "Yo creo que el número de piedras\n"
	.string "que hay, quiere decir algo...$"

