FiveIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FiveIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FIVE_ISLAND
	end

FiveIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

FiveIsland_PokemonCenter_1F_EventScript_Chef::
	msgbox FiveIsland_PokemonCenter_1F_Text_OnMyWayToPrepareMeal, MSGBOX_NPC
	end

FiveIsland_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox FiveIsland_PokemonCenter_1F_Text_YoureOnQuestToCatchEveryMon, MSGBOX_NPC
	end

FiveIsland_PokemonCenter_1F_Text_OnMyWayToPrepareMeal::
	.string "Voy a preparar una comida para\n"
	.string "una persona muy importante.$"

FiveIsland_PokemonCenter_1F_Text_YoureOnQuestToCatchEveryMon::
	.string "¿Quieres atrapar a todos los\n"
	.string "POKéMON que te encuentres?\p"
	.string "¡Qué increíble!... ¡Oye, pues\n"
	.string "avísame si atrapas alguno fuerte!$"

