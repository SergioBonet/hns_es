Route31_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE_HNS, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten, Route31_EventScript_RegisterWade
	goto_if_set FLAG_WADE_HAS_ITEM_HNS, Route31_EventScript_WadeGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_RematchWade
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_RegisterWade::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route31_Text_WadeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WADE_HNS
	release
	end

Route31_EventScript_RematchWade::
	trainerbattle_rematch TRAINER_WADE_HNS, Route31_Text_WadeRematchIntro, Route31_Text_WadeRematchDefeat
	msgbox Route31_Text_WadePostRematch, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeGiveItem::
	msgbox Route31_Text_WadeHasItem, MSGBOX_DEFAULT
	giveitem VAR_WADE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route31_EventScript_WadeNoRoom
	clearflag FLAG_WADE_HAS_ITEM_HNS
	msgbox Route31_Text_WadeGaveItem, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeNoRoom::
	msgbox Route31_Text_WadeNoRoom, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 1, Route31_EventScript_SleepyMan_AskForKenya
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_AskForKenya::
	msgbox Route31_Text_SleepyManGotMail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_SleepyMan_GiveKenya
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_GiveKenya::
	removenamedmon 1
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route31_EventScript_SleepyMan_Fail
	msgbox Route31_Text_HandOverMailMon, MSGBOX_DEFAULT
	delay 55
	callnative UpdateFollowingPokemon
	msgbox Route31_Text_ReadingMail, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	msgbox Route31_Text_DescribeRest, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 2
	release
	end

Route31_EventScript_SleepyMan_Fail::
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	release
	end


Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
	.string "CUEVA OSCURA…\p"
	.string "Si los POKéMON pudieran iluminarla, la\n"
	.string "exploraría.$"

Route31_Text_BugCatcherWade1_Seen:
	.string "He atrapado un montón de POKéMON.\n"
	.string "¡Luchemos!$"

Route31_Text_BugCatcherWade1_Beaten:
	.string "Awwwww…$"

Route31_Text_BugCatcherWade1_After:
	.string "Puedes atrapar POKéMON aunque ya\n"
	.string "lleves seis contigo.\p"
	.string "Si atrapas alguno más, será enviado a\n"
	.string "una caja de tu PC.$"

Route31_Text_SleepyMan:
	.string "¡Arg…! ¿Eh?\p"
	.string "Hoy he caminado mucho buscando\n"
	.string "POKéMON.\p"
	.string "Me duelen los pies y tengo sueño…\p"
	.string "Si fuera un POKéMON salvaje, sería\n"
	.string "fácil atraparme…\p"
	.string "¡Zzzz…!$"

Route31_Text_SleepyManGotMail:
	.string "…Zzzz… Huh?\p"
	.string "What's that? You have MAIL\n"
	.string "for me?$"

Route31_Text_SleepyManFail:
	.string "…Zzzz…$"

Route31_Text_HandOverMailMon:
	.string "{PLAYER} entregó el POKéMON que lleva\n"
	.string "la CARTA.$"

Route31_Text_ReadingMail:
	.string "Let's see…\p"
	.string "Thanks for bringing this to\n"
	.string "me.\p"
	.string "My friend's a good guy, and\n"
	.string "you're swell too!\p"
	.string "I'd like to do something good\n"
	.string "in return too!\p"
	.string "I know! I want you to have\n"
	.string "this!$"

Route31_Text_DescribeRest:
	.string "...Zzz...\p"
	.string "...Umm... Rest!\p"
	.string "The phrase 'recover fast' became\n"
	.string "shortened to 'Rest,' you see?\p"
	.string "This is a move to sleep and recover\n"
	.string "some HP.$"

Route31_Text_WrongMail:
	.string "Esta CARTA no es para mí.$"

Route31_Text_MissingMail:
	.string "¿Por qué es especial este POKéMON?\p"
	.string "No tiene ninguna CARTA.$"

Route31_Text_DeclinedToHandOverMail:
	.string "What? You don't want\n"
	.string "anything?$"

Route31_Text_CantTakeLastMon:
	.string "Si te quito ese POKéMON, ¿qué vas a\n"
	.string "usar en los combates?$"

Route31_Text_Youngster:
	.string "He encontrado un buen POKéMON en la\n"
	.string "CUEVA OSCURA.\p"
	.string "Voy a criarlo para enfrentarme a\n"
	.string "PEGASO.\p"
	.string "Es el LÍDER del GIMNASIO de CIUDAD\n"
	.string "MALVA.$"

Route31_Text_Sign:
	.string "RUTA 31\p"
	.string "CIUDAD MALVA - CIUDAD CEREZO$"

Route31_Text_WadeRegister:
	.string "You're awesome! I like you!\p"
	.string "I look for POKéMON here every\n"
	.string "day.\p"
	.string "When I'm in the grass, I find\n"
	.string "all kinds of BERRIES.\p"
	.string "If you'd like, I'll share\n"
	.string "some.$"

Route31_Text_WadeRematchIntro:
	.string "Te esperaba. ¡Luchemos!\p"
	.string "$"

Route31_Text_WadeRematchDefeat:
	.string "Awwwww…$"

Route31_Text_WadePostRematch:
	.string "Oirás de mí tan pronto como encuentre\n"
	.string "algo que te pueda interesar.$"

Route31_Text_WadeHasItem:
	.string "Hey! I've been looking for\n"
	.string "you!\p"
	.string "I found something while I\n"
	.string "was in the grass.\p"
	.string "Here, you can have it!$"

Route31_Text_WadeGaveItem:
	.string "I'll let you know if I find\n"
	.string "anything else!$"

Route31_Text_WadeNoRoom:
	.string "Hmm, looks like your BAG\n"
	.string "is full.\p"
	.string "Come back when you have\n"
	.string "room!$"

Route31_Text_DarkCaveSign:
	.string "DARK CAVE$"
