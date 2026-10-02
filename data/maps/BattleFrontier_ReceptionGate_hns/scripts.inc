BattleFrontier_ReceptionGate_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition_hns
	.byte 0

BattleFrontier_ReceptionGate_OnTransition_hns:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame_hns:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering_hns
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering_hns::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_FRONTIER_RECEPTION_GREETER
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter_hns
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene_hns
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene_hns::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass_hns, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass_hns
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass_hns, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott_hns
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott_hns
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott_hns
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter_hns
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit_hns
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter_hns:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter_hns:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit_hns:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2_hns
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena_hns
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory_hns
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike_hns
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid_hns
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall_hns
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner_hns
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall_hns::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner_hns::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat_hns
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry_hns
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems_hns
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode_hns::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_Level50_hns::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel_hns::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry_hns::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems_hns::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1_hns
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_Symbols_hns::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle_hns::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay_hns:
	.string "¿Es la primera vez que vienes?\n"
	.string "¡Entonces por aquí, por favor!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns:
	.string "¡Éste es el FRENTE de BATALLA!\n"
	.string "¡La prueba final de los ENTRENADORES!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass_hns:
	.string "Como es la primera vez que nos visitas,\n"
	.string "te entregaremos el PASE del FRENTE.\p"
	.string "Te permitirá entrar y competir en todos\n"
	.string "los edificios del FRENTE de BATALLA.\p"
	.string "¡Aquí tienes!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass_hns:
	.string "{PLAYER} obtuvo el PASE del FRENTE.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass_hns:
	.string "{PLAYER} colocó su FICHA de ENTRENADOR\n"
	.string "dentro del PASE del FRENTE.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns:
	.string "¡Y ahora, disfruta al máximo de todo lo\n"
	.string "que te ofrece el FRENTE de BATALLA!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame_hns:
	.string "(?): Bueno, bueno, ¡pero si es {PLAYER}{KUN}!\n"
	.string "¡Al final has venido!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay_hns:
	.string "GUÍA: ¡Oh! ¡Don TRETO! ¡Está usted aquí!\n"
	.string "¡Muy buenas! ¡Muy buenas tenga usted!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere_hns:
	.string "TRETO: ¡Me alegra mucho verte,\n"
	.string "por supuesto que sí!\p"
	.string "Espero que tengas tiempo de\n"
	.string "echarle un vistazo a todo esto.\p"
	.string "Y, por supuesto, espero que no vengas\n"
	.string "sólo a mirar, sino también a combatir.\p"
	.string "Aquí tengo mi rinconcito, así que\n"
	.string "puedes venir a verme cuando quieras.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities_hns:
	.string "¿Buscas información sobre algún\n"
	.string "edificio del FRENTE de BATALLA?$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2_hns:
	.string "¿Sobre cuál?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo_hns:
	.string "Esta torre es para muchos el edificio\n"
	.string "emblemático del FRENTE de BATALLA.\p"
	.string "En ella se disputan cuatro tipos\n"
	.string "de combates: INDIVIDUALES,\l"
	.string "DOBLES, MÚLTIPLES y\l"
	.string "MULTIJUGADOR con CONEXIÓN.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo_hns:
	.string "La CÚPULA BATALLA es un enorme\n"
	.string "edificio con forma de huevo gigante.\p"
	.string "Dentro de ella se disputan los llamados\n"
	.string "TORNEOS de COMBATES, en dos\l"
	.string "modalidades: INDIVIDUAL y DOBLES.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo_hns:
	.string "El PALACIO BATALLA es un edificio rojo\n"
	.string "situado al este del FRENTE de BATALLA.\p"
	.string "En él se celebran los llamados\n"
	.string "COMBATES sin TUTELA, en dos\l"
	.string "modalidades: INDIVIDUAL y DOBLES.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo_hns:
	.string "El DOJO BATALLA es el edificio\n"
	.string "de aspecto oriental situado en la\l"
	.string "zona central del FRENTE de BATALLA.\p"
	.string "Los denominados TORNEOS con JUEZ\n"
	.string "tienen lugar en el DOJO BATALLA.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo_hns:
	.string "La FÁBRICA BATALLA es ese enorme\n"
	.string "edificio que está nada más salir\l"
	.string "a la izquierda.\p"
	.string "Allí se celebran los famosos COMBATES\n"
	.string "con TRUEQUE, tanto en la modalidad\l"
	.string "INDIVIDUAL como en la de DOBLES.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo_hns:
	.string "La SIERPE BATALLA es ese edificio con\n"
	.string "la forma de un POKéMON que está situado\l"
	.string "en el centro del FRENTE de BATALLA.\p"
	.string "El desafío conocido como\n"
	.string "ELECCIÓN de COMBATES se celebra allí.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo_hns:
	.string "La PIRÁMIDE BATALLA es la gran\n"
	.string "pirámide que está al noreste\l"
	.string "del FRENTE de BATALLA.\p"
	.string "Allí podrás emprender las llamadas\n"
	.string "EXPEDICIONES de COMBATES.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo_hns:
	.string "El HALL de las CLASIFICACIONES\n"
	.string "se halla junto a la TORRE BATALLA.\p"
	.string "En él podrás ver los récords logrados\n"
	.string "por los más grandes ENTRENADORES\l"
	.string "en los distintos desafíos que ofrece\l"
	.string "el FRENTE de BATALLA.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo_hns:
	.string "El CENTRO del SERVICIO de CANJE está\n"
	.string "junto a la entrada de la TORRE BATALLA.\p"
	.string "Los PUNTOS de BATALLA que hayas\n"
	.string "ganado en el FRENTE de BATALLA podrás\l"
	.string "canjearlos allí por fabulosos premios.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules_hns:
	.string "Mi trabajo es informar sobre las reglas\n"
	.string "básicas comunes a todos los desafíos\l"
	.string "a los que puedes enfrentarte en los\l"
	.string "escenarios del FRENTE de BATALLA.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat_hns:
	.string "¿Sobre qué quieres que te hable?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo_hns:
	.string "Todos los desafíos del FRENTE\n"
	.string "de BATALLA están disponibles\l"
	.string "en el nivel 50 y el nivel libre.$"

BattleFrontier_ReceptionGate_Text_Level50Info_hns:
	.string "El nivel 50 está abierto a los POKéMON\n"
	.string "cuyo nivel sea igual o inferior a 50.\p"
	.string "Pero debes saber que ninguno de los\n"
	.string "ENTRENADORES a los que te enfrentes\l"
	.string "tendrá POKéMON por debajo del nivel 50.\p"
	.string "Es el nivel básico para enfrentarse a\n"
	.string "los desafíos del FRENTE de BATALLA.\p"
	.string "Para empezar, te recomendamos\n"
	.string "que elijas este nivel.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo_hns:
	.string "El nivel libre, como su nombre indica,\n"
	.string "no impone límite alguno al nivel de los\l"
	.string "POKéMON con los que se combate.\p"
	.string "Los niveles de tus rivales se ajustarán\n"
	.string "para igualarse a los de tus POKéMON.\p"
	.string "Con todo, ningún ENTRENADOR\n"
	.string "al que te enfrentes tendrá POKéMON\l"
	.string "por debajo del nivel 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo_hns:
	.string "Prácticamente cualquier POKéMON podrá\n"
	.string "participar en los desafíos que ofrece\l"
	.string "cualquiera de los escenarios que hay.\p"
	.string "No obstante, los HUEVOS y ciertos\n"
	.string "POKéMON no podrán hacerlo.\p"
	.string "El número de POKéMON necesario para\n"
	.string "participar dependerá del escenario.\p"
	.string "Sin embargo, lo que no podrás hacer en\n"
	.string "ninguno de los escenarios es participar\l"
	.string "con dos POKéMON iguales.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo_hns:
	.string "Antes de afrontar cualquier desafío\n"
	.string "en un escenario del FRENTE de BATALLA,\l"
	.string "comprueba que no haya dos de tus\l"
	.string "POKéMON sosteniendo el mismo objeto.\p"
	.string "Asegúrate de que todos los POKéMON\n"
	.string "que vayan a entrar en un combate\l"
	.string "sostienen objetos diferentes.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass_hns:
	.string "Estaré encantado de explicarte lo que\n"
	.string "quieras sobre el PASE del FRENTE.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1_hns:
	.string "¿Sobre cuál?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo_hns:
	.string "Hay siete escenarios diferentes\n"
	.string "en el FRENTE de BATALLA.\p"
	.string "Cuando un ENTRENADOR demuestra\n"
	.string "sus habilidades y triunfa en uno de los\l"
	.string "edificios, puede que reciba su símbolo.\p"
	.string "Para ganar un símbolo, puede que haya\n"
	.string "que derrotar a varios ENTRENADORES\l"
	.string "consecutivamente y puede que en varias\l"
	.string "ocasiones.\p"
	.string "No es nada fácil ganar estos símbolos.\n"
	.string "¡Que tengas suerte!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo_hns:
	.string "En tu PASE del FRENTE puedes\n"
	.string "grabar un combate.\p"
	.string "Puedes grabar un combate en el que te\n"
	.string "hayas enfrentado a uno o varios amigos.\p"
	.string "O puedes grabar uno de tus combates\n"
	.string "del FRENTE de BATALLA, salvo los de la\l"
	.string "SIERPE BATALLA y la PIRÁMIDE BATALLA.\p"
	.string "La opción de grabarlos aparece\n"
	.string "al terminar el combate.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo_hns:
	.string "Cuando un ENTRENADOR lucha de manera\n"
	.string "extraordinaria en el FRENTE de BATALLA,\l"
	.string "recibe PUNTOS de BATALLA como premio.\p"
	.string "Luego, esos PUNTOS de BATALLA\n"
	.string "pueden canjearse por objetos en\l"
	.string "el CENTRO del SERVICIO de CANJE.$"

