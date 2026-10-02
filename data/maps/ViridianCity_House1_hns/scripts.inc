ViridianCity_House1_hns_MapScripts::
	.byte 0

ViridianCity_House1_EventScript_Pokefan::
	msgbox ViridianCity_House1_Text_PokefanM, MSGBOX_NPC
	end

ViridianCity_House1_EventScript_Lass::
	msgbox ViridianCity_House1_Text_Lass, MSGBOX_NPC
	end


ViridianCity_House1_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Speary, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_EventScript_Rattey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Rattey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_Text_PokefanM:
	.string "¿Dedicas mucho tiempo a pensar en\n"
	.string "nombres para tus POKéMON?\p"
	.string "Es más divertido intercambiarlos si\n"
	.string "les pones buenos motes.$"

ViridianCity_House1_Text_Lass:
	.string "Son Speary, un SPEAROW, y Rattey, un\n"
	.string "RATTATA.$"

ViridianCity_House1_Text_Speary:
	.string "SPEARY: ¡Spea!$"

ViridianCity_House1_Text_Rattey:
	.string "RATTEY: ¡Ratii!$"

