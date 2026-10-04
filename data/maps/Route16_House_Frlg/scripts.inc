Route16_House_Frlg_MapScripts::
	.byte 0

Route16_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM02, Route16_House_EventScript_AlreadyGotHM02
	msgbox Route16_House_Text_FoundMySecretRetreat
	checkitemspace ITEM_HM02
	goto_if_eq VAR_RESULT, FALSE, Route16_House_EventScript_NoRoomForHM02
	giveitem_msg Route16_House_Text_ReceivedHM02FromGirl, ITEM_HM02
	msgbox Route16_House_Text_ExplainHM02
	setflag FLAG_GOT_HM02
	release
	end

Route16_House_EventScript_NoRoomForHM02::
	msgbox Route16_House_Text_DontHaveAnyRoomForThis
	release
	end

Route16_House_EventScript_AlreadyGotHM02::
	msgbox Route16_House_Text_ExplainHM02
	release
	end

Route16_House_EventScript_Fearow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FEAROW, CRY_MODE_NORMAL
	msgbox Route16_House_Text_Fearow
	waitmoncry
	release
	end

Route16_House_Text_FoundMySecretRetreat::
	.string "¡Oh!\n"
	.string "¡Has encontrado mi escondite!\p"
	.string "Por favor, no le digas a nadie que\n"
	.string "estoy aquí, ¡te ayudaré!$"

Route16_House_Text_ReceivedHM02FromGirl::
	.string "¡{PLAYER} obtuvo la MO02\n"
	.string "de manos de la chica!$"

Route16_House_Text_ExplainHM02::
	.string "MO02 es VOLAR. Ésta te llevará\n"
	.string "de vuelta a cualquier ciudad.\p"
	.string "¡Úsala bien!$"

Route16_House_Text_DontHaveAnyRoomForThis::
	.string "No tienes sitio para esto.$"

Route16_House_Text_Fearow::
	.string "FEAROW: ¡Fea, row, row!$"

