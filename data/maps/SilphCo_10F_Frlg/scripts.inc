SilphCo_10F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_10F_OnLoad
	.byte 0

SilphCo_10F_OnLoad::
	call_if_unset FLAG_SILPH_10F_DOOR, EventScript_Close10FDoor
	end

SilphCo_10F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_10F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_10F_Text_WaaaImScared
	release
	end

SilphCo_10F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_10F_Text_KeepMeCryingASecret
	release
	end

SilphCo_10F_EventScript_FloorSign::
	msgbox SilphCo_10F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_10F_EventScript_Travis::
	trainerbattle_single TRAINER_SCIENTIST_TRAVIS, SilphCo_10F_Text_TravisIntro, SilphCo_10F_Text_TravisDefeat
	msgbox SilphCo_10F_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_39, SilphCo_10F_Text_GruntIntro, SilphCo_10F_Text_GruntDefeat
	msgbox SilphCo_10F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_Text_GruntIntro::
	.string "¡Hola, éste es el noveno piso!\n"
	.string "¡Me alegra que hayas venido!$"

SilphCo_10F_Text_GruntDefeat::
	.string "¡Estoy aturdido!$"

SilphCo_10F_Text_GruntPostBattle::
	.string "¡Bien hecho, pero la sala del\n"
	.string "consejo está un piso más arriba!$"

SilphCo_10F_Text_TravisIntro::
	.string "¡Ya está bien de tonterías!$"

SilphCo_10F_Text_TravisDefeat::
	.string "¡No quedan continuaciones!$"

SilphCo_10F_Text_TravisPostBattle::
	.string "¿Te alegra haberme ganado?\n"
	.string "¡Pues vete a casa!$"

SilphCo_10F_Text_WaaaImScared::
	.string "¡Buaaaa!\n"
	.string "¡Tengo miedo!$"

SilphCo_10F_Text_KeepMeCryingASecret::
	.string "¡Por favor, no le digas a nadie\n"
	.string "que he llorado!$"

SilphCo_10F_Text_FloorSign::
	.string "OFICINA CENTRAL DE SILPH S.A.\n"
	.string "P9$"

