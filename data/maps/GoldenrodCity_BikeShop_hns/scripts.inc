GoldenrodCity_BikeShop_hns_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_BICYCLE
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
	.string "Riding the BIKE is as simple as\n"
	.string "pressing a button if you\l"
	.string "REGISTER it from the BAG.\p"
	.string "If you need to go faster,\n"
	.string "you first need to come to a stop!\p"
	.string "That might seem like strange\n"
	.string "advice, but you can only change\l"
	.string "gears on the BIKE while stopped.\p"
	.string "Press your R button when stopped\n"
	.string "and the next time you pedal,\l"
	.string "you will reach greater speeds!$"

GoldenrodCity_BikeShop_Text_ClerkIntro:
	.string "(Suspiro…) Me trasladé aquí, pero no\n"
	.string "vendo mis BICIS. ¿Por qué?\p"
	.string "¿Montarías en una BICI para hacerme\n"
	.string "publicidad?$"

GoldenrodCity_BikeShop_Text_ClerkAgreed:
	.string "¿De verdad? ¡Bien!\p"
	.string "Dime tu nombre y número de teléfono y\n"
	.string "te prestaré una BICI.$"

GoldenrodCity_BikeShop_Text_BorrowedBicycle:
	.string "{PLAYER} tomó prestada una BICI.$"

GoldenrodCity_BikeShop_Text_Mainshop:
	.string "Business has been hard to come\n"
	.string "by since we moved from KANTO.\l"
	.string "We appreciate your help!\p"
	.string "Can you make sure to show off\n"
	.string "our patented gear-changing tech?\p"
	.string "It's as simple as pressing R when\n"
	.string "you are stopped on your BIKE.\p"
	.string "Beware! You will then go faster!$"

GoldenrodCity_BikeShop_Text_Refused:
	.string "(Suspiro…) ¡Oh, rayos y centellas…!$"

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
	.string "¡Lo último! ¡BICIS compactas de\n"
	.string "máxima calidad!$"

GoldenrodCity_BikeShop_Text_Bicycle:
	.string "¡Es una BICI novísima!$"
