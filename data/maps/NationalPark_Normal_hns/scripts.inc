NationalPark_Normal_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Normal_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NationalPark_Normal_OnTransition: 
	callnative SetTimeBasedEncounters
	end

NationalPark_Normal_EventScript_Lass::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster1::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Teacher2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Teacher2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

NationalPark_Normal_EventScript_TeacherQuickclaw::
	lock
	faceplayer
	goto_if_set FLAG_GOT_QUICK_CLAW, NationalPark_Normal_EventScript_TeacherQuickclaw2
	msgbox NationalPark_Normal_Text_Teacher1, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_QUICK_CLAW
NationalPark_Normal_EventScript_TeacherQuickclaw2::
	msgbox NationalPark_Normal_Text_Teacher1_QuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, CRY_MODE_NORMAL
	msgbox NationalPark_Normal_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end



NationalPark_Normal_Text_Lass:
	.string "¡Mira! ¡Mira mi bolso!\p"
	.string "He imprimido mis favoritos de la\n"
	.string "POKéDEX y los he pegado en el bolso.$"

NationalPark_Normal_Text_PokefanF:
	.string "Es una CARTA de mi hija. ¡Me da ánimos!$"

NationalPark_Normal_Text_Teacher1:
	.string "¡Presta atención, por favor!\p"
	.string "¡Vaya! A ver si dejo de hablar como si\n"
	.string "fuera una maestra.\p"
	.string "Eres ENTRENADOR POKéMON, ¿no?\p"
	.string "Como estás trabajando tanto, he\n"
	.string "pensado darte esto.\p"
	.string "$"

NationalPark_Normal_Text_Teacher1_QuickClaw:
	.string "Dale a un POKéMON esa GARRA RÁPIDA.\p"
	.string "A veces, atacará el primero en\n"
	.string "combate.$"

NationalPark_Normal_Text_Youngster1:
	.string "Estoy jugando con las pegatinas que\n"
	.string "he imprimido de mi POKéDEX.$"

NationalPark_Normal_Text_Youngster2:
	.string "La pegatina de la POKéDEX del otro\n"
	.string "chico será mía si gano.$"

NationalPark_Normal_Text_Teacher2:
	.string "Paseo por el PARQUE, pero nunca me\n"
	.string "meto en la hierba.\p"
	.string "Los ENTRENADORES siempre quieren\n"
	.string "luchar…\p"
	.string "Tú debes de haber tenido muchos\n"
	.string "combates. Deja que cure a tus\l"
	.string "POKéMON.$"

NationalPark_Normal_Text_Persian:
	.string "PERSIAN: ¡Persiia!$"

NationalPark_Normal_EventScript_Jack::
	trainerbattle_single TRAINER_JACK_HNS, NationalPark_Normal_Text_SchoolboyJack1_Seen, NationalPark_Normal_Text_SchoolboyJack1_Beaten, NationalPark_Normal_EventScript_RegisterJack
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchJack
	msgbox NationalPark_Normal_Text_SchoolboyJack_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterJack::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_JackRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACK_HNS
	release
	end

NationalPark_Normal_EventScript_RematchJack::
	trainerbattle_rematch TRAINER_JACK_HNS, NationalPark_Normal_Text_JackRematchIntro, NationalPark_Normal_Text_JackRematchDefeat
	msgbox NationalPark_Normal_Text_JackPostRematch, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten, NationalPark_Normal_EventScript_RegisterBeverly
	goto_if_set FLAG_BEVERLY_HAS_ITEM_HNS, NationalPark_Normal_EventScript_BeverlyGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchBeverly
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RematchBeverly::
	trainerbattle_rematch TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterBeverly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_BeverlyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BEVERLY_HNS
	release
	end

NationalPark_Normal_EventScript_BeverlyGiveItem::
	msgbox NationalPark_Normal_Text_BeverlyHasItem, MSGBOX_DEFAULT
	giveitem VAR_BEVERLY_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, NationalPark_Normal_EventScript_BeverlyNoRoom
	clearflag FLAG_BEVERLY_HAS_ITEM_HNS
	msgbox NationalPark_Normal_Text_BeverlyGaveItem, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_BeverlyNoRoom::
	msgbox NationalPark_Normal_Text_BeverlyNoRoom, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM_HNS, NationalPark_Normal_Text_PokefanmWilliam_Seen, NationalPark_Normal_Text_PokefanmWilliam_Beaten
	msgbox NationalPark_Normal_Text_PokefanmWilliam_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE_HNS, NationalPark_Normal_Text_LassKrise_Seen, NationalPark_Normal_Text_LassKrise_Beaten
	msgbox NationalPark_Normal_Text_LassKrise_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_TM_Dig::
	finditem ITEM_TM_DIG
	end

NationalPark_Normal_EventScript_Item_Soothe_Bell::
	finditem ITEM_SOOTHE_BELL
	end

NationalPark_Normal_Text_SchoolboyJack1_Seen:
	.string "El mundo de los POKéMON es muy\n"
	.string "profundo.\p"
	.string "Aún hay muchas cosas que no sabemos.\p"
	.string "¡Pero yo sé más que tú!$"

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
	.string "¿Qué, qué, qué?$"

NationalPark_Normal_Text_SchoolboyJack_After:
	.string "Hay mucho que aprender.\p"
	.string "Por ejemplo…\p"
	.string "Hay 92 tipos de MT.\p"
	.string "Los POKéMON intercambiados suben de\n"
	.string "nivel más rápido.$"

NationalPark_Normal_Text_JackRegister:
	.string "Hay mucho que aprender.\p"
	.string "Por ejemplo…\p"
	.string "Hay 92 tipos de MT.\p"
	.string "Los POKéMON intercambiados suben de\n"
	.string "nivel más rápido.$"

NationalPark_Normal_Text_JackRematchIntro:
	.string "¡He aprendido mucho desde nuestro\n"
	.string "último combate! ¡Vamos!$"

NationalPark_Normal_Text_JackRematchDefeat:
	.string "¿Qué, qué, qué?$"

NationalPark_Normal_Text_JackPostRematch:
	.string "Hay mucho que aprender.\p"
	.string "Por ejemplo…\p"
	.string "Hay 92 tipos de MT.\p"
	.string "Los POKéMON intercambiados suben de\n"
	.string "nivel más rápido.$"

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
	.string "Mis POKéMON son una monada.\p"
	.string "Deja que te cuente lo orgullosa que me\n"
	.string "hacen sentir mis cielitos.$"

NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
	.string "Puedo derrotarte, pero…$"

NationalPark_Normal_Text_PokefanFBeverly_After:
	.string "Debo decirte que tus POKéMON son\n"
	.string "bonitos también.$"

NationalPark_Normal_Text_PokefanmWilliam_Seen:
	.string "Queremos a nuestros POKéMON, aunque\n"
	.string "ellos no nos quieran.\p"
	.string "Eso significa ser un FAN POKéMON.$"

NationalPark_Normal_Text_PokefanmWilliam_Beaten:
	.string "Mi… ¡Mi POKéMON!$"

NationalPark_Normal_Text_PokefanmWilliam_After:
	.string "He perdido el combate, pero mis\n"
	.string "POKéMON se llevan el premio a los más\l"
	.string "adorables.$"

NationalPark_Normal_Text_LassKrise_Seen:
	.string "¿Eh? ¿Y tú qué miras?\p"
	.string "¿Quieres luchar?\p"
	.string "$"

NationalPark_Normal_Text_LassKrise_Beaten:
	.string "¡Mmmm…!$"

NationalPark_Normal_Text_LassKrise_After:
	.string "¡Pensaba que me estabas mirando\n"
	.string "porque soy bonita!$"

NationalPark_Normal_Text_Sign_RelaxationSquare:
	.string "PLAZA DEL DESCANSO PARQUE NACIONAL$"

NationalPark_Normal_Text_Sign_BattleNotice:
	.string "¿Qué dice este cartel?\p"
	.string "Por favor, lucha sólo en la hierba.\p"
	.string "PARQUE NACIONAL PUESTO DEL GUARDA$"

NationalPark_Normal_Text_TrainerTips:
	.string "PISTAS ENTRENADOR\p"
	.string "Imprime una CARTA abriéndola y\n"
	.string "pulsando START$"

NationalPark_Normal_Text_BeverlyRegister:
	.string "Debo decirte que tus POKéMON son\n"
	.string "bonitos también.$"

NationalPark_Normal_Text_BeverlyHasItem:
	.string "¡Oh, hola! Tengo algo para ti.\p"
	.string "¡Acéptalo como muestra de mi\n"
	.string "agradecimiento!$"

NationalPark_Normal_Text_BeverlyGaveItem:
	.string "¡Mis POKéMON adorados y yo te\n"
	.string "animaremos!$"

NationalPark_Normal_Text_BeverlyNoRoom:
	.string "Mmm, tienes la MOCHILA llena.\p"
	.string "Vuelve cuando tengas sitio.$"
