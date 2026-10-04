SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	setvar VAR_0x8009, SPECIES_SEEDOT
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	setvar VAR_0x8009, SPECIES_LOTAD
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "¿Conoces el POKéMON SEEDOT?\n"
	.string "Apenas se le ve en ARRECÍPOLIS.\p"
	.string "Pero igualmente me encanta:\n"
	.string "cuanto más grande, mejor.\p"
	.string "Mi hermano pequeño dice que\n"
	.string "LOTAD es más grande.\p"
	.string "¡Qué chorrada! SEEDOT es gigantesco…\p"
	.string "Eh… ¿Tienes un SEEDOT?\n"
	.string "¿Me lo puedes enseñar?$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "¡{STR_VAR_2}!\n"
	.string "¡Madre mía, este es grande!\p"
	.string "¡Quizá supere al LOTAD grande que\n"
	.string "vio mi hermano pequeño!\p"
	.string "Gracias por enseñármelo.\n"
	.string "¡Aquí tienes mi agradecimiento!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} recibió una POCIÓN.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "¿Eh? ¡Pero si la MOCHILA\n"
	.string "está que revienta!$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "¿{STR_VAR_2}, dices?\p"
	.string "Hmm… He visto un SEEDOT más grande\n"
	.string "que este.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Mmmm… No está nada mal,\n"
	.string "pero no es un SEEDOT.$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "¿No tienes un SEEDOT grande?\n"
	.string "Qué mala suerte…\p"
	.string "Si consigues uno, ven a verme.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "¡El SEEDOT más grande de la historia!\n"
	.string "¡{STR_VAR_2}, {STR_VAR_3} gigante!\p"
	.string "¡Un SEEDOT más grande de lo que\n"
	.string "soñaba un LOTAD!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "¿Conoces el POKéMON LOTAD?\n"
	.string "Apenas se le ve en ARRECÍPOLIS.\p"
	.string "Pero igualmente me encanta:\n"
	.string "cuanto más grande, mejor.\p"
	.string "Mi hermano mayor dice que\n"
	.string "SEEDOT es más grande.\p"
	.string "¡Qué absurdo! Todo el mundo sabe\n"
	.string "que LOTAD es colosal…\p"
	.string "Eh… ¿Tienes un LOTAD?\n"
	.string "¿Me lo puedes enseñar?$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "¡{STR_VAR_2}!\n"
	.string "¡Vaya, qué grande!\p"
	.string "¡Quizá sea aún más grande que el\n"
	.string "SEEDOT enorme que vio mi hermano mayor!\p"
	.string "Gracias por enseñármelo.\n"
	.string "¡Aquí tienes mi agradecimiento!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} recibió una POCIÓN.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "¿Eh? ¡Pero si la MOCHILA\n"
	.string "está que revienta!$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "¿{STR_VAR_2}?\p"
	.string "Hmm… He visto un LOTAD más grande\n"
	.string "que este.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Mmmm… No está nada mal,\n"
	.string "pero no es un LOTAD.$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "¿No tienes un LOTAD grande?\n"
	.string "Qué decepción…\p"
	.string "Si consigues uno, ven a verme.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "¡El LOTAD más grande de la historia!\n"
	.string "¡{STR_VAR_2}, {STR_VAR_3} coloso!\p"
	.string "¡Un LOTAD más grande de lo que\n"
	.string "soñaba un SEEDOT!$"

