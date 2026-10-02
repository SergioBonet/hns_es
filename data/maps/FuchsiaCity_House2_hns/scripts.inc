FuchsiaCity_House2_hns_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_Granddaughter::	
	goto_if_set FLAG_TEMP_1, FuchsiaCity_House2_EventScript_Granddaughter2
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

FuchsiaCity_House2_EventScript_Granddaughter2::
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter2, MSGBOX_NPC
	end

FuchsiaCity_House2_EventScript_Photo::
	msgbox FuchsiaCity_House2_Text_WardenPhoto, MSGBOX_NPC
	end

FuchsiaCity_House2_Text_WardensGranddaughter1:
	.string "Mi abuelo es el GUARDA de la ZONA\n"
	.string "SAFARI.\p"
	.string "Al menos lo era…\p"
	.string "Decidió irse de vacaciones y se fue al\n"
	.string "extranjero él solo.\p"
	.string "Así fue como dejó de ocuparse de la\n"
	.string "ZONA SAFARI.$"

FuchsiaCity_House2_Text_WardensGranddaughter2:
	.string "Mucha gente se enfadó cuando\n"
	.string "cerraron la ZONA SAFARI, pero el\l"
	.string "abuelo es terco.$"

FuchsiaCity_House2_Text_WardenPhoto:
	.string "Es una foto de un anciano sonriente\n"
	.string "rodeado de POKéMON.$"

FuchsiaCity_House2_Text_SafariZonePhoto:
	.string "Es una foto de una extensa pradera\n"
	.string "llena de POKéMON raros jugando.$"
