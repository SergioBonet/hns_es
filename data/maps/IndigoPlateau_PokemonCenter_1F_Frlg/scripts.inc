IndigoPlateau_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	call_if_eq VAR_RESULT, TRUE, IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor::
	goto_if_set FLAG_IS_CHAMPION, Common_EventScript_NopReturn
	setobjectxyperm LOCALID_LEAGUE_DOOR_GUARD, 4, 2
	return

IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard::
	lock
	faceplayer
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	goto_if_eq VAR_RESULT, TRUE, IndigoPlateau_PokemonCenter_1F_EventScript_CheckSeviiIslandComplete
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckSeviiIslandComplete::
	goto_if_set FLAG_IS_CHAMPION, IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete
	msgbox IndigoPlateau_PokemonCenter_1F_Text_LoreleiIsAbsentClosedForTimeBeing
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice, MSGBOX_NPC
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice::
	.string "¡Hola, aspirante al título!\p"
	.string "En la LIGA POKéMON tendrás que\n"
	.string "luchar contra todos los miembros\l"
	.string "del ALTO MANDO, uno tras otro.\p"
	.string "¡Si pierdes, tendrás que volver\n"
	.string "a empezar!\p"
	.string "¡Eso es todo!\n"
	.string "¡A por ellos!$"

IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck::
	.string "¡Ahora lucharás contra todos los\n"
	.string "del ALTO MANDO, sin excepción!\p"
	.string "¡Si ganas, se abrirá una puerta\n"
	.string "y pasarás al siguiente ENTRENADOR!\l"
	.string "¡Buena suerte!$"

IndigoPlateau_PokemonCenter_1F_Text_LoreleiIsAbsentClosedForTimeBeing::
	.string "Lo siento, pero has perdido\n"
	.string "el tiempo viniendo hasta aquí.\p"
	.string "LORELEI, del ALTO MANDO,\n"
	.string "no está, como puedes comprobar.\p"
	.string "Así que la LIGA POKéMON está\n"
	.string "cerrada de momento.$"

IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs::
	.string "Los POKéMON de tipo FANTASMA\n"
	.string "de AGATHA son escalofriantemente\l"
	.string "fuertes.\p"
	.string "Yo me puse a criar a mis POKéMON\n"
	.string "del tipo LUCHA con todas las ganas\l"
	.string "del mundo...\p"
	.string "Y me planté ante AGATHA convencido\n"
	.string "de que podría ganar... y no quiero\l"
	.string "ni contarte la paliza que me dio.\p"
	.string "Además, ¡no sabes el genio que\n"
	.string "tiene la señora!\p"
	.string "¡Como empiece a gritar, lo llevas\n"
	.string "claro!$"

IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway::
	.string "Yo creo que lo de ser del ALTO\n"
	.string "MANDO se lleva en la sangre.\p"
	.string "Por lo que sé, un primo de LANCE\n"
	.string "es también LÍDER de un GIMNASIO\l"
	.string "de por ahí.$"

