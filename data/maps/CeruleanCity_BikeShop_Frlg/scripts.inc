CeruleanCity_BikeShop_Frlg_MapScripts::
	.byte 0

CeruleanCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BICYCLE, CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle
	goto_if_set FLAG_GOT_BIKE_VOUCHER, CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher
	showmoneybox 0, 0
	message CeruleanCity_BikeShop_Text_WelcomeToBikeShop
	waitmessage
	multichoice 11, 0, MULTI_BIKE_SHOP, FALSE
	hidemoneybox
	showmoneybox 0, 0
	switch VAR_RESULT
	case 0, CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle
	case 1, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	case 127, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

@ The Bicycle price / players money is never actually checked
CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle::
	msgbox CeruleanCity_BikeShop_Text_SorryYouCantAffordIt
	goto CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

CeruleanCity_BikeShop_EventScript_ClerkGoodbye::
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain
	hidemoneybox
	release
	end

CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher::
	msgbox CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo
	msgreceiveditem CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle, ITEM_BICYCLE, 1, MUS_RG_OBTAIN_KEY_ITEM
	setflag FLAG_GOT_BICYCLE
	additem ITEM_BICYCLE
	removeitem ITEM_BIKE_VOUCHER
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain
	release
	end

CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle::
	msgbox CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle
	release
	end

@ Unused
CeruleanCity_BikeShop_EventScript_NoRoomForBicycle::
	msgbox CeruleanCity_BikeShop_Text_MakeRoomForBicycle
	release
	end

CeruleanCity_BikeShop_EventScript_Woman::
	msgbox CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe, MSGBOX_NPC
	end

CeruleanCity_BikeShop_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BICYCLE, CeruleanCity_BikeShop_EventScript_YoungsterHaveBike
	msgbox CeruleanCity_BikeShop_Text_BikesCoolButExpensive
	release
	end

CeruleanCity_BikeShop_EventScript_YoungsterHaveBike::
	msgbox CeruleanCity_BikeShop_Text_WowYourBikeIsCool
	release
	end

CeruleanCity_BikeShop_EventScript_Bicycle::
	msgbox CeruleanCity_BikeShop_Text_ShinyNewBicycle, MSGBOX_SIGN
	end

CeruleanCity_BikeShop_Text_WelcomeToBikeShop::
	.string "¡Ésta es la TIENDA de BICIS!\p"
	.string "¡Tenemos la BICI que buscabas!$"

CeruleanCity_BikeShop_Text_SorryYouCantAffordIt::
	.string "¡Lo siento!\n"
	.string "¡No tienes dinero para pagarla!$"

CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo::
	.string "Anda, pero si tienes...\p"
	.string "¡Un BONO para una BICICLETA!\p"
	.string "¡Muy bien!\n"
	.string "¡Toda tuya!$"

CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle::
	.string "{PLAYER} cambió el BONO por una\n"
	.string "BICICLETA.$"

CeruleanCity_BikeShop_Text_ThankYouComeAgain::
	.string "¡Vuelve cuando quieras!$"

CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle::
	.string "¿Te gusta tu nueva BICICLETA?\p"
	.string "¡Puedes usarla por el CAMINO\n"
	.string "de BICIS y por las cuevas!$"

CeruleanCity_BikeShop_Text_MakeRoomForBicycle::
	.string "¡No tienes sitio para esto!$"

CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe::
	.string "Una bici de ciudad normal me\n"
	.string "basta.\p"
	.string "Al fin y al cabo, en una bici de\n"
	.string "montaña no cabe la cesta de la compra.$"

CeruleanCity_BikeShop_Text_BikesCoolButExpensive::
	.string "¡Estas BICIS son geniales, pero\n"
	.string "muy caras!$"

CeruleanCity_BikeShop_Text_WowYourBikeIsCool::
	.string "¡Uauu!\n"
	.string "¡Vaya BICI tan chula!$"

@ Unused
CeruleanCity_BikeShop_Text_GermanFoldableBicyleFinallyOnMarket::
	.string "¡Por fin a la venta!\p"
	.string "Bicicleta plegable alemana\n"
	.string "de primera calidad.$"

CeruleanCity_BikeShop_Text_ShinyNewBicycle::
	.string "¡Una BICICLETA flamante!$"

