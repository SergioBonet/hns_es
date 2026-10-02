GoldenrodCity_RadioTower_1F_hns_MapScripts::
	.byte 0

RadioTower1F_EventScript_Grunt::
	lock
	faceplayer
	msgbox RadioTower1F_Text_GruntM3Seen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_2_HNS,  RadioTower1F_Text_GruntM3Beaten
	msgbox RadioTower1F_Text_GruntM3After, MSGBOX_AUTOCLOSE
	turnobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT, DIR_EAST
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_GRUNT, RadioTower1F_Movement_Rocket
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	release
	end

RadioTower1F_Movement_Rocket::
	walk_in_place_right
	step_end

RadioTower1F_EventScript_Lass::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Whitney::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Whitney1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_SOUTH
	release
	end

RadioTower1F_Text_Whitney1::
	.string "BLANCA: ¡Hola! ¡Soy BLANCA!\p"
	.string "¿Has oído lo del concurso para\n"
	.string "obtener una Tarjeta RADIO? ¡Yo he\l"
	.string "venido porque quiero una!\p"
	.string "Pero es que las preguntas… ¡son\n"
	.string "superdifíciles!\p"
	.string "$"

RadioTower1F_Text_Whitney2::
	.string "BLANCA: ¡Vaya, lo has conseguido!\p"
	.string "¡Yo pensaba que la respuesta a la\n"
	.string "tercera pregunta era seguro los\l"
	.string "bonguris! ¡Uy!\p"
	.string "¡Hora de volver al GIMNASIO!$"

RadioTower1F_EventScript_Reception::
	lock
	faceplayer
	msgbox RadioTower1F_Text_ReceptionistWelcome, MSGBOX_DEFAULT
	goto_if_unset FLAG_ENABLE_RADIO, RadioTower1F_EventScript_ReceptionOfferQuiz
	msgbox RadioTower1F_Text_ReceptionistNoTours, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionOfferQuiz::
	msgbox RadioTower1F_Text_RadioCardWomanOfferQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz1
	msgbox RadioTower1F_Text_DeclineQuiz, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz1::
	msgbox RadioTower1F_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz2
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz2::
	msgbox RadioTower1F_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz3
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz3::
	msgbox RadioTower1F_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz4
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz4::
	msgbox RadioTower1F_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz5
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz5::
	msgbox RadioTower1F_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionGiveRadio
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionGiveRadio::
	msgbox RadioTower1F_Text_QuizWin, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox RadioTower1F_Text_PokegearRadio, MSGBOX_AUTOCLOSE
	waitfanfare
	msgbox RadioTower1F_Text_TuneIn, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_EAST
	delay 20
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RadioTower1F_Text_Whitney2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	setflag FLAG_ENABLE_RADIO
	setflag FLAG_HIDE_GOLDENROD_BEAUTY
	setvar VAR_GOLDENROD_CITY_STATE, 2
	release
	end

GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	step_end

GoldenrodCity_RadioTower_1F_EventScript_Sign::
	lock
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

RadioTower1F_Text_ReceptionistWelcome:
	.string "¡Bienvenido!$"

RadioTower1F_Text_ReceptionistNoTours:
	.string "Hola. Lo siento, pero hoy no se admiten\n"
	.string "visitas.$"

RadioTower1F_Text_RadioCardWomanOfferQuiz:
	.string "Ahora mismo tenemos una campaña\n"
	.string "especial de PREGUNTAS.\p"
	.string "Responde bien cinco preguntas y\n"
	.string "ganarás una TARJETA RADIO para el\l"
	.string "POKéGEAR.\p"
	.string "Tú y tus POKéMON podréis usarla para\n"
	.string "escuchar música en cualquier momento\l"
	.string "y lugar.\p"
	.string "¿Quieres participar en el concurso?$"

RadioTower1F_Text_QuizQuestion1:
	.string "Pregunta 1:\p"
	.string "¿Hay algún POKéMON que solo aparezca\n"
	.string "de día?$"

RadioTower1F_Text_QuizQuestion2:
	.string "¡Correcto! 2a Pregunta:\p"
	.string "¿Es verdad que no puedes comprar una\p"
	.string "BAYA en una TIENDA?$"

RadioTower1F_Text_QuizQuestion3:
	.string "¡Has dado en el clavo!\p"
	.string "Pregunta 3:\p"
	.string "¿CÉSAR, el creador de POKé BALLS, usa\n"
	.string "bonguris como ingredientes?$"

RadioTower1F_Text_QuizQuestion4:
	.string "¡Vas bien! 4a Pregunta:\p"
	.string "¿PEGASO, el LÍDER de GIMNASIO de\p"
	.string "CIUDAD MALVA usa POKéMON pájaro?$"

RadioTower1F_Text_QuizQuestion5:
	.string "¡Guau! ¡Correcto! Ésta es la última\n"
	.string "pregunta:\p"
	.string "¿Sale CHARMANDER en las máquinas del\n"
	.string "CASINO de CIUDAD TRIGAL?$"

RadioTower1F_Text_QuizWin:
	.string "¡Bingo! ¡Correcto! ¡Enhorabuena!\p"
	.string "¡Aquí tienes tu premio, una TARJETA\n"
	.string "RADIO!$"

RadioTower1F_Text_PokegearRadio:
	.string "¡El POKéGEAR de {PLAYER} se puede usar\n"
	.string "como radio!$"

RadioTower1F_Text_TuneIn:
	.string "Sintoniza nuestros programas.$"

RadioTower1F_Text_WrongAnswer:
	.string "Lo siento mucho, pero te has\n"
	.string "equivocado. ¡Vuelve a probar!$"

RadioTower1F_Text_DeclineQuiz:
	.string "¡Ah! Entiendo. Vuelve a probar si\n"
	.string "cambias de idea.$"

RadioTower1F_Text_Lass:
	.string "NARDO es un DJ fabuloso.\p"
	.string "¡Su dulce voz me derrite!$"

RadioTower1F_Text_Youngster:
	.string "Me gusta ROSA, de la HORA POKéMON,\n"
	.string "aunque sólo conozca su voz.$"

RadioTower1F_Text_GruntM3Seen:
	.string "¡Por fin nos hemos apoderado de la\n"
	.string "TORRE RADIO!\p"
	.string "¡Ahora todos experimentarán el\n"
	.string "verdadero terror del TEAM ROCKET!\p"
	.string "¡Ya veréis qué horribles somos!$"

RadioTower1F_Text_GruntM3Beaten:
	.string "¡Demasiado fuerte! Lo siento, jefe…$"

RadioTower1F_Text_GruntM3After:
	.string "Eres muy fuerte.\p"
	.string "Arruinarías nuestros planes.\p"
	.string "Mejor alertar a los otros…$"

RadioTower1F_Text_Directory:
	.string "PB RECEPCIÓN P1 VENTAS\p"
	.string "P2 PERSONAL P3 PRODUCCIÓN\p"
	.string "P4 DESPACHO DEL DIRECTOR$"

RadioTower1F_Text_GotRadio:
	.string "¡{PLAYER} ha conseguido la TARJETA\n"
	.string "RADIO para el POKéGEAR!$"

GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow
	msgbox GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message GoldenrodCity_RadioTower_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	special PickLotteryCornerTicket
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, GoldenrodCity_RadioTower_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, GoldenrodCity_RadioTower_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow::
	msgbox GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_NoMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FullMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	end

GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier::
	msgbox GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket:
	.string "Esta es la LOTERÍA POKéMON.\p"
	.string "Si el número del BOLETO coincide con el\n"
	.string "número ID de alguno de tus POKéMON,\l"
	.string "recibirás un regalo fabuloso.\p"
	.string "¿Quieres sacar un BOLETO de la\n"
	.string "LOTERÍA POKéMON?$"

GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow:
	.string "Vuelve mañana, por favor.$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain:
	.string "Por favor, vuelve pronto.$"

GoldenrodCity_RadioTower_1F_Text_PleasePickTicket:
	.string "Elige un BILLETE de LOTERÍA.\n"
	.string "A ver… {PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}… {PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"

GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait:
	.string "El número del BILLETE de LOTERÍA\n"
	.string "es {STR_VAR_1}.\p"
	.string "Debo comprobar si este número coincide\n"
	.string "con el del ID de alguno de tus POKéMON.\l"
	.string "Espera un momento.$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon:
	.string "¡Felicidades!\p"
	.string "El número ID del {STR_VAR_1} de tu\n"
	.string "equipo coincide con el número del\l"
	.string "BILLETE de LOTERÍA.$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon:
	.string "¡Felicidades!\p"
	.string "El número ID del {STR_VAR_1} de una\n"
	.string "CAJA de tu PC coincide con el número\l"
	.string "del BILLETE de LOTERÍA.$"

GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched:
	.string "Lo siento.\n"
	.string "No coincide ningún número.$"

GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched:
	.string "Coincidían dos dígitos, así que has\n"
	.string "ganado el tercer premio.\l"
	.string "¡Un magnífico {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched:
	.string "Coincidían tres dígitos, así que has\n"
	.string "ganado el segundo premio.\l"
	.string "¡Un magnífico {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched:
	.string "Coincidían cuatro dígitos, así que\n"
	.string "has ganado el primer premio.\l"
	.string "¡Un magnífico {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched:
	.string "¡Guau! ¡Coinciden los cinco dígitos!\p"
	.string "¡Has ganado el premio gordo!\n"
	.string "¡Un magnífico {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_NoRoomForThis:
	.string "¿Eh?\n"
	.string "Se diría que no tienes sitio para esto.\p"
	.string "Haz un hueco en la MOCHILA\n"
	.string "y vuelve por aquí.$"

GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding:
	.string "¿{PLAYER}?\n"
	.string "Sí, te estaba esperando.\p"
	.string "Tenía este premio guardado para ti.$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2:
	.string "Por favor, vuelve pronto.$"


