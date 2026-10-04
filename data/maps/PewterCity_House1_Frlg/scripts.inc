PewterCity_House1_Frlg_MapScripts::
	.byte 0

PewterCity_House1_EventScript_BaldingMan::
	msgbox PewterCity_House1_Text_TradeMonsAreFinicky, MSGBOX_NPC
	end

PewterCity_House1_EventScript_LittleBoy::
	lock
	msgbox PewterCity_House1_Text_NidoranSit
	call PewterCity_House1_EventScript_DoNidoranCry
	release
	end

PewterCity_House1_EventScript_Nidoran::
	lock
	faceplayer
	call PewterCity_House1_EventScript_DoNidoranCry
	applymovement LOCALID_PEWTER_HOUSE_NIDORAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_House1_EventScript_DoNidoranCry::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	waitse
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
	msgbox PewterCity_House1_Text_Nidoran
	waitmoncry
	call EventScript_RestorePrevTextColor
	return

PewterCity_House1_Text_Nidoran::
	.string "NIDORAN♂: ¡Nidor!$"

PewterCity_House1_Text_NidoranSit::
	.string "¡Siéntate, NIDORAN!$"

PewterCity_House1_Text_TradeMonsAreFinicky::
	.string "Nuestro POKéMON es de fuera, así que\n"
	.string "es quisquilloso y difícil de manejar.\p"
	.string "Un POKéMON de fuera es uno que\n"
	.string "obtienes en un intercambio.\p"
	.string "Crece rápido, pero puede ignorar a un\n"
	.string "ENTRENADOR inexperto en combate.\p"
	.string "¡Si tuviéramos algunas MEDALLAS…!$"

