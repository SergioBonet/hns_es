BattleFrontier_BattlePalaceCorridor_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceCorridor_OnFrame_hns
	.byte 0

BattleFrontier_BattlePalaceCorridor_OnFrame_hns:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor_hns
	.2byte 0

BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor_hns::
	delay 16
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor_hns
	waitmovement 0
	lockall
	palace_getcomment
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1_hns
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2_hns
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3_hns
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment_hns
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment_hns
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	goto_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom_hns
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom_hns
	waitmovement 0
	opendoor 6, 3
	waitdooranim
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom_hns
	waitmovement 0
	closedoor 6, 3
	waitdooranim
	goto BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom_hns

BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom_hns::
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom_hns
	waitmovement 0
	opendoor 10, 3
	waitdooranim
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom_hns
	waitmovement 0
	closedoor 10, 3
	waitdooranim
BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom_hns::
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM_HNS, 7, 4
	waitstate
	end

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1_hns::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2_hns::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3_hns::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment_hns::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment_hns::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom_hns:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom_hns:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom_hns:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom_hns:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom_hns:
	walk_up
BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame_hns:
	.string "Los POKéMON no son tan distintos\n"
	.string "de la gente…\p"
	.string "Su naturaleza hace que sean buenos\n"
	.string "para ciertas cosas, y no tan buenos\l"
	.string "para otras.$"

BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes_hns:
	.string "En lugar de obligar a un POKéMON\n"
	.string "a hacer algo que no le gusta, deja que\l"
	.string "haga lo que le gusta y se le da mejor.\p"
	.string "Ponte en el lugar del POKéMON y piensa\n"
	.string "qué movimiento le gustaría usar.$"

BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered_hns:
	.string "La naturaleza de un POKéMON es algo \n"
	.string "verdaderamente extraordinario…\p"
	.string "Los POKéMON reaccionan de forma\n"
	.string "muy distinta cuando se ven acorralados.$"

BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature_hns:
	.string "¿Empiezas a comprender cómo influye\n"
	.string "la naturaleza de un POKéMON\l"
	.string "en su comportamiento?$"

BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons_hns:
	.string "Ah… Noto un vínculo tremendamente\n"
	.string "fuerte entre tus POKéMON y tú…$"

