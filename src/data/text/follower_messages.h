extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];
extern const u8 EventScript_FollowerLookUp[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("{STR_VAR_1} te ha dado golpecitos en\nla tripa.");
static const u8 sHappyMsg01[] = _("{STR_VAR_1} está contento, pero le da\nvergüenza.");
static const u8 sHappyMsg02[] = _("{STR_VAR_1} te sigue muy contento.");
static const u8 sHappyMsg03[] = _("{STR_VAR_1} está tranquilo.");
static const u8 sHappyMsg04[] = _("{STR_VAR_1} parece feliz cuando te\nsigue.");
static const u8 sHappyMsg05[] = _("{STR_VAR_1} rebosa salud.");
static const u8 sHappyMsg06[] = _("{STR_VAR_1} parece muy contento.");
static const u8 sHappyMsg07[] = _("{STR_VAR_1} se ha esforzado un poco\nmás.");
static const u8 sHappyMsg08[] = _("{STR_VAR_1} está olisqueando a su\nalrededor.");
static const u8 sHappyMsg09[] = _("¡{STR_VAR_1} no cabe en sí de gozo!");
static const u8 sHappyMsg10[] = _("A {STR_VAR_1} le queda energía para\nrato.");
static const u8 sHappyMsg11[] = _("Está olisqueando el humo.");
static const u8 sHappyMsg12[] = _("{STR_VAR_1} te está dando golpecitos\nen la tripa.");
static const u8 sHappyMsg13[] = _("Se está repantingando.");
static const u8 sHappyMsg14[] = _("Se diría que {STR_VAR_1} quiere ir\ndelante.");
static const u8 sHappyMsg15[] = _("{STR_VAR_1} hace lo que puede para\nseguirte el ritmo.");
static const u8 sHappyMsg16[] = _("{STR_VAR_1} te hace mimos, con la cara\nrebosante de alegría.");
static const u8 sHappyMsg17[] = _("¡{STR_VAR_1} está lleno de vida!");
static const u8 sHappyMsg18[] = _("¡{STR_VAR_1} está radiante!");
static const u8 sHappyMsg19[] = _("¡{STR_VAR_1} está tan contento que no\npuede estarse quieto!");
static const u8 sHappyMsg20[] = _("{STR_VAR_1} ha asentido despacio.");
static const u8 sHappyMsg21[] = _("{STR_VAR_1} se siente muy motivado.");
static const u8 sHappyMsg22[] = _("{STR_VAR_1} escucha con interés un\nruido.");
static const u8 sHappyMsg23[] = _("{STR_VAR_1} parece muy interesado.");
static const u8 sHappyMsg24[] = _("Parece que {STR_VAR_1} será capaz de\nseguirte.");
static const u8 sHappyMsg25[] = _("{STR_VAR_1} saluda con entusiasmo.");
static const u8 sHappyMsg26[] = _("{STR_VAR_1} te mira con alegría y\nsonríe.");
static const u8 sHappyMsg27[] = _("Tu POKéMON está oliendo el aroma de\nlas flores.");
static const u8 sHappyMsg28[] = _("¡{STR_VAR_1} parece muy contento de\nverte!");
static const u8 sHappyMsg29[] = _("{STR_VAR_1} se ha girado y te ha\nsonreído.");
static const u8 sHappyMsg30[] = _("¡{STR_VAR_1} se ha acurrucado junto a\nti!");
// Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("Tu POKéMON parece contento con el\nbuen tiempo.");
static const u8 sHappyMsg32[] = _("¡{STR_VAR_1} está muy sereno y seguro\nde sí mismo!");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31}, {sHappyMsg32},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("{STR_VAR_1} está picoteando el suelo.");
static const u8 sNeutralMsg01[] = _("{STR_VAR_1} está montando guardia.");
static const u8 sNeutralMsg02[] = _("{STR_VAR_1} está mirando a la nada.");
static const u8 sNeutralMsg03[] = _("{STR_VAR_1} está incansable.");
static const u8 sNeutralMsg04[] = _("Ha bostezado enérgicamente.");
static const u8 sNeutralMsg05[] = _("Está mirando a su alrededor y no puede\nparar.");
static const u8 sNeutralMsg06[] = _("{STR_VAR_1} se ha dado la vuelta y te\nha sonreído.");
static const u8 sNeutralMsg07[] = _("{STR_VAR_1} inspecciona a su\nalrededor con interés.");
static const u8 sNeutralMsg08[] = _("{STR_VAR_1} ha lanzado un grito de\nguerra.");
static const u8 sNeutralMsg09[] = _("{STR_VAR_1} ha bailado con mucho\nestilo.");
static const u8 sNeutralMsg10[] = _("{STR_VAR_1} tiene muchas ganas.");
static const u8 sNeutralMsg11[] = _("{STR_VAR_1} mira fijamente a lo lejos.");
static const u8 sNeutralMsg12[] = _("{STR_VAR_1} observa a su alrededor.");
static const u8 sNeutralMsg13[] = _("{STR_VAR_1} ha lanzado un aullido a la\nlejanía.");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{STR_VAR_1} está mareado.");
static const u8 sSadMsg01[] = _("¡{STR_VAR_1} te está pisando los pies!");
static const u8 sSadMsg02[] = _("Parece que {STR_VAR_1} está un poco\ncansado.");
// Conditional messages begin, index 3
static const u8 sSadMsg03[] = _("{STR_VAR_1} no está contento.");
static const u8 sSadMsg04[] = _("¡{STR_VAR_1} se va a caer!");
static const u8 sSadMsg05[] = _("¡{STR_VAR_1} está a punto de caerse!");
static const u8 sSadMsg06[] = _("{STR_VAR_1} hace todo lo que puede\npara seguirte.");
static const u8 sSadMsg07[] = _("{STR_VAR_1} está nervioso.");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06}, {sSadMsg07},
};

// Unconditional upset messages
static const u8 sUpsetMsg00[] = _("{STR_VAR_1} pone cara de no estar muy\ncontento.");
static const u8 sUpsetMsg01[] = _("{STR_VAR_1} pone cara de disgusto.");
static const u8 sUpsetMsg02[] = _("…Parece que tu POKéMON tiene un poco\nde frío.");
// Conditional messages, index 3
static const u8 sUpsetMsg03[] = _("{STR_VAR_1} se está refugiando en la\nhierba alta.");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("{STR_VAR_1} ha soltado un gruñido.");
static const u8 sAngryMsg01[] = _("{STR_VAR_1} está gimiendo con cara de\nenfado.");
static const u8 sAngryMsg02[] = _("Parece que {STR_VAR_1} está enfadado\npor algo.");
static const u8 sAngryMsg03[] = _("Tu POKéMON se ha dado la vuelta con\ncara desafiante.");
static const u8 sAngryMsg04[] = _("{STR_VAR_1} ha gritado.");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("{STR_VAR_1} mira fijamente hacia\nabajo.");
static const u8 sPensiveMsg01[] = _("{STR_VAR_1} está examinando la zona.");
static const u8 sPensiveMsg02[] = _("{STR_VAR_1} está mirando hacia abajo.");
static const u8 sPensiveMsg03[] = _("{STR_VAR_1} está luchando contra el\ncansancio.");
static const u8 sPensiveMsg04[] = _("Parece que {STR_VAR_1} anda de un\nlado a otro.");
static const u8 sPensiveMsg05[] = _("{STR_VAR_1} mira a su alrededor con\naire distraído.");
static const u8 sPensiveMsg06[] = _("¡{STR_VAR_1} ha bostezado con fuerza!");
static const u8 sPensiveMsg07[] = _("{STR_VAR_1} está relajándose\ntranquilamente.");
static const u8 sPensiveMsg08[] = _("{STR_VAR_1} te mira fijamente a la\ncara.");
static const u8 sPensiveMsg09[] = _("{STR_VAR_1} te mira a la cara con\natención.");
static const u8 sPensiveMsg10[] = _("{STR_VAR_1} te está mirando\nfijamente.");
static const u8 sPensiveMsg11[] = _("{STR_VAR_1} mira hacia las\nprofundidades.");
static const u8 sPensiveMsg12[] = _("{STR_VAR_1} olisquea el suelo.");
static const u8 sPensiveMsg13[] = _("Tu POKéMON mira fijamente a la nada.");
static const u8 sPensiveMsg14[] = _("{STR_VAR_1} ha centrado su mirada\nlarga y fijamente.");
static const u8 sPensiveMsg15[] = _("{STR_VAR_1} se está concentrando.");
static const u8 sPensiveMsg16[] = _("{STR_VAR_1} se ha vuelto hacia ti y se\nbalancea suavemente.");
static const u8 sPensiveMsg17[] = _("{STR_VAR_1} parece algo nervioso…");
static const u8 sPensiveMsg18[] = _("{STR_VAR_1} está mirando tus huellas.");
static const u8 sPensiveMsg19[] = _("{STR_VAR_1} te mira directamente a los\nojos.");

const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("¡{STR_VAR_1} se pega a tus piernas!");
static const u8 sLoveMsg01[] = _("¡A {STR_VAR_1} se le sonrojan las\nmejillas!");
static const u8 sLoveMsg02[] = _("¡Hala! ¡{STR_VAR_1} te ha abrazado de\nrepente!");
static const u8 sLoveMsg03[] = _("¡Hala! ¡A {STR_VAR_1} le han entrado\nganas de jugar!");
static const u8 sLoveMsg04[] = _("¡{STR_VAR_1} se frota contra tus\npiernas!");
static const u8 sLoveMsg05[] = _("{STR_VAR_1} se ha sonrojado.");
static const u8 sLoveMsg06[] = _("¡Ah! ¡{STR_VAR_1} te hace mimos!");
static const u8 sLoveMsg07[] = _("{STR_VAR_1} te mira esperando que lo\nacaricies.");
static const u8 sLoveMsg08[] = _("{STR_VAR_1} se ha acercado a ti.");
static const u8 sLoveMsg09[] = _("{STR_VAR_1} se pega a tus piernas.");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("¡{STR_VAR_1} ha estado a punto de\ntropezarse!");
static const u8 sSurpriseMsg01[] = _("¡{STR_VAR_1} se ha chocado contigo!");
static const u8 sSurpriseMsg02[] = _("Parece que {STR_VAR_1} aún no se ha\nacostumbrado a su nombre.");
static const u8 sSurpriseMsg03[] = _("{STR_VAR_1} está mirando hacia abajo.");
static const u8 sSurpriseMsg04[] = _("Se ha tropezado y ha estado a punto\nde caerse.");
static const u8 sSurpriseMsg05[] = _("{STR_VAR_1} ha notado algo raro y ha\nsoltado un gruñido.");
static const u8 sSurpriseMsg06[] = _("¡{STR_VAR_1} parece renovado!");
static const u8 sSurpriseMsg07[] = _("{STR_VAR_1} se ha girado de repente y\nha lanzado un gruñido.");
static const u8 sSurpriseMsg08[] = _("¡{STR_VAR_1} se ha girado de repente!");
static const u8 sSurpriseMsg09[] = _("Se ha sorprendido al dirigirle la\npalabra.");
static const u8 sSurpriseMsg10[] = _("¡Snif, snif! ¡Algo huele de maravilla!");
static const u8 sSurpriseMsg11[] = _("{STR_VAR_1} se siente renovado.");
static const u8 sSurpriseMsg12[] = _("{STR_VAR_1} está tambaleándose y\nparece que se va a caer.");
static const u8 sSurpriseMsg13[] = _("{STR_VAR_1} está a punto de caerse.");
static const u8 sSurpriseMsg14[] = _("{STR_VAR_1} camina con cuidado.");
static const u8 sSurpriseMsg15[] = _("{STR_VAR_1} está en tensión.");
static const u8 sSurpriseMsg16[] = _("{STR_VAR_1} se ha sorprendido con un\nolor peculiar.");
static const u8 sSurpriseMsg17[] = _("¡{STR_VAR_1} se ha asustado y se ha\nabrazado a ti!");
static const u8 sSurpriseMsg18[] = _("{STR_VAR_1} está notando algo\nextraño...");
static const u8 sSurpriseMsg19[] = _("{STR_VAR_1} está en tensión.");
// Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("¡A {STR_VAR_1} parece sorprenderle\nmucho que llueva!");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("Está buscando algo con insistencia.");
static const u8 sCuriousMsg01[] = _("No estaba mirando y se ha chocado.");
static const u8 sCuriousMsg02[] = _("Snif... ¿Habrá algo extraño cerca?");
static const u8 sCuriousMsg03[] = _("{STR_VAR_1} se entretiene haciendo\nrodar guijarros.");
static const u8 sCuriousMsg04[] = _("{STR_VAR_1} está buscando algo a su\nalrededor frenéticamente.");
static const u8 sCuriousMsg05[] = _("{STR_VAR_1} te está olfateando.");
static const u8 sCuriousMsg06[] = _("Da la impresión de que {STR_VAR_1}\nestá un poco perdido.");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("{STR_VAR_1} se mueve con aire\ndespreocupado.");
static const u8 sMusicMsg01[] = _("¡{STR_VAR_1} está rebosante de\nenergía!");
static const u8 sMusicMsg02[] = _("¡Hala! ¡{STR_VAR_1} se ha puesto a\nbailar de alegría!");
static const u8 sMusicMsg03[] = _("{STR_VAR_1} te sigue todo contento.");
static const u8 sMusicMsg04[] = _("Parece que {STR_VAR_1} quiere jugar\ncontigo.");
static const u8 sMusicMsg05[] = _("{STR_VAR_1} va dando saltitos de\nalegría.");
static const u8 sMusicMsg06[] = _("{STR_VAR_1} está cantando y\ntarareando.");
static const u8 sMusicMsg07[] = _("{STR_VAR_1} picotea junto a tus pies.");
static const u8 sMusicMsg08[] = _("{STR_VAR_1} se da la vuelta y te mira.");
static const u8 sMusicMsg09[] = _("{STR_VAR_1} intenta llamar la atención\ncon todas sus ganas.");
static const u8 sMusicMsg10[] = _("¡Eh! {STR_VAR_1} se ha puesto a bailar\nde alegría.");
static const u8 sMusicMsg11[] = _("¡{STR_VAR_1} está animado!");
static const u8 sMusicMsg12[] = _("{STR_VAR_1} ha saltado con aire\ndespreocupado.");
static const u8 sMusicMsg13[] = _("Parece que hay un olor que le trae\nbuenos recuerdos.");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("{STR_VAR_1} está encantado con la\nlluvia.");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{STR_VAR_1} tiembla por los efectos\ndel veneno.");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};
