SixIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SixIsland_PokemonCenter_1F_OnFrame
	.byte 0

SixIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_SIX_ISLAND
	call_if_eq VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F, 0, SixIsland_PokemonCenter_1F_EventScript_ShowRival
	end

SixIsland_PokemonCenter_1F_EventScript_ShowRival::
	clearflag FLAG_HIDE_SIX_ISLAND_POKECENTER_RIVAL
	return

SixIsland_PokemonCenter_1F_OnFrame::
	map_script_2 VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F, 0, SixIsland_PokemonCenter_1F_EventScript_RivalScene
	.2byte 0

SixIsland_PokemonCenter_1F_EventScript_RivalScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_SIX_ISLAND_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_SIX_ISLAND_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SIX_ISLAND_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 25
	applymovement LOCALID_SIX_ISLAND_RIVAL, SixIsland_PokemonCenter_1F_Movement_RivalApproach
	waitmovement 0
	msgbox SixIsland_PokemonCenter_1F_Text_RivalImpossibleToGetAllMonsAroundHere
	closemessage
	applymovement LOCALID_PLAYER, SixIsland_PokemonCenter_1F_Movement_PlayerWatchRivalExit
	applymovement LOCALID_SIX_ISLAND_RIVAL, SixIsland_PokemonCenter_1F_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	playse SE_EXIT
	delay 35
	removeobject LOCALID_SIX_ISLAND_RIVAL
	setvar VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F, 1
	setvar VAR_MAP_SCENE_FOUR_ISLAND, 1
	releaseall
	end

SixIsland_PokemonCenter_1F_Movement_RivalApproach::
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SixIsland_PokemonCenter_1F_Movement_RivalExit::
	delay_16
	delay_4
	walk_down
	step_end

SixIsland_PokemonCenter_1F_Movement_PlayerWatchRivalExit::
	walk_left
	walk_in_place_faster_right
	step_end

SixIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

SixIsland_PokemonCenter_1F_EventScript_Hiker::
	msgbox SixIsland_PokemonCenter_1F_Text_SomethingHiddenOnThisIsland, MSGBOX_NPC
	end

SixIsland_PokemonCenter_1F_EventScript_OldMan::
	msgbox SixIsland_PokemonCenter_1F_Text_SomeMonsEvolveByTradingWithHeldItem, MSGBOX_NPC
	end

SixIsland_PokemonCenter_1F_Text_SomethingHiddenOnThisIsland::
	.string "Llevo diez años buscando\n"
	.string "las RUINAS.\p"
	.string "No, mucho más, ¡llevo veinte!\p"
	.string "Creo que en esta isla hay algo\n"
	.string "raro.$"

SixIsland_PokemonCenter_1F_Text_SomeMonsEvolveByTradingWithHeldItem::
	.string "Tú ya sabes que hay POKéMON que\n"
	.string "evolucionan durante el intercambio,\l"
	.string "¿no?\p"
	.string "¿Y sabes que algunos necesitan un\n"
	.string "objeto concreto para evolucionar\l"
	.string "durante el intercambio?$"

SixIsland_PokemonCenter_1F_Text_RivalImpossibleToGetAllMonsAroundHere::
	.string "{RIVAL}: ¡Eh, {PLAYER}!\n"
	.string "¿Qué tal llevas la POKéDEX?\p"
	.string "Parece imposible conseguir todos\n"
	.string "los POKéMON paseando sólo por\l"
	.string "esta zona, ¿eh?\p"
	.string "A lo mejor hay otros POKéMON\n"
	.string "lejos de aquí...\p"
	.string "... ... ... ... ... ... ... ... ...\p"
	.string "Desde luego, si yo no lo consigo,\n"
	.string "tampoco vas a conseguirlo tú.\p"
	.string "Bueno, tampoco voy a obsesionarme\n"
	.string "mucho con el tema.\p"
	.string "Seguiré coleccionando POKéMON\n"
	.string "a mi ritmo y los entrenaré.\p"
	.string "Eso es lo que voy a hacer.\n"
	.string "No merece la pena estar aquí,\l"
	.string "creo que me voy a casa.\p"
	.string "Pues eso.\n"
	.string "¡Nos vemos!$"

