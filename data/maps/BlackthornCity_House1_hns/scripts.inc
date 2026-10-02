BlackthornCity_House1_hns_MapScripts::
	.byte 0

BlackthornCity_House1EventScript_Granny::
	msgbox BlackthornCity_House1_Text_Granny, MSGBOX_NPC
	end

BlackthornCity_House1EventScript_Dratini::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRATINI, CRY_MODE_NORMAL
	msgbox BlackthornCity_House1_Text_Dratini, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BlackthornCity_House1_Text_Granny:
	.string "Aquí mismo, en CIUDAD ENDRINO, vive un\n"
	.string "clan de ENTRENADORES capaces de\l"
	.string "dominar dragones.\p"
	.string "Por eso en esta ciudad hay muchas\n"
	.string "leyendas sobre dragones.$"

BlackthornCity_House1_Text_Dratini:
	.string "DRATINI: ¡Draa!$"
