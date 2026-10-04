BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	facilitytrainerbattle FACILITY_BATTLE_PYRAMID
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Mensaje de prueba.$"

gText_BattlePyramidConfirmRest::
	.string "Tu expedición de la PIRÁMIDE BATALLA\n"
	.string "se guardará para que puedas tomarte\l"
	.string "un descanso. ¿Estás de acuerdo?$"

gText_BattlePyramidConfirmRetire::
	.string "¿Seguro que quieres abandonar tu\n"
	.string "expedición a la PIRÁMIDE?$"

BattlePyramid_Text_ExitHintUp1::
	.string "La salida de esta planta está en\n"
	.string "esta dirección: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "La salida de esta planta está en\n"
	.string "esta dirección: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "La salida de esta planta está en\n"
	.string "esta dirección: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "La salida de esta planta está en\n"
	.string "esta dirección: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "La salida de esta planta está en\n"
	.string "dirección {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "La salida de esta planta está en\n"
	.string "dirección {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "La salida de esta planta está en\n"
	.string "dirección {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "La salida de esta planta está en\n"
	.string "dirección {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "La salida está por\n"
	.string "ese lado {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "La salida está por\n"
	.string "ese lado {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight3::
	.string "La salida está por\n"
	.string "ese lado {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown3::
	.string "La salida está por\n"
	.string "ese lado {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp4::
	.string "En esta planta, la salida está en\n"
	.string "algún punto en dirección {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "En esta planta, la salida está en\n"
	.string "algún punto en dirección {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "En esta planta, la salida está en\n"
	.string "algún punto en dirección {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "En esta planta, la salida está en\n"
	.string "algún punto en dirección {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "¿La salida?\n"
	.string "Por ahí {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "¿La salida?\n"
	.string "Por ahí {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight5::
	.string "¿La salida?\n"
	.string "Por ahí {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown5::
	.string "¿La salida?\n"
	.string "Por ahí {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp6::
	.string "La salida está justo en\n"
	.string "dirección {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "La salida está justo en\n"
	.string "dirección {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "La salida está justo en\n"
	.string "dirección {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "La salida está justo en\n"
	.string "dirección {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan ocho objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan siete objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan seis objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan cinco objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan cuatro objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan tres objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan dos objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Queda un objeto por\n"
	.string "encontrar.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "¡No queda nada por\n"
	.string "encontrar!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Como has ganado, te revelo\n"
	.string "un pequeño secreto.\p"
	.string "Hay ocho objetos\n"
	.string "tirados por aquí.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Como has ganado, te revelo\n"
	.string "un pequeño secreto.\p"
	.string "Hay siete objetos\n"
	.string "tirados por aquí.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Como has ganado, te revelo\n"
	.string "un pequeño secreto.\p"
	.string "Hay seis objetos\n"
	.string "tirados por aquí.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Como has ganado, te revelo\n"
	.string "un pequeño secreto.\p"
	.string "Hay cinco objetos\n"
	.string "tirados por aquí.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Como has ganado, te revelo\n"
	.string "un pequeño secreto.\p"
	.string "Hay cuatro objetos\n"
	.string "tirados por aquí.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Como has ganado, te revelo\n"
	.string "un pequeño secreto.\p"
	.string "Hay tres objetos\n"
	.string "tirados por aquí.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Como has ganado, te revelo\n"
	.string "un pequeño secreto.\p"
	.string "Hay dos objetos\n"
	.string "tirados por aquí.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Como has ganado, te revelo\n"
	.string "un pequeño secreto.\p"
	.string "Solo queda un objeto\n"
	.string "tirado por aquí.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Como has ganado, te revelo\n"
	.string "un pequeño secreto.\p"
	.string "No queda nada\n"
	.string "tirado por aquí.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "¿Qué tal vas de objetos?\p"
	.string "Creo que quedan ocho objetos por\n"
	.string "encontrar en esta planta.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "¿Qué tal vas de objetos?\p"
	.string "Creo que quedan siete objetos por\n"
	.string "encontrar en esta planta.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "¿Qué tal vas de objetos?\p"
	.string "Creo que quedan seis objetos por\n"
	.string "encontrar en esta planta.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "¿Qué tal vas de objetos?\p"
	.string "Creo que quedan cinco objetos por\n"
	.string "encontrar en esta planta.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "¿Qué tal vas de objetos?\p"
	.string "Creo que quedan cuatro objetos por\n"
	.string "encontrar en esta planta.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "¿Qué tal vas de objetos?\p"
	.string "Creo que quedan tres objetos por\n"
	.string "encontrar en esta planta.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "¿Qué tal vas de objetos?\p"
	.string "Creo que quedan dos objetos por\n"
	.string "encontrar en esta planta.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "¿Qué tal vas de objetos?\p"
	.string "Creo que queda un solo objeto por\n"
	.string "encontrar en esta planta.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "¿Qué tal vas de objetos?\p"
	.string "Creo que no queda ningún objeto por\n"
	.string "encontrar en esta planta.\l"
	.string "¡Cuídate!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Eres fuerte, ¡así que te has ganado\n"
	.string "una pista!\p"
	.string "Parece que hay ocho objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Eres fuerte, ¡así que te has ganado\n"
	.string "una pista!\p"
	.string "Parece que hay siete objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Eres fuerte, ¡así que te has ganado\n"
	.string "una pista!\p"
	.string "Parece que hay seis objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Eres fuerte, ¡así que te has ganado\n"
	.string "una pista!\p"
	.string "Parece que hay cinco objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Eres fuerte, ¡así que te has ganado\n"
	.string "una pista!\p"
	.string "Parece que hay cuatro objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Eres fuerte, ¡así que te has ganado\n"
	.string "una pista!\p"
	.string "Parece que hay tres objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Eres fuerte, ¡así que te has ganado\n"
	.string "una pista!\p"
	.string "Parece que hay dos objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Eres fuerte, ¡así que te has ganado\n"
	.string "una pista!\p"
	.string "Parece que solo hay un objeto más\n"
	.string "en el suelo.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "¡Te mereces una pequeña ayudita\n"
	.string "por haberme ganado!\p"
	.string "Ahí va: ¡ya no quedan más objetos\n"
	.string "en este nivel!$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 8 objetos…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 7 objetos…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 6 objetos…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 5 objetos…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 4 objetos…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 3 objetos…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 2 objetos…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 1 objeto…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "no quedan objetos…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan ocho objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan siete objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan seis objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan cinco objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan cuatro objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan tres objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan dos objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que queda un objeto más\n"
	.string "en esta planta.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que no quedan más objetos\n"
	.string "en esta planta.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te quedan otros 7\n"
	.string "ENTRENADORES aparte de mí!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te quedan otros 6\n"
	.string "ENTRENADORES aparte de mí!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te quedan otros 5\n"
	.string "ENTRENADORES aparte de mí!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te quedan otros 4\n"
	.string "ENTRENADORES aparte de mí!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te quedan otros 3\n"
	.string "ENTRENADORES aparte de mí!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te quedan otros 2\n"
	.string "ENTRENADORES aparte de mí!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te queda otro\n"
	.string "ENTRENADOR aparte de mí!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Ya no te queda ningún\n"
	.string "ENTRENADOR por batir!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "¡Qué rabia!\p"
	.string "¡Pero quedan siete ENTRENADORES!\n"
	.string "¡Alguien te humillará!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "¡Qué rabia!\p"
	.string "¡Pero quedan seis ENTRENADORES!\n"
	.string "¡Alguien te humillará!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "¡Qué rabia!\p"
	.string "¡Pero quedan cinco ENTRENADORES!\n"
	.string "¡Alguien te humillará!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "¡Qué rabia!\p"
	.string "¡Pero quedan cuatro ENTRENADORES!\n"
	.string "¡Alguien te humillará!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "¡Qué rabia!\p"
	.string "¡Pero quedan tres ENTRENADORES!\n"
	.string "¡Alguien te humillará!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "¡Qué rabia!\p"
	.string "¡Pero quedan dos ENTRENADORES!\n"
	.string "¡Alguien te humillará!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "¡Qué rabia!\p"
	.string "¡Pero queda un ENTRENADOR!\n"
	.string "¡Seguro que te humillará!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "¡Qué rabia!\p"
	.string "¡Pero ya no quedan ENTRENADORES\n"
	.string "que puedan combatirte!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te quedan 7 ENTRENADORES\n"
	.string "más en este nivel. ¿Podrás con todos?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te quedan 6 ENTRENADORES\n"
	.string "más en este nivel. ¿Podrás con todos?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te quedan 5 ENTRENADORES\n"
	.string "más en este nivel. ¿Podrás con todos?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te quedan 4 ENTRENADORES\n"
	.string "más en este nivel. ¿Podrás con todos?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te quedan 3 ENTRENADORES\n"
	.string "más en este nivel. ¿Podrás con todos?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te quedan 2 ENTRENADORES\n"
	.string "más en este nivel. ¿Podrás con todos?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te queda 1 ENTRENADOR\n"
	.string "más en este nivel. ¿Cómo lo ves?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "¡Has acabado uno a uno con todos\n"
	.string "los ENTRENADORES de este nivel!$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Dudo que puedas derrotar a los 7\n"
	.string "ENTRENADORES que quedan en este nivel.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Dudo que puedas derrotar a los 6\n"
	.string "ENTRENADORES que quedan en este nivel.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Dudo que puedas derrotar a los 5\n"
	.string "ENTRENADORES que quedan en este nivel.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Dudo que puedas derrotar a los 4\n"
	.string "ENTRENADORES que quedan en este nivel.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Dudo que puedas derrotar a los 3\n"
	.string "ENTRENADORES que quedan en este nivel.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Dudo que puedas derrotar a los 2\n"
	.string "ENTRENADORES que quedan en este nivel.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Dudo que puedas derrotar al\n"
	.string "ENTRENADOR que queda en este nivel.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Bueno, ya no te queda nadie\n"
	.string "por vencer en este nivel…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Puede que hasta consigas derrotar\n"
	.string "a los 7 ENTRENADORES que quedan.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Puede que hasta consigas derrotar\n"
	.string "a los 6 ENTRENADORES que quedan.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Puede que hasta consigas derrotar\n"
	.string "a los 5 ENTRENADORES que quedan.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Puede que hasta consigas derrotar\n"
	.string "a los 4 ENTRENADORES que quedan.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Puede que hasta consigas derrotar\n"
	.string "a los 3 ENTRENADORES que quedan.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Puede que hasta consigas derrotar\n"
	.string "a los 2 ENTRENADORES que quedan.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Puede que hasta consigas derrotar\n"
	.string "al ENTRENADOR que queda.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Eres mucho para nosotros.\p"
	.string "En este nivel ya no queda ningún\n"
	.string "ENTRENADOR para enfrentarse a ti.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "¿Serás capaz de vencer a los 7\n"
	.string "ENTRENADORES que quedan?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "¿Serás capaz de vencer a los 6\n"
	.string "ENTRENADORES que quedan?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "¿Serás capaz de vencer a los 5\n"
	.string "ENTRENADORES que quedan?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "¿Serás capaz de vencer a los 4\n"
	.string "ENTRENADORES que quedan?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "¿Serás capaz de vencer a los 3\n"
	.string "ENTRENADORES que quedan?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "¿Serás capaz de vencer a los 2\n"
	.string "ENTRENADORES que quedan?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "¿Serás capaz de vencer al último\n"
	.string "ENTRENADOR que queda?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Ya no queda ni un solo ENTRENADOR\n"
	.string "que pueda retarte…$"
