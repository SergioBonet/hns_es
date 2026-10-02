Route41_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE_HNS, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
	.string "Aquí el agua está templada. Estoy muy\n"
	.string "a gusto.\p"
	.string "¡Claro que lucharé contigo!$"

Route41_Text_SwimmermCharlieBeaten:
	.string "¡Vaya! ¡Estoy como una pasa!$"

Route41_Text_SwimmermCharlieAfter:
	.string "Isn't it relaxing just floating\n"
	.string "like this?$"

Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE_HNS, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "Estoy cansado. Si gano, ¿me prestas\n"
	.string "tus POKéMON?$"

Route41_Text_SwimmermGeorgeBeaten:
	.string "Uf, uf…$"

Route41_Text_SwimmermGeorgeAfter:
	.string "CIUDAD ORQUÍDEA está muy lejos.\p"
	.string "Pero tampoco es fácil volver a CIUDAD\n"
	.string "OLIVO.\p"
	.string "¿Qué se puede hacer?$"

Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE_HNS, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "¿Ves esas islas aisladas por\n"
	.string "torbellinos?\p"
	.string "¡Tiene que haber un secreto!$"

Route41_Text_SwimmermBerkeBeaten:
	.string "¿Cuál es tu secreto?$"

Route41_Text_SwimmermBerkeAfter:
	.string "Era de noche y llovía…\p"
	.string "Vi un POKéMON gigante volando desde\n"
	.string "las islas.\p"
	.string "Dejaba caer las plumas de sus alas\n"
	.string "plateadas.$"

Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK_HNS, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "Aquí hay mucho oleaje.\p"
	.string "Cuesta mucho nadar.$"

Route41_Text_SwimmermKirkBeaten:
	.string "¡Me has vencido!$"

Route41_Text_SwimmermKirkAfter:
	.string "La corriente me impide llegar a las\n"
	.string "islas.$"

Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW_HNS, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "¿Estás buscando el secreto de las\n"
	.string "ISLAS REMOLINO?$"

Route41_Text_SwimmermMathewBeaten:
	.string "¡Ooh, tienes una gran resistencia!$"

Route41_Text_SwimmermMathewAfter:
	.string "Un secreto sobre ISLAS REMOLINO…\p"
	.string "¡Dentro está muy oscuro!$"

Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE_HNS, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "Voy hacia las ISLAS REMOLINO.\p"
	.string "Voy a explorarlas con unos amigos.$"

Route41_Text_SwimmerfKayleeBeaten:
	.string "¿Así es como lo haces?$"

Route41_Text_SwimmerfKayleeAfter:
	.string "There's supposed to be a big\n"
	.string "POKéMON deep beneath WHIRL ISLANDS.\p"
	.string "I wonder what it could be?$"

Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE_HNS, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "Estás tan elegante sobre tu POKéMON.$"

Route41_Text_SwimmerfSusieBeaten:
	.string "He perdido…$"

Route41_Text_SwimmerfSusieAfter:
	.string "¿No había una canción famosa sobre\n"
	.string "un niño que montaba un LAPRAS?$"

Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE_HNS, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "¡No me puedo creer el buen día que\n"
	.string "hace!$"

Route41_Text_SwimmerfDeniseBeaten:
	.string "¡Oooh!$"

Route41_Text_SwimmerfDeniseAfter:
	.string "El sol es muy malo para la piel.\p"
	.string "Pero yo no uso protección solar.\p"
	.string "No quiero ensuciar el agua.$"

Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA_HNS, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "Si necesitas descansar, flota y\n"
	.string "déjate llevar por el viento, así no\l"
	.string "malgastarás tus fuerzas.$"

Route41_Text_SwimmerfKaraBeaten:
	.string "¡Oh! Tienes más energía que yo.$"

Route41_Text_SwimmerfKaraAfter:
	.string "He oído rugidos procedentes de las\n"
	.string "ISLAS.$"

Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY_HNS, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "Por la noche, los STARYU se reúnen\n"
	.string "cerca de la superficie.$"

Route41_Text_SwimmerfWendyBeaten:
	.string "¡Oh, vaya…!$"

Route41_Text_SwimmerfWendyAfter:
	.string "Los grupos de STARYU se iluminan al\n"
	.string "mismo tiempo.\p"
	.string "Es muy bonito, pero da miedo.$"

Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
	.string "TENTACRUEL: Cruooo...$"

Route41_Text_TentacruelAttack:
	.string "TENTACRUEL: CRUOOOOOO!$"

Route41_Text_TentacruelHeal:
	.string "The TENTACRUEL used RECOVER!\n"
	.string "It is fully healed!$"
