VermilionCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_OnTransition
	.byte 0

VermilionCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY_HNS
	end

VermilionPokeCenter_EventScript_FishingGuru::
	goto_if_set FLAG_HIDE_VERMILION_SNORLAX, VermilionPokeCenter_EventScript_FishingGuru2
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_FishingGuru2::
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Sailor::
	msgbox VermilionCity_PokemonCenter1F_Text_Sailor, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Bugcatcher::
	msgbox VermilionCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

VermilionCity_PokemonCenter1F_Text_FishingGuru:
	.string "Hay un POKéMON dormido delante de la\n"
	.string "CUEVA DIGLETT.\p"
	.string "¡El momento ideal para atraparlo!\p"
	.string "¿Pero cómo lo despertaremos?$"

VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax:
	.string "Antes había un POKéMON durmiendo\n"
	.string "delante de la CUEVA de DIGLETT.\p"
	.string "Pero parece que ha desaparecido.$"

VermilionCity_PokemonCenter1F_Text_Sailor:
	.string "El FERRY es un buen lugar para luchar\n"
	.string "y conocer entrenadores.$"

VermilionCity_PokemonCenter1F_Text_BugCatcher:
	.string "Tienes algunas MEDALLAS que no había\n"
	.string "visto nunca.\p"
	.string "¡Claro! Las has ganado en JOHTO.$"
