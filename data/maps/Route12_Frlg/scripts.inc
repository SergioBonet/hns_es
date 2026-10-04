Route12_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route12_EventScript_TryRemoveSnorlax
	end

Route12_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route12_EventScript_FoughtSnorlax
	release
	end

Route12_EventScript_DontUsePokeFlute::
	release
	end

Route12_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute::
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end

Route12_Text_MonSprawledOutInSlumber::
	.string "Un POKéMON está tumbado en un\n"
	.string "sueño profundo y cómodo.$"

Text_SnorlaxWokeUp::
	.string "¡SNORLAX se ha despertado!\p"
	.string "¡Se ha enfadado mucho\n"
	.string "y te quiere atacar!$"

Text_SnorlaxReturnedToMountains::
	.string "SNORLAX se ha calmado.\n"
	.string "¡Y tras bostezar se ha marchado\l"
	.string "a las montañas!$"

Text_WantToUsePokeFlute::
	.string "¿Quieres usar la POKé FLAUTA?$"

Text_PlayedPokeFlute::
	.string "{PLAYER} tocó la POKé FLAUTA.$"

Route12_Text_NedIntro::
	.string "¡Sí!\n"
	.string "¡Ha picado algo!$"

Route12_Text_NedDefeat::
	.string "¡Bah!\n"
	.string "Solo un pececillo…$"

Route12_Text_NedPostBattle::
	.string "¡Alto!\n"
	.string "¡Mi sedal está enganchado!$"

Route12_Text_ChipIntro::
	.string "¡Ten paciencia!\n"
	.string "¡Pescar requiere tiempo!$"

Route12_Text_ChipDefeat::
	.string "¡Ése se escapó!$"

Route12_Text_ChipPostBattle::
	.string "¡Con una CAÑA mejor podría pescar\n"
	.string "mejores POKéMON!$"

Route12_Text_JustinIntro::
	.string "¿Has encontrado una PIEDRA LUNAR?$"

Route12_Text_JustinDefeat::
	.string "¡Auuuu!$"

Route12_Text_JustinPostBattle::
	.string "¡Podría haber transformado a mis\n"
	.string "POKéMON con una PIEDRA LUNAR!\p"
	.string "¡Y podría haber ganado!$"

Route12_Text_LucaIntro::
	.string "¡Soy un experto en electricidad!\p"
	.string "Pero no sé nada sobre los POKéMON\n"
	.string "de mar.$"

Route12_Text_LucaDefeat::
	.string "¡Se acabó!$"

Route12_Text_LucaPostBattle::
	.string "El agua conduce la electricidad.\n"
	.string "¡Deberías poder atrapar a los\l"
	.string "POKéMON de mar!$"

Route12_Text_HankIntro::
	.string "¡El PESCADOR LOCO contra alguien\n"
	.string "que no tiene idea sobre POKéMON!$"

Route12_Text_HankDefeat::
	.string "¡Has tocado demasiado!$"

Route12_Text_HankPostBattle::
	.string "¡Me has ganado con los POKéMON,\n"
	.string "pero yo soy muy bueno pescando!\p"
	.string "Supongo que hay que hacer lo que\n"
	.string "mejor se le da a cada uno...$"

Route12_Text_ElliotIntro::
	.string "A mí me encanta pescar, ¡pero\n"
	.string "es que no pican ni a la de tres!$"

Route12_Text_ElliotDefeat::
	.string "No es fácil...$"

Route12_Text_ElliotPostBattle::
	.string "Está bien.\n"
	.string "Perder ya no me importa.$"

Route12_Text_AndrewIntro::
	.string "¡Nunca se sabe lo que puedes\n"
	.string "pescar!$"

Route12_Text_AndrewDefeat::
	.string "¡He perdido!$"

Route12_Text_AndrewPostBattle::
	.string "Es fácil pescar MAGIKARP,\n"
	.string "¡son tan débiles!$"

Route12_Text_RouteSign::
	.string "RUTA 12:\n"
	.string "LAVANDA, al norte$"

Route12_Text_SportfishingArea::
	.string "ZONA DE PESCA$"

Route12_Text_JesIntro::
	.string "ARE: Si gano, le pediré a AGA\n"
	.string "que se case conmigo.$"

Route12_Text_JesDefeat::
	.string "ARE: ¿Puedes dejarnos ganar,\n"
	.string "por favor?$"

Route12_Text_JesPostBattle::
	.string "ARE: AGA, ¡lo siento, cariño!$"

Route12_Text_JesNotEnoughMons::
	.string "ARE: AGA y yo vamos a estar juntos\n"
	.string "toda la vida.\p"
	.string "¡Y no lucharemos hasta que no\n"
	.string "tengas dos POKéMON!$"

Route12_Text_GiaIntro::
	.string "AGA: Oye, ARE...\p"
	.string "Si ganamos, ¡me caso contigo!$"

Route12_Text_GiaDefeat::
	.string "AGA: Oh... ¿Por qué?$"

Route12_Text_GiaPostBattle::
	.string "AGA: ¡ARE, eres medio lelo! ¡Todo\n"
	.string "se ha fastidiado por tu culpa!$"

Route12_Text_GiaNotEnoughMons::
	.string "AGA: ¡No pienso luchar sin mi ARE!\p"
	.string "¿No tienes dos POKéMON?$"
