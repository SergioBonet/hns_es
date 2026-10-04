CeladonCity_Restaurant_Frlg_MapScripts::
	.byte 0

CeladonCity_Restaurant_EventScript_Chef::
	msgbox CeladonCity_Restaurant_Text_TakingBreakRightNow, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_Woman::
	msgbox CeladonCity_Restaurant_Text_OftenGoToDrugstore, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_CoinCaseMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_COIN_CASE, CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase
	msgbox CeladonCity_Restaurant_Text_TakeThisImBusted
	checkitemspace ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Restaurant_EventScript_NoRoomForCoinCase
	giveitem_msg CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan, ITEM_COIN_CASE
	setflag FLAG_GOT_COIN_CASE
	release
	end

CeladonCity_Restaurant_EventScript_NoRoomForCoinCase::
	msgbox CeladonCity_Restaurant_Text_MakeRoomForThis
	release
	end

CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase::
	msgbox CeladonCity_Restaurant_Text_ThoughtIdWinItBack
	release
	end

CeladonCity_Restaurant_EventScript_WorkerM::
	msgbox CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_FatMan::
	msgbox CeladonCity_Restaurant_Text_ManLostItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_TakingBreakRightNow::
	.string "¡Hola!\p"
	.string "Ahora estamos descansando.$"

CeladonCity_Restaurant_Text_OftenGoToDrugstore::
	.string "Suelo visitar la FARMACIA, porque\n"
	.string "mis POKéMON son débiles.$"

CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner::
	.string "¡Psss!\n"
	.string "Hay un sótano debajo del CASINO.$"

CeladonCity_Restaurant_Text_ManLostItAllAtSlots::
	.string "Oye...\p"
	.string "El hombre de esa mesa lo perdió\n"
	.string "todo en las tragaperras.$"

CeladonCity_Restaurant_Text_TakeThisImBusted::
	.string "¡Venga! ¡Ríete!\n"
	.string "¡Estoy arruinado!\p"
	.string "¡No más tragaperras para mí!\n"
	.string "¡Yo me largo!\p"
	.string "¡Toma esto!\n"
	.string "¡Ya no lo necesito!$"

CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan::
	.string "¡{PLAYER} recibió un MONEDERO\n"
	.string "de manos del hombre!$"

CeladonCity_Restaurant_Text_MakeRoomForThis::
	.string "¡Haz sitio para esto!$"

CeladonCity_Restaurant_Text_ThoughtIdWinItBack::
	.string "Pensaba que iba a recuperarme...$"

