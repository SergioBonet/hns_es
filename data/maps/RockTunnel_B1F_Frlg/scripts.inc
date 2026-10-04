RockTunnel_B1F_Frlg_MapScripts::
	.byte 0

RockTunnel_B1F_EventScript_Sofia::
	trainerbattle_single TRAINER_PICNICKER_SOFIA, RockTunnel_B1F_Text_SofiaIntro, RockTunnel_B1F_Text_SofiaDefeat
	msgbox RockTunnel_B1F_Text_SofiaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Martha::
	trainerbattle_single TRAINER_PICNICKER_MARTHA, RockTunnel_B1F_Text_MarthaIntro, RockTunnel_B1F_Text_MarthaDefeat
	msgbox RockTunnel_B1F_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Dudley::
	trainerbattle_single TRAINER_HIKER_DUDLEY, RockTunnel_B1F_Text_DudleyIntro, RockTunnel_B1F_Text_DudleyDefeat
	msgbox RockTunnel_B1F_Text_DudleyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Allen::
	trainerbattle_single TRAINER_HIKER_ALLEN, RockTunnel_B1F_Text_AllenIntro, RockTunnel_B1F_Text_AllenDefeat
	msgbox RockTunnel_B1F_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Eric::
	trainerbattle_single TRAINER_HIKER_ERIC, RockTunnel_B1F_Text_EricIntro, RockTunnel_B1F_Text_EricDefeat
	msgbox RockTunnel_B1F_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Cooper::
	trainerbattle_single TRAINER_POKEMANIAC_COOPER, RockTunnel_B1F_Text_CooperIntro, RockTunnel_B1F_Text_CooperDefeat
	msgbox RockTunnel_B1F_Text_CooperPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Steve::
	trainerbattle_single TRAINER_POKEMANIAC_STEVE, RockTunnel_B1F_Text_SteveIntro, RockTunnel_B1F_Text_SteveDefeat
	msgbox RockTunnel_B1F_Text_StevePostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Winston::
	trainerbattle_single TRAINER_POKEMANIAC_WINSTON, RockTunnel_B1F_Text_WinstonIntro, RockTunnel_B1F_Text_WinstonDefeat
	msgbox RockTunnel_B1F_Text_WinstonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_SofiaIntro::
	.string "¿Sabes cómo evitar perderte en\n"
	.string "las montañas?\p"
	.string "Puedes doblar ramitas como\n"
	.string "señales del camino.$"

RockTunnel_B1F_Text_SofiaDefeat::
	.string "¡Ohhh!\n"
	.string "¡He hecho todo lo posible!$"

RockTunnel_B1F_Text_SofiaPostBattle::
	.string "¡Quiero volver a mi casa!$"

RockTunnel_B1F_Text_DudleyIntro::
	.string "¡Ja, ja, ja!\n"
	.string "¿Crees que puedes ganarme?$"

RockTunnel_B1F_Text_DudleyDefeat::
	.string "¡Vaya!\n"
	.string "¡Superado en fuerza!$"

RockTunnel_B1F_Text_DudleyPostBattle::
	.string "¡Prefiero la fuerza, porque no\n"
	.string "me gusta pensar!$"

RockTunnel_B1F_Text_CooperIntro::
	.string "¿Tienes una POKéDEX?\n"
	.string "¡Yo también quiero una!$"

RockTunnel_B1F_Text_CooperDefeat::
	.string "¡Brgg!\n"
	.string "¡Me das tanta envidia!$"

RockTunnel_B1F_Text_CooperPostBattle::
	.string "Cuando termines con tu POKéDEX\n"
	.string "¿me la dejarás?$"

RockTunnel_B1F_Text_SteveIntro::
	.string "Eh… ¿Sabes qué es el cosplay\n"
	.string "de POKéMON?$"

RockTunnel_B1F_Text_SteveDefeat::
	.string "Pues eso es todo.$"

RockTunnel_B1F_Text_StevePostBattle::
	.string "No hay nada como disfrazarse\n"
	.string "de POKéMON para divertirse.\p"
	.string "El mejor es CLEFAIRY.$"

RockTunnel_B1F_Text_AllenIntro::
	.string "¡Mis técnicas de POKéMON te harán\n"
	.string "llorar!$"

RockTunnel_B1F_Text_AllenDefeat::
	.string "¡Me rindo!\n"
	.string "¡Tus técnicas son mejores!$"

RockTunnel_B1F_Text_AllenPostBattle::
	.string "En las montañas suele haber\n"
	.string "POKéMON del tipo ROCA.$"

RockTunnel_B1F_Text_MarthaIntro::
	.string "¡No suelo venir por aquí, pero\n"
	.string "lucharé contigo!$"

RockTunnel_B1F_Text_MarthaDefeat::
	.string "¡Oh! ¡He perdido!$"

RockTunnel_B1F_Text_MarthaPostBattle::
	.string "Me gustan los POKéMON pequeños.\n"
	.string "¡Los grandes dan mucho miedo!$"

RockTunnel_B1F_Text_EricIntro::
	.string "¡Lánzame tu mejor ataque!$"

RockTunnel_B1F_Text_EricDefeat::
	.string "¡Disparado!$"

RockTunnel_B1F_Text_EricPostBattle::
	.string "¡Criaré a mis POKéMON para que\n"
	.string "venzan a los tuyos!$"

RockTunnel_B1F_Text_WinstonIntro::
	.string "Cuando estoy en casa, dibujo a los\n"
	.string "POKéMON.$"

RockTunnel_B1F_Text_WinstonDefeat::
	.string "¡Uf!\n"
	.string "¡Estoy agotado!$"

RockTunnel_B1F_Text_WinstonPostBattle::
	.string "Soy artista, no luchador.\n"
	.string "Me voy a casa a dibujar.$"

