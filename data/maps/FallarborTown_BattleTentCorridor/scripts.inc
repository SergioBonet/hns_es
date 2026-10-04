FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
	.byte 0

FallarborTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	releaseall
	end

FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
	.string "Nos va bien en la ronda preliminar,\n"
	.string "pero nunca ganamos las exhibiciones…\p"
	.string "Quizá signifique que debo fijarme en lo\n"
	.string "que hacen los otros concursantes…$"

@ Unused
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
	.string "¡Mira! ¡Mi POKéMON ha ganado todas\n"
	.string "estas CINTAS!\p"
	.string "¿Tus POKéMON han conseguido alguna\n"
	.string "CINTA? Puedes verlas en tu POKéNAV.$"

@ Unused
FallarborTown_ContestHall_Text_CantWinEverywhere:
	.string "No puedo con los LÍDERES de GIMNASIO…\p"
	.string "No gano ningún CONCURSO…\p"
	.string "He ido de aquí para allá,\n"
	.string "y todo ha sido en vano…$"

@ Unused
FallarborTown_ContestHall_Text_SuperRankStage:
	.string "¡CONCURSOS POKéMON\n"
	.string "ESCENARIO RANGO SUPER!$"

