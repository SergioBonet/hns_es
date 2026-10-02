EcruteakCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

EcruteakCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

EcruteakCity_Test_Lugia::
	setvar VAR_LUGIA_OR_HOOH, 1
	end
EcruteakCity_Test_League::
	setvar VAR_COMPLETED_HO_OH, 4
	setvar VAR_COMPLETED_LUGIA, 4
	end


EcruteakCity_EventScript_Trigger::
	@flagheap
	clearflag FLAG_RELEASED_BEASTS
	clearflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_ECRUTEAK_BILL
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_CAUGHT_HO_OH
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_CAUGHT_LUGIA
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS  
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	clearflag FLAG_GOT_TM_SNATCH
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_GOT_TYROGUE
	clearflag FLAG_BEAT_KIYO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH

	setflag FLAG_VISITED_ECRUTEAK_CITY
	setflag FLAG_HIDE_ROUTE42_EUSINE

	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setflag FLAG_HIDE_ROUTE39_SHADOW
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setvar VAR_COMPLETED_HO_OH, 0
	setvar VAR_COMPLETED_LUGIA, 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 0 
	setvar VAR_ECRUTEAK_CITY_STATE, 1
	end

EcruteakCity_Trigger_Silver::
	lockall
	opendoor 39, 40
	waitdooranim
	delay 10
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
	addobject LOCALID_ECRUTEK_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	playse SE_BANG
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
	message EcruteakCity_Text_Silver1
	
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	closedoor 39, 40
	waitdooranim
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
	waitmovement LOCALID_ECRUTEK_SILVER


	setflag FLAG_HIDE_ECRUTEAK_SILVER
	removeobject LOCALID_ECRUTEK_SILVER
	fadedefaultbgm

	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	releaseall
	end

EcruteakCity_Movement_Silver1:
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

EcruteakCity_Movement_Silver2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EcruteakCity_Text_Silver1:
	.string "¡PUMBA!$"

EcruteakCity_Text_Silver2:
	.string "{RIVAL}: ¿Cómo…? ¿Cómo es posible?\n"
	.string "¿Cómo puedo perder contra unas\l"
	.string "simples CHICAS KIMONO…?$"

EcruteakCity_Text_Silver3:
	.string "{RIVAL}: Me estabas mirando,\n"
	.string "{PLAYER}…\p"
	.string "Sí, eso es.\p"
	.string "Nunca pensé que vencer a cinco\n"
	.string "CHICAS KIMONO fuera tan difícil…\p"
	.string "Me han dado una paliza…\p"
	.string "…\p"
	.string "Tú también has venido por lo mismo,\n"
	.string "¿verdad?\p"
	.string "¡No te creas mucho solo porque\n"
	.string "venciste al TEAM ROCKET!\p"
	.string "Estas CHICAS KIMONO son fortísimas.\p"
	.string "A ver si puedes vencerlas.\p"
	.string "Pero yo no vuelvo, no quiero verte\n"
	.string "ganar.$"

EcruteakCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
	closemessage
	release
	end
		
EcruteakCity_EventScript_Lass::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl2::
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man::
	lock
	faceplayer
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man2::
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageRight::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageTower::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageGym::
	lock
	faceplayer
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_TheaterSign::
	lock
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_OfficeSign::
	lock
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_BurnedSign::
	lock
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_CitySign::
	lock
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_GymSign::
	lock
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Vulpix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

EcruteakCity_Text_Eevee:
	.string "EEVEE: ¡Veee!$"

EcruteakCity_Text_Vulpix:
	.string "VULPIX: ¡Vullll Pix!$"


EcruteakCity_Text_UnusedMissingDaughter:
	.string "Ay, no. Ay, no…\p"
	.string "Mi hija ha desaparecido.\p"
	.string "No… No puede haber ido a la TORRE\n"
	.string "QUEMADA.\p"
	.string "Le dije que no se acercara…\p"
	.string "Allí la gente desaparece…\p"
	.string "Ay, ¿qué hago…?$"

EcruteakCity_Text_Gramps1:
	.string "En CIUDAD IRIS había dos torres:\p"
	.string "una en el Este y otra en el Oeste.$"

EcruteakCity_Text_Gramps2:
	.string "¡Ah, tú! ¿Has aprendido a bailar como\n"
	.string "las CHICAS KIMONO?\p"
	.string "Si vas a su TEATRO de DANZA, un raro\n"
	.string "anciano te dará algo bonito.\p"
	.string "Eso me han dicho.$"

EcruteakCity_Text_Lass1:
	.string "Voy a practicar en el TEATRO de DANZA.\p"
	.string "¿Vienes conmigo?$"

EcruteakCity_Text_Lass2:
	.string "La torre que había aquí…\p"
	.string "Mi abuela me dijo que antes era mucho\n"
	.string "más alta.\p"
	.string "Dicen que ahora hay fantasmas dentro.$"

EcruteakCity_Text_Lass2_ReleasedBeasts:
	.string "Tres POKéMON muy grandes huyeron en\n"
	.string "direcciones diferentes. ¿Qué estaría\l"
	.string "pasando?$"

EcruteakCity_Text_Fisher:
	.string "He oído un rumor sobre el FARO de C.\n"
	.string "OLIVO.\p"
	.string "El POKéMON que usan como luz ha caído\n"
	.string "enfermo.\p"
	.string "Parece que tienen problemas.$"

EcruteakCity_Text_Fisher_JasmineReturned:
	.string "El POKéMON de FARO OLIVO se ha\n"
	.string "curado.\p"
	.string "Los barcos pueden volver a navegar\n"
	.string "seguros de noche.$"

EcruteakCity_Text_Youngster:
	.string "Los POKéMON están causando estragos\n"
	.string "en el LAGO DE LA FURIA. Me gustaría\l"
	.string "verlo.$"

EcruteakCity_Text_Gramps3:
	.string "Hace mucho, mucho tiempo…\p"
	.string "Esta torre ardió por el fuego. Tres\p"
	.string "POKéMON desconocidos perecieron en\n"
	.string "ella.\p"
	.string "Un POKéMON con los colores del arco\n"
	.string "iris bajó del cielo y los resucitó…\p"
	.string "Es una leyenda que ha ido pasando de\p"
	.string "LÍDER a LÍDER en el GIMNASIO IRIS.\p"
	.string "¿Yo?\p"
	.string "Yo sólo soy un entrenador. ¡Jo, jo, jo!$"

EcruteakCity_Text_SageGym:
	.string "MORTI, el LÍDER del GIMNASIO, no está\n"
	.string "ahora mismo. Puede que lo encuentres\l"
	.string "en la TORRE QUEMADA.$"

EcruteakCity_Text_Sign:
	.string "CIUDAD IRIS Una ciudad donde\n"
	.string "conviven el pasado y el presente$"

EcruteakCity_Text_TinTowerSign:
	.string "TORRE HOJALATA\p"
	.string "Aquí duerme un POKéMON legendario.$"

EcruteakCity_Text_OfficeSign:
	.string "Puesto de control de la TORRE CAMPANA\p"
	.string "Prohibido el paso a los que no sean\n"
	.string "dignos.$"

EcruteakCity_Text_GymSign:
	.string "LÍDER DEL GIMNASIO POKéMON DE\n"
	.string "CIUDAD IRIS: MORTI\p"
	.string "El místico adivino del futuro$"

EcruteakCity_Text_DanceTheaterSign:
	.string "TEATRO DE DANZA DE CIUDAD IRIS$"

EcruteakCity_Text_BurnedTowerSign:
	.string "TORRE QUEMADA\p"
	.string "Destruida por un misterioso incendio\n"
	.string "¡Atención! ¡Peligro!$"
