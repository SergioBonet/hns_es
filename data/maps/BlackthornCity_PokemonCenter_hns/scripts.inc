BlackthornCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_PokemonCenter_OnTransition
	.byte 0

BlackthornCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	end

BlackthornCity_PokemonCenter_EventScript_Gent::
	msgbox BlackthornCity_PokemonCenter1FGentlemanText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter_EventScript_Twin::
	msgbox BlackthornCity_PokemonCenter1FTwinText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter1FGentlemanText:
	.string "En el corazón de la remota Meseta Añil\n"
	.string "se celebra la LIGA POKéMON.\p"
	.string "Dicen que allí se reúnen los mejores\n"
	.string "Entrenadores de todo el país.$"

BlackthornCity_PokemonCenter1FTwinText:
	.string "Tenía un movimiento que quería\n"
	.string "enseñar a mi POKéMON.\p"
	.string "Así que usé el QUITA-MOVIMIENTOS y\n"
	.string "eliminé una MO.$"
