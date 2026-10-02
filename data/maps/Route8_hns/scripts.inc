Route8_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE_HNS, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	msgbox Route8_Text_BikerDwayneAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Harris::
	trainerbattle_single TRAINER_HARRIS_HNS, Route8_Text_BikerHarrisSeen, Route8_Text_BikerHarrisBeaten
	msgbox Route8_Text_BikerHarrisAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE_HNS, Route8_Text_BikerZekeSeen, Route8_Text_BikerZekeBeaten
	msgbox Route8_Text_BikerZekeAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sam::
	trainerbattle_single TRAINER_SAM_HNS, Route8_Text_SupernerdSamSeen, Route8_Text_SupernerdSamBeaten
	msgbox Route8_Text_SupernerdSamAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Tom::
	trainerbattle_single TRAINER_TOM_HNS, Route8_Text_SupernerdTomSeen, Route8_Text_SupernerdTomBeaten
	msgbox Route8_Text_SupernerdTomAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneSeen:
	.string "Somos el grupo de ENTRENADORES de la\n"
	.string "FEDERACIÓN POKéMON de KANTO.\p"
	.string "¡Te vamos a pasar por encima con\n"
	.string "nuestras ruedas!$"

Route8_Text_BikerDwayneBeaten:
	.string "¡Lo… lo siento!$"

Route8_Text_BikerDwayneAfter:
	.string "¡Viva la FEDERACIÓN POKéMON de KANTO!$"

Route8_Text_BikerHarrisSeen:
	.string "La policía ha cerrado la VÍA\p"
	.string "SUBTERRÁNEA. ¡Qué fastidio!$"

Route8_Text_BikerHarrisBeaten:
	.string "¡Per… perdóname!$"

Route8_Text_BikerHarrisAfter:
	.string "¡Destruido por alguien de Johto!…$"

Route8_Text_BikerZekeSeen:
	.string "¡Somos la FEDERACIÓN POKéMON de\n"
	.string "KANTO! ¡Toma ya!$"

Route8_Text_BikerZekeBeaten:
	.string "¡Vaya! ¡Perdona!$"

Route8_Text_BikerZekeAfter:
	.string "Intentaremos no molestar a nadie a\n"
	.string "partir de ahora.$"

Route8_Text_SupernerdSamSeen:
	.string "¿Cómo funciona el MAGNETOTRÉN?$"

Route8_Text_SupernerdSamBeaten:
	.string "Quiero ver el MAGNETOTRÉN…$"

Route8_Text_SupernerdSamAfter:
	.string "¡El poder de los imanes es inmenso!$"

Route8_Text_SupernerdTomSeen:
	.string "Mmm… Tienes muchas MEDALLAS de\n"
	.string "GIMNASIO.$"

Route8_Text_SupernerdTomBeaten:
	.string "Tal y como pensaba. ¡Eres fuerte!$"

Route8_Text_SupernerdTomAfter:
	.string "Las MEDALLAS de GIMNASIO te dan\n"
	.string "ventaja en los combates.$"

Route8_Text_LockedDoor:
	.string "Está cerrada…$"

Route8_Text_UndergroundPathSign:
	.string "El cartel está roto.\p"
	.string "Es imposible leerlo…$"
