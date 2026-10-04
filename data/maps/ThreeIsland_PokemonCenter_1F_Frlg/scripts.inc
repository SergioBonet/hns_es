ThreeIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ThreeIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_THREE_ISLAND
	end

ThreeIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

ThreeIsland_PokemonCenter_1F_EventScript_Sailor::
	msgbox ThreeIsland_PokemonCenter_1F_Text_ImpossibleToSurfBetweenIslands, MSGBOX_NPC
	end

ThreeIsland_PokemonCenter_1F_EventScript_Lass::
	msgbox ThreeIsland_PokemonCenter_1F_Text_AlwaysBerriesInBerryForest, MSGBOX_NPC
	end

ThreeIsland_PokemonCenter_1F_EventScript_Rocker::
	msgbox ThreeIsland_PokemonCenter_1F_Text_PCNetworkCanLinkWithKanto, MSGBOX_NPC
	end

ThreeIsland_PokemonCenter_1F_Text_PCNetworkCanLinkWithKanto::
	.string "Eh, ¿te has enterado?\p"
	.string "Ahora podemos estar en red\n"
	.string "con los PCs de KANTO.\p"
	.string "¡No sé quién lo habrá organizado,\n"
	.string "pero me parece una idea estupenda!$"

ThreeIsland_PokemonCenter_1F_Text_ImpossibleToSurfBetweenIslands::
	.string "Es imposible hacer SURF\n"
	.string "entre las islas de esta zona.\p"
	.string "Hay corrientes y remolinos.$"

ThreeIsland_PokemonCenter_1F_Text_AlwaysBerriesInBerryForest::
	.string "¡Vamos a MACHACAR BAYAS!\n"
	.string "¿Que sería un desperdicio de BAYAS\l"
	.string "dices?...\p"
	.string "¡Pero si el BOSQUE BAYA está hasta\n"
	.string "arriba!$"

