SSAqua_B1F_hns_MapScripts::
	.byte 0

SSAqua_B1F_EventScript_Trigger::
	lock
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0 
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_SOUTH
	release
	end

SSAqua_B1F_EventScript_SailorLookingForBuddy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SSAQUA_SAILOR, SSAqua_B1F_EventScript_SailorLookingFoundBuddy
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SailorLookingFoundBuddy::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorThanks, MSGBOX_DEFAULT
	goto_if_lt VAR_SSAQUA_STATE, 5, SSAqua_B1F_EventScript_SailorGirl
	closemessage
	release
	end
SSAqua_B1F_EventScript_SailorGirl::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorSawGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SleepySailor::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorDirections, MSGBOX_NPC
	end

SSAqua_B1F_EventScript_Barfcan::
	msgbox SSAqua_B1F_Text_BarfCan, MSGBOX_SIGN
	end

SSAqua_B1F_Text_BarfCan:
	.string "¡Puaj! ¡No debería haber mirado!$"

SSAqua_B1F_Text_FastShipOnDutySailor:
	.string "¡Eh! ¿Podrías buscar a mi compañero?\p"
	.string "¡Está haciendo de las suyas en algún\n"
	.string "sitio! ¡El muy vago!\p"
	.string "Me gustaría ir a buscarle, pero estoy\n"
	.string "de servicio.$"

SSAqua_B1F_Text_FastShipOnDutySailorRefused:
	.string "¡Oh…!\p"
	.string "El CAPITÁN se pondrá furioso…$"

SSAqua_B1F_Text_FastShipOnDutySailorThanks:
	.string "¡Gracias, joven! ¡Le he echado una\n"
	.string "buena bronca y se ha tranquilizado!$"

SSAqua_B1F_Text_FastShipOnDutySailorSawGirl:
	.string "¿Una niña pequeña?\p"
	.string "Puede que la haya visto por aquí.$"

SSAqua_B1F_Text_FastShipOnDutySailorDirections:
	.string "El comedor está ahí delante.\p"
	.string "Las escaleras del fondo conducen al\n"
	.string "camarote del CAPITÁN.$"

SSAqua_B1F_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF_HNS, SSAqua_B1F_Text_SailorJeffSeen, SSAqua_B1F_Text_SailorJeffBeaten
	msgbox SSAqua_B1F_Text_SailorJeffAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorJeffSeen:
	.string "No hay nada mejor que un combate en mi\n"
	.string "tiempo libre.$"

SSAqua_B1F_Text_SailorJeffBeaten:
	.string "¡Gane o pierda, se acabó el descanso!$"

SSAqua_B1F_Text_SailorJeffAfter:
	.string "Supongo que no ganaré si no me lo tomo\n"
	.string "en serio.$"

SSAqua_B1F_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA_HNS, SSAqua_B1F_Text_PicnickerDebraSeen, SSAqua_B1F_Text_PicnickerDebraBeaten
	msgbox SSAqua_B1F_Text_PicnickerDebraAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_PicnickerDebraSeen:
	.string "Me aburro tanto… ¿Quieres luchar?\p"
	.string "$"

SSAqua_B1F_Text_PicnickerDebraBeaten:
	.string "¡Uau! ¡Eres demasiado fuerte!$"

SSAqua_B1F_Text_PicnickerDebraAfter:
	.string "AZAFRÁN… AZULONA…\p"
	.string "Dicen que hay muchas ciudades\n"
	.string "grandes en KANTO.$"

SSAqua_B1F_EventScript_Fritz::
	trainerbattle_single TRAINER_FRITZ_HNS, SSAqua_B1F_Text_JugglerFritzSeen, SSAqua_B1F_Text_JugglerFritzBeaten
	msgbox SSAqua_B1F_Text_JugglerFritzAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_JugglerFritzSeen:
	.string "¡Urrf…! ¡Estoy mareado!$"

SSAqua_B1F_Text_JugglerFritzBeaten:
	.string "No me puedo mover…$"

SSAqua_B1F_Text_JugglerFritzAfter:
	.string "No vuelvo a ir en barco. La próxima vez\n"
	.string "viajaré en el MAGNETOTRÉN.$"

SSAqua_B1F_EventScript_Garrett::
	trainerbattle_single TRAINER_GARRETT_HNS, SSAqua_B1F_Text_SailorGarrettSeen, SSAqua_B1F_Text_SailorGarrettBeaten
	msgbox SSAqua_B1F_Text_SailorGarrettAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorGarrettSeen:
	.string "¡Aquí es donde trabajamos!$"

SSAqua_B1F_Text_SailorGarrettBeaten:
	.string "He perdido en mi propio campo…$"

SSAqua_B1F_Text_SailorGarrettAfter:
	.string "Cuando vamos de CIUDAD CARMÍN a\n"
	.string "Ciudad Olivo los pasajeros no son los\l"
	.string "mismos.$"

SSAqua_B1F_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH_HNS, SSAqua_B1F_Text_FisherJonahSeen, SSAqua_B1F_Text_FisherJonahBeaten
	msgbox SSAqua_B1F_Text_FisherJonahAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_FisherJonahSeen:
	.string "¡Aunque estemos en el mar, no puedo\n"
	.string "pescar!\p"
	.string "¡Qué aburrido! ¡Luchemos!$"

SSAqua_B1F_Text_FisherJonahBeaten:
	.string "Ya… Ya no me aburro…$"

SSAqua_B1F_Text_FisherJonahAfter:
	.string "Voy a pescar en los muelles de CIUDAD\n"
	.string "CARMÍN.$"

SSAqua_B1F_EventScript_Wai::
	trainerbattle_single TRAINER_WAI_HNS, SSAqua_B1F_Text_BlackbeltWaiSeen, SSAqua_B1F_Text_BlackbeltWaiBeaten
	msgbox SSAqua_B1F_Text_BlackbeltWaiAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_BlackbeltWaiSeen:
	.string "¡Fortalezco mis piernas nadando en la\n"
	.string "estela del barco!\p"
	.string "$"

SSAqua_B1F_Text_BlackbeltWaiBeaten:
	.string "¡Bailemos el Rock and Roll!$"

SSAqua_B1F_Text_BlackbeltWaiAfter:
	.string "No pude encontrar al REY del KARATE\n"
	.string "en JOHTO.\p"
	.string "Dicen que se está entrenando en\n"
	.string "alguna cueva.$"

SSAqua_B1F_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH_HNS, SSAqua_B1F_Text_SailorKennethSeen, SSAqua_B1F_Text_SailorKennethBeaten
	msgbox SSAqua_B1F_Text_SailorKennethAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorKennethSeen:
	.string "¡Soy marinero!\p"
	.string "¡Pero estoy entrenando POKéMON para\n"
	.string "ser CAMPEÓN!$"

SSAqua_B1F_Text_SailorKennethBeaten:
	.string "Me falta entrenamiento…$"

SSAqua_B1F_Text_SailorKennethAfter:
	.string "¡Ocho MEDALLAS! Demuestran que has\n"
	.string "vencido\p"
	.string "a los LÍDERES de GIMNASIO.\p"
	.string "¡Con razón eres tan bueno!$"

SSAqua_B1F_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY_HNS, SSAqua_B1F_Text_TeacherShirleySeen, SSAqua_B1F_Text_TeacherShirleyBeaten
	msgbox SSAqua_B1F_Text_TeacherShirleyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_TeacherShirleySeen:
	.string "¡No toques a mis alumnos!$"

SSAqua_B1F_Text_TeacherShirleyBeaten:
	.string "¡Aaah!$"

SSAqua_B1F_Text_TeacherShirleyAfter:
	.string "Vamos de excursión a las RUINAS de las\n"
	.string "afueras de CIUDAD MALVA.$"

SSAqua_B1F_EventScript_Nate::
	trainerbattle_single TRAINER_NATE_HNS, SSAqua_B1F_Text_SchoolboyNateSeen, SSAqua_B1F_Text_SchoolboyNateBeaten
	msgbox SSAqua_B1F_Text_SchoolboyNateAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyNateSeen:
	.string "¿Conoces las RUINAS ALFA?$"

SSAqua_B1F_Text_SchoolboyNateBeaten:
	.string "¡Aarg!$"

SSAqua_B1F_Text_SchoolboyNateAfter:
	.string "Las radios captan señales extrañas\n"
	.string "en las RUINAS.$"

SSAqua_B1F_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY_HNS, SSAqua_B1F_Text_SchoolboyRickySeen, SSAqua_B1F_Text_SchoolboyRickyBeaten
	msgbox SSAqua_B1F_Text_SchoolboyRickyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyRickySeen:
	.string "En las RUINAS ALFA hay unos extraños\n"
	.string "grabados de piedra.\p"
	.string "$"

SSAqua_B1F_Text_SchoolboyRickyBeaten:
	.string "¡Estoy agotado!$"

SSAqua_B1F_Text_SchoolboyRickyAfter:
	.string "He leído que hay cuatro paneles de\n"
	.string "piedra como ésos.$"

