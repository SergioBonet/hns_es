CeladonCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	.byte 0

CeladonCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CELADON_CITY
	end

CeladonCity_EventScript_LittleGirl::
	msgbox CeladonCity_Text_GotMyKoffingInCinnabar, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1::
	lock
	msgbox CeladonCity_Text_GymIsGreatFullOfWomen
	release
	end

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan2::
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_EventScript_SoftboiledTutor::
	goto EventScript_SoftboiledTutor
	end

CeladonCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
	closemessage
	applymovement LOCALID_CELADON_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath
	closemessage
	waitmoncry
	applymovement LOCALID_CELADON_POLIWRATH, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_RocketGrunt1::
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
	end

CeladonCity_EventScript_RocketGrunt2::
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
	end

CeladonCity_EventScript_Boy::
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
	end

CeladonCity_EventScript_SilphCoScientist::
	msgbox CeladonCity_Text_SomeoneStoleSilphScope, MSGBOX_NPC
	end

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
	end

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_ERIKA, 0
	msgbox CeladonCity_Text_GymSign
	releaseall
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
	end

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_Text_GotMyKoffingInCinnabar::
	.string "Conseguí mi KOFFING en ISLA CANELA.\p"
	.string "Suele ser simpático, pero echa\n"
	.string "veneno cuando se enfada.$"

CeladonCity_Text_GymIsGreatFullOfWomen::
	.string "¡Je, je! ¡Este GIMNASIO es genial!\n"
	.string "¡Está lleno de chicas!$"

CeladonCity_Text_GameCornerIsBadForCitysImage::
	.string "AZULONA se enorgullece de mantener\n"
	.string "la ciudad bonita.\p"
	.string "Por eso el nuevo CASINO es\n"
	.string "malo para la imagen de la ciudad.$"

CeladonCity_Text_BlewItAllAtSlots::
	.string "Ay…\n"
	.string "¡Lo he perdido todo en las tragaperras!\p"
	.string "¡Sabía que debí canjear mis\n"
	.string "FICHAS por premios!$"

CeladonCity_Text_MyTrustedPalPoliwrath::
	.string "Este es mi fiel amigo, POLIWRATH.\p"
	.string "Evolucionó de POLIWHIRL cuando\n"
	.string "usé una PIEDRA AGUA.$"

CeladonCity_Text_Poliwrath::
	.string "POLIWRATH: ¡Ribi ribit!$"

CeladonCity_Text_GetLostOrIllPunchYou::
	.string "¿Qué miras?\n"
	.string "Lárgate o te doy un puñetazo.$"

CeladonCity_Text_KeepOutOfTeamRocketsWay::
	.string "¡No te metas en el camino del\n"
	.string "TEAM ROCKET!$"

CeladonCity_Text_ExplainXAccuracyDireHit::
	.string "PISTAS ENTRENADOR\p"
	.string "PRECISIÓN X aumenta la precisión\n"
	.string "de las técnicas.\p"
	.string "FOCO ENERGÍA aumenta la probabilidad\n"
	.string "de dar golpes críticos.\p"
	.string "¡Consigue los objetos en el\n"
	.string "CENTRO COMERCIAL de AZULONA!$"

CeladonCity_Text_CitySign::
	.string "CIUDAD AZULONA\p"
	.string "La ciudad de los sueños de arco iris$"

CeladonCity_Text_GymSign::
	.string "GIMNASIO POKéMON de CIUDAD AZULONA\n"
	.string "LÍDER: ERIKA\l"
	.string "¡La Princesa Amante de la Naturaleza!$"

CeladonCity_Text_MansionSign::
	.string "MANSIÓN AZULONA$"

CeladonCity_Text_DeptStoreSign::
	.string "¡Compra lo que necesites en el Centro\n"
	.string "Comercial Azulona!$"

CeladonCity_Text_GuardSpecProtectsFromStatus::
	.string "PISTAS ENTRENADOR\p"
	.string "PROTECCIÓN protege a los POKéMON\n"
	.string "de los movimientos que reducen\l"
	.string "estadísticas durante el combate.\p"
	.string "¡Consigue los objetos en el\n"
	.string "CENTRO COMERCIAL de AZULONA!$"

CeladonCity_Text_PrizeExchangeSign::
	.string "¡Se cambian FICHAS por premios!\n"
	.string "CAMBIO DE PREMIOS$"

CeladonCity_Text_GameCornerSign::
	.string "CASINO ROCKET\n"
	.string "¡El paraíso de los adultos!$"

CeladonCity_Text_ScaldedTongueOnTea::
	.string "¡Aaay, ay…\n"
	.string "¡Me he quemado la lengua!\p"
	.string "Una amable anciana de la MANSIÓN\n"
	.string "me ofreció un TÉ.\p"
	.string "¡Pero estaba hirviendo!\n"
	.string "Hay que enfriarlo para beberlo.$"

Text_SoftboiledTeach::
	.string "¡Hola!\p"
	.string "Te he visto por aquí, pero nunca\n"
	.string "tuve ocasión de charlar.\p"
	.string "Debe de ser la buena suerte lo que\n"
	.string "nos ha reunido por fin.\p"
	.string "Para celebrarlo, quiero enseñarte\n"
	.string "el movimiento AMORTIGUADOR.$"

Text_SoftboiledDeclined::
	.string "Siempre estaré pendiente de ti.\p"
	.string "Espero que podamos charlar\n"
	.string "otra vez.$"

Text_SoftboiledWhichMon::
	.string "Entonces, ¿qué POKéMON tendrá la\n"
	.string "oportunidad de aprender AMORTIGUADOR?$"

Text_SoftboiledTaught::
	.string "¡Te deseo mucha suerte!$"

CeladonCity_Text_SomeoneStoleSilphScope::
	.string "Ay, ¿qué voy a hacer…\p"
	.string "Alguien ha robado nuestro SCOPE SILPH.\p"
	.string "El ladrón vino corriendo hacia aquí,\n"
	.string "estoy seguro.\p"
	.string "¡Pero lo perdí de vista!\n"
	.string "¿Adónde habrá ido?$"

