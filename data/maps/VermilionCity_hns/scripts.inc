VermilionCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

VermilionCity_MapScript_OnTransition::
	setflag FLAG_VISITED_VERMILION_CITY
	goto_if_eq VAR_SUICUNE_ENCOUNTERS, 3, VermilionCity_EventScript_SetSuicuneScene
	setflag FLAG_HIDE_VERMILION_EUSINE_SUICUNE
	callnative SetTimeBasedEncounters
	end

VermilionCity_EventScript_SetSuicuneScene::
	clearflag FLAG_HIDE_VERMILION_EUSINE_SUICUNE
	callnative SetTimeBasedEncounters
	end

VermilionCity_EventScript_OldSeaMap::
	finditem ITEM_OLD_SEA_MAP
	end

VermilionCity_TriggerSuicuneNorth_Left::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto VermilionCity_TriggerSuicuneNorth_Merge
VermilionCity_TriggerSuicuneNorth_Mid::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto VermilionCity_TriggerSuicuneNorth_Merge
VermilionCity_TriggerSuicuneNorth_Right::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_TriggerSuicuneNorth_Merge
VermilionCity_TriggerSuicuneNorth_Merge::
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_NorthSuicune_PlayerWalkDown
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_NorthSuicune_PlayerWalkDown
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode

VermilionCity_Movement_NorthSuicune_PlayerWalkDown:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VermilionCity_TriggerSuicuneTop::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerWalkToRailTop
	delay 60
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode
VermilionCity_TriggerSuicuneMid::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerWalkToRailMid
	delay 60
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode
VermilionCity_TriggerSuicuneBot::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerWalkToRailBot
	waitmovement 0
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode

VermilionCity_EventScript_SuicuneEpisode::
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_SuicuneLeave
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	msgbox VermilionCity_Text_Eusine, MSGBOX_DEFAULT
	turnobject LOCALID_VERMILION_EUSINE, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox VermilionCity_Text_Eusine2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineLeave
	waitmovement 0
	removeobject LOCALID_VERMILION_EUSINE
	removeobject LOCALID_VERMILION_SUICUNE
	setflag FLAG_HIDE_VERMILION_EUSINE_SUICUNE

	setvar VAR_SUICUNE_ENCOUNTERS, 4
	clearflag FLAG_HIDE_ROUTE14_SUICUNE
	release
	end

VermilionCity_EventScript_Teacher::
	msgbox VermilionCity_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_EventScript_Oldman::
	msgbox VermilionCity_Text_MachopOwner, MSGBOX_NPC
	end

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop1, MSGBOX_DEFAULT
	waitmoncry
	msgbox VermilionCity_Text_Machop2, MSGBOX_DEFAULT
	release
	end

VermilionCity_EventScript_Nerd::
	msgbox VermilionCity_Text_SuperNerd, MSGBOX_NPC
	end

VermilionCity_EventScript_Snorlax::
	lock
	special CheckRadioStation
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_SnorlaxWakeUp
	@goto_if_set FLAG_KANTO_RADIO_GOT, VermilionCity_EventScript_SnorlaxWakeUp
	msgbox VermilionCity_Text_SnorlaxSleeping, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_EventScript_SnorlaxWakeUp::
    playbgm MUS_HG_RADIO_POKE_FLUTE, FALSE
    msgbox VermilionCity_Text_RadioNearSnorlax, MSGBOX_DEFAULT
    playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
    delay 40
    waitmoncry
    setwildbattle SPECIES_SNORLAX, 50
    dowildbattle
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VermilionCity_EventScript_SnorlaxRan
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject LOCALID_VERMILION_SNORLAX
    removeobject 8
    removeobject 9
    removeobject 10
    removeobject 11
    setflag FLAG_HIDE_VERMILION_SNORLAX
    fadescreenswapbuffers FADE_FROM_BLACK
    setflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD
    fadedefaultbgm
    release
    end

VermilionCity_EventScript_SnorlaxRan::
    fadedefaultbgm
    release
    end

VermilionCity_EventScript_BadgeGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_VERMILION_HP_UP, VermilionCity_EventScript_BadgeGuyAfter
	goto_if_ge VAR_NUM_BADGES, 16, VermilionCity_EventScript_BadgeGuyAll
	goto_if_ge VAR_NUM_BADGES, 12, VermilionCity_EventScript_BadgeGuyMost
	goto_if_ge VAR_NUM_BADGES, 9, VermilionCity_EventScript_BadgeGuySome
	msgbox VermilionCity_Text_BadgeGuy_Trainer, MSGBOX_DEFAULT
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuySome::
	msgbox VermilionCity_Text_BadgeGuy_SomeBadges, MSGBOX_DEFAULT
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuyMost::
	msgbox VermilionCity_Text_BadgeGuy_MostBadges, MSGBOX_DEFAULT
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuyAll::
	msgbox VermilionCity_Text_BadgeGuy_AllBadges, MSGBOX_DEFAULT
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_VERMILION_HP_UP
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuyAfter::
	msgbox VermilionCity_Text_BadgeGuy_BattleEdge, MSGBOX_DEFAULT
	closemessage
	release
	end


VermilionCity_Movement_Suicune1:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end

VermilionCity_Movement_PlayerWalkToRailTop: @goal tile = 51, 28
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	step_end
VermilionCity_Movement_PlayerWalkToRailMid:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	step_end
VermilionCity_Movement_PlayerWalkToRailBot:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

VermilionCity_Movement_EusineWalkToRail:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	step_end

VermilionCity_Movement_SuicuneLeave:
	jump_in_place_left
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

VermilionCity_Movement_EusineLeave:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

VermilionCity_Text_Eusine:
	.string "EUSINE: ¡Por los pelos! Creía que\n"
	.string "podría acorralarlo tendiéndole una\l"
	.string "emboscada aquí.\p"
	.string "Pero eso de correr sobre el agua me\n"
	.string "supera.\p"
	.string "Aun así, empiezo a ver un patrón.\p"
	.string "¡A SUICUNE le gusta el agua!\p"
	.string "Eso significa que…$"

VermilionCity_Text_Eusine2:
	.string "¡Lo siento, {PLAYER}, tengo que irme!$"

VermilionCity_Text_Teacher:
	.string "CIUDAD CARMÍN es el puerto más\n"
	.string "importante de KANTO.\p"
	.string "En él atracan lujosos transatlánticos\n"
	.string "de todo el mundo.$"

VermilionCity_Text_MachopOwner:
	.string "Mi POKéMON está preparando el terreno\n"
	.string "donde edificar.\p"
	.string "Pero no tengo dinero para el\n"
	.string "proyecto…$"

VermilionCity_Text_Machop1:
	.string "MACHOP: ¡Machop, machop!$"

VermilionCity_Text_Machop2:
	.string "Un MACHOP gruñe mientras pisotea el\n"
	.string "suelo.$"

VermilionCity_Text_SuperNerd:
	.string "En KANTO hay ocho GIMNASIOS.\p"
	.string "Ese gran edificio es el GIMNASIO\p"
	.string "POKéMON de CIUDAD CARMÍN.$"

VermilionCity_Text_SnorlaxSleeping:
	.string "SNORLAX duerme plácidamente…$"

VermilionCity_Text_RadioNearSnorlax:
	.string "El POKéGEAR está cerca del SNORLAX\n"
	.string "dormido.\p"
	.string "…\p"
	.string "¡SNORLAX se despertó!$"

VermilionCity_Text_BadgeGuy_Trainer:
	.string "Los entrenadores expertos se reúnen\n"
	.string "en KANTO.\p"
	.string "Los LÍDERES de GIMNASIO son muy\n"
	.string "fuertes.\p"
	.string "No serán fáciles de vencer.$"

VermilionCity_Text_BadgeGuy_SomeBadges:
	.string "¿Has conseguido ya alguna MEDALLA de\n"
	.string "GIMNASIO de KANTO?\p"
	.string "¿A que los entrenadores de\p"
	.string "KANTO son muy fuertes?$"

VermilionCity_Text_BadgeGuy_MostBadges:
	.string "Supongo que pronto habrás conseguido\n"
	.string "todas las MEDALLAS de KANTO.\p"
	.string "Cuando tengas las ocho MEDALLAS,\n"
	.string "dímelo.$"

VermilionCity_Text_BadgeGuy_AllBadges:
	.string "¡Enhorabuena!\p"
	.string "Tienes todas las MEDALLAS de KANTO.\p"
	.string "Te recompensaré por tu esfuerzo.$"

VermilionCity_Text_BadgeGuy_BattleEdge:
	.string "Llevar distintos tipos de POKéMON\p"
	.string "te debería ayudar en el combate.\p"
	.string "Seguro que las MEDALLAS de KANTO te\n"
	.string "ayudarán.$"

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_Sign, MSGBOX_SIGN
	end
VermilionCity_EventScript_GymSign::
	msgbox VermilionCity_Text_GymSign, MSGBOX_SIGN
	end
VermilionCity_EventScript_FanClubSign::
	msgbox VermilionCity_Text_FanClubSign, MSGBOX_SIGN
	end
VermilionCity_EventScript_DiglettsCaveSign::
	msgbox VermilionCity_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

VermilionCity_Text_Sign:
	.string "CIUDAD CARMÍN\p"
	.string "El puerto de los ocasos exquisitos$"

VermilionCity_Text_GymSign:
	.string "LÍDER DEL GIMNASIO POKéMON DE\n"
	.string "CIUDAD CARMÍN: LT. SURGE\p"
	.string "El rayo americano$"

VermilionCity_Text_FanClubSign:
	.string "CLUB DE FANS DE POKéMON ¡Bienvenidos!$"

VermilionCity_Text_DiglettsCaveSign:
	.string "CUEVA DIGLETT$"

VermilionCity_Text_PortSign:
	.string "ENTRADA AL PUERTO CARMÍN$"

VermilionCity_EventScript_TriggerStevenLeft::
	lock
	playse SE_PIN
	applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkLeft1
	waitmovement 0
	call VermilionCity_EventScript_LatiChoice
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, VermilionCity_Movement_StevenWalkToPlayer
	waitmovement 0
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkDown1
	waitmovement 0
	setvar VAR_VERMILION_CITY_STEVEN, 1
	removeobject LOCALID_VERMILIONCITY_STEVEN
	release
	end

VermilionCity_EventScript_TriggerStevenMiddle::
	lock
	playse SE_PIN
	applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	call VermilionCity_EventScript_LatiChoice
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, VermilionCity_Movement_StevenWalkToPlayer
	waitmovement 0
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkDown1
	waitmovement 0
	setvar VAR_VERMILION_CITY_STEVEN, 1
	removeobject LOCALID_VERMILIONCITY_STEVEN
	release
	end
 
VermilionCity_EventScript_TriggerStevenRight::
	lock
	playse SE_PIN
	applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkRight1
	waitmovement 0
	call VermilionCity_EventScript_LatiChoice
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, VermilionCity_Movement_StevenWalkToPlayer
	waitmovement 0
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, Common_Movement_WalkDown1
	waitmovement 0
	setvar VAR_VERMILION_CITY_STEVEN, 1
	removeobject LOCALID_VERMILIONCITY_STEVEN
	release
	end


VermilionCity_EventScript_LatiChoice::
	applymovement2 LOCALID_VERMILIONCITY_STEVEN, VermilionCity_Movement_StevenWalkToPlayer
	waitmovement LOCALID_VERMILIONCITY_STEVEN
	msgbox VermilionCity_Text_StevenIntro, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_TV_LATI, TRUE
	@goto_if_eq VAR_RESULT, MULTI_B_PRESSED, VermilionCity_EventScript_LatiCancel
	copyvar VAR_0x8004, VAR_RESULT
	copyvar VAR_ROAMER_POKEMON_HNS, VAR_RESULT
	special InitKantoRoamers
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	msgbox VermilionCity_Text_StevenOutro, MSGBOX_DEFAULT
	closemessage
	return

VermilionCity_Movement_StevenWalkToPlayer:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	step_end

VermilionCity_Text_StevenIntro:
	.string "¡Hola! Me llamo MÁXIMO. Soy el CAMPEÓN\n"
	.string "de la región de HOENN.\p"
	.string "¿Nos hemos visto… antes?\p"
	.string "No es posible. De todas formas, todos\n"
	.string "los ENTRENADORES con los que he\l"
	.string "luchado parecen tener la misma mirada.\p"
	.string "Sobre todo los que me han puesto las\n"
	.string "cosas difíciles.\p"
	.string "He venido a KANTO por negocios.\n"
	.string "Últimamente, muchos POKéMON de HOENN\l"
	.string "han migrado a esta región. Esta\l"
	.string "afluencia amenaza con alterar el\l"
	.string "ecosistema natural de aquí.\p"
	.string "Así que, con la ayuda de mi empresa,\n"
	.string "estoy creando un hábitat especial\l"
	.string "para atraer y contener a las especies\l"
	.string "más invasoras.\p"
	.string "Estate atento y atrapa todos los\n"
	.string "POKéMON de HOENN que veas.\p"
	.string "Algunos ENTRENADORES incluso han\n"
	.string "visto uno que surca el cielo como un\l"
	.string "avión… ¿De qué color era?$"

VermilionCity_Text_StevenOutro:
	.string "Ah, claro.\p"
	.string "Tengo que irme. Ojalá nuestros\n"
	.string "caminos vuelvan a cruzarse.$"

VermilionCity_EventScript_TriggerSamson::
	lock
	clearflag FLAG_HIDE_VERMILION_CITY_SAMSON
	addobject LOCALID_VERMILION_CITY_SAMSON
	playse SE_BANG
	applymovement LOCALID_VERMILION_CITY_SAMSON, VermilionCity_Movement_SamsonEnter
	applymovement LOCALID_PLAYER, VermilionCity_Movement_PlayerSlideback
	waitmovement LOCALID_VERMILION_CITY_SAMSON
	waitmovement LOCALID_PLAYER
	msgbox VermilionCity_Text_Samson, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VERMILION_CITY_SAMSON, VermilionCity_Movement_SamsonLeave
	waitmovement LOCALID_VERMILION_CITY_SAMSON
	removeobject LOCALID_VERMILION_CITY_SAMSON
	setflag FLAG_HIDE_VERMILION_CITY_SAMSON
	setvar VAR_VERMILION_CITY_SAMSON, 2
	release
	end

VermilionCity_Movement_PlayerSlideback:
	lock_facing_direction
	walk_fast_down
	walk_fast_down
	unlock_facing_direction
	step_end

VermilionCity_Movement_SamsonEnter:
	walk_fast_down
	walk_fast_down
	step_end

VermilionCity_Movement_SamsonLeave:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

VermilionCity_Text_Samson:
	.string "¡Uau!\p"
	.string "¡Lo siento, chaval, tengo prisa!\p"
	.string "El ferry de la RUTA 13 está a punto de\n"
	.string "salir hacia las ISLAS, ¡y tengo que\l"
	.string "estar a bordo!\p"
	.string "Uf… Uf…\p"
	.string "He venido corriendo desde el MT. MOON.\p"
	.string "¿Ves esta chuchería?\p"
	.string "Compré esta ESTATUILLA RARA en la\n"
	.string "TIENDA de RECUERDOS.\p"
	.string "Es mi billete para las ISLAS.\p"
	.string "¡Bueno, hasta luego!$"
