IlexForest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IlexForest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

IlexForest_OnTransition: 
	call_if_eq VAR_ILEX_FOREST_FARFETCHD, 1, IlexForest_EventScript_ReenterWhenFarfetchdLeaving
	call_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_ReenterDuringCutScene
	callnative SetTimeBasedEncounters
	end	

IlexForest_EventScript_ReenterWhenFarfetchdLeaving::
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 33, 51
	return

IlexForest_EventScript_ReenterDuringCutScene::
	clearflag FLAG_HIDE_ILEX_FOREST_MASTER
	clearflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 28, 42
	return

IlexForest_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_Apprentice2
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 3, IlexForest_EventScript_Apprentice2
	msgbox IlexForest_Text_ApprenticeIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_Apprentice2::
	msgbox IlexForest_Text_ApprenticeAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_Boss::
	lock
	faceplayer
	msgbox IlexForest_Text_CharcoalMasterTalkAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_Farfetchd_1A::
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 3, IlexForest_EventScript_Farfetchd_Done
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_Farfetchd_Done
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 1, IlexForest_EventScript_Farfetchd_Leave
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_1B
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_1A
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_1
	@add clockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	addobject LOCALID_ILEX_FOREST_FARFETCHD_2
	release
	end
IlexForest_EventScript_Farfetchd_1B::
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_1B
	waitmovement 0
	setvar VAR_ILEX_FOREST_FARFETCHD, 1
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 33, 51
	release
	end

IlexForest_EventScript_Farfetchd_2A::
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_2B
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_2, IlexForest_Movement_Farfetchd_2A
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_2
	@add clockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	addobject LOCALID_ILEX_FOREST_FARFETCHD_3
	release
	end
IlexForest_EventScript_Farfetchd_2B::
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_2, IlexForest_Movement_Farfetchd_2B
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_2
	@add counterclockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	addobject LOCALID_ILEX_FOREST_FARFETCHD_1
	release
	end

IlexForest_EventScript_Farfetchd_3A::
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_3B
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_3, IlexForest_Movement_Farfetchd_3A
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_3
	@add clockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	addobject LOCALID_ILEX_FOREST_FARFETCHD_2
	release
	end
IlexForest_EventScript_Farfetchd_3B::
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_3, IlexForest_Movement_Farfetchd_3B
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_3
	@add counterclockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
	addobject LOCALID_ILEX_FOREST_FARFETCHD_4
	release
	end

IlexForest_EventScript_Farfetchd_4A::
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_4B
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_4, IlexForest_Movement_Farfetchd_4A
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_4
	@add clockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	addobject LOCALID_ILEX_FOREST_FARFETCHD_3
	release
	end
IlexForest_EventScript_Farfetchd_4B::
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_4, IlexForest_Movement_Farfetchd_4B
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_4
	@add counterclockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	addobject LOCALID_ILEX_FOREST_FARFETCHD_1
	release
	end


IlexForest_EventScript_Farfetchd_Leave::
	goto_if_eq VAR_FACING, DIR_EAST, IlexForest_EventScript_Farfetchd_Return
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_Return
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_Leave
	waitmovement 0
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 28, 42
	setvar VAR_ILEX_FOREST_FARFETCHD, 2
	clearflag FLAG_HIDE_ILEX_FOREST_KIMONO
	clearflag FLAG_HIDE_ILEX_FOREST_MASTER
	setflag FLAG_HIDE_AZALEA_TOWN_CUT_MASTER
	addobject 1
	release
	end
IlexForest_EventScript_Farfetchd_Return::
	setvar VAR_ILEX_FOREST_FARFETCHD, 0
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_Return
	waitmovement 0
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 42, 47
	release
	end
IlexForest_EventScript_Farfetchd_Done::
	release
	end

IlexForest_EventScript_TriggerBot::
	lock
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkUp
	waitmovement 0
IlexForest_EventScript_Trigger::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox IlexForest_Text_CharcoalMasterIntro, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HM_CUT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox IlexForest_Text_CharcoalMasterOutro, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_HM_CUT
	setflag FLAG_HIDE_ILEX_FOREST_MASTER
	setflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	setvar VAR_ILEX_FOREST_FARFETCHD, 3
	setvar VAR_AZALEA_TOWN_STATE, 7
	clearflag FLAG_HIDE_AZALEA_TOWN_FARFETCHD
	clearflag FLAG_HIDE_AZALEA_TOWN_CUT_MASTER
	closemessage
	release
	end

IlexForest_EventScript_Picnicker::
	lock
	faceplayer
	msgbox IlexForest_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_BugcatcherWayne::
	trainerbattle_single TRAINER_WAYNE_HNS, IlexForest_Text_BugCatcherWayneSeen, IlexForest_Text_BugCatcherWayneBeaten
	msgbox IlexForest_Text_BugCatcherWayneAfter, MSGBOX_AUTOCLOSE
	end

IlexForest_EventScript_Shrine::
	lock
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, IlexForest_EventScript_Celebi_Event
	msgbox IlexForest_Text_Shrine, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_Celebi_Event::
	msgbox IlexForest_Text_ShrineCelebiEvent, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, IlexForest_EventScript_Shrine_Cancel
	msgbox IlexForest_Text_InsertGSBall, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_CELEBI
	addobject LOCALID_ILEX_FOREST_CELEBI
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_ILEX_FOREST_CELEBI, IlexForest_Movement_Celebi1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_ILEX_FOREST_CELEBI, IlexForest_Movement_Celebi2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_ILEX_FOREST_CELEBI, IlexForest_Movement_Celebi3
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_CELEBI, 40
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	call_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, IlexForest_EventScript_Shrine_Caught
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ILEX_FOREST_CELEBI
	setflag FLAG_HIDE_CELEBI
	special GivePartyMonNationalRibbon
	fadescreenswapbuffers FADE_FROM_BLACK
IlexForest_EventScript_Kurt::
	clearflag FLAG_HIDE_ILEX_FOREST_KURT
	addobject LOCALID_ILEX_FOREST_KURT
	applymovement LOCALID_ILEX_FOREST_KURT, IlexForest_Movement_Kurt1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox IlexForest_Text_KurtCaughtCelebi, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ILEX_FOREST_KURT, IlexForest_Movement_Kurt2
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_KURT
	removeobject LOCALID_ILEX_FOREST_KURT
	setvar VAR_AZALEA_TOWN_STATE, 10
	release
	end

IlexForest_EventScript_Shrine_Caught::
	setflag FLAG_CAUGHT_CELEBI
	return

IlexForest_EventScript_Shrine_Cancel::
	closemessage
	release
	end


IlexForest_EventScript_SecondCelebi::
	lock
	faceplayer
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_CELEBI, 40
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IlexForest_EventScript_SecondCelebiRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ILEX_FOREST_SECOND_CELEBI
	setflag FLAG_HIDE_ILEX_FOREST_SECOND_CELEBI
	fadescreenswapbuffers FADE_FROM_BLACK
	special GivePartyMonNationalRibbon
	release
	end

IlexForest_EventScript_SecondCelebiRan::
	release
	end


IlexForest_EventScript_Sign::
	lock
	msgbox IlexForest_Text_Signpost, MSGBOX_SIGN
	closemessage
	release
	end

IlexForest_EventScript_Kimono::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	playse SE_PIN
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_NORTH
	applymovement2 LOCALID_ILEX_FOREST_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ILEX_FOREST_KIMONO
	applymovement2 LOCALID_ILEX_FOREST_KIMONO, IlexForest_Movement_Kimono_Girl1
	waitmovement 0
	msgbox IlexForest_Text_Kimono_Girl1, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ILEX_FOREST_KIMONO, IlexForest_Movement_Kimono_Girl_Spin
	waitmovement 0
	turnobject LOCALID_ILEX_FOREST_KIMONO, DIR_SOUTH
	msgbox IlexForest_Text_Kimono_Girl2, MSGBOX_YESNO
	closemessage
	msgbox IlexForest_Text_Kimono_Girl3, MSGBOX_DEFAULT
	closemessage
	playfirstmoncry
	applymovement2 OBJ_EVENT_ID_FOLLOWER, IlexForest_Movement_Follower1
	waitmovement 0
	playfirstmoncry
	turnobject LOCALID_ILEX_FOREST_KIMONO, DIR_WEST
	msgbox IlexForest_Text_Kimono_Girl4, MSGBOX_DEFAULT
	closemessage 
	turnobject LOCALID_ILEX_FOREST_KIMONO, DIR_SOUTH
	delay 16
	msgbox IlexForest_Text_Kimono_Girl5, MSGBOX_DEFAULT
	closemessage
	delay 16
	playfirstmoncry
	applymovement2 OBJ_EVENT_ID_FOLLOWER, IlexForest_Movement_Follower2
	applymovement2 LOCALID_ILEX_FOREST_KIMONO, IlexForest_Movement_Kimono_Girl2
	waitmovement 0
	waitmovement 0
	fadedefaultbgm
	setvar VAR_ILEX_FOREST_FARFETCHD, 4
	setflag FLAG_HIDE_ILEX_FOREST_KIMONO
	removeobject LOCALID_ILEX_FOREST_KIMONO
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER, IlexForest_Movement_Follower3
	waitmovement 0
	playfirstmoncry
	release
	end

IlexForest_EventScript_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

IlexForest_EventScript_Ether::
	finditem ITEM_ETHER
	end

IlexForest_EventScript_FullHeal::
	finditem ITEM_FULL_HEAL
	end

IlexForest_EventScript_Item_FalseSwipe::
	finditem ITEM_TM_FALSE_SWIPE
	end

IlexForest_Movement_Kimono_Girl1:
	walk_right
	face_down
	step_end

IlexForest_Movement_Kimono_Girl_Spin:
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	step_end

IlexForest_Movement_Follower1:
	walk_left
	jump_2_up
	walk_up
	face_right
	jump_in_place_right
	delay 16
	face_left
	jump_in_place_left
	delay 16
	face_right
	step_end

IlexForest_Movement_Follower2:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

IlexForest_Movement_Kimono_Girl2:
	face_left
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

IlexForest_Movement_Follower3:
	delay 16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	jump_2_down
	walk_right
	face_up
	step_end


IlexForest_Movement_Farfetchd_1A:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
IlexForest_Movement_Farfetchd_1B:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
IlexForest_Movement_Farfetchd_2A:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
IlexForest_Movement_Farfetchd_2B:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
IlexForest_Movement_Farfetchd_3A:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
IlexForest_Movement_Farfetchd_3B:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
IlexForest_Movement_Farfetchd_4A:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
IlexForest_Movement_Farfetchd_4B:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

IlexForest_Movement_Farfetchd_Leave:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_down
	step_end
IlexForest_Movement_Farfetchd_Return:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up	
	step_end

IlexForest_Movement_Celebi1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

IlexForest_Movement_Celebi2:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

IlexForest_Movement_Celebi3:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

IlexForest_Movement_Kurt1:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

IlexForest_Movement_Kurt2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

IlexForest_Text_ApprenticeIntro:
	.string "Ay, madre… Mi jefe se va a poner hecho\n"
	.string "una furia…\p"
	.string "El FARFETCH'D que CORTA árboles para\n"
	.string "hacer carbón se me ha escapado.\p"
	.string "No puedo ir a buscarlo aquí, en el\n"
	.string "ENCINAR.\p"
	.string "Es demasiado grande, oscuro y da\n"
	.string "mucho miedo…$"

IlexForest_Text_ApprenticeAfter:
	.string "¡Uau! ¡Muchísimas gracias!\p"
	.string "El POKéMON de mi jefe no me obedece\n"
	.string "porque no tengo MEDALLA.$"

IlexForest_Text_ItsTheMissingPokemon:
	.string "¡Es el POKéMON perdido!$"

IlexForest_Text_Kwaaaa:
	.string "FARFETCH'D: ¡Farf!$"

IlexForest_Text_CharcoalMasterIntro:
	.string "¡Ah! ¡Mi FARFETCH'D!\p"
	.string "¿Lo encontraste para nosotros?\p"
	.string "Sin su ayuda, no podríamos CORTAR\p"
	.string "árboles para hacer carbón vegetal.\p"
	.string "¡Gracias!\p"
	.string "¿Cómo podría agradecértelo…?\p"
	.string "¡Ya sé! Coge esto.$"

IlexForest_Text_CharcoalMasterOutro:
	.string "Es la MO de CORTE. Enséñasela a un\n"
	.string "POKéMON para cortar arbolitos.\p"
	.string "Claro que, para usarla, necesitas la\n"
	.string "MEDALLA del GIMNASIO de PUEBLO\l"
	.string "AZALEA.$"

IlexForest_Text_CharcoalMasterTalkAfter:
	.string "¿Quieres que te enseñe mi oficio? ¡En\n"
	.string "diez años serás el mejor!$"

IlexForest_Text_Lass:
	.string "¿Le ha pasado algo al guardián del\n"
	.string "bosque?$"

IlexForest_Text_Signpost:
	.string "Hay tantos árboles en el ENCINAR que\n"
	.string "no se ve ni el cielo.\p"
	.string "Por favor, busca objetos que puedan\n"
	.string "haber caído.$"

IlexForest_Text_Shrine:
	.string "SANTUARIO DEL ENCINAR…\p"
	.string "Está dedicado al protector del\n"
	.string "bosque…$"

IlexForest_Text_ShrineCelebiEvent:
	.string "SANTUARIO DEL ENCINAR…\p"
	.string "Está dedicado al protector del\n"
	.string "bosque…\p"
	.string "¿Eh? ¿Qué es esto?\p"
	.string "Es un agujero. Parece que la GS BALL\n"
	.string "cabría dentro.\p"
	.string "¿Quieres poner la GS BALL aquí?$"

IlexForest_Text_InsertGSBall:
	.string "{PLAYER} coloca la GS BALL.$"

IlexForest_Text_KurtCaughtCelebi:
	.string "¡Uf! ¡Eso sí que ha sido increíble!\p"
	.string "{PLAYER}, ha sido fantástico. ¡Gracias!\p"
	.string "Las leyendas sobre ese SANTUARIO\n"
	.string "eran ciertas.\p"
	.string "Lo que acabo de ver me ha inspirado.\p"
	.string "¡Me motiva para hacer mejores BALLS!\p"
	.string "¡Me voy!$"

IlexForest_Text_BugCatcherWayneSeen:
	.string "¡No me des estos sustos!\p"
	.string "¡Un POKéMON ha escapado asustado!$"

IlexForest_Text_BugCatcherWayneBeaten:
	.string "No había visto nunca ese POKéMON…$"

IlexForest_Text_BugCatcherWayneAfter:
	.string "Cuando usé GOLPE CABEZA, se cayó del\n"
	.string "árbol un POKéMON que no había visto\l"
	.string "nunca.\p"
	.string "Debería usar GOLPE CABEZA en otros\n"
	.string "sitios también.$"

IlexForest_Text_Kimono_Girl1:
	.string "CHICA KIMONO, CHICA KIMONO, perdida y\n"
	.string "sola. Pobre chica perdida en el oscuro\l"
	.string "ENCINAR.$"

IlexForest_Text_Kimono_Girl2:
	.string "¿Que te acuerdas de mí de CIUDAD\n"
	.string "MALVA? Te lo habrás imaginado.\p"
	.string "En fin, ¿me enseñas cómo salir de este\n"
	.string "bosque?$"

IlexForest_Text_Kimono_Girl3:
	.string "¿Significa eso que vos también\n"
	.string "desconocéis el camino?\p"
	.string "$"

IlexForest_Text_Kimono_Girl4:
	.string "¡Uau! ¿Vas a enseñarme cómo salir?\p"
	.string "¡Qué POKéMON tan listo!$"

IlexForest_Text_Kimono_Girl5:
	.string "Hasta luego.$"
