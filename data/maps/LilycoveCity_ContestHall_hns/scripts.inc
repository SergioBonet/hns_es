@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_hns_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1_hns::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2_hns::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl_hns::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor_hns::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1_hns::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1_hns::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear_hns, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest_hns:
	.string "Este POKéMON ya ha ganado\n"
	.string "el CONCURSO de BELLEZA…\p"
	.string "¿Y sabes qué? ¡Hoy ha ganado\n"
	.string "el CONCURSO de INGENIO!\p"
	.string "Soy tan bueno que no me lo creo…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests_hns:
	.string "He entrado en un montón de CONCURSOS\n"
	.string "para ver cómo funciona este tinglado.\p"
	.string "Si estás en un CONCURSO de CARISMA,\n"
	.string "usa movimientos carismáticos para\l"
	.string "ganar más puntos.\p"
	.string "Vamos, que los movimientos ingeniosos\n"
	.string "o dulces no servirán de gran cosa…$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks_hns:
	.string "Ese jovencito que ganó antes tenía\n"
	.string "un buen montón de {POKEBLOCK}S diferentes.\p"
	.string "¿Crees que usando muchas cosas\n"
	.string "de ésas resulta más fácil ganar?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous_hns:
	.string "Guau… Este sitio es gigantesco…\p"
	.string "Se respira tanta tensión… No es en\n"
	.string "absoluto como esas SALAS de CONCURSO\l"
	.string "perdidas en medio de la nada…$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal_hns:
	.string "PRESENTADORA: Muy bien. POKéMON\n"
	.string "ingeniosos y ENTRENADORES\l"
	.string "respectivos, ¿estáis listos?\p"
	.string "¡Dad lo mejor de vosotros!\n"
	.string "¡A exhibirse!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest_hns:
	.string "JUEZ: ¿Te está gustando el CONCURSO?\p"
	.string "Vuelve con tres amigos más y todos\n"
	.string "podréis participar en uno.$"

LilycoveCity_ContestHall_Text_EnteredWrongContest_hns:
	.string "Ay, ay, ay, ay…\n"
	.string "¡Me he equivocado de CONCURSO!\p"
	.string "He apuntado a un POKéMON duro\n"
	.string "a un CONCURSO de INGENIO…\p"
	.string "¡Venga, déjalos patidifusos\n"
	.string "con un ingenioso GOLPE ROCA!$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart_hns:
	.string "Durante años he aplicado todos\n"
	.string "mis conocimientos para entrenar\l"
	.string "un POKéMON ingenioso como él solo.\p"
	.string "Dudo mucho que los POKéMON\n"
	.string "de unos renacuajos puedan superarlo…\p"
	.string "Cariño, ¿ves todo bien desde ahí?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext_hns:
	.string "¡Toma ya!\p"
	.string "¡Si mi POKéMON hace alarde\n"
	.string "de un movimiento ingenioso ahora,\l"
	.string "el público se va a volver loco!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife_hns:
	.string "¡Oh, no!\p"
	.string "El CHUPAVIDAS de mi querido ZUBAT\n"
	.string "es tan guay que lo he usado varias\l"
	.string "veces seguidas…\p"
	.string "¡Pero estos cabezas de chorlito no\n"
	.string "han sabido apreciarlo en absoluto!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa_hns:
	.string "¡Adelante! ¡Amorcito, eres el mejor!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves_hns:
	.string "Aun cuando los ENTRENADORES apuntan\n"
	.string "al mismo tipo de POKéMON, cada uno\l"
	.string "se exhibe con un movimiento distinto.\p"
	.string "Porque, claro, ¡todo el mundo\n"
	.string "tiene su propio estilo de lucha!$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers_hns:
	.string "Creo que esos POKéMON parecen mucho\n"
	.string "más ingeniosos que sus ENTRENADORES.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests_hns:
	.string "Por mucho que venga, estos CONCURSOS\n"
	.string "de INGENIO me siguen encantando.\p"
	.string "Ese color verde es tan… agudo…\n"
	.string "Es tan, tan… intelectual…$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest_hns:
	.string "PRESENTADORA: ¿Tú también participas\n"
	.string "en el CONCURSO de BELLEZA?\l"
	.string "¡Pues suerte!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty_hns:
	.string "JUEZ: Todos los POKéMON que hay aquí\n"
	.string "son un modelo de perfecta belleza.\p"
	.string "¡Huy, en vez de admirarlos tanto,\n"
	.string "debería darles una puntuación!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty_hns:
	.string "Este POKéMON es de una BELLEZA\n"
	.string "sin igual… No tiene rival.\p"
	.string "Sin duda el público se quedará\n"
	.string "admirado al verlo.$"

LilycoveCity_ContestHall_Text_OverdidGrooming_hns:
	.string "¡Aaaaah!\p"
	.string "He peinado y arreglado a mi POKéMON\n"
	.string "especialmente para el CONCURSO…\p"
	.string "Pero me he pasado…\n"
	.string "Y ahora su bonito pelo está todo tieso…\p"
	.string "¡¿Qué puedo hacer?!$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam_hns:
	.string "Este RAYO AURORA es deslumbrante.\n"
	.string "El JUEZ no podrá ni verlo.\p"
	.string "Eh, un momento…\n"
	.string "¡Entonces no servirá de nada!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe_hns:
	.string "Este bonito POKéMON se parece\n"
	.string "a mí cuando era joven, clavadito.\p"
	.string "Pues, cuando se lo dije a mi marido,\n"
	.string "no pudo aguantarse la risa.\p"
	.string "Y, digo yo, ¿dónde está la gracia?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy_hns:
	.string "Yo creo que a cualquiera le hace\n"
	.string "ilusión ganar un CONCURSO\l"
	.string "de BELLEZA, ¿o no?$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon_hns:
	.string "¡Ja, ja, ja!\p"
	.string "¡Mira bien todos esos POKéMON!\n"
	.string "¡Son tan bonitos que deslumbran!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone_hns:
	.string "La belleza natural no basta.\p"
	.string "Hay que potenciarla un poco para\n"
	.string "conseguir una imagen tan estupenda\l"
	.string "como la de mi POKéMON.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest_hns:
	.string "PRESENTADORA: ¡Huy, hola!\n"
	.string "¡Estamos en mitad de un CONCURSO!\p"
	.string "Ve a registrarte primero si quieres\n"
	.string "participar, ¿vale?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals_hns:
	.string "JUEZ: ¡Nunca había visto exhibiciones\n"
	.string "tan dulces y encantadoras como éstas!\p"
	.string "Por ejemplo, ese HIDROCHORRO tan\n"
	.string "adorable merece una gran puntuación.$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted_hns:
	.string "Oh, no, un POKéMON ha distraído\n"
	.string "a mi dulce AZURILL…$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest_hns:
	.string "Mi POKéMON nunca ha vencido luchando,\n"
	.string "¡pero ya verás como gana el CONCURSO!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel_hns:
	.string "La DANZA PÉTALO de mi POKéMON\n"
	.string "es un prodigio de elegancia.\p"
	.string "No dejaré que nadie le moleste\n"
	.string "durante su actuación.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter_hns:
	.string "Todo el mundo piensa que su POKéMON\n"
	.string "es el más dulce de todos.\p"
	.string "Pero yo sé que, cuando el mío haga\n"
	.string "una exhibición de DULZURA…,\p"
	.string "¡se llevará la palma!$"

LilycoveCity_ContestHall_Text_MyChildIsInContest_hns:
	.string "Mi hijo está participando\n"
	.string "en el CONCURSO.$"

LilycoveCity_ContestHall_Text_ComeOnDear_hns:
	.string "¡Adelante, cariño!\n"
	.string "¡Tu POKéMON es el mejor!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest_hns:
	.string "Creo que esa chica de ahí\n"
	.string "es la más dulce de toda la sala.\p"
	.string "¿Cómo? ¿Que compiten los POKéMON,\n"
	.string "no sus ENTRENADORES?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn_hns:
	.string "Oooooh, al ver a esos POKéMON tan\n"
	.string "dulces, me entran ganas de tener uno…\p"
	.string "¡Me voy a atrapar unos cuantos!$"

LilycoveCity_ContestHall_Text_BeautyContestStage_hns:
	.string "ESCENARIO del CONCURSO de BELLEZA\n"
	.string "¡LOS POKéMON MÁS GUAPOS!$"

LilycoveCity_ContestHall_Text_CuteContestStage_hns:
	.string "ESCENARIO del CONCURSO de DULZURA\n"
	.string "¡LOS POKéMON MÁS ACHUCHABLES!$"

LilycoveCity_ContestHall_Text_SmartContestStage_hns:
	.string "ESCENARIO del CONCURSO de INGENIO\n"
	.string "¡LOS POKéMON MÁS LISTOS!$"

