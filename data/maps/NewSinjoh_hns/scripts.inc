NewSinjoh_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_On_Transition
	.byte 0

NewSinjoh_On_Transition:
    setflag FLAG_VISITED_NEW_SINJOH
	end

NewSinjoh_EventScript_TriggerNorthGate::
	lock
	msgbox NewSinjoh_Text_TriggerNorthGate, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	release
	end

NewSinjoh_Text_TriggerNorthGate:
	.string "Mejor no hacer esperar a las CHICAS\n"
	.string "KIMONO.$"

NewSinjoh_EventScript_PetStantler::
    lock
	faceplayer
	playmoncry SPECIES_STANTLER, 0
	msgbox NewSinjoh_Text_Stantler_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Text_Stantler_Cry:
	.string "¡Lerrrrr!$"

NewSinjoh_EventScript_Steven::
	msgbox NewSinjoh_Text_Steven, MSGBOX_AUTOCLOSE
	end

NewSinjoh_Text_Steven:
	.string "MÁXIMO: Señora, ¿quiere que la ayude a\n"
	.string "llegar a la fuente termal de allí?\p"
	.string "Parece que hay sitio de sobra.$"

NewSinjoh_MilkMan_EventScript_Seller::
	lock
	faceplayer
	checkitem ITEM_MOOMOO_MILK, 99
	goto_if_eq VAR_RESULT, 1, MilkMan_EventScript_Battle
	showmoneybox 0, 0
	msgbox NewSinjoh_MilkMan_text_BuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, NewSinjoh_EventScript_MilkMan_BuyMilk
	msgbox NewSinjoh_MilkMan_NoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

NewSinjoh_EventScript_MilkMan_BuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_MilkMan_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_MilkMan_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox NewSinjoh_MilkMan_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, NewSinjoh_EventScript_MilkMan_BuyMilk

	msgbox NewSinjoh_MilkMan_GotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox NewSinjoh_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSinjoh_MilkMan_BagFull::
	msgbox NewSinjoh_MilkMan_NoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

NewSinjoh_MilkMan_NotEnough::
	msgbox NewSinjoh_MilkMan_NoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSinjoh_MilkMan_text_BuyMilk:
	.string "Soy el Lechero.\p"
	.string "Mi leche es deliciosa.\p"
	.string "Si quieres un poco hoy, te costará\n"
	.string "¥500.$"

NewSinjoh_MilkMan_GotMilk:
	.string "¡Aquí tienes! Enriquecida con lo que\n"
	.string "el mundo quiere.$"

NewSinjoh_MilkMan_NoMoney:
	.string "Lo siento. Consigue dinero y entonces\n"
	.string "habrá trato.$"

NewSinjoh_MilkMan_NoRoom:
	.string "Parece que tienes la MOCHILA llena.$"

NewSinjoh_MilkMan_NoSale:
	.string "¿No la quieres? Tiene lo que el mundo\n"
	.string "se merece.$"

NewSinjoh_MilkMan_Text_WouldYouLikeAnother:
	.string "¿Qué tal otra?$"

NewSinjoh_Text_GotMilk:
	.string "¡{PLAYER} ha conseguido LECHE MU-MU!$"

MilkMan_EventScript_Battle:: 
    msgbox MilkMan_Battle_text
    Trainerbattle_no_intro TRAINER_MILKMAN_HNS, NewSinjoh_MilkMan_text_Lose
    release
    end

MilkMan_Battle_text:
	.string "Soy el Lechero.\p"
	.string "Mi leche es deliciosa.\p"
	.string "¡Hoy hay reparto especial!$"

NewSinjoh_MilkMan_text_Lose:
	.string "Este mundo es perfecto, ¿verdad?$"

NewSinjoh_Script_TravelMart::
	lock
	faceplayer
	message NewSinjoh_Text_TravelShopGreeting
	waitmessage
	pokemart NewSinjoh_Pokemart_TravelShop
	msgbox NewSinjoh_Text_TravelShopEnd, MSGBOX_DEFAULT
	release
	end

	.align 2
NewSinjoh_Pokemart_TravelShop:
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_ELIXER
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_MAX_LURE
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NONE

NewSinjoh_Text_TravelShopGreeting:
	.string "Bienvenido a mi pequeña tienda de\n"
	.string "suministros. ¿En qué puedo ayudarte?$"

NewSinjoh_Text_TravelShopEnd:
	.string "Vuelve cuando quieras.$"

Script_NewSinjoh_Traveler_Brother::
	lock
	faceplayer
	msgbox NewSinjoh_Text_TravelBrother_Greeting
	release
	end

NewSinjoh_Text_TravelBrother_Greeting:
	.string "¡Todos nuestros productos son\n"
	.string "caseros y de la zona!\p"
	.string "Mi hermana mayor abrió esta tienda\n"
	.string "porque la empresa de las TIENDAS\l"
	.string "POKéMON no quiere abrir un local tan\l"
	.string "lejos de una ciudad grande.$"

NewSinjoh_EventScript_Josh::
	msgbox NewSinjoh_Text_Josh, MSGBOX_NPC
	end

NewSinjoh_Text_Josh:
	.string "¡Este sitio es una pasada!\p"
	.string "Esconder estas fuentes termales al\n"
	.string "mundo es un crimen.\p"
	.string "¡Se lo voy a contar a todos mis amigos!$"

NewSinjoh_EventScript_Janice::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_JaniceAfter
	msgbox NewSinjoh_Text_Janice, MSGBOX_NPC
	end
NewSinjoh_EventScript_JaniceAfter::
	msgbox NewSinjoh_Text_JaniceAfter, MSGBOX_NPC
	end

NewSinjoh_Text_Janice:
	.string "Estas fuentes termales son mágicas,\n"
	.string "pero tengo la sensación de que los de\l"
	.string "aquí nos miran mal.$"
NewSinjoh_Text_JaniceAfter:
	.string "Estas fuentes termales son mágicas,\n"
	.string "¡y los de aquí son muy amables cuando\l"
	.string "los conoces!$"

NewSinjoh_EventScript_OldLady1::
	msgbox NewSinjoh_Text_OldLady1, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady1:
	.string "No hay nada como unas buenas vistas\n"
	.string "para reanimar a este viejo.$"

NewSinjoh_EventScript_OldLady2::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady2Steven
	msgbox NewSinjoh_Text_OldLady2, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady2Steven::
	msgbox NewSinjoh_Text_OldLady2Steven, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady2:
	.string "¡Genial, ahora estos turistas\n"
	.string "acaparan nuestras fuentes termales!\p"
	.string "¡Últimamente no paran de pasar cosas\n"
	.string "malas!$"
NewSinjoh_Text_OldLady2Steven:
	.string "¡Qué joven tan apuesto!\p"
	.string "Quizá estos turistas no sean tan\n"
	.string "malos, después de todo.$"

NewSinjoh_EventScript_OldLady3::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady3After
	msgbox NewSinjoh_Text_OldLady3, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady3After::
	msgbox NewSinjoh_Text_OldLady3After, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady3:
	.string "¿Cómo puede esa mujer ser tan\n"
	.string "maleducada con nuestros visitantes?\p"
	.string "Tendría que darse un baño en las\n"
	.string "fuentes termales.\p"
	.string "Hay sitio para todos.$"
NewSinjoh_Text_OldLady3After:
	.string "Parece que por aquí todos se están\n"
	.string "acostumbrando los unos a los otros.\p"
	.string "¡Bien!$"

NewSinjoh_EventScript_SpringsSage::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_SpringsSageAfter
	msgbox NewSinjoh_Text_SpringsSage, MSGBOX_NPC
	end
NewSinjoh_EventScript_SpringsSageAfter::
	msgbox NewSinjoh_Text_SpringsSageAfter, MSGBOX_NPC
	end

NewSinjoh_Text_SpringsSage:
	.string "Desde que llegaron los recién\n"
	.string "llegados, en nuestra comunidad hay\l"
	.string "mucha división y discordia.\p"
	.string "Sea cual sea tu punto de vista, está\n"
	.string "claro que se ha alterado el equilibrio.\p"
	.string "Por favor, sé amable tanto con los de\n"
	.string "aquí como con los turistas.$"
NewSinjoh_Text_SpringsSageAfter:
	.string "Las cosas van mejor desde que se\n"
	.string "calmó a los POKéMON legendarios.\p"
	.string "El equilibrio ha vuelto a SINJOH.$"

NewSinjoh_EventScript_Sage2::
	msgbox NewSinjoh_Text_Sage2, MSGBOX_NPC
	end

NewSinjoh_Text_Sage2:
	.string "Los tiempos cambian, pero los\n"
	.string "STANTLER siguen reuniéndose. Por eso\l"
	.string "podemos estar agradecidos.$"

NewSinjoh_EventScript_Daughter::
	msgbox NewSinjoh_Text_Daughter, MSGBOX_NPC
	end

NewSinjoh_Text_Daughter:
	.string "¡¡Yupiiiii!!\p"
	.string "¡Mira, mamá! ¡Sin manos!\p"
	.string "¡Como los del snowboard!$"

NewSinjoh_EventScript_Mother::
	lock
	faceplayer
	msgbox NewSinjoh_Text_Mother, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_NEWSINJOH_MOTHER, DIR_EAST
	release
	end

NewSinjoh_Text_Mother:
	.string "¡Mira cómo va mi niño, qué rico!\p"
	.string "Esta pista lleva aquí generaciones,\n"
	.string "pero los niños nunca la usaban hasta\l"
	.string "que llegaron los recién llegados.$"

NewSinjoh_EventScript_Welcome_Sign::
	msgbox NewSinjoh_Text_Welcome_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Welcome_Sign:
	.string "NUEVO SINJOH$"

NewSinjoh_EventScript_Resturant_Sign::
	msgbox NewSinjoh_Text_Resturant_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Resturant_Sign:
	.string "CAFETERÍA FAMILIAR$"

NewSinjoh_EventScript_Cave_Sign::
	msgbox NewSinjoh_Text_Cave_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Cave_Sign:
	.string "CUEVA DE LAS FUENTES TERMALES$"

NewSinjoh_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_HikerAfter
	msgbox NewSinjoh_Text_Hiker, MSGBOX_NPC
	end
NewSinjoh_EventScript_HikerAfter::
	msgbox NewSinjoh_Text_HikerAfter, MSGBOX_NPC
	end

NewSinjoh_Text_Hiker:
	.string "¡El negocio va viento en popa! Pero los\n"
	.string "precios han subido desde que la gente\l"
	.string "de ciudad se interesó por nuestro\l"
	.string "pueblecito.$"
NewSinjoh_Text_HikerAfter:
	.string "¡El negocio va viento en popa!\p"
	.string "¡Y con las propinas que deja ese chico\n"
	.string "de pelo plateado, los precios han\l"
	.string "bajado!$"

NewSinjoh_EventScript_OldLady4::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady4After
	msgbox NewSinjoh_Text_OldLady4, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady4After::
	msgbox NewSinjoh_Text_OldLady4After, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady4:
	.string "¡Solo le vendo a la gente de aquí!$"
NewSinjoh_Text_OldLady4After:
	.string "¡SIGO vendiéndole solo a la gente de\n"
	.string "aquí!$"

NewSinjoh_EventScript_Item_DuskBall::
	finditem ITEM_DUSK_BALL
    end


