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
	.string "Montar en BICI es tan fácil como\n"
	.string "pulsar un botón si la REGISTRAS desde\l"
	.string "la MOCHILA.\p"
	.string "Si necesitas ir más rápido, ¡primero\n"
	.string "tienes que pararte!\p"
	.string "Puede parecer un consejo raro, pero\n"
	.string "solo puedes cambiar de marcha en la\l"
	.string "BICI cuando estás parado.\p"
	.string "Pulsa el botón R cuando estés parado\n"
	.string "y, la próxima vez que pedalees, ¡irás\l"
	.string "mucho más rápido!$"

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
	.string "Desde que nos mudamos de KANTO, el\n"
	.string "negocio va fatal. ¡Te agradecemos tu\l"
	.string "ayuda!\p"
	.string "¿Podrías presumir de nuestro sistema\n"
	.string "patentado de cambio de marchas?\p"
	.string "Es tan fácil como pulsar R cuando\n"
	.string "estés parado en tu BICI.\p"
	.string "¡Cuidado! ¡Irás más rápido!$"

GoldenrodCity_BikeShop_Text_Refused:
	.string "(Suspiro…) ¡Oh, rayos y centellas…!$"

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
	.string "¡Lo último! ¡BICIS compactas de\n"
	.string "máxima calidad!$"

GoldenrodCity_BikeShop_Text_Bicycle:
	.string "¡Es una BICI novísima!$"
