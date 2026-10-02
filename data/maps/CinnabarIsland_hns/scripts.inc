CinnabarIsland_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0
	
CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	callnative SetTimeBasedEncounters
	end

CinnabarIsland_EventScript_Blaine::
    lock
    faceplayer
    msgbox CinnabarIsland_Text_Blaine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CINNABAR_BLAINE
    removeobject LOCALID_CINNABAR_BLAINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BLAINE
    release
    end

CinnabarIsland_Text_Blaine:
	.string "BLAINE: ¡No me rendiré hasta el día en\n"
	.string "que haya reconstruido el GIMNASIO de\l"
	.string "ISLA CANELA!\p"
	.string "Hasta entonces, estaré en el DOJO\n"
	.string "KARATE.$"



CinnabarIsland_EventScript_Blue::
	lock
	faceplayer
	goto_if_eq VAR_NUM_BADGES, 15, CinnabarIsland_EventScript_BlueActive
	msgbox CinnabarIsland_Text_BlueBefore, MSGBOX_NPC
	release
	end

CinnabarIsland_EventScript_BlueActive::
	msgbox CinnabarIsland_Text_Blue, MSGBOX_NPC
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CINNABAR_BLUE
	removeobject LOCALID_CINNABAR_BLUE
	clearflag FLAG_HIDE_VIRIDIAN_BLUE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


CinnabarIsland_Text_BlueBefore:
	.string "¿Quién eres?\p"
	.string "Bueno, salta a la vista que eres\n"
	.string "ENTRENADOR…\p"
	.string "Me llamo AZUL.\p"
	.string "Fui CAMPEÓN, aunque solo durante un\n"
	.string "tiempo…\p"
	.string "Ese entrometido de ROJO acabó\n"
	.string "conmigo…\p"
	.string "En fin, ¿qué quieres? ¿Desafiarme o\n"
	.string "algo así?\p"
	.string "… Me fastidia decirlo, pero ahora no\n"
	.string "estoy de humor para luchar.\p"
	.string "Mira bien a tu alrededor…\p"
	.string "Un volcán entra en erupción y, sin más,\n"
	.string "desaparece una ciudad entera.\p"
	.string "Podemos seguir ganando y perdiendo\n"
	.string "en combates POKéMON. Pero basta con\l"
	.string "que la naturaleza se agite un poco\l"
	.string "para perderlo todo en un segundo.\p"
	.string "…\p"
	.string "Así son las cosas…\p"
	.string "Pero, de todos modos, sigo siendo\n"
	.string "ENTRENADOR.\p"
	.string "Si veo a un rival fuerte, me entran\n"
	.string "ganas de luchar.\p"
	.string "Si quieres luchar conmigo, primero\n"
	.string "necesitarás 15 medallas.\p"
	.string "Entonces me enfrentaré a ti.$"

CinnabarIsland_Text_Blue:
	.string "¿Quién eres tú?\p"
	.string "Es evidente que entrenas POKéMON…\p"
	.string "Me llamo AZUL.\p"
	.string "Y una vez fui el CAMPEÓN, pero sólo\n"
	.string "durante poco tiempo…\p"
	.string "El entrometido de ROJO me ganó…\p"
	.string "¡Pero qué más da! ¿Y tú qué quieres?\p"
	.string "¿Has venido a desafiarme?\p"
	.string "Lo siento, pero no, ahora no tengo\n"
	.string "ganas de luchar.\p"
	.string "Echa un vistazo a tu alrededor…\p"
	.string "Un volcán entra en erupción y una\n"
	.string "ciudad entera desaparece.\p"
	.string "En POKéMON se puede ganar o perder,\n"
	.string "pero si se tuercen las cosas se puede\l"
	.string "perder enseguida.\p"
	.string "…\p"
	.string "Así son las cosas…\p"
	.string "Sin embargo, sigo siendo entrenador.\p"
	.string "Y encontrarme con un rival fuerte me\n"
	.string "anima a luchar.\p"
	.string "Si quieres luchar contra mí, ven al\p"
	.string "GIMNASIO de la CIUDAD VERDE.\p"
	.string "Y aceptaré tu desafío…$"

CinnabarIsland_EventScript_Sign::
	msgbox CinnabarIsland_Text_Sign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_GymSign:
	.string "Aquí hay una nota…\p"
	.string "El GIMNASIO DE ISLA CANELA se ha\n"
	.string "trasladado a ISLAS ESPUMA.\p"
	.string "BLAINE$"

CinnabarIsland_Text_Sign:
	.string "ISLA CANELA\p"
	.string "La abrasadora isla del ardiente deseo$"

