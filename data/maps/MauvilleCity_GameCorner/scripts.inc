MauvilleCity_GameCorner_MapScripts::
	.byte 0

    @ Game Corner prices
	.set TM_DOUBLE_TEAM_COINS, 1500
	.set TM_PSYCHIC_COINS, 3500
	.set TM_FLAMETHROWER_COINS, 4000
	.set TM_THUNDERBOLT_COINS, 4000
	.set TM_ICE_BEAM_COINS, 4000
	.set DOLL_COINS, 1000
	.set DOLL2_COINS,  9000

	.set COINS_PRICE_50,  500
	.set COINS_PRICE_500, 5000
	.set COINS_PRICE_1000, 10000
	.set COINS_PRICE_2500, 25000
	.set COINS_PRICE_5000, 50000

MauvilleCity_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomFor50Coins_NoBoxes
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoneyFor50_NoBoxes
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	case 2, MauvilleCity_GameCorner_EventScript_Buy1000Coins
	case 3, MauvilleCity_GameCorner_EventScript_Buy2500Coins
	case 4, MauvilleCity_GameCorner_EventScript_Buy5000Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	case 2, MauvilleCity_GameCorner_EventScript_Buy1000Coins
	case 3, MauvilleCity_GameCorner_EventScript_Buy2500Coins
	case 4, MauvilleCity_GameCorner_EventScript_Buy5000Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault1000::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 2, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	case 2, MauvilleCity_GameCorner_EventScript_Buy1000Coins
	case 3, MauvilleCity_GameCorner_EventScript_Buy2500Coins
	case 4, MauvilleCity_GameCorner_EventScript_Buy5000Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault2500::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 3, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	case 2, MauvilleCity_GameCorner_EventScript_Buy1000Coins
	case 3, MauvilleCity_GameCorner_EventScript_Buy2500Coins
	case 4, MauvilleCity_GameCorner_EventScript_Buy5000Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault5000::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 4, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	case 2, MauvilleCity_GameCorner_EventScript_Buy1000Coins
	case 3, MauvilleCity_GameCorner_EventScript_Buy2500Coins
	case 4, MauvilleCity_GameCorner_EventScript_Buy5000Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomFor50Coins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoneyFor50
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50
	end

MauvilleCity_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500
	end

MauvilleCity_GameCorner_EventScript_Buy1000Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 1000), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_1000
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 1000
	removemoney COINS_PRICE_1000
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault1000
	end

MauvilleCity_GameCorner_EventScript_Buy2500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 2500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_2500
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 2500
	removemoney COINS_PRICE_2500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault2500
	end

MauvilleCity_GameCorner_EventScript_Buy5000Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 5000), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_5000
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 5000
	removemoney COINS_PRICE_5000
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault5000
	end

MauvilleCity_GameCorner_EventScript_NeedCoinCase::
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoneyFor50::
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoneyFor50, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_2
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoneyFor50_NoBoxes::
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoneyFor50, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_2
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoneyFor50
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50
	end

MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
	goto_if_set FLAG_TEMP_2, MauvilleCity_GameCorner_EventScript_ThanksBuyCoins
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_2
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_ThanksBuyCoins::
	msgbox MauvilleCity_GameCorner_Text_ThanksBuyCoins, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_2
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomFor50Coins::
	msgbox MauvilleCity_GameCorner_Text_NoRoomFor50Coins, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_2
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomFor50Coins_NoBoxes::
	msgbox MauvilleCity_GameCorner_Text_NoRoomFor50Coins, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_2
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomFor50Coins
	msgbox MauvilleCity_GameCorner_Text_NoRoomForCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerDolls::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
	release
	end

@ Script not called, can be set to an Object Event with an appropriate flag to enable Regi Doll Decoration Purchases
@ Recommend adding an Object Event in Celedon Game Corner between existing Prize Counter Sellers and enabling after
@ catching all Regis
MauvilleCity_GameCorner_EventScript_PrizeCornerDolls2::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage2
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage2::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize2

MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize2::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize2

MauvilleCity_GameCorner_EventScript_ChooseDollPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_TorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_MudkipDoll
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
	end

MauvilleCity_GameCorner_EventScript_ChooseDollPrize2::
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS2, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_RegirockDoll
	case 1, MauvilleCity_GameCorner_EventScript_RegiceDoll
	case 2, MauvilleCity_GameCorner_EventScript_RegisteelDoll
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
	end

MauvilleCity_GameCorner_EventScript_TreeckoDoll::
	setvar VAR_TEMP_1, 1
	bufferdecorationname STR_VAR_1, DECOR_TREECKO_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_TorchicDoll::
	setvar VAR_TEMP_1, 2
	bufferdecorationname STR_VAR_1, DECOR_TORCHIC_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_MudkipDoll::
	setvar VAR_TEMP_1, 3
	bufferdecorationname STR_VAR_1, DECOR_MUDKIP_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_RegirockDoll::
	setvar VAR_TEMP_1, 1
	bufferdecorationname STR_VAR_1, DECOR_REGIROCK_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize2

MauvilleCity_GameCorner_EventScript_RegiceDoll::
	setvar VAR_TEMP_1, 2
	bufferdecorationname STR_VAR_1, DECOR_REGIROCK_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize2

MauvilleCity_GameCorner_EventScript_RegisteelDoll::
	setvar VAR_TEMP_1, 3
	bufferdecorationname STR_VAR_1, DECOR_REGIROCK_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize2

MauvilleCity_GameCorner_EventScript_ConfirmDollPrize::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll
	case 2, MauvilleCity_GameCorner_EventScript_BuyTorchicDoll
	case 3, MauvilleCity_GameCorner_EventScript_BuyMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_ConfirmDollPrize2::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyRegirockDoll
	case 2, MauvilleCity_GameCorner_EventScript_BuyRegiceDoll
	case 3, MauvilleCity_GameCorner_EventScript_BuyRegisteelDoll
	end

MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TREECKO_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTorchicDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TORCHIC_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyMudkipDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_MUDKIP_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyRegirockDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL2_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll2
	bufferdecorationname STR_VAR_2, DECOR_REGIROCK_DOLL
	checkdecorspace DECOR_REGIROCK_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll2
	removecoins DOLL2_COINS
	adddecoration DECOR_REGIROCK_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize2
	end

MauvilleCity_GameCorner_EventScript_BuyRegiceDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL2_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll2
	bufferdecorationname STR_VAR_2, DECOR_REGICE_DOLL
	checkdecorspace DECOR_REGICE_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll2
	removecoins DOLL2_COINS
	adddecoration DECOR_REGICE_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize2
	end

MauvilleCity_GameCorner_EventScript_BuyRegisteelDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL2_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll2
	bufferdecorationname STR_VAR_2, DECOR_REGISTEEL_DOLL
	checkdecorspace DECOR_REGISTEEL_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll2
	removecoins DOLL2_COINS
	adddecoration DECOR_REGISTEEL_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize2
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll2::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize2
	end

MauvilleCity_GameCorner_EventScript_NoRoomForDoll::
	call Common_EventScript_NoRoomForDecor
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForDoll2::
	call Common_EventScript_NoRoomForDecor
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize2
	end

MauvilleCity_GameCorner_EventScript_CancelDollSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerTMs::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_EventScript_ChooseTMPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TMDoubleTeam
	case 1, MauvilleCity_GameCorner_EventScript_TMPsychic
	case 2, MauvilleCity_GameCorner_EventScript_TMIceBeam
	case 3, MauvilleCity_GameCorner_EventScript_TMThunderbolt
	case 4, MauvilleCity_GameCorner_EventScript_TMFlamethrower
	case 5, MauvilleCity_GameCorner_EventScript_CancelTMSelect
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
	end

MauvilleCity_GameCorner_EventScript_TMDoubleTeam::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_TM_DOUBLE_TEAM
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMPsychic::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_TM_PSYCHIC
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMFlamethrower::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMThunderbolt::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMIceBeam::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_ConfirmTMPrize::
	special BufferTMHMMoveName
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelTMSelect
	goto_if_unset FLAG_FINITE_TMS, MauvilleCity_GameCorner_EventScript_ConfirmTMPrizeInfinite
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam
	case 2, MauvilleCity_GameCorner_EventScript_BuyTMPsychic
	case 3, MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower
	case 4, MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt
	case 5, MauvilleCity_GameCorner_EventScript_BuyTMIceBeam
	end

MauvilleCity_GameCorner_EventScript_ConfirmTMPrizeInfinite::
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTM32InfiniteDoubleTeam
	case 2, MauvilleCity_GameCorner_EventScript_BuyTM29InfinitePsychic
	case 3, MauvilleCity_GameCorner_EventScript_BuyTM35InfiniteFlamethrower
	case 4, MauvilleCity_GameCorner_EventScript_BuyTM24InfiniteThunderbolt
	case 5, MauvilleCity_GameCorner_EventScript_BuyTM13InfiniteIceBeam
	end

MauvilleCity_GameCorner_EventScript_BuyTM32InfiniteDoubleTeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_DOUBLE_TEAM, 1
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM_DOUBLE_TEAM_COINS
	additem ITEM_TM_DOUBLE_TEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTM29InfinitePsychic::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_PSYCHIC, 1
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM_PSYCHIC_COINS
	additem ITEM_TM_PSYCHIC
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTM35InfiniteFlamethrower::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_FLAMETHROWER, 1
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTM24InfiniteThunderbolt::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_THUNDERBOLT, 1
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTM13InfiniteIceBeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_ICE_BEAM, 1
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis
	removecoins  TM_ICE_BEAM_COINS
	additem ITEM_TM_ICE_BEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_DOUBLE_TEAM
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_DOUBLE_TEAM_COINS
	additem ITEM_TM_DOUBLE_TEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMPsychic::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_PSYCHIC
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_PSYCHIC_COINS
	additem ITEM_TM_PSYCHIC
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_FLAMETHROWER
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMIceBeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_ICE_BEAM
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_ICE_BEAM_COINS
	additem ITEM_TM_ICE_BEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForTM::
	call Common_EventScript_BagIsFull
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_YouAlreadyHaveThis::
    msgbox GoldenrodCity_GameCorner_PrizeRoom_Text_YouAlreadyHaveThis, MSGBOX_AUTOCLOSE
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_CancelTMSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_Woman2::
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Gentleman::
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
	switch VAR_STARTER_MON
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll::
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTorchicDoll::
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveMudkipDoll::
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
	call Common_EventScript_NoRoomForDecor
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_TryGive20Coins
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_TryGive20Coins::
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
	setflag FLAG_RECEIVED_20_COINS
	addcoins 20
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
	end

MauvilleCity_GameCorner_EventScript_PokefanMNormal::
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Cook::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Man::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_Maniac::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_NoCoinCase::
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner:
	.string "Este es el CASINO.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins:
	.string "¿Querías algunas FICHAS para\n"
	.string "jugar?\p"
	.string "Lástima, no tienes un MONEDERO\n"
	.string "para guardarlas…$"

MauvilleCity_GameCorner_Text_WereYouLookingForCoins:
	.string "¿Buscabas FICHAS?\p"
	.string "Son ¥500 por 50 FICHAS.\n"
	.string "¿Quieres algunas?$"

MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins:
	.string "Muchas gracias.\n"
	.string "Aquí tienes tus FICHAS.$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoneyFor50:
	.string "Eh… Parece que no tienes dinero\n"
	.string "suficiente para comprar FICHAS…\p"
	.string "Vuelve cuando tengas al menos\n"
	.string "¥1000.$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoney:
	.string "Eh… Parece que no tienes dinero\n"
	.string "suficiente para tantas FICHAS…$"

MauvilleCity_GameCorner_Text_NoRoomFor50Coins:
	.string "¡Vaya! ¡Tu MONEDERO está demasiado\n"
	.string "lleno para comprar más FICHAS!\p"
	.string "Disfruta del CASINO o\n"
	.string "cambia tus FICHAS por premios\l"
	.string "antes de volver.$"

MauvilleCity_GameCorner_Text_NoRoomForCoins:
	.string "¿Eh? En tu MONEDERO no caben tantas\n"
	.string "FICHAS…$"

MauvilleCity_GameCorner_Text_DontNeedCoinsThen:
	.string "¿Entonces no necesitas FICHAS?\n"
	.string "Bueno, pues que te vaya bien.$"

MauvilleCity_GameCorner_Text_ThanksBuyCoins:
	.string "¡Gracias por comprar FICHAS!\n"
	.string "¡Mucha suerte en tu aventura!$"

MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "Hola. Aquí puedes canjear\n"
	.string "tus FICHAS por premios.$"

MauvilleCity_GameCorner_Text_WhichPrize:
	.string "¿Qué premio quieres?$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX:
	.string "¿Así que quieres\n"
	.string "{STR_VAR_1} {STR_VAR_2}?$"

MauvilleCity_GameCorner_Text_SendToYourHomePC:
	.string "Estupendo. El envío llegará\n"
	.string "directamente a tu PC.$"

MauvilleCity_GameCorner_Text_NotEnoughCoins:
	.string "No tienes bastantes fichas.$"

@ Unused
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor:
	.string "No hay sitio disponible para\n"
	.string "colocar {STR_VAR_1}.$"

MauvilleCity_GameCorner_Text_OhIsThatSo:
	.string "Como quieras… En cualquier caso, si\n"
	.string "cambias de opinión y vuelves, asegúrate\l"
	.string "de tener ahorradas suficientes FICHAS.$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsX:
	.string "¿Así que quieres {STR_VAR_1}?$"

MauvilleCity_GameCorner_Text_HereYouGo:
	.string "¡Aquí tienes!$"

@ Unused
MauvilleCity_GameCorner_Text_CantCarryAnyMore:
	.string "Vaya, no puedes llevar más que eso.$"

MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne:
	.string "Me he equivocado y ahora tengo\n"
	.string "dos MUÑECOS iguales.\p"
	.string "¿Quieres uno?$"

MauvilleCity_GameCorner_Text_HereYouGo2:
	.string "¡Aquí tienes!$"

MauvilleCity_GameCorner_Text_YouWantItButNotNow:
	.string "¿Qué? ¿Que sí lo quieres,\n"
	.string "pero no ahora mismo?$"

MauvilleCity_GameCorner_Text_DontBeNegative:
	.string "Venga, no seas aguafiestas.\n"
	.string "¡Si te lo estoy regalando!$"

MauvilleCity_GameCorner_Text_CantWinJackpot:
	.string "Hay un premio que me gusta mucho,\n"
	.string "pero no gano ni a la de tres.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
	.string "A ver, si quieres jugar aquí,\n"
	.string "necesitas un MONEDERO.\p"
	.string "Creo que aquí al lado vive una chica\n"
	.string "que tiene uno. Ve a verla.$"

MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
	.string "Creo que ya he jugado de sobra.\n"
	.string "Mejor no abusar de la suerte.\l"
	.string "¡Toma algunas FICHAS!$"

MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone:
	.string "Cuando vengo a MALVALONA,\n"
	.string "siempre voy un rato al CASINO.\p"
	.string "Yo diría que esta ciudad me da suerte.$"

MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates:
	.string "No todas las mesas de la RULETA\n"
	.string "cuestan lo mismo.\p"
	.string "Antes de elegir una mesa, comprueba\n"
	.string "cuántas FICHAS tienes.$"

MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime:
	.string "Es fácil entretenerse en este lugar.\n"
	.string "Debería irme a trabajar…$"

MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay:
	.string "Para jugar en el CASINO\n"
	.string "se necesitan FICHAS.$"

MauvilleCity_GameCorner_Text_RouletteOnlyLuck:
	.string "La RULETA tiene peligro…\p"
	.string "Ganar o perder es cuestión de suerte\n"
	.string "y puede engancharte…$"

MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
	.string "Se pueden usar hasta tres FICHAS\n"
	.string "en las TRAGAPERRAS.\p"
	.string "Cuantas más uses, más posibilidades\n"
	.string "tendrás de ganar el premio gordo.$"

MauvilleCity_GameCorner_Text_DifficultToStopOn7:
	.string "Es difícil hacer que se pare justo\n"
	.string "en el “7”.\p"
	.string "Si se para en el “7” durante\n"
	.string "una partida de bonificación REEL TIME,\l"
	.string "ganas muchas más FICHAS.$"

MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo:
	.string "Te voy a dar algo de información\n"
	.string "sobre las TRAGAPERRAS.\p"
	.string "Cuantos más rayos consigas, más\n"
	.string "oportunidades tendrás en el REEL TIME.\p"
	.string "En el mejor de los casos, si logras cinco\n"
	.string "oportunidades en el REEL TIME…,\p"
	.string "podrás ganar cuatro BONUS normales\n"
	.string "y un BIG BONUS al final.\p"
	.string "Esto haría un total de 660 FICHAS,\n"
	.string "pero no es nada fácil hacerse con ellas.$"

MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase:
	.string "No puedes jugar si no tienes\n"
	.string "un MONEDERO.$"

