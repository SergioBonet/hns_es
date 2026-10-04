SilphCo_7F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
	.byte 0

SilphCo_7F_OnLoad::
	call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
	call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
	call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
	end

SilphCo_7F_OnTransition::
	call_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_SetObjRocketsGone
	end

SilphCo_7F_EventScript_SetObjRocketsGone::
	setobjectmovementtype LOCALID_SILPH_CO_7F_WORKER_M2, MOVEMENT_TYPE_FACE_UP
	return

SilphCo_7F_EventScript_RivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalScene::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox SilphCo_7F_Text_RivalWhatKeptYou
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalApproachTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalApproachBottom
	msgbox SilphCo_7F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_RIVAL
	call_if_eq VAR_STARTER_MON, 2, SilphCo_7F_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, SilphCo_7F_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, SilphCo_7F_EventScript_RivalCharmander
	msgbox SilphCo_7F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalExitTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalExitBottom
	playse SE_WARP_IN
	fadedefaultbgm
	removeobject LOCALID_SILPH_CO_RIVAL
	waitse
	setvar VAR_MAP_SCENE_SILPH_CO_7F, 1
	releaseall
	end

SilphCo_7F_EventScript_RivalApproachTop::
	closemessage
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalApproachTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalApproachBottom::
	return

SilphCo_7F_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_SQUIRTLE, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_BULBASAUR, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CHARMANDER, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalExitTop::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalExitBottom::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitBottom
	waitmovement 0
	return

SilphCo_7F_Movement_RivalApproachTop::
	walk_up
	step_end

SilphCo_7F_Movement_RivalExitTop::
	walk_right
	walk_right
	walk_right
	walk_up
	delay_16
	step_end

SilphCo_7F_Movement_RivalExitBottom::
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	step_end

SilphCo_7F_EventScript_LaprasGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
	msgbox SilphCo_7F_Text_HaveMonForSavingUs
	setvar VAR_TEMP_1, SPECIES_LAPRAS
	givemon SPECIES_LAPRAS, 25
	goto_if_eq VAR_RESULT, 0, SilphCo_7F_EventScript_ReceiveLaprasParty
	goto_if_eq VAR_RESULT, 1, SilphCo_7F_EventScript_ReceiveLaprasPC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

SilphCo_7F_EventScript_ReceiveLaprasParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_EndReceiveLapras
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_ReceiveLaprasPC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_LaprasTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SilphCo_7F_EventScript_LaprasTransferredToPC
	end

SilphCo_7F_EventScript_LaprasTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_EndReceiveLapras::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SilphCo_7F_Text_ExplainLapras
	setflag FLAG_GOT_LAPRAS_FROM_SILPH
	release
	end

SilphCo_7F_EventScript_AlreadyGotLapras::
	msgbox SilphCo_7F_Text_RocketBossWentToBoardroom
	release
	end

SilphCo_7F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_7F_Text_RocketsAfterMasterBall
	release
	end

SilphCo_7F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_7F_Text_CanceledMasterBallProject
	release
	end

SilphCo_7F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver
	release
	end

SilphCo_7F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket
	release
	end

SilphCo_7F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_7F_Text_ReallyDangerousHere
	release
	end

SilphCo_7F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_7F_Text_ThankYouSoMuch
	release
	end

SilphCo_7F_EventScript_FloorSign::
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_EventScript_Joshua::
	trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
	msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
	msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
	msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_Text_HaveMonForSavingUs::
	.string "¡Hola! ¡Tú no eres de los ROCKET!\n"
	.string "¿Has venido a salvarnos?\l"
	.string "¡Pues gracias!\p"
	.string "Voy a darte este POKéMON\n"
	.string "por habernos salvado.$"

SilphCo_7F_Text_ObtainedLaprasFromEmployee::
	.string "¡{PLAYER} obtuvo un LAPRAS\n"
	.string "del empleado de SILPH S.A.!$"

SilphCo_7F_Text_ExplainLapras::
	.string "Es un LAPRAS.\n"
	.string "Es muy inteligente.\p"
	.string "Lo teníamos en el laboratorio,\n"
	.string "pero estará mucho mejor contigo.\p"
	.string "Seguro que lo entrenarás muy bien.\p"
	.string "Es muy buen nadador.\n"
	.string "¡Podría llevarte incluso!$"

SilphCo_7F_Text_RocketBossWentToBoardroom::
	.string "¡El JEFE del TEAM ROCKET fue\n"
	.string "a la sala del consejo!\p"
	.string "¿Está bien el PRESIDENTE?$"

SilphCo_7F_Text_RocketsAfterMasterBall::
	.string "¡El TEAM ROCKET buscaba la MASTER\n"
	.string "BALL para poder atrapar cualquier\l"
	.string "tipo de POKéMON!$"

SilphCo_7F_Text_CanceledMasterBallProject::
	.string "Cancelamos el proyecto de la\n"
	.string "MASTER BALL por culpa del \l"
	.string "TEAM ROCKET.$"

SilphCo_7F_Text_BadIfTeamRocketTookOver::
	.string "¡Sería horrible que el TEAM\n"
	.string "ROCKET se hiciera con SILPH S.A.\l"
	.string "o con nuestros POKéMON!$"

SilphCo_7F_Text_WowYouChasedOffTeamRocket::
	.string "¡Uauu!\p"
	.string "¿Echaste tú al TEAM ROCKET?$"

SilphCo_7F_Text_ReallyDangerousHere::
	.string "¡Oye!\n"
	.string "¡Este lugar es muy peligroso!\p"
	.string "¿Has venido a salvarme?\n"
	.string "¡Pues no puedes!$"

SilphCo_7F_Text_ThankYouSoMuch::
	.string "¡Por fin a salvo! ¡Muchas gracias!$"

SilphCo_7F_Text_Grunt3Intro::
	.string "¡Oh, oh!\n"
	.string "¡Huelo a ratoncito!$"

SilphCo_7F_Text_Grunt3Defeat::
	.string "¡Luces fuera!$"

SilphCo_7F_Text_Grunt3PostBattle::
	.string "¡No encontrarás a mi JEFE con sólo\n"
	.string "merodear por ahí!$"

SilphCo_7F_Text_JoshuaIntro::
	.string "¡Ejem!\p"
	.string "¿Me confundiste con un empleado\n"
	.string "de SILPH?$"

SilphCo_7F_Text_JoshuaDefeat::
	.string "¡Estoy acabado!$"

SilphCo_7F_Text_JoshuaPostBattle::
	.string "¡A pesar de tu edad, eres genial\n"
	.string "entrenando POKéMON!$"

SilphCo_7F_Text_Grunt1Intro::
	.string "¡Soy uno de los 4 HERMANOS\n"
	.string "ROCKET!$"

SilphCo_7F_Text_Grunt1Defeat::
	.string "¡Auch!\n"
	.string "¡Hermanos, he perdido!$"

SilphCo_7F_Text_Grunt1PostBattle::
	.string "No importa. ¡Mis hermanos\n"
	.string "te devolverán el favor!$"

SilphCo_7F_Text_Grunt2Intro::
	.string "¿Que nos invaden?\n"
	.string "¿No serás tú?$"

SilphCo_7F_Text_Grunt2Defeat::
	.string "¡Vale!\n"
	.string "¡He perdido!$"

SilphCo_7F_Text_Grunt2PostBattle::
	.string "¡Vete a casa antes de que\n"
	.string "se enfade mi JEFE!$"

SilphCo_7F_Text_RivalWhatKeptYou::
	.string "{RIVAL}: ¿Qué te retrasó,\n"
	.string "{PLAYER}?$"

SilphCo_7F_Text_RivalIntro::
	.string "{RIVAL}: ¡Jaja! ¡Sabía que\n"
	.string "aparecerías si esperaba aquí!\p"
	.string "¡Supongo que el TEAM ROCKET\n"
	.string "te retrasó!\l"
	.string "¡Aunque no es que me importe!\p"
	.string "¡Te vi en CIUDAD AZAFRÁN, y\n"
	.string "decidí esperar a ver si mejorabas!$"

SilphCo_7F_Text_RivalDefeat::
	.string "¡Ajá! Así que ya estás para\n"
	.string "luchar contra el JEFE ROCKET...$"

SilphCo_7F_Text_RivalPostBattle::
	.string "¡Bien, {PLAYER}!\n"
	.string "¡Sigo mejorando y avanzando!\p"
	.string "¡Consultando mi POKéDEX puedo ver\n"
	.string "cuáles son los más fuertes y\l"
	.string "cómo evolucionan!\p"
	.string "¿Soy un genio o qué?\p"
	.string "Voy a la LIGA POKéMON a echar\n"
	.string "al ALTO MANDO.\p"
	.string "¡Seré el ENTRENADOR más poderoso\n"
	.string "del mundo!\p"
	.string "{PLAYER}, bueno, ¡buena suerte!\n"
	.string "¡No te agobies!\l"
	.string "¡Hasta la vista!$"

SilphCo_7F_Text_FloorSign::
	.string "OFICINA CENTRAL DE SILPH S.A.\n"
	.string "P6$"

