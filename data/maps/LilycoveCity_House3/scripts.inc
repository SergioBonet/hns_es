LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "¡Ay, vaya! ¿Viajas por tu cuenta?\n"
	.string "¡Pero si eres muy joven! ¡Qué bien!\p"
	.string "¡Seguro que mis hijos podrían\n"
	.string "aprender algo de ti!\p"
	.string "¿Yo? Soy una maestra de los {POKEBLOCK}S.\p"
	.string "Si me pongo seria un poquito, ¡vaya!,\n"
	.string "puedo preparar grandes {POKEBLOCK}S.\p"
	.string "¿Te gustaría aprender de mí,\n"
	.string "una maestra de los {POKEBLOCK}S?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "¿Seguro? ¿De verdad?\p"
	.string "¡A veces también hay que pedir\n"
	.string "ayuda a los demás, sabes!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "¡Oh, bien! ¡Tienes buena cabeza!\n"
	.string "Esto es un poco largo, ¡así que atiende!\p"
	.string "¿Estás listo?\p"
	.string "Si miras los {POKEBLOCK}S, verás que\n"
	.string "se valoran según su suavidad.\p"
	.string "Cuanto más baja es la valoración,\n"
	.string "mejor. ¡No lo olvides!\p"
	.string "Un buen {POKEBLOCK} tiene una valoración\n"
	.string "baja y un nivel alto.\p"
	.string "Un POKéMON también puede comer más\n"
	.string "{POKEBLOCK}S buenos que normales.\p"
	.string "Y esto es importante.\p"
	.string "Si quieres preparar {POKEBLOCK}S suaves,\n"
	.string "usa distintas clases de BAYAS.\p"
	.string "¡No seas tacaño! Las clases de BAYAS\n"
	.string "influyen en la suavidad de los {POKEBLOCK}S.\p"
	.string "Y otra cosa.\p"
	.string "Cuanta más gente mezcle BAYAS,\n"
	.string "más suaves serán los {POKEBLOCK}S.\p"
	.string "Por eso deberías hablar con otras\n"
	.string "personas y preparar {POKEBLOCK}S juntos.\p"
	.string "Eso es todo lo que necesitas saber\n"
	.string "para preparar buenos {POKEBLOCK}S.\p"
	.string "Si todos tuvieran POKéMON que aman,\n"
	.string "{POKEBLOCK}S suaves y una familia cariñosa,\l"
	.string "el mundo sería más feliz.\p"
	.string "¡No te rindas, querido!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Cuando mi mujer tuvo cuatrillizos,\n"
	.string "casi me dio un ataque…\p"
	.string "Pero ahora, cuando los veo jugar\n"
	.string "juntos, me siento tan feliz…$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "Estamos entablando COMBATES\n"
	.string "MÚLTIPLES y sé que voy a ganar.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "Nos encanta mezclar cosas\n"
	.string "en el CENTRO de RÉCORDS.\p"
	.string "Pero ¿qué se mezcla allí?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "¡Vamos a preparar súper {POKEBLOCK}S\n"
	.string "con una LICUABAYAS!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Quiero poder fardar de POKéMON, por\n"
	.string "eso vamos a apuntarnos a un CONCURSO.$"

