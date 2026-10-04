#if IS_HNS
// HnS rematch trainer check page text — currently unused (check page disabled).
// Rematch slot → HnS trainer mapping kept here for reference if re-enabled.
// REMATCH_ROSE         = Joey (Youngster, Route 30)
// REMATCH_ANDRES       = Wade (Bug Catcher, Route 31)
// REMATCH_DUSTY        = Ralph (Fisherman, Route 32)
// REMATCH_LOLA         = Liz (Picnicker, Route 32)
// REMATCH_RICKY        = Anthony (Hiker, Route 33)
// REMATCH_LILA_AND_ROY = Todd (Camper, Route 34)
// REMATCH_CRISTIN      = Gina (Picnicker, Route 34)
// REMATCH_BROOKE       = Irwin (Juggler, Route 35)
// REMATCH_WILTON       = Arnie (Bug Catcher, Route 35)
// REMATCH_VALERIE      = Alan (School Kid, Route 36)
// REMATCH_CINDY        = Dana (Lass, Route 38)
// REMATCH_THALIA       = Chad (School Kid, Route 38)
// REMATCH_JESSICA      = Derek (Pokefan, Route 39)
// REMATCH_WINSTON      = Tully (Fisherman, Route 42)
// REMATCH_STEVE        = Brent (Pokemaniac, Route 43)
// REMATCH_TONY         = Tiffany (Picnicker, Route 43)
// REMATCH_NOB          = Vance (Bird Keeper, Route 44)
// REMATCH_KOJI         = Wilton (Fisherman, Route 44)
// REMATCH_FERNANDO     = Kenji (Black Belt, Route 45)
// REMATCH_DALTON       = Parry (Hiker, Route 45)
// REMATCH_BERNIE       = Erin (Picnicker, Route 46)
// REMATCH_ETHAN        = Jack (School Kid, National Park)
// REMATCH_JOHN_AND_JAY = Beverly (Parasol Lady, National Park)
// REMATCH_JEFFREY      = Huey (Sailor, Lighthouse)
// REMATCH_CAMERON      = Gaven (Cooltrainer, Route 26)
// REMATCH_JACKI        = Beth (Cooltrainer, Route 26)
// REMATCH_WALTER       = Jose (Bird Keeper, Route 27)
// REMATCH_KAREN        = Reena (Cooltrainer, Route 27)
// Crystal phone text reference: pokecrystal/data/phone/text/<name>_caller.asm
#else
const u8 gText_MatchCallAromaLady_Rose_Strategy[] = _("Calma las emociones del combate.");
const u8 gText_MatchCallAromaLady_Rose_Pokemon[] = _("POKéMON PLANTA fragantes.");
const u8 gText_MatchCallAromaLady_Rose_Intro1[] = _("Los aromas relajantes dan");
const u8 gText_MatchCallAromaLady_Rose_Intro2[] = _("salud al cuerpo y la mente.");

const u8 gText_MatchCallRuinManiac_Andres_Strategy[] = _("No se me da muy bien.");
const u8 gText_MatchCallRuinManiac_Andres_Pokemon[] = _("Compañeros de exploración.");
const u8 gText_MatchCallRuinManiac_Andres_Intro1[] = _("Busco ruinas y reliquias");
const u8 gText_MatchCallRuinManiac_Andres_Intro2[] = _("submarinas.");

const u8 gText_MatchCallRuinManiac_Dusty_Strategy[] = _("¡Aplasta con fuerza!");
const u8 gText_MatchCallRuinManiac_Dusty_Pokemon[] = _("POKéMON ROCA escarpados.");
const u8 gText_MatchCallRuinManiac_Dusty_Intro1[] = _("En busca de saber antiguo,");
const u8 gText_MatchCallRuinManiac_Dusty_Intro2[] = _("recorro el mundo.");

const u8 gText_MatchCallTuber_Lola_Strategy[] = _("¡Me esforzaré a tope!");
const u8 gText_MatchCallTuber_Lola_Pokemon[] = _("POKéMON buenos nadadores.");
const u8 gText_MatchCallTuber_Lola_Intro1[] = _("Ojalá pudiera nadar sin");
const u8 gText_MatchCallTuber_Lola_Intro2[] = _("usar flotador.");

const u8 gText_MatchCallTuber_Ricky_Strategy[] = _("No sé. Me esforzaré.");
const u8 gText_MatchCallTuber_Ricky_Pokemon[] = _("Los POKéMON AGUA son colegas.");
const u8 gText_MatchCallTuber_Ricky_Intro1[] = _("No es que no sepa nadar.");
const u8 gText_MatchCallTuber_Ricky_Intro2[] = _("Es que me gusta mi flotador.");

const u8 gText_MatchCallSisAndBro_LilaAndRoy_Strategy[] = _("Nos repartimos las tareas.");
const u8 gText_MatchCallSisAndBro_LilaAndRoy_Pokemon[] = _("Nos gustan los POKéMON amistosos.");
const u8 gText_MatchCallSisAndBro_LilaAndRoy_Intro1[] = _("Disfrutamos de los POKéMON");
const u8 gText_MatchCallSisAndBro_LilaAndRoy_Intro2[] = _("como hermana y hermano.");

const u8 gText_MatchCallCooltrainer_Cristin_Strategy[] = _("¡Termino con movimientos fuertes!");
const u8 gText_MatchCallCooltrainer_Cristin_Pokemon[] = _("Mezcla de diferentes tipos.");
const u8 gText_MatchCallCooltrainer_Cristin_Intro1[] = _("Aspiro a ser el mejor");
const u8 gText_MatchCallCooltrainer_Cristin_Intro2[] = _("TRAINER!");

const u8 gText_MatchCallCooltrainer_Brooke_Strategy[] = _("Aprovecho la debilidad rival.");
const u8 gText_MatchCallCooltrainer_Brooke_Pokemon[] = _("El equilibrio es clave.");
const u8 gText_MatchCallCooltrainer_Brooke_Intro1[] = _("Mi objetivo es convertirme en");
const u8 gText_MatchCallCooltrainer_Brooke_Intro2[] = _("POKéMON CHAMPION.");

const u8 gText_MatchCallCooltrainer_Wilton_Strategy[] = _("Desconcertar al rival.");
const u8 gText_MatchCallCooltrainer_Wilton_Pokemon[] = _("El tipo no importa.");
const u8 gText_MatchCallCooltrainer_Wilton_Intro1[] = _("Soy un estudiante destacado");
const u8 gText_MatchCallCooltrainer_Wilton_Intro2[] = _("TRAINER'S SCHOOL.");

const u8 gText_MatchCallHexManiac_Valerie_Strategy[] = _("Sufrimiento lento y constante.");
const u8 gText_MatchCallHexManiac_Valerie_Pokemon[] = _("Da miedo encontrarlo de noche.");
const u8 gText_MatchCallHexManiac_Valerie_Intro1[] = _("Veo cosas que otros");
const u8 gText_MatchCallHexManiac_Valerie_Intro2[] = _("no pueden ver...");

const u8 gText_MatchCallLady_Cindy_Strategy[] = _("Lo que sea por ganar.");
const u8 gText_MatchCallLady_Cindy_Pokemon[] = _("¡Un tipo precioso!");
const u8 gText_MatchCallLady_Cindy_Intro1[] = _("Tengo una piscina para mis");
const u8 gText_MatchCallLady_Cindy_Intro2[] = _("POKéMON en casa.");

const u8 gText_MatchCallBeauty_Thalia_Strategy[] = _("¡Caerás bajo mi hechizo!");
const u8 gText_MatchCallBeauty_Thalia_Pokemon[] = _("Tipo AGUA maduro.");
const u8 gText_MatchCallBeauty_Thalia_Intro1[] = _("Sueño con recorrer el mundo");
const u8 gText_MatchCallBeauty_Thalia_Intro2[] = _("en un crucero de lujo.");

const u8 gText_MatchCallBeauty_Jessica_Strategy[] = _("Te llevaré por mal camino.");
const u8 gText_MatchCallBeauty_Jessica_Pokemon[] = _("Monos, por supuesto.");
const u8 gText_MatchCallBeauty_Jessica_Intro1[] = _("Me encanta la ZONA SAFARI.");
const u8 gText_MatchCallBeauty_Jessica_Intro2[] = _("Siempre acabo allí.");

const u8 gText_MatchCallRichBoy_Winston_Strategy[] = _("¿Estrategia? ¿Quién la necesita?");
const u8 gText_MatchCallRichBoy_Winston_Pokemon[] = _("¡Me costó un dineral!");
const u8 gText_MatchCallRichBoy_Winston_Intro1[] = _("Yo, siendo rico, duermo en una");
const u8 gText_MatchCallRichBoy_Winston_Intro2[] = _("cama POKéMON a medida.");

const u8 gText_MatchCallPokeManiac_Steve_Strategy[] = _("Luchar con fuerza.");
const u8 gText_MatchCallPokeManiac_Steve_Pokemon[] = _("Costó toda la noche atraparlo.");
const u8 gText_MatchCallPokeManiac_Steve_Intro1[] = _("Los POKéMON grandes, fornidos");
const u8 gText_MatchCallPokeManiac_Steve_Intro2[] = _("y musculosos son los mejores...");

const u8 gText_MatchCallSwimmer_Tony_Strategy[] = _("¡Embestir a toda velocidad!");
const u8 gText_MatchCallSwimmer_Tony_Pokemon[] = _("¡Un tipo AGUA con estilo!");
const u8 gText_MatchCallSwimmer_Tony_Intro1[] = _("Si no puedo estar nadando,");
const u8 gText_MatchCallSwimmer_Tony_Intro2[] = _("levantaré pesas.");

const u8 gText_MatchCallBlackBelt_Nob_Strategy[] = _("¡Paliza de campeonato!");
const u8 gText_MatchCallBlackBelt_Nob_Pokemon[] = _("FIGHTING type.");
const u8 gText_MatchCallBlackBelt_Nob_Intro1[] = _("Sin presumir, puedo romper");
const u8 gText_MatchCallBlackBelt_Nob_Intro2[] = _("¡diez tejas!");

const u8 gText_MatchCallBlackBelt_Koji_Strategy[] = _("¡Contempla el poder del kárate!");
const u8 gText_MatchCallBlackBelt_Koji_Pokemon[] = _("¡Mis compañeros de entrenamiento!");
const u8 gText_MatchCallBlackBelt_Koji_Intro1[] = _("Hablemos de los asuntos del");
const u8 gText_MatchCallBlackBelt_Koji_Intro2[] = _("mundo con los puños desnudos.");

const u8 gText_MatchCallGuitarist_Fernando_Strategy[] = _("¡Rockea con sonidos asombrosos!");
const u8 gText_MatchCallGuitarist_Fernando_Pokemon[] = _("¡Combo de electricidad y sonido!");
const u8 gText_MatchCallGuitarist_Fernando_Intro1[] = _("¡Mis composiciones te");
const u8 gText_MatchCallGuitarist_Fernando_Intro2[] = _("impactarán y aturdirán!");

const u8 gText_MatchCallGuitarist_Dalton_Strategy[] = _("¡Te electrizaré!");
const u8 gText_MatchCallGuitarist_Dalton_Pokemon[] = _("¡Son ELÉCTRICOS!");
const u8 gText_MatchCallGuitarist_Dalton_Intro1[] = _("Quiero hacer llorar a la gente");
const u8 gText_MatchCallGuitarist_Dalton_Intro2[] = _("con canciones del corazón.");

const u8 gText_MatchCallKindler_Bernie_Strategy[] = _("¡Quémalo todo!");
const u8 gText_MatchCallKindler_Bernie_Pokemon[] = _("POKéMON que provocan quemaduras.");
const u8 gText_MatchCallKindler_Bernie_Intro1[] = _("Cuando enciendas una hoguera,");
const u8 gText_MatchCallKindler_Bernie_Intro2[] = _("ten agua a mano.");

const u8 gText_MatchCallCamper_Ethan_Strategy[] = _("¡Aguanta y sé tenaz!");
const u8 gText_MatchCallCamper_Ethan_Pokemon[] = _("Criaré cualquier POKéMON.");
const u8 gText_MatchCallCamper_Ethan_Intro1[] = _("¡Los POKéMON criados en la");
const u8 gText_MatchCallCamper_Ethan_Intro2[] = _("naturaleza se hacen fuertes!");

const u8 gText_MatchCallOldCouple_JohnAndJay_Strategy[] = _("Nuestro amor nos hace vencer.");
const u8 gText_MatchCallOldCouple_JohnAndJay_Pokemon[] = _("Los tenemos desde hace años.");
const u8 gText_MatchCallOldCouple_JohnAndJay_Intro1[] = _("Casados desde hace 50 años,");
const u8 gText_MatchCallOldCouple_JohnAndJay_Intro2[] = _("criamos POKéMON con devoción.");

const u8 gText_MatchCallBugManiac_Jeffrey_Strategy[] = _("¡Ataca en oleadas!");
const u8 gText_MatchCallBugManiac_Jeffrey_Pokemon[] = _("Los POKéMON BICHO son geniales.");
const u8 gText_MatchCallBugManiac_Jeffrey_Intro1[] = _("Voy al bosque cada día");
const u8 gText_MatchCallBugManiac_Jeffrey_Intro2[] = _("a capturar POKéMON BICHO.");

const u8 gText_MatchCallPsychic_Cameron_Strategy[] = _("¡Aturdir y confundir!");
const u8 gText_MatchCallPsychic_Cameron_Pokemon[] = _("Los de poderes extraños.");
const u8 gText_MatchCallPsychic_Cameron_Intro1[] = _("¡Veo exactamente lo que");
const u8 gText_MatchCallPsychic_Cameron_Intro2[] = _("estás pensando!");

const u8 gText_MatchCallPsychic_Jacki_Strategy[] = _("Combate a pleno poder.");
const u8 gText_MatchCallPsychic_Jacki_Pokemon[] = _("POKéMON de muchos misterios.");
const u8 gText_MatchCallPsychic_Jacki_Intro1[] = _("Cuando hablamos, en realidad");
const u8 gText_MatchCallPsychic_Jacki_Intro2[] = _("usaba telepatía.");

const u8 gText_MatchCallGentleman_Walter_Strategy[] = _("Calma y serenidad.");
const u8 gText_MatchCallGentleman_Walter_Pokemon[] = _("POKéMON distinguidos.");
const u8 gText_MatchCallGentleman_Walter_Intro1[] = _("Tomamos el té cada día.");
const u8 gText_MatchCallGentleman_Walter_Intro2[] = _("Es importado.");

const u8 gText_MatchCallSchoolKid_Karen_Strategy[] = _("Combato con la cabeza.");
const u8 gText_MatchCallSchoolKid_Karen_Pokemon[] = _("¡Me encanta cualquier POKéMON!");
const u8 gText_MatchCallSchoolKid_Karen_Intro1[] = _("Mi papá me da una paga si");
const u8 gText_MatchCallSchoolKid_Karen_Intro2[] = _("saco buena nota en un examen.");

const u8 gText_MatchCallSchoolKid_Jerry_Strategy[] = _("¡Mi conocimiento manda!");
const u8 gText_MatchCallSchoolKid_Jerry_Pokemon[] = _("¡Cualquier POKéMON listo!");
const u8 gText_MatchCallSchoolKid_Jerry_Intro1[] = _("Quiero ser investigador");
const u8 gText_MatchCallSchoolKid_Jerry_Intro2[] = _("de POKéMON en el futuro.");

const u8 gText_MatchCallSrAndJr_AnnaAndMeg_Strategy[] = _("Lo hablamos primero.");
const u8 gText_MatchCallSrAndJr_AnnaAndMeg_Pokemon[] = _("POKéMON que nos gustan a las dos.");
const u8 gText_MatchCallSrAndJr_AnnaAndMeg_Intro1[] = _("¡Somos alumnas mayor y menor");
const u8 gText_MatchCallSrAndJr_AnnaAndMeg_Intro2[] = _("fanáticas de los POKéMON!");

const u8 gText_MatchCallPokefan_Isabel_Strategy[] = _("¡Adelante, mis queridos!");
const u8 gText_MatchCallPokefan_Isabel_Pokemon[] = _("No tengo gustos ni manías.");
const u8 gText_MatchCallPokefan_Isabel_Intro1[] = _("Mientras compro la cena,");
const u8 gText_MatchCallPokefan_Isabel_Intro2[] = _("también combato.");

const u8 gText_MatchCallPokefan_Miguel_Strategy[] = _("¡Combato con amor!");
const u8 gText_MatchCallPokefan_Miguel_Pokemon[] = _("¡Un POKéMON criado con amor!");
const u8 gText_MatchCallPokefan_Miguel_Intro1[] = _("Es importante ganarse la");
const u8 gText_MatchCallPokefan_Miguel_Intro2[] = _("confianza de tus POKéMON.");

const u8 gText_MatchCallExpert_Timothy_Strategy[] = _("¡Veo a través de tus movimientos!");
const u8 gText_MatchCallExpert_Timothy_Pokemon[] = _("La esencia de LUCHA.");
const u8 gText_MatchCallExpert_Timothy_Intro1[] = _("¡Aún no estoy listo para");
const u8 gText_MatchCallExpert_Timothy_Intro2[] = _("ceder el paso a los jóvenes!");

const u8 gText_MatchCallExpert_Shelby_Strategy[] = _("Atacar mientras defiendo.");
const u8 gText_MatchCallExpert_Shelby_Pokemon[] = _("El tipo LUCHA.");
const u8 gText_MatchCallExpert_Shelby_Intro1[] = _("Siendo mayor, tengo mi propio");
const u8 gText_MatchCallExpert_Shelby_Intro2[] = _("estilo de combate.");

const u8 gText_MatchCallYoungster_Calvin_Strategy[] = _("Hago lo que puedo.");
const u8 gText_MatchCallYoungster_Calvin_Pokemon[] = _("I use different types.");
const u8 gText_MatchCallYoungster_Calvin_Intro1[] = _("Seguiré trabajando hasta");
const u8 gText_MatchCallYoungster_Calvin_Intro2[] = _("derrotar a un LÍDER de GIMNASIO.");

const u8 gText_MatchCallFisherman_Elliot_Strategy[] = _("Combato con paciencia.");
const u8 gText_MatchCallFisherman_Elliot_Pokemon[] = _("¡POKéMON AGUA al combate!");
const u8 gText_MatchCallFisherman_Elliot_Intro1[] = _("¡Soy el único del mundo que");
const u8 gText_MatchCallFisherman_Elliot_Intro2[] = _("capturó un POKéMON enorme!");

const u8 gText_MatchCallTriathlete_Isaiah_Strategy[] = _("¡Aprovecha el entorno!");
const u8 gText_MatchCallTriathlete_Isaiah_Pokemon[] = _("¡Viva el tipo AGUA!");
const u8 gText_MatchCallTriathlete_Isaiah_Intro1[] = _("¡No me vencerá un simple");
const u8 gText_MatchCallTriathlete_Isaiah_Intro2[] = _("NADADOR de playa!");

const u8 gText_MatchCallTriathlete_Maria_Strategy[] = _("¡La velocidad ante todo!");
const u8 gText_MatchCallTriathlete_Maria_Pokemon[] = _("Uso un POKéMON veloz.");
const u8 gText_MatchCallTriathlete_Maria_Intro1[] = _("Un maratón es un desafío");
const u8 gText_MatchCallTriathlete_Maria_Intro2[] = _("contra uno mismo.");

const u8 gText_MatchCallTriathlete_Abigail_Strategy[] = _("La defensa es crucial.");
const u8 gText_MatchCallTriathlete_Abigail_Pokemon[] = _("Mi POKéMON es sólido.");
const u8 gText_MatchCallTriathlete_Abigail_Intro1[] = _("Empecé para adelgazar,");
const u8 gText_MatchCallTriathlete_Abigail_Intro2[] = _("pero me enganché.");

const u8 gText_MatchCallTriathlete_Dylan_Strategy[] = _("¡Golpea antes de que te golpeen!");
const u8 gText_MatchCallTriathlete_Dylan_Pokemon[] = _("¡Un POKéMON de carrera veloz!");
const u8 gText_MatchCallTriathlete_Dylan_Intro1[] = _("Si corrieras y corrieras,");
const u8 gText_MatchCallTriathlete_Dylan_Intro2[] = _("serías uno con el viento.");

const u8 gText_MatchCallTriathlete_Katelyn_Strategy[] = _("¡Ofensiva total!");
const u8 gText_MatchCallTriathlete_Katelyn_Pokemon[] = _("¡Los POKéMON AGUA mandan!");
const u8 gText_MatchCallTriathlete_Katelyn_Intro1[] = _("Debo nadar más de 10 km");
const u8 gText_MatchCallTriathlete_Katelyn_Intro2[] = _("every day.");

const u8 gText_MatchCallTriathlete_Benjamin_Strategy[] = _("¡Empuja y empuja otra vez!");
const u8 gText_MatchCallTriathlete_Benjamin_Pokemon[] = _("La fuerza del ACERO.");
const u8 gText_MatchCallTriathlete_Benjamin_Intro1[] = _("Si estás sudando, bebe");
const u8 gText_MatchCallTriathlete_Benjamin_Intro2[] = _("líquidos con regularidad.");

const u8 gText_MatchCallTriathlete_Pablo_Strategy[] = _("Saca el poder del AGUA.");
const u8 gText_MatchCallTriathlete_Pablo_Pokemon[] = _("POKéMON AGUA curtidos.");
const u8 gText_MatchCallTriathlete_Pablo_Intro1[] = _("Entrenar POKéMON está bien,");
const u8 gText_MatchCallTriathlete_Pablo_Intro2[] = _("pero no te descuides.");

const u8 gText_MatchCallDragonTamer_Nicolas_Strategy[] = _("¡Se trata del poder POKéMON!");
const u8 gText_MatchCallDragonTamer_Nicolas_Pokemon[] = _("¡Mira el poder de los DRAGONES!");
const u8 gText_MatchCallDragonTamer_Nicolas_Intro1[] = _("Algún día seré legendario");
const u8 gText_MatchCallDragonTamer_Nicolas_Intro2[] = _("como el más fuerte.");

const u8 gText_MatchCallBirdKeeper_Robert_Strategy[] = _("¡Te mostraré mi técnica!");
const u8 gText_MatchCallBirdKeeper_Robert_Pokemon[] = _("AVES que giran con elegancia.");
const u8 gText_MatchCallBirdKeeper_Robert_Intro1[] = _("Mis POKéMON AVE, ¡llevad mi");
const u8 gText_MatchCallBirdKeeper_Robert_Intro2[] = _("amor a esa chica!");

const u8 gText_MatchCallNinjaBoy_Lao_Strategy[] = _("¡Sufrirás el veneno!");
const u8 gText_MatchCallNinjaBoy_Lao_Pokemon[] = _("POKéMON venenosos.");
const u8 gText_MatchCallNinjaBoy_Lao_Intro1[] = _("Me entreno para poder");
const u8 gText_MatchCallNinjaBoy_Lao_Intro2[] = _("ser ninja.");

const u8 gText_MatchCallBattleGirl_Cyndy_Strategy[] = _("¡Quien golpea primero gana!");
const u8 gText_MatchCallBattleGirl_Cyndy_Pokemon[] = _("Tipo LUCHA veloz.");
const u8 gText_MatchCallBattleGirl_Cyndy_Intro1[] = _("Si mis POKéMON pierden,");
const u8 gText_MatchCallBattleGirl_Cyndy_Intro2[] = _("¡seguiré luchando yo!");

const u8 gText_MatchCallParasolLady_Madeline_Strategy[] = _("¡Vamos, vamos, mis POKéMON!");
const u8 gText_MatchCallParasolLady_Madeline_Pokemon[] = _("Criaré lo que sea.");
const u8 gText_MatchCallParasolLady_Madeline_Intro1[] = _("Los rayos UV son enemigos de");
const u8 gText_MatchCallParasolLady_Madeline_Intro2[] = _("tu piel. Protégete.");

const u8 gText_MatchCallSwimmer_Jenny_Strategy[] = _("¡Sin piedad!");
const u8 gText_MatchCallSwimmer_Jenny_Pokemon[] = _("POKéMON AGUA monos.");
const u8 gText_MatchCallSwimmer_Jenny_Intro1[] = _("Tengo demasiados fans.");
const u8 gText_MatchCallSwimmer_Jenny_Intro2[] = _("Salí entrevistada en la tele.");

const u8 gText_MatchCallPicnicker_Diana_Strategy[] = _("Pienso en esto y en aquello.");
const u8 gText_MatchCallPicnicker_Diana_Pokemon[] = _("Me gustan todos los POKéMON.");
const u8 gText_MatchCallPicnicker_Diana_Intro1[] = _("¿Qué habrá más allá de");
const u8 gText_MatchCallPicnicker_Diana_Intro2[] = _("aquella colina?");

const u8 gText_MatchCallTwins_AmyAndLiv_Strategy[] = _("¡Combatimos juntos!");
const u8 gText_MatchCallTwins_AmyAndLiv_Pokemon[] = _("¡Entrenamos juntas!");
const u8 gText_MatchCallTwins_AmyAndLiv_Intro1[] = _("Nos gustan los mismos POKéMON,");
const u8 gText_MatchCallTwins_AmyAndLiv_Intro2[] = _("pero distintos postres.");

const u8 gText_MatchCallSailor_Ernest_Strategy[] = _("¡Fuerzo las cosas con poder!");
const u8 gText_MatchCallSailor_Ernest_Pokemon[] = _("Tipos AGUA y LUCHA.");
const u8 gText_MatchCallSailor_Ernest_Intro1[] = _("¡Los marineros somos rudos!");
const u8 gText_MatchCallSailor_Ernest_Intro2[] = _("¿Alguna queja?");

const u8 gText_MatchCallSailor_Cory_Strategy[] = _("¡Listo para pelear siempre!");
const u8 gText_MatchCallSailor_Cory_Pokemon[] = _("¡Mis favoritos son los POKéMON AGUA!");
const u8 gText_MatchCallSailor_Cory_Intro1[] = _("Si quieres gritar fuerte,");
const u8 gText_MatchCallSailor_Cory_Intro2[] = _("¡toma aire con la barriga!");

const u8 gText_MatchCallCollector_Edwin_Strategy[] = _("Proteger a los POKéMON del daño.");
const u8 gText_MatchCallCollector_Edwin_Pokemon[] = _("Me encantan los POKéMON raros.");
const u8 gText_MatchCallCollector_Edwin_Intro1[] = _("Quiero coleccionar todos los");
const u8 gText_MatchCallCollector_Edwin_Intro2[] = _("POKéMON raros del mundo.");

const u8 gText_MatchCallPkmnBreeder_Lydia_Strategy[] = _("Confío en la fuerza.");
const u8 gText_MatchCallPkmnBreeder_Lydia_Pokemon[] = _("Los POKéMON son mis hijos.");
const u8 gText_MatchCallPkmnBreeder_Lydia_Intro1[] = _("Criar POKéMON requiere");
const u8 gText_MatchCallPkmnBreeder_Lydia_Intro2[] = _("conocimiento y amor.");

const u8 gText_MatchCallPkmnBreeder_Isaac_Strategy[] = _("¡Ataque total!");
const u8 gText_MatchCallPkmnBreeder_Isaac_Pokemon[] = _("Cualquiera. Lo criaré.");
const u8 gText_MatchCallPkmnBreeder_Isaac_Intro1[] = _("Les doy {POKEBLOCK}S para");
const u8 gText_MatchCallPkmnBreeder_Isaac_Intro2[] = _("que busquen títulos de CONCURSO.");

const u8 gText_MatchCallPkmnBreeder_Gabrielle_Strategy[] = _("Crío POKéMON con cuidado.");
const u8 gText_MatchCallPkmnBreeder_Gabrielle_Pokemon[] = _("POKéMON divertidos de criar.");
const u8 gText_MatchCallPkmnBreeder_Gabrielle_Intro1[] = _("Trata con respeto a todos");
const u8 gText_MatchCallPkmnBreeder_Gabrielle_Intro2[] = _("los POKéMON que conozcas.");

const u8 gText_MatchCallPkmnRanger_Catherine_Strategy[] = _("Creo en mis POKéMON.");
const u8 gText_MatchCallPkmnRanger_Catherine_Pokemon[] = _("Me gustan los POKéMON fuertes.");
const u8 gText_MatchCallPkmnRanger_Catherine_Intro1[] = _("Me entreno para el rescate");
const u8 gText_MatchCallPkmnRanger_Catherine_Intro2[] = _("con mis POKéMON.");

const u8 gText_MatchCallPkmnRanger_Jackson_Strategy[] = _("¡Ataca en oleadas!");
const u8 gText_MatchCallPkmnRanger_Jackson_Pokemon[] = _("I use different types.");
const u8 gText_MatchCallPkmnRanger_Jackson_Intro1[] = _("¡A quienes destruyen la naturaleza");
const u8 gText_MatchCallPkmnRanger_Jackson_Intro2[] = _("jamás se les debe perdonar!");

const u8 gText_MatchCallLass_Haley_Strategy[] = _("¡Te mostraré mis agallas!");
const u8 gText_MatchCallLass_Haley_Pokemon[] = _("¡Mis favoritos son los POKéMON monos!");
const u8 gText_MatchCallLass_Haley_Intro1[] = _("Tras un combate, siempre");
const u8 gText_MatchCallLass_Haley_Intro2[] = _("me baño con mis POKéMON.");

const u8 gText_MatchCallBugCatcher_James_Strategy[] = _("¡Ataque rápido como un rayo!");
const u8 gText_MatchCallBugCatcher_James_Pokemon[] = _("¡Los POKéMON BICHO son los mejores!");
const u8 gText_MatchCallBugCatcher_James_Intro1[] = _("Si quieres capturar POKéMON");
const u8 gText_MatchCallBugCatcher_James_Intro2[] = _("BICHO, madruga.");

const u8 gText_MatchCallHiker_Trent_Strategy[] = _("Combato con fuerza.");
const u8 gText_MatchCallHiker_Trent_Pokemon[] = _("POKéMON de cuerpo duro.");
const u8 gText_MatchCallHiker_Trent_Intro1[] = _("Llevo un mes planeando la");
const u8 gText_MatchCallHiker_Trent_Intro2[] = _("excursión de hoy.");

const u8 gText_MatchCallHiker_Sawyer_Strategy[] = _("¡Me gusta el calor!");
const u8 gText_MatchCallHiker_Sawyer_Pokemon[] = _("¡POKéMON calientes!");
const u8 gText_MatchCallHiker_Sawyer_Intro1[] = _("Por mucho que ame a los POKéMON,");
const u8 gText_MatchCallHiker_Sawyer_Intro2[] = _("¡me encanta el senderismo!");

const u8 gText_MatchCallYoungCouple_LoisAndHal_Strategy[] = _("¡Estrategia de tortolitos!");
const u8 gText_MatchCallYoungCouple_LoisAndHal_Pokemon[] = _("¡POKéMON tortolitos!");
const u8 gText_MatchCallYoungCouple_LoisAndHal_Intro1[] = _("¡Somos tortolitos!");
const u8 gText_MatchCallYoungCouple_LoisAndHal_Intro2[] = _("¡Tortolitos para siempre!");

const u8 gText_MatchCallPkmnTrainer_Wally_Strategy[] = _("Lo damos todo.");
const u8 gText_MatchCallPkmnTrainer_Wally_Pokemon[] = _("El primer POKéMON que capturé.");
const u8 gText_MatchCallPkmnTrainer_Wally_Intro1[] = _("Los POKéMON y yo nos hemos");
const u8 gText_MatchCallPkmnTrainer_Wally_Intro2[] = _("hecho más fuertes juntos.");

const u8 gText_MatchCallRockinWhiz_Roxanne_Strategy[] = _("Ataque de poder tipo ROCA.");
const u8 gText_MatchCallRockinWhiz_Roxanne_Pokemon[] = _("Prefiero POKéMON duros como rocas.");
const u8 gText_MatchCallRockinWhiz_Roxanne_Intro1[] = _("Un LÍDER de un gran GIMNASIO");
const u8 gText_MatchCallRockinWhiz_Roxanne_Intro2[] = _("tiene mucha responsabilidad.");

const u8 gText_MatchCallTheBigHit_Brawly_Strategy[] = _("¡Acción física directa!");
const u8 gText_MatchCallTheBigHit_Brawly_Pokemon[] = _("¡Los POKéMON LUCHA mandan!");
const u8 gText_MatchCallTheBigHit_Brawly_Intro1[] = _("¡El mundo me espera como la");
const u8 gText_MatchCallTheBigHit_Brawly_Intro2[] = _("próxima gran ola!");

const u8 gText_MatchCallSwellShock_Wattson_Strategy[] = _("Elijo electrizar.");
const u8 gText_MatchCallSwellShock_Wattson_Pokemon[] = _("¡Siente la descarga eléctrica!");
const u8 gText_MatchCallSwellShock_Wattson_Intro1[] = _("Nunca se debe tirar una");
const u8 gText_MatchCallSwellShock_Wattson_Intro2[] = _("cerilla. Ni yo debo hacerlo.");

const u8 gText_MatchCallPassionBurn_Flannery_Strategy[] = _("Combatir con agresividad.");
const u8 gText_MatchCallPassionBurn_Flannery_Pokemon[] = _("¡Arde de pasión!");
const u8 gText_MatchCallPassionBurn_Flannery_Intro1[] = _("¡Elimina del todo la fatiga");
const u8 gText_MatchCallPassionBurn_Flannery_Intro2[] = _("diaria en aguas termales!");

const u8 gText_MatchCallReliableOne_Dad_Strategy[] = _("Adapto mi estilo con flexibilidad.");
const u8 gText_MatchCallReliableOne_Dad_Pokemon[] = _("Criados de forma equilibrada.");
const u8 gText_MatchCallReliableOne_Dad_Intro1[] = _("Camino 30 minutos desde casa");
const u8 gText_MatchCallReliableOne_Dad_Intro2[] = _("hasta aquí cada día.");

const u8 gText_MatchCallSkyTamer_Winona_Strategy[] = _("Aprovecho la velocidad.");
const u8 gText_MatchCallSkyTamer_Winona_Pokemon[] = _("Elegantes bailarines del cielo.");
const u8 gText_MatchCallSkyTamer_Winona_Intro1[] = _("Lo máximo sería vivir en");
const u8 gText_MatchCallSkyTamer_Winona_Intro2[] = _("armonía con la naturaleza.");

const u8 gText_MatchCallMysticDuo_TateAndLiza_Strategy[] = _("Combatimos en cooperación.");
const u8 gText_MatchCallMysticDuo_TateAndLiza_Pokemon[] = _("POKéMON siempre amistosos.");
const u8 gText_MatchCallMysticDuo_TateAndLiza_Intro1[] = _("¡Papá tiene problemas para");
const u8 gText_MatchCallMysticDuo_TateAndLiza_Intro2[] = _("distinguirnos!");

const u8 gText_MatchCallDandyCharm_Juan_Strategy[] = _("Uso un espléndido poder del agua.");
const u8 gText_MatchCallDandyCharm_Juan_Pokemon[] = _("¡POKéMON de elegancia!");
const u8 gText_MatchCallDandyCharm_Juan_Intro1[] = _("¡La adulación de bellas damas");
const u8 gText_MatchCallDandyCharm_Juan_Intro2[] = _("me llena de energía!");

const u8 gText_MatchCallEliteFour_Sidney_Strategy[] = _("¡Ofensiva sobre defensa!");
const u8 gText_MatchCallEliteFour_Sidney_Pokemon[] = _("Las bellezas del lado SINIESTRO.");
const u8 gText_MatchCallEliteFour_Sidney_Intro1[] = _("Dijeron que era un gamberro, pero");
const u8 gText_MatchCallEliteFour_Sidney_Intro2[] = _("¡soy del ALTO MANDO!");

const u8 gText_MatchCallEliteFour_Phoebe_Strategy[] = _("Confundir y desconcertar.");
const u8 gText_MatchCallEliteFour_Phoebe_Pokemon[] = _("No hay nada definitivo.");
const u8 gText_MatchCallEliteFour_Phoebe_Intro1[] = _("Me pregunto cómo estará mi");
const u8 gText_MatchCallEliteFour_Phoebe_Intro2[] = _("abuela en el MT. PYRE.");

const u8 gText_MatchCallEliteFour_Glacia_Strategy[] = _("Uso objetos como ayuda.");
const u8 gText_MatchCallEliteFour_Glacia_Pokemon[] = _("¡Pasión ardiente en el frío!");
const u8 gText_MatchCallEliteFour_Glacia_Intro1[] = _("El tipo HIELO se entrena mejor");
const u8 gText_MatchCallEliteFour_Glacia_Intro2[] = _("en esta tierra cálida.");

const u8 gText_MatchCallEliteFour_Drake_Strategy[] = _("Aprovecha grandes habilidades.");
const u8 gText_MatchCallEliteFour_Drake_Pokemon[] = _("¡El poder puro de los DRAGONES!");
const u8 gText_MatchCallEliteFour_Drake_Intro1[] = _("Me dedico a los POKéMON que");
const u8 gText_MatchCallEliteFour_Drake_Intro2[] = _("me salvaron.");

const u8 gText_MatchCallChampion_Wallace_Strategy[] = _("Dignidad y respeto.");
const u8 gText_MatchCallChampion_Wallace_Pokemon[] = _("Prefiero POKéMON con gracia.");
const u8 gText_MatchCallChampion_Wallace_Intro1[] = _("Represento la belleza y");
const u8 gText_MatchCallChampion_Wallace_Intro2[] = _("la inteligencia.");
#endif

#if IS_HNS
// Check page disabled for HnS trainers — table left empty.
// To re-enable: add MCFLAVOR entries here and set HasCheckPage_Trainer to TRUE.
const u8 *const gMatchCallFlavorTexts[REMATCH_TABLE_ENTRIES][CHECK_PAGE_ENTRY_COUNT] = {0};
#else
const u8 *const gMatchCallFlavorTexts[REMATCH_TABLE_ENTRIES][CHECK_PAGE_ENTRY_COUNT] =
{
    [REMATCH_ROSE] = MCFLAVOR(AromaLady_Rose),
    [REMATCH_ANDRES] = MCFLAVOR(RuinManiac_Andres),
    [REMATCH_DUSTY] = MCFLAVOR(RuinManiac_Dusty),
    [REMATCH_LOLA] = MCFLAVOR(Tuber_Lola),
    [REMATCH_RICKY] = MCFLAVOR(Tuber_Ricky),
    [REMATCH_LILA_AND_ROY] = MCFLAVOR(SisAndBro_LilaAndRoy),
    [REMATCH_CRISTIN] = MCFLAVOR(Cooltrainer_Cristin),
    [REMATCH_BROOKE] = MCFLAVOR(Cooltrainer_Brooke),
    [REMATCH_WILTON] = MCFLAVOR(Cooltrainer_Wilton),
    [REMATCH_VALERIE] = MCFLAVOR(HexManiac_Valerie),
    [REMATCH_CINDY] = MCFLAVOR(Lady_Cindy),
    [REMATCH_THALIA] = MCFLAVOR(Beauty_Thalia),
    [REMATCH_JESSICA] = MCFLAVOR(Beauty_Jessica),
    [REMATCH_WINSTON] = MCFLAVOR(RichBoy_Winston),
    [REMATCH_STEVE] = MCFLAVOR(PokeManiac_Steve),
    [REMATCH_TONY] = MCFLAVOR(Swimmer_Tony),
    [REMATCH_NOB] = MCFLAVOR(BlackBelt_Nob),
    [REMATCH_KOJI] = MCFLAVOR(BlackBelt_Koji),
    [REMATCH_FERNANDO] = MCFLAVOR(Guitarist_Fernando),
    [REMATCH_DALTON] = MCFLAVOR(Guitarist_Dalton),
    [REMATCH_BERNIE] = MCFLAVOR(Kindler_Bernie),
    [REMATCH_ETHAN] = MCFLAVOR(Camper_Ethan),
    [REMATCH_JOHN_AND_JAY] = MCFLAVOR(OldCouple_JohnAndJay),
    [REMATCH_JEFFREY] = MCFLAVOR(BugManiac_Jeffrey),
    [REMATCH_CAMERON] = MCFLAVOR(Psychic_Cameron),
    [REMATCH_JACKI] = MCFLAVOR(Psychic_Jacki),
    [REMATCH_WALTER] = MCFLAVOR(Gentleman_Walter),
    [REMATCH_KAREN] = MCFLAVOR(SchoolKid_Karen),
    [REMATCH_JERRY] = MCFLAVOR(SchoolKid_Jerry),
    [REMATCH_ANNA_AND_MEG] = MCFLAVOR(SrAndJr_AnnaAndMeg),
    [REMATCH_ISABEL] = MCFLAVOR(Pokefan_Isabel),
    [REMATCH_MIGUEL] = MCFLAVOR(Pokefan_Miguel),
    [REMATCH_TIMOTHY] = MCFLAVOR(Expert_Timothy),
    [REMATCH_SHELBY] = MCFLAVOR(Expert_Shelby),
    [REMATCH_CALVIN] = MCFLAVOR(Youngster_Calvin),
    [REMATCH_ELLIOT] = MCFLAVOR(Fisherman_Elliot),
    [REMATCH_ISAIAH] = MCFLAVOR(Triathlete_Isaiah),
    [REMATCH_MARIA] = MCFLAVOR(Triathlete_Maria),
    [REMATCH_ABIGAIL] = MCFLAVOR(Triathlete_Abigail),
    [REMATCH_DYLAN] = MCFLAVOR(Triathlete_Dylan),
    [REMATCH_KATELYN] = MCFLAVOR(Triathlete_Katelyn),
    [REMATCH_BENJAMIN] = MCFLAVOR(Triathlete_Benjamin),
    [REMATCH_PABLO] = MCFLAVOR(Triathlete_Pablo),
    [REMATCH_NICOLAS] = MCFLAVOR(DragonTamer_Nicolas),
    [REMATCH_ROBERT] = MCFLAVOR(BirdKeeper_Robert),
    [REMATCH_LAO] = MCFLAVOR(NinjaBoy_Lao),
    [REMATCH_CYNDY] = MCFLAVOR(BattleGirl_Cyndy),
    [REMATCH_MADELINE] = MCFLAVOR(ParasolLady_Madeline),
    [REMATCH_JENNY] = MCFLAVOR(Swimmer_Jenny),
    [REMATCH_DIANA] = MCFLAVOR(Picnicker_Diana),
    [REMATCH_AMY_AND_LIV] = MCFLAVOR(Twins_AmyAndLiv),
    [REMATCH_ERNEST] = MCFLAVOR(Sailor_Ernest),
    [REMATCH_CORY] = MCFLAVOR(Sailor_Cory),
    [REMATCH_EDWIN] = MCFLAVOR(Collector_Edwin),
    [REMATCH_LYDIA] = MCFLAVOR(PkmnBreeder_Lydia),
    [REMATCH_ISAAC] = MCFLAVOR(PkmnBreeder_Isaac),
    [REMATCH_GABRIELLE] = MCFLAVOR(PkmnBreeder_Gabrielle),
    [REMATCH_CATHERINE] = MCFLAVOR(PkmnRanger_Catherine),
    [REMATCH_JACKSON] = MCFLAVOR(PkmnRanger_Jackson),
    [REMATCH_HALEY] = MCFLAVOR(Lass_Haley),
    [REMATCH_JAMES] = MCFLAVOR(BugCatcher_James),
    [REMATCH_TRENT] = MCFLAVOR(Hiker_Trent),
    [REMATCH_SAWYER] = MCFLAVOR(Hiker_Sawyer),
    [REMATCH_KIRA_AND_DAN] = MCFLAVOR(YoungCouple_LoisAndHal),
    [REMATCH_WALLY_VR] = MCFLAVOR(PkmnTrainer_Wally),
    [REMATCH_ROXANNE] = MCFLAVOR(RockinWhiz_Roxanne),
    [REMATCH_BRAWLY] = MCFLAVOR(TheBigHit_Brawly),
    [REMATCH_WATTSON] = MCFLAVOR(SwellShock_Wattson),
    [REMATCH_FLANNERY] = MCFLAVOR(PassionBurn_Flannery),
    [REMATCH_NORMAN] = MCFLAVOR(ReliableOne_Dad),
    [REMATCH_WINONA] = MCFLAVOR(SkyTamer_Winona),
    [REMATCH_TATE_AND_LIZA] = MCFLAVOR(MysticDuo_TateAndLiza),
    [REMATCH_JUAN] = MCFLAVOR(DandyCharm_Juan),
    [REMATCH_SIDNEY] = MCFLAVOR(EliteFour_Sidney),
    [REMATCH_PHOEBE] = MCFLAVOR(EliteFour_Phoebe),
    [REMATCH_GLACIA] = MCFLAVOR(EliteFour_Glacia),
    [REMATCH_DRAKE] = MCFLAVOR(EliteFour_Drake),
    [REMATCH_WALLACE] = MCFLAVOR(Champion_Wallace),
};
#endif
