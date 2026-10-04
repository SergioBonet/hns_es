SaffronCity_CopycatsHouse_2F_Frlg_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_2F_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_2F_Text_Doduo
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Doll::
	lock
	msgbox SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	checkitem ITEM_POKE_DOLL
	goto_if_eq VAR_RESULT, TRUE, EventScript_MimicTutor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale
	call_if_eq VAR_RESULT, FEMALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale
	return

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale
	return

SaffronCity_CopycatsHouse_2F_EventScript_Computer::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MySecrets, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_EventScript_Game::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale::
	.string "{PLAYER}: ¡Hola!\n"
	.string "¿Te gustan los POKéMON?\p"
	.string "{PLAYER}: Eh, no, solo te lo pregunté.\p"
	.string "{PLAYER}: ¿Eh?\n"
	.string "¡Eres rara!\p"
	.string "COPIONA: ¿Mm? ¿Que deje de imitar?\n"
	.string "¡Pero si es mi afición favorita!$"

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale::
	.string "{PLAYER}: Hola.\n"
	.string "Debes de gustarte los POKéMON.\p"
	.string "{PLAYER}: No, a mí no.\n"
	.string "Te lo pregunté a ti.\p"
	.string "{PLAYER}: ¿Perdón?\n"
	.string "¡Eres rara!\l"
	.string " \l"
	.string "COPIONA: ¿Mm? ¿Que deje de imitar?\l"
	.string "¡Pero si es mi afición favorita!$"

Text_MimicTeach::
	.string "¡Uauuu!\n"
	.string "¡Un POKé MUÑECO!\p"
	.string "¿Es para mí?\n"
	.string "¡Gracias!\p"
	.string "¿Sabes una cosa? Podría\n"
	.string "enseñarte el movimiento MIMÉTICO.$"

Text_MimicDeclined::
	.string "¿No tienes interés en MIMÉTICO?$"

Text_MimicWhichMon::
	.string "¡Bien, a mí me encanta!\n"
	.string "¿A qué POKéMON quieres que\l"
	.string "le enseñe MIMÉTICO?$"

Text_MimicTaughtMale::
	.string "{PLAYER}: ¡Hola!\n"
	.string "¡Gracias por lo de antes!\p"
	.string "{PLAYER}: ¿Sí?\p"
	.string "{PLAYER}: ¿Te divierte imitar cada\n"
	.string "uno de mis movimientos?\p"
	.string "COPIONA: ¿Verdad?\n"
	.string "¡Es muy divertido!$"

Text_MimicTaughtFemale::
	.string "{PLAYER}: ¡Hola!\n"
	.string "¡Gracias por lo de antes!\p"
	.string "{PLAYER}: ¿Sí?\p"
	.string "{PLAYER}: ¿Te divierte imitar cada\n"
	.string "uno de mis movimientos?\p"
	.string "COPIONA: ¿Verdad?\n"
	.string "¡Es muy divertido!$"

SaffronCity_CopycatsHouse_2F_Text_Doduo::
	.string "DODUO: ¡Dodu!\p"
	.string "¡ESPEJO, ESPEJITO! ¿QUIÉN ES\n"
	.string "LA MÁS BELLA DE TODAS?$"

SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll::
	.string "¡Éste es un POKéMON raro!\n"
	.string "¿Eh? ¡Pero si es un muñeco!$"

SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket::
	.string "¡Un juego de MARIO con un cubo\n"
	.string "en la cabeza!$"

SaffronCity_CopycatsHouse_2F_Text_MySecrets::
	.string "...\p"
	.string "¡Éstos son mis secretos!\p"
	.string "Habilidad: imitar.\n"
	.string "Hobby: coleccionar muñecos.\l"
	.string "POKéMON favorito: ¡CLEFAIRY!$"

