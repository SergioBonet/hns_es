ViridianCity_House_Frlg_MapScripts::
	.byte 0

ViridianCity_House_EventScript_BaldingMan::
	msgbox ViridianCity_House_Text_NicknamingIsFun, MSGBOX_NPC
	end

ViridianCity_House_EventScript_LittleGirl::
	msgbox ViridianCity_House_Text_MyDaddyLovesMonsToo, MSGBOX_NPC
	end

ViridianCity_House_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House_Text_Speary
	waitmoncry
	release
	end

ViridianCity_House_EventScript_NicknameSign::
	msgbox ViridianCity_House_Text_SpearowNameSpeary, MSGBOX_SIGN
	end

ViridianCity_House_Text_NicknamingIsFun::
	.string "Inventarse motes es divertido, pero\n"
	.string "difícil.\p"
	.string "Es más fácil recordar nombres\n"
	.string "sencillos.$"

ViridianCity_House_Text_MyDaddyLovesMonsToo::
	.string "¡A mi padre también le gustan los\n"
	.string "POKéMON!$"

ViridianCity_House_Text_Speary::
	.string "SPEARY: ¡Spe-pe-peeary!$"

ViridianCity_House_Text_SpearowNameSpeary::
	.string "SPEAROW\n"
	.string "Nombre: SPEARY$"

