.equ FOUND_FIRST_SWITCH, FLAG_TEMP_1
.equ SWITCH1_ID,         VAR_0x8004
.equ SWITCH2_ID,         VAR_0x8005
.equ TRASH_CAN_ID,       VAR_0x8008

VermilionCity_Gym_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, Common_EventScript_NopReturn
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	goto_if_eq SWITCH1_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	goto_if_eq SWITCH2_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_EventScript_LtSurge::
	famechecker FAMECHECKER_LTSURGE, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_LT_SURGE, VermilionCity_Gym_Text_LtSurgeIntro, VermilionCity_Gym_Text_LtSurgeDefeat, VermilionCity_Gym_EventScript_DefeatedLtSurge, NO_MUSIC
	goto_if_unset FLAG_GOT_TM34_FROM_SURGE, VermilionCity_Gym_EventScript_GiveTM34
	msgbox VermilionCity_Gym_Text_LtSurgePostBattle
	release
	end

VermilionCity_Gym_EventScript_DefeatedLtSurge::
	famechecker FAMECHECKER_LTSURGE, 1
	call_if_unset FLAG_GOT_HM05, VermilionCity_Gym_EventScript_ShowOaksAide
	clearflag FLAG_HIDE_FAME_CHECKER_LT_SURGE_JOURNAL
	setflag FLAG_DEFEATED_LT_SURGE
	setflag FLAG_BADGE03_GET
	set_gym_trainers_frlg 3
	goto VermilionCity_Gym_EventScript_GiveTM34
	end

VermilionCity_Gym_EventScript_ShowOaksAide::
	clearflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	return

VermilionCity_Gym_EventScript_GiveTM34::
	msgbox VermilionCity_Gym_Text_ExplainThunderBadgeTakeThis
	checkitemspace ITEM_TM34
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_NoRoomForTM34
	giveitem_msg VermilionCity_Gym_Text_ReceivedTM34FromLtSurge, ITEM_TM34
	setflag FLAG_GOT_TM34_FROM_SURGE
	msgbox VermilionCity_Gym_Text_ExplainTM34
	release
	end

VermilionCity_Gym_EventScript_NoRoomForTM34::
	msgbox VermilionCity_Gym_Text_MakeRoomInYourBag
	release
	end

VermilionCity_Gym_EventScript_Dwayne::
	trainerbattle_single TRAINER_SAILOR_DWAYNE, VermilionCity_Gym_Text_DwayneIntro, VermilionCity_Gym_Text_DwayneDefeat
	famechecker FAMECHECKER_LTSURGE, 4
	msgbox VermilionCity_Gym_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Baily::
	trainerbattle_single TRAINER_ENGINEER_BAILY, VermilionCity_Gym_Text_BailyIntro, VermilionCity_Gym_Text_BailyDefeat
	msgbox VermilionCity_Gym_Text_BailyPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Tucker::
	trainerbattle_single TRAINER_GENTLEMAN_TUCKER, VermilionCity_Gym_Text_TuckerIntro, VermilionCity_Gym_Text_TuckerDefeat, VermilionCity_Gym_EventScript_DefeatedTucker
	famechecker FAMECHECKER_LTSURGE, 3
	msgbox VermilionCity_Gym_Text_TuckerPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_DefeatedTucker::
	famechecker FAMECHECKER_LTSURGE, 2
	release
	end

VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LT_SURGE, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_Text_LtSurgeIntro::
	.string "¡Eh, chaval! ¿Qué crees que haces\n"
	.string "aquí?\p"
	.string "¡No durarás en combate!\n"
	.string "¡No con tu poder tan escaso!\p"
	.string "¡Te lo digo, chaval, los POKéMON\n"
	.string "eléctricos me salvaron en la guerra!\p"
	.string "¡Paralizaron a mis enemigos\n"
	.string "con descargas!\p"
	.string "¡Lo mismo que haré contigo!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

VermilionCity_Gym_Text_LtSurgePostBattle::
	.string "¡Te daré un pequeño consejo!\p"
	.string "¡La electricidad es muy potente!\p"
	.string "¡Pero no afecta a los POKéMON\n"
	.string "del tipo TIERRA!$"

VermilionCity_Gym_Text_ExplainThunderBadgeTakeThis::
	.string "¡La MEDALLA TRUENO aumenta la\n"
	.string "VELOCIDAD de tus POKéMON!\p"
	.string "¡Y permite volar a tus POKéMON\n"
	.string "cuando quieran!\p"
	.string "¡Tú eres muy especial!\n"
	.string "¡Toma esto!$"

VermilionCity_Gym_Text_ReceivedTM34FromLtSurge::
	.string "¡{PLAYER} recibió la MT34\n"
	.string "de manos de LT. SURGE!$"

VermilionCity_Gym_Text_ExplainTM34::
	.string "¡MT34 contiene ONDA VOLTIO!\p"
	.string "¡Enséñaselo a un POKéMON\n"
	.string "eléctrico!$"

VermilionCity_Gym_Text_MakeRoomInYourBag::
	.string "¡Más vale que le hagas sitio!$"

VermilionCity_Gym_Text_LtSurgeDefeat::
	.string "¡Guau!\p"
	.string "¡Tú sí que eres fuerte!\p"
	.string "¡Anda, toma la MEDALLA TRUENO!$"

VermilionCity_Gym_Text_TuckerIntro::
	.string "¡Cuando estaba en el ejército,\n"
	.string "el LT. SURGE era muy estricto!$"

VermilionCity_Gym_Text_TuckerDefeat::
	.string "¡Alto!\n"
	.string "¡Eres muy bueno!$"

VermilionCity_Gym_Text_TuckerPostBattle::
	.string "No es fácil abrir esta puerta...\p"
	.string "¡El LT. SURGE siempre fue muy\n"
	.string "cauteloso en el ejército!$"

VermilionCity_Gym_Text_BailyIntro::
	.string "¡No es que yo sea muy fuerte,\n"
	.string "pero soy muy bueno con la\l"
	.string "electricidad!$"

VermilionCity_Gym_Text_BailyDefeat::
	.string "¡Qué paliza!$"

VermilionCity_Gym_Text_BailyPostBattle::
	.string "¡Vale, hablaré!\p"
	.string "¡LT. SURGE dijo que ocultaría los\n"
	.string "botones de la puerta dentro de\l"
	.string "algo!$"

VermilionCity_Gym_Text_DwayneIntro::
	.string "¡Este lugar no es para niños!\n"
	.string "¡Por muy fuerte que seas!$"

VermilionCity_Gym_Text_DwayneDefeat::
	.string "¡Uau!\n"
	.string "¡Me has sorprendido!$"

VermilionCity_Gym_Text_DwaynePostBattle::
	.string "LT. SURGE colocó cerraduras\n"
	.string "dobles en el GIMNASIO.\p"
	.string "¡Las puso por todos sitios!\n"
	.string "¡Te daré una pista!\p"
	.string "¡Tras abrir la 1.ª cerradura, la\n"
	.string "2.ª está al lado!$"

VermilionCity_Gym_Text_GymGuyAdvice::
	.string "¡Eh!\n"
	.string "¡Aspirante al título!\p"
	.string "LT. SURGE tiene un apodo.\p"
	.string "La gente lo llama el\n"
	.string "¡Americano Relámpago!\p"
	.string "Es un experto en POKéMON\n"
	.string "eléctricos.\p"
	.string "Los POKéMON de tipo AVE/AGUA se\n"
	.string "enfrentan mal al tipo ELÉCTRICO.\p"
	.string "Cuidado también con la parálisis.\p"
	.string "LT. SURGE es muy cauteloso.\p"
	.string "Se ha encerrado, así que no será\n"
	.string "fácil llegar hasta él.$"

VermilionCity_Gym_Text_GymGuyPostVictory::
	.string "¡Uau!\n"
	.string "¡Vaya pelea tan eléctrica!$"

VermilionCity_Gym_Text_GymStatue::
	.string "LÍDER del GIMNASIO POKéMON\n"
	.string "de CARMÍN: LT. SURGE\p"
	.string "ENTRENADOR GANADOR:\n"
	.string "{RIVAL}$"

VermilionCity_Gym_Text_GymStatuePlayerWon::
	.string "LÍDER del GIMNASIO POKéMON\n"
	.string "de CARMÍN: LT. SURGE\p"
	.string "ENTRENADORES GANADORES:\n"
	.string "{RIVAL} y {PLAYER}$"

VermilionCity_Gym_Text_NopeOnlyTrashHere::
	.string "¡No, aquí sólo hay basura!$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
	.string "¡Oye! ¡Hay un botón debajo de la\n"
	.string "basura!\p"
	.string "¡Púlsalo!\n"
	.string "Abierto primer cierre eléctrico.$"

VermilionCity_Gym_Text_SecondLockOpened::
	.string "Abierto segundo cierre eléctrico.\p"
	.string "¡Abierta la puerta mecánica!$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
	.string "¡No! Aquí sólo hay basura.\p"
	.string "¡Las cerraduras eléctricas fueron\n"
	.string "reajustadas!$"

