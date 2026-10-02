NewSinjoh_House1_hns_MapScripts::
	.byte 0


NewSinjoh__House1_EventScripts_Elizabeth::
    lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVEWOOPER, NewSinjoh_House1_EventScript_Elizabeth_AfterGift
    msgbox NewSinjoh_House1_Text_Looking4Celebi MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_House1_EventScript_Decline
    checkspecies SPECIES_CELEBI
    goto_if_eq VAR_RESULT, TRUE, NewSinjoh_House1_EventScript_GiveWooperPaldea
	msgbox NewSinjoh_House1_Text_NicePokemonButNotCelebi, MSGBOX_DEFAULT
    release
    end

NewSinjoh_House1_EventScript_Decline::
	msgbox NewSinjoh_House1_Text_Decline, MSGBOX_DEFAULT
	closemessage
	release
	end

NewSinjoh_House1_EventScript_GiveWooperPaldea::
	playse SE_PIN
    applymovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH
    msgbox NewSinjoh_House1_OffersWooper MSGBOX_DEFAULT
    setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_WOOPER_PALDEA
    bufferspeciesname STR_VAR_1, SPECIES_WOOPER_PALDEA
    givemon SPECIES_WOOPER_PALDEA, 5
	call Common_EventScript_GiftMon
	setflag FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVEWOOPER
	closemessage
    release
    end

NewSinjoh_House1_Text_Looking4Celebi:
	.string "¡Hola, ENTRENADOR!\p"
	.string "¿Has venido desde PUEBLO PRIMAVERA?\p"
	.string "Tengo una petición para alguien que\n"
	.string "ha viajado tanto como tú. Verás, mi\l"
	.string "POKéMON favorito del mundo entero\l"
	.string "resulta ser el POKéMON singular\l"
	.string "conocido como CELEBI.\p"
	.string "Si por casualidad tienes uno, ¿te\n"
	.string "importaría enseñármelo?$"

NewSinjoh_House1_Text_NicePokemonButNotCelebi:
	.string "Ese POKéMON que tienes es\n"
	.string "maravilloso, pero no es exactamente lo\l"
	.string "que buscaba…$"

NewSinjoh_House1_OffersWooper:
	.string "¡Eso es! ¡¡Es un CELEBI de verdad!!\p"
	.string "Muchísimas gracias por traerlo hasta\n"
	.string "el norte para que lo vea.\p"
	.string "Toma, mi novia atrapó demasiados de\n"
	.string "estos en su viaje a una región lejana…\p"
	.string "Por favor, acepta este WOOPER\n"
	.string "especial como agradecimiento,\l"
	.string "{PLAYER}.$"

NewSinjoh_House1_Text_Decline:
	.string "Qué pena. Tenía muchas ganas de ver\n"
	.string "uno.$"

NewSinjoh_House1_Text_TakeCareOfWooper:
	.string "Cuida bien de ese WOOPER por mí,\n"
	.string "¿vale?$"

NewSinjoh_House1_EventScript_Elizabeth_AfterGift::
	msgbox NewSinjoh_House1_Text_GoodToSeeYouAgain MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Text_GoodToSeeYouAgain:
	.string "Me alegro de volver a verte, {PLAYER}.\p"
	.string "¿Qué tal tratas a ese WOOPER?$"

NewSinjoh_House1_Bookshelf::
    lock
	msgbox NewSinjoh_House1_Bookshelf_Text MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Bookshelf_Text:
	.string "¡Es una estantería repleta de\n"
	.string "videojuegos y novelas gráficas!$"

NewSinjoh_House1_Eevee::
    lock
	faceplayer
	playmoncry SPECIES_EEVEE, 0
	msgbox NewSinjoh_House1_Text_Eevee_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_House1_Text_Eevee_Cry:
	.string "¿Vee vee?$"
