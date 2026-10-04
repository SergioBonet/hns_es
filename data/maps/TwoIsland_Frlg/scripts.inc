TwoIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_OnTransition
	.byte 0

TwoIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_TWO_ISLAND
	setflag FLAG_VISITED_TWO_ISLAND
	call TwoIsland_EventScript_SetShopState
	end

TwoIsland_EventScript_SetShopState::
	goto_if_set FLAG_IS_CHAMPION, TwoIsland_EventScript_SetShopStateAfterHoennLink
	goto_if_set FLAG_SYS_GAME_CLEAR, TwoIsland_EventScript_SetShopStateAfterChampion
	goto_if_set FLAG_RESCUED_LOSTELLE, TwoIsland_EventScript_SetShopStateAfterLostelleRescue
	goto TwoIsland_EventScript_SetShopStateDefault
	end

TwoIsland_EventScript_SetShopStateAfterHoennLink::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_SetShopExpanded1
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_2, TwoIsland_EventScript_SetShopExpanded2
	goto TwoIsland_EventScript_SetShopExpanded3
	end

TwoIsland_EventScript_SetShopStateAfterChampion::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_RESCUED_LOSTELLE, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_SetShopExpanded1
	goto TwoIsland_EventScript_SetShopExpanded2
	end

TwoIsland_EventScript_SetShopStateAfterLostelleRescue::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto TwoIsland_EventScript_SetShopExpanded1
	end

TwoIsland_EventScript_SetShopStateDefault::
	goto TwoIsland_EventScript_SetShopInitial
	end

TwoIsland_EventScript_SetShopInitial::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 1
	return

TwoIsland_EventScript_SetShopExpanded1::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 2
	clearflag FLAG_HIDE_TWO_ISLAND_WOMAN
	return

TwoIsland_EventScript_SetShopExpanded2::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 3
	clearflag FLAG_HIDE_TWO_ISLAND_BEAUTY
	return

TwoIsland_EventScript_SetShopExpanded3::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 4
	clearflag FLAG_HIDE_TWO_ISLAND_SUPER_NERD
	return

TwoIsland_EventScript_Clerk::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 4, TwoIsland_EventScript_ClerkShopExpanded3
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 3, TwoIsland_EventScript_ClerkShopExpanded2
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 2, TwoIsland_EventScript_ClerkShopExpanded1
	goto TwoIsland_EventScript_ClerkShopInitial
	end

TwoIsland_EventScript_ClerkShopExpanded3::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_3, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_3
	message TwoIsland_Text_BringingItemsFromDistantLands
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded3
	end

TwoIsland_EventScript_ClerkShopExpanded2::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_2, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_2
	message TwoIsland_Text_HopeYouGiveItYourBest
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded2
	end

TwoIsland_EventScript_ClerkShopExpanded1::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_1
	message TwoIsland_Text_AddedMerchandiseForLostelle
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded1
	end

TwoIsland_EventScript_ClerkShopInitial::
	goto_if_set FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_INTRODUCED
	message TwoIsland_Text_WelcomeToShopMerchandiseLimited
	waitmessage
	goto TwoIsland_EventScript_ShopInitial
	end

TwoIsland_EventScript_ClerkShopSkipIntro::
	message gText_HowMayIServeYou
	waitmessage
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 4, TwoIsland_EventScript_ShopExpanded3
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 3, TwoIsland_EventScript_ShopExpanded2
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 2, TwoIsland_EventScript_ShopExpanded1
	goto TwoIsland_EventScript_ShopInitial
	end

TwoIsland_EventScript_ShopInitial::
	pokemart TwoIsland_Items_ShopInitial
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopInitial::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_ShopExpanded1::
	pokemart TwoIsland_Items_ShopExpanded1
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopExpanded1::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_ShopExpanded2::
	pokemart TwoIsland_Items_ShopExpanded2
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopExpanded2::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_ShopExpanded3::
	pokemart TwoIsland_Items_ShopExpanded3
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopExpanded3::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_Sailor::
	msgbox TwoIsland_Text_FellowMovedFromCeladonCity, MSGBOX_NPC
	end

TwoIsland_EventScript_Woman::
	msgbox TwoIsland_Text_ShopkeepersBrotherWorksGameCorner, MSGBOX_NPC
	end

TwoIsland_EventScript_Beauty::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 4
	msgbox TwoIsland_Text_BrunoCameToIslandWhileBack
	release
	end

TwoIsland_EventScript_SuperNerd::
	msgbox TwoIsland_Text_BuyRareItemsHere, MSGBOX_NPC
	end

TwoIsland_EventScript_Boy::
	msgbox TwoIsland_Text_OldWomanLivesOutOnCape, MSGBOX_NPC
	end

TwoIsland_EventScript_LittleBoy::
	msgbox TwoIsland_Text_HaveYouTriedJumpingGame, MSGBOX_NPC
	end

TwoIsland_EventScript_IslandSign::
	msgbox TwoIsland_Text_IslandSign, MSGBOX_SIGN
	end

TwoIsland_EventScript_JoyfulGameCornerSign::
	msgbox TwoIsland_Text_JoyfulGameCornerSign, MSGBOX_SIGN
	end

TwoIsland_EventScript_FastCurrentSign::
	msgbox TwoIsland_Text_DangerFastCurrent, MSGBOX_SIGN
	end

TwoIsland_Text_IslandSign::
	.string "ISLA SECUNDA\n"
	.string "Isla ideal para dos.$"

TwoIsland_Text_JoyfulGameCornerSign::
	.string "¡Salta y atrapa!\n"
	.string "RECREATIVOS alegres$"

TwoIsland_Text_DangerFastCurrent::
	.string "¡PELIGRO! ¡FUERTES RÁPIDOS!\n"
	.string "Queda terminantemente prohibido\l"
	.string "pescar y bañarse.$"

TwoIsland_Text_WelcomeToShopMerchandiseLimited::
	.string "¡Hola!\n"
	.string "¡Ésta es mi tienda!\p"
	.string "Hemos abierto hace muy poco.\p"
	.string "Aún no tenemos mucha variedad\n"
	.string "de artículos, pero espero que\l"
	.string "encuentres lo que buscas.$"

TwoIsland_Text_AddedMerchandiseForLostelle::
	.string "No sabes cómo te agradecemos\n"
	.string "que hayas rescatado a PEDRITA.\p"
	.string "Gracias a ti, la gente de ISLA\n"
	.string "TERA, tiene otra actitud hacia\l"
	.string "los habitantes de KANTO.\p"
	.string "Y yo soy de KANTO, ¿sabes?\p"
	.string "Por los habitantes de ISLA TERA,\n"
	.string "he aumentado el número\l"
	.string "de artículos.$"

TwoIsland_Text_HopeYouGiveItYourBest::
	.string "¡Eh, yo aquí hago lo que puedo!\n"
	.string "¡Espero que tú, también, {PLAYER}!$"

TwoIsland_Text_BringingItemsFromDistantLands::
	.string "¡Hola, {PLAYER}!\n"
	.string "¿Qué tal?\p"
	.string "He estado importando artículos\n"
	.string "de otras islas de por ahí.\p"
	.string "Y tengo unas cosas rarísimas.\n"
	.string "¡Échales un vistazo!$"

TwoIsland_Text_FellowMovedFromCeladonCity::
	.string "Ese tipo de ahí, vino de CIUDAD\n"
	.string "AZULONA para instalarse aquí.\p"
	.string "Montó una tienda con su hermano\n"
	.string "pequeño.\p"
	.string "Me parece a mí que no sabía en\n"
	.string "lo que se metía.$"

TwoIsland_Text_ShopkeepersBrotherWorksGameCorner::
	.string "El hermano del tendero encontró\n"
	.string "trabajo en los RECREATIVOS.\p"
	.string "Y pretende ahorrar dinero\n"
	.string "para comprar más artículos\l"
	.string "para la tienda.$"

TwoIsland_Text_BrunoCameToIslandWhileBack::
	.string "Oye, oye, ¿sabes una cosa?\p"
	.string "Hace poco, vino un ENTRENADOR\n"
	.string "a la ISLA.\p"
	.string "Era uno de los miembros del ALTO\n"
	.string "MANDO. Se llamaba BRUNO.\p"
	.string "Pero se fue decepcionado cuando\n"
	.string "vio que no quedaban bastones de\l"
	.string "caramelo superfuertes.$"

TwoIsland_Text_BuyRareItemsHere::
	.string "¡El experto ENTRENADOR sabe\n"
	.string "comprar objetos raros!$"

TwoIsland_Text_OldWomanLivesOutOnCape::
	.string "Hay una señora que vive en una\n"
	.string "casita en el cabo.\p"
	.string "Es un poco desconcertante,\n"
	.string "¡le tira los tejos a los POKéMON!$"

TwoIsland_Text_HaveYouTriedJumpingGame::
	.string "¡Boing! ¡Boing!\n"
	.string "¿Has probado el juego de los\l"
	.string "saltos?\p"
	.string "Los POKéMON que pueden\n"
	.string "participar...\l"
	.string "¡Boing! ¡Boing!\p"
	.string "¡Algunos dan saltos!\p"
	.string "¡Y otros, dan saaaaaaaaaaaltos!\p"
	.string "¿Lo sabías?\n"
	.string "¡Boing! ¡Boing!$"

