GoldenrodCity_hns_MapScripts::
	.byte 0

GoldenrodCity_EventScript_Trigger:: @flagheap
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
	setflag FLAG_VISITED_GOLDENROD_CITY
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_BILL
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	
	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_GOT_RETURN
	clearflag FLAG_GOT_FRUSTRATION
	clearflag FLAG_RECEIVED_BIKE
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
	clearflag FLAG_GOT_EEVEE
	clearflag FLAG_SYS_PC_BILL
	clearflag FLAG_RETURNED_MACHINE_PART
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	clearflag FLAG_GOLDENROD_MACHOKE_1
	clearflag FLAG_GOLDENROD_MACHOKE_2
	clearflag FLAG_GOLDENROD_MACHOKE_3
	clearflag FLAG_COMPLETED_SWITCHES
	clearflag FLAG_ENABLE_RADIO
	clearflag FLAG_KANTO_RADIO_GOT
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	clearflag FLAG_GOT_SUNNY_DAY
	clearflag FLAG_HIDE_RADIOTOWER_GATE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
	clearflag FLAG_GOT_QUICK_CLAW
	clearflag FLAG_GOT_MAGNET

	setvar VAR_BUG_CONTEST_STATE, 0
	setvar VAR_KENYA, 0
	setvar VAR_LUGIA_OR_HOOH, 0
	setvar VAR_TRAIN, 0
	setvar VAR_ELEVATOR, 0
	setvar VAR_GOLDENROD_CITY_STATE, 1
	release
	end

GoldenrodCity_Trigger_Music::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	fadenewbgm MUS_HG_ROCKET_TAKEOVER
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1 
	end

GoldenrodCity_Trigger_Music2::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	fadedefaultbgm
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Trigger_MusicNotYet::
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Elm_Togepi_Call::
	lock
	setspeaker GoldenrodCity_Text_ElmName
	pokenavcall GoldenrodCity_Text_ElmCall
	waitmessage
	delay 30
	release
	return

GoldenrodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Youngster::
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Youngster2::
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_CooltrainerFCleared::
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RocketScout::
	lock
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROCKET_SCOUT
	faceplayer
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
	release
	end

GoldenrodCity_EventScript_Rocket1::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket2::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket3::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket4::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket5::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket6::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Woman::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker2::
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Snubbull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_Mime::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_SignUnderground::
	lock
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignDept::
	lock
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignBike::
	lock
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignTrain::
	lock
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGym::
	lock
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignFlower::
	lock
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignRadio::
	lock
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGameCorner::
	lock
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Text_Beauty:
	.string "¡Este es el GIMNASIO de CIUDAD\n"
	.string "TRIGAL!\p"
	.string "Nuestra LÍDER, BLANCA, no está ahora\n"
	.string "mismo. Puede que esté en la ESTACIÓN\l"
	.string "DE RADIO.$"

GoldenrodCity_Text_Woman:
	.string "Antes entrenaba en el GIMNASIO de\n"
	.string "BLANCA, pero tanto llanto me daba\l"
	.string "dolor de cabeza.$"

GoldenrodCity_Text_HikerDay:
	.string "Cuando entré en el CASINO era de\n"
	.string "noche… ¿¡Cuánto tiempo he estado ahí\l"
	.string "dentro!?$"

GoldenrodCity_Text_HikerNight:
	.string "Cuando entré en el CASINO era de día…\n"
	.string "¿¡Cuánto tiempo he estado ahí\l"
	.string "dentro!?$"

GoldenrodCity_Text_Snubbull:
	.string "SNUBBULL: ¡SNUUUBUUUULL!$"

GoldenrodCity_Text_MrMime:
	.string "……$"

GoldenrodCity_Text_ElmName:
	.string "PROF. ELM$"

GoldenrodCity_Text_ElmCall:
	.string "PROF. ELM: Hola, ¿{PLAYER}? ¿Ha\n"
	.string "eclosionado ya ese HUEVO?\p"
	.string "Cuando eclosione, ¡no te olvides de\n"
	.string "traerlo al laboratorio! ¡Tengo que\l"
	.string "verlo!$"

GoldenrodCity_Text_PokefanM:
	.string "Construyeron la nueva ESTACIÓN DE\n"
	.string "RADIO para sustituir a la vieja, que\l"
	.string "estaba hecha polvo.$"

GoldenrodCity_Text_Youngster1:
	.string "Sé que hay una nueva TIENDA DE\p"
	.string "BICIS, pero no la encuentro.$"

GoldenrodCity_Text_CooltrainerF1:
	.string "¿Ese hombre de negro se ha vestido\n"
	.string "como uno del TEAM ROCKET? ¡Qué tonto!$"

GoldenrodCity_Text_CooltrainerF1_Cleared:
	.string "¿Pertenecía ese hombre de negro al\p"
	.string "TEAM ROCKET? ¡Es increíble!$"

GoldenrodCity_Text_CooltrainerF2:
	.string "La ESTACIÓN DE RADIO de CIUDAD\n"
	.string "TRIGAL es todo un emblema.\p"
	.string "Ahora tienen una campaña.\p"
	.string "Si superas su concurso de preguntas,\n"
	.string "te regalan una RADIO nueva y\l"
	.string "reluciente.$"

GoldenrodCity_Text_CooltrainerF2_GotCard:
	.string "¡Oh, tu POKéGEAR ya funciona como\n"
	.string "radio!$"

GoldenrodCity_Text_Youngster2:
	.string "Jejeje…\p"
	.string "Me metí en un lío por jugar en el\n"
	.string "sótano del CENTRO COMERCIAL.$"

GoldenrodCity_Text_Lass:
	.string "Ese hombre de ahí dentro valora los\n"
	.string "motes de los POKéMON.\p"
	.string "Y hasta puede cambiarlos.$"

GoldenrodCity_Text_Gramps:
	.string "¡Uf! Esta ciudad es tan grande que no\n"
	.string "encuentro nada.$"

GoldenrodCity_Text_RocketScout1:
	.string "Así que ésta es la TORRE RADIO…$"

GoldenrodCity_Text_RocketScout2:
	.string "¿Qué quieres, pesado? ¡Largo de aquí!$"

GoldenrodCity_Text_Rocket1:
	.string "¡No estorbes! ¡Esfúmate, chaval!$"

GoldenrodCity_Text_Rocket2:
	.string "Asaltaremos la Torre RADIO y…\p"
	.string "¿Qué? ¡Aquí no se te ha perdido nada!$"

GoldenrodCity_Text_Rocket3:
	.string "¿POKéMON? ¡Solo son herramientas\n"
	.string "para ganar dinero!$"

GoldenrodCity_Text_Rocket4:
	.string "Nuestro sueño pronto se hará\n"
	.string "realidad…\p"
	.string "Ha sido una lucha larga y dura…$"

GoldenrodCity_Text_Rocket5:
	.string "¡Eh, mocoso! ¡Tú no pintas nada aquí!\n"
	.string "¡Piérdete!$"

GoldenrodCity_Text_Rocket6:
	.string "¡Ven a probar el terror del TEAM\n"
	.string "ROCKET!$"

GoldenrodCity_Text_StationSign:
	.string "ESTACIÓN DE CIUDAD TRIGAL$"

GoldenrodCity_Text_RadioTowerSign:
	.string "TORRE RADIO DE CIUDAD TRIGAL$"

GoldenrodCity_Text_DeptStoreSign:
	.string "¡Una gran gama de artículos POKéMON!\p"
	.string "CENTRO COMERCIAL DE CIUDAD TRIGAL$"

GoldenrodCity_Text_GymSign:
	.string "LÍDER DEL GIMNASIO POKéMON DE\n"
	.string "CIUDAD TRIGAL: BLANCA\p"
	.string "¡La increíble y bella señorita!$"

GoldenrodCity_Text_CitySign:
	.string "CIUDAD TRIGAL\p"
	.string "La alegre ciudad de rico encanto$"

GoldenrodCity_Text_BikeShopSign:
	.string "¡El mundo es un camino de bicis!\n"
	.string "TIENDA DE BICIS$"

GoldenrodCity_Text_GameCornerSign:
	.string "¡Tu zona de juego!\p"
	.string "CASINO DE CIUDAD TRIGAL$"

GoldenrodCity_Text_NameRaterSign:
	.string "INSPECTOR DE MOTES\p"
	.string "Evalúa los motes de tus POKéMON$"

GoldenrodCity_Text_UndergroundNorthSign:
	.string "ENTRADA SUBTERRÁNEA$"

GoldenrodCity_Text_UndergroundSouthSign:
	.string "ENTRADA SUBTERRÁNEA$"


GoldenrodCity_Text_FlowerShopSign:
	.string "Un bello florecer FLORISTERÍA$"

GoldenrodCity_Text_MoveTutorAsk:
	.string "¡Puedo enseñarles movimientos\n"
	.string "increíbles a tus POKéMON!\p"
	.string "¿Les enseño uno?$"

GoldenrodCity_Text_MoveTutorCost:
	.string "Te costará 1000 fichas. ¿Vale?$"

GoldenrodCity_Text_MoveTutorDecline:
	.string "Vaya… ¡Pero si estos movimientos son\n"
	.string "geniales!$"

GoldenrodCity_Text_MoveTutorWhich:
	.string "¡Uajajaja! ¡No lo lamentarás!\p"
	.string "¿Qué movimiento debo enseñar?$"

GoldenrodCity_Text_MoveTutorNoCash:
	.string "Qué pena. Tendré que sacar dinero de\n"
	.string "casa…$"

GoldenrodCity_Text_MoveTutorUnderstand:
	.string "Si entiendes este movimiento, eres\n"
	.string "todo un ENTRENADOR.$"

GoldenrodCity_Text_MoveTutorFarewell:
	.string "¡Uajajaja! ¡Adiós!$"

GoldenrodCity_Text_MoveTutorBut:
	.string "Pe… Pero…$"

GoldenrodCity_Text_MoveTutorNotEnoughCoins:
	.string "… No tienes suficientes fichas…$"
