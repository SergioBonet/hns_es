ThreeIsland_Port_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_Port_OnTransition
	.byte 0

ThreeIsland_Port_OnTransition::
	clearflag FLAG_SYS_PC_STORAGE_DISABLED
	setflag FLAG_SEVII_DETOUR_FINISHED
	end

ThreeIsland_Port_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, ThreeIsland_Port_EventScript_WomanLostelleFound
	goto_if_ge VAR_MAP_SCENE_THREE_ISLAND, 4, ThreeIsland_Port_EventScript_WomanBikersGone
	msgbox ThreeIsland_Port_Text_IllCallThePolice
	release
	end

ThreeIsland_Port_EventScript_WomanLostelleFound::
	msgbox ThreeIsland_Port_Text_EverythingTurnedOutForBest
	release
	end

ThreeIsland_Port_EventScript_WomanBikersGone::
	msgbox ThreeIsland_Port_Text_ThankGoodnessBikersGone
	release
	end

ThreeIsland_Port_EventScript_Biker1::
	msgbox ThreeIsland_Port_Text_WereKantoRiderFederation, MSGBOX_NPC
	end

ThreeIsland_Port_EventScript_Biker2::
	lock
	msgbox ThreeIsland_Port_Text_ForkOverMoney
	release
	end

ThreeIsland_Port_Text_WereKantoRiderFederation::
	.string "FEDERACIÓN MOTORISTA de KANTO\n"
	.string "¡Rrruuunn! ¡Rrruuun! ¡Rruunnn!\p"
	.string "¡Mi moto no es muy potente,\n"
	.string "por eso hago los ruidos yo mismo!$"

ThreeIsland_Port_Text_ForkOverMoney::
	.string "¡Eh, señora! ¡Déjese caer\n"
	.string "y denos algo de pasta!$"

ThreeIsland_Port_Text_IllCallThePolice::
	.string "¡Aaaaaaah!\p"
	.string "Pero ¿qui-qui-quiénes sois?\n"
	.string "Voy a... ¡a llamar a la policía!$"

ThreeIsland_Port_Text_ThankGoodnessBikersGone::
	.string "¡Dichosos MOTORISTAS!...\n"
	.string "¿Se han marchado ya?\p"
	.string "¡Menos mal!\n"
	.string "¡Me han dado un susto tremendo!$"

ThreeIsland_Port_Text_EverythingTurnedOutForBest::
	.string "Bueno, ya no hay problema.\n"
	.string "Los MOTORISTAS se han marchado\p"
	.string "y PEDRITA ha aparecido sana y\n"
	.string "salva, ¡eso es lo importante!$"

