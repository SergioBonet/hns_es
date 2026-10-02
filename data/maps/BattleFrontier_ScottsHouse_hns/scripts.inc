BattleFrontier_ScottsHouse_hns_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott_hns::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry_hns
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield_hns
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints_hns
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems_hns
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems_hns::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier_hns
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols_hns
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols_hns
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield_hns
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield_hns
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment_hns
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols_hns::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols_hns, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull_hns
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols_hns::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols_hns, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull_hns
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull_hns::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry_hns::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment_hns::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment_hns
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment_hns
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment_hns::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment_hns::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield_hns::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield_hns
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield_hns
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment_hns
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow_hns, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield_hns
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield_hns
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield_hns::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield_hns
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield_hns
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment_hns
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow_hns, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield_hns
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield_hns
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints_hns::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier_hns::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayNorth_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwaySouth_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayEast_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayWest_hns
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal_hns, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing_hns, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints_hns
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints_hns
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints_hns
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints_hns::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints_hns::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints_hns::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint_hns::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints_hns, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints_hns, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayNorth_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwaySouth_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayEast_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayWest_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier_hns:
	.string "TRETO: ¡Hola, hola!\n"
	.string "Je, je… Perdona por lo pequeño del sitio.\p"
	.string "Pero, en fin, {PLAYER}{KUN}, déjame darte\n"
	.string "la bienvenida al FRENTE de BATALLA.\p"
	.string "Éste es mi sueño.\n"
	.string "Me ha llevado años, pero por fin\l"
	.string "he conseguido hacerlo realidad.$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal_hns:
	.string "Ahora que lo pienso, la verdad es que\n"
	.string "ha sido un viaje largo y agotador…\p"
	.string "Dejé mi hogar hace mucho tiempo en\n"
	.string "busca de los ENTRENADORES más fuertes.\p"
	.string "Nadie sabe el trabajo que me ha costado\n"
	.string "conseguirlo.$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing_hns:
	.string "Pero bueno, todo eso ya pasó.\n"
	.string "¡Ya no hay por qué lamentarse!\p"
	.string "Ahora sólo quiero que disfrutes todo\n"
	.string "lo que puedas de este lugar mágico.\p"
	.string "{PLAYER}{KUN}, quiero entregarte esto\n"
	.string "como recuerdo de todas las ocasiones\l"
	.string "en que se cruzaron nuestros caminos.$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints_hns:
	.string "{PLAYER} obtuvo {STR_VAR_1} PB.$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints_hns:
	.string "TRETO: En el PASE del FRENTE podrás\n"
	.string "ver los PUNTOS de BATALLA que tienes.\p"
	.string "A medida que mejoren tus resultados\n"
	.string "en el FRENTE de BATALLA, se será\l"
	.string "más generoso a la hora de darte puntos.\p"
	.string "Usa los puntos para lo que consideres.\n"
	.string "Cámbialos por objetos si quieres.$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings_hns:
	.string "¡Espero mucho de ti!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers_hns:
	.string "TRETO: Cada ENTRENADOR es como es.\n"
	.string "Cada uno vive a su manera.\p"
	.string "Pero, cuando entran en combate,\n"
	.string "ya no importa quiénes son.\p"
	.string "¡Todos son iguales!\p"
	.string "Me gusta esa pureza del combate,\n"
	.string "donde todo el mundo es igual.\p"
	.string "Por eso me he pasado media vida\n"
	.string "buscando ENTRENADORES de verdad.\l"
	.string "Y por eso están todos aquí.$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain_hns:
	.string "TRETO: ¿Has llegado a conocer\n"
	.string "a alguno de los ASES del FRENTE?\p"
	.string "Mejor aún, ¿has conseguido\n"
	.string "alguno de sus símbolos?\p"
	.string "Yo los escogí personalmente uno a uno.\n"
	.string "Son los mejores ENTRENADORES que hay.\p"
	.string "Pero estoy seguro de que, cuando vean\n"
	.string "lo fuerte que eres tú, más de uno se va\l"
	.string "a quedar con la boca abierta…$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier_hns:
	.string "TRETO: Tú no entrenas sólo\n"
	.string "para combatir, ¿verdad?\p"
	.string "Creo que te vi una vez con una POKéDEX.\p"
	.string "Pues vas a tener suerte, oye.\p"
	.string "Quizás encuentres algunos POKéMON\n"
	.string "salvajes en el FRENTE de BATALLA…\l"
	.string "¡Je, je, je!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols_hns:
	.string "TRETO: ¿Te está gustando\n"
	.string "el FRENTE de BATALLA?\p"
	.string "Eh…, espera un segundo…\p"
	.string "¡Tu PASE del FRENTE!\n"
	.string "¡¡Tienes todos los símbolos de plata!!\p"
	.string "¡Eso es impresionante!\n"
	.string "¡Ya sabía yo que valías para esto!\p"
	.string "Normalmente, no suelo hacerlo,\n"
	.string "¡pero es una ocasión especial!\p"
	.string "¡Toma esto!\n"
	.string "¡Seguro que sabes sacarle partido!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols_hns:
	.string "TRETO: Espero que estés disfrutando\n"
	.string "mucho del FRENTE de BATALLA.\p"
	.string "…\n"
	.string "Pero ¿qué ven mis ojos?…\p"
	.string "¡Mira ese PASE del FRENTE! ¡¡Pero\n"
	.string "si tienes todos los símbolos de oro!!\p"
	.string "¡Ahora sí que me has dejado de piedra!\n"
	.string "¡Eres increíble, justo como pensaba!\p"
	.string "Mmm…\p"
	.string "¡{PLAYER}, tienes que aceptar esto!\p"
	.string "¡Nadie como tú sabrá apreciar\n"
	.string "el valor de este regalo!$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere_hns:
	.string "Debo decir que sé reconocer a un buen\n"
	.string "ENTRENADOR nada más verlo.\p"
	.string "¡Me alegro tanto de haberte traído!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed_hns:
	.string "Tu BOLSILLO de BAYAS está a tope.$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow_hns:
	.string "TRETO: ¡Oye, todo el mundo habla de ti!\n"
	.string "¡La TORRE BATALLA está a tus pies!\l"
	.string "¿50 ENTRENADORES consecutivos?\p"
	.string "¡Eso es fantástico!\n"
	.string "¡Toma esto, te lo mereces más que nadie!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow_hns:
	.string "TRETO: ¡Eh, todos hablan de ti!\n"
	.string "¡Y de cómo arrasas en la TORRE BATALLA!\l"
	.string "¡100 ENTRENADORES seguidos!\p"
	.string "¡Ahora sí que te has pasado!\n"
	.string "¡Toma, quiero darte esto!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings_hns:
	.string "¡Espero seguir oyendo a todos\n"
	.string "hablar de esas hazañas tuyas!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater_hns:
	.string "Vaya, parece que tienes demasiadas\n"
	.string "cosas. Vuelve más tarde.$"

