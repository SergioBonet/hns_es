RuinsOfAlph_Outside_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RuinsOfAlph_Outside_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

RuinsOfAlph_Outside_EventScript_Quagsire::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RuinsOfAlph_Outside_Text_Quagsire:
	.string "QUAGSIRE: Quag quag$"

RuinsOfAlph_Outside_EventScript_Stan::
	trainerbattle_single TRAINER_STAN_HNS, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN_HNS, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Youngster1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Youngster2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign1::
	lock
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign2::
	lock
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign3::
	lock
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_Text_Scientist:
	.string "¿Mmm? Eso es una POKéDEX, ¿verdad?\n"
	.string "¿Puedo verla?\p"
	.string "Hay muchísimas clases de POKéMON.\p"
	.string "¿Mmm? ¿Qué es esto?\p"
	.string "¿Qué POKéMON es este?\p"
	.string "Se parece a la extraña escritura de\n"
	.string "las paredes de las\p"
	.string "RUINAS.\p"
	.string "Si esos dibujos son de verdad\n"
	.string "POKéMON, debería haber muchos más.\p"
	.string "¡Ya sé! Deja que mejore tu POKéDEX.\n"
	.string "Sígueme.$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
	.string "¿Qué quieres? Estoy estudiando. ¡No\n"
	.string "me molestes!$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
	.string "Perdona… Me deprime nuestra falta de\n"
	.string "conocimientos…$"

RuinsOfAlph_Outside_Text_SuperNerdStan_After:
	.string "Las RUINAS datan de hace unos 1.500\n"
	.string "años.\p"
	.string "Nadie sabe quién las construyó.\p"
	.string "Y tampoco sabemos si las estatuas de\n"
	.string "los POKéMON significan algo.\p"
	.string "Es un gran misterio…$"

RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
	.string "¡Mmm…! ¡Qué lugar tan extraño!$"

RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
	.string "…$"

RuinsOfAlph_Outside_Text_PsychicNathan_After:
	.string "Me gusta pensar aquí.$"

RuinsOfAlph_Outside_Text_MysteryChamberSign:
	.string "SALA DEL PANEL DE PIEDRA MISTERIOSO$"

RuinsOfAlph_Outside_Text_MainSign:
	.string "RUINAS ALFA ¡Bienvenidos!$"

RuinsOfAlph_Outside_Text_ResearchSign:
	.string "CENTRO DE INVESTIGACIÓN DE LAS\n"
	.string "RUINAS ALFA\p"
	.string "LA AUTORIDAD EN LAS RUINAS ALFA$"

RuinsOfAlph_Outside_Text_Fisher1:
	.string "Mientras explorábamos las RUINAS, de\n"
	.string "repente notamos una extraña\l"
	.string "presencia.\p"
	.string "Nos asustamos y huimos.\p"
	.string "Tu también debes tener cuidado.$"

RuinsOfAlph_Outside_Text_Fisher2:
	.string "¡Las RUINAS esconden un gran\n"
	.string "secreto!\p"
	.string "Creo…$"

RuinsOfAlph_Outside_Text_Youngster1:
	.string "Hay muchas clases de UNOWN, así que\n"
	.string "los usamos para nuestros códigos\l"
	.string "secretos.$"

RuinsOfAlph_Outside_Text_Youngster2:
	.string "A… D… E… L… A… N… T… E… Mmmmmm…\p"
	.string "¿Qué?\p"
	.string "¡Estoy decodificando el mensaje!$"
