BattleFrontier_BattlePyramidTop_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidTop_OnResume_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidTop_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidTop_OnTransition_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePyramidTop_OnWarp_hns
	.byte 0

BattleFrontier_BattlePyramidTop_OnTransition_hns:
	pyramid_updatelight 200, PYRAMID_LIGHT_SET_RADIUS
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidTop_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects_hns
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto_if_ne VAR_TEMP_C, 0, BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects_hns
	setobjectxyperm LOCALID_BRANDON, 0, 0
BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects_hns::
	end

BattleFrontier_BattlePyramidTop_OnResume_hns:
	frontier_getbrainstatus
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus_hns
	call BattleFrontier_EventScript_SetBrainObjectGfx
BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus_hns::
	copyvar VAR_TEMP_C, VAR_RESULT
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge_hns
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hns
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge_hns
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	end

BattleFrontier_BattlePyramidTop_OnFrame_hns:
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic_hns
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidTop_EventScript_ShowMapName_hns
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic_hns::
	playbgm MUS_B_PYRAMID_TOP, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidTop_EventScript_ShowMapName_hns::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge_hns::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidTop_EventScript_Attendant_hns::
	lock
	faceplayer
	goto_if_ne VAR_TEMP_D, 0, BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady_hns
	goto_if_ne VAR_TEMP_C, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside_hns
	msgbox BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside_hns
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop_hns
	waitmovement 0
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath_hns
	waitmovement 0
	message BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid_hns
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	closemessage
BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY_HNS, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady_hns::
	msgbox BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady_hns, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside_hns::
	msgbox BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere_hns, MSGBOX_DEFAULT
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside_hns
	setvar VAR_TEMP_D, 1
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon_hns::
	lockall
	switch VAR_TEMP_C
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold_hns
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech_hns
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech_hns
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech_hns
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure_hns, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon_hnsSilver_hns
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech_hns::
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer_hns
	waitmovement 0
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon_hnsSilver_hns::
	msgbox BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle_hns
	playbgm MUS_B_PYRAMID_TOP, FALSE
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver_hns
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns

BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver_hns::
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon_hns
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease_hns, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol_hns
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon_hns

BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold_hns::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech_hns
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned_hns, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer_hns
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon_hnsGold_hns
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech_hns::
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer_hns
	waitmovement 0
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon_hnsGold_hns::
	msgbox BattleFrontier_BattlePyramidTop_Text_EverythingYouHave_hns, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle_hns
	playbgm MUS_B_PYRAMID_TOP, FALSE
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold_hns
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns

BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold_hns::
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon_hns
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis_hns, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine_hns
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePyramidTop_Text_FarewellForNow_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon_hns

BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle_hns::
	closemessage
	dofacilitytrainerbattle FACILITY_BATTLE_PYRAMID
	waitstate
	return

BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside_hns:
	walk_right
	walk_in_place_faster_left
	step_end

BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath_hns:
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer_hns:
	walk_fast_down
	step_end

BattleFrontier_BattlePyramidTop_Movement_CameraPanUp_hns:
	walk_slow_up
	walk_slow_up
	delay_16
	step_end

BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo_hns:
	.string "¡Qué alegría verte llegar hasta aquí!\n"
	.string "¡Has conquistado la cima\l"
	.string "de la PIRÁMIDE BATALLA!\p"
	.string "Arriba está el mirador de la pirámide.\p"
	.string "Es un lugar reservado sólo a aquellos\n"
	.string "que han llegado a lo más alto.\p"
	.string "¡Ve, pues!\n"
	.string "¡Hasta lo más alto!$"

BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid_hns:
	.string "¡{PLAYER} ha conquistado la PIRÁMIDE!\n"
	.string "¡Que los vientos aclamen su nombre!$"

BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere_hns:
	.string "¡Qué alegría verte llegar hasta aquí!\p"
	.string "¡Pero qué pena que hayas llegado\n"
	.string "en segundo lugar!\p"
	.string "Nuestro jefe ha llegado a la cima\n"
	.string "de la PIRÁMIDE antes que tú.\p"
	.string "Con todo…, ¡reconozco tu valentía!\p"
	.string "¡En tus manos está ahora conquistar\n"
	.string "la fama y arrebatársela a nuestro jefe!\p"
	.string "Bueno, cuando te sientas con fuerzas,\n"
	.string "¡sube el último escalón hacia la gloria!$"

BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure_hns:
	.string "Tú, que te aventuras en lo desconocido…\p"
	.string "¿Verdad que las expediciones son las\n"
	.string "más grandiosas de todas las aventuras?\p"
	.string "¡Tu propia inteligencia!\p"
	.string "¡Tu propia fuerza!\p"
	.string "¡Tus propios POKéMON!\p"
	.string "Y, sobre todo, tu propia valentía te ha\n"
	.string "sabido llevar por mundos desconocidos…$"

BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon_hns:
	.string "¡Ah, realmente esta vida es grandiosa!\n"
	.string "Grandiosa, ¿no te parece? ¿Eh?\p"
	.string "¡Yo soy VALENTE!\p"
	.string "Soy el REY de la PIRÁMIDE, o sea,\n"
	.string "que soy el que manda aquí.\p"
	.string "La mayoría me llama simplemente\n"
	.string "“jefe”.\p"
	.string "El que hayas llegado hasta aquí\n"
	.string "significa que confías en ti, ¿verdad?\p"
	.string "¡Ja, ja, ja, ja!\n"
	.string "¡Esto promete!$"

BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle_hns:
	.string "¡Adelante, pues!\n"
	.string "¡Veamos si tienes suficiente valentía!$"

BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease_hns:
	.string "VALENTE: ¡Ja, ja, ja! ¡Grandioso!\n"
	.string "¡Tu valentía es realmente grandiosa!\p"
	.string "¡Te has ganado mi reconocimiento!\n"
	.string "¡Tu PASE del FRENTE, por favor!$"

BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol_hns:
	.string "¡El SÍMBOLO de la VALENTÍA ha sido\n"
	.string "grabado en el PASE del FRENTE!$"

BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting_hns:
	.string "¡Ya estoy deseando\n"
	.string "que nos volvamos a ver!$"

BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned_hns:
	.string "VALENTE: Por fin has vuelto…\p"
	.string "Parece que sientes un profundo amor\n"
	.string "por la aventura…\p"
	.string "Sí… Te veo, y me veo a mí\n"
	.string "cuando sólo era un chaval…\p"
	.string "Ah…\p"
	.string "¡La pasión!\p"
	.string "¡El peligro!\p"
	.string "¡La impaciencia!\p"
	.string "¡Aquellos días en que no temía a nada\n"
	.string "ni a nadie!… ¡Tú me los has devuelto!$"

BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter_hns:
	.string "¡Venga, adelante!\p"
	.string "¡Me siento más valiente que nunca!$"

BattleFrontier_BattlePyramidTop_Text_EverythingYouHave_hns:
	.string "¡Lucha con todas tus fuerzas!\n"
	.string "¡Estoy preparado para todo!$"

BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis_hns:
	.string "VALENTE: ¡Ja, ja, ja, ja! ¡Excelente!\n"
	.string "¡Grandioso, realmente grandioso!\p"
	.string "¡Qué espíritu aventurero!\p"
	.string "¡Me has superado en todo!\n"
	.string "¡Toma! ¡Te lo mereces!$"

BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine_hns:
	.string "¡El SÍMBOLO de la VALENTÍA\n"
	.string "ha adquirido un brillo dorado!$"

BattleFrontier_BattlePyramidTop_Text_FarewellForNow_hns:
	.string "¡Ah, sí! ¡Esto me sirve para ver\n"
	.string "que aún tengo mucho que aprender!\p"
	.string "¡Ojalá vuelvan a cruzarse nuestros\n"
	.string "caminos! ¡Hasta la vista, pues!$"

BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady_hns:
	.string "Cuando tu mente esté preparada, \n"
	.string "que tu cuerpo dé un paso al frente.$"

