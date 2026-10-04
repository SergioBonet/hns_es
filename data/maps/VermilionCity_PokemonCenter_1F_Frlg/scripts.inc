VermilionCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VermilionCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_Man::
	msgbox VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Hiker::
	msgbox VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_VSSeekerWoman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_VS_SEEKER, VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker
	msgbox VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain
	setflag FLAG_GOT_VS_SEEKER
	giveitem ITEM_VS_SEEKER
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker::
	msgbox VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker
	release
	end

VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild::
	.string "Aunque sean del mismo nivel, los\n"
	.string "POKéMON pueden tener diferentes\l"
	.string "habilidades.\p"
	.string "Un POKéMON entrenado es más fuerte\n"
	.string "que uno salvaje.$"

VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking::
	.string "¡Mi POKéMON fue envenenado y\n"
	.string "se debilitó mientras caminábamos!$"

VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes::
	.string "Es cierto que un POKéMON de un\n"
	.string "nivel superior es más fuerte.\p"
	.string "Pero todos los POKéMON son\n"
	.string "vulnerables ante ciertos tipos.\p"
	.string "Es decir, que no hay POKéMON\n"
	.string "invulnerables.$"

VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain::
	.string "Esa necesidad de luchar de nuevo\n"
	.string "con gente a la que ya te has\l"
	.string "enfrentado...\p"
	.string "¿Sabes a lo que me refiero?\n"
	.string "Seguro que la has sentido alguna\l"
	.string "vez.\p"
	.string "Yo quería luchar una y otra vez\n"
	.string "con mis antiguos rivales.\p"
	.string "Y me dieron esto.\n"
	.string "¡Toma uno para ti!$"

VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches::
	.string "Usa este dispositivo para ver qué\n"
	.string "ENTRENADOR quiere luchar de\l"
	.string "nuevo contigo.\p"
	.string "Ten en cuenta que debes cargar\n"
	.string "la batería.$"

VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker::
	.string "¿Cómo se usa el BUSCAPELEA?\n"
	.string "No tiene ciencia.\p"
	.string "Úsalo así, bip-bip-bip, y los\n"
	.string "ENTRENADORES de alrededor lo notarán.\p"
	.string "Si algún ENTRENADOR quiere una\n"
	.string "revancha, te avisará al instante.\p"
	.string "Carga su batería y úsalo\n"
	.string "mientras vas por un camino.$"
