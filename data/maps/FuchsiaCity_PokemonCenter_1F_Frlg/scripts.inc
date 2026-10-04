FuchsiaCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FuchsiaCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FUCHSIA_CITY
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Man::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon::
	.string "No se puede ser un buen ENTRENADOR\n"
	.string "con un solo POKéMON fuerte.\p"
	.string "Pero criar a muchos POKéMON por\n"
	.string "igual tampoco es tarea fácil.$"

FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian::
	.string "Hay un sendero estrecho al oeste de\n"
	.string "CIUDAD VERDE.\p"
	.string "Lleva al CUARTEL de la LIGA POKéMON.\n"
	.string "El CUARTEL gobierna a todos los\l"
	.string "ENTRENADORES.$"

FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex::
	.string "Si estás completando una POKéDEX,\n"
	.string "visita la ZONA SAFARI.\p"
	.string "Allí se crían todo tipo de POKéMON\n"
	.string "raros.$"

