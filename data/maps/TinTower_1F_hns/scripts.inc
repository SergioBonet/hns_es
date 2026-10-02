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
	.string "I knew it.\p"
	.string "I knew you'd get to see the POKéMON\n"
	.string "of rainbow colors, <PLAYER>.\p"
	.string "It happened just as I envisioned.\n"
	.string "My research isn't bad, I might say.\p"
	.string "I'm going to keep studying POKéMON\n"
	.string "to become a famous POKéMANIAC!$"

TinTower_1F_EusineSuicune_Text:
	.string "EUSINE: Awesome! Too awesome, even!\n"
	.string "I've never seen a battle that great.\p"
	.string "That was truly inspiring to see.\n"
	.string "SUICUNE was tough, but you were even\p"
	.string "more incredible, <PLAYER>.\n"
	.string "I heard SUICUNE's mystic power\p"
	.string "summons a rainbow-colored POKéMON.\n"
	.string "Maybe, just maybe, what went on today\p"
	.string "will cause that POKéMON to appear.\n"
	.string "I'm going to study the legends more.\p"
	.string "Thanks for showing me that fantastic\n"
	.string "battle.\p"
	.string "Later, <PLAYER>!$"
