BattleFrontier_OutsideWest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition_hns
	.byte 0

BattleFrontier_OutsideWest_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_EventScript_Sailor_hns::
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_AsYouLike_hns
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	hideobjectat LOCALID_BATTLE_FRONTIER_SAILOR_HNS, MAP_BATTLE_FRONTIER_OUTSIDE_WEST_HNS
	setvar VAR_0x8004, LOCALID_FARAWAY_BATTLE_FRONTIER_HNS_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warpsilent MAP_OLIVINE_CITY_PORT_INSIDE_HNS, 8, 16
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_AsYouLike_hns::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign_hns, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2_hns::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1_hns::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_Maniac2_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hns::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns::
	return

BattleFrontier_OutsideWest_EventScript_Girl_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass_hns::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM_hns::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2_hns::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1_hns::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2_hns::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF_hns::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign_hns:
	.string "¡Ésta es la CÚPULA BATALLA!\n"
	.string "¡La ruta a la fama pasa por aquí!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign_hns:
	.string "¡Ésta es la FÁBRICA BATALLA!\n"
	.string "¡Hazte con el POKéMON más fuerte!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign_hns:
	.string "¡Ésta es la SIERPE BATALLA!\n"
	.string "¡Elige el mejor de los tres caminos!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns:
	.string "Ésta es la TORRE BATALLA.\p"
	.string "Los ENTRENADORES traen a sus mejores\n"
	.string "POKéMON para luchar en combates\l"
	.string "eliminatorios.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket_hns:
	.string "Buenas, ¿vienes para coger el ferry?\n"
	.string "¿Puedo ver tu TICKET?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard_hns:
	.string "{PLAYER} no tiene ningún TICKET…\p"
	.string "Cuánto lo lamento.\p"
	.string "Necesitas un TICKET para poder\n"
	.string "subir a bordo del ferry.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo_hns:
	.string "{PLAYER} enseñó el TICKET…\p"
	.string "Perfecto. Todo está en regla.\p"
	.string "¿Adónde te gustaría ir?$"

BattleFrontier_OutsideWest_Text_SlateportItIs_hns:
	.string "Muy bien, rumbo a CIUDAD PORTUAL.$"

BattleFrontier_OutsideWest_Text_LilycoveItIs_hns:
	.string "Muy bien, rumbo a CIUDAD CALAGUA.$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime_hns:
	.string "¡Esperamos que vuelvas a navegar\n"
	.string "con nosotros!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry_hns:
	.string "Sube a bordo y espera a que zarpemos.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo_hns:
	.string "¿Adónde te gustaría ir?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns:
	.string "Les doy mil vueltas a todos mis amigos.\n"
	.string "Pero aquí…\l"
	.string "He hecho el ridículo.$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns:
	.string "Quiero ir a la TORRE BATALLA,\n"
	.string "pero no la encuentro, y eso que tengo\l"
	.string "un mapa del FRENTE de BATALLA…\p"
	.string "¡Es que este sitio es muy grande!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns:
	.string "Quería llegar lo antes posible\n"
	.string "para ponerme a luchar.\p"
	.string "Pero me he mareado en el barco…\n"
	.string "Uajjj…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns:
	.string "No te creas que al FRENTE de BATALLA\n"
	.string "puede venir cualquiera, ¿eh?\p"
	.string "Aquí sólo invitan a los ENTRENADORES\n"
	.string "que han demostrado que valen.\p"
	.string "Por eso muchos ENTRENADORES\n"
	.string "ni han oído hablar de este lugar.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns:
	.string "Eh, colega…\p"
	.string "¿Seguro que podemos combatir\n"
	.string "aunque no tengamos ni un POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns:
	.string "¡Claro! ¡Seguro que no pasa nada!\p"
	.string "Creo…\p"
	.string "Recuerda lo que dijo el gorila ese del\n"
	.string "mostrador: “¡Yo te presto\l"
	.string "los POKéMON!”.$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns:
	.string "Eso de ahí es la FÁBRICA BATALLA.\n"
	.string "Ahí te prestan POKéMON muy fuertes.\p"
	.string "Siempre me he preguntado quién será\n"
	.string "el guapo que los entrena…$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns:
	.string "Me da miedo entrar en la SIERPE\n"
	.string "BATALLA con todos esos SEVIPER…\p"
	.string "Pe-pero, ya que he llegado hasta aquí,\n"
	.string "tendré que conquistarlo todo, ¿no?\l"
	.string "Ay, ay, ay…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns:
	.string "¡Vamos a jugar a piedra, papel o tijeras!\n"
	.string "Una, dos, y…\p"
	.string "¡tres!\p"
	.string "Mmm…$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns:
	.string "¡Sí! ¡Gané!\n"
	.string "¡Entraré en la SIERPE BATALLA!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns:
	.string "Oh, no…\n"
	.string "He perdido.\p"
	.string "Hoy no es mi día de suerte.\n"
	.string "Creo que tendré que dejar lo de\l"
	.string "la SIERPE BATALLA para mañana.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns:
	.string "Creo que soy el único de por aquí que, \n"
	.string "por alguna razón que se me escapa,\l"
	.string "prefiere pescar a combatir.\p"
	.string "¿Cómo?…\p"
	.string "¿Que aquí no pica nada?\n"
	.string "Vaya, qué fastidio…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns:
	.string "¡Hoy no pienso parar de combatir hasta\n"
	.string "que no haya ganado un símbolo! ¡Ea!$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns:
	.string "¿Eh? ¿Tú también piensas entrar\n"
	.string "en la CÚPULA BATALLA?\p"
	.string "Pues te deseo toda la suerte del mundo.\n"
	.string "Ojalá ganemos los dos\l"
	.string "y nos encontremos en la final.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns:
	.string "¡Abuelito, por aquí!\n"
	.string "¡La CÚPULA BATALLA está aquí!\l"
	.string "¡Venga, a por ellos, abuelito!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns:
	.string "Ah, conque esto es la CÚPULA BATALLA…\n"
	.string "¡No pienso dejarme ganar por ninguno\l"
	.string "de esos a los que llaman CABALLEROS!\p"
	.string "Pero ¿por dónde se entra a este sitio?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns:
	.string "Todavía me acuerdo de cuando aquí\n"
	.string "no había nada.\p"
	.string "Pero mira ahora… ¡Increíble!\n"
	.string "¡Esto tiene que verlo mi madre!$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns:
	.string "¡Por fin estoy en el FRENTE de BATALLA!\p"
	.string "¡Ya verás cómo triunfo aquí con\n"
	.string "todos mis encantos y habilidades!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns:
	.string "Ñam, ñam…\p"
	.string "Esta plaza está llena de tipos duros,\n"
	.string "¿no crees?\p"
	.string "Ñam, ñam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns:
	.string "Ñam, ñam…\p"
	.string "El otro día me encontré con una chica\n"
	.string "en la SIERPE BATALLA.\p"
	.string "Tenía unos ojos que daban miedo.\p"
	.string "Ñam, ñam…\p"
	.string "Estaba indignada: “¡¿Vas a dejar de\n"
	.string "comer de una vez?!”, me dijo.\l"
	.string "Y luego me machacó.\p"
	.string "Lo pasé fatal, menuda experiencia tan\n"
	.string "traumática, oye. Qué mal lo pasé…\p"
	.string "Ñam, ñam…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns:
	.string "Pero ¡¿qué estás diciendo, chaval?!\n"
	.string "¡Menuda tontería!\p"
	.string "¿Sabes lo que te digo?\n"
	.string "¡Que era a mí a quien miraba!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns:
	.string "¡¿Que qué?!\n"
	.string "¡Bah!\p"
	.string "¡Eso fue porque estabas\n"
	.string "sentada a mi lado, lista!\p"
	.string "¡El ASTRO de la CÚPULA me estaba\n"
	.string "mirando a mí! ¡Y sólo a mí!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns:
	.string "¡Venga, ya!\n"
	.string "¡Dejad de discutir! ¡Parecéis críos!\p"
	.string "¡Menudos fans de pacotilla!\n"
	.string "¡No os merecéis animar\l"
	.string "ni a un LÍDER de GIMNASIO!\p"
	.string "¡El ASTRO de la CÚPULA es para mí!\n"
	.string "¡Es mi único ídolo!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns:
	.string "Mira a ésos de ahí discutiendo…\p"
	.string "Resulta difícil de creer, pero antes\n"
	.string "eran ENTRENADORES, y de los buenos.\p"
	.string "Vamos, que eran famosos y todo.\p"
	.string "Pero en un torneo, hubo un ENTRENADOR\n"
	.string "que los eclipsó completamente.\p"
	.string "Les dio una paliza tremenda a todos.\p"
	.string "Y ahora son sus fans incondicionales\n"
	.string "y van a animarlo a la CÚPULA BATALLA\l"
	.string "siempre que participa en un torneo.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns:
	.string "Dicen que han visto a un POKéMON\n"
	.string "que tiene una cola larguísima en algún\l"
	.string "sitio del FRENTE de BATALLA.\p"
	.string "Tiene que ser adorable, seguro…\p"
	.string "Los desafíos pueden esperar.\n"
	.string "¡Yo quiero encontrar a ese POKéMON!$"

