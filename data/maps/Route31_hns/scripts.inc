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
	.string "Ooooh…$"

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
	.string "… Zzzz… ¿Eh?\p"
	.string "¿Qué pasa? ¿Tienes una CARTA para\n"
	.string "mí?$"

Route31_Text_SleepyManFail:
	.string "… Zzzz…$"

Route31_Text_HandOverMailMon:
	.string "{PLAYER} entregó el POKéMON que lleva\n"
	.string "la CARTA.$"

Route31_Text_ReadingMail:
	.string "A ver…\p"
	.string "Gracias por traérmela.\p"
	.string "Mi amigo es un buen tipo, ¡y tú también\n"
	.string "eres genial!\p"
	.string "¡Me gustaría devolverte el favor!\p"
	.string "¡Ya sé! ¡Quiero que te quedes esto!$"

Route31_Text_DescribeRest:
	.string "… Zzz…\p"
	.string "… Eh… ¡Descanso!\p"
	.string "Es un movimiento para dormir y\n"
	.string "recuperar PS, ¿ves?\p"
	.string "Para descansar y reponerse, ¡nada\n"
	.string "como un buen DESCANSO!$"

Route31_Text_WrongMail:
	.string "Esta CARTA no es para mí.$"

Route31_Text_MissingMail:
	.string "¿Por qué es especial este POKéMON?\p"
	.string "No tiene ninguna CARTA.$"

Route31_Text_DeclinedToHandOverMail:
	.string "¿Qué? ¿No quieres nada?$"

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
	.string "¡Eres genial! ¡Me caes bien!\p"
	.string "Busco POKéMON aquí todos los días.\p"
	.string "Cuando estoy en la hierba, encuentro\n"
	.string "todo tipo de BAYAS.\p"
	.string "Si quieres, te daré algunas.$"

Route31_Text_WadeRematchIntro:
	.string "Te esperaba. ¡Luchemos!\p"
	.string "$"

Route31_Text_WadeRematchDefeat:
	.string "Ooooh…$"

Route31_Text_WadePostRematch:
	.string "Oirás de mí tan pronto como encuentre\n"
	.string "algo que te pueda interesar.$"

Route31_Text_WadeHasItem:
	.string "¡Eh! ¡Te estaba buscando!\p"
	.string "He encontrado algo mientras estaba\n"
	.string "en la hierba.\p"
	.string "¡Toma, para ti!$"

Route31_Text_WadeGaveItem:
	.string "¡Te avisaré si encuentro algo más!$"

Route31_Text_WadeNoRoom:
	.string "Mmm, parece que tienes la MOCHILA\n"
	.string "llena.\p"
	.string "¡Vuelve cuando tengas sitio!$"

Route31_Text_DarkCaveSign:
	.string "CUEVA OSCURA$"
