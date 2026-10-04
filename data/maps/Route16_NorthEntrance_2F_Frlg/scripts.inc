.equ REQUIRED_CAUGHT_MONS, 40

Route16_NorthEntrance_2F_Frlg_MapScripts::
	.byte 0

Route16_NorthEntrance_2F_EventScript_LittleBoy::
	msgbox Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_EventScript_LittleGirl::
	msgbox Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_LongPathOverWater, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_EventScript_Aide::
	lock
	faceplayer
	call Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE, Route16_NorthEntrance_2F_EventScript_AlreadyGotAmuletCoin
	msgbox Route16_NorthEntrance_2F_Text_GiveAmuletCoinIfCaught40, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_CAUGHT_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route16_NorthEntrance_2F_Text_GreatHereYouGo
	checkitemspace ITEM_AMULET_COIN
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route16_NorthEntrance_2F_Text_ReceivedAmuletCoinFromAide, ITEM_AMULET_COIN
	setflag FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE
	msgbox Route16_NorthEntrance_2F_Text_ExplainAmuletCoin
	release
	end

Route16_NorthEntrance_2F_EventScript_AlreadyGotAmuletCoin::
	msgbox Route16_NorthEntrance_2F_Text_ExplainAmuletCoin
	release
	end

Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_CAUGHT_MONS
	bufferitemname STR_VAR_2, ITEM_AMULET_COIN
	return

Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend::
	.string "¡Voy a darme una vuelta con mi\n"
	.string "novia!$"

Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes::
	.string "¡Vamos a pedalear juntos!$"

Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore::
	.string "Has usado los prismáticos...\p"
	.string "¡Es el CENTRO COMERCIAL\n"
	.string "de CIUDAD AZULONA!$"

Route16_NorthEntrance_2F_Text_LongPathOverWater::
	.string "Has usado los prismáticos...\p"
	.string "¡Hay un largo camino sobre\n"
	.string "el agua!$"

Route16_NorthEntrance_2F_Text_GiveAmuletCoinIfCaught40::
	.string "¡Hola! ¿Te acuerdas de mí?\n"
	.string "Soy uno de los AYUDANTES del PROF. OAK.\p"
	.string "Si tu POKéDEX tiene datos completos\n"
	.string "de 40 especies, debo darte\l"
	.string "un premio.\p"
	.string "El PROF. OAK me confió una\n"
	.string "MONEDA AMULETO para ti.\p"
	.string "Así que, {PLAYER}, déjame preguntarte.\p"
	.string "¿Has reunido datos de al menos\n"
	.string "40 clases de POKéMON?$"

Route16_NorthEntrance_2F_Text_GreatHereYouGo::
	.string "¡Bien! ¡Has logrado {STR_VAR_3} tipos\n"
	.string "de POKéMON!\p"
	.string "¡Enhorabuena!\n"
	.string "¡Aquí tienes!$"

Route16_NorthEntrance_2F_Text_ReceivedAmuletCoinFromAide::
	.string "¡{PLAYER} obtuvo MON. AMULETO\n"
	.string "de manos del AYUDANTE!$"

Route16_NorthEntrance_2F_Text_ExplainAmuletCoin::
	.string "Una MONEDA AMULETO es un objeto\n"
	.string "que puede llevar un POKéMON.\p"
	.string "Si gana el POKéMON que la tenga,\n"
	.string "conseguirás más dinero.$"

