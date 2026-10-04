SevenIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SevenIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_SEVEN_ISLAND
	end

SevenIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

SevenIsland_PokemonCenter_1F_EventScript_OldMan::
	msgbox SevenIsland_PokemonCenter_1F_Text_EventsDependingOnConnections, MSGBOX_NPC
	end

SevenIsland_PokemonCenter_1F_EventScript_Sailor::
	msgbox SevenIsland_PokemonCenter_1F_Text_DidYouRideSeagallopHere, MSGBOX_NPC
	end

SevenIsland_PokemonCenter_1F_EventScript_Beauty::
	msgbox SevenIsland_PokemonCenter_1F_Text_CheckOutTrainerTower, MSGBOX_NPC
	end

SevenIsland_PokemonCenter_1F_Text_EventsDependingOnConnections::
	.string "En la isla, ocurren distintas cosas\n"
	.string "según las conexiones.\p"
	.string "¿Que qué son las conexiones?\p"
	.string "Eso tendrás que descubrirlo sin\n"
	.string "ayuda de nadie.$"

SevenIsland_PokemonCenter_1F_Text_DidYouRideSeagallopHere::
	.string "¿Has venido a bordo del SURCAMAR?\p"
	.string "Creo que en total hay diez barcos\n"
	.string "rápidos de esos.\p"
	.string "Pero no sé las rutas que cubren.$"

SevenIsland_PokemonCenter_1F_Text_CheckOutTrainerTower::
	.string "Si te sientes con fuerzas, deberías\n"
	.string "visitar la TORRE DESAFÍO.$"

