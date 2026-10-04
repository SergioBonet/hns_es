PokemonMansion_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_B1F_OnLoad
	.byte 0

PokemonMansion_B1F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_B1F
	end

PokemonMansion_B1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 3
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_B1F_EventScript_DiarySep1st::
	msgbox PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful, MSGBOX_SIGN
	end

PokemonMansion_B1F_EventScript_Lewis::
	trainerbattle_single TRAINER_BURGLAR_LEWIS, PokemonMansion_B1F_Text_LewisIntro, PokemonMansion_B1F_Text_LewisDefeat
	msgbox PokemonMansion_B1F_Text_LewisPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_EventScript_Ivan::
	trainerbattle_single TRAINER_SCIENTIST_IVAN, PokemonMansion_B1F_Text_IvanIntro, PokemonMansion_B1F_Text_IvanDefeat
	msgbox PokemonMansion_B1F_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_Text_LewisIntro::
	.string "¡Oh, oh!\n"
	.string "¿Dónde estoy ahora?$"

PokemonMansion_B1F_Text_LewisDefeat::
	.string "¡Vaya!$"

PokemonMansion_B1F_Text_LewisPostBattle::
	.string "Se pueden encontrar cosas por ahí.\n"
	.string "Seguro que las dejaron los residentes.$"

PokemonMansion_B1F_Text_IvanIntro::
	.string "Este lugar es ideal para un\n"
	.string "laboratorio.$"

PokemonMansion_B1F_Text_IvanDefeat::
	.string "¿Era esto lo que querías?$"

PokemonMansion_B1F_Text_IvanPostBattle::
	.string "¡Me encanta este sitio! ¡Es muy\n"
	.string "apropiado para mis estudios!$"

PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful::
	.string "Diario: 1 de septiembre.\n"
	.string "MEWTWO es demasiado poderoso.\p"
	.string "No hemos sabido contener sus malos\n"
	.string "instintos.$"

