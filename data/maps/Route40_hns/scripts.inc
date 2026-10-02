Route40_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route40_MapScript_OnTransition
	.byte 0

Route40_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, Route40_MapScript_ClearWeather
	end

Route40_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

Route40_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON_HNS, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermSimonSeen:
	.string "Debes calentar antes de entrar en el\n"
	.string "agua.\p"
	.string "Es imprescindible.$"

Route40_Text_SwimmermSimonBeaten:
	.string "¡Vale! ¡Me rindo!$"

Route40_Text_SwimmermSimonAfter:
	.string "CIUDAD ORQUÍDEA está bastante lejos\n"
	.string "de aquí.$"

Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL_HNS, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermRandallSeen:
	.string "¡Eres joven y estás en forma!\p"
	.string "¡No vayas sobre tu POKéMON! ¡Nada!$"

Route40_Text_SwimmermRandallBeaten:
	.string "¡Oh, he perdido…!$"

Route40_Text_SwimmermRandallAfter:
	.string "La natación fortalece tu cuerpo. Es\n"
	.string "sana.$"

Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE_HNS, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "¿Vas a CIUDAD ORQUÍDEA?\p"
	.string "¿Te apetece luchar antes?$"

Route40_Text_SwimmerfElaineBeaten:
	.string "¡He perdido!$"

Route40_Text_SwimmerfElaineAfter:
	.string "Creo que nado mejor que tú. ¡Sin duda!$"

Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA_HNS, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "Yo no necesito flotador.\p"
	.string "¡Voy agarrada a un POKéMON de mar!$"

Route40_Text_SwimmerfPaulaBeaten:
	.string "¡Ooh, estoy mareada!$"

Route40_Text_SwimmerfPaulaAfter:
	.string "Mientras flote así, las olas me\n"
	.string "llevarán.$"

Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "Aunque no se ve desde aquí, CIUDAD\p"
	.string "ORQUÍDEA está al otro lado del mar.$"

Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "Vine en barco a C. OLIVO por las vistas\n"
	.string "y el aire que se respira.\p"
	.string "Como es un puerto, parece diferente\n"
	.string "de la gran ciudad.$"

Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "¿Has ido a la COLINA DESAFÍO?\p"
	.string "Creo que allí ya se ha reunido un\n"
	.string "montón de ENTRENADORES duros.\p"
	.string "Pero como tienes tantas MEDALLAS, no\n"
	.string "deberías hacerlo nada mal.$"

Route40_Text_Monica:
	.string "LUNA: Encantada de conocerte. Soy\n"
	.string "LUNA, de la FAMILIA de los DÍAS de la\l"
	.string "SEMANA.\p"
	.string "¡A que no adivinas cuál es mi día\n"
	.string "favorito de la semana!$"

Route40_Text_MonicaGivesGift:
	.string "¡Correcto!\p"
	.string "¡Como muestra de nuestra amistad,\n"
	.string "tengo un regalo para ti!$"

Route40_Text_MonicaGaveGift:
	.string "Luna: Es un objeto que aumenta el\n"
	.string "poder de los movimientos de tipo\l"
	.string "VOLADOR.\p"
	.string "Deberías darle este objeto a un\n"
	.string "POKéMON pájaro.$"

Route40_Text_MonicaMonday:
	.string "LUNA: Mis hermanos y hermanas están\n"
	.string "por todas partes.\p"
	.string "¡A ver si los encuentras!$"

Route40_Text_MonicaNotMonday:
	.string "LUNA: No creo que hoy sea lunes. ¡Qué\n"
	.string "pena…!$"

Route40_Text_MonicaNope:
	.string "Ese no.$"

Rotue40_EventScript_Monica::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Rotue40_EventScript_MonicaNope
	case 1, Rotue40_EventScript_MonicaYes
	case 2, Rotue40_EventScript_MonicaNope
	case 3, Rotue40_EventScript_MonicaNope
	case 4, Rotue40_EventScript_MonicaNope
	case 5, Rotue40_EventScript_MonicaNope
	case 6, Rotue40_EventScript_MonicaNope
	case 7 Rotue40_EventScript_MonicaCancel
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
	closemessage
	release
	end
Rotue40_EventScript_MonicaYes::
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SHARP_BEAK
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaNope::
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaCancel::
	closemessage
	release
	end
Rotue40_EventScript_MonicaCompleted::
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
	closemessage
	release
	end
