FuchsiaCity_House1_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House1_EventScript_Woman::
	msgbox FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth, MSGBOX_NPC
	end

FuchsiaCity_House1_EventScript_OldMan::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 2
	msgbox FuchsiaCity_House1_Text_BillIsMyGrandson
	release
	end

FuchsiaCity_House1_EventScript_LittleBoy::
	msgbox FuchsiaCity_House1_Text_BillFilesHisOwnMonData, MSGBOX_NPC
	end

FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth::
	.string "¡El GUARDA de la ZONA del SAFARI\n"
	.string "es ya mayor, pero sigue en activo!\p"
	.string "¡Y lleva dentadura postiza!$"

FuchsiaCity_House1_Text_BillIsMyGrandson::
	.string "¿Mmm?\n"
	.string "¿Conoces a BILL?\p"
	.string "¡Es mi nieto!\p"
	.string "¡Le gustaba coleccionar cosas\n"
	.string "desde niño!$"

FuchsiaCity_House1_Text_BillFilesHisOwnMonData::
	.string "¡BILL registra los datos de sus\n"
	.string "POKéMON en su PC!\p"
	.string "¿Te los ha enseñado?$"

