/*********************************************************************
File name: DisplayManager.cpp
Author: <Luke Lyons>(<ujw18>)
Date: 11/14/2025

Purpose:
    Implementation file for the DisplayManager class. Initializes
    all game scene text for the Airship Delivery System.
Command Parameters:
    N/A
Input:
    N/A
Results:
    Initializes all scene text strings.
Notes:
    Contains all story text, customer dialogues, and game scenes.
*********************************************************************/

/*********************************************************************
include file name: "DisplayManager.hpp"
Purpose:
    Header file for DisplayManager class.
Notes:
    Contains class definition and function prototypes.
*********************************************************************/
#include "DisplayManager.hpp"

/*********************************************************************
DisplayManager::DisplayManager()
Purpose:
    Constructor that initializes all scene text by calling setter functions.
Parameters:
    None
Return Value:
    None (constructor)
Notes:
    Calls all setter methods to populate scene strings.
*********************************************************************/
DisplayManager::DisplayManager()
{
    setStartingScene();
    setCustomerOne();
    setCustomerTwo();
    setCustomerThree();
    setCustomerFour();
    setCustomerFive();
    setCustomerSix();
    setGuessingScene();
    setVictoryScene();
    setLosingScene();
}

/*********************************************************************
void DisplayManager::setStartingScene()
Purpose:
    Initializes the starting scene text with the game introduction.
Parameters:
    None
Return Value:
    None
Notes:
    Sets up the opening narrative and instructions for the player.
*********************************************************************/
void DisplayManager::setStartingScene()
{
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

Engines purr in the dark. Rain taps Morse on the hull. Six bookings tonight. 
All flagged "priority." None look honest.

Every slip has a name, an item, a quantity, and a cost. The system only trusts *exact* 
entries. One wrong letter, one wrong digit, and a lie can hide in plain sight.

[Radio crackle]

DISPATCH: "Captain, heads up. HQ got a tip: one shipment's manifest is fraudulent. 
Its price looks wrong on paper — not by much, but enough to put a target on our backs 
if we load it."

DISPATCH: "They like to talk, these six. Listen to what they say about each other, 
cargo gossip's cheaper than insurance."

DISPATCH: "And a few of them are fond of riddles now, for some reason. Note those too. 
Between price, loose tongues, and riddles, you’ll spot the liar."

You flip your clipboard open, pen hovering over the first line.

Tonight, you *know* one shipment is lying. Your job is to find it and remove it before 
the ramp closes.

If something goes wrong tonight, your signature’s on it.
)";
}

/*********************************************************************
void DisplayManager::setCustomerOne()
Purpose:
    Initializes customer one (Bulk Ryker) scene text.
Parameters:
    None
Return Value:
    None
Notes:
    Contains dialogue and delivery information for Bulk Ryker.
*********************************************************************/
void DisplayManager::setCustomerOne()
{
    m_szCustomerOne = R"(                 
                 .                             .
                //                             \\
               //                               \\
              //                                 \\
             //                _._                \\
          .---.              .//|\\.              .---.
________ / .-. \_________..-~ _.-._ ~-..________ / .-. \_________
         \ ~-~ /   /H-     `-=.___.=-'     -H\   \ ~-~ /             
           ~~~    / H          [H]          H \    ~~~      0       ()
                 / _H_         _H_         _H_ \           /\#     {[]}
                   UUU         UUU         UUU             /\      //\\

    )"
R"(
──────────────────────────────────────────────
   [January 17 – 00:12, Bulk Ryker Arrives]
──────────────────────────────────────────────

The hangar doors hiss open and a wall of muscle stomps through the rain. 
Tank top, duffel bag, and an expression like the weather offended him.

"BRO," he grunts. "Just got back from Mexico. Don't ask. DO. NOT. ASK."

He drags his crate like it insulted his mother and lets it slam onto the deck.

Bulk Ryker: "Protein Infusion Canisters. Four units. Cost: two hundred. 
Best deal on the dock, bro. Nobody gets them cheaper than me."

The number catches your ear. You’ve seen similar canisters. 
They never come that cheap by a long shot.

Bulk jerks his chin toward the programmer pacing near the back.

Bulk Ryker: "But that programmer kid, Linton? Bro jitters like he drank twelve energy drinks 
and forgot to breathe. Always muttering, eyes all bugged out. I wouldn’t trust him alone 
with my gym bag, let alone a shipment."

He cracks his neck, smirks, then adds:

Bulk Ryker: "25 * 5 is 100"

You log: 
    Name: Bulk Ryker |
    Item: Protein Infusion Canisters |
    Qty: 4 |
    Cost: 200 |
)";
}

/*********************************************************************
void DisplayManager::setCustomerTwo()
Purpose:
    Initializes customer two (Buck Hawthorne) scene text.
Parameters:
    None
Return Value:
    None
Notes:
    Contains dialogue and delivery information for Buck Hawthorne.
*********************************************************************/
void DisplayManager::setCustomerTwo()
{
    m_szCustomerTwo = R"(                 
                 .                             .
                //                             \\
               //                               \\
              //                                 \\
             //                _._                \\
          .---.              .//|\\.              .---.
________ / .-. \_________..-~ _.-._ ~-..________ / .-. \_________
         \ ~-~ /   /H-     `-=.___.=-'     -H\   \ ~-~ /    
           ~~~    / H          [H]          H \    ~~~      0     O
                 / _H_         _H_         _H_ \           /\#  /(_)\
                   UUU         UUU         UUU             /\    | | 

    )"
R"(
──────────────────────────────────────────────
 [January 17 – 00:47, Buck Hawthorne Arrives]
──────────────────────────────────────────────

He waddles in under a rain-slick jacket that does not quite close over his belly, 
clutching a brown bottle of dock beer.

Buck: "Back when I was young, crates were honest. Beer was cheaper. 
Knees didn't hurt. Anyway, here's mine." He eases the crate down with a wheezy grunt.

Buck: "Classic Ale Keg. One unit. Cost: ninety. Standard issue. 
Back when I was young, that would've been thirty. But hey, inflation."

The number sounds right. Nothing unusual there.

He nods toward the conspiracy theorist, still clutching his notebook like evidence.

Buck: "That Vesper boy? Smells like excuses, same scent my disappointing son used to drag 
around after missing shift again. Hell, the kid even slouches the same. 
But underneath all that jitter and talk of lights and triangles, he's solid. 
If my ex-wife had given me custody, I reckon I'd've raised someone a lot like him
rough edges, weird stories, but a good heart shoved in there anyway."

Buck leans closer, voice dropping to a tipsy hush.

Buck: "Here’s a little brain teaser for you, Captain:

    'What has numbers but no weight, 
     letters but no sound?'

Back when I was young, we used that to haze the rookies."

You log: 
    Name: Buck Hawthorne |
    Item: Classic Ale Keg |
    Qty: 1 |
    Cost: 90 |
)";
}

/*********************************************************************
void DisplayManager::setCustomerThree()
Purpose:
    Initializes customer three (Old Man Ripple) scene text.
Parameters:
    None
Return Value:
    None
Notes:
    Contains dialogue and delivery information for Old Man Ripple.
*********************************************************************/
void DisplayManager::setCustomerThree()
{
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
                 / _H_         _H_         _H_ \           /\#   _O_
                   UUU         UUU         UUU             /\     /\

    )"
R"(
──────────────────────────────────────────────
 [January 17 – 01:03, Old Man Ripple Arrives]
──────────────────────────────────────────────

He drifts out of the mist like he was poured from it. 
Coat salt-stained, eyes cloudy, steps slow and sure.

Ripple: "Evening, Captain. Sea spat me back out with a job to finish. 
Funny thing ’bout tides—what leaves always comes back, 
unless it doesn’t. Circle of something… you know."

He pats the crate once, almost fondly, before resting it on the deck, 
clearly convinced he’s just shared ancient ocean wisdom instead of damp confusion.

Ripple: "Net-Stabilizer Kit. Two units. Cost: one hundred twenty."

You’ve seen the same kits listed closer to one-eighty. His price feels… light.

Ripple watches the big man pace grooves into the hangar floor.

Ripple: "Bulk walks like a bar fight looking for a table to break. 
Loud voice, louder footsteps, never still. That kind of energy capsizes calm crews. 
I’ve seen whole voyages sink on men like him."

He listens to the rain for a long moment, then adds, softer, like a tide going out:

Ripple: 
    "When two shadows stand, only one is true.  
     The liar’s breath chills the page they touch."

You log: 
    Name: Old Man Ripple |
    Item: Net-Stabilizer Kit |
    Qty: 2 |
    Cost: 120 |
)";
}

/*********************************************************************
void DisplayManager::setCustomerFour()
Purpose:
    Initializes customer four (Bramble Nett) scene text.
Parameters:
    None
Return Value:
    None
Notes:
    Contains dialogue and delivery information for Bramble Nett.
*********************************************************************/
void DisplayManager::setCustomerFour()
{
    m_szCustomerFour = R"(                 
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
  [January 17 – 01:14, Bramble Nett Arrives]
──────────────────────────────────────────────

He moves like he is not entirely convinced the floor is real. Damp hair, half-smile, 
eyes fixed on the ceiling lights as if checking their pulse.

Bramble: "Mmm. Your dock hums tonight, Captain. Good soil. Good echoes. 
And those lights? I won’t stop staring at ’em. Swear to god they’re breathing. 
In… out… in… out… like they know we’re here."

He lowers the crate with surprising care, like setting down a sleeping animal.

Bramble: "Cultivation Spore Beds. Three units. Cost: one hundred fifty. Fair trade. The fungi approve."

The number matches what you’ve seen before. Standard rate.

His gaze drifts toward the old sailor listening to the rain as if it’s speaking back.

Bramble: "Ripple carries storms in his bones, but his eyes? Those are deep roots. 
He’s the sort who patches holes in other people’s ships without telling them. 
If there’s anyone here I’d plant a secret with, it’s him."

Bramble’s smile tilts, distant.

Bramble:
    "The quietest growth makes the loudest bloom 
     when no one’s watching."

You log: 
    Name: Bramble Nett |
    Item: Cultivation Spore Beds |
    Qty: 3 |
    Cost: 150 |
)";
}

/*********************************************************************
void DisplayManager::setCustomerFive()
Purpose:
    Initializes customer five (Vesper Morrow) scene text.
Parameters:
    None
Return Value:
    None
Notes:
    Contains dialogue and delivery information for Vesper Morrow.
*********************************************************************/
void DisplayManager::setCustomerFive()
{
    m_szCustomerFive = R"(                 
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
  [January 17 – 01:26, Vesper Morrow Arrives]
──────────────────────────────────────────────

He barrels in mid-sentence, rain plastering his hair to his head, 
notebook clutched to his chest.

Vesper: "—AND THAT’S WHEN THE DOGMAN STEPPED OUT OF THE TREE LINE, CAPTAIN. 
Seven feet tall, glowing eyes, smelling like wet copper and bad omens. 
Locking eyes with him? Absolute sign of the apocalypse. 
Page forty-two of my notebook predicted this EXACT scenario."

He sets the crate down like it might bite.

Vesper: "EM Field Sensor. One unit. Cost: one hundred ten. Got a discount from a guy who was 
absolutely beamed up last winter. You can tell in his eyes."

You know EM sensors run more than twice that. The number itches at the back of your mind.

His gaze snags on Buck, who is taking a slow pull from his bottle.

Vesper: "That old-timer, Buck? Everyone acts like he’s harmless, but he’s always watching, 
always listening, like he’s writing a report no one asked for. Folks who play that harmless 
tend to know more than they should."

He taps his notebook once, eyes bright.

Vesper: "Patterns, Captain. The universe loves them. So do liars."

You log: 
    Name: Vesper Morrow |
    Item: EM Field Sensor |
    Qty: 1 |
    Cost: 110 |
)";
}

/*********************************************************************
void DisplayManager::setCustomerSix()
Purpose:
    Initializes customer six (Linton Yarrow) scene text.
Parameters:
    None
Return Value:
    None
Notes:
    Contains dialogue and delivery information for Linton Yarrow.
*********************************************************************/
void DisplayManager::setCustomerSix()
{
    m_szCustomerSix = R"(                 
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
  [January 17 – 01:39, Linton Yarrow Arrives]
──────────────────────────────────────────────

He arrives mid-mutter, fingers twitching like he is typing on an invisible keyboard.

Linton: And for the record, Captain, I’ve decided encapsulation is overrated. 
Everyone keeps telling me to ‘hide my data’ and ‘respect boundaries.’ 
I say: make everything public. Let the world see the mess. 
At least then no one’s surprised when it breaks."

He adjusts the box with unnecessary fuss, then reads from his slip.

Linton: "Soft-Code Debugging Array. One unit. Cost: three hundred twenty."

You have seen arrays like that listed near nine hundred; even on the cheap end, his number runs low.

He forces a laugh that does not quite land.

Linton’s eyes flick to Bramble, still studying the ceiling like it’s growing something.

Linton: "And that Bramble guy? Talks like a meditation app with a glitch. Nobody floats through life 
that calm without hiding a subroutine or two. If anyone here’s running something in the background, 
it’s him."

He leans in, voice dropping.

Linton: 
    "A tool that finds mistakes 
     cannot afford one of its own."

You log: 
    Name: Linton Yarrow |
    Item: Soft-Code Debugging Array |
    Qty: 1 |
    Cost: 320 |
)";
}

/*********************************************************************
void DisplayManager::setGuessingScene()
Purpose:
    Initializes the guessing scene text where player analyzes deliveries.
Parameters:
    None
Return Value:
    None
Notes:
    Sets up the scene where player must identify the fraudulent package.
*********************************************************************/
void DisplayManager::setGuessingScene()
{
    m_szGuessingScene = R"(                 
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
    [January 17 – 01:52, The Manifest Test]
──────────────────────────────────────────────

The rain slackens. The hangar lights buzz. You plant the six slips on the crate and listen.

The mail pouch at your hip thrums—soft, then sharp— like a tuning fork near a lie.

One shipment’s description isn’t honest.

Some costs rang low. Some tongues pointed fingers. Some riddles curled around something nastier 
than wordplay.

You scan the names, the items, the quantities, the costs. Somewhere in the ink, one bad entry 
waits to take the fall.

Review the entries and delete the suspect's delivery:
)";
}

/*********************************************************************
void DisplayManager::setVictoryScene()
Purpose:
    Initializes the victory ending scene text.
Parameters:
    None
Return Value:
    None
Notes:
    Displayed when player correctly identifies the fraudulent package.
*********************************************************************/
void DisplayManager::setVictoryScene()
{
    m_szVictoryScene = R"(                 
                  _
                 -=\`\
             |\ ____\_\__
           -=\ `""""""" "`)
              `----/ /~~`
                -==/ /
                  '-'

                  _  _
                 ( `   )_
                (    )    `)
              (_   (_ .  _) _)
                                             _
                                            (  )
             _ .                         ( `  ) . )
           (  _ )_                      (_, _(  ,_)_)
         (_  _(_ ,)
)"
R"(
──────────────────────────────────────────────
     [January 17 – 02:07, Manifest Verified]
──────────────────────────────────────────────

The pouch on your hip gives one clean, steady hum a truth-note.

You flip the final slip over, scribble your signature, and the hangar exhales with you.

DISPATCH (radio): "Captain, HQ confirms it. Good call. That could’ve cost the entire dock."

A soft clunk echoes as the loading clamps lock. Engines spool, hungry to leave.

Bulk finally stops pacing. 
Buck raises his bottle in a tired salute. 
Ripple closes his eyes and listens to a storm that never arrives. 
Bramble finaly stops staring at the wall.
Vesper scans the sky for triangles and, for once, finds none. 
Linton’s crate sits untouched, danger filed under 'averted.'

Tonight, nothing blows up, phases out, lies, or sings.

You earned your lift-off.

✔ Manifest cleared  
✔ Shipment secured  
✔ Captain intact  

Victory feels like a hangar finally going still.
)";
}

/*********************************************************************
void DisplayManager::setLosingScene()
Purpose:
    Initializes the losing ending scene text.
Parameters:
    None
Return Value:
    None
Notes:
    Displayed when player incorrectly identifies the fraudulent package.
*********************************************************************/
void DisplayManager::setLosingScene()
{
    m_szLosingScene = R"(                            * #** 
                 .          **              .__      * ###*
                //        **##**             \|_       *#*
               //          *#* *               \\     **
              //           **                    \\   *#
             //             ** _._                \\ **
          .---.              ./  |\\.             .---.             <O
         / .-. \___    __..-~ _.-._ ~-..________ / .-. \_________    |\
         \ ~-~ /   \        `-=.___.=-'          \ ~-~ /             /\
_____/              
)"
R"(
──────────────────────────────────────────────
     [January 17 – 02:07, Manifest Failure]
──────────────────────────────────────────────

The pouch on your hip screeches—short, sharp, unmistakably wrong.

Before you can flip the slip back over, the crate beside you *ticks* out of rhythm.

Someone shouts. Something hums. Everything goes sideways.

A flash of light bleeds through the metal like fog through fingers. 
The air screams and the hangar lights pop, one by one.

DISPATCH (radio, panicked): "Captain—Captain?!  
You cleared the wrong manifest. Back away—"

But it’s too late.

The shipment you passed wasn’t honest. 
And tonight, honesty was the only shield you had.

✖ Manifest falsified  
✖ HQ breach reported  
✖ Plane compromised  

The hangar falls silent, except for the rain
tapping your mistake into the floor.
)";
}
