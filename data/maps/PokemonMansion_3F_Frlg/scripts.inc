PokemonMansion_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_3F_OnLoad
	.byte 0

PokemonMansion_3F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_3F
	end

PokemonMansion_3F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 2
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_3F_EventScript_DiaryFeb6th::
	msgbox PokemonMansion_1F_Text_MewGaveBirthToMewtwo, MSGBOX_SIGN
	end

PokemonMansion_3F_EventScript_Simon::
	trainerbattle_single TRAINER_BURGLAR_SIMON, PokemonMansion_1F_Text_SimonIntro, PokemonMansion_1F_Text_SimonDefeat
	msgbox PokemonMansion_1F_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_Braydon::
	trainerbattle_single TRAINER_SCIENTIST_BRAYDON, PokemonMansion_1F_Text_BraydonIntro, PokemonMansion_1F_Text_BraydonDefeat
	msgbox PokemonMansion_1F_Text_BraydonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_SimonIntro::
	.string "Este lugar es...\n"
	.string "¡Gigantesco!$"

PokemonMansion_1F_Text_SimonDefeat::
	.string "¡Ayah!$"

PokemonMansion_1F_Text_SimonPostBattle::
	.string "Me pregunto adónde habrá ido\n"
	.string "mi compañero.$"

PokemonMansion_1F_Text_BraydonIntro::
	.string "Mi maestro vivió aquí hace tiempo.$"

PokemonMansion_1F_Text_BraydonDefeat::
	.string "¡Uf!\n"
	.string "¡Impresionante!$"

PokemonMansion_1F_Text_BraydonPostBattle::
	.string "¿Estás atascado?\n"
	.string "¡Prueba a saltar por ahí!$"

PokemonMansion_1F_Text_MewGaveBirthToMewtwo::
	.string "Diario: 6 de febrero.\n"
	.string "MEW dio a luz.\p"
	.string "Llamamos al pequeño: MEWTWO.$"

