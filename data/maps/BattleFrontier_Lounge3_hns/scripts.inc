BattleFrontier_Lounge3_hns_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler_hns::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5_hns
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10_hns
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15_hns
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet5_hns::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet10_hns::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet15_hns::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet_hns
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_PlaceBet_hns::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet_hns
	end

BattleFrontier_Lounge3_EventScript_FinishBet_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns::
	msgbox BattleFrontier_Lounge3_Text_Oh_hns, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults_hns
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults_hns::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge_hns
	goto BattleFrontier_Lounge3_EventScript_LostChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_WonChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15_hns
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NotInterested_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet_hns::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_Man_hns::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_PokefanF_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FatMan_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns::
	.string "¿Y tú qué es lo que quieres?\p"
	.string "¿No ves que estamos ocupados?\n"
	.string "¿O es que no puedes esperar?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns::
	.string "Anda, mira, a primera vista\n"
	.string "se ve que ENTRENAS con fiereza.\p"
	.string "Je, je, je…\n"
	.string "Oye, te propongo una cosa.\p"
	.string "Hemos formado un grupillo aquí,\n"
	.string "y solemos jugar a un juego que va\l"
	.string "sobre el FRENTE de BATALLA.\p"
	.string "Las reglas son muy sencillas.\p"
	.string "Primero, elegimos uno de los escenarios\n"
	.string "que hay en el FRENTE de BATALLA.\p"
	.string "Luego, cada uno elige a un ENTRENADOR\n"
	.string "que vaya a participar en el desafío\l"
	.string "de ese escenario y apostamos por él\l"
	.string "nuestros PUNTOS de BATALLA.\p"
	.string "El que apueste por el ENTRENADOR que\n"
	.string "consiga el mejor resultado, se lleva\l"
	.string "los PUNTOS de BATALLA de los demás.\p"
	.string "¿Fácil, verdad?\n"
	.string "Pues eso.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle_hns::
	.string "Estoy buscando a un ENTRENADOR que\n"
	.string "quiera luchar en el COMBATE INDIVIDUAL\l"
	.string "de la TORRE BATALLA.\p"
	.string "Pero, hasta ahora, no he visto a nadie\n"
	.string "que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble_hns::
	.string "Estoy buscando a un ENTRENADOR que\n"
	.string "quiera luchar en el COMBATE DOBLE\l"
	.string "de la TORRE BATALLA.\p"
	.string "Pero, hasta ahora, no he visto a nadie\n"
	.string "que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti_hns::
	.string "Estoy buscando a un ENTRENADOR que\n"
	.string "quiera luchar en el COMBATE MÚLTIPLE\l"
	.string "de la TORRE BATALLA.\p"
	.string "Pero, hasta ahora, no he visto a nadie\n"
	.string "que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle_hns::
	.string "Estoy buscando a un ENTRENADOR que\n"
	.string "quiera entrar en el TORNEO de COMBATES\l"
	.string "INDIVIDUALES de la CÚPULA BATALLA.\p"
	.string "Pero, hasta ahora, no he visto a nadie\n"
	.string "que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble_hns::
	.string "Estoy buscando a un ENTRENADOR que\n"
	.string "quiera entrar en el TORNEO de COMBATES\l"
	.string "DOBLES de la CÚPULA BATALLA.\p"
	.string "Pero, hasta ahora, no he visto a nadie\n"
	.string "que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle_hns::
	.string "Estoy buscando a un ENTRENADOR que\n"
	.string "quiera entrar en el TORNEO de COMBATES\l"
	.string "con TRUEQUE INDIVIDUALES\l"
	.string "en la FÁBRICA BATALLA.\p"
	.string "Pero, hasta ahora, no he visto a nadie\n"
	.string "que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble_hns::
	.string "Estoy buscando a un ENTRENADOR que\n"
	.string "quiera entrar en el TORNEO de COMBATES\l"
	.string "con TRUEQUE DOBLES\l"
	.string "en la FÁBRICA BATALLA.\p"
	.string "Pero, hasta ahora, no he visto a nadie\n"
	.string "que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle_hns::
	.string "Estoy buscando a un ENTRENADOR que\n"
	.string "quiera luchar en el COMBATE sin TUTELA\l"
	.string "INDIVIDUAL del PALACIO BATALLA.\p"
	.string "Pero, hasta ahora, no he visto a nadie\n"
	.string "que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble_hns::
	.string "Estoy buscando a un ENTRENADOR que\n"
	.string "quiera luchar en el COMBATE sin TUTELA\l"
	.string "DOBLE del PALACIO BATALLA.\p"
	.string "Pero, hasta ahora, no he visto a nadie\n"
	.string "que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena_hns::
	.string "Estoy buscando a un ENTRENADOR que\n"
	.string "quiera entrar en el TORNEO con JUEZ\l"
	.string "en el DOJO BATALLA.\p"
	.string "Pero, hasta ahora, no he visto a nadie\n"
	.string "que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike_hns::
	.string "Estoy buscando a un ENTRENADOR que\n"
	.string "quiera entrar en la ELECCIÓN\l"
	.string "de COMBATES en la SIERPE BATALLA.\p"
	.string "Pero, hasta ahora, no he visto a nadie\n"
	.string "que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid_hns::
	.string "Estoy buscando a un ENTRENADOR que\n"
	.string "quiera entrar en la EXPEDICIÓN\l"
	.string "de COMBATES en la PIRÁMIDE BATALLA.\p"
	.string "Pero, hasta ahora, no he visto a nadie\n"
	.string "que me inspire la suficiente confianza.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns::
	.string "Creo que tú también podrías ganar algo.\n"
	.string "Así que, ¿qué me dices?\l"
	.string "¿Aceptarías ese desafío por mí?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns::
	.string "Perfecto… ¿Qué tal si me prestas\n"
	.string "algunos de tus PUNTOS de BATALLA?\p"
	.string "Confía en mí, sé agradecer los favores\n"
	.string "con creces.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns::
	.string "¡Genial, genial!\n"
	.string "¿Cuántos me puedes prestar?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns::
	.string "¡Oh, no, no, no! ¡No tienes suficientes\n"
	.string "PUNTOS de BATALLA!\p"
	.string "¡Yo que tú no iría por ahí burlándome de\n"
	.string "la gente ni haciéndole perder el tiempo!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns::
	.string "¡Je, je, je! ¡Muchas gracias!\n"
	.string "¡Venga, adelante!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle_hns::
	.string "¡Te espera el COMBATE INDIVIDUAL\n"
	.string "de la TORRE BATALLA!\p"
	.string "¡No puedes perder!\n"
	.string "¡No me falles!\l"
	.string "¡Nuestra fortuna está en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble_hns::
	.string "¡Te espera el COMBATE DOBLE\n"
	.string "de la TORRE BATALLA!\p"
	.string "¡No puedes perder!\n"
	.string "¡No me falles!\l"
	.string "¡El futuro de los dos está en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti_hns::
	.string "¡Te espera el COMBATE MÚLTIPLE\n"
	.string "de la TORRE BATALLA!\p"
	.string "¡No puedes perder!\n"
	.string "¡No me falles!\l"
	.string "¡El futuro de los dos está en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle_hns::
	.string "¡Te espera el TORNEO de COMBATES\n"
	.string "INDIVIDUALES de la CÚPULA BATALLA!\p"
	.string "¡No puedes perder!\n"
	.string "¡No me falles!\l"
	.string "¡El futuro de los dos está en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble_hns::
	.string "¡Te espera el TORNEO de COMBATES\n"
	.string "DOBLES de la CÚPULA BATALLA!\p"
	.string "¡No puedes perder!\n"
	.string "¡No me falles!\l"
	.string "¡El futuro de los dos está en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle_hns::
	.string "¡Te espera el TORNEO de COMBATES\n"
	.string "con TRUEQUE INDIVIDUALES\l"
	.string "de la FÁBRICA BATALLA!\p"
	.string "¡No puedes perder!\n"
	.string "¡No me falles!\l"
	.string "¡El futuro de los dos está en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble_hns::
	.string "¡Te espera el TORNEO de COMBATES\n"
	.string "con TRUEQUE DOBLES\l"
	.string "de la FÁBRICA BATALLA!\p"
	.string "¡No puedes perder!\n"
	.string "¡No me falles!\l"
	.string "¡El futuro de los dos está en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle_hns::
	.string "¡Te espera el COMBATE sin TUTELA\n"
	.string "INDIVIDUAL del PALACIO BATALLA!\p"
	.string "¡No puedes perder!\n"
	.string "¡No me falles!\l"
	.string "¡El futuro de los dos está en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble_hns::
	.string "¡Te espera el COMBATE sin TUTELA\n"
	.string "DOBLE del PALACIO BATALLA!\p"
	.string "¡No puedes perder!\n"
	.string "¡No me falles!\l"
	.string "¡El futuro de los dos está en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattleArena_hns::
	.string "¡Te espera el TORNEO con JUEZ\n"
	.string "del DOJO BATALLA!\p"
	.string "¡No puedes perder!\n"
	.string "¡No me falles!\l"
	.string "¡El futuro de los dos está en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattlePike_hns::
	.string "¡Te espera la ELECCIÓN de COMBATES\n"
	.string "de la SIERPE BATALLA!\p"
	.string "¡No puedes perder!\n"
	.string "¡No me falles!\l"
	.string "¡El futuro de los dos está en tus manos!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid_hns::
	.string "¡Te espera la EXPEDICIÓN de COMBATES\n"
	.string "de la PIRÁMIDE BATALLA!\p"
	.string "¡No puedes perder!\n"
	.string "¡No me falles!\l"
	.string "¡El futuro de los dos está en tus manos!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns::
	.string "Ah, eres tú…\n"
	.string "Buen intento…\p"
	.string "Siento decírtelo, pero no puedo\n"
	.string "devolverte tus PUNTOS de BATALLA…\p"
	.string "¡Tendremos que motivarnos para\n"
	.string "hacerlo mejor la próxima vez!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns::
	.string "¡Eh, hola!\p"
	.string "¡Sabía que podías!\n"
	.string "¡Sabía que lo harías!\l"
	.string "Gracias a ti, ¡hemos ganado los dos!\p"
	.string "Toma, tus PUNTOS de BATALLA\n"
	.string "y, por supuesto, ¡tu recompensa!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns::
	.string "{PLAYER} obtuvo\n"
	.string "{STR_VAR_1} PUNTOS de BATALLA.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns::
	.string "Antes de aceptar otro desafío,\n"
	.string "¡habla antes conmigo!$"

BattleFrontier_Lounge3_Text_NotInterested_hns::
	.string "¡¿No te interesa?!\n"
	.string "¡No deberías tener miedo de probar!$"

BattleFrontier_Lounge3_Text_Oh_hns::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns::
	.string "¡He apostado otra vez por\n"
	.string "el ENTRENADOR equivocado!\p"
	.string "Quizás debería combatir yo misma,\n"
	.string "como hacen los demás…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns::
	.string "Ese ENTRENADOR…\p"
	.string "Es bueno, pero no lo veo con el aguante\n"
	.string "necesario para la CÚPULA BATALLA…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns::
	.string "¡Yo reconozco a un ENTRENADOR\n"
	.string "ganador nada más verlo! ¡Ji, ji, ji!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns::
	.string "Pero esos ENTRENADORES…\n"
	.string "¿Qué están haciendo?\l"
	.string "Deberían estar combatiendo, ¿no?$"
