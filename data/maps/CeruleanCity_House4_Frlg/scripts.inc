.set REWARD_TYPE, VAR_0x8004
.set REWARD_ITEM, VAR_0x8008

CeruleanCity_House4_Frlg_MapScripts::
	.byte 0

CeruleanCity_House4_EventScript_WonderNewsBerryMan::
	lock
	specialvar REWARD_TYPE, WonderNews_GetRewardInfo
	copyvar REWARD_ITEM, VAR_RESULT
	goto_if_eq REWARD_TYPE, NEWS_REWARD_NONE,       CeruleanCity_House4_EventScript_NoNews
	goto_if_eq REWARD_TYPE, NEWS_REWARD_RECV_SMALL, CeruleanCity_House4_EventScript_Reward_RecvSmall
	goto_if_eq REWARD_TYPE, NEWS_REWARD_RECV_BIG,   CeruleanCity_House4_EventScript_Reward_RecvBig
	goto_if_eq REWARD_TYPE, NEWS_REWARD_WAITING,    CeruleanCity_House4_EventScript_Waiting
	goto_if_eq REWARD_TYPE, NEWS_REWARD_SENT_SMALL, CeruleanCity_House4_EventScript_Reward_SentSmall
	goto_if_eq REWARD_TYPE, NEWS_REWARD_SENT_BIG,   CeruleanCity_House4_EventScript_Reward_SentBig
	goto_if_eq REWARD_TYPE, NEWS_REWARD_AT_MAX,     CeruleanCity_House4_EventScript_AtMax
	end

@ Mystery Gift is not enabled, or the player has no saved Wonder News
CeruleanCity_House4_EventScript_NoNews::
	msgbox CeruleanCity_House4_Text_NothingEntertaining
	release
	end

@ Small reward for receiving Wonder News from friend
CeruleanCity_House4_EventScript_Reward_RecvSmall::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_NewNewsInformativeHaveThis
	giveitem REWARD_ITEM
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Big reward for receiving Wonder News from non-friend source
CeruleanCity_House4_EventScript_Reward_RecvBig::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_IncredibleNewsHaveBerries
	giveitem REWARD_ITEM, 4
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Player has not recently sent Wonder News
CeruleanCity_House4_EventScript_Waiting::
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CeruleanCity_House4_Text_WishCouldShareNewsWithOthers
	release
	end

@ Small reward for sending Wonder News every 1-3 times
CeruleanCity_House4_EventScript_Reward_SentSmall::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_ThanksForSpreadingNewsTakeThis
	giveitem REWARD_ITEM
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Big reward for sending Wonder News every 4th time
CeruleanCity_House4_EventScript_Reward_SentBig::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_MagnificentNewsSpreadHaveBerries
	giveitem REWARD_ITEM, 4
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Player has hit reward limit and must wait to receive new rewards
CeruleanCity_House4_EventScript_AtMax::
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CeruleanCity_House4_Text_EnjoyingMyselfWithAllSortsOfNews
	release
	end

CeruleanCity_House4_EventScript_MovementReactionToNews::
	playse SE_PIN
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_Delay48
	waitmovement 0
	return

CeruleanCity_House4_EventScript_NoRoomForBerries::
	msgbox CeruleanCity_House4_Text_YourBerryPouchIsFull
	release
	end

CeruleanCity_House4_Text_NothingEntertaining::
	.string "Uff... Tengo tanto tiempo\n"
	.string "y tan poco que hacer...\p"
	.string "¿No hay nada divertido cociéndose\n"
	.string "por ahí?$"

CeruleanCity_House4_Text_NewNewsInformativeHaveThis::
	.string "¡Anda, hay novedades!\n"
	.string "¡Un boletín informativo!\p"
	.string "A ver, a ver...\p"
	.string "¡Interesante!\n"
	.string "¡Interesantísimo!\p"
	.string "Muy bien, me encanta que la gente\n"
	.string "joven como tú se interese por las\l"
	.string "noticias.\p"
	.string "Quiero agradecerte el haberme\n"
	.string "traído estas noticias, toma.$"

CeruleanCity_House4_Text_IncredibleNewsHaveBerries::
	.string "¡Por fin!\n"
	.string "¡Un boletín informativo!\p"
	.string "A ver, a ver...\p"
	.string "¡Maravilloso!\n"
	.string "¡Maravillosísimo!\p"
	.string "Hacía tiempo que no leía nada\n"
	.string "igual.\p"
	.string "Gracias por traerme semejantes\n"
	.string "noticias, toma, unas BAYITAS.$"

CeruleanCity_House4_Text_WishCouldShareNewsWithOthers::
	.string "Sería una pena no compartir estas\n"
	.string "noticias...\p"
	.string "Me encantaría poder pasárselas\n"
	.string "a alguien...\l"
	.string "Compártelas con más gente...$"

CeruleanCity_House4_Text_ThanksForSpreadingNewsTakeThis::
	.string "¿Has pasado las noticias\n"
	.string "a más gente?\p"
	.string "¡Las buenas noticias hay que\n"
	.string "compartirlas con quien se pueda!\p"
	.string "Gracias por pasárselas a otras\n"
	.string "personas, toma, anda.$"

CeruleanCity_House4_Text_MagnificentNewsSpreadHaveBerries::
	.string "¿Has pasado las noticias\n"
	.string "a más gente todavía?\p"
	.string "¡Las propias noticias deben\n"
	.string "de estar encantadas de la vida!\p"
	.string "¡Lo que yo te diga!\p"
	.string "¡En mi nombre y en nombre\n"
	.string "de las propias noticias, toma!\p"
	.string "¡Voy a darte más BAYITAS\n"
	.string "que de costumbre!$"

CeruleanCity_House4_Text_EnjoyingMyselfWithAllSortsOfNews::
	.string "Yo me lo paso pipa leyendo\n"
	.string "noticias. Todas me gustan, todas.\p"
	.string "¡Ya estoy contento! ¡Voy a estar\n"
	.string "entretenido para rato!$"

CeruleanCity_House4_Text_YourBerryPouchIsFull::
	.string "Vaya, tienes el SACO de las BAYAS\n"
	.string "hasta arriba. Vuelve a por ellas\l"
	.string "cuando tengas sitio.$"

