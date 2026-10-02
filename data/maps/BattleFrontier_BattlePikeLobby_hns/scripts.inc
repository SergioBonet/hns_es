BattleFrontier_BattlePikeLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving_hns::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting_hns, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen_hns
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance_hns, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen_hns, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults_hns
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge_hns::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults_hns
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge_hns::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay_hns, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor_hns
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain_hns
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR_HNS, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor_hns::
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor_hns
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor_hns:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag_hns
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems_hns
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder_hns
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain_hns::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitstate
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike_hns:
	.string "¡Aquí ponemos a prueba la suerte\n"
	.string "de los ENTRENADORES!\p"
	.string "¡Te doy la bienvenida\n"
	.string "a la SIERPE BATALLA!\p"
	.string "Yo seré tu primera guía si aceptas\n"
	.string "el desafío de la ELECCIÓN de COMBATES.$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge_hns:
	.string "Dime, pues, ¿aceptas el desafío\n"
	.string "de la ELECCIÓN de COMBATES?$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike_hns:
	.string "Si aceptas entrar aquí, te enfrentarás\n"
	.string "a la llamada ELECCIÓN de COMBATES.\p"
	.string "Las reglas de la ELECCIÓN de COMBATES\n"
	.string "son muy simples…\p"
	.string "Elige uno de los tres caminos y llega\n"
	.string "a la última sala de la SIERPE BATALLA.\l"
	.string "Así de sencillo.\p"
	.string "Pero recuerda: lo que te encuentres\n"
	.string "en el camino que elijas, dependerá\l"
	.string "únicamente de tu fortuna…\p"
	.string "Si alcanzas la meta, recibirás como\n"
	.string "recompensa PUNTOS de BATALLA.\p"
	.string "Si quieres interrumpir el desafío, habla\n"
	.string "con cualquiera de mis compañeras\l"
	.string "que están en las salas grandes.\p"
	.string "Si no guardas antes de salirte\n"
	.string "del juego, se te descalificará.$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou_hns:
	.string "Esperamos que vuelvas\n"
	.string "pronto por aquí.$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode_hns:
	.string "El desafío se disputa en dos niveles:\n"
	.string "el nivel 50 y el nivel libre. ¿Cuál eliges?$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "Disculpa, pero…\p"
	.string "No tienes tres POKéMON que cumplan\n"
	.string "los requisitos de la Elección de\l"
	.string "Combate.\p"
	.string "Para participar, debes tener tres\n"
	.string "POKéMON distintos de nivel 50 o\l"
	.string "inferior.\p"
	.string "Además, deben llevar objetos\n"
	.string "distintos.\p"
	.string "Los HUEVOS{STR_VAR_1}.$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "Ven a verme cuando estés listo…$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "Disculpa, pero…\p"
	.string "No tienes tres POKéMON que cumplan\n"
	.string "los requisitos de la Elección de\l"
	.string "Combate.\p"
	.string "Para participar, debes tener tres\n"
	.string "POKéMON distintos.\p"
	.string "Además, deben llevar objetos\n"
	.string "distintos.\p"
	.string "Los HUEVOS{STR_VAR_1}.$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons_hns:
	.string "Selecciona los tres POKéMON con los\n"
	.string "que quieres combatir.$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge_hns:
	.string "Antes de comenzar tu ELECCIÓN de\n"
	.string "COMBATES, debo guardar la partida.\l"
	.string "¿Estás de acuerdo?$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay_hns:
	.string "Pasa por aquí.$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults_hns:
	.string "El desafío ha terminado…\p"
	.string "Voy a guardar tus resultados.\n"
	.string "Espera unos instantes.$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance_hns:
	.string "Has logrado finalizar el desafío…\p"
	.string "Debo reconocer… que has tenido\n"
	.string "mucha fortuna…$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults_hns:
	.string "Vamos a guardar tus resultados.\n"
	.string "Espera unos instantes.$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints_hns2_hns:
	.string "Para conmemorar que has superado el\n"
	.string "desafío de la Elección de Combate, te\l"
	.string "entregamos estos Puntos de Batalla…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit_hns:
	.string "Parece que has llegado al límite de\n"
	.string "Puntos de Batalla…\p"
	.string "Canjea algunos por premios y vuelve…$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting_hns:
	.string "Una lástima…\p"
	.string "Se te olvidó guardar la partida antes\n"
	.string "de abandonar el desafío…\p"
	.string "Me temo que se te ha descalificado…$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen_hns:
	.string "Enhorabuena…\p"
	.string "Has conseguido derrotar a la REINA\n"
	.string "de la SIERPE y superar la gran prueba…$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints_hns:
	.string "Premiaremos tu increíble fortuna\n"
	.string "con PUNTOS de BATALLA…$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal_hns:
	.string "¡Grrr! ¡La he pifiado!\n"
	.string "¡Y sólo me quedaba una sala!\p"
	.string "En este lugar hay que tener cuidado\n"
	.string "con venenos, paralizantes y demás.$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer_hns:
	.string "Aunque no te lo creas, he terminado\n"
	.string "el desafío 10 veces sin tener que\l"
	.string "enfrentarme nunca a un ENTRENADOR.$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere_hns:
	.string "¡Oye! ¡Oye!\p"
	.string "¿No crees que aquí podrías sacarles\n"
	.string "mucho partido a las habilidades\l"
	.string "especiales de los POKéMON?$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose_hns:
	.string "¿Qué es este sitio tan raro? ¡No lo\n"
	.string "entiendo!\p"
	.string "He aceptado el desafío un montón de\n"
	.string "veces, pero elija el camino que elija,\l"
	.string "siempre me encuentro con\l"
	.string "ENTRENADORES.$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed_hns:
	.string "Aquí están expuestas las reglas\n"
	.string "de la ELECCIÓN de COMBATES.$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading_hns:
	.string "¿Qué capítulo quieres leer?$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules_hns:
	.string "La MOCHILA y el POKéNAV no pueden\n"
	.string "usarse en la ELECCIÓN de COMBATES.$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules_hns:
	.string "Durante la ELECCIÓN de COMBATES,\n"
	.string "las BAYAS o HIERBAS que sostengan los\l"
	.string "POKéMON sólo tendrán efecto una vez.$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules_hns:
	.string "Durante la ELECCIÓN de COMBATES,\n"
	.string "el orden de salida de tus POKéMON\l"
	.string "no puede cambiarse.\p"
	.string "El orden debe fijarse antes de comenzar\n"
	.string "el desafío.$"

