GoldenrodCity_UndergroundStorage_hns_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Director::
    lock
    faceplayer
    checkitem ITEM_CARD_KEY
    goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundStorage_EventScript_Director2
    msgbox RadioTowerBasement_Text_DirectorIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_CARD_KEY
    msgbox RadioTowerBasement_Text_DirectorCardKey, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Director2::
    msgbox RadioTowerBasement_Text_DirectorAfter, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Grunt19::
    trainerbattle_single TRAINER_GRUNT_19_HNS, RadioTowerBasement_Text_GruntM24Seen, RadioTowerBasement_Text_GruntM24Beaten
	msgbox RadioTowerBasement_Text_GruntM24After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Grunt12::
    trainerbattle_single TRAINER_GRUNT_12_HNS, RadioTowerBasement_Text_GruntM14Seen, RadioTowerBasement_Text_GruntM14Beaten
	msgbox RadioTowerBasement_Text_GruntM14After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Eto::
    trainerbattle_single TRAINER_ETO_3_HNS, RadioTowerBasement_Text_GruntM15Seen, RadioTowerBasement_Text_GruntM15Beaten
	msgbox RadioTowerBasement_Text_GruntM15After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Item_TM_CALM_MIND::
    finditem ITEM_TM_CALM_MIND
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

RadioTowerBasement_Text_GruntM24Seen:
	.string "¿Cómo has llegado hasta aquí?\p"
	.string "Supongo que no pudieron evitarlo.\n"
	.string "¡Acabaré contigo!$"

RadioTowerBasement_Text_GruntM24Beaten:
	.string "Acabó conmigo…$"

RadioTowerBasement_Text_GruntM24After:
	.string "El TEAM ROCKET seguirá esperando el\n"
	.string "regreso de GIOVANNI.\p"
	.string "Haremos lo que sea necesario.$"

RadioTowerBasement_Text_GruntM14Seen:
	.string "¡No vas a ir más lejos!\p"
	.string "¡Soy implacable con mis enemigos y con\n"
	.string "cualquier joven!$"

RadioTowerBasement_Text_GruntM14Beaten:
	.string "¡Maldición!$"

RadioTowerBasement_Text_GruntM14After:
	.string "He perdido…\p"
	.string "¡Perdóname, GIOVANNI!$"

RadioTowerBasement_Text_GruntM15Seen:
	.string "¡Ja, ja, ja! ¡Mira quién está aquí!\p"
	.string "¿Listo? ¡Ahora soy muy fuerte!$"

RadioTowerBasement_Text_GruntM15Beaten:
	.string "¡Ja, ja, ja! ¡Qué bueno eres!\p"
	.string "Esto del TEAM ROCKET es solo un\n"
	.string "trabajo, pero ya veo que hace daño a\l"
	.string "los demás.\p"
	.string "Se acabó, me largo.\p"
	.string "Muchísimas gracias. ¡Lo siento,\n"
	.string "GIOVANNI!$"

RadioTowerBasement_Text_GruntM15After:
	.string "¡Ji, ji, ji! ¡Vaya combate! ¡No te\n"
	.string "olvidaré!$"

RadioTowerBasement_Text_DirectorIntro:
	.string "DIRECTOR: ¿Quién? ¿Qué? ¿Has venido a\n"
	.string "rescatarme?\p"
	.string "¡Gracias!\p"
	.string "La TORRE RADIO.\p"
	.string "¿Qué está pasando ahí dentro?\p"
	.string "¿Invadida por el TEAM ROCKET?\p"
	.string "Mira. Toma esta LLAVE MAGNÉTICA.$"

RadioTowerBasement_Text_DirectorCardKey:
	.string "Director: Úsala para abrir la puerta de\n"
	.string "la segunda planta.\p"
	.string "$"

RadioTowerBasement_Text_DirectorAfter:
	.string "Te ruego que me ayudes.\p"
	.string "¡Quién sabe lo que harían si se\n"
	.string "apoderaran de la emisora!\p"
	.string "¡Podrían hasta controlar a los\p"
	.string "POKéMON usando una señal especial!\p"
	.string "Sólo tú puedes ayudarme.\p"
	.string "Salva la TORRE RADIO…\p"
	.string "¡Y a todos los POKéMON del mundo!$"
