SSAqua_RoomSSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSSW_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE_HNS, SSAqua_RoomSSW_Text_FirebreatherLyleSeen, SSAqua_RoomSSW_Text_FirebreatherLyleBeaten
	msgbox SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_EventScript_Ken::
	trainerbattle_single TRAINER_KEN_HNS, SSAqua_RoomSSW_Text_BugCatcherKenSeen, SSAqua_RoomSSW_Text_BugCatcherKenBeaten
	msgbox SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_Text_FirebreatherLyleSeen:
	.string "¡Voy a Kanto para actuar en un\n"
	.string "espectáculo de Comefuegos!\p"
	.string "$"

SSAqua_RoomSSW_Text_FirebreatherLyleBeaten:
	.string "La débil llama pierde fuerza.$"

SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle:
    .string "I guess fire is weak on the sea.\n"
    .string "It doesn't matter? Really?$"

SSAqua_RoomSSW_Text_BugCatcherKenSeen:
	.string "¡Voy a ver a mi abuela para que me\n"
	.string "atrape unos cuantos bichos!$"

SSAqua_RoomSSW_Text_BugCatcherKenBeaten:
	.string "Ooooh, guau. ¡Qué fuerte!$"

SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle:
	.string "Encontrarás muchos POKéMON en los\n"
	.string "árboles de JOHTO.$"
