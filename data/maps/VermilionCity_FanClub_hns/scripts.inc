VermilionCity_FanClub_hns_MapScripts::
	.byte 0

VermilionCity_FanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_eq VAR_FAN_CLUB_GUY, 1, VermilionCity_FanClub_EventScript_ChairmanAfter
	msgbox PokemonFanClub_Text_Chairman_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_FanClub_EventScript_ChairmanRefused
	msgbox PokemonFanClub_Text_Chairman_Rapidash, MSGBOX_DEFAULT
	msgbox PokemonFanClub_Text_Chairman_Gift, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_GUY, 1
	msgbox PokemonFanClub_Text_Chairman_Candy, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanRefused::
	msgbox PokemonFanClub_Text_Chairman_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanAfter::
	msgbox PokemonFanClub_Text_Chairman_MoreTales, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Woman1::
	msgbox PokemonFanClub_Text_Receptionist, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_Woman2::
	msgbox PokemonFanClub_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_ClefairyGuy::
	lock
	faceplayer
	msgbox PokemonFanClub_Text_ClefairyGuy_Adorable, MSGBOX_DEFAULT
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 1, VermilionCity_FanClub_EventScript_ClefairyGiveDoll
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 2, VermilionCity_FanClub_EventScript_ClefairyAfter
	msgbox PokemonFanClub_Text_ClefairyGuy_MakingDo, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyGiveDoll::
	msgbox PokemonFanClub_Text_ClefairyGuy_ReturnDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	removeobject LOCALID_FAN_CLUB_CLEFAIRY_DOLL
	fadescreenswapbuffers FADE_FROM_BLACK
	giveitem ITEM_LOST_ITEM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_CLEFAIRY, 2
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyAfter::
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Bayleef::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BAYLEEF, CRY_MODE_NORMAL
	msgbox PokemonFanClub_Text_Bayleef, MSGBOX_DEFAULT
	waitmoncry
	release
	end


PokemonFanClub_Text_Chairman_Intro:
	.string "Soy el PRESIDENTE del CLUB de FANS de\n"
	.string "POKéMON.\p"
	.string "He curado a más de 150 POKéMON.\p"
	.string "Soy muy exigente cuando se trata de\n"
	.string "POKéMON.\p"
	.string "¿Has venido para saber de mis\n"
	.string "POKéMON?$"

PokemonFanClub_Text_Chairman_Rapidash:
	.string "¡Muy bien! ¡Pues escucha!\p"
	.string "Mi… preferido es RAPIDASH…\p"
	.string "Es… gracioso… cariñoso… veloz e\n"
	.string "increíble… ¿No crees…? Es\l"
	.string "sorprendente… simpático… ¡Y lo\l"
	.string "quiero!\p"
	.string "Si lo abrazas… cuando duerme… es tan\n"
	.string "cálido… y mimoso… Es espectacular…\l"
	.string "encantador… ¡Uuups! ¡Mira qué hora es!\l"
	.string "¡Hablo demasiado!$"

PokemonFanClub_Text_Chairman_Gift:
	.string "¡Gracias por escucharme! ¡Toma esto!$"

PokemonFanClub_Text_Chairman_Candy:
	.string "Es un CARAMELO RARO que fortalece a\n"
	.string "los POKéMON.\p"
	.string "Prefiero que mis POKéMON luchen para\n"
	.string "fortalecerse. ¡Así que toma!$"

PokemonFanClub_Text_Chairman_MoreTales:
	.string "¡Hey, {PLAYER}!\p"
	.string "¿Te digo algo sobre mis POKéMON?\p"
	.string "¿No? Oh… Tengo más historias que\n"
	.string "contar…$"

PokemonFanClub_Text_Chairman_Disappointed:
	.string "¡Qué pena…!\p"
	.string "¡Vuelve cuando quieras!$"

PokemonFanClub_Text_Receptionist:
	.string "Al PRESIDENTE le encanta hablar\n"
	.string "cuando se trata de POKéMON…$"

@=Clefairy=Guy=========================================================================================================
PokemonFanClub_Text_ClefairyGuy_Adorable:
	.string "Me encanta el modo en que CLEFAIRY\p"
	.string "mueve el dedo para usar METRÓNOMO.\p"
	.string "¡Es tan adorable!$"

PokemonFanClub_Text_ClefairyGuy_MakingDo:
	.string "Me gusta CLEFAIRY, pero jamás podría\n"
	.string "atrapar uno. Por eso me conformo con\l"
	.string "este POKé MUÑECO que he encontrado.$"

PokemonFanClub_Text_ClefairyGuy_ReturnDoll:
	.string "¡Ah, entiendo! La niña que perdió el\p"
	.string "POKé MUÑECO está triste…\p"
	.string "Vale. ¿Podrías devolverle este\p"
	.string "POKé MUÑECO a esa pobre niña?\p"
	.string "Un día me haré amigo de un\p"
	.string "CLEFAIRY real. ¡No te preocupes!$"

PokemonFanClub_Text_ClefairyGuy_GoingToGetOne:
	.string "¡Ya verás! Voy a hacerme amigo de un\n"
	.string "auténtico CLEFAIRY.$"

@============================================================================================================================

PokemonFanClub_Text_Teacher:
	.string "¡Mira mi precioso BAYLEEF!\p"
	.string "¡Lleva una hoja tan mona!$"

PokemonFanClub_Text_ClefairyDoll:
	.string "¡Es un CLEFAIRY! ¿Verdad?\p"
	.string "¡No! Es un POKé MUÑECO CLEFAIRY.$"

PokemonFanClub_Text_Bayleef:
	.string "BAYLEEF: ¡Liliif!$"

PokemonFanClub_Text_Listen:
	.string "Escuchemos atentamente a los\n"
	.string "entrenadores.$"

PokemonFanClub_Text_Bragging:
	.string "Si alguno alardea, hazlo tú también.$"
