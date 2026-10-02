CeladonCity_Apartments_2F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_2F_EventScript_Computer::
	lock
	playse SE_PC_ON
	msgbox CeladonMansion2F_Text_Computer
	playse SE_PC_OFF
	waitse
	release
	end

CeladonCity_Apartments_2F_EventScript_Sign::
	msgbox CeladonMansion2F_Text_DevOfficeSign, MSGBOX_SIGN
	end

CeladonMansion2F_Text_Computer:
	.string "{PLAYER} encendió el PC.\p"
	.string "…\p"
	.string "Alguien estaba escribiendo un e-mail.\p"
	.string "Espero que vengas a KANTO.\p"
	.string "Te sorprenderás de cuánto han\n"
	.string "cambiado las cosas por aquí.\p"
	.string "También verás muchos POKéMON\p"
	.string "que no son nativos de JOHTO.\p"
	.string "Al PRODUCTOR\p"
	.string "…$"

CeladonMansion2F_Text_DevOfficeSign:
	.string "OFICINA DE DESARROLLO DE HEART &\n"
	.string "SOUL$"

CeladonMansion2F_EventScript_LilDill::
	msgbox CeladonMansion2F_Text_LilDill, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_InfiniteBacon::
	msgbox CeladonMansion2F_Text_InfiniteBacon, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_TixoRebel::
	msgbox CeladonMansion2F_Text_TixoRebel, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Phant::
	msgbox CeladonMansion2F_Text_Phant, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Exclsior::
	msgbox CeladonMansion2F_Text_Exclsior, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_DaniRainbow::
    msgbox CeladonMansion2F_Text_DaniRaibow, MSGBOX_NPC
    end

CeladonMansion2F_Text_LilDill:
	.string "Hola a todos, parche 15…\p"
	.string "Perdón, quería decir…\p"
	.string "¡Hola, soy el DIRECTOR DEL JUEGO!\p"
	.string "He hecho los mapas, los gráficos, los\n"
	.string "scripts y mucho más.\p"
	.string "Pero no lo habría conseguido sin el\n"
	.string "resto del equipo y los probadores.\p"
	.string "¡Gracias por jugar! Espero que hayas\n"
	.string "disfrutado de POKéMON HEART & SOUL.$"

CeladonMansion2F_Text_InfiniteBacon:
	.string "¡Estamos rehaciendo este juego en\n"
	.string "pokeemerald expansion!$"

CeladonMansion2F_Text_TixoRebel:
	.string "¿Has oído hablar de LA\n"
	.string "HUEVIFICACIÓN? Fue un fallo de las\l"
	.string "pruebas que convertía POKéMON en\l"
	.string "HUEVOS al azar.\p"
	.string "¡Yo desarrollé la solución!$"

CeladonMansion2F_Text_Phant:
	.string "¡Me encantan los DEMAKES!\p"
	.string "¿Has jugado a SWORD AND SHIELD\n"
	.string "ULTIMATE PLUS - ENGLISH? ¡Lo traduje\l"
	.string "yo!\p"
	.string "Para mi próximo DEMAKE, creo que haré\n"
	.string "ALOLA.$"

CeladonMansion2F_Text_Exclsior:
	.string "¡Hice los sprites de surf únicos para\n"
	.string "cada POKéMON!\p"
	.string "Como el proyecto es de CÓDIGO\n"
	.string "ABIERTO, ¡tú también puedes añadir\l"
	.string "tus propias funciones!$"

CeladonMansion2F_Text_DaniRaibow:
	.string "¡Hola!\p"
	.string "Se me da bastante bien encontrar\n"
	.string "problemas, y puedo arreglar los\l"
	.string "pequeños.\p"
	.string "¿Quieres oír un chiste?\p"
	.string "LANCE intentó enseñarle a DRAGONITE\n"
	.string "el movimiento DRAGOALIENTO.\p"
	.string "Pero DRAGONITE iba tan rápido por\n"
	.string "VELOC. EXTREMA que ¡no pudo cogerle el\l"
	.string "aliento!$"
