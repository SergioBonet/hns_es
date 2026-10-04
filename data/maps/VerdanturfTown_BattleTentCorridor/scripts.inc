VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "¿En qué CONCURSO vas a participar?\n"
	.string "¿Quieres un consejo?\p"
	.string "En cualquier CONCURSO, por ejemplo,\n"
	.string "un CONCURSO de SIMPATÍA, no creo que\l"
	.string "te juzguen solo por simpatía en la\l"
	.string "primera ronda.\p"
	.string "Tienes que buscar maneras de criar\n"
	.string "mejor a tus POKéMON.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "Crié a mi POKéMON para que fuera mono.\p"
	.string "Descubrí que se puede presentar a un\n"
	.string "POKéMON a un CONCURSO de simpatía.\p"
	.string "¡Me alegro mucho de haber criado a\n"
	.string "mi POKéMON con cariño…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "¡Mi POKéMON es el mejor!\p"
	.string "Es genial, duro pero bello, mono\n"
	.string "e inteligente. ¡Es completo!\p"
	.string "Bien podría intentar ganar en todos\n"
	.string "los CONCURSOS.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "¡CONCURSOS POKéMON\n"
	.string "ESCENARIO RANGO NORMAL!$"

