SixIsland_RuinValley_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SixIsland_RuinValley_OnLoad
	.byte 0

SixIsland_RuinValley_OnLoad::
	call_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, SixIsland_RuinValley_EventScript_OpenDottedHoleDoor
	end

SixIsland_RuinValley_EventScript_OpenDottedHoleDoor::
	setmetatile 24, 24, METATILE_SeviiIslands67_DottedHoleDoor_Open, 0
	return

SixIsland_RuinValley_EventScript_Scientist::
	lock
	msgbox SixIsland_RuinValley_Text_CantFigureOutHowToGetInside
	applymovement LOCALID_RUIN_VALLEY_SCIENTIST, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SixIsland_RuinValley_Text_IFoundThisPlace
	applymovement LOCALID_RUIN_VALLEY_SCIENTIST, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SixIsland_RuinValley_EventScript_DottedHoleDoor::
	lockall
	goto_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, SixIsland_RuinValley_EventScript_DottedHoleDoorOpen
	msgbox SixIsland_RuinValley_Text_CheckDoorMoreThoroughly, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SixIsland_RuinValley_EventScript_IgnoreDottedHoleDoor
	msgbox SixIsland_RuinValley_Text_SeveralDotsOnTheDoor
	braillemsgbox Braille_Text_Cut
	releaseall
	end

SixIsland_RuinValley_EventScript_DottedHoleDoorOpen::
	msgbox SixIsland_RuinValley_Text_DoorIsOpen
	releaseall
	end

SixIsland_RuinValley_EventScript_IgnoreDottedHoleDoor::
	msgbox SixIsland_RuinValley_Text_LeftDoorAlone
	releaseall
	end

SixIsland_RuinValley_Text_CantFigureOutHowToGetInside::
	.string "No sé cómo se supone que\n"
	.string "debo entrar.$"

SixIsland_RuinValley_Text_IFoundThisPlace::
	.string "Para tu información, fui yo quien\n"
	.string "encontró este lugar.\p"
	.string "Tampoco es para que pongas\n"
	.string "esa cara de envidia...$"

SixIsland_RuinValley_Text_CheckDoorMoreThoroughly::
	.string "La puerta no cede ni un milímetro.\n"
	.string "¿Quieres examinarla un poco?$"

SixIsland_RuinValley_Text_LeftDoorAlone::
	.string "{PLAYER} dejó tranquila la puerta.$"

SixIsland_RuinValley_Text_SeveralDotsOnTheDoor::
	.string "Si lo miras de cerca, hay\n"
	.string "varios puntos en la puerta…$"

SixIsland_RuinValley_Text_DoorIsOpen::
	.string "La puerta está abierta.$"

SixIsland_RuinValley_Text_StanlyIntro::
	.string "Creo que en este mundo quedan\n"
	.string "misterios por resolver.$"

SixIsland_RuinValley_Text_StanlyDefeat::
	.string "Mmmm...$"

SixIsland_RuinValley_Text_StanlyPostBattle::
	.string "Te sugiero que tú también pienses\n"
	.string "en los secretos y misterios de\l"
	.string "nuestro mundo una vez al día.$"

SixIsland_RuinValley_Text_FosterIntro::
	.string "Tengo curiosidad, ¿qué te impulsó\n"
	.string "a venir aquí?$"

SixIsland_RuinValley_Text_FosterDefeat::
	.string "Hace tanto que no combato que\n"
	.string "mi instinto está oxidado.$"

SixIsland_RuinValley_Text_FosterPostBattle::
	.string "Hay varias ruinas en ARCHI7.\p"
	.string "La mayoría datan de tiempos\n"
	.string "inmemoriales.$"

SixIsland_RuinValley_Text_LarryIntro::
	.string "Dicen que hay misteriosas piedras\n"
	.string "en esta isla.\p"
	.string "Supongo que tendrán algo que ver\n"
	.string "con las ruinas de aquí.$"

SixIsland_RuinValley_Text_LarryDefeat::
	.string "Eh... muy interesante.$"

SixIsland_RuinValley_Text_LarryPostBattle::
	.string "Las ruinas de ahí...\p"
	.string "Son rarísimas, yo no he conseguido\n"
	.string "entrar todavía.$"

SixIsland_RuinValley_Text_DarylIntro::
	.string "¿Luchar contigo?\n"
	.string "¡Ahora mismo!$"

SixIsland_RuinValley_Text_DarylDefeat::
	.string "No soporto el sabor de la derrota\n"
	.string "ante ti...$"

SixIsland_RuinValley_Text_DarylPostBattle::
	.string "¡Descubre la alegría de escalar!$"

SixIsland_RuinValley_Text_HectorIntro::
	.string "Conozco bastante bien el terreno\n"
	.string "por estos alrededores.$"

SixIsland_RuinValley_Text_HectorDefeat::
	.string "No hace falta que seas tan\n"
	.string "insistente. Te lo diré encantado.$"

SixIsland_RuinValley_Text_HectorPostBattle::
	.string "La entrada a las ruinas...\n"
	.string "Tiene unos dibujos extrañísimos\l"
	.string "grabados.\p"
	.string "Y no tengo ni idea de lo que\n"
	.string "significan.$"
