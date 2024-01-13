# Payday 3: FbiServer Heist

**Disclaimer:** I am not a 3D designer and I never did maps before. This is my first time working with Unreal Engine.  
I am not affiliated in any way with Starbreeze or Deep Silver.

### What?

This is a PD3 port of the firstarter heist day 2 from PD2. I picked this heist since I wanted to have a small simple heist with both stealth and loud and is not reimagined yet in PD3. So, I ported the same layout (since I am neither a designer nor have something unique in mind to implement) and added the new PD3 mechanisms.

### Why?

The game has been out for more than 4 months at the moment of this upload and we don't have any functional maps. I am not really sure if this is because the game is kinda of dead that the modding community doesn't want to bother building, the fact that you can't play with friends custom heists, or due to unreal engine. For me, I took the map building as a challenge that I wanted to tackle and hopefully help bootstrap more content by providing the modders with a complete heist they can use as a lookup and possibly with documentation.

### How?

You just need to use the `sources` folder to compile your editor with SBZ assets. The source creation is created using `UE4SS` courtesy of the original developer and `Narknon`. However, the automatically generated assets have close but not fully correct constructors. This leads to issues such as crashing or some functionality broken. (Ex: the safe was working correctly but with no sound due to a missing AK component, whereas a missing interactable leads to a crash). Once compiled, you can use the custom contents folder.  
**NOTE:** I didn't include any of the game assets for legal purposes and size-wise. You will need to extract them yourself.

#### Assets Extraction

Not all asset types can be handled the same. Here is a list of what you need to do based on asset type:
- **Audio:** You only need to dummy the files you want to play. Just create an `AkEvent` and set the name and it should work.
- **Widgets:** Generally speaking you won't be working with widgets unless they are used in the gameplay like drill widget and hacking widgets. You can use the cooked assets extracted from `fmodel` or `unpak` without the need for asset generation as long as you don't plan to modify them.
- **Effects:** Unfortunately, you can't regenerate Niagera effects as far as I know and cooked assets will crash the editor on any click or attempted use. This only allows you to create a dummy so you can use it. As a result, you won't be able to see the hacking circle or escape area and will have to run the game to correct the size of your escape.
- **Meshes and Texture:** You can use cooked directly and it would work flawlessly.
- **Dynamic Materials:** For Most of those, I used cooked but it won't show correctly in the editor but would work as expected in the game.
- **Blueprint classes:** Use cooked unless you want to alter a behavior there. You can use cooked and still change the mesh or material. Using assets generated will be a big troublesome journey for you, due to that the editor will remove all assets' references if they don't exist. Not to mention that if the BP contains a timeline, a new timeline GUID is generated and thus won't work with the one bundled in the game. You can solve that using HxD but I wouldn't recommend it. I used the door from asset generation and although I got it working, if I try to use cooked now, the editor crashes. Using the uncooked one resulted in a painful experience handling inconsistency between the editor and game, and missing static meshes references.

### Where?

The current map state is complete logic both stealth and loud. But it is missing the guards/patrol and assault spawn point. It is also missing the camera randomization but that is not a coding issue but rather because I don't have a plan of how to group them and what to show with which. Some of the furniture are placed but most are not but they shouldn't affect functionality since most of the glass panels that control navigation are already placed.  
This map is not professional at all, so if you come looking for a multi-million/billion studio level of polishing you won't find it in here.  
Lighting is a bit of a mess but you should be able to see all of the map, just some maintenance boxes show a fading color or just white because of the unlit conditions.  
The map is dauntless in terms of time consumption, there is a lot of hacking and they have a long time. I understand that but I needed to include as many features as possible for guiding others and since the map is small, I wanted the loud to have a good assault time and the stealth to not be trivially easy, so both will be a bit challenging.  
I didn't set the correct scaling for the floor plan and as a result, the area of the map is smaller than PD2, you can see that in the street width or the floor space. Although I wanted to fix that, it implied that I would need to rebuild all walls and reallocate all the stuff so I ignored this issue.  
All the assets used are the game assets, remember I don't use any 3D software so I can't create my own assets.

### Then?

I do plan to finish this map completely but I wanted to release it now rather than later to get some feedback and try to encourage people to start developing maps before the game completely dies, if it is not already dead.  
A full documentation is planned with all the issues I faced, but that needs a lot of time and effort for one guy.  
I still have one challenge to feel that I conquered all the challenges I planned. The final piece of the puzzle would be to make it a co-op map. This is done by either using the in-game -already built albeit hidden- server browser which only lists P2P game sessions or by allowing matchmaking this heist. The earlier option implies that I need to be able to reintroduce the game code support for `Listen Server` (re-add the stripped functions) and I would register my game as a P2P session for other people to join me, while the latter would still require `Listen Server` but then I would reintroduce the code for dedicated server and join the heist pool as if it was SBZ server. A lot of work and I am sure they won't like it there but that is the only way we can extend the game with custom content.

### License?

This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.   
To view a copy of this license, visit <http://creativecommons.org/licenses/by-nc-nd/4.0/> or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.  
I welcome all feedback and would love for you to help by creating pull requests. What I don't want is people repackaging and releasing as their own. When the time comes for me to move off this game or be too busy to maintain it, I will drop the `NoDerivatives` clause. Open source is for helping people build and improve not to help them steal it.

### Contact?

You can reach me on Discord at `abkarino`, here in GitHub issues, or on the map mod page on NexusMods.

### Donation?

If you like my work and want to support me in spending more time modding, feel free to donate at <https://www.buymeacoffee.com/abkarino>
