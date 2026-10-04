OneIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OneIsland_OnFrame
	.byte 0

OneIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ONE_ISLAND
	end

OneIsland_OnFrame::
	map_script_2 VAR_MAP_SCENE_ONE_ISLAND_HARBOR, 2, OneIsland_EventScript_EnterOneIslandFirstTime
	.2byte 0

OneIsland_EventScript_EnterOneIslandFirstTime::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, OneIsland_Movement_PlayerExitHarbor
	waitmovement 0
	msgbox OneIsland_Text_BillLetsGoSeeCelio
	closemessage
	applymovement LOCALID_ONE_ISLAND_BILL, OneIsland_Movement_BillWalkToPokeCenter
	applymovement LOCALID_PLAYER, OneIsland_Movement_PlayerWalkToPokeCenter
	waitmovement 0
	opendoor 14, 5
	waitdooranim
	applymovement LOCALID_ONE_ISLAND_BILL, OneIsland_Movement_BillEnterPokeCenter
	applymovement LOCALID_PLAYER, OneIsland_Movement_PlayerEnterPokeCenter
	waitmovement 0
	closedoor 14, 5
	waitdooranim
	removeobject LOCALID_ONE_ISLAND_BILL
	setvar VAR_MAP_SCENE_ONE_ISLAND_HARBOR, 3
	warp MAP_ONE_ISLAND_POKEMON_CENTER_1F, 9, 9
	waitstate
	releaseall
	end

	.macro walk_to_pokecenter
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	.endm

OneIsland_Movement_PlayerWalkToPokeCenter::
	walk_up
	walk_to_pokecenter
	step_end

OneIsland_Movement_PlayerEnterPokeCenter::
	walk_up
	walk_up
	set_invisible
	step_end

OneIsland_Movement_PlayerExitHarbor::
	walk_up
	step_end

OneIsland_Movement_BillWalkToPokeCenter::
	walk_to_pokecenter
	walk_up
	step_end

OneIsland_Movement_BillEnterPokeCenter::
	walk_up
	set_invisible
	step_end

OneIsland_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, OneIsland_EventScript_OldManLinkHoenn
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_EventScript_OldManLinkKanto
	msgbox OneIsland_Text_LuckyToHaveCelioHere
	release
	end

OneIsland_EventScript_OldManLinkKanto::
	msgbox OneIsland_Text_HavePCLinkageWithKanto
	release
	end

OneIsland_EventScript_OldManLinkHoenn::
	msgbox OneIsland_Text_HavePCLinkageWithHoenn
	release
	end

OneIsland_EventScript_BaldingMan::
	msgbox OneIsland_Text_IsntWarmClimateHereGreat, MSGBOX_NPC
	end

OneIsland_EventScript_IslandSign::
	msgbox OneIsland_Text_IslandSign, MSGBOX_SIGN
	end

OneIsland_EventScript_PokemonNetCenterSign::
	msgbox OneIsland_Text_PokemonNetCenterSign, MSGBOX_SIGN
	end

OneIsland_Text_BillLetsGoSeeCelio::
	.string "BILL: Bueno, ya estamos aquí.\n"
	.string "Esto es ISLA PRIMA.\p"
	.string "Como indica su nombre,\n"
	.string "no es la única isla de por aquí.\p"
	.string "Mi amigo CELIO fue el que\n"
	.string "envió el barco.\p"
	.string "Él es el encargado de la red\n"
	.string "local de la isla. Se pasa el día\l"
	.string "con eso.\p"
	.string "Bueno, que me enrollo como las\n"
	.string "persianas, ¡vamos a ver a CELIO!$"

Text_WhereDoYouWantToSail::
	.string "¡Hola, caracola!\n"
	.string "¿Adónde vamos?$"

OneIsland_Text_LuckyToHaveCelioHere::
	.string "La verdad es que esta isla está\n"
	.string "plantada en medio de la nada,\l"
	.string "pero bueno...\p"
	.string "Menos mal que tenemos a un\n"
	.string "chicarrón hecho y derecho como\l"
	.string "CELIO.\p"
	.string "Mi nieta estaba un poco nerviosa\n"
	.string "con la llegada del amigo de CELIO.\p"
	.string "¿Será un POKéMANÍACO?\p"
	.string "En fin..., yo lo que sé es que\n"
	.string "estamos encantados con CELIO.$"

OneIsland_Text_HavePCLinkageWithKanto::
	.string "Mi nieta estaba un poco nerviosa\n"
	.string "por un reciente descubrimiento.\p"
	.string "Según dijo, ahora tenemos conexión\n"
	.string "vía PC con la gente de KANTO.\p"
	.string "En fin..., yo lo que sé es que\n"
	.string "estamos encantados con CELIO.$"

OneIsland_Text_HavePCLinkageWithHoenn::
	.string "Mi nieta estaba un poco nerviosa\n"
	.string "por un reciente descubrimiento.\p"
	.string "Según dijo, ahora tenemos conexión\n"
	.string "vía PC con la gente de HOENN.\p"
	.string "En fin..., yo lo que sé es que\n"
	.string "estamos encantados con CELIO.\p"
	.string "¡La verdad es que sería el marido\n"
	.string "perfecto para mi nieta!$"

OneIsland_Text_IslandSign::
	.string "ISLA PRIMA\n"
	.string "Punto de encuentro para todos.$"

OneIsland_Text_PokemonNetCenterSign::
	.string "CENTRO DE RED POKéMON\n"
	.string "¡Un mundo POKéMON en conexión!$"

@ Unused
OneIsland_Text_ReturnToCinnabar::
	.string "¿Quieres volver a ISLA CANELA?$"

OneIsland_Text_IsntWarmClimateHereGreat::
	.string "Hola, ¿de turismo?\n"
	.string "¿A que el clima cálido de aquí es genial?$"

