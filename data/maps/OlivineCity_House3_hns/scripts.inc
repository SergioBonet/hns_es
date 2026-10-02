OlivineCity_House3_hns_MapScripts::
	.byte 0

OlivineCityHouse3_EventScriptFishingGuru::
	lock
	faceplayer
	checkitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, TRUE, OlivineCityHouse3_EventScriptFishingGuru2
	msgbox OlivineCity_Text_OfferGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineCityHouse3_EventScriptFishingGuruRefused
	msgbox OlivineCity_Text_GiveGoodRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Text_GaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuru2::
	msgbox OlivineCity_Text_HaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuruRefused::
	msgbox OlivineCity_Text_DontWantGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_OfferGoodRod:
	.string "¡CIUDAD OLIVO está junto al mar!\p"
	.string "¡Y si está junto al mar, seguro que hay\n"
	.string "peces!\p"
	.string "Llevo 30 años pescando aquí.\p"
	.string "¿Quieres ponerte frente al mar y\n"
	.string "probar a pescar?$"

OlivineCity_Text_GiveGoodRod:
	.string "¡Ajá, jajá! ¡Tenemos un nuevo pescador\n"
	.string "en ciernes!$"

OlivineCity_Text_GaveGoodRod:
	.string "Los peces no solo están en el mar:\n"
	.string "están allí donde haya agua.\p"
	.string "Por cierto, tu POKéDEX muestra los\n"
	.string "grupos de pesca de los POKéMON.\p"
	.string "En sitios distintos puede haber peces\n"
	.string "de tipos parecidos.$"

OlivineCity_Text_DontWantGoodRod:
	.string "¿Quéee? ¿¡No te gusta pescar!? ¡Es\n"
	.string "incomprensible!$"

OlivineCity_Text_HaveGoodRod:
	.string "¿Qué tal te va? ¿Has pescado el pez\n"
	.string "gordo?$"
