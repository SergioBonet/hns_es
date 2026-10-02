Gate_IlexForest_Route34_hns_MapScripts::
	.byte 0

Route34IlexForestGate_EventScript_Lass::
	lock
	faceplayer
	msgbox Route34IlexForestGate_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34IlexForestGate_EventScript_Butterfree::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUTTERFREE, CRY_MODE_NORMAL
	msgbox Route34IlexForestGate_Text_Butterfree, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34IlexForestGate_Text_Lass:
	.string "¿Has visto el santuario en honor al\n"
	.string "protector?\p"
	.string "Vigila el BOSQUE a través del tiempo.\p"
	.string "Creo que debe de ser un POKéMON de\n"
	.string "tipo PLANTA.$"

Route34IlexForestGate_Text_Butterfree:
	.string "BUTTERFREE: ¡Free!$"
