const u8 gEasyChatWord_Meet[] = _("ENFADADO");
const u8 gEasyChatWord_Play[] = _("ENTRETENIDO");
const u8 gEasyChatWord_Hurried[] = _("VELOCIDAD");
const u8 gEasyChatWord_Goes[] = _("ENTRETENIDA");
const u8 gEasyChatWord_Giddy[] = _("MAREADO");
const u8 gEasyChatWord_Happy[] = _("MAREADA");
const u8 gEasyChatWord_Happiness[] = _("EMOCIONADA");
const u8 gEasyChatWord_Excite[] = _("EMOCIONADO");
const u8 gEasyChatWord_Important[] = _("CANSADA");
const u8 gEasyChatWord_Funny[] = _("DÉBIL");
const u8 gEasyChatWord_Got[] = _("HOGAREÑO");
const u8 gEasyChatWord_GoHome[] = _("HOGAREÑA");
const u8 gEasyChatWord_Disappointed[] = _("DECEPCIONADO");
const u8 gEasyChatWord_Disappoints[] = _("DECEPCIONADA");
const u8 gEasyChatWord_Sad[] = _("TRISTE");
const u8 gEasyChatWord_Try[] = _("HARTO");
const u8 gEasyChatWord_Tries[] = _("HARTA");
const u8 gEasyChatWord_Hears[] = _("ATENTO");
const u8 gEasyChatWord_Think[] = _("ATENTA");
const u8 gEasyChatWord_Hear[] = _("ARISCO");
const u8 gEasyChatWord_Wants[] = _("ARISCA");
const u8 gEasyChatWord_Misheard[] = _("HAMBRIENTO");
const u8 gEasyChatWord_Dislike[] = _("HAMBRIENTA");
const u8 gEasyChatWord_Angry[] = _("MOSQUEADO");
const u8 gEasyChatWord_Anger[] = _("MOSQUEADA");
const u8 gEasyChatWord_Scary[] = _("ALUCINADO");
const u8 gEasyChatWord_Lonesome[] = _("ALUCINADA");
const u8 gEasyChatWord_Disappoint[] = _("SOLO");
const u8 gEasyChatWord_Joy[] = _("SOLA");
const u8 gEasyChatWord_Gets[] = _("COBARDICA");
const u8 gEasyChatWord_Never[] = _("MALDITA");
const u8 gEasyChatWord_Darn[] = _("PREPARADO");
const u8 gEasyChatWord_Downcast[] = _("CANSADO");
const u8 gEasyChatWord_Incredible[] = _("INCREÍBLE");
const u8 gEasyChatWord_Likes[] = _("SATISFECHO");
const u8 gEasyChatWord_Dislikes[] = _("SATISFECHA");
const u8 gEasyChatWord_Boring[] = _("ABURRIDO");
const u8 gEasyChatWord_Care[] = _("ABURRIDA");
const u8 gEasyChatWord_Cares[] = _("ENAMORADO");
const u8 gEasyChatWord_AllRight[] = _("ENAMORADA");
const u8 gEasyChatWord_Adore[] = _("LOCO");
const u8 gEasyChatWord_Disaster[] = _("LOCA");
const u8 gEasyChatWord_Enjoy[] = _("SIMPÁTICO");
const u8 gEasyChatWord_Enjoys[] = _("SIMPÁTICA");
const u8 gEasyChatWord_Eat[] = _("ATONTADO");
const u8 gEasyChatWord_Lacking[] = _("ATONTADA");
const u8 gEasyChatWord_Bad[] = _("MALO");
const u8 gEasyChatWord_Hard[] = _("MALA");
const u8 gEasyChatWord_Terrible[] = _("TERRIBLE");
const u8 gEasyChatWord_Should[] = _("ANTIPÁTICO");
const u8 gEasyChatWord_Nice[] = _("ANTIPÁTICA");
const u8 gEasyChatWord_Drink[] = _("SEDIENTO");
const u8 gEasyChatWord_Surprise[] = _("SEDIENTA");
const u8 gEasyChatWord_Fear[] = _("MIEDOSO");
const u8 gEasyChatWord_Want[] = _("MIEDOSA");
const u8 gEasyChatWord_Wait[] = _("VISCOSO");
const u8 gEasyChatWord_Satisfied[] = _("CONTENTO");
const u8 gEasyChatWord_See[] = _("CONTENTA");
const u8 gEasyChatWord_Rare[] = _("RARO");
const u8 gEasyChatWord_Negative[] = _("RARA");
const u8 gEasyChatWord_Done[] = _("PELIGROSO");
const u8 gEasyChatWord_Danger[] = _("PELIGROSA");
const u8 gEasyChatWord_Defeated[] = _("AGOTADO");
const u8 gEasyChatWord_Beat[] = _("AGOTADA");
const u8 gEasyChatWord_Great[] = _("ROMÁNTICO");
const u8 gEasyChatWord_Romantic[] = _("ROMÁNTICA");
const u8 gEasyChatWord_Question[] = _("SOCIABLE");
const u8 gEasyChatWord_Understand[] = _("AGOBIADO");
const u8 gEasyChatWord_Understands[] = _("AGOBIADA");

const struct EasyChatWordInfo gEasyChatGroup_Feelings[] = {
    [EC_INDEX(EC_WORD_MEET)] =
    {
        .text = COMPOUND_STRING("ENFADADO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ADORE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLAY)] =
    {
        .text = COMPOUND_STRING("ENTRETENIDO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALL_RIGHT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HURRIED)] =
    {
        .text = COMPOUND_STRING("VELOCIDAD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANGER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOES)] =
    {
        .text = COMPOUND_STRING("ENTRETENIDA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANGRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIDDY)] =
    {
        .text = COMPOUND_STRING("MAREADO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BAD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPY)] =
    {
        .text = COMPOUND_STRING("MAREADA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPINESS)] =
    {
        .text = COMPOUND_STRING("EMOCIONADA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BORING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCITE)] =
    {
        .text = COMPOUND_STRING("EMOCIONADO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CARE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IMPORTANT)] =
    {
        .text = COMPOUND_STRING("CANSADA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CARES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FUNNY)] =
    {
        .text = COMPOUND_STRING("DÉBIL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DANGER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOT)] =
    {
        .text = COMPOUND_STRING("HOGAREÑO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DARN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO_HOME)] =
    {
        .text = COMPOUND_STRING("HOGAREÑA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEFEATED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPOINTED)] =
    {
        .text = COMPOUND_STRING("DECEPCIONADO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPOINT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPOINTS)] =
    {
        .text = COMPOUND_STRING("DECEPCIONADA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPOINTED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAD)] =
    {
        .text = COMPOUND_STRING("TRISTE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPOINTS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRY)] =
    {
        .text = COMPOUND_STRING("HARTO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISASTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRIES)] =
    {
        .text = COMPOUND_STRING("HARTA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISLIKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEARS)] =
    {
        .text = COMPOUND_STRING("ATENTO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISLIKES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINK)] =
    {
        .text = COMPOUND_STRING("ATENTA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEAR)] =
    {
        .text = COMPOUND_STRING("ARISCO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOWNCAST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WANTS)] =
    {
        .text = COMPOUND_STRING("ARISCA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DRINK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MISHEARD)] =
    {
        .text = COMPOUND_STRING("HAMBRIENTO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISLIKE)] =
    {
        .text = COMPOUND_STRING("HAMBRIENTA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENJOY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANGRY)] =
    {
        .text = COMPOUND_STRING("MOSQUEADO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENJOYS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANGER)] =
    {
        .text = COMPOUND_STRING("MOSQUEADA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCITE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SCARY)] =
    {
        .text = COMPOUND_STRING("ALUCINADO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LONESOME)] =
    {
        .text = COMPOUND_STRING("ALUCINADA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FUNNY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPOINT)] =
    {
        .text = COMPOUND_STRING("SOLO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GETS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JOY)] =
    {
        .text = COMPOUND_STRING("SOLA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIDDY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GETS)] =
    {
        .text = COMPOUND_STRING("COBARDICA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO_HOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEVER)] =
    {
        .text = COMPOUND_STRING("MALDITA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DARN)] =
    {
        .text = COMPOUND_STRING("PREPARADO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOWNCAST)] =
    {
        .text = COMPOUND_STRING("CANSADO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GREAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INCREDIBLE)] =
    {
        .text = COMPOUND_STRING("INCREÍBLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPINESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIKES)] =
    {
        .text = COMPOUND_STRING("SATISFECHO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISLIKES)] =
    {
        .text = COMPOUND_STRING("SATISFECHA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HARD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BORING)] =
    {
        .text = COMPOUND_STRING("ABURRIDO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CARE)] =
    {
        .text = COMPOUND_STRING("ABURRIDA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEARS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CARES)] =
    {
        .text = COMPOUND_STRING("ENAMORADO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HURRIED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALL_RIGHT)] =
    {
        .text = COMPOUND_STRING("ENAMORADA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IMPORTANT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ADORE)] =
    {
        .text = COMPOUND_STRING("LOCO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INCREDIBLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISASTER)] =
    {
        .text = COMPOUND_STRING("LOCA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_JOY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENJOY)] =
    {
        .text = COMPOUND_STRING("SIMPÁTICO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LACKING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENJOYS)] =
    {
        .text = COMPOUND_STRING("SIMPÁTICA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIKES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EAT)] =
    {
        .text = COMPOUND_STRING("ATONTADO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LONESOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LACKING)] =
    {
        .text = COMPOUND_STRING("ATONTADA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BAD)] =
    {
        .text = COMPOUND_STRING("MALO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISHEARD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HARD)] =
    {
        .text = COMPOUND_STRING("MALA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEGATIVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TERRIBLE)] =
    {
        .text = COMPOUND_STRING("TERRIBLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEVER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOULD)] =
    {
        .text = COMPOUND_STRING("ANTIPÁTICO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NICE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NICE)] =
    {
        .text = COMPOUND_STRING("ANTIPÁTICA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DRINK)] =
    {
        .text = COMPOUND_STRING("SEDIENTO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUESTION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SURPRISE)] =
    {
        .text = COMPOUND_STRING("SEDIENTA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RARE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FEAR)] =
    {
        .text = COMPOUND_STRING("MIEDOSO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROMANTIC),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WANT)] =
    {
        .text = COMPOUND_STRING("MIEDOSA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAIT)] =
    {
        .text = COMPOUND_STRING("VISCOSO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SATISFIED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SATISFIED)] =
    {
        .text = COMPOUND_STRING("CONTENTO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SCARY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEE)] =
    {
        .text = COMPOUND_STRING("CONTENTA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RARE)] =
    {
        .text = COMPOUND_STRING("RARO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOULD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEGATIVE)] =
    {
        .text = COMPOUND_STRING("RARA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SURPRISE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DONE)] =
    {
        .text = COMPOUND_STRING("PELIGROSO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TERRIBLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DANGER)] =
    {
        .text = COMPOUND_STRING("PELIGROSA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEFEATED)] =
    {
        .text = COMPOUND_STRING("AGOTADO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRIES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEAT)] =
    {
        .text = COMPOUND_STRING("AGOTADA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GREAT)] =
    {
        .text = COMPOUND_STRING("ROMÁNTICO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNDERSTAND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROMANTIC)] =
    {
        .text = COMPOUND_STRING("ROMÁNTICA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNDERSTANDS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUESTION)] =
    {
        .text = COMPOUND_STRING("SOCIABLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAIT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNDERSTAND)] =
    {
        .text = COMPOUND_STRING("AGOBIADO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNDERSTANDS)] =
    {
        .text = COMPOUND_STRING("AGOBIADA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANTS),
        .enabled = TRUE,
    },
};
