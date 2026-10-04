SilphCo_9F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_9F_OnLoad
	.byte 0

SilphCo_9F_OnLoad::
	call_if_unset FLAG_SILPH_9F_DOOR_1, EventScript_Close9FDoor1
	call_if_unset FLAG_SILPH_9F_DOOR_2, EventScript_Close9FDoor2
	call_if_unset FLAG_SILPH_9F_DOOR_3, EventScript_Close9FDoor3
	call_if_unset FLAG_SILPH_9F_DOOR_4, EventScript_Close9FDoor4
	end

SilphCo_9F_EventScript_HealWoman::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_9F_EventScript_HealWomanRocketsGone
	msgbox SilphCo_9F_Text_YouShouldTakeQuickNap
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SilphCo_9F_Text_DontGiveUp
	release
	end

SilphCo_9F_EventScript_HealWomanRocketsGone::
	msgbox SilphCo_9F_Text_ThankYouSoMuch
	release
	end

SilphCo_9F_EventScript_FloorSign::
	msgbox SilphCo_9F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_9F_EventScript_Ed::
	trainerbattle_single TRAINER_SCIENTIST_ED, SilphCo_9F_Text_EdIntro, SilphCo_9F_Text_EdDefeat
	msgbox SilphCo_9F_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_37, SilphCo_9F_Text_Grunt1Intro, SilphCo_9F_Text_Grunt1Defeat
	msgbox SilphCo_9F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_38, SilphCo_9F_Text_Grunt2Intro, SilphCo_9F_Text_Grunt2Defeat
	msgbox SilphCo_9F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_Text_YouShouldTakeQuickNap::
	.string "Tienes cara de cansancio.\n"
	.string "Deberías echarte una siestecita.$"

SilphCo_9F_Text_DontGiveUp::
	.string "¡No te rindas!$"

SilphCo_9F_Text_ThankYouSoMuch::
	.string "¡Muchísimas gracias!$"

SilphCo_9F_Text_Grunt1Intro::
	.string "¡Tus POKéMON parecen adorarte,\n"
	.string "chaval!$"

SilphCo_9F_Text_Grunt1Defeat::
	.string "¡Buaah!$"

SilphCo_9F_Text_Grunt1PostBattle::
	.string "Si yo hubiera empezado como\n"
	.string "ENTRENADOR a tu edad...$"

SilphCo_9F_Text_EdIntro::
	.string "¡Tus POKéMON tienen puntos\n"
	.string "débiles! ¡Yo puedo verlos!$"

SilphCo_9F_Text_EdDefeat::
	.string "¡Me has machacado!$"

SilphCo_9F_Text_EdPostBattle::
	.string "¡Aprovechar sus puntos débiles\n"
	.string "funciona! ¡Piensa en los tipos!$"

SilphCo_9F_Text_Grunt2Intro::
	.string "¡Soy uno de los 4\n"
	.string "HERMANOS ROCKET!$"

SilphCo_9F_Text_Grunt2Defeat::
	.string "¡Hermanos!\n"
	.string "¡He perdido!$"

SilphCo_9F_Text_Grunt2PostBattle::
	.string "¡Mis hermanos me vengarán!$"

SilphCo_9F_Text_FloorSign::
	.string "OFICINA CENTRAL DE SILPH S.A.\n"
	.string "P8$"

