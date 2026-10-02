Route34_DayCare_hns_MapScripts::
	.byte 0

Route34_DayCare_Bookshelf1::
	lock
	msgbox Route34_DayCare_Text_Bookshelf1, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE1_WINDOW
	release
	end

Route34_DayCare_Bookshelf2::
	lock
	msgbox Route34_DayCare_Text_Bookshelf2, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE2_WINDOW
	release
	end

Route34_DayCare_Bookshelf3::
	lock
	msgbox Route34_DayCare_Text_Bookshelf3, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE3_WINDOW
	release
	end

Route34_DayCare_Bookshelf4::
	lock
	msgbox Route34_DayCare_Text_Bookshelf4, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE4_WINDOW
	release
	end

Route34_DayCare_Text_Bookshelf1:
	.string "¡Una enciclopedia de POKéMON BEBÉ!\p"
	.string "VOLUMEN 1: TODO SOBRE LAS\n"
	.string "HABILIDADES$"

Route34_DayCare_Text_Bookshelf2:
	.string "¡Una enciclopedia de POKéMON BEBÉ!\p"
	.string "VOLUMEN 2: TIPOS TÍPICOS$"

Route34_DayCare_Text_Bookshelf3:
	.string "¡Una enciclopedia de POKéMON BEBÉ!\p"
	.string "VOLUMEN 3: GRITOS DE BEBÉS$"

Route34_DayCare_Text_Bookshelf4:
	.string "¡Una enciclopedia de POKéMON BEBÉ!\p"
	.string "VOLUMEN 4: COSTUMBRES ADORABLES$"

Route34_DayCare_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ODD_EGG, Route34_DayCare_EventScript_ClerkAfter
	msgbox Route34_DayCare_Text_ClerkBefore, MSGBOX_DEFAULT
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, Route34_DayCare_EventScript_ClerkPartyFull
	msgbox Route34_DayCare_Text_ClerkQuestion, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_INTERVIEW
	setvar VAR_0x8005, 0
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	switch VAR_RESULT
	case 0, Route34_DayCare_EventScript_ClerkRejection
	case 1, Route34_DayCare_EventScript_GivePichu
	case 2, Route34_DayCare_EventScript_GiveCleffa
	case 3, Route34_DayCare_EventScript_GiveIgglybuff
	case 4, Route34_DayCare_EventScript_GiveTyrogue
	case 5, Route34_DayCare_EventScript_GiveSmoochum
	case 6, Route34_DayCare_EventScript_GiveElekid
	case 7, Route34_DayCare_EventScript_GiveMagby
	case 8, Route34_DayCare_EventScript_GiveMantyke
	case 9, Route34_DayCare_EventScript_GiveBonsly
	case 10, Route34_DayCare_EventScript_GiveHappiny
	case 11, Route34_DayCare_EventScript_GiveMimeJr
	closemessage
	release
	end

Route34_DayCare_EventScript_GivePichu::
	giveoddegg 1
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveCleffa::
	giveoddegg 2
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveIgglybuff::
	giveoddegg 3
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveTyrogue::
	giveoddegg 4
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveSmoochum::
	giveoddegg 5
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveElekid::
	giveoddegg 6
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMagby::
	giveoddegg 7
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMantyke::
	giveoddegg 8
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveBonsly::
	giveoddegg 9
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveHappiny::
	giveoddegg 10
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMimeJr::
	giveoddegg 11
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_Clerk_GaveEgg::
	msgbox Route34_DayCare_Text_TakeCare, MSGBOX_DEFAULT
	closemessage
	delay 30
	setflag FLAG_RECEIVED_ODD_EGG
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message Route34_DayCare_Text_ReceivedOddEgg
	waitfanfare
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkPartyFull::
	msgbox Route34_DayCare_Text_ClerkNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkRejection::
	msgbox Route34_DayCare_Text_Rejection, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkAfter::
	msgbox Route34_DayCare_Text_ClerkAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_Text_ClerkBefore:
	.string "Soy el hijo de la pareja de la\n"
	.string "GUARDERÍA.\p"
	.string "Encontraron un HUEVO RARO con el\n"
	.string "POKéMON de un ENTRENADOR, pero no lo\l"
	.string "quiso…\p"
	.string "Te lo ofrecería a ti…\p"
	.string "Pero ¿cómo sé que lo vas a cuidar\n"
	.string "bien?$"

Route34_DayCare_Text_ClerkNoRoom:
	.string "Parece que de todas formas no puedes\n"
	.string "llevar otro POKéMON.$"

Route34_DayCare_Text_ClerkQuestion:
	.string "Respóndeme a esta pregunta. ¿Qué\n"
	.string "sientes por este HUEVO RARO?$"

Route34_DayCare_Text_Rejection:
	.string "Mmm, creo que este HUEVO no es para ti.\p"
	.string "¡Sería una irresponsabilidad por mi\n"
	.string "parte darle un HUEVO tan valioso a\l"
	.string "alguien que no sabe tanto de POKéMON\l"
	.string "bebé!$"

Route34_DayCare_Text_ReceivedOddEgg:
	.string "¡{PLAYER} ha recibido el HUEVO RARO!$"

Route34_DayCare_Text_TakeCare:
	.string "Sabía que eras el ENTRENADOR\n"
	.string "adecuado para esto. ¡Cuídalo bien!$"

Route34_DayCare_Text_ClerkAfter:
	.string "Por aquí vemos muchos huevos de esos.\p"
	.string "Pero ese tenía algo distinto.$"

Route34_DayCare_EventScript_Ditto::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DITTO, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_Ditto, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34_DayCare_Text_Ditto:
	.string "DITTO: ¡Tto!$"

Route34_EventScript_DaycareMan::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPartyLimitChallengeActive @ tx_randomizer_and_challenges
	goto_if_eq VAR_RESULT, TRUE, Route34_DayCare_EventScript_ClosedForChallenge
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_EventScript_CheckOnTwoMons
	msgbox Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareEggWaiting::
	msgbox Route34_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route34_EventScript_DaycareAcceptEgg::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, VAR_0x8004, Route34_EventScript_DaycareReceiveEgg
	msgbox Route34_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareReceiveEgg::
	message Route34_Text_ReceivedEgg
	playfanfare MUS_HG_OBTAIN_EGG
	waitfanfare
	waitbuttonpress
	msgbox Route34_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route34_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route34_EventScript_MonReceivedMail
	return

Route34_EventScript_MonReceivedMail::
	msgbox Route34_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route34_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_DayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPartyLimitChallengeActive @ tx_randomizer_and_challenges
	goto_if_eq VAR_RESULT, TRUE, Route34_DayCare_EventScript_ClosedForChallenge
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_DayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_DayCare_EventScript_TwoMonsInDaycare
	msgbox Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route34_DayCare_EventScript_OnlyTwoAliveMons
	msgbox Route34_DayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route34_DayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route34_DayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CanRaiseOneMore
	release
	end

Route34_DayCare_EventScript_ComeAgain::
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_CanRaiseOneMore::
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_ClosedForChallenge::
	msgbox Route34_DayCare_Text_ClosedForChallenge, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_Text_ClosedForChallenge:
	.string "¡Lo siento, durante un desafío con\n"
	.string "límite de equipo no podemos cuidar de\l"
	.string "tus POKéMON!$"

Route34_DayCare_EventScript_OnlyOneMon::
	msgbox Route34_DayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyOneAliveMon::
	msgbox Route34_DayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route34_DayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_EggWaiting::
	msgbox Route34_DayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route34_DayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route34_DayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route34_DayCare_EventScript_YourMonHasGrownXLevels
	return

Route34_DayCare_EventScript_OneMonInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_TryRetrieveMon::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, VAR_0x8004, Route34_DayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_CostPrompt
	end

Route34_DayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route34_DayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_CheckEnoughMoney
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_RetrieveMon
	msgbox Route34_DayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_RetrieveMon::
	@applymovement LOCALID_DAYCARE_LADY, Route34_DayCare_Movement_RetrieveDaycareMon
	@waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route34_DayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_AskRetrieveOtherMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route34_DayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_NoRoom::
	msgbox Route34_DayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route34_DayCare_EventScript_UnusedEnd::
	end

Route34_DayCare_EventScript_TwoMonsInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "Soy el ENCARGADO de la GUARDERÍA.\p"
	.string "Ayudo a los ENTRENADORES a cuidar\n"
	.string "de sus preciosos POKéMON.\p"
	.string "Si quieres que me encargue del tuyo,\n"
	.string "ve a hablar con mi mujer.$"

Route34_Text_DoYouWantEgg:
	.string "¡Ah, eres tú!\p"
	.string "¡Hemos cuidado de tu POKéMON y vaya\n"
	.string "sorpresa que nos hemos llevado!\p"
	.string "¡Tu POKéMON ha tenido un HUEVO!\p"
	.string "No sabemos cómo ha sucedido,\n"
	.string "pero es de tu POKéMON, seguro.\p"
	.string "¿Lo quieres?$"

Route34_Text_YourMonIsDoingFine:
	.string "¡Ah, eres tú! Me alegro de verte.\n"
	.string "Tu {STR_VAR_1} está estupendamente.$"

Route34_Text_IllKeepIt:
	.string "Muy bien, entonces me seguiré\n"
	.string "ocupando de él. ¡Gracias!$"

Route34_Text_YouHaveNoRoomForIt:
	.string "No tienes sitio para él…\n"
	.string "Vuelve cuando lo tengas.$"

Route34_Text_ReceivedEgg:
	.string "El Encargado de la Guardería le ha\n"
	.string "dado el Huevo a {PLAYER}.$"

Route34_Text_TakeGoodCareOfIt:
	.string "Cuídalo bien.$"

Route34_Text_FriendlyWithOtherTrainersMon:
	.string "Por cierto, con respecto a tu\n"
	.string "{STR_VAR_1}, parece que se ha hecho\l"
	.string "amigo del {STR_VAR_3} de {STR_VAR_2}.\p"
	.string "Es incluso posible que haya\n"
	.string "recibido una CARTA.$"

@ Unused
Route34_Text_SeeWifeIfYouWantToPickUpMon:
	.string "Si quieres recoger a tu POKéMON, habla\n"
	.string "con mi mujer.$"

Route34_Text_YourMonsAreDoingFine:
	.string "¡Ah, eres tú! Tu {STR_VAR_1} y el\n"
	.string "{STR_VAR_2} están muy bien.$"

Route34_Text_IWillKeepDoYouWantIt:
	.string "Yo me lo quedaría.\n"
	.string "Pero imagino que lo quieres.$"

Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "Soy la ENCARGADA de la GUARDERÍA.\p"
	.string "Podemos ocuparnos de tus POKéMON.\p"
	.string "¿Quieres que cuidemos de alguno?$"

Route34_DayCare_Text_WhichMonShouldWeRaise:
	.string "¿Qué POKéMON quieres que cuidemos?\p"
	.string "$"

Route34_DayCare_Text_WellRaiseYourMon:
	.string "Estupendo, nos ocuparemos de tu\n"
	.string "{STR_VAR_1} durante un tiempo.\p"
	.string "Recógelo cuando quieras.\p"
	.string "$"

Route34_DayCare_Text_WeCanRaiseOneMore:
	.string "Podemos cuidar a dos de tus POKéMON.\n"
	.string "¿Quieres que cuidemos de otro más?$"

Route34_DayCare_Text_HusbandWasLookingForYou:
	.string "Mi marido te estaba buscando.$"

Route34_DayCare_Text_FineThenComeAgain:
	.string "Muy bien. Vuelve cuando quieras.$"

Route34_DayCare_Text_NotEnoughMoney:
	.string "No tienes bastante dinero.$"

Route34_DayCare_Text_TakeOtherOneBackToo:
	.string "¿Quieres llevarte el otro también?$"

Route34_DayCare_Text_ComeAgain:
	.string "Muy bien.\n"
	.string "Vuelve cuando quieras.$"

Route34_DayCare_Text_GoodToSeeYou:
	.string "¡Ah, eres tú! Me alegro de verte.\n"
	.string "Y tú te alegrarás de saber esto…$"

Route34_DayCare_Text_YourMonHasGrownXLevels:
	.string "Tu {STR_VAR_1} ha crecido\n"
	.string "estos niveles: ¡{STR_VAR_2}!$"

Route34_DayCare_Text_YourTeamIsFull:
	.string "Tu equipo POKéMON está completo. Haz\n"
	.string "un hueco y vuelve a verme.$"

@ Unused
Route34_DayCare_Text_TakeBackWhichMon:
	.string "¿Qué POKéMON quieres recoger?$"

Route34_DayCare_Text_ItWillCostX:
	.string "Si quieres llevarte a tu {STR_VAR_1},\n"
	.string "tendrás que pagar {STR_VAR_2}¥.$"

Route34_DayCare_Text_HeresYourMon:
	.string "¡Perfecto!\n"
	.string "Aquí tienes a tu POKéMON.$"

Route34_DayCare_Text_TookBackMon:
	.string "{PLAYER} recogió a {STR_VAR_1} de\n"
	.string "la GUARDERÍA POKéMON.$"

Route34_DayCare_Text_YouHaveJustOneMon:
	.string "Anda, pero si sólo tienes un POKéMON…\p"
	.string "Vuelve cuando tengas alguno más.$"

Route34_DayCare_Text_TakeYourMonBack:
	.string "¿Quieres recoger un POKéMON?$"

Route34_DayCare_Text_WhatWillYouBattleWith:
	.string "Si me dejas ese POKéMON,\n"
	.string "no podrás entablar combates.\p"
	.string "Vuelve en otra ocasión.$"

Route34_DayCare_Text_YoullBeLeftWithJustOne:
	.string "¿Eh?\n"
	.string "A ver, a ver.\p"
	.string "Si me dejas ese POKéMON aquí, \n"
	.string "sólo te quedarás con uno en forma.\p"
	.string "Será mejor que atrapes alguno más,\n"
	.string "vamos, digo yo.$"
