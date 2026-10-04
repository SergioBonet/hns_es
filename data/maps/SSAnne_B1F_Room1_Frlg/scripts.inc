SSAnne_B1F_Room1_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room1_EventScript_Barny::
	trainerbattle_single TRAINER_FISHERMAN_BARNY, SSAnne_B1F_Room1_Text_BarnyIntro, SSAnne_B1F_Room1_Text_BarnyDefeat
	msgbox SSAnne_B1F_Room1_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_EventScript_Phillip::
	trainerbattle_single TRAINER_SAILOR_PHILLIP, SSAnne_B1F_Room1_Text_PhillipIntro, SSAnne_B1F_Room1_Text_PhillipDefeat
	msgbox SSAnne_B1F_Room1_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_PhillipIntro::
	.string "¡Marinero, si pierdes, caminarás\n"
	.string "por la plancha!$"

SSAnne_B1F_Room1_Text_PhillipDefeat::
	.string "¡Argh! ¡Derrotado por alguien\n"
	.string "más joven que yo!$"

SSAnne_B1F_Room1_Text_PhillipPostBattle::
	.string "A veces, algunas medusas caen\n"
	.string "dentro del barco.$"

SSAnne_B1F_Room1_Text_BarnyIntro::
	.string "¡Eh, tú!\p"
	.string "¡No sé si eres de tierra o mar, \n"
	.string "pero para y habla conmigo!\p"
	.string "¡Todos mis POKéMON vienen del mar!$"

SSAnne_B1F_Room1_Text_BarnyDefeat::
	.string "¡Vaya!\n"
	.string "¡He dejado que se me escape!$"

SSAnne_B1F_Room1_Text_BarnyPostBattle::
	.string "¡Yo también te iba a hacer\n"
	.string "mi ayudante!$"

