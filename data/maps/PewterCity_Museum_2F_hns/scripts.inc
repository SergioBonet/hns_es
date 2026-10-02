PewterCity_Museum_2F_hns_MapScripts::
	.byte 0


PewterCity_Museum_2F_EventScript_Nerd::
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Dad::
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Meteor::
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "Dicen que unos meteoritos cayeron en\n"
	.string "la ISLA ORIGEN.\p"
	.string "Nos encantaría exponerlos aquí, en\n"
	.string "nuestro museo, pero…\p"
	.string "Dicen que esos meteoritos emiten una\n"
	.string "energía extraña y que no se pueden\l"
	.string "transportar…$"

PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
	.string "¡Quiero un PIKACHU! ¡Es tan mono!\p"
	.string "¡Le he pedido a mi papá que me atrape\n"
	.string "uno!$"

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
	.string "Sí, pronto tendrás un PIKACHU, te lo\n"
	.string "prometo.$"

PewterCity_Museum_2F_Text_SpaceShuttle::
	.string "Transbordador espacial$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
	.string "Un meteorito que cayó en el MT. MOON.\n"
	.string "Se cree que es una PIEDRA LUNAR.$"
