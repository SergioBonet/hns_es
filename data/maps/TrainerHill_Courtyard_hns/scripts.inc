TrainerHill_Courtyard_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Courtyard_OnTransition
	.byte 0

TrainerHill_Courtyard_OnTransition::
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	end

TrainerHill_Courtyard_EventScript_BattleTowerSign::
	lock
	msgbox BattleTowerOutsideSignText, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Factory::
	lock
	msgbox BattleTower_Battle_Tent_Text_Factory, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Palace::
	lock
	msgbox BattleTower_Battle_Tent_Text_Palace, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Arena::
	lock
	msgbox BattleTower_Battle_Tent_Text_Arena, MSGBOX_SIGN	
	closemessage	
	release
	end
	
TrainerHill_Courtyard_EventScript_Engineer::
	lock
	faceplayer
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Youngster::
	lock
	faceplayer
	msgbox BattleTowerOutsideYoungsterText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Beauty::
	lock
	faceplayer
	msgbox BattleTowerOutsideBeautyText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleTowerOutsideSailorText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTowerOutsideYoungsterText:
	.string "¡Uau, la COLINA DESAFÍO es enorme!\p"
	.string "¡Ahí dentro debe de haber muchas\n"
	.string "clases de POKéMON!$"

BattleTowerOutsideBeautyText:
	.string "En las TIENDAS BATALLA solo puedes\n"
	.string "usar tres POKéMON.\p"
	.string "Es dificilísimo decidir qué tres van a\n"
	.string "luchar…$"

BattleTowerOutsideSailorText:
	.string "Je, je… Me escapé del trabajo.\p"
	.string "¡No puedo achicar agua hasta que haya\n"
	.string "ganado!\p"
	.string "Tengo que ganarlo todo. ¡Debo ganarlo!$"

BattleTowerOutsideSignText:
	.string "{UP_ARROW} ENTRADA DE LA COLINA\n"
	.string "DESAFÍO\p"
	.string "“¡Conquistad las alturas,\n"
	.string "ENTRENADORES apasionados!”\p"
	.string "{RIGHT_ARROW} TIENDAS BATALLA.$"

BattleTower_Battle_Tent_Text_Factory:
	.string "TIENDA BATALLA: FÁBRICA\n"
	.string "“¡Encuentra el POKéMON definitivo!”$"

BattleTower_Battle_Tent_Text_Palace:
	.string "TIENDA BATALLA: PALACIO\n"
	.string "“¡Disfruta de los combates!”$"

BattleTower_Battle_Tent_Text_Arena:
	.string "TIENDA BATALLA: CÚPULA\n"
	.string "“¡Que se reúnan los mejores equipos!”$"

BattleTowerOutsideText_Closed:
	.string "La COLINA DESAFÍO está cerrada por\n"
	.string "reparaciones.$"


TrainerHill_Courtyard_EventScript_LeftMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_LeftMoveTutor_hns
	end

TrainerHill_Courtyard_EventScript_RightMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_RightMoveTutor_hns
	end

TrainerHill_Courtyard_EventScript_ElementalMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_ElementalMoveTutor
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPDecorShop1
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPDecorShop2
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPVitaminShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPHoldItemShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk2::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPHoldItemShop2
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PowerClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPPowerShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Man::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Sailor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Girl::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text:
	.string "¡Hola! Si buscas el INTERCAMBIO\n"
	.string "PRODIGIOSO, ahora está en todos los\l"
	.string "CENTROS POKéMON. ¡Diviértete!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hola, éste es el CENTRO del SERVICIO\n"
	.string "de CANJE.\p"
	.string "Aquí podemos cambiar tus PUNTOS\n"
	.string "de BATALLA por fabulosos premios.\p"
	.string "Elige el premio que desees de la lista.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "¡Ay, qué bonitos!\n"
	.string "¡Me gustaría tenerlos todos!\l"
	.string "¡Me gustaría apachurrarlos todos!\l"
	.string "¡MUÑECOS grandes!\l"
	.string "¡MUÑECOS pequeñitos!\l"
	.string "¡Los quiero todos para mí!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "¡No te preocupes, ya se encarga mamá!\p"
	.string "¡Si es eso lo que quieres, haré lo que\n"
	.string "sea para conseguirlo, cariño!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "Si consigo esos objetos que hay ahí,\n"
	.string "mis POKéMON se harán más fuertes.\p"
	.string "¡Apostaría lo que fuera!\n"
	.string "¡No me cabe duda!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "¡Eh, tú!\n"
	.string "¿A qué viene esa cara?\p"
	.string "Al peluche que llevo encima\n"
	.string "no le gusta nada que lo miren así.\p"
	.string "¡Si quieres uno, cómpratelo!\n"
	.string "A que sí, ¿SMOOCHUM?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "¿Sabes una cosa?\p"
	.string "Si superas tu récord en cualquiera de\n"
	.string "los escenarios del FRENTE de BATALLA,\l"
	.string "te darán más y más PUNTOS de BATALLA.$"
