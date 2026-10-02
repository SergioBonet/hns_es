BattleFrontier_OutsideEast_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition_hns
	.byte 0

BattleFrontier_OutsideEast_OnResume_hns:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo_hns
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo_hns::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo_hns
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo_hns::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker_hns::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac_hns::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1_hns::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon_hns::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant_hns, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy_hns::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF_hns::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF_hns::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin_hns::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM_hns::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo_hns::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo_hns::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1_hns::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl_hns::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM_hns::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3_hns::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2_hns::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2_hns::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman_hns::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWoman_hnsSudowoodoGone_hns
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWoman_hnsSudowoodoGone_hns::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper_hns::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign_hns:
	.string "¡Ésta es la TORRE BATALLA!\n"
	.string "¡Nada como una buena racha\l"
	.string "para demostrar lo que vales!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign_hns:
	.string "¡Éste es el PALACIO BATALLA!\n"
	.string "¡No pierdas de vista a tus POKéMON!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign_hns:
	.string "¡Éste es el DOJO BATALLA!\n"
	.string "¡Hazte con un buen equipo!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign_hns:
	.string "¡Ésta es la PIRÁMIDE BATALLA!\n"
	.string "¡Te espera la EXPEDICIÓN de COMBATES!$"

BattleFrontier_OutsideEast_Text_RankingHallSign_hns:
	.string "¡HALL de las CLASIFICACIONES!\n"
	.string "¡Apúntate los mejores récords!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign_hns:
	.string "CENTRO del SERVICIO de CANJE\n"
	.string "¡Canjea tus PUNTOS de BATALLA!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial_hns:
	.string "¡Guau!\n"
	.string "¡Es gigantesca!\p"
	.string "Sólo con ver la TORRE BATALLA,\n"
	.string "uno sabe que es un lugar especial.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier_hns:
	.string "¡Mi gran sueño es conquistar el FRENTE\n"
	.string "de BATALLA y la LIGA POKéMON!\p"
	.string "Y, si consigo hacerlo realidad…,\p"
	.string "le preguntaré a MIMI, mi vecina,\n"
	.string "si quiere que seamos amigos.$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh_hns:
	.string "¡La PIRÁMIDE BATALLA es muy dura!\n"
	.string "¡Nunca podré llegar arriba del todo!\p"
	.string "Aunque siempre puedo tratar de llegar\n"
	.string "escalando por fuera…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness_hns:
	.string "Me crezco en las tinieblas…\n"
	.string "Sí… ¿Hay algo que sea digno de mí?\l"
	.string "Nada, salvo la PIRÁMIDE BATALLA…\p"
	.string "¿Acaso hay algo mejor que perderse\n"
	.string "entre las tinieblas y la desesperación?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam_hns:
	.string "No he dormido nada esta semana,\n"
	.string "¡pero ya tengo el equipo invencible!\p"
	.string "¡Voy a hacer historia\n"
	.string "en el DOJO BATALLA!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere_hns:
	.string "¿Te ha traído a ti también el tal TRETO?\n"
	.string "Qué tipo más raro, ¿no te parece?\p"
	.string "Es como si supiese de verdad elegir\n"
	.string "a los mejores ENTRENADORES, pero…\p"
	.string "Nunca lo he visto combatir por sí mismo.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy_hns:
	.string "¡ZIGG!\n"
	.string "¡Confío en ti, chiquitín!\p"
	.string "¡Y mi pequeño ZIGG tendrá la gominola\n"
	.string "que más le guste si gana!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant_hns:
	.string "ZIGZAGOON parece perdido…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody_hns:
	.string "La gente dice que soy un metomentodo,\n"
	.string "pero es que no puedo evitarlo…\p"
	.string "¡Tienes la gorra torcida!\n"
	.string "¡Mira qué de basura hay en el suelo!\l"
	.string "¡Huy, es hora de cenar!\p"
	.string "No sé si podré soportar quedarme\n"
	.string "sólo mirando el PALACIO BATALLA…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader_hns:
	.string "Aunque no lo parezca ahora, en mi época\n"
	.string "llegué a ganar a un LÍDER de GIMNASIO.\p"
	.string "Quién sabe, si me lo propusiera, quizás\n"
	.string "podría volver a saborear la gloria.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles_hns:
	.string "Soy el más rápido con mi BICI.\n"
	.string "¡Igualito que cuando combato!\p"
	.string "¡He ganado algunos combates\n"
	.string "en menos que canta un gallo!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon_hns:
	.string "Soy mucho mejor que mi padre\n"
	.string "entrenando POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy_hns:
	.string "¡Venga, hija mía!\n"
	.string "¡Vete y gana unos combates por papá!\p"
	.string "Eres igualita a tu madre,\n"
	.string "¡contigo no va a poder nadie!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena_hns:
	.string "No ha sido fácil llegar hasta aquí,\n"
	.string "pero había oído que había una belleza\l"
	.string "despampanante en el DOJO BATALLA.\p"
	.string "¿Y sabes lo que me he encontrado\n"
	.string "en realidad?\p"
	.string "¡Una banda de “artistas marciales”\n"
	.string "sudados, malolientes y salvajes!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere_hns:
	.string "A veces veo entrar ahí a un anciano\n"
	.string "que tiene pinta de ser muy importante.\p"
	.string "¡Menudos POKéMON que lleva!…\p"
	.string "Pero, a pesar de todo, parece\n"
	.string "ser un tipo agradable.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid_hns:
	.string "¿La conoces? ¿Conoces la leyenda\n"
	.string "de la PIRÁMIDE BATALLA?\p"
	.string "Cuando un ENTRENADOR armado de valor\n"
	.string "llegue a la cima dorada, un hombre entre\l"
	.string "los hombres saldrá a su encuentro.\p"
	.string "¿No conocías esta leyenda?…\p"
	.string "¡Pues claro que no!\n"
	.string "¡Me la acabo de inventar!\p"
	.string "¿Y qué significa?, me dirás…\p"
	.string "Bueno, eso, ¡no puedo decírtelo!$"

BattleFrontier_OutsideEast_Text_GotWipedOut_hns:
	.string "¡Madre mía!\n"
	.string "¡Y yo que no había perdido nunca antes!\p"
	.string "¡Pero esta vez me han tratado\n"
	.string "sin contemplaciones!\p"
	.string "¡Y encima van y me dicen que no\n"
	.string "valgo para nada! ¡Madre mía!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower_hns:
	.string "Este pobre se topó con un ENTRENADOR\n"
	.string "que lo hizo trizas en la TORRE BATALLA.\p"
	.string "Mira cómo lo han dejado…\p"
	.string "No lo olvides si alguna vez decides\n"
	.string "entrar en la TORRE BATALLA.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll_hns:
	.string "¡Sí! ¡Por fin he conseguido suficientes\n"
	.string "PUNTOS de BATALLA!\p"
	.string "¡Creo que voy a canjearlos por\n"
	.string "un MUÑECO de peluche gigante!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere_hns:
	.string "¡Guay, sí!\n"
	.string "¡El HALL de las CLASIFICACIONES!\p"
	.string "Yo quiero pasar a la historia como\n"
	.string "un gran campeón y que graben\l"
	.string "aquí mi nombre con letras de oro.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou_hns:
	.string "Contigo a mi lado,\n"
	.string "la victoria está más que asegurada.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome_hns:
	.string "¡Ay, pichoncito, eres maravilloso!\p"
	.string "¡Estoy deseando empezar a luchar!\p"
	.string "¡Venga, vamos corriendo a una de esas\n"
	.string "salas de COMBATES MÚLTIPLES!\p"
	.string "Cuando entremos juntos en el SALÓN\n"
	.string "BATALLA, dejaremos a todos atrás\l"
	.string "con el poder de nuestro amor.\p"
	.string "¡Irán cayendo uno a uno\n"
	.string "como piezas de dominó!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers_hns:
	.string "El FRENTE de BATALLA no es sólo\n"
	.string "para ENTRENADORES fuertes.\p"
	.string "Parece que aquí hay también gente\n"
	.string "con habilidades especiales.\p"
	.string "Ese TRETO…\p"
	.string "Puede que haya construido este lugar\n"
	.string "pensando en hacer algo aún más grande…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle_hns:
	.string "Por favor, ¿serías tan amable?\n"
	.string "¿Tienes buena vista?\p"
	.string "Por ahí abajo hay un árbol viejo\n"
	.string "y, aunque tengo la vista cansada,\l"
	.string "para mí que se está meneando…$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere_hns:
	.string "Por favor, ¿serías tan amable?\n"
	.string "¿Tienes buena memoria?\p"
	.string "Es que tengo la sensación de que ahí\n"
	.string "abajo había antes un árbol viejo…$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail_hns:
	.string "¡Yo! ¡Yo! ¡Yo!…\n"
	.string "¡Lo he visto!\p"
	.string "¡Era una especie de POKéMON pegajoso\n"
	.string "y con una cola muy larga!\p"
	.string "¡Estaba escondido debajo de esa piedra,\n"
	.string "y no dejaba de mirarme! ¡Ay, qué repelús!$"
