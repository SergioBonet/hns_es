Route47_hns_MapScripts::
	.byte 0


Route47_EventScript_Hiker::
	trainerbattle_single TRAINER_DEVIN_HNS, Route47_Text_HikerSeen, Route47_Text_HikerBeaten
	msgbox Route47_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_HikerSeen::
	.string "Echar de menos a los demás… es lo que\n"
	.string "hay.\p"
	.string "Pero un combate es un combate, ¡así\n"
	.string "que vamos!$"

Route47_Text_HikerBeaten::
	.string "¡Juajajá!$"

Route47_Text_HikerAfter::
	.string "¡Después de un combate, siempre hay\n"
	.string "que despedirse con una carcajada!$"

Route47_EventScript_Camper::
	trainerbattle_single TRAINER_GRANT_HNS, Route47_Text_CamperSeen, Route47_Text_CamperBeaten
	msgbox Route47_Text_CamperAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_CamperSeen::
	.string "No me gustan las multitudes, ¡así que\n"
	.string "estoy de acampada aquí con mis\l"
	.string "POKéMON!$"

Route47_Text_CamperBeaten::
	.string "Supongo que debería adentrarme más\n"
	.string "en la montaña…$"

Route47_Text_CamperAfter::
	.string "¡NOS VEMOS!$"

Route47_EventScript_Thom::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Kae::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple1Seen::
	.string "THOM: Uno más uno son dos. ¡Pero los\n"
	.string "dos juntos somos mucho más fuertes!\p"
	.string "KAE: ¡No somos una pareja aburrida\n"
	.string "cualquiera!$"

Route47_Text_Couple1Beaten::
	.string "THOM: No me lo esperaba.\l"
	.string "KAE: ¡Tú también eres poco común!$"

Route47_Text_Couple1After1::
	.string "Cad: Tu increíble fuerza es\n"
	.string "incalculable.$"

Route47_Text_Couple1After2::
	.string "KAE: Pensaba que eras un ENTRENADOR\n"
	.string "solitario corriente. ¡Pues me\l"
	.string "equivocaba!$"

Route47_EventScript_Duff::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple2After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Eda::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox Route47_Text_Couple2After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple2Seen::
	.string "DUFF: ¡Cuidar de mi novia me hace volar\n"
	.string "el corazón!\p"
	.string "EDA: ¡Lo que siento por mi novio es tan\n"
	.string "ancho y profundo como el océano!$"

Route47_Text_Couple2Beaten::
	.string "DUFF: No era rival para ti…\l"
	.string "EDA: Eres increíble…$"

Route47_Text_Couple2After1::
	.string "DUFF: ¡Gracias por este combate\n"
	.string "impresionante! ¡Adiós!$"

Route47_Text_Couple2After2::
	.string "EDA: ¡Tú también deberías encontrar\n"
	.string "una pareja maravillosa!$"

Route47_EventScript_Sage::
	lock
	faceplayer
	msgbox EmbeddedTower_Text_OldManIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

EmbeddedTower_Text_OldManIntro:
	.string "¡Vaya, hola!\p"
	.string "Dicen que al otro lado de este agujero\n"
	.string "había una torre enorme que llegaba\l"
	.string "hasta el cielo.\p"
	.string "Dicen que era una torre bastante\n"
	.string "extraña, con la mitad metida en el\l"
	.string "acantilado.\p"
	.string "¡No solo era una torre alta que llegaba\n"
	.string "al cielo, sino que también se hundía en\l"
	.string "las profundidades de la tierra!\p"
	.string "¡Se rumorea que llegaba incluso al\n"
	.string "fondo del océano!\p"
	.string "En resumen, las ruinas unían el cielo,\n"
	.string "la tierra y el mar…\p"
	.string "La mayor parte de la torre se ha\n"
	.string "derrumbado, y lo único que queda es la\l"
	.string "entrada y su interior, donde verás\l"
	.string "unos dibujos extraños.$"

Route47_EventScript_Item_Pearl::
    finditem ITEM_PEARL
    end

Route47_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route47_EventScript_Item_WhiteFlute::
    finditem ITEM_WHITE_FLUTE
    end

Route47_EventScript_Item_Stardust::
	finditem ITEM_STARDUST
	end

Route47_EventScript_Item_LuckyPunch::
	finditem ITEM_LUCKY_PUNCH
	end

Route47_EventScript_Chinchou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINCHOU, CRY_MODE_NORMAL
	msgbox Route47_Text_Chinchou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route47_Text_Chinchou:
	.string "CHINCHOU: ¡Chou!$"
