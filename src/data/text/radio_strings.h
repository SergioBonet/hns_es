// Radio station strings ported from pokecrystal
// Lines fit ~32 char width for 28-tile window

#ifndef GUARD_DATA_TEXT_RADIO_STRINGS_H
#define GUARD_DATA_TEXT_RADIO_STRINGS_H

// ==========================================================
// Station Names (displayed at top of radio UI)
// ==========================================================

static const u8 sRadioStationName_OaksPkmnTalk[]    = _("HORA POKéMON DE OAK");
static const u8 sRadioStationName_PokedexShow[]     = _("PROGRAMA POKéDEX");
static const u8 sRadioStationName_PokemonMusic[]    = _("MÚSICA POKéMON");
static const u8 sRadioStationName_LuckyChannel[]    = _("CANAL SUERTE");
static const u8 sRadioStationName_BuenasPassword[]  = _("CONTRASEÑAS DE BUENA");
static const u8 sRadioStationName_Unown[]           = _("?????");
static const u8 sRadioStationName_PlacesAndPeople[] = _("LUGARES Y GENTE");
static const u8 sRadioStationName_LetsAllSing[]     = _("¡A CANTAR!");
static const u8 sRadioStationName_PokeFlute[]       = _("POKé FLAUTA");

static const u8 sRadioStationName_HoennSound[]  = _("SONIDOS DE HOENN");

// ==========================================================
// Hoenn Sound
// ==========================================================

static const u8 sRadioText_Hoenn1[] = _("¡Una melodía POKéMON de una");
static const u8 sRadioText_Hoenn2[] = _("región lejana llamada HOENN!");
static const u8 sRadioText_Hoenn3[] = _("¡Puede que aparezcan POKéMON");
static const u8 sRadioText_Hoenn4[] = _("salvajes de esa región!");

// ==========================================================
// POKéDEX Show
// ==========================================================

static const u8 sRadioText_PokedexShow_Intro[] = _("¡PROGRAMA POKéDEX DE OAK!");
static const u8 sRadioText_PokedexShow_TodaysPrefix[] = _("OAK: ¡Hoy toca ");

// ==========================================================
// Oak's POKéMON Talk
// ==========================================================

static const u8 sRadioText_OPT_Intro[] = _("ROSA: ¡LA HORA POKéMON DE OAK!");
static const u8 sRadioText_OPT_WithMeMary[] = _("¡Con vuestra amiga ROSA!");
static const u8 sRadioText_OPT_OakPrefix[] = _("OAK: ");
static const u8 sRadioText_OPT_SeenAround[] = _("puede verse en");
static const u8 sRadioText_OPT_MaryPrefix[] = _("ROSA: ");
static const u8 sRadioText_OPT_MaryIs[] = _(" es");

// Pokemon Channel interlude
static const u8 sRadioText_OPT_PokemonChannel[] = _("Canal POKéMON");

// Adverbs (randomly selected)
static const u8 sRadioText_OPT_Adverb_SweetAdorably[]      = _("dulce y adorablemente");
static const u8 sRadioText_OPT_Adverb_WigglySlickly[]      = _("escurridiza y ágilmente");
static const u8 sRadioText_OPT_Adverb_AptlyNamed[]         = _("de nombre acertado y");
static const u8 sRadioText_OPT_Adverb_UndeniablyKindOf[]   = _("innegablemente algo");
static const u8 sRadioText_OPT_Adverb_Unbearably[]         = _("tan, tan insoportablemente");
static const u8 sRadioText_OPT_Adverb_WowImpressively[]    = _("guau, impresionantemente");
static const u8 sRadioText_OPT_Adverb_AlmostPoisonously[]  = _("casi venenosamente");
static const u8 sRadioText_OPT_Adverb_Sensually[]          = _("uy, tan sensualmente");
static const u8 sRadioText_OPT_Adverb_Mischievously[]      = _("tan traviesamente");
static const u8 sRadioText_OPT_Adverb_Topically[]          = _("tan oportunamente");
static const u8 sRadioText_OPT_Adverb_Addictively[]        = _("tan adictivamente");
static const u8 sRadioText_OPT_Adverb_LooksInWater[]       = _("en el agua, de lo más");
static const u8 sRadioText_OPT_Adverb_EvolutionMustBe[]    = _("una vez evolucionado, muy");
static const u8 sRadioText_OPT_Adverb_Provocatively[]      = _("provocativamente");
static const u8 sRadioText_OPT_Adverb_FlippedOut[]         = _("tan alocado y");
static const u8 sRadioText_OPT_Adverb_HeartMeltingly[]     = _("enternecedoramente");

static const u8 *const sRadioText_OPT_Adverbs[] =
{
    sRadioText_OPT_Adverb_SweetAdorably,
    sRadioText_OPT_Adverb_WigglySlickly,
    sRadioText_OPT_Adverb_AptlyNamed,
    sRadioText_OPT_Adverb_UndeniablyKindOf,
    sRadioText_OPT_Adverb_Unbearably,
    sRadioText_OPT_Adverb_WowImpressively,
    sRadioText_OPT_Adverb_AlmostPoisonously,
    sRadioText_OPT_Adverb_Sensually,
    sRadioText_OPT_Adverb_Mischievously,
    sRadioText_OPT_Adverb_Topically,
    sRadioText_OPT_Adverb_Addictively,
    sRadioText_OPT_Adverb_LooksInWater,
    sRadioText_OPT_Adverb_EvolutionMustBe,
    sRadioText_OPT_Adverb_Provocatively,
    sRadioText_OPT_Adverb_FlippedOut,
    sRadioText_OPT_Adverb_HeartMeltingly,
};

// Adjectives (randomly selected)
static const u8 sRadioText_OPT_Adj_Cute[]           = _("mono.");
static const u8 sRadioText_OPT_Adj_Weird[]          = _("raro.");
static const u8 sRadioText_OPT_Adj_Pleasant[]       = _("agradable.");
static const u8 sRadioText_OPT_Adj_BoldSortOf[]     = _("audaz, más o menos.");
static const u8 sRadioText_OPT_Adj_Frightening[]    = _("aterrador.");
static const u8 sRadioText_OPT_Adj_SuaveDebonair[]  = _("fino y elegante.");
static const u8 sRadioText_OPT_Adj_Powerful[]        = _("poderoso.");
static const u8 sRadioText_OPT_Adj_Exciting[]        = _("emocionante.");
static const u8 sRadioText_OPT_Adj_Groovy[]          = _("molón.");
static const u8 sRadioText_OPT_Adj_Inspiring[]       = _("inspirador.");
static const u8 sRadioText_OPT_Adj_Friendly[]        = _("simpático.");
static const u8 sRadioText_OPT_Adj_HotHotHot[]       = _("ardiente, ardiente.");
static const u8 sRadioText_OPT_Adj_Stimulating[]     = _("estimulante.");
static const u8 sRadioText_OPT_Adj_Guarded[]         = _("precavido.");
static const u8 sRadioText_OPT_Adj_Lovely[]          = _("encantador.");
static const u8 sRadioText_OPT_Adj_Speedy[]          = _("veloz.");

static const u8 *const sRadioText_OPT_Adjectives[] =
{
    sRadioText_OPT_Adj_Cute,
    sRadioText_OPT_Adj_Weird,
    sRadioText_OPT_Adj_Pleasant,
    sRadioText_OPT_Adj_BoldSortOf,
    sRadioText_OPT_Adj_Frightening,
    sRadioText_OPT_Adj_SuaveDebonair,
    sRadioText_OPT_Adj_Powerful,
    sRadioText_OPT_Adj_Exciting,
    sRadioText_OPT_Adj_Groovy,
    sRadioText_OPT_Adj_Inspiring,
    sRadioText_OPT_Adj_Friendly,
    sRadioText_OPT_Adj_HotHotHot,
    sRadioText_OPT_Adj_Stimulating,
    sRadioText_OPT_Adj_Guarded,
    sRadioText_OPT_Adj_Lovely,
    sRadioText_OPT_Adj_Speedy,
};

// ==========================================================
// POKéMON Music Channel (Ben & Fern)
// ==========================================================

static const u8 sRadioText_BenIntro[] = _("NARDO: ¡CANAL DE MÚSICA POKéMON!");
static const u8 sRadioText_BenIntro2[] = _("¡Soy yo, DJ NARDO!");
static const u8 sRadioText_FernIntro[] = _("FERN: ¡MÚSICA POKéMON!");
static const u8 sRadioText_FernIntro2[] = _("¡Con DJ FERN!");
// "Today's {DAY}," built dynamically
static const u8 sRadioText_BenFern_TodayIs[] = _("Hoy es ");
static const u8 sRadioText_BenFern_JamTo[] = _("¡así que a bailar con la");
static const u8 sRadioText_BenFern_ChillTo[] = _("¡así que a relajarse con la");
static const u8 sRadioText_BenFern_March[] = _("MARCHA POKéMON!");
static const u8 sRadioText_BenFern_Lullaby[] = _("NANA POKéMON!");

// ==========================================================
// Lucky Channel
// ==========================================================

static const u8 sRadioText_LC1[] = _("REED: ¡Yija! ¿Qué tal estáis,");
static const u8 sRadioText_LC2[] = _("amigos? Estéis arriba o abajo,");
static const u8 sRadioText_LC3[] = _("¡no os perdáis el programa del");
static const u8 sRadioText_LC4[] = _("NÚMERO DE LA SUERTE!");
static const u8 sRadioText_LC5[] = _("¡El número de esta semana es el");
// "{number}!" built dynamically
static const u8 sRadioText_LC_Repeat[] = _("¡Lo repito!");
static const u8 sRadioText_LC_Match[] = _("¡Si coincide, venid a la");
static const u8 sRadioText_LC_Tower[] = _("ESTACIÓN DE RADIO!");
static const u8 sRadioText_LC_Drag1[] = _("…Esto de repetirme");
static const u8 sRadioText_LC_Drag2[] = _("es un rollo…");

// ==========================================================
// Places and People
// ==========================================================

static const u8 sRadioText_PnP_Intro[] = _("¡LUGARES Y GENTE! Os lo");
static const u8 sRadioText_PnP_Intro2[] = _("presenta vuestra DJ, ¡LILY!");
static const u8 sRadioText_PnP_Space[] = _(" ");

// People adjectives
static const u8 sRadioText_PnP_Cute[]       = _("es adorable.");
static const u8 sRadioText_PnP_Lazy[]       = _("tiene un aire perezoso.");
static const u8 sRadioText_PnP_Happy[]      = _("siempre está alegre.");
static const u8 sRadioText_PnP_Noisy[]      = _("hace mucho ruido.");
static const u8 sRadioText_PnP_Precocious[] = _("es precoz.");
static const u8 sRadioText_PnP_Bold[]       = _("es algo audaz.");
static const u8 sRadioText_PnP_Picky[]      = _("¡es demasiado exigente!");
static const u8 sRadioText_PnP_SortOfOK[]   = _("no está mal.");
static const u8 sRadioText_PnP_SoSo[]       = _("es del montón.");
static const u8 sRadioText_PnP_Great[]       = _("es genial, la verdad.");
static const u8 sRadioText_PnP_MyType[]      = _("es justo mi tipo.");
static const u8 sRadioText_PnP_Cool[]        = _("mola mucho, ¿no?");
static const u8 sRadioText_PnP_Inspiring[]   = _("¡inspira mucho!");
static const u8 sRadioText_PnP_Weird[]       = _("es algo peculiar.");
static const u8 sRadioText_PnP_RightForMe[]  = _("¿es para mí?");
static const u8 sRadioText_PnP_Odd[]         = _("¡tiene algo muy raro!");

static const u8 *const sRadioText_PnP_PeopleAdj[] =
{
    sRadioText_PnP_Cute,
    sRadioText_PnP_Lazy,
    sRadioText_PnP_Happy,
    sRadioText_PnP_Noisy,
    sRadioText_PnP_Precocious,
    sRadioText_PnP_Bold,
    sRadioText_PnP_Picky,
    sRadioText_PnP_SortOfOK,
    sRadioText_PnP_SoSo,
    sRadioText_PnP_Great,
    sRadioText_PnP_MyType,
    sRadioText_PnP_Cool,
    sRadioText_PnP_Inspiring,
    sRadioText_PnP_Weird,
    sRadioText_PnP_RightForMe,
    sRadioText_PnP_Odd,
};

// ==========================================================
// Rocket Radio
// ==========================================================

static const u8 sRadioStationName_Rocket[] = _("TEAM ROCKET");
static const u8 sRadioText_Rocket1[]  = _("… …Ejem, ¡somos el");
static const u8 sRadioText_Rocket2[]  = _("TEAM ROCKET!");
static const u8 sRadioText_Rocket3[]  = _("¡Tras tres años");
static const u8 sRadioText_Rocket4[]  = _("de preparativos,");
static const u8 sRadioText_Rocket5[]  = _("hemos resurgido");
static const u8 sRadioText_Rocket6[]  = _("de nuestras cenizas!");
static const u8 sRadioText_Rocket7[]  = _("¡GIOVANNI!");
static const u8 sRadioText_Rocket8[]  = _("¿Nos oye?");
static const u8 sRadioText_Rocket9[]  = _("");
static const u8 sRadioText_Rocket10[] = _("");

// ==========================================================
// Buena's Password
// ==========================================================

static const u8 sRadioText_Buena1[] = _("BUENA: ¡Aquí BUENA!");
static const u8 sRadioText_Buena2[] = _("¡La contraseña de hoy!");
static const u8 sRadioText_Buena3[] = _("Déjame pensar… Es");
// "{password}!" built dynamically with STR_VAR_1
static const u8 sRadioText_Buena4[] = _("¡{STR_VAR_1}!");
static const u8 sRadioText_Buena5[] = _("¡No la olvidéis! ¡Estoy en la");
static const u8 sRadioText_Buena6[] = _("ESTACIÓN DE RADIO de TRIGAL!");


// ==========================================================
// Buena's Password Categories & Options
// ==========================================================

static const u8 sRadioBuenaPassword_NewBarkTown[]     = _("PUEBLO PRIMAVERA");
static const u8 sRadioBuenaPassword_CherrygroveCity[]  = _("CIUDAD CEREZO");
static const u8 sRadioBuenaPassword_AzaleaTown[]      = _("PUEBLO AZALEA");
static const u8 sRadioBuenaPassword_Flying[]          = _("VOLAD.");
static const u8 sRadioBuenaPassword_Bug[]             = _("BICHO");
static const u8 sRadioBuenaPassword_Grass[]           = _("PLANTA");
static const u8 sRadioBuenaPassword_PkmnTalk[]        = _("HORA POKéMON");
static const u8 sRadioBuenaPassword_PkmnMusic[]       = _("MÚSICA POKéMON");
static const u8 sRadioBuenaPassword_LuckyChannel[]    = _("CANAL SUERTE");

// ==========================================================
// Oak's POKéMON Talk - Special Reports
// ==========================================================

static const u8 sOPT_Report_Clefairy_0[]  = _("ROSA: Esta noche, ¡un raro");
static const u8 sOPT_Report_Clefairy_1[]  = _("momento lunar en LA HORA POKéMON!");
static const u8 sOPT_Report_Clefairy_2[]  = _("OAK: ¡Hoy hablamos del");
static const u8 sOPT_Report_Clefairy_3[]  = _("místico CLEFAIRY!");
static const u8 sOPT_Report_Clefairy_4[]  = _("Se reúnen en el MT. MOON");
static const u8 sOPT_Report_Clefairy_5[]  = _("en las noches de luna llena.");
static const u8 sOPT_Report_Clefairy_6[]  = _("ROSA: ¡BAILAN en círculos!");
static const u8 sOPT_Report_Clefairy_7[]  = _("¡Qué raros y qué adorables!");
static const u8 sOPT_Report_Clefairy_8[]  = _("OAK: Un misterio eterno");
static const u8 sOPT_Report_Clefairy_9[]  = _("¡y todo un espectáculo!");

static const u8 sOPT_Report_Lapras_0[]  = _("ROSA: ¡Un gigante amable");
static const u8 sOPT_Report_Lapras_1[]  = _("protagoniza el programa de hoy!");
static const u8 sOPT_Report_Lapras_2[]  = _("OAK: ¡Es el ferry del océano,");
static const u8 sOPT_Report_Lapras_3[]  = _("nuestro querido LAPRAS!");
static const u8 sOPT_Report_Lapras_4[]  = _("Se ve en la CUEVA UNIÓN, pero");
static const u8 sOPT_Report_Lapras_5[]  = _("en ningún otro sitio. ¡Curioso!");
static const u8 sOPT_Report_Lapras_6[]  = _("ROSA: ¡Qué raro y qué tranquilo!");
static const u8 sOPT_Report_Lapras_7[]  = _("¡Y además canta!");
static const u8 sOPT_Report_Lapras_8[]  = _("OAK: Dicen que su canto calma");
static const u8 sOPT_Report_Lapras_9[]  = _("el alma del mar.");

static const u8 sOPT_Report_Ampharos_0[]  = _("ROSA: ¡Bienvenidos de nuevo!");
static const u8 sOPT_Report_Ampharos_1[]  = _("¡Empieza LA HORA POKéMON!");
static const u8 sOPT_Report_Ampharos_2[]  = _("OAK: ¡Hoy iluminamos a");
static const u8 sOPT_Report_Ampharos_3[]  = _("nuestro amigo AMPHAROS!");
static const u8 sOPT_Report_Ampharos_4[]  = _("Su cola brillante atraviesa la");
static const u8 sOPT_Report_Ampharos_5[]  = _("niebla y guía a los perdidos.");
static const u8 sOPT_Report_Ampharos_6[]  = _("ROSA: ¡Poderoso, elegante");
static const u8 sOPT_Report_Ampharos_7[]  = _("y simpático a más no poder!");
static const u8 sOPT_Report_Ampharos_8[]  = _("OAK: ¡Es clave en muchas");
static const u8 sOPT_Report_Ampharos_9[]  = _("historias de faros!");

static const u8 sOPT_Report_Sudowoodo_0[]  = _("ROSA: Y ahora, un bicho raro");
static const u8 sOPT_Report_Sudowoodo_1[]  = _("de la RUTA 36...");
static const u8 sOPT_Report_Sudowoodo_2[]  = _("OAK: ¡SUDOWOODO! Parece un");
static const u8 sOPT_Report_Sudowoodo_3[]  = _("árbol, ¡pero no lo es!");
static const u8 sOPT_Report_Sudowoodo_4[]  = _("Bloquea el camino y no se");
static const u8 sOPT_Report_Sudowoodo_5[]  = _("mueve si no le echas agua.");
static const u8 sOPT_Report_Sudowoodo_6[]  = _("ROSA: ¡Solo reacciona a la");
static const u8 sOPT_Report_Sudowoodo_7[]  = _("REGADERA!");
static const u8 sOPT_Report_Sudowoodo_8[]  = _("OAK: ¡No es un arbusto, es un");
static const u8 sOPT_Report_Sudowoodo_9[]  = _("tipo ROCA disfrazado!");

static const u8 sOPT_Report_RedGyarados_0[]  = _("ROSA: ¡La noticia de hoy");
static const u8 sOPT_Report_RedGyarados_1[]  = _("es impactante y viene de JOHTO!");
static const u8 sOPT_Report_RedGyarados_2[]  = _("OAK: ¡Han visto un GYARADOS");
static const u8 sOPT_Report_RedGyarados_3[]  = _("ROJO en el LAGO DE LA FURIA!");
static const u8 sOPT_Report_RedGyarados_4[]  = _("A diferencia de los azules,");
static const u8 sOPT_Report_RedGyarados_5[]  = _("¡este es de un rojo intenso!");
static const u8 sOPT_Report_RedGyarados_6[]  = _("ROSA: ¡Dicen que tiene que ver");
static const u8 sOPT_Report_RedGyarados_7[]  = _("con unas extrañas ondas de radio!");
static const u8 sOPT_Report_RedGyarados_8[]  = _("OAK: Una evolución misteriosa…");
static const u8 sOPT_Report_RedGyarados_9[]  = _("Quizá no sea natural.");

static const u8 sOPT_Report_Unown_0[]  = _("ROSA: ¿Habéis visitado las");
static const u8 sOPT_Report_Unown_1[]  = _("RUINAS ALFA? ¡Dan miedo!");
static const u8 sOPT_Report_Unown_2[]  = _("OAK: Hay extraños símbolos en");
static const u8 sOPT_Report_Unown_3[]  = _("sus muros, como runas antiguas.");
static const u8 sOPT_Report_Unown_4[]  = _("Dentro encontraréis UNOWN…");
static const u8 sOPT_Report_Unown_5[]  = _("¡cada uno con forma de letra!");
static const u8 sOPT_Report_Unown_6[]  = _("ROSA: ¿Quizá escriben algo?");
static const u8 sOPT_Report_Unown_7[]  = _("¡O solo quieren asustarnos!");
static const u8 sOPT_Report_Unown_8[]  = _("OAK: Un auténtico enigma de la");
static const u8 sOPT_Report_Unown_9[]  = _("naturaleza, aún sin resolver.");

static const u8 sOPT_Report_Snubbull_0[]  = _("ROSA: ¡En CIUDAD TRIGAL lo");
static const u8 sOPT_Report_Snubbull_1[]  = _("buscan por todas partes!");
static const u8 sOPT_Report_Snubbull_2[]  = _("OAK: ¡Un SNUBBULL se ha");
static const u8 sOPT_Report_Snubbull_3[]  = _("escapado y anda suelto!");
static const u8 sOPT_Report_Snubbull_4[]  = _("Es tímido y quisquilloso, pero");
static const u8 sOPT_Report_Snubbull_5[]  = _("lo han visto cerca de la estación.");
static const u8 sOPT_Report_Snubbull_6[]  = _("ROSA: Quizá busca el amor…");
static const u8 sOPT_Report_Snubbull_7[]  = _("¡o solo una aventura!");
static const u8 sOPT_Report_Snubbull_8[]  = _("OAK: ¡Estad muy atentos");
static const u8 sOPT_Report_Snubbull_9[]  = _("y tened la correa a mano!");

static const u8 sOPT_Report_Slowpoke_0[]  = _("ROSA: ¡Grandes noticias de");
static const u8 sOPT_Report_Slowpoke_1[]  = _("PUEBLO AZALEA esta semana!");
static const u8 sOPT_Report_Slowpoke_2[]  = _("OAK: ¡Los SLOWPOKE han vuelto");
static const u8 sOPT_Report_Slowpoke_3[]  = _("a su pozo tras una crisis!");
static const u8 sOPT_Report_Slowpoke_4[]  = _("¡El TEAM ROCKET les estaba");
static const u8 sOPT_Report_Slowpoke_5[]  = _("cortando la cola! ¡Qué horror!");
static const u8 sOPT_Report_Slowpoke_6[]  = _("ROSA: ¡Pero alguien muy valiente");
static const u8 sOPT_Report_Slowpoke_7[]  = _("les paró los pies!");
static const u8 sOPT_Report_Slowpoke_8[]  = _("OAK: Los SLOWPOKE están a salvo");
static const u8 sOPT_Report_Slowpoke_9[]  = _("y vuelven a dormitar felices.");

static const u8 sOPT_Report_LavenderTower_0[]  = _("ROSA: ¡La torre de PUEBLO LAVANDA");
static const u8 sOPT_Report_LavenderTower_1[]  = _("ha cambiado de sintonía!");
static const u8 sOPT_Report_LavenderTower_2[]  = _("OAK: ¡La vieja torre fantasma");
static const u8 sOPT_Report_LavenderTower_3[]  = _("es ahora una EMISORA DE RADIO!");
static const u8 sOPT_Report_LavenderTower_4[]  = _("Algunos vecinos dicen que aún");
static const u8 sOPT_Report_LavenderTower_5[]  = _("da… un poco de miedo.");
static const u8 sOPT_Report_LavenderTower_6[]  = _("ROSA: ¡Juraría que vi un GASTLY");
static const u8 sOPT_Report_LavenderTower_7[]  = _("junto a la cabina del micro!");
static const u8 sOPT_Report_LavenderTower_8[]  = _("OAK: Puede que fuera estática…");
static const u8 sOPT_Report_LavenderTower_9[]  = _("¡o espectros!");

static const u8 sOPT_Report_Tentacruel_0[]  = _("ROSA: ¡Noticias extrañas desde");
static const u8 sOPT_Report_Tentacruel_1[]  = _("las ISLAS REMOLINO!");
static const u8 sOPT_Report_Tentacruel_2[]  = _("OAK: ¡Los TENTACRUEL rodean");
static const u8 sOPT_Report_Tentacruel_3[]  = _("las entradas de las cuevas!");
static const u8 sOPT_Report_Tentacruel_4[]  = _("Son enormes y se comportan");
static const u8 sOPT_Report_Tentacruel_5[]  = _("de forma casi territorial.");
static const u8 sOPT_Report_Tentacruel_6[]  = _("ROSA: Bloquean el paso");
static const u8 sOPT_Report_Tentacruel_7[]  = _("sin atacar…");
static const u8 sOPT_Report_Tentacruel_8[]  = _("OAK: Como si protegieran algo");
static const u8 sOPT_Report_Tentacruel_9[]  = _("en las profundidades del mar.");

#define OPT_REPORT_LINES 10
#define NUM_OPT_REPORTS 10

static const u8 *const sOPT_Reports[NUM_OPT_REPORTS][OPT_REPORT_LINES] =
{
    { sOPT_Report_Clefairy_0, sOPT_Report_Clefairy_1, sOPT_Report_Clefairy_2, sOPT_Report_Clefairy_3, sOPT_Report_Clefairy_4, sOPT_Report_Clefairy_5, sOPT_Report_Clefairy_6, sOPT_Report_Clefairy_7, sOPT_Report_Clefairy_8, sOPT_Report_Clefairy_9 },
    { sOPT_Report_Lapras_0, sOPT_Report_Lapras_1, sOPT_Report_Lapras_2, sOPT_Report_Lapras_3, sOPT_Report_Lapras_4, sOPT_Report_Lapras_5, sOPT_Report_Lapras_6, sOPT_Report_Lapras_7, sOPT_Report_Lapras_8, sOPT_Report_Lapras_9 },
    { sOPT_Report_Ampharos_0, sOPT_Report_Ampharos_1, sOPT_Report_Ampharos_2, sOPT_Report_Ampharos_3, sOPT_Report_Ampharos_4, sOPT_Report_Ampharos_5, sOPT_Report_Ampharos_6, sOPT_Report_Ampharos_7, sOPT_Report_Ampharos_8, sOPT_Report_Ampharos_9 },
    { sOPT_Report_Sudowoodo_0, sOPT_Report_Sudowoodo_1, sOPT_Report_Sudowoodo_2, sOPT_Report_Sudowoodo_3, sOPT_Report_Sudowoodo_4, sOPT_Report_Sudowoodo_5, sOPT_Report_Sudowoodo_6, sOPT_Report_Sudowoodo_7, sOPT_Report_Sudowoodo_8, sOPT_Report_Sudowoodo_9 },
    { sOPT_Report_RedGyarados_0, sOPT_Report_RedGyarados_1, sOPT_Report_RedGyarados_2, sOPT_Report_RedGyarados_3, sOPT_Report_RedGyarados_4, sOPT_Report_RedGyarados_5, sOPT_Report_RedGyarados_6, sOPT_Report_RedGyarados_7, sOPT_Report_RedGyarados_8, sOPT_Report_RedGyarados_9 },
    { sOPT_Report_Unown_0, sOPT_Report_Unown_1, sOPT_Report_Unown_2, sOPT_Report_Unown_3, sOPT_Report_Unown_4, sOPT_Report_Unown_5, sOPT_Report_Unown_6, sOPT_Report_Unown_7, sOPT_Report_Unown_8, sOPT_Report_Unown_9 },
    { sOPT_Report_Snubbull_0, sOPT_Report_Snubbull_1, sOPT_Report_Snubbull_2, sOPT_Report_Snubbull_3, sOPT_Report_Snubbull_4, sOPT_Report_Snubbull_5, sOPT_Report_Snubbull_6, sOPT_Report_Snubbull_7, sOPT_Report_Snubbull_8, sOPT_Report_Snubbull_9 },
    { sOPT_Report_Slowpoke_0, sOPT_Report_Slowpoke_1, sOPT_Report_Slowpoke_2, sOPT_Report_Slowpoke_3, sOPT_Report_Slowpoke_4, sOPT_Report_Slowpoke_5, sOPT_Report_Slowpoke_6, sOPT_Report_Slowpoke_7, sOPT_Report_Slowpoke_8, sOPT_Report_Slowpoke_9 },
    { sOPT_Report_LavenderTower_0, sOPT_Report_LavenderTower_1, sOPT_Report_LavenderTower_2, sOPT_Report_LavenderTower_3, sOPT_Report_LavenderTower_4, sOPT_Report_LavenderTower_5, sOPT_Report_LavenderTower_6, sOPT_Report_LavenderTower_7, sOPT_Report_LavenderTower_8, sOPT_Report_LavenderTower_9 },
    { sOPT_Report_Tentacruel_0, sOPT_Report_Tentacruel_1, sOPT_Report_Tentacruel_2, sOPT_Report_Tentacruel_3, sOPT_Report_Tentacruel_4, sOPT_Report_Tentacruel_5, sOPT_Report_Tentacruel_6, sOPT_Report_Tentacruel_7, sOPT_Report_Tentacruel_8, sOPT_Report_Tentacruel_9 },
};

#endif // GUARD_DATA_TEXT_RADIO_STRINGS_H
