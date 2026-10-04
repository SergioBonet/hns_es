SSAnne_B1F_Room3_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room3_EventScript_Dylan::
	trainerbattle_single TRAINER_SAILOR_DYLAN, SSAnne_B1F_Room3_Text_DylanIntro, SSAnne_B1F_Room3_Text_DylanDefeat
	msgbox SSAnne_B1F_Room3_Text_DylanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room3_Text_DylanIntro::
	.string "¡Me gustan los chavales con garra\n"
	.string "como tú!$"

SSAnne_B1F_Room3_Text_DylanDefeat::
	.string "¡Argh!\n"
	.string "¡He perdido!$"

SSAnne_B1F_Room3_Text_DylanPostBattle::
	.string "Los POKéMON del mar viven en las\n"
	.string "profundidades.\l"
	.string "¡Necesitarás una CAÑA!$"

