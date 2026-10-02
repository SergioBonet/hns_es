Route20_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route20_EventScript_ShellBell::
	finditem ITEM_SHELL_BELL
	end

Route20_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route20_EventScript_Nicole::
	trainerbattle_single TRAINER_NICOLE_HNS, Route20_Text_SwimmerfNicoleSeen, Route20_Text_SwimmerfNicoleBeaten, Route20_EventScript_RegisterNicole
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route20_EventScript_RematchNicole
	msgbox Route20_Text_SwimmerfNicoleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_RegisterNicole::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route20_Text_NicoleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLE_HNS
	release
	end

Route20_EventScript_RematchNicole::
	trainerbattle_rematch TRAINER_NICOLE_HNS, Route20_Text_NicoleRematchIntro, Route20_Text_NicoleRematchDefeat
	msgbox Route20_Text_NicolePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_NICOLE_2_HNS, Route20_EventScript_RematchNicoleTryGiveItem
	end

Route20_EventScript_RematchNicoleTryGiveItem::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_HEART_SCALE
	closemessage
	end

Route20_EventScript_Lori::
	trainerbattle_single TRAINER_LORI_HNS, Route20_Text_SwimmerfLoriSeen, Route20_Text_SwimmerfLoriBeaten
	msgbox Route20_Text_SwimmerfLoriAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON_HNS, Route20_Text_SwimmermCameronSeen, Route20_Text_SwimmermCameronBeaten
	msgbox Route20_Text_SwimmermCameronAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_SeafoamSign::
	msgbox Route20_Text_SeafoamSign, MSGBOX_SIGN
	end

Route20_EventScript_GymSign::
	msgbox Route20_Text_CinnabarIsland_GymUnusedSign, MSGBOX_SIGN
	end

Route20_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox Route20_Text_Seel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox Route20_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dennis::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route20_Text_Dennis, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Headlocker::
	lock
	faceplayer
	msgbox Route20_Text_Headlocker, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE20_HEADLOCKER, DIR_SOUTH
	release
	end

Route20_Text_Dennis:
	.string "DENNIS: ¡SHAAAAAAAA!$"

Route20_Text_Headlocker:
	.string "En esta ruta hay un POKéMON raro.\p"
	.string "Y a veces lleva un objeto evolutivo\n"
	.string "raro.\p"
	.string "¡Eso es doblemente raro!\p"
	.string "Tengo que completar mi POKéDEX, ¡así\n"
	.string "que llevo horas pescando aquí!$"

Route20_Text_Seel:
	.string "SEEL: ¡Seel seel!$"

Route20_Text_Dewgong:
	.string "DEWGONG: ¡Goooong!$"

Route20_Text_SeafoamSign:
	.string "ISLAS ESPUMA$"

Route20_Text_NicoleRegister:
	.string "¡Tu POKéMON nada muy rápido! ¡Dame tu\n"
	.string "número!$"

Route20_Text_NicoleRematchIntro:
	.string "¡De tanto nadar, mis POKéMON se han\n"
	.string "vuelto más fuertes! ¡Luchemos!$"

Route20_Text_NicoleRematchDefeat:
	.string "Arrastrado otra vez…$"

Route20_Text_NicolePostRematch:
	.string "Gane o pierda, ¡me pongo en forma, y\n"
	.string "mis POKéMON también!$"

Route20_Text_SwimmerfNicoleSeen:
	.string "Me siento más ligera en el agua.$"

Route20_Text_SwimmerfNicoleBeaten:
	.string "¡Oh, no!$"

Route20_Text_SwimmerfNicoleAfterBattle:
	.string "La natación fortalece todo tu cuerpo.\n"
	.string "¡Es muy sana!$"

Route20_Text_SwimmerfLoriSeen:
	.string "¡Vaya colección de MEDALLAS de\p"
	.string "GIMNASIO! ¡Luchemos!$"

Route20_Text_SwimmerfLoriBeaten:
	.string "¡No!$"

Route20_Text_SwimmerfLoriAfterBattle:
	.string "SURF ya no es el único movimiento que\n"
	.string "se utiliza en el agua.$"

Route20_Text_SwimmermCameronSeen:
	.string "Supongo que es imposible ir nadando\n"
	.string "así hasta Johto.\p"
	.string "$"

Route20_Text_SwimmermCameronBeaten:
	.string "¡Aiyaa!$"

Route20_Text_SwimmermCameronAfterBattle:
	.string "Además de nadar en el mar, puedo nadar\n"
	.string "en estanques y ríos.$"

Route20_Text_CinnabarIsland_GymUnusedSign:
	.string "¿Qué pone en este letrero?\p"
	.string "LÍDER DEL GIMNASIO de ISLA CANELA:\n"
	.string "BLAINE$"

