PokemonTower_6F_Frlg_MapScripts::
	.byte 0

PokemonTower_6F_EventScript_MarowakGhost::
	lockall
	textcolor NPC_TEXT_COLOR_MON
	msgbox PokemonTower_6F_Text_BeGoneIntruders
	setwildbattle SPECIES_MAROWAK, 30
	special StartMarowakBattle
	waitstate
	goto_if_eq VAR_RESULT, FALSE, PokemonTower_6F_EventScript_DefeatedMarowakGhost  @ VAR_RESULT set by CB2_EndMarowakBattle
	applymovement LOCALID_PLAYER, PokemonTower_6F_Movement_ForcePlayerUp
	waitmovement 0
	releaseall
	end

PokemonTower_6F_EventScript_DefeatedMarowakGhost::
	message PokemonTower_6F_Text_GhostWasCubonesMother
	waitmessage
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	msgbox PokemonTower_6F_Text_MothersSpiritWasCalmed
	setvar VAR_MAP_SCENE_POKEMON_TOWER_6F, 1
	releaseall
	end

PokemonTower_6F_Movement_ForcePlayerUp::
	walk_up
	step_end

PokemonTower_6F_EventScript_Angelica::
	trainerbattle_single TRAINER_CHANNELER_ANGELICA, PokemonTower_6F_Text_AngelicaIntro, PokemonTower_6F_Text_AngelicaDefeat
	msgbox PokemonTower_6F_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Emilia::
	trainerbattle_single TRAINER_CHANNELER_EMILIA, PokemonTower_6F_Text_EmiliaIntro, PokemonTower_6F_Text_EmiliaDefeat
	msgbox PokemonTower_6F_Text_EmiliaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Jennifer::
	trainerbattle_single TRAINER_CHANNELER_JENNIFER, PokemonTower_6F_Text_JenniferIntro, PokemonTower_6F_Text_JenniferDefeat
	msgbox PokemonTower_6F_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_AngelicaIntro::
	.string "Dame…\n"
	.string "sangre…$"

PokemonTower_6F_Text_AngelicaDefeat::
	.string "¡Grrr!$"

PokemonTower_6F_Text_AngelicaPostBattle::
	.string "Me siento anémica y débil...$"

PokemonTower_6F_Text_EmiliaIntro::
	.string "Urff…\n"
	.string "¡Kuaah!$"

PokemonTower_6F_Text_EmiliaDefeat::
	.string "¡Algo se ha caído!$"

PokemonTower_6F_Text_EmiliaPostBattle::
	.string "¡No me lo creo!\n"
	.string "¡Era un malvado espíritu!$"

PokemonTower_6F_Text_JenniferIntro::
	.string "Ke…ke…ke…\n"
	.string "ke…ke…ke!$"

PokemonTower_6F_Text_JenniferDefeat::
	.string "¡Kiii!$"

PokemonTower_6F_Text_JenniferPostBattle::
	.string "¿Qué está pasando aquí?$"

PokemonTower_6F_Text_BeGoneIntruders::
	.string "Fuera…\n"
	.string "Intrusos…$"

PokemonTower_6F_Text_GhostWasCubonesMother::
	.string "¡Ese GHOST era el inquieto\n"
	.string "espíritu de la madre de CUBONE!$"

PokemonTower_6F_Text_MothersSpiritWasCalmed::
	.string "El espíritu de la madre descansa\n"
	.string "tranquilo.\p"
	.string "¡Y ha partido al más allá!$"

