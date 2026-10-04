Route12_NorthEntrance_2F_Frlg_MapScripts::
	.byte 0

Route12_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_TheresManFishing, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_ItsPokemonTower, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM27, Route12_NorthEntrance_2F_EventScript_ExplainTM27
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route12_NorthEntrance_2F_EventScript_TakeTMMale
	call_if_eq VAR_RESULT, FEMALE, Route12_NorthEntrance_2F_EventScript_TakeTMFemale
	checkitemspace ITEM_TM27
	goto_if_eq VAR_RESULT, FALSE, Route12_NorthEntrance_2F_EventScript_NoRoomForTM27
	giveitem_msg Route12_NorthEntrance_2F_Text_ReceivedTM27FromLittleGirl, ITEM_TM27
	msgbox Route12_NorthEntrance_2F_Text_ExplainTM27
	setflag FLAG_GOT_TM27
	release
	end

Route12_NorthEntrance_2F_EventScript_TakeTMMale::
	msgbox Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreMale
	return

Route12_NorthEntrance_2F_EventScript_TakeTMFemale::
	msgbox Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreFemale
	return

Route12_NorthEntrance_2F_EventScript_NoRoomForTM27::
	msgbox Route12_NorthEntrance_2F_Text_DontHaveRoomForThis
	release
	end

Route12_NorthEntrance_2F_EventScript_ExplainTM27::
	msgbox Route12_NorthEntrance_2F_Text_ExplainTM27
	release
	end

@ Male and female text identical, differ (presumably) in JP
Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreMale::
	.string "Las cenizas de mis POKéMON están\n"
	.string "guardadas en la TORRE POKéMON.\p"
	.string "Puedes quedarte con mi MT. Ya no\n"
	.string "la necesito...$"

Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreFemale::
	.string "Las cenizas de mis POKéMON están\n"
	.string "guardadas en la TORRE POKéMON.\p"
	.string "Puedes quedarte con mi MT. Ya no\n"
	.string "la necesito...$"

Route12_NorthEntrance_2F_Text_ReceivedTM27FromLittleGirl::
	.string "¡{PLAYER} obtuvo la MT27\n"
	.string "de manos de la chica!$"

Route12_NorthEntrance_2F_Text_ExplainTM27::
	.string "¡La MT27 es un ataque que se\n"
	.string "llama RETROCESO!\p"
	.string "Si tratas bien a tus POKéMON,\n"
	.string "aumentará sus efectos en\l"
	.string "combate.$"

Route12_NorthEntrance_2F_Text_DontHaveRoomForThis::
	.string "¡No tienes sitio para esto!$"

Route12_NorthEntrance_2F_Text_TheresManFishing::
	.string "Has usado los prismáticos...\p"
	.string "¡Un hombre está pescando!$"

Route12_NorthEntrance_2F_Text_ItsPokemonTower::
	.string "Has usado los prismáticos...\p"
	.string "¡Es la TORRE POKéMON!$"

