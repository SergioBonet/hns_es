ViridianCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ViridianCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

ViridianCity_PokemonCenter_1F_EventScript_Boy::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC::
	.string "Siéntete libre de usar ese PC del\n"
	.string "rincón.\p"
	.string "Me lo dijo la recepcionista.\n"
	.string "¡Qué amable es!$"

ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown::
	.string "A este pueblo se lo conoce como\n"
	.string "el lugar de reposo de los POKéMON.\p"
	.string "Los homenajes se celebran en la\n"
	.string "TORRE POKéMON.$"

ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons::
	.string "Los CENTROS POKéMON curan a tus\n"
	.string "POKéMON cansados, heridos o\l"
	.string "debilitados.\p"
	.string "Los dejan completamente sanos.$"

