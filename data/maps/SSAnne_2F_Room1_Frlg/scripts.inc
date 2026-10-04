SSAnne_2F_Room1_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Room1_EventScript_Gentleman::
	lock
	faceplayer
	message SSAnne_2F_Room1_Text_SleepingMonLookedLikeThis
	waitmessage
	setvar VAR_0x8004, SPECIES_SNORLAX
	special SetSeenMon
	showmonpic SPECIES_SNORLAX, 10, 3
	waitbuttonpress
	hidemonpic
	release
	end

SSAnne_2F_Room1_Text_SleepingMonLookedLikeThis::
	.string "¡Ay, mamaíta, qué miedo!\p"
	.string "Yo pensaba que en estas ruinas tan\n"
	.string "antiguas no había nada de nada,\l"
	.string "¡pero creo que hay fantasmas!$"

