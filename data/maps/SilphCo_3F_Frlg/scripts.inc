SilphCo_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_3F_OnLoad
	.byte 0

SilphCo_3F_OnLoad::
	call_if_unset FLAG_SILPH_3F_DOOR_1, EventScript_Close3FDoor1
	call_if_unset FLAG_SILPH_3F_DOOR_2, EventScript_Close3FDoor2
	end

SilphCo_3F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_3F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_3F_Text_WhatAmIToDo
	release
	end

SilphCo_3F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_3F_Text_YouAndYourMonsSavedUs
	release
	end

SilphCo_3F_EventScript_FloorSign::
	msgbox SilphCo_3F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_3F_EventScript_Jose::
	trainerbattle_single TRAINER_SCIENTIST_JOSE, SilphCo_3F_Text_JoseIntro, SilphCo_3F_Text_JoseDefeat
	msgbox SilphCo_3F_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_25, SilphCo_3F_Text_GruntIntro, SilphCo_3F_Text_GruntDefeat
	msgbox SilphCo_3F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_Text_WhatAmIToDo::
	.string "Trabajo para SILPH S.A.\n"
	.string "¿Qué debería hacer?$"

SilphCo_3F_Text_YouAndYourMonsSavedUs::
	.string "¡{PLAYER}! ¡Tú y tus POKéMON\n"
	.string "nos habéis salvado!$"

SilphCo_3F_Text_GruntIntro::
	.string "¡Eh, no nos molestes más!$"

SilphCo_3F_Text_GruntDefeat::
	.string "¡Me rindo!$"

SilphCo_3F_Text_GruntPostBattle::
	.string "¿Una pista? ¡Para abrir las puertas\n"
	.string "utiliza una LLAVE MAGNÉTICA!$"

SilphCo_3F_Text_JoseIntro::
	.string "¡¡¡Apoyo más al TEAM ROCKET\n"
	.string "que a SILPH S.A.!!!$"

SilphCo_3F_Text_JoseDefeat::
	.string "¡Me has derrotado!$"

SilphCo_3F_Text_JosePostBattle::
	.string "Mmmm...\p"
	.string "¡El TEAM ROCKET me dijo que si\n"
	.string "les ayudaba, me dejarían estudiar\l"
	.string "a los POKéMON!$"

SilphCo_3F_Text_FloorSign::
	.string "OFICINA CENTRAL DE SILPH S.A.\n"
	.string "P2$"

