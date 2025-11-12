#include "DisplayManager.hpp"
#include <iostream>

DisplayManager::DisplayManager() {
    setStartingScene();
    setCustomerOne();
    setCustomerTwo();
    setCustomerThree();
    setCustomerFour();
    setCustomerFive();
    setCustomerSix();
}

void DisplayManager::setStartingScene() {
    m_szStartingScene = R"(                 
                 .                             .
                //                             \\
               //                               \\
              //                                 \\
             //                _._                \\
          .---.              .//|\\.              .---.
________ / .-. \_________..-~ _.-._ ~-..________ / .-. \_________
         \ ~-~ /   /H-     `-=.___.=-'     -H\   \ ~-~ /    
           ~~~    / H          [H]          H \    ~~~      0
                 / _H_         _H_         _H_ \           /\#
                   UUU         UUU         UUU             /\

    )"
R"(
        ──────────────────────────────────────────────
          SKYBORNE EXPRESS – DOCK 7, MIDNIGHT SHIFT
        ──────────────────────────────────────────────

    Engines purr in the dark. Rain taps Morse on the hull.
    Six bookings tonight. All flagged "priority." None look honest.

    [Radio crackle]

    DISPATCH: "Captain, wrap by 0100. Double-check every manifest.
    HQ's twitchy."

    You flip your clipboard open.

    If something goes wrong tonight, your signature’s on it.
)";
}

void DisplayManager::setCustomerOne() {
    m_szCustomerOne = R"(                 
                 .                             .
                //                             \\
               //                               \\
              //                                 \\
             //                _._                \\
          .---.              .//|\\.              .---.
________ / .-. \_________..-~ _.-._ ~-..________ / .-. \_________
         \ ~-~ /   /H-     `-=.___.=-'     -H\   \ ~-~ /                 
           ~~~    / H          [H]          H \    ~~~      0   O    O  \O*
                 / _H_         _H_         _H_ \           /\   \\[]//   ()*
                   UUU         UUU         UUU             /\   /\  /\   /\*
    )"
R"(
──────────────────────────────────────────────
 [January 17 – 00:12, The Lord Arrives]
──────────────────────────────────────────────

Perfume hits before the echo of his boots.

Lord Varric, velvet and gold, gestures lazily to a crate:
"Clockwork Champagne. Heirloom. Handle it like gossip: gently."

He leans in, smile too polished.

Lord Varric: "Between glass and trust, Captain, one always breaks.
Guess which I insure."

The crate ticks. Subtle. Wrong.

[You log: House Altura | Item: Clockwork Champagne | Qty: 1 | Cost: 300]
)";
}

void DisplayManager::setCustomerTwo() {
    m_szCustomerTwo = R"(                 
                 .                             .
                //                             \\
               //                               \\
              //                                 \\
             //                _._                \\
          .---.              .//|\\.              .---.
________ / .-. \_________..-~ _.-._ ~-..________ / .-. \_________
         \ ~-~ /   /H-     `-=.___.=-'     -H\   \ ~-~ /                 
           ~~~    / H          [H]          H \    ~~~      0      0
                 / _H_         _H_         _H_ \           /\     //)  \|/
                   UUU         UUU         UUU             /\   _ _ /\  #
    )"
R"(
──────────────────────────────────────────────
 [January 17 – 00:47, The Professor Arrives]
──────────────────────────────────────────────

A storm in a lab coat skids inside, trailing papers.

Professor Elmwick: "Good vessel. Questionable humidity. Anyway—"
He slaps a hand on a glass cylinder of swirling blue light.
"Do not drop it. Do not insult it. Do not *concentrate* on it."

The vapor pulses when he says "concentrate."

Professor Elmwick: "If it phases through anything important,
log it as peer review."

He chases a formula sheet back into the rain.

[You log: Professor Elmwick | Item: Cognitive Phase Cylinder | Qty: 1 | Cost: 450]
)";
}

void DisplayManager::setCustomerThree() {
    m_szCustomerThree = R"(                 
                 .                             .
                //                             \\
               //                               \\
              //                                 \\
             //                _._                \\
          .---.              .//|\\.              .---.
________ / .-. \_________..-~ _.-._ ~-..________ / .-. \_________
         \ ~-~ /   /H-     `-=.___.=-'     -H\   \ ~-~ /                 
           ~~~    / H          [H]          H \    ~~~      0
                 / _H_         _H_         _H_ \        O /|\ 
                   UUU         UUU         UUU           / \
    )"
R"(
──────────────────────────────────────────────
 [January 17 – 01:03, The Mechanic Arrives]
──────────────────────────────────────────────

Mira Dross walks like she owns gravity.

Mira: "Engine valves. Eight units. Fifty each. They'll outlive you."

The crate’s heavy, clean, correctly stenciled.

Mira: "Saboteurs love tidy labels and boring numbers.
When it looks perfect, squint harder."

She holds your stare a beat too long, then nods.

[You log: Mira Dross | Item: Engine Valves | Qty: 8 | Cost: 400]
)";
}

void DisplayManager::setCustomerFour() {
    m_szCustomerFour = R"(                 
                 .                             .
                //                             \\
               //                               \\
              //                                 \\
             //                _._                \\
          .---.              .//|\\.              .---.
________ / .-. \_________..-~ _.-._ ~-..________ / .-. \_________
         \ ~-~ /   /H-     `-=.___.=-'     -H\   \ ~-~ /                 
           ~~~    / H          [H]          H \    ~~~
                 / _H_         _H_         _H_ \                o>
                   UUU         UUU         UUU                 /| 
                                                               / \
    )"
R"(
──────────────────────────────────────────────
 [January 17 – 01:14, The Skyrunner Arrives]
──────────────────────────────────────────────

Lyra Skyrunner drops a sealed pouch on your crate.

Lyra: "Encrypted mail. One bag. Sixty credits.
Mostly route chatter. Mostly."

A faint harmonic hum rises, brushes your teeth, fades.

Lyra: "They sing when a manifest lies.
One of your nobles didn’t like his description line."

She taps your clipboard and walks off, feathers dripping.

[You log: Lyra Skyrunner | Item: Encrypted Mail Pouch | Qty: 1 | Cost: 60]
)";
}

void DisplayManager::setCustomerFive() {
    m_szCustomerFive = R"(                 
                 .                             .
                //                             \\
               //                               \\
              //                                 \\
             //                _._                \\
          .---.              .//|\\.              .---.
________ / .-. \_________..-~ _.-._ ~-..________ / .-. \_________
         \ ~-~ /   /H-     `-=.___.=-'     -H\   \ ~-~ /                 
           ~~~    / H          [H]          H \    ~~~
                 / _H_         _H_         _H_ \ 
                   UUU         UUU         UUU             [] 
                                                            ||
                                                           /__\
    )"
R"(
──────────────────────────────────────────────
 [January 17 – 01:26, The Mortician Arrives]
──────────────────────────────────────────────

A man in a rain-slick black coat sets down a small urn.

Mortician: "Gray & Sons. Ceremonial ash urn. One unit. Seventy-five."

The paperwork is flawless. Too flawless.

Mortician: "We do not mislabel, Captain.
Others… project."

He inclines his head and leaves like a closing lid.

[You log: Gray & Sons | Item: Ceremonial Ash Urn | Qty: 1 | Cost: 75]
)";
}

void DisplayManager::setCustomerSix() {
    m_szCustomerSix = R"(                 
                 .                             .
                //                             \\
               //                               \\
              //                                 \\
             //                _._                \\
          .---.              .//|\\.              .---.
________ / .-. \_________..-~ _.-._ ~-..________ / .-. \_________
         \ ~-~ /   /H-     `-=.___.=-'     -H\   \ ~-~ /                 
           ~~~    / H          [H]          H \    ~~~
                 / _H_         _H_         _H_ \ 
                   UUU         UUU         UUU          ____   ____
                                                        |  |___|  |
                                                        |__|   |__|
    )"
R"(
──────────────────────────────────────────────
 [January 17 – 01:39, The Alchemist Arrives]
──────────────────────────────────────────────

Dr. Caldera arrives last, dry in a drowning night.

Two drums roll beside him:
"CLEANING SOLVENT – INDUSTRIAL – NON-REACTIVE."

Dr. Caldera: "Two units. Six hundred. Very... efficient."

No slosh. No scent. Too quiet.

Dr. Caldera: "Some people undercharge for what’s real.
Some call that misdeclared. I call it… leverage."

The mail pouch at your hip spikes, then settles.

[You log: Dr. Caldera | Item: Cleaning Solvent | Qty: 2 | Cost: 600]
)";
}
