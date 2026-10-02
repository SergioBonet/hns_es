LavenderTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN_HNS
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "Al norte de PUEBLO LAVANDA está el\n"
	.string "TÚNEL ROCA.\p"
	.string "Crúzalo para llegar a la CENTRAL\n"
	.string "ENERGÍA.$"

LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "Hay un programa de radio que emite\n"
	.string "música de la POKé FLAUTA.\p"
	.string "¿Eh? Ah, tu radio necesita una MEJORA\n"
	.string "de RADIO para sintonizarlo.\p"
	.string "¿Quizás la EMISORA DE RADIO de aquí\n"
	.string "te pueda dar una?$"

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "Si la CENTRAL ENERGÍA no está en\n"
	.string "funcionamiento, el Magnetotrén\l"
	.string "tampoco lo estará…\p"
	.string "Y eso significa que tampoco habrá\n"
	.string "emisiones de radio.$"

LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "El DIRECTOR de la EMISORA estaba muy\n"
	.string "contento.\p"
	.string "Dijo que han vuelto a emitir porque la\n"
	.string "CENTRAL ENERGÍA ya funciona.$"
