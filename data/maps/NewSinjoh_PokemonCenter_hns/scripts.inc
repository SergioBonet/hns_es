NewSinjoh_PokemonCenter_hns_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_PokemonCenter_OnTransition
    .byte 0

NewSinjoh_PokemonCenter_OnTransition: 
    setrespawn HEAL_LOCATION_NEW_SINJOH_HNS
    end

NewSinjoh_EventScript_Artist::
	lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT, NewSinjoh_EventScript_ZoomLens_Gotten
	msgbox NewSinjoh_Text_Artist, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_EventScript_ZoomLens_No
	msgbox Text_ItemGiveaway, MSGBOX_DEFAULT
	giveitem ITEM_ZOOM_LENS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT
	release
	end

NewSinjoh_PokemonCenter_EventScript_Skiier::
	lock
	faceplayer
	msgbox NewSinjoh_PokemonCenter_Text_Skiier, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_NEWSINJOH_POKEMONCENTER_SKIIER, DIR_NORTH
	release
	end

NewSinjoh_PokemonCenter_hns_Map::
	lockall
	setvar VAR_0x8000, 1 @ SCREENSHOT_SINJOH_MAP
	msgbox NewSinjoh_PokemonCenter_hns_Text_0, MSGBOX_DEFAULT
	closemessage
	callnative OpenScreenshotsFromScript
	waitstate
	releaseall
	end

NewSinjoh_PokemonCenter_Text_Skiier:
	.string "Con la nieve cuesta orientarse por\n"
	.string "aquí.\p"
	.string "Todo parece igual.\p"
	.string "¡Así que este mapa es de gran ayuda!\p"
	.string "¡Qué región tan bonita!$"

NewSinjoh_Text_Artist:
	.string "¡He encontrado mucha inspiración en\n"
	.string "este pueblo escondido!\p"
	.string "¿No te parece que el paisaje quita el\n"
	.string "aliento?$"

Text_ItemGiveaway:
	.string "¡Ya veo! ¡Tú también debes de ser\n"
	.string "artista!\p"
	.string "¡Tengo algo de sobra que te ayudará a\n"
	.string "fijarte en los pequeños detalles de la\l"
	.string "vida!$"

NewSinjoh_Text_Artist_No:
	.string "No serás de esos que odian a los\n"
	.string "turistas, ¿verdad? La belleza está\l"
	.string "para compartirla.$"

NewSinjoh_EventScript_ZoomLens_No::
	msgbox NewSinjoh_Text_Artist_No, MSGBOX_DEFAULT
	release
	end

NewSinjoh_EventScript_ZoomLens_Gotten::
	msgbox Text_WasGiven_ZoomLensAlready, MSGBOX_DEFAULT
	release
	end

Text_WasGiven_ZoomLensAlready:
	.string "¡Espero que disfrutes de esa lente!$"

NewSinjoh_EventScript_FemAce::
	msgbox NewSinjoh_Text_FemAce, MSGBOX_NPC
	end

NewSinjoh_Text_FemAce:
	.string "En NUEVO SINJOH no tenemos muchas\n"
	.string "comodidades modernas.\p"
	.string "Pero al menos tenemos este CENTRO\n"
	.string "POKéMON.$"


NewSinjoh_PokemonCenter_hns_Text_0:
	.string "{PLAYER} ha mirado con atención el\n"
	.string "mapa de SINJOH.$"
