SproutTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_3F_OnTransition: 
	callnative SetTimeBasedEncounters
	end


SproutTower_3F_EventScript_SageJin::
	trainerbattle_single TRAINER_JIN_HNS, SproutTower_Text_SageJin_Seen, SproutTower_Text_SageJin_Beaten
	msgbox SproutTower_Text_SageJin_AfterBattle, MSGBOX_AUTOCLOSE
	end


SproutTower_3F_EventScript_SageNeal::
	trainerbattle_single TRAINER_NEAL_HNS, SproutTower_Text_SageNeal_Seen, SproutTower_Text_SageNeal_Beaten
	msgbox SproutTower_Text_SageNeal_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_SageTroy::
	trainerbattle_single TRAINER_TROY_HNS, SproutTower_Text_SageTroy_Seen, SproutTower_Text_SageTroy_Beaten
	msgbox SproutTower_Text_SageTroy_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_Painting::
	lock
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_3F_EventScript_Potion::
	finditem ITEM_POTION
	end

SproutTower_3F_EventScript_EscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

SproutTower_3F_EventScript_TriggerSceneLeft::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	delay 30
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_TriggerSceneRight::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
	waitmovement 0
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_SageLi::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LI_HNS, SproutTower_Text_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_EventScript_SageLi_Beaten::
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_Movement_Silver1:
	walk_fast_up
	walk_fast_up
	step_end

SproutTower_3F_Movement_SilverLeft:
	face_down
	delay_16
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_SilverRight:
	face_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_EscapeRope:
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

SproutTower_Text_ElderLecturesRival:
	.string "ANCIANO: Eres muy hábil entrenando\n"
	.string "POKéMON.\p"
	.string "Como te prometí, aquí tienes tu MO.\p"
	.string "Pero déjame que te diga que deberías\n"
	.string "tratar mejor a tus POKéMON.\p"
	.string "Luchas de forma muy violenta.\p"
	.string "Los POKéMON no son armas de guerra.$"

SproutTower_Text_RivalOnlyCaresStrong:
	.string "…\p"
	.string "¡Bah! Afirma ser el\p"
	.string "ANCIANO, pero es muy débil.\p"
	.string "Es evidente.\p"
	.string "Jamás perdería ante quienes dicen\n"
	.string "que hay que ser bueno con los\l"
	.string "POKéMON.\p"
	.string "Sólo me interesan los POKéMON\n"
	.string "ganadores.\p"
	.string "Paso de los POKéMON débiles.$"

SproutTower_Text_RivalUsedEscapeRope:
	.string "¡{RIVAL} usó CUERDA HUIDA!$"

SproutTower_Text_SageLi_Seen:
	.string "¡Encantado de verte por aquí!\p"
	.string "TORRE BELLSPROUT es un lugar de\n"
	.string "entrenamiento.\p"
	.string "La gente y los POKéMON evalúan sus\n"
	.string "vínculos para construir juntos un\l"
	.string "futuro mejor.\p"
	.string "Yo soy la prueba final.\p"
	.string "¡Déjame evaluar tus vínculos con los\n"
	.string "POKéMON!$"

SproutTower_Text_SageLi_Beaten:
	.string "¡Ah, excelente!$"

SproutTower_Text_SageLi_TakeFlash:
	.string "Tú y tus POKéMON no deberíais tener\n"
	.string "problemas con este movimiento.\p"
	.string "Toma esta MO. Es DESTELLO.$"

SproutTower_Text_SageLi_FlashExplain:
	.string "DESTELLO ilumina hasta el lugar más\n"
	.string "oscuro.\p"
	.string "Y, con la MEDALLA de CIUDAD MALVA,\n"
	.string "podrás usarlo fuera del combate.$"

SproutTower_Text_SageLi_AfterBattle:
	.string "¡Ojalá aprendas y madures con tu\n"
	.string "viaje!$"

SproutTower_Text_SageJin_Seen:
	.string "¡Me entreno para saberlo todo sobre\n"
	.string "los POKéMON!$"

SproutTower_Text_SageJin_Beaten:
	.string "Mi entrenamiento es incompleto…$"

SproutTower_Text_SageJin_AfterBattle:
	.string "Cuanto más fuerte sea el POKéMON, más\n"
	.string "fuerte será su entrenador.\p"
	.string "No, espera. Cuanto más fuerte sea el\n"
	.string "entrenador, más fuerte el POKéMON.$"

SproutTower_Text_SageTroy_Seen:
	.string "A ver cuánto confías en tus POKéMON.$"

SproutTower_Text_SageTroy_Beaten:
	.string "¡Sí, tu confianza es auténtica!$"

SproutTower_Text_SageTroy_AfterBattle:
	.string "No estás lejos del ANCIANO.$"

SproutTower_Text_SageNeal_Seen:
	.string "La MO del ANCIANO ilumina incluso la\n"
	.string "oscuridad más absoluta.$"

SproutTower_Text_SageNeal_Beaten:
	.string "¡Mi cerebro sí que es brillante!$"

SproutTower_Text_SageNeal_AfterBattle:
	.string "¡Que haya luz en tus viajes!$"

SproutTower_Text_3F_Painting:
	.string "Es un bonito cuadro de un BELLSPROUT.$"
