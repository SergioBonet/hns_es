SixIsland_PatternBush_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_PatternBush_OnTransition
	.byte 0

SixIsland_PatternBush_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_PATTERN_BUSH
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_ge VAR_TEMP_1, 50, SixIsland_PatternBush_EventScript_SetEscapeRightExit
	call_if_le VAR_TEMP_1, 49, SixIsland_PatternBush_EventScript_SetEscapeLeftExit
	end

SixIsland_PatternBush_EventScript_SetEscapeRightExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 64, 10
	return

SixIsland_PatternBush_EventScript_SetEscapeLeftExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 45, 10
	return

SixIsland_PatternBush_EventScript_Bethany::
	trainerbattle_single TRAINER_PKMN_BREEDER_BETHANY, SixIsland_PatternBush_Text_BethanyIntro, SixIsland_PatternBush_Text_BethanyDefeat
	msgbox SixIsland_PatternBush_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Allison::
	trainerbattle_single TRAINER_PKMN_BREEDER_ALLISON, SixIsland_PatternBush_Text_AllisonIntro, SixIsland_PatternBush_Text_AllisonDefeat
	msgbox SixIsland_PatternBush_Text_AllisonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Garret::
	trainerbattle_single TRAINER_BUG_CATCHER_GARRET, SixIsland_PatternBush_Text_GarretIntro, SixIsland_PatternBush_Text_GarretDefeat
	msgbox SixIsland_PatternBush_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Jonah::
	trainerbattle_single TRAINER_BUG_CATCHER_JONAH, SixIsland_PatternBush_Text_JonahIntro, SixIsland_PatternBush_Text_JonahDefeat
	msgbox SixIsland_PatternBush_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Vance::
	trainerbattle_single TRAINER_BUG_CATCHER_VANCE, SixIsland_PatternBush_Text_VanceIntro, SixIsland_PatternBush_Text_VanceDefeat
	msgbox SixIsland_PatternBush_Text_VancePostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Nash::
	trainerbattle_single TRAINER_YOUNGSTER_NASH, SixIsland_PatternBush_Text_NashIntro, SixIsland_PatternBush_Text_NashDefeat
	msgbox SixIsland_PatternBush_Text_NashPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Cordell::
	trainerbattle_single TRAINER_YOUNGSTER_CORDELL, SixIsland_PatternBush_Text_CordellIntro, SixIsland_PatternBush_Text_CordellDefeat
	msgbox SixIsland_PatternBush_Text_CordellPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Dalia::
	trainerbattle_single TRAINER_LASS_DALIA, SixIsland_PatternBush_Text_DaliaIntro, SixIsland_PatternBush_Text_DaliaDefeat
	msgbox SixIsland_PatternBush_Text_DaliaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Joana::
	trainerbattle_single TRAINER_LASS_JOANA, SixIsland_PatternBush_Text_JoanaIntro, SixIsland_PatternBush_Text_JoanaDefeat
	msgbox SixIsland_PatternBush_Text_JoanaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Riley::
	trainerbattle_single TRAINER_CAMPER_RILEY, SixIsland_PatternBush_Text_RileyIntro, SixIsland_PatternBush_Text_RileyDefeat
	msgbox SixIsland_PatternBush_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Marcy::
	trainerbattle_single TRAINER_PICNICKER_MARCY, SixIsland_PatternBush_Text_MarcyIntro, SixIsland_PatternBush_Text_MarcyDefeat
	msgbox SixIsland_PatternBush_Text_MarcyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Layton::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAYTON, SixIsland_PatternBush_Text_LaytonIntro, SixIsland_PatternBush_Text_LaytonDefeat
	msgbox SixIsland_PatternBush_Text_LaytonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_Text_BethanyIntro::
	.string "Oye, que me pica la curiosidad,\n"
	.string "¿cómo crías a tus POKéMON?$"

SixIsland_PatternBush_Text_BethanyDefeat::
	.string "¡Veo que con mucho cariño!$"

SixIsland_PatternBush_Text_BethanyPostBattle::
	.string "Hay que criarlos con el mismo\n"
	.string "cariño con el que una madre cría\l"
	.string "a sus pequeños.$"

SixIsland_PatternBush_Text_AllisonIntro::
	.string "Yo me encargo de preservar el\n"
	.string "entorno natural de los POKéMON.$"

SixIsland_PatternBush_Text_AllisonDefeat::
	.string "¡Oh, para ser tan joven,\n"
	.string "eres formidable!$"

SixIsland_PatternBush_Text_AllisonPostBattle::
	.string "¡Yo no he dicho que no debas\n"
	.string "atrapar POKéMON!\p"
	.string "Sólo quiero que la gente los críe\n"
	.string "de forma responsable.$"

SixIsland_PatternBush_Text_GarretIntro::
	.string "He atrapado un POKéMON del tipo\n"
	.string "BICHO que sólo vive por aquí.$"

SixIsland_PatternBush_Text_GarretDefeat::
	.string "Je, je, je...\n"
	.string "¿No es impresionante mi POKéMON?$"

SixIsland_PatternBush_Text_GarretPostBattle::
	.string "Hay una chica cerca del arbusto,\n"
	.string "que mide las fuerzas de HERACROSS.$"

SixIsland_PatternBush_Text_JonahIntro::
	.string "¿Sabes? Si no uso POKéMON del tipo\n"
	.string "BICHO, no disfruto los combates.$"

SixIsland_PatternBush_Text_JonahDefeat::
	.string "No pasa nada, perder tiene también\n"
	.string "su encanto.$"

SixIsland_PatternBush_Text_JonahPostBattle::
	.string "Por cierto, “atractivo” es una\n"
	.string "palabra rara, si lo piensas.\p"
	.string "¿Es como una cáscara de naranja?\n"
	.string "¿O como una campana que suena?$"

SixIsland_PatternBush_Text_VanceIntro::
	.string "¡Mira qué POKéMON del tipo BICHO\n"
	.string "tengo! ¡Sí, señor!$"

SixIsland_PatternBush_Text_VanceDefeat::
	.string "¡Me han ganado en plena euforia!$"

SixIsland_PatternBush_Text_VancePostBattle::
	.string "La próxima vez, me vengo con mi\n"
	.string "hermano pequeño.$"

SixIsland_PatternBush_Text_NashIntro::
	.string "¡Mira al suelo!\n"
	.string "Qué dibujos más raros... ¿verdad?$"

SixIsland_PatternBush_Text_NashDefeat::
	.string "¡Flipo en colores!$"

SixIsland_PatternBush_Text_NashPostBattle::
	.string "Los dibujos tan raros del suelo...\p"
	.string "¡Se parecen al estampado de\n"
	.string "la ropa de mi abuelo!$"

SixIsland_PatternBush_Text_CordellIntro::
	.string "Seguro que piensas que soy un tipo\n"
	.string "cualquiera, ¿eh?$"

SixIsland_PatternBush_Text_CordellDefeat::
	.string "Crees que soy débil, ¿no?$"

SixIsland_PatternBush_Text_CordellPostBattle::
	.string "Anda, los de ciudad venís tan\n"
	.string "presumidos con un sombrero tan\l"
	.string "llamativo…\p"
	.string "¿Qué tal si me lo das?$"

SixIsland_PatternBush_Text_DaliaIntro::
	.string "¡Mmmm, respira hondo!\n"
	.string "Qué aire tan puro...$"

SixIsland_PatternBush_Text_DaliaDefeat::
	.string "Si quieres, puedo enseñarte a\n"
	.string "respirar como es debido.$"

SixIsland_PatternBush_Text_DaliaPostBattle::
	.string "Espira...\n"
	.string "Hasta que no te quede aire...\p"
	.string "Cuando no puedas espirar más,\n"
	.string "¡inspira!\p"
	.string "¿No es una sensación de frescor\n"
	.string "fantástica?$"

SixIsland_PatternBush_Text_JoanaIntro::
	.string "Me encantan los POKéMON del tipo\n"
	.string "BICHO. Por eso estoy siempre aquí.\p"
	.string "Supongo que no seré la única...$"

SixIsland_PatternBush_Text_JoanaDefeat::
	.string "No pienso perder la sonrisa.\n"
	.string "Supongo que no soy la única...$"

SixIsland_PatternBush_Text_JoanaPostBattle::
	.string "Voy a seguir coleccionando\n"
	.string "POKéMON del tipo BICHO.\p"
	.string "Supongo que no soy la única...$"

SixIsland_PatternBush_Text_RileyIntro::
	.string "Este sitio es estupendo.\n"
	.string "Voy a colocar la tienda aquí.$"

SixIsland_PatternBush_Text_RileyDefeat::
	.string "Qué paliza...$"

SixIsland_PatternBush_Text_RileyPostBattle::
	.string "Me quedaré aquí para observar\n"
	.string "las estrellas.$"

SixIsland_PatternBush_Text_MarcyIntro::
	.string "¡Puaj!\n"
	.string "¡Creo que me ha picado un bicho!$"

SixIsland_PatternBush_Text_MarcyDefeat::
	.string "No ha sido ningún bicho, me he\n"
	.string "cortado con el césped.$"

SixIsland_PatternBush_Text_MarcyPostBattle::
	.string "Un corte tan pequeño…\n"
	.string "¡Un poco de saliva basta para curarlo!$"

SixIsland_PatternBush_Text_LaytonIntro::
	.string "¿Has visto algo raro por aquí?$"

SixIsland_PatternBush_Text_LaytonDefeat::
	.string "¿Has mirado bien\n"
	.string "alrededor de tus pies?$"

SixIsland_PatternBush_Text_LaytonPostBattle::
	.string "Hay sitios en el BOSQUEJO,\n"
	.string "en los que no crece la hierba.\p"
	.string "¿Por qué será?$"

