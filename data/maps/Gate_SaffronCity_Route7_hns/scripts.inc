Gate_SaffronCity_Route7_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route7_EventScript_Guard::
	goto_if_set FLAG_RETURNED_MACHINE_PART, Gate_SaffronCity_Route7_EventScript_GuardReturnedPart
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardReturnedPart::
	msgbox Route7_Text_SaffronGuard_Serious, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_PowerPlant:
	.string "¿Has oído lo del accidente de la\n"
	.string "CENTRAL ENERGÍA?\p"
	.string "Se encuentra al Este, cerca de PUEBLO\n"
	.string "LAVANDA.$"

Route7_Text_SaffronGuard_Serious:
	.string "Me tomo muy en serio mi trabajo de\n"
	.string "GUARDA.\p"
	.string "¡Eh! Tienes una POKéDEX.\p"
	.string "Vale. Puedes pasar.$"
