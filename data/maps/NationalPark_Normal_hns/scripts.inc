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
	.string "Look! Check out my bag!\p"
	.string "I printed out my favorites from my\n"
	.string "POKéDEX and stuck them on my bag.$"

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
	.string "I'm playing with stickers I printed\n"
	.string "from my POKéDEX.$"

NationalPark_Normal_Text_Youngster2:
	.string "La pegatina de la POKéDEX del otro\n"
	.string "chico será mía si gano.$"

NationalPark_Normal_Text_Teacher2:
	.string "I take walks in the PARK, but I\n"
	.string "never go into the grass.\p"
	.string "Trainers always want to battle…\p"
	.string "You must have been in many battles.\n"
	.string "Let me heal your POKéMON for you.$"

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
	.string "The world of POKéMON is deep.\p"
	.string "There are still lots of things we\n"
	.string "don't know.\p"
	.string "But I know more than you do!$"

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
	.string "¿Qué, qué, qué?$"

NationalPark_Normal_Text_SchoolboyJack_After:
	.string "There is a lot to learn.\p"
	.string "For example…\p"
	.string "There are 92 kinds of TMs.\p"
	.string "Traded POKéMON level up faster.$"

NationalPark_Normal_Text_JackRegister:
	.string "There is a lot to learn.\p"
	.string "For example…\p"
	.string "There are 92 kinds of TMs.\p"
	.string "Traded POKéMON level up faster.$"

NationalPark_Normal_Text_JackRematchIntro:
	.string "I've learned a lot since we\n"
	.string "last battled! Let's go!$"

NationalPark_Normal_Text_JackRematchDefeat:
	.string "¿Qué, qué, qué?$"

NationalPark_Normal_Text_JackPostRematch:
	.string "There is a lot to learn.\p"
	.string "For example…\p"
	.string "There are 92 kinds of TMs.\p"
	.string "Traded POKéMON level up faster.$"

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
	.string "My POKéMON are simply darling.\p"
	.string "Let me tell you how proud my\n"
	.string "darlings make me.$"

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
	.string "I lost the battle, but my POKéMON win\n"
	.string "the prize for being most lovely.$"

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
	.string "Oh, hello! I have something\n"
	.string "for you.\p"
	.string "Please take it as a token of\n"
	.string "my appreciation!$"

NationalPark_Normal_Text_BeverlyGaveItem:
	.string "My darling POKéMON and I will\n"
	.string "be cheering for you!$"

NationalPark_Normal_Text_BeverlyNoRoom:
	.string "Hmm, your BAG is full.\p"
	.string "Come back when you have room.$"
