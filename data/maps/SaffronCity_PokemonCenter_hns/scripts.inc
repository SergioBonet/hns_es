SaffronCity_PokemonCenter_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_OnTransition
	.byte 0

SaffronCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY_HNS
	end

SaffronCity_PokemonCenter_EventScript_Teacher::
	msgbox SaffronCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC	
	end

SaffronCity_PokemonCenter_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher, MSGBOX_NPC	
	end
SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart::
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_EventScript_Youngster::
	msgbox SaffronCity_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_PokemonCenter1F_Text_Teacher:
	.string "¿Cómo son los CENTROS POKéMON de\n"
	.string "JOHTO?\p"
	.string "Oh… ya veo. Así que no son tan\n"
	.string "diferentes de los de KANTO…\p"
	.string "¡Entonces puedo ir a JOHTO sin tener\n"
	.string "que preocuparme!$"

SaffronCity_PokemonCenter1F_Text_Fisher:
	.string "Acabo de cruzar el TÚNEL ROCA.\p"
	.string "Pasaba algo en la CENTRAL ENERGÍA.$"

SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart:
	.string "En CIUDAD CELESTE hay una cueva muy\n"
	.string "rara.\p"
	.string "Como MONTAÑERO profesional, debería\n"
	.string "explorarla, pero ese sitio me da miedo\l"
	.string "hasta a mí.$"

SaffronCity_PokemonCenter1F_Text_Youngster:
	.string "La OFICINA CENTRAL de SILPH S.A. y la\n"
	.string "ESTACIÓN del MAGNETOTRÉN son los\l"
	.string "lugares más vistos de AZAFRÁN.$"
