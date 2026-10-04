CeladonCity_Condominiums_1F_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_1F_EventScript_TeaWoman::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_TEA_LADY_AFTER_HOF, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy
	goto_if_set FLAG_GOT_TEA, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	msgbox CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead
	setflag FLAG_GOT_TEA
	giveitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea::
	msgbox CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany
	release
	end

CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy::
	famechecker FAMECHECKER_DAISY, 4
	setflag FLAG_TALKED_TO_TEA_LADY_AFTER_HOF
	msgbox CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Meowth
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_Clefairy::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Clefairy
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_Nidoran::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Nidoran
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_SuiteSign::
	msgbox CeladonCity_Condominiums_1F_Text_ManagersSuite, MSGBOX_SIGN
	end

CeladonCity_Condominiums_1F_Text_Meowth::
	.string "MEOWTH: ¡Meow!$"

CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead::
	.string "No deberías gastarte el dinero\n"
	.string "en latas.\p"
	.string "Toma, prueba esto.$"

CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea::
	.string "No hay nada que calme la sed\n"
	.string "mejor que el TÉ.\p"
	.string "Es lo mejor que hay.$"

CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany::
	.string "¡Mis queridos POKéMON me\n"
	.string "acompañan!\p"
	.string "¡Y MEOWTH hasta trae dinero a\n"
	.string "casa!$"

CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea::
	.string "Hola, encanto.\n"
	.string "¿Te gustó el TÉ?\p"
	.string "Ah, te quería preguntar si eres\n"
	.string "de PUEBLO PALETA.\p"
	.string "Es que allí hay una chica, DALIA,\n"
	.string "que toma TÉ a diario.\p"
	.string "Suele comprarlo en el CENTRO\n"
	.string "COMERCIAL de AZULONA.$"

CeladonCity_Condominiums_1F_Text_Clefairy::
	.string "CLEFAIRY: ¡Iry! ¡Cleclecle!$"

CeladonCity_Condominiums_1F_Text_Nidoran::
	.string "NIDORAN♀: ¡Nidor! ¡Nidoorr!$"

CeladonCity_Condominiums_1F_Text_ManagersSuite::
	.string "MANSIÓN AZULONA\n"
	.string "Suite presidencial$"

