GoldenrodCity_FlowerShop_hns_MapScripts::
	.byte 0


GoldenrodCity_FlowerShop_EventScript_MintClerk::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_MintClerkNotReady
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodCity_FlowerShop_Mints
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_FlowerShop_EventScript_MintClerkNotReady::
	msgbox GoldenrodCity_FlowerShop_Text_MintClerkNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_Text_MintClerkNotReady:
	.string "Ahora mismo no nos queda nada.\p"
	.string "Vuelve más tarde, por favor.$"

	.align 2
GoldenrodCity_FlowerShop_Mints:
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	pokemartlistend


GoldenrodCity_FlowerShop_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Normal
	goto_if_set FLAG_RECEIVED_SQUIRTBOTTLE, GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle
	msgbox GoldenrodCity_FlowerShop_Text_Owner1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner2, MSGBOX_DEFAULT
	giveitem ITEM_SQUIRT_BOTTLE
	setflag FLAG_RECEIVED_SQUIRTBOTTLE
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Normal::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Floria3
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_Floria2
	msgbox GoldenrodCity_FlowerShop_Text_Floria, MSGBOX_DEFAULT
	closemessage
	release
	end
	
GoldenrodCity_FlowerShop_EventScript_Floria2::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria3::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaItWasAMon, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_Text_Floria:
	.string "Cuando le hablé a mi hermana de ese\n"
	.string "árbol, me dijo que era peligroso.\p"
	.string "Si venzo a BLANCA, quizás me preste su\n"
	.string "REGADERA…$"

GoldenrodCity_FlowerShop_Text_Owner1:
	.string "Por lo visto, en la RUTA 36 hay un árbol\n"
	.string "muy raro.\p"
	.string "Dicen que baila cuando lo riegas…\p"
	.string "¡Bah, qué va!\p"
	.string "Como esto es una floristería, sí que\n"
	.string "tenemos regaderas…\p"
	.string "¡Pero no puedo darte una! ¡Es\n"
	.string "demasiado peligroso!\p"
	.string "Bueno, a lo mejor, si consigues vencer\n"
	.string "a BLANCA, la LÍDER del GIMNASIO, no\l"
	.string "pasaría nada.$"

GoldenrodCity_FlowerShop_Text_Owner2:
	.string "Por lo visto, en la RUTA 36 hay un árbol\n"
	.string "muy raro.\p"
	.string "Dicen que baila cuando lo riegas…\p"
	.string "¡Oh, esa es la MEDALLA LLANURA del\n"
	.string "GIMNASIO de CIUDAD TRIGAL!\p"
	.string "¿Has vencido a BLANCA?\p"
	.string "Entonces no hay nada de qué\n"
	.string "preocuparse, ¿verdad?\p"
	.string "Te dejaré esta REGADERA un tiempo.\p"
	.string "…\p"
	.string "¡Bah, da igual! ¡Quédatela!$"

GoldenrodCity_FlowerShop_Text_Owner3:
	.string "El árbol extraño está en la RUTA 36.\n"
	.string "Ten mucho cuidado.$"

GoldenrodCity_FlowerShop_Text_Owner4:
	.string "Lalala, lalalala. ¡Échale mucha agua,\n"
	.string "cariño!$"

GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney:
	.string "Uuau, ¿venciste a BLANCA? ¡Genial!$"

GoldenrodCity_FlowerShop_Text_FloriaItWasAMon:
	.string "¡Entonces era un POKéMON!$"


GoldenrodCity_FlowerShop_EventScript_RandomBerryGirl::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY_HNS, GoldenrodCity_FlowerShop_EventScript_AlreadyReceivedBerry
	msgbox Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
	random 8
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY_HNS
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_FlowerShop_EventScript_AlreadyReceivedBerry::
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

