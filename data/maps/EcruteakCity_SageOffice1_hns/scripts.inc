EcruteakCity_SageOffice1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_SageOffice1_OnTransition
	.byte 0

EcruteakCity_SageOffice1_OnTransition::
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice1_EventScript_SageAside
	end

EcruteakCity_SageOffice1_EventScript_SageAside::
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	end

EcruteakCity_SageOffice1_EventScript_Sign::
	msgbox EcruteakCity_SageOffice1_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_SageOffice1_Text_Sign:
	.string "El cascabel de la torre suena claro\n"
	.string "para quienes están bajo su\l"
	.string "protección.$"

EcruteakCity_SageOffice2_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice2_EventScript_SageA4
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageA2
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA2::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAGEOFFICE_SAGE
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA3::
	msgbox EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA4::
	msgbox EcruteakTinTowerEntrance_Text_SageDone, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_SageOffice2_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 10, EcruteakCity_SageOffice2_EventScript_B2
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, EcruteakCity_SageOffice2_EventScript_B2
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_B2::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageClearBell, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageC::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_Movement_StandAside:
	walk_left
	face_down
	step_end

EcruteakTinTowerEntrance_Text_SageNoBadge:
	.string "La TORRE CAMPANA está vetada a los\n"
	.string "que no son dignos. Lo siento, pero\l"
	.string "tendrás que irte.$"

EcruteakTinTowerEntrance_Text_SageWithBadge:
	.string "Sin la MEDALLA del GIMNASIO de CIUDAD\p"
	.string "IRIS, no se puede entrar en la TORRE\n"
	.string "HOJALATA.\p"
	.string "¡Ah!\p"
	.string "¡La MEDALLA de CIUDAD IRIS!\p"
	.string "Puedes pasar.$"

EcruteakTinTowerEntrance_Text_SageNoClearBell:
	.string "Ha ocurrido un hecho importante.\p"
	.string "Perdóname, pero tengo que pedirte que\n"
	.string "te vayas.\p"
	.string "Lo que alivia el alma…\p"
	.string "El TRÍO DE SABIOS dice cosas muy\n"
	.string "difíciles de entender…$"

EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
	.string "Ha ocurrido algo trascendental.\p"
	.string "Disculpa, pero debo pedirte que te\n"
	.string "marches.\p"
	.string "……$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
	.string "¡Ah!\p"
	.string "¡El sonido de ese CASCABEL CLARO!\p"
	.string "¡Es… es sublime!\p"
	.string "¡Nunca había oído un sonido tan\n"
	.string "bonito!\p"
	.string "El tintineo de ese cascabel refleja el\n"
	.string "alma de quien lo lleva.\p"
	.string "Tú…\p"
	.string "Tú quizá puedas superar la TORRE\n"
	.string "CAMPANA.\p"
	.string "Adelante, por favor.$"

EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
	.string "Sigue adelante.$"

EcruteakTinTowerEntrance_Text_SageDone:
	.string "El tintineo de ese cascabel refleja el\n"
	.string "alma de quien lo lleva.\p"
	.string "Tú… Eres digno de verdad.$"

EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "La TORRE HOJALATA es una espléndida\n"
	.string "torre de nueve pisos.\p"
	.string "Alivia el alma de todos los que la\n"
	.string "miran.$"

EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
	.string "¡La TORRE CAMPANA ha temblado! ¡Un\n"
	.string "POKéMON debe de haber vuelto a la\l"
	.string "cima!$"

EcruteakTinTowerEntrance_Text_Gramps:
	.string "Dos torres… Dos POKéMON…\p"
	.string "Pero cuando una se quemó, los dos\p"
	.string "POKéMON huyeron y nunca volvieron.$"
