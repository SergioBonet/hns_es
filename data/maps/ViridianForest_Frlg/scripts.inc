ViridianForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_FriendsItchingToBattle::
	.string "¡Vine aquí con unos amigos a\n"
	.string "capturar POKéMON BICHO!\p"
	.string "¡Todos tienen ganas de meterse en\n"
	.string "combates POKéMON!$"

ViridianForest_Text_RickIntro::
	.string "¡Eh! ¡Tienes POKéMON!\n"
	.string "¡Venga!\l"
	.string "¡Vamos a combatir!$"

ViridianForest_Text_RickDefeat::
	.string "¡No!\n"
	.string "¡CATERPIE no ha podido con ellos!$"

ViridianForest_Text_RickPostBattle::
	.string "¡Ssh! Vas a espantar a los bichos.\n"
	.string "Otro día, ¿vale?$"

ViridianForest_Text_DougIntro::
	.string "¡Eh!\n"
	.string "¡Si eres ENTRENADOR POKéMON no\l"
	.string "puedes montar un buen concierto!$"

ViridianForest_Text_DougDefeat::
	.string "¿Eh?\n"
	.string "¡Me he quedado sin POKéMON!$"

ViridianForest_Text_DougPostBattle::
	.string "¡Qué rabia! ¡Voy a atrapar\n"
	.string "algunos más fuertes!$"

ViridianForest_Text_SammyIntro::
	.string "¡Eh, espera!\n"
	.string "¿Por qué tienes tanta prisa?$"

ViridianForest_Text_SammyDefeat::
	.string "¡Me rindo!\n"
	.string "¡Eres muy bueno!$"

ViridianForest_Text_SammyPostBattle::
	.string "A veces puedes encontrar cosas en\n"
	.string "el suelo.\p"
	.string "Estoy buscando lo que se me cayó.\n"
	.string "¿Me ayudas?$"

ViridianForest_Text_AnthonyIntro::
	.string "Puede que sea pequeño, ¡pero no me\n"
	.string "gustará que me trates con suavidad!$"

ViridianForest_Text_AnthonyDefeat::
	.string "Vaya, qué fastidio.\n"
	.string "Nada ha salido bien.$"

ViridianForest_Text_AnthonyPostBattle::
	.string "He perdido parte de mi paga…$"

ViridianForest_Text_CharlieIntro::
	.string "¿Sabías que los POKéMON evolucionan?$"

ViridianForest_Text_CharlieDefeat::
	.string "¡Oh!\n"
	.string "¡He perdido!$"

ViridianForest_Text_CharliePostBattle::
	.string "Los POKéMON BICHO evolucionan\n"
	.string "rápido. ¡Son muy divertidos!$"

ViridianForest_Text_RanOutOfPokeBalls::
	.string "Estaba lanzando POKé BALLS para\n"
	.string "capturar POKéMON y me quedé sin ellas.\p"
	.string "Por eso nunca se tienen demasiadas\n"
	.string "POKé BALLS.$"

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
	.string "PISTAS ENTRENADOR\p"
	.string "Si tus POKéMON están débiles y quieres\n"
	.string "evitar combates, ¡aléjate de las\l"
	.string "zonas de hierba!$"

ViridianForest_Text_UseAntidoteForPoison::
	.string "¡Usa ANTÍDOTO contra el veneno!\n"
	.string "¡Consíguelo en las TIENDAS POKéMON!$"

ViridianForest_Text_ContactOakViaPCToRatePokedex::
	.string "PISTAS ENTRENADOR\p"
	.string "¡Contacta con el PROF. OAK desde\n"
	.string "un PC para evaluar tu POKéDEX!$"

ViridianForest_Text_CantCatchOwnedMons::
	.string "PISTAS ENTRENADOR\p"
	.string "No puedes capturar un POKéMON que\n"
	.string "pertenece a otro ENTRENADOR.\p"
	.string "¡Lanza POKé BALLS solo a POKéMON\n"
	.string "salvajes para capturarlos!$"

ViridianForest_Text_WeakenMonsBeforeCapture::
	.string "PISTAS ENTRENADOR\p"
	.string "¡Debilita a los POKéMON antes de\n"
	.string "intentar capturarlos!\p"
	.string "¡Si están sanos, pueden escapar!$"

ViridianForest_Text_LeavingViridianForest::
	.string "SALIENDO DEL BOSQUE VERDE\n"
	.string "CIUDAD PLATEADA, SIGUIENDO ADELANTE$"

