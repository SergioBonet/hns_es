SafariZone_EventScript_OutOfBallsMidBattle::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3
#elif IS_HNS
	setvar VAR_SAFARI_ZONE_STATE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#elif IS_HNS
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKantoMidBattle
	setwarp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS, 9, 3
#else
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	end

SafariZone_EventScript_ExitKantoMidBattle::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_HNS, 5, 6
	end

SafariZone_EventScript_Exit::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1
#elif IS_HNS
	setvar VAR_SAFARI_ZONE_STATE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#elif IS_HNS
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKanto
	warp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS, 9, 3
#else
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	waitstate
	end

SafariZone_EventScript_ExitKanto::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_HNS, 5, 6
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockGone::
	lockall
	message SafariZone_Text_PokeblockGone
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_PokeblockGone:
	.string "¡Se han comido todo el {STR_VAR_1}!$"

SafariZone_Text_WouldYouLikeToExit:
	.string "¿Quieres salir ahora mismo de la ZONA\n"
	.string "SAFARI?$"

SafariZone_Text_TimesUp:
	.string "¡Tilín, tilín!\p"
	.string "¡Se acabó el tiempo! El Safari ha\n"
	.string "terminado.\p"
	.string "$"

SafariZone_Text_OutOfBalls:
	.string "Te has quedado sin SAFARI BALLS. Tu\n"
	.string "Juego Safari ha terminado.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "¿Quieres poner un {POKEBLOCK} en el\n"
	.string "COMEDERO de {POKEBLOCK}S?$"

SafariZone_Text_PokeblockStillHere:
	.string "El {STR_VAR_1} que dejaste antes\n"
	.string "sigue aquí.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "Has puesto el {STR_VAR_1} en el\n"
	.string "COMEDERO de {POKEBLOCK}S.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "¡Bienvenido a la ZONA SAFARI!\p"
	.string "Aquí podrás ver muchas clases de\n"
	.string "POKéMON que rara vez se ven en esta\l"
	.string "región.\p"
	.string "Y los verás en estado salvaje, en sus\n"
	.string "hábitats naturales.\p"
	.string "Además, hemos abierto las puertas a\n"
	.string "los ENTRENADORES POKéMON.\p"
	.string "¡Te animamos a atrapar POKéMON para\n"
	.string "quedártelos!\p"
	.string "¡Pasa y disfruta de la ZONA SAFARI!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "¡Bienvenido a la ZONA SAFARI! ¿Es tu\n"
	.string "primera vez aquí?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "¡Pasa y disfruta de la ZONA SAFARI!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Al entrar en la ZONA SAFARI, empiezas\n"
	.string "con 30 SAFARI BALLS para atrapar\l"
	.string "POKéMON.\p"
	.string "El Juego Safari termina cuando te\n"
	.string "quedas sin SAFARI BALLS o cuando has\l"
	.string "dado 500 pasos.\p"
	.string "¡Pasa y disfruta de la ZONA SAFARI!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "¡Hola! ¡Ésta es la ZONA SAFARI!\p"
	.string "¡Atrapa todo lo que puedas por sólo\n"
	.string "500¥! ¿Quieres jugar una partida\l"
	.string "SAFARI?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "No hay problema.\n"
	.string "Ven cuando quieras.$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Lo siento, no tienes bastante dinero.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Son 500¥, por favor.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Toma Safari Balls.\p"
	.string "$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} recibió 30 SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Te avisaremos cuando se termine\n"
	.string "la partida.\p"
	.string "Hasta entonces, pásatelo bien.\n"
	.string "¡La aventura ha comenzado!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Lo siento, pero todas las CAJAS\n"
	.string "de tu PC están llenas.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Disculpa.\n"
	.string "Parece que no tienes un {POKEBLOCK} CASE.\p"
	.string "Tu juego SAFARI será mucho más\n"
	.string "fructífero si usas {POKEBLOCK}S.\p"
	.string "Vuelve con un {POKEBLOCK} CASE.\p"
	.string "Puedes conseguir un {POKEBLOCK} CASE de\n"
#if IS_HNS
	.string "ese chico de ahí.$"
#else
	.string "la SALA DE CONCURSOS de LILYCOVE.$"
#endif

SafariZone_South_Text_StillHaveTimeExit:
	.string "Aún te queda tiempo. ¿Quieres salir\n"
	.string "ahora de la ZONA SAFARI?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "¡Disfruta del resto de tu aventura\n"
	.string "salvaje!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Muy bien.\p"
	.string "Me quedaré con las SAFARI BALLS\n"
	.string "que te sobran.\p"
	.string "Gracias por jugar con nosotros.\n"
	.string "Vuelve siempre que quieras.$"

SafariZone_South_Text_GoodLuck:
	.string "¡Buena suerte!\p"
	.string "Si necesitas algo, ¡no dudes en\n"
	.string "decírmelo!$"

SafariZone_South_Text_Boy:
	.string "¿Sabías que…?\p"
	.string "Si pones un {POKEBLOCK} en esa caja\n"
	.string "cuadrada, los POKéMON se acercan.$"

SafariZone_South_Text_Man:
	.string "Quiero adentrarme más, pero se me ha\n"
	.string "olvidado traer una BICI.\p"
	.string "Algo me dice que en las zonas más\n"
	.string "apartadas viven POKéMON raros.$"

SafariZone_Southwest_Text_Woman:
	.string "A veces, cuando les lanzo un {POKEBLOCK} a\n"
	.string "los POKéMON, no me hacen caso.\p"
	.string "¿Tendrán los POKéMON gustos con la\n"
	.string "comida?$"

SafariZone_Northwest_Text_Man:
	.string "Uf… Uf… He… llegado hasta aquí… pero…\p"
	.string "Estoy agotado… No tengo energía para\n"
	.string "atrapar POKéMON…$"

SafariZone_North_Text_Fisherman:
	.string "Estoy en una misión para encontrar\n"
	.string "POKéMON de AGUA que no se ven en\l"
	.string "HOENN.\p"
	.string "¿Sabes dónde está el lago?$"

SafariZone_North_Text_Man:
	.string "¡Voy a atrapar un montón de POKéMON\n"
	.string "raros aquí y a cambiárselos a mis\l"
	.string "amigos!$"

SafariZone_South_Text_Youngster:
	.string "Puse un {POKEBLOCK} en el COMEDERO de\n"
	.string "{POKEBLOCK}S. Pero parece que ha\l"
	.string "desaparecido.\p"
	.string "Supongo que se lo habrán comido los\n"
	.string "POKéMON sin que me diera cuenta.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "¡PISTA de la ZONA SAFARI para\n"
	.string "ENTRENADORES!\p"
	.string "Lanza {POKEBLOCK}S a los POKéMON salvajes\n"
	.string "para que sea menos probable que\l"
	.string "huyan.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Descansa tus pies cansados.”\n"
	.string "CASA DE DESCANSO$"

SafariZone_RestHouse_Text_Youngster:
	.string "No tengo {POKEBLOCK}S, pero he atrapado\n"
	.string "bastantes POKéMON.\p"
	.string "Puedes aumentar tus posibilidades de\n"
	.string "atraparlos si te acercas a ellos antes\l"
	.string "de lanzar una SAFARI BALL.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Si usas {POKEBLOCK}S, los POKéMON salvajes\n"
	.string "no huirán tan rápido.\p"
	.string "No sirve de mucho dar {POKEBLOCK}S a los\n"
	.string "POKéMON que no huyen fácilmente.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Si pones un {POKEBLOCK} en el COMEDERO,\n"
	.string "atrae a los POKéMON.\p"
	.string "Creo que los POKéMON con una\n"
	.string "naturaleza parecida se sienten\l"
	.string "atraídos por cierto tipo de {POKEBLOCK}.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Esta zona todavía está en obras. Lo\n"
	.string "siento, ¡prohibido el paso!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "El proyecto de ampliación de la ZONA\n"
	.string "SAFARI ya ha terminado.\p"
	.string "Esperamos que disfrutes de la nueva\n"
	.string "zona.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Esta zona todavía está en obras. Lo\n"
	.string "siento, ¡prohibido el paso!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "¡Uau! ¡Yupi! ¡No había visto nunca\n"
	.string "ninguno de estos POKéMON!$"

SafariZone_Southeast_Text_FatMan:
	.string "Todos los POKéMON de esta zona son\n"
	.string "nuevos para mí.\p"
	.string "¡Y me dejan atrapar estos POKéMON tan\n"
	.string "raros! ¡Qué guay!$"

SafariZone_Southeast_Text_RichBoy:
	.string "Parece que los POKéMON de por aquí\n"
	.string "son de un lugar que no es HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "Solo me quedan un par de SAFARI\n"
	.string "BALLS.\p"
	.string "Me cuesta mucho decidir qué atrapar.$"

SafariZone_Northeast_Text_Woman:
	.string "He oído que aquí se puede ver a\n"
	.string "PIKACHU. ¿Dónde estará?$"

SafariZone_Northeast_Text_Girl:
	.string "¡Uf, qué rabia! ¡No consigo atrapar\n"
	.string "nada!\p"
	.string "¡Si no atrapo algo, habré tirado el\n"
	.string "precio de la entrada!$"
