MahoganyTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_PokemonCenter_OnTransition
	.byte 0

MahoganyTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
	end

MahoganyTown_PokemonCenter_EventScript_Hiker::
	msgbox MahoganyTown_PokemonCenter_Text_PokefanM, MSGBOX_NPC
	end
	
MahoganyTown_PokemonCenter_EventScript_Boy::
	msgbox MahoganyTown_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_EventScript_Girl::
	msgbox MahoganyTown_PokemonCenter_Text_CooltrainerF, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_Text_PokefanM:
	.string "¿Qué pasa? ¿Ha vuelto el TEAM ROCKET?\p"
	.string "He visto hombres de negro en el LAGO\n"
	.string "DE LA FURIA.$"

MahoganyTown_PokemonCenter_Text_Youngster:
	.string "No permito que mis POKéMON\n"
	.string "evolucionen demasiado pronto.\p"
	.string "Antes de dejarles evolucionar, les\n"
	.string "enseño algunos movimientos.$"

MahoganyTown_PokemonCenter_Text_CooltrainerF:
	.string "Al evolucionar, los POKéMON se\n"
	.string "fortalecen, pero tardan más en\l"
	.string "aprender ataques.$"
