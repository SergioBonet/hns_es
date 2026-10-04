SSAnne_1F_Room7_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room7_EventScript_Thomas::
	trainerbattle_single TRAINER_GENTLEMAN_THOMAS, SSAnne_1F_Room7_Text_ThomasIntro, SSAnne_1F_Room7_Text_ThomasDefeat
	msgbox SSAnne_1F_Room7_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room7_Text_ThomasIntro::
	.string "Soy un viajero solitario…\p"
	.string "Mis únicos compañeros y amigos son\n"
	.string "los POKéMON que capturé en mis viajes…$"

SSAnne_1F_Room7_Text_ThomasDefeat::
	.string "Mis queridos amigos…$"

SSAnne_1F_Room7_Text_ThomasPostBattle::
	.string "¡Deberías ser amable con los amigos!$"

