VioletCity_TrainerSchool_hns_MapScripts::
	.byte 0

VioletCity_TrainerSchool_EventScript_Earl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_EarlIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy1::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy2::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Girl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Twin::
	msgbox VioletCity_TrainerSchool_Text_Twin, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_BlackBoard::
	lock
	msgbox VioletCity_TrainerSchool_Text_Blackboard, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_Text_Twin:
	.string "No soy de la generación de la GBA,\n"
	.string "¡pero me encantan los juegos de\l"
	.string "POKéMON!\p"
	.string "En los juegos antiguos, tenías que\n"
	.string "luchar contra muchísimos POKéMON\l"
	.string "salvajes para conseguir suficiente\l"
	.string "EXP.\p"
	.string "Pero en los juegos más nuevos, el\n"
	.string "REPARTIR EXP hace que tus POKéMON\l"
	.string "suban de nivel demasiado rápido.\p"
	.string "En este juego, el REPARTIR EXP está\n"
	.string "equilibrado para que tus POKéMON\l"
	.string "tengan el nivel justo. O un poco más\l"
	.string "alto, según cuántos combates hagas.\p"
	.string "Si quieres una experiencia tradicional\n"
	.string "de las GEN 1-4, desactiva el REPARTIR\l"
	.string "EXP. Si quieres una experiencia\l"
	.string "moderna, actívalo.\p"
	.string "¡Tú eliges cómo quieres jugar!$"

VioletCity_TrainerSchool_Text_EarlIntro:
	.string "¡EARL soy yo!\p"
	.string "¡Maravillosos los POKéMON son, sí!\p"
	.string "¡Enseñarte a ser mejor ENTRENADOR yo\n"
	.string "haré!$"

VioletCity_TrainerSchool_Text_Teacher:
	.string "Algunos POKéMON empiezan siendo\n"
	.string "débiles y necesitan mucha más EXP que\l"
	.string "otros para hacerse fuertes.\p"
	.string "Por ejemplo, LARVITAR es bastante\n"
	.string "débil, pero con el tiempo se convertirá\l"
	.string "en un poderoso TYRANITAR, a costa de\l"
	.string "mucha EXP.\p"
	.string "Solo los ENTRENADORES más entregados\n"
	.string "deberían intentar criar a un POKéMON\l"
	.string "así.$"

VioletCity_TrainerSchool_Text_TeachHowToWin:
	.string "¡Bien! ¡A ti yo te enseñaré!\p"
	.string "¡En combate, los primeros POKéMON\n"
	.string "salen antes!\p"
	.string "¡Quizá sea más fácil si cambias el\n"
	.string "orden!\p"
	.string "¿Quieres que te cuente más cosas?$"

VioletCity_TrainerSchool_Text_TeachMore:
	.string "¿Quieres saber cómo educar bien a los\n"
	.string "POKéMON?$"

VioletCity_TrainerSchool_Text_TeachRaiseWell:
	.string "¡Bien! ¡Enseñarte, yo haré!\p"
	.string "Si los POKéMON salen al combate,\n"
	.string "aunque sea un momento, algunos\l"
	.string "PUNTOS de EXP.\p"
	.string "consiguen. Al principio de la lista, pon\n"
	.string "a los POKéMON débiles.\p"
	.string "¡Cámbialos rápido en combate! ¡Así,\n"
	.string "los POKéMON débiles fuertes\p"
	.string "se vuelven!$"

VioletCity_TrainerSchool_Text_NoMoreToTeach:
	.string "¡Oh! ¡Listo alumno eres! ¡Nada más te\n"
	.string "enseño!\p"
	.string "¡Si quieres más, habla con los alumnos!$"

VioletCity_TrainerSchool_Text_Youngster1:
	.string "Los POKéMON que se creía que solo\n"
	.string "evolucionaban por intercambio pueden\p"
	.string "evolucionar subiendo de nivel.\n"
	.string "MACHOKE y GRAVELER evolucionan\p"
	.string "al NV. 38, mientras que KADABRA y\n"
	.string "HAUNTER evolucionan al NV. 42.\p"
	.string "También se ha descubierto que algunos\n"
	.string "objetos, como el REVEST. METÁLICO,\l"
	.string "hacen\p"
	.string "evolucionar a ciertos POKéMON si los\n"
	.string "llevan al subir de nivel.$"

VioletCity_TrainerSchool_Text_GameboyKid1:
	.string "¡Los POKéMON más destacados de cada\n"
	.string "zona se pueden ver en el mapa!\p"
	.string "¡Pero no te olvides de mirar las rutas\n"
	.string "de DÍA y de NOCHE!$"

VioletCity_TrainerSchool_Text_GameboyKid2:
	.string "Las BAYAS de la región de JOHTO sirven\n"
	.string "para curar y hacer BALLS.\p"
	.string "Las BAYAS de KANTO sirven para\n"
	.string "reducir las estadísticas de un\l"
	.string "POKéMON.\p"
	.string "El DOJO de KANTO ayuda a los POKéMON a\n"
	.string "perfeccionar estadísticas concretas.$"

VioletCity_TrainerSchool_Text_Youngster2:
	.string "Ten en cuenta que ahora tus rivales\n"
	.string "usan equipos con mejor cobertura de\l"
	.string "tipos, así que espera un viaje mucho\l"
	.string "más desafiante.$"

VioletCity_TrainerSchool_Text_Blackboard:
	.string "La pizarra describe los movimientos de\n"
	.string "MO de los POKéMON.\p"
	.string "Las MO, una vez desbloqueadas, no\n"
	.string "hace falta enseñarlas para usarlas.$"

VioletCity_TrainerSchool_Text_Notebook:
	.string "Es el cuaderno de este niño…\p"
	.string "Captura POKéMON usando POKé BALL.\p"
	.string "Tu equipo puede tener hasta seis.\p"
	.string "¿Sigues leyendo?$"

VioletCity_TrainerSchool_Text_Notebook1:
	.string "Antes de lanzar la POKé BALL, debes\n"
	.string "debilitarlo.\p"
	.string "Atrapar un POKéMON quemado o\n"
	.string "envenenado es mucho más fácil.\p"
	.string "¿Sigues leyendo?$"

VioletCity_TrainerSchool_Text_Notebook2:
	.string "Algunos ataques causan confusión.\p"
	.string "Un POKéMON confuso puede atacarse a\n"
	.string "sí mismo.\p"
	.string "Retirarlo del combate, eliminará su\n"
	.string "confusión.\p"
	.string "¿Sigues leyendo?$"

VioletCity_TrainerSchool_Text_Notebook3:
	.string "Quienes atrapan POKéMON y los usan\n"
	.string "para luchar son entrenadores.\p"
	.string "Su misión es ir a los GIMNASIOS\p"
	.string "y vencer a otros entrenadores.\p"
	.string "La hoja siguiente está… ¡vacía!\p"
	.string "Niño: Eh, eh…\p"
	.string "No he escrito nada más…$"

VioletCity_TrainerSchool_Text_StickerMachine:
	.string "¡Esta supermáquina imprime los datos\n"
	.string "como pegatinas!$"
