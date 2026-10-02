BattleFrontier_Lounge1_hns_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder_hns::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_Breeder_hnsIntro_hns
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder_hns
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder_hns
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder_hns::
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder_hns
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect_hns
	end

BattleFrontier_Lounge1_EventScript_Breeder_hnsIntro_hns::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro_hns, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder_hns::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon_hns, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder_hns::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder_hns
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs_hns       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs_hns @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs_hns         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs_hns     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder_hns::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder_hns
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat_hns::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP_hns
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk_hns
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef_hns
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed_hns
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk_hns
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef_hns
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue_hns::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow_hns
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid_hns
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh_hns
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax_hns
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments_hns::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs_hns::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat_hns
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs_hns::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat_hns
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs_hns::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat_hns
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs_hns::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef_hns::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow_hns::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid_hns::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh_hns::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments_hns
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax_hns::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments_hns
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect_hns::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1_hns::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2_hns::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro_hns:
	.string "¡Llevo 70 años entrenando POKéMON!\n"
	.string "¡Todos me consideran una leyenda viva\l"
	.string "y me rinden sus honores!\p"
	.string "¡Soy el mejor CRIAPOKéMON!\p"
	.string "Si llegas a alcanzar mi maestría,\n"
	.string "podrás reconocer las habilidades\l"
	.string "de un POKéMON nada más verlo.\p"
	.string "Tú parece que sabes algo de entrenar.\n"
	.string "¿Te interesa conocer las habilidades\l"
	.string "de tus propios POKéMON?\p"
	.string "¡Venga!\n"
	.string "¡Veamos a esos POKéMON que llevas ahí!$"

BattleFrontier_Lounge1_Text_AverageAbility_hns:
	.string "Mmm…\p"
	.string "De éste, a grandes rasgos, diría\n"
	.string "que posee habilidades normales.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility_hns:
	.string "Mmm…\p"
	.string "De éste, a grandes rasgos, diría\n"
	.string "que posee buenas habilidades.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility_hns:
	.string "Mmm…\p"
	.string "De éste, a grandes rasgos, diría que\n"
	.string "posee habilidades impresionantes.$"

BattleFrontier_Lounge1_Text_OutstandingAbility_hns:
	.string "Mmm…\p"
	.string "De éste, a grandes rasgos, diría que\n"
	.string "posee habilidades extraordinarias.$"

BattleFrontier_Lounge1_Text_BestAspectHP_hns:
	.string "Más concretamente, su punto fuerte\n"
	.string "está en los PS…$"

BattleFrontier_Lounge1_Text_BestAspectAtk_hns:
	.string "Más concretamente, su punto fuerte\n"
	.string "está en el ATAQUE…$"

BattleFrontier_Lounge1_Text_BestAspectDef_hns:
	.string "Más concretamente, su punto fuerte\n"
	.string "está en la DEFENSA…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk_hns:
	.string "Más concretamente, su punto fuerte\n"
	.string "está en el ATAQUE ESPECIAL…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef_hns:
	.string "Más concretamente, su punto fuerte\n"
	.string "está en la DEFENSA ESPECIAL…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed_hns:
	.string "Más concretamente, su punto fuerte\n"
	.string "está en la VELOCIDAD…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood_hns:
	.string "Es una característica buena.\n"
	.string "Mm… Sí, así la definiría yo.$"

BattleFrontier_Lounge1_Text_StatImpressive_hns:
	.string "Es una característica muy buena.\n"
	.string "Mm… Sí, así la definiría yo.$"

BattleFrontier_Lounge1_Text_StatOutstanding_hns:
	.string "Es una característica extraordinaria.\n"
	.string "Mm… Sí, así la definiría yo.$"

BattleFrontier_Lounge1_Text_StatFlawless_hns:
	.string "¡Es algo sencillamente perfecto!\n"
	.string "Mm… Sí, así lo definiría yo.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice_hns:
	.string "¿Cómo?\n"
	.string "¿Que no tienes tiempo para consejos?\p"
	.string "¡Deberías estar feliz por poder\n"
	.string "aprender algo de los mayores!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending_hns:
	.string "Sí, ¿qué pasa ahora?\p"
	.string "¡Tengo asuntos que atender! ¡Déjalo\n"
	.string "para la próxima!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon_hns:
	.string "Mmm… ¿Te intrigan las habilidades\n"
	.string "de tus POKéMON?\p"
	.string "¡Venga! ¡Vamos a echarles un vistazo!$"

BattleFrontier_Lounge1_Text_EvenICantTell_hns:
	.string "¡Soy un experto, no un adivino!\n"
	.string "¡No puedo decir nada sobre los POKéMON\l"
	.string "que aún no han roto el cascarón!\p"
	.string "¡Muéstrame un POKéMON!\n"
	.string "¡Lo que necesito ver es un POKéMON!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding_hns:
	.string "¡Este señor me ha dicho\n"
	.string "que mi POKéMON es extraordinario!\l"
	.string "¡Me alegro de haberlo entrenado bien!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt_hns:
	.string "¡Este señor me ha dicho\n"
	.string "que mi POKéMON es extraordinario!\l"
	.string "Y eso que no me he esmerado mucho…$"

