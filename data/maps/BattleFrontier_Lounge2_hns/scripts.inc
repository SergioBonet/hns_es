BattleFrontier_Lounge2_hns_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac_hns::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac_hns
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice_hns
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac_hns::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice_hns
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice_hns::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMulti_hnsLink_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike_hns
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid_hns
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews_hns
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews_hns
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews_hns::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews_hns::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle_hns::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble_hns::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti_hns::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMulti_hnsLink_hns::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid_hns::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3_hns::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF_hns::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro_hns::
	.string "Howdy! When it comes to news about\n"
	.string "the BATTLE FRONTIER, I'm no. 1.\p"
	.string "You can think of me as\n"
	.string "the FRONTIER MANIAC.\p"
	.string "Just checking, but you are a TRAINER,\n"
	.string "isn't that right?\p"
	.string "I'll happily share the hottest news\n"
	.string "I gathered about the BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord_hns::
	.string "Howdy! Did you swing by to grill me\n"
	.string "about the latest word? Oh, all right!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight_hns::
	.string "Well? Well? Well?\p"
	.string "I'm sure my information's been\n"
	.string "seriously useful to you, right?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest_hns::
	.string "Let's see now…\p"
	.string "It sounds like the {STR_VAR_1}\n"
	.string "is the hottest place going.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest_hns::
	.string "Let's see now…\p"
	.string "It sounds like BATTLE TOWER\n"
	.string "{STR_VAR_1} is the hottest.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere_hns::
	.string "¡Seguro que no lo sabías!\p"
	.string "Allí hay una ENTRENADORA\n"
	.string "de esas a las que TRETO denomina\l"
	.string "AS del FRENTE.\p"
	.string "Es la misteriosa DAMA de la TORRE,\n"
	.string "y es la que hace y deshace por allí.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons_hns::
	.string "Have you battled the SALON MAIDEN?\p"
	.string "When she's measuring up her opponent,\n"
	.string "she apparently uses these POKéMON:\p"
	.string "A PSYCHIC-type PSI POKéMON,\n"
	.string "a FIRE-type VOLCANO POKéMON,\l"
	.string "and a NORMAL-type SLEEPING POKéMON.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons_hns::
	.string "¿Te has enfrentado alguna vez\n"
	.string "a la DAMA de la TORRE en serio?\p"
	.string "Cuando pone toda la carne en el asador,\n"
	.string "parece que usa estos POKéMON:\p"
	.string "Un POKéMON EÓN de tipo PSÍQUICO y\n"
	.string "DRAGÓN, un POKéMON TRUENO de tipo\l"
	.string "ELÉCTRICO y un POKéMON DORMIR\l"
	.string "de tipo NORMAL.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere_hns::
	.string "¡Seguro que no lo sabías!\p"
	.string "Allí hay un ENTRENADOR de esos\n"
	.string "que TRETO denomina AS del FRENTE.\p"
	.string "Es el extravagante ASTRO de la CÚPULA\n"
	.string "y es el jefe de allí, vaya.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons_hns::
	.string "Have you battled the DOME ACE?\p"
	.string "When he's treating the opponent\n"
	.string "lightly, he uses these three POKéMON:\p"
	.string "A DRAGON & FLYING DRAGON POKéMON,\n"
	.string "a WATER & GROUND MUD FISH POKéMON,\l"
	.string "and a FIRE & FLYING FLAME POKéMON.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons_hns::
	.string "¿Te has enfrentado alguna vez\n"
	.string "al ASTRO de la CÚPULA en serio?\p"
	.string "Cuando quiere demostrar lo que sabe,\n"
	.string "suele usar estos tres POKéMON:\p"
	.string "Un POKéMON EÓN de tipo DRAGÓN y\n"
	.string "PSÍQUICO, un POKéMON PEZ LODO de tipo\l"
	.string "AGUA y TIERRA, y un POKéMON PATA\l"
	.string "HIERRO de tipo ACERO y PSÍQUICO.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere_hns::
	.string "¡Apuesto a que no lo sabías!\p"
	.string "Allí hay un ENTRENADOR de esos\n"
	.string "que TRETO denomina AS del FRENTE.\p"
	.string "Es un tipo un poco raro, pero la cosa\n"
	.string "es que es el JEFE de la FÁBRICA.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons_hns::
	.string "¿Te has enfrentado alguna vez\n"
	.string "al JEFE de la FÁBRICA?\p"
	.string "Si mal no recuerdo, en combate\n"
	.string "suele alquilar sólo tres POKéMON:\p"
	.string "Suele luchar en igualdad\n"
	.string "de condiciones contra su rival.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons_hns::
	.string "¿Te has enfrentado alguna vez\n"
	.string "al JEFE de la FÁBRICA en serio?\p"
	.string "Aunque el combate vaya en serio,\n"
	.string "sigue alquilando sólo tres POKéMON:\p"
	.string "Siempre lucha en igualdad\n"
	.string "de condiciones contra su rival.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere_hns::
	.string "¡Apuesto a que no lo sabías!\p"
	.string "Allí hay una ENTRENADORA\n"
	.string "de esas a las que TRETO denomina\l"
	.string "AS del FRENTE.\p"
	.string "Da un miedo terrible,\n"
	.string "¡es la REINA de la SIERPE!$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons_hns::
	.string "¿Te has enfrentado alguna vez\n"
	.string "a la REINA de la SIERPE?\p"
	.string "Cuando está de buenas, suele\n"
	.string "usar estos tres POKéMON:\p"
	.string "Un POKéMON COLMILLOS de tipo VENENO,\n"
	.string "un POKéMON MOHO de tipo BICHO y ROCA,\l"
	.string "y un POKéMON TIERNO de tipo AGUA.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons_hns::
	.string "¿Te has enfrentado alguna vez\n"
	.string "a la REINA de la SIERPE en serio?\p"
	.string "Cuando está furiosa de verdad,\n"
	.string "suele usar estos tres POKéMON:\p"
	.string "Un POKéMON COLMILLOS de tipo VENENO,\n"
	.string "un POKéMON SERPFÉRREA de tipo ACERO\l"
	.string "y TIERRA, y un POKéMON ATROCIDAD\l"
	.string "de tipo AGUA y VOLADOR.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere_hns::
	.string "¡Apuesto a que no lo sabías!\p"
	.string "Allí hay una ENTRENADORA\n"
	.string "de esas a las que TRETO denomina\l"
	.string "AS del FRENTE.\p"
	.string "Es una belleza, es la MAESTRA del DOJO.\n"
	.string "Parece que es quien manda allí.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons_hns::
	.string "¿Te has enfrentado alguna vez\n"
	.string "a la MAESTRA del DOJO?\p"
	.string "Cuando está calibrando las fuerzas del\n"
	.string "enemigo, suele usar estos tres POKéMON:\p"
	.string "Un POKéMON UNICORNIO de tipo BICHO\n"
	.string "y LUCHA, un POKéMON LUZ LUNAR\l"
	.string "de tipo SINIESTRO y un POKéMON MUDA\l"
	.string "de tipo BICHO y FANTASMA.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons_hns::
	.string "¿Te has enfrentado alguna vez\n"
	.string "a la MAESTRA del DOJO en serio?\p"
	.string "Cuando da el todo por el todo,\n"
	.string "suele usar estos tres POKéMON:\p"
	.string "Un POKéMON LUZ LUNAR de tipo\n"
	.string "SINIESTRO, un POKéMON SOMBRA de tipo\l"
	.string "FANTASMA y VENENO, y un POKéMON\l"
	.string "HONGO de tipo PLANTA y LUCHA.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere_hns::
	.string "¡Apuesto a que no lo sabías!\p"
	.string "Allí hay un ENTRENADOR de esos\n"
	.string "que TRETO denomina AS del FRENTE.\p"
	.string "Es un ENTRENADOR siniestro llamado\n"
	.string "AMO del PALACIO, y es el que manda allí.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons_hns::
	.string "¿Te has enfrentado alguna vez\n"
	.string "al AMO del PALACIO?\p"
	.string "Cuando quiere poner a prueba al rival,\n"
	.string "dicen que suele usar estos POKéMON:\p"
	.string "Un POKéMON MURCIÉLAGO de tipo VENENO\n"
	.string "y VOLADOR, un POKéMON HOLGAZÁN de\l"
	.string "tipo NORMAL y un POKéMON TRANSPORTE\l"
	.string "de tipo AGUA y HIELO.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons_hns::
	.string "¿Te has enfrentado alguna vez\n"
	.string "al AMO del PALACIO en serio?\p"
	.string "Cuando se la juega de verdad,\n"
	.string "dicen que usa estos POKéMON:\p"
	.string "Un POKéMON LEGENDARIO de tipo FUEGO,\n"
	.string "un POKéMON HOLGAZÁN de tipo NORMAL\l"
	.string "y un POKéMON AURORA de tipo AGUA.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere_hns::
	.string "¡Apuesto a que no lo sabías!\p"
	.string "Allí hay un ENTRENADOR de esos\n"
	.string "que TRETO denomina AS del FRENTE.\p"
	.string "Es el feroz ENTRENADOR al que llaman\n"
	.string "REY de la PIRÁMIDE,\l"
	.string "y allí es como el dueño.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons_hns::
	.string "¿Te has enfrentado alguna vez\n"
	.string "al REY de la PIRÁMIDE?\p"
	.string "Cuando quiere probar al enemigo,\n"
	.string "usa siempre estos POKéMON:\p"
	.string "Un POKéMON PICO ROCA de tipo ROCA,\n"
	.string "un POKéMON ICEBERG de tipo HIELO\l"
	.string "y un POKéMON HIERRO de tipo ACERO.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons_hns::
	.string "¿Te has enfrentado alguna vez\n"
	.string "al REY de la PIRÁMIDE en serio?\p"
	.string "Cuando no se anda con chiquitas,\n"
	.string "usa siempre estos POKéMON:\p"
	.string "Un POKéMON CONGELAR de tipo HIELO\n"
	.string "y VOLADOR, un POKéMON ELÉCTRICO\l"
	.string "de tipo ELÉCTRICO y VOLADOR, y un\l"
	.string "POKéMON LLAMA de tipo FUEGO y VOLADOR.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1_hns::
	.string "Claro, hay varios sitios donde puedes\n"
	.string "enfrentarte en COMBATES DOBLES.\p"
	.string "Pero digamos que lo básico son las\n"
	.string "SALAS BATALLA de COMBATES DOBLES\l"
	.string "de la TORRE BATALLA.\p"
	.string "Es donde se aprende de verdad\n"
	.string "a entablar COMBATES DOBLES\l"
	.string "en el FRENTE de BATALLA.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2_hns::
	.string "Ten cuidado en los combates de aquí.\p"
	.string "He oído que hay ENTRENADORES\n"
	.string "que han creado estrategias sólo\l"
	.string "para los COMBATES DOBLES.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3_hns::
	.string "Cuando creas que dominas los COMBATES\n"
	.string "DOBLES de aquí, podrás pensar en ir\l"
	.string "a otros lugares donde también haya.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice_hns::
	.string "En el SALÓN BATALLA se juntan\n"
	.string "todo tipo de ENTRENADORES.\p"
	.string "¡Piénsalo, igual hasta te encuentras\n"
	.string "con tus amigos o con tus seguidores!\l"
	.string "¡Busca y seguro que encuentras!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice_hns::
	.string "Si estás con un amigo, ve a la\n"
	.string "SALA BATALLA de COMBATES\l"
	.string "MULTIJUGADOR con CONEXIÓN.\p"
	.string "¡Si tu amigo es muy fuerte, prepárate\n"
	.string "para enfrentarte a enemigos muy duros!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower_hns::
	.string "What amazing news-gathering power!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation_hns::
	.string "What amazing powers of observation!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion_hns::
	.string "What amazing power of persuasion!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe_hns::
	.string "…What is this place?\n"
	.string "It's scaring me…$"

