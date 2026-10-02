TinTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_OnTransition
	.byte 0

TinTower_OnTransition::
	setescapewarp MAP_BELLCHIME_TRAIL_HNS, 35, 42
	end

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
	.string "De acuerdo con la leyenda…\p"
	.string "Cuando las almas de los POKéMON y los\n"
	.string "humanos se unan, descenderá de los\l"
	.string "cielos un POKéMON con los colores del\l"
	.string "arco iris…\p"
	.string "¿Quiere eso decir que el POKéMON\p"
	.string "legendario está probando a los\n"
	.string "humanos?$"

TinTower_1F_Sage2_Text:
	.string "Se dice que, cuando la TORRE\p"
	.string "LATÓN se quemó, tres POKéMON\n"
	.string "anónimos perecieron. Fue una\l"
	.string "tragedia.\p"
	.string "Sin embargo…\p"
	.string "Un POKéMON con los colores del arco\n"
	.string "iris…\p"
	.string "En otras palabras…\p"
	.string "HO-OH descendió desde el cielo y\n"
	.string "devolvió la vida a los tres POKéMON.\p"
	.string "Son…\p"
	.string "SUICUNE, ENTEI y RAIKOU.\p"
	.string "Eso es lo que dicen…$"

TinTower_1F_Sage3_Text:
	.string "Se dice que las dos TORRES fueron\n"
	.string "construidas para fomentar la amistad\l"
	.string "entre los POKéMON y la gente.\p"
	.string "Eso ocurrió hace 700 años, pero la\n"
	.string "idea se mantiene intacta.$"

TinTower_1F_Sage4_Text1:
	.string "¡Parece que HO-OH se ha posado sobre\n"
	.string "la TORRE HOJALATA!$"

TinTower_1F_Sage4_Text2:
	.string "Se dice que los POKéMON legendarios\n"
	.string "encarnan tres poderes…\p"
	.string "El rayo que alcanzó la TORRE…\p"
	.string "El fuego que quemó la TORRE…\p"
	.string "Y la lluvia que apagó dicho fuego…$"

TinTower_1F_Sage6_Text2:
	.string "De los POKéMON legendarios, se dice\n"
	.string "que SUICUNE es el más cercano a\l"
	.string "HO-OH.\p"
	.string "Además, he oído que también puede\n"
	.string "haber una conexión con los POKéMON\l"
	.string "UNOWN.\p"
	.string "Los POKéMON UNOWN deben de tener un\n"
	.string "lazo de unión con SUICUNE.$"

TinTower_1F_EusineHoOh_Text:
	.string "Lo sabía.\p"
	.string "Sabía que llegarías a ver al POKéMON\n"
	.string "de los colores del arcoíris, <PLAYER>.\p"
	.string "Ha pasado tal y como lo imaginé. Mi\n"
	.string "investigación no está nada mal, si se\l"
	.string "me permite decirlo.\p"
	.string "Voy a seguir estudiando a los POKéMON\n"
	.string "para convertirme en un POKéMANÍACO\l"
	.string "famoso.$"

TinTower_1F_EusineSuicune_Text:
	.string "EUSINE: ¡Impresionante! ¡Demasiado\n"
	.string "impresionante, incluso! Nunca había\l"
	.string "visto un combate tan grandioso.\p"
	.string "Ha sido muy inspirador. SUICUNE era\n"
	.string "duro, pero tú has estado aún más\p"
	.string "increíble, <PLAYER>. He oído que el\n"
	.string "poder místico de SUICUNE\p"
	.string "invoca a un POKéMON de color arcoíris.\n"
	.string "Quizás, solo quizás, lo que ha pasado\l"
	.string "hoy\p"
	.string "haga que aparezca ese POKéMON. Voy a\n"
	.string "estudiar más las leyendas.\p"
	.string "Gracias por enseñarme ese combate\n"
	.string "tan fantástico.\p"
	.string "¡Hasta luego, <PLAYER>!$"
