PewterCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PewterCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

PewterCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox PewterCity_PokemonCenter_1F_Text_TeamRocketMtMoonImOnPhone, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_EventScript_Jigglypuff::
	lock
	faceplayer
	fadeoutbgm 0
	playbgm MUS_RG_JIGGLYPUFF, 0
	message PewterCity_PokemonCenter_1F_Text_Jigglypuff
	waitmessage
	delay 455
	playbgm MUS_POKE_CENTER, 1
	release
	end

PewterCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PewterCity_PokemonCenter_1F_Text_WhenJiggylypuffSingsMonsGetDrowsy, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_EventScript_GBAKid1::
	lock
	msgbox PewterCity_PokemonCenter_1F_Text_TradingMyClefairyForPikachu
	release
	end

PewterCity_PokemonCenter_1F_EventScript_GBAKid2::
	msgbox PewterCity_PokemonCenter_1F_Text_TradingPikachuWithKid, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_Text_TeamRocketMtMoonImOnPhone::
	.string "¿¡Qué!?\p"
	.string "¿Que el TEAM ROCKET está en el\n"
	.string "MT. MOON?\p"
	.string "¡Estoy hablando por teléfono!\n"
	.string "¿Será posible?$"

PewterCity_PokemonCenter_1F_Text_Jigglypuff::
	.string "JIGGLYPUFF: ¡Puf! ¡Puuuff!$"

PewterCity_PokemonCenter_1F_Text_WhenJiggylypuffSingsMonsGetDrowsy::
	.string "Aaah..., qué sueño...\p"
	.string "Cuando JIGGLYPUFF canta, los\n"
	.string "POKéMON se duermen...\p"
	.string "Y yo también...\n"
	.string "Qué sueño...$"

PewterCity_PokemonCenter_1F_Text_TradingMyClefairyForPikachu::
	.string "¡Yo quiero un PIKACHU, así que\n"
	.string "voy a intercambiar a mi CLEFAIRY\l"
	.string "por uno!$"

PewterCity_PokemonCenter_1F_Text_TradingPikachuWithKid::
	.string "Voy a intercambiar mi POKéMON\n"
	.string "con ese chico de ahí.\p"
	.string "Como tengo dos PIKACHU,\n"
	.string "voy a pasarle uno.$"

