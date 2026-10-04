LavenderTown_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavenderTown_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

LavenderTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_EventScript_Lass::
	msgbox LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney::
	.string "¡El TEAM ROCKET hará lo que sea\n"
	.string "por el oro!\p"
	.string "¡No hay trabajo sucio ni actos\n"
	.string "vandálicos que no sean capaces\l"
	.string "de hacer!$"

LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets::
	.string "¡Vi a la madre de CUBONE\n"
	.string "intentando huir del TEAM ROCKET!\p"
	.string "La pobre no lo consiguió...$"

LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls::
	.string "Los CUBONE llevan cráneos,\n"
	.string "¿verdad?\p"
	.string "¡La gente pagaría mucho por uno\n"
	.string "de ellos!$"

