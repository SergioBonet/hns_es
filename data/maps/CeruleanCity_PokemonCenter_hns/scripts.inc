CeruleanCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY_HNS
	end

CeruleanCity_PokemonCenter_EventScript_Nerd::
	msgbox CeruleanCity_PokemonCenter1F_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_EventScript_Guy::
	msgbox CeruleanCity_PokemonCenter1F_Text_GymGuide, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter1F_Text_SuperNerd:
	.string "En los combates yo prefiero usar\p"
	.string "POKéMON que he entrenado, aunque\n"
	.string "sean más débiles que los POKéMON\l"
	.string "recién capturados.$"

CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "El MAGNETOTRÉN viaja a unos\p"
	.string "550 km/h. Puede llevarte de\p"
	.string "KANTO a JOHTO en pocos segundos.\p"
	.string "Hace que sea muy fácil ir a JOHTO.$"
