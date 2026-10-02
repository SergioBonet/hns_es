BattleFrontier_BattlePyramidFloor_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition_hns
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame_hns:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hns
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic_hns
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName_hns
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hns::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hnsLoop_hns::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight_hnsLoop_hns
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName_hns::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic_hns::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume_hns:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge_hns
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hns
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge_hns
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty_hns::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hns::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY_HNS, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge_hns::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition_hns:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius_hns
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius_hns::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor_hns::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop_hns
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR_HNS, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop_hns::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP_HNS, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle_hns::
	facilitytrainerbattle FACILITY_BATTLE_PYRAMID
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall_hns::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBall_hnsEnd_hns
	pyramid_hideitem
BattlePyramid_FindItemBall_hnsEnd_hns::
	end

BattlePyramid_Retire_hns::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobby_hnsLost_hns

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText_hns:
	.string "This is a sample message.$"

gText_BattlePyramidConfirmRest_hns::
	.string "Tu expedición de la PIRÁMIDE BATALLA\n"
	.string "se guardará para que puedas tomarte\l"
	.string "un descanso. ¿Estás de acuerdo?$"

gText_BattlePyramidConfirmRetire_hns::
	.string "Are you sure you want to quit your\n"
	.string "PYRAMID quest?$"

BattlePyramid_Text_ExitHintUp1_hns::
	.string "La salida de este nivel está\n"
	.string "en esa dirección: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft1_hns::
	.string "La salida de este nivel está\n"
	.string "en esa dirección: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight1_hns::
	.string "La salida de este nivel está\n"
	.string "en esa dirección: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown1_hns::
	.string "La salida de este nivel está\n"
	.string "en esa dirección: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp2_hns::
	.string "Creo que la salida de este nivel\n"
	.string "está por ahí: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2_hns::
	.string "Creo que la salida de este nivel\n"
	.string "está por ahí: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2_hns::
	.string "Creo que la salida de este nivel\n"
	.string "está por ahí: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2_hns::
	.string "Creo que la salida de este nivel\n"
	.string "está por ahí: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3_hns::
	.string "The exit is over\n"
	.string "that {UP_ARROW} way.$"

BattlePyramid_Text_ExitHintLeft3_hns::
	.string "The exit is over\n"
	.string "that {LEFT_ARROW} way.$"

BattlePyramid_Text_ExitHintRight3_hns::
	.string "The exit is over\n"
	.string "that {RIGHT_ARROW} way.$"

BattlePyramid_Text_ExitHintDown3_hns::
	.string "The exit is over\n"
	.string "that {DOWN_ARROW} way.$"

BattlePyramid_Text_ExitHintUp4_hns::
	.string "En este nivel, la salida está\n"
	.string "en esa dirección: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4_hns::
	.string "En este nivel, la salida está\n"
	.string "en esa dirección: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4_hns::
	.string "En este nivel, la salida está\n"
	.string "en esa dirección: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4_hns::
	.string "En este nivel, la salida está\n"
	.string "en esa dirección: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5_hns::
	.string "¿La salida, dices?\n"
	.string "Por ahí: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft5_hns::
	.string "¿La salida, dices?\n"
	.string "Por ahí: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight5_hns::
	.string "¿La salida, dices?\n"
	.string "Por ahí: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown5_hns::
	.string "¿La salida, dices?\n"
	.string "Por ahí: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp6_hns::
	.string "La salida resulta que está \n"
	.string "en la dirección: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6_hns::
	.string "La salida resulta que está \n"
	.string "en la dirección: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6_hns::
	.string "La salida resulta que está \n"
	.string "en la dirección: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6_hns::
	.string "La salida resulta que está \n"
	.string "en la dirección: {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1_hns::
	.string "Are you looking for items?\p"
	.string "There are eight items left to\n"
	.string "be found.$"

BattlePyramid_Text_SevenItemsRemaining1_hns::
	.string "Are you looking for items?\p"
	.string "There are seven items left to\n"
	.string "be found.$"

BattlePyramid_Text_SixItemsRemaining1_hns::
	.string "Are you looking for items?\p"
	.string "There are six items left to\n"
	.string "be found.$"

BattlePyramid_Text_FiveItemsRemaining1_hns::
	.string "Are you looking for items?\p"
	.string "There are five items left to\n"
	.string "be found.$"

BattlePyramid_Text_FourItemsRemaining1_hns::
	.string "Are you looking for items?\p"
	.string "There are four items left to\n"
	.string "be found.$"

BattlePyramid_Text_ThreeItemsRemaining1_hns::
	.string "Are you looking for items?\p"
	.string "There are three items left to\n"
	.string "be found.$"

BattlePyramid_Text_TwoItemsRemaining1_hns::
	.string "Are you looking for items?\p"
	.string "There are two items left to\n"
	.string "be found.$"

BattlePyramid_Text_OneItemRemaining1_hns::
	.string "Are you looking for items?\p"
	.string "There is one item left to\n"
	.string "be found.$"

BattlePyramid_Text_ZeroItemsRemaining1_hns::
	.string "Are you looking for items?\p"
	.string "There isn't anything left to\n"
	.string "be found!$"

BattlePyramid_Text_EightItemsRemaining2_hns::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are eight items\n"
	.string "lying around here.$"

BattlePyramid_Text_SevenItemsRemaining2_hns::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are seven items left\n"
	.string "lying around here.$"

BattlePyramid_Text_SixItemsRemaining2_hns::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are six items left\n"
	.string "lying around here.$"

BattlePyramid_Text_FiveItemsRemaining2_hns::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are five items left\n"
	.string "lying around here.$"

BattlePyramid_Text_FourItemsRemaining2_hns::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are four items left\n"
	.string "lying around here.$"

BattlePyramid_Text_ThreeItemsRemaining2_hns::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are three items left\n"
	.string "lying around here.$"

BattlePyramid_Text_TwoItemsRemaining2_hns::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are two items left\n"
	.string "lying around here.$"

BattlePyramid_Text_OneItemRemaining2_hns::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There is just one item\n"
	.string "lying around here.$"

BattlePyramid_Text_ZeroItemsRemaining2_hns::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There isn't anything left\n"
	.string "lying around here.$"

BattlePyramid_Text_EightItemsRemaining3_hns::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are eight items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_SevenItemsRemaining3_hns::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are seven items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_SixItemsRemaining3_hns::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are six items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_FiveItemsRemaining3_hns::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are five items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_FourItemsRemaining3_hns::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are four items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_ThreeItemsRemaining3_hns::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are three items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_TwoItemsRemaining3_hns::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are two items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_OneItemRemaining3_hns::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there's but one item left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_ZeroItemsRemaining3_hns::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are no more items\n"
	.string "waiting to be found on this floor.\l"
	.string "You take care now!$"

BattlePyramid_Text_EightItemsRemaining4_hns::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be eight more\n"
	.string "items on the ground.$"

BattlePyramid_Text_SevenItemsRemaining4_hns::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be seven more\n"
	.string "items on the ground.$"

BattlePyramid_Text_SixItemsRemaining4_hns::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be six more\n"
	.string "items on the ground.$"

BattlePyramid_Text_FiveItemsRemaining4_hns::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be five more\n"
	.string "items on the ground.$"

BattlePyramid_Text_FourItemsRemaining4_hns::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be four more\n"
	.string "items on the ground.$"

BattlePyramid_Text_ThreeItemsRemaining4_hns::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be three more\n"
	.string "items on the ground.$"

BattlePyramid_Text_TwoItemsRemaining4_hns::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be two more\n"
	.string "items on the ground.$"

BattlePyramid_Text_OneItemRemaining4_hns::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appears to be only one more\n"
	.string "item on the ground.$"

BattlePyramid_Text_ZeroItemsRemaining4_hns::
	.string "¡Te mereces una pequeña ayudita\n"
	.string "por haberme ganado!\p"
	.string "Ahí va: ¡ya no quedan más objetos\n"
	.string "en este nivel!$"

BattlePyramid_Text_EightItemsRemaining5_hns::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 8 objetos…$"

BattlePyramid_Text_SevenItemsRemaining5_hns::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 7 objetos…$"

BattlePyramid_Text_SixItemsRemaining5_hns::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 6 objetos…$"

BattlePyramid_Text_FiveItemsRemaining5_hns::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 5 objetos…$"

BattlePyramid_Text_FourItemsRemaining5_hns::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 4 objetos…$"

BattlePyramid_Text_ThreeItemsRemaining5_hns::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 3 objetos…$"

BattlePyramid_Text_TwoItemsRemaining5_hns::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 2 objetos…$"

BattlePyramid_Text_OneItemRemaining5_hns::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "hay 1 objeto…$"

BattlePyramid_Text_ZeroItemsRemaining5_hns::
	.string "Dicen que en este nivel de la PIRÁMIDE,\n"
	.string "no quedan objetos…$"

BattlePyramid_Text_EightItemsRemaining6_hns::
	.string "Have you collected any items?\p"
	.string "I believe there are eight more\n"
	.string "items on this floor.$"

BattlePyramid_Text_SevenItemsRemaining6_hns::
	.string "Have you collected any items?\p"
	.string "I believe there are seven more\n"
	.string "items on this floor.$"

BattlePyramid_Text_SixItemsRemaining6_hns::
	.string "Have you collected any items?\p"
	.string "I believe there are six more\n"
	.string "items on this floor.$"

BattlePyramid_Text_FiveItemsRemaining6_hns::
	.string "Have you collected any items?\p"
	.string "I believe there are five more\n"
	.string "items on this floor.$"

BattlePyramid_Text_FourItemsRemaining6_hns::
	.string "Have you collected any items?\p"
	.string "I believe there are four more\n"
	.string "items on this floor.$"

BattlePyramid_Text_ThreeItemsRemaining6_hns::
	.string "Have you collected any items?\p"
	.string "I believe there are three more\n"
	.string "items on this floor.$"

BattlePyramid_Text_TwoItemsRemaining6_hns::
	.string "Have you collected any items?\p"
	.string "I believe there are two more\n"
	.string "items on this floor.$"

BattlePyramid_Text_OneItemRemaining6_hns::
	.string "Have you collected any items?\p"
	.string "I believe there is one more\n"
	.string "item on this floor.$"

BattlePyramid_Text_ZeroItemsRemaining6_hns::
	.string "Have you collected any items?\p"
	.string "I believe there are no more\n"
	.string "items on this floor.$"

BattlePyramid_Text_SevenTrainersRemaining1_hns::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te quedan otros 7\n"
	.string "ENTRENADORES aparte de mí!$"

BattlePyramid_Text_SixTrainersRemaining1_hns::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te quedan otros 6\n"
	.string "ENTRENADORES aparte de mí!$"

BattlePyramid_Text_FiveTrainersRemaining1_hns::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te quedan otros 5\n"
	.string "ENTRENADORES aparte de mí!$"

BattlePyramid_Text_FourTrainersRemaining1_hns::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te quedan otros 4\n"
	.string "ENTRENADORES aparte de mí!$"

BattlePyramid_Text_ThreeTrainersRemaining1_hns::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te quedan otros 3\n"
	.string "ENTRENADORES aparte de mí!$"

BattlePyramid_Text_TwoTrainersRemaining1_hns::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te quedan otros 2\n"
	.string "ENTRENADORES aparte de mí!$"

BattlePyramid_Text_OneTrainersRemaining1_hns::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Pero aún te queda otro\n"
	.string "ENTRENADOR aparte de mí!$"

BattlePyramid_Text_ZeroTrainersRemaining1_hns::
	.string "¡Sabes combatir, de eso no hay duda!\p"
	.string "¡Ya no te queda ningún\n"
	.string "ENTRENADOR por batir!$"

BattlePyramid_Text_SevenTrainersRemaining2_hns::
	.string "This is so upsetting!\p"
	.string "But there are seven TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_SixTrainersRemaining2_hns::
	.string "This is so upsetting!\p"
	.string "But there are six TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_FiveTrainersRemaining2_hns::
	.string "This is so upsetting!\p"
	.string "But there are five TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_FourTrainersRemaining2_hns::
	.string "This is so upsetting!\p"
	.string "But there are four TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_ThreeTrainersRemaining2_hns::
	.string "This is so upsetting!\p"
	.string "But there are three TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_TwoTrainersRemaining2_hns::
	.string "This is so upsetting!\p"
	.string "But there are two TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_OneTrainersRemaining2_hns::
	.string "This is so upsetting!\p"
	.string "But there's one TRAINER left!\n"
	.string "I'm sure you will be humbled!$"

BattlePyramid_Text_ZeroTrainersRemaining2_hns::
	.string "This is so upsetting!\p"
	.string "But there are no more TRAINERS\n"
	.string "who can engage you!$"

BattlePyramid_Text_SevenTrainersRemaining3_hns::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te quedan 7 ENTRENADORES\n"
	.string "más en este nivel. ¿Podrás con todos?$"

BattlePyramid_Text_SixTrainersRemaining3_hns::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te quedan 6 ENTRENADORES\n"
	.string "más en este nivel. ¿Podrás con todos?$"

BattlePyramid_Text_FiveTrainersRemaining3_hns::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te quedan 5 ENTRENADORES\n"
	.string "más en este nivel. ¿Podrás con todos?$"

BattlePyramid_Text_FourTrainersRemaining3_hns::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te quedan 4 ENTRENADORES\n"
	.string "más en este nivel. ¿Podrás con todos?$"

BattlePyramid_Text_ThreeTrainersRemaining3_hns::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te quedan 3 ENTRENADORES\n"
	.string "más en este nivel. ¿Podrás con todos?$"

BattlePyramid_Text_TwoTrainersRemaining3_hns::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te quedan 2 ENTRENADORES\n"
	.string "más en este nivel. ¿Podrás con todos?$"

BattlePyramid_Text_OneTrainersRemaining3_hns::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "Todavía te queda 1 ENTRENADOR\n"
	.string "más en este nivel. ¿Cómo lo ves?$"

BattlePyramid_Text_ZeroTrainersRemaining3_hns::
	.string "¡Me has dejado con la boca abierta!\p"
	.string "¡Has acabado uno a uno con todos\n"
	.string "los ENTRENADORES de este nivel!$"

BattlePyramid_Text_SevenTrainersRemaining4_hns::
	.string "Dudo que puedas derrotar a los 7\n"
	.string "ENTRENADORES que quedan en este nivel.$"

BattlePyramid_Text_SixTrainersRemaining4_hns::
	.string "Dudo que puedas derrotar a los 6\n"
	.string "ENTRENADORES que quedan en este nivel.$"

BattlePyramid_Text_FiveTrainersRemaining4_hns::
	.string "Dudo que puedas derrotar a los 5\n"
	.string "ENTRENADORES que quedan en este nivel.$"

BattlePyramid_Text_FourTrainersRemaining4_hns::
	.string "Dudo que puedas derrotar a los 4\n"
	.string "ENTRENADORES que quedan en este nivel.$"

BattlePyramid_Text_ThreeTrainersRemaining4_hns::
	.string "Dudo que puedas derrotar a los 3\n"
	.string "ENTRENADORES que quedan en este nivel.$"

BattlePyramid_Text_TwoTrainersRemaining4_hns::
	.string "Dudo que puedas derrotar a los 2\n"
	.string "ENTRENADORES que quedan en este nivel.$"

BattlePyramid_Text_OneTrainersRemaining4_hns::
	.string "Dudo que puedas derrotar al\n"
	.string "ENTRENADOR que queda en este nivel.$"

BattlePyramid_Text_ZeroTrainersRemaining4_hns::
	.string "Bueno, ya no te queda nadie\n"
	.string "por vencer en este nivel…$"

BattlePyramid_Text_SevenTrainersRemaining5_hns::
	.string "Puede que hasta consigas derrotar\n"
	.string "a los 7 ENTRENADORES que quedan.$"

BattlePyramid_Text_SixTrainersRemaining5_hns::
	.string "Puede que hasta consigas derrotar\n"
	.string "a los 6 ENTRENADORES que quedan.$"

BattlePyramid_Text_FiveTrainersRemaining5_hns::
	.string "Puede que hasta consigas derrotar\n"
	.string "a los 5 ENTRENADORES que quedan.$"

BattlePyramid_Text_FourTrainersRemaining5_hns::
	.string "Puede que hasta consigas derrotar\n"
	.string "a los 4 ENTRENADORES que quedan.$"

BattlePyramid_Text_ThreeTrainersRemaining5_hns::
	.string "Puede que hasta consigas derrotar\n"
	.string "a los 3 ENTRENADORES que quedan.$"

BattlePyramid_Text_TwoTrainersRemaining5_hns::
	.string "Puede que hasta consigas derrotar\n"
	.string "a los 2 ENTRENADORES que quedan.$"

BattlePyramid_Text_OneTrainersRemaining5_hns::
	.string "Puede que hasta consigas derrotar\n"
	.string "al ENTRENADOR que queda.$"

BattlePyramid_Text_ZeroTrainersRemaining5_hns::
	.string "Eres mucho para nosotros.\p"
	.string "En este nivel ya no queda ningún\n"
	.string "ENTRENADOR para enfrentarse a ti.$"

BattlePyramid_Text_SevenTrainersRemaining6_hns::
	.string "¿Serás capaz de vencer a los 7\n"
	.string "ENTRENADORES que quedan?$"

BattlePyramid_Text_SixTrainersRemaining6_hns::
	.string "¿Serás capaz de vencer a los 6\n"
	.string "ENTRENADORES que quedan?$"

BattlePyramid_Text_FiveTrainersRemaining6_hns::
	.string "¿Serás capaz de vencer a los 5\n"
	.string "ENTRENADORES que quedan?$"

BattlePyramid_Text_FourTrainersRemaining6_hns::
	.string "¿Serás capaz de vencer a los 4\n"
	.string "ENTRENADORES que quedan?$"

BattlePyramid_Text_ThreeTrainersRemaining6_hns::
	.string "¿Serás capaz de vencer a los 3\n"
	.string "ENTRENADORES que quedan?$"

BattlePyramid_Text_TwoTrainersRemaining6_hns::
	.string "¿Serás capaz de vencer a los 2\n"
	.string "ENTRENADORES que quedan?$"

BattlePyramid_Text_OneTrainersRemaining6_hns::
	.string "¿Serás capaz de vencer al último\n"
	.string "ENTRENADOR que queda?$"

BattlePyramid_Text_ZeroTrainersRemaining6_hns::
	.string "Ya no queda ni un solo ENTRENADOR\n"
	.string "que pueda retarte…$"
