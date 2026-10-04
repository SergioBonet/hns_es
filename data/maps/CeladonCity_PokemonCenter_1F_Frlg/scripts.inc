CeladonCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CeladonCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

CeladonCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

CeladonCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CeladonCity_PokemonCenter_1F_Text_PokeFluteAwakensSleepingMons, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter_1F_Text_RodeHereFromFuchsia, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox CeladonCity_PokemonCenter_1F_Text_GoToCyclingRoadIfIHadBike, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_Text_PokeFluteAwakensSleepingMons::
	.string "La POKé FLAUTA despierta a los\n"
	.string "POKéMON dormidos. Ya lo sabes.\p"
	.string "Lo hace con un sonido que solo\n"
	.string "ellos pueden oír.$"

CeladonCity_PokemonCenter_1F_Text_RodeHereFromFuchsia::
	.string "Vine desde FUCSIA.\p"
	.string "El CAMINO de BICIS es cuesta arriba,\n"
	.string "así que estoy agotado.$"

CeladonCity_PokemonCenter_1F_Text_GoToCyclingRoadIfIHadBike::
	.string "¡Si tuviera una BICI, iría al\n"
	.string "CAMINO de BICIS!$"

