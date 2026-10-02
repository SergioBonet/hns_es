ViridianCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_OnTransition
	.byte 0

ViridianCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY_HNS
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerM::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerMBlue::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerF, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_BugCatcher::
	msgbox ViridianCity_PokemonCenter_Text_1FBugCatcher, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_Text_1FCooltrainerM:
	.string "¿Dónde estará el LÍDER del GIMNASIO\p"
	.string "de CIUDAD VERDE? Quería desafiarle.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned:
	.string "No hay ningún ENTRENADOR en el\p"
	.string "GIMNASIO de CIUDAD VERDE.\p"
	.string "El LÍDER dice que su política es ganar\n"
	.string "sin tener subordinados.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerF:
	.string "Dicen que el GIMNASIO de ISLA\p"
	.string "CANELA está destruido.\p"
	.string "Me pregunto qué habrá sido de BLAINE,\n"
	.string "su LÍDER.$"

ViridianCity_PokemonCenter_Text_1FBugCatcher:
	.string "Mi sueño es ser LÍDER de GIMNASIO.$"
