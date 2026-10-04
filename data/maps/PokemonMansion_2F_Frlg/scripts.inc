PokemonMansion_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_2F_OnLoad
	.byte 0

PokemonMansion_2F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_2F
	end

PokemonMansion_2F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 1
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_2F_EventScript_DiaryJuly5th::
	msgbox PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_DiaryJuly10th::
	msgbox PokemonMansion_1F_Text_ChristenedDiscoveredMonMew, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_Arnie::
	trainerbattle_single TRAINER_BURGLAR_ARNIE, PokemonMansion_1F_Text_ArnieIntro, PokemonMansion_1F_Text_ArnieDefeat
	msgbox PokemonMansion_1F_Text_ArniePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_Text_PressSecretSwitch::
	.string "Un botón secreto.\p"
	.string "¿Lo pulso?$"

PokemonMansion_Text_WhoWouldnt::
	.string "¿Y quién no lo haría?$"

PokemonMansion_Text_NotQuiteYet::
	.string "¡Todavía no!$"

PokemonMansion_1F_Text_ArnieIntro::
	.string "¡No sé salir! ¡Este viejo lugar\n"
	.string "es un enorme laberinto!$"

PokemonMansion_1F_Text_ArnieDefeat::
	.string "¡Oh, no!\n"
	.string "¡Mi botín!$"

PokemonMansion_1F_Text_ArniePostBattle::
	.string "¡Los botones abren y cierran\n"
	.string "alternativamente los grupos\l"
	.string "de puertas!$"

PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle::
	.string "Diario: 5 de julio.\n"
	.string "Guyana, Suramérica.\p"
	.string "Un nuevo tipo de POKéMON fue\n"
	.string "descubierto en el interior de la\l"
	.string "selva.$"

PokemonMansion_1F_Text_ChristenedDiscoveredMonMew::
	.string "Diario: 10 de julio.\n"
	.string "Hemos llamado a este nuevo\l"
	.string "POKéMON, MEW.$"

