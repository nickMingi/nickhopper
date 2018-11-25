--
-- libraries
--

Class = require 'lib/class'
Event = require 'lib/knife.event'
push = require 'lib/push'
Timer = require 'lib/knife.timer'

require 'src/Animation'
require 'src/constants'
require 'src/Party'
require 'src/Pokemon'
require 'src/pokemon_defs'
require 'src/StateMachine'
require 'src/Util'
require 'src/Item'
require 'src/item_defs'
require 'src/Bag'

require 'src/battle/BattleSprite'
require 'src/battle/Opponent'

require 'src/entity/entity_defs'
require 'src/entity/Entity'
require 'src/entity/Player'

require 'src/gui/Menu'
require 'src/gui/Panel'
require 'src/gui/ProgressBar'
require 'src/gui/Selection'
require 'src/gui/Textbox'

require 'src/states/BaseState'
require 'src/states/StateStack'

require 'src/states/entity/EntityBaseState'
require 'src/states/entity/EntityIdleState'
require 'src/states/entity/EntityWalkState'
require 'src/states/entity/PlayerIdleState'
require 'src/states/entity/PlayerWalkState'

require 'src/states/game/BattleState'
require 'src/states/game/BattleMenuState'
require 'src/states/game/BattleMessageState'
require 'src/states/game/DialogueState'
require 'src/states/game/FadeInState'
require 'src/states/game/FadeOutState'
require 'src/states/game/PlayState'
require 'src/states/game/StartState'
require 'src/states/game/TakeTurnState'
require 'src/states/game/FieldMenuState'
require 'src/states/game/MenuState'

require 'src/world/Level'
require 'src/world/tile_ids'
require 'src/world/Tile'
require 'src/world/TileMap'

gTextures = {
    ['tiles'] = love.graphics.newImage('graphics/sheet.png'),
    ['entities'] = love.graphics.newImage('graphics/entities.png'),
    ['cursor'] = love.graphics.newImage('graphics/cursor.png'),

--[[     ['aardart-back'] = love.graphics.newImage('graphics/pokemon/aardart-back.png'),
    ['aardart-front'] = love.graphics.newImage('graphics/pokemon/aardart-front.png'),
    ['agnite-back'] = love.graphics.newImage('graphics/pokemon/agnite-back.png'),
    ['agnite-front'] = love.graphics.newImage('graphics/pokemon/agnite-front.png'),
    ['anoleaf-back'] = love.graphics.newImage('graphics/pokemon/anoleaf-back.png'),
    ['anoleaf-front'] = love.graphics.newImage('graphics/pokemon/anoleaf-front.png'),
    ['bamboon-back'] = love.graphics.newImage('graphics/pokemon/bamboon-back.png'),
    ['bamboon-front'] = love.graphics.newImage('graphics/pokemon/bamboon-front.png'),
    ['cardiwing-back'] = love.graphics.newImage('graphics/pokemon/cardiwing-back.png'),
    ['cardiwing-front'] = love.graphics.newImage('graphics/pokemon/cardiwing-front.png'), ]]

    ['Bulbasaur-front'] = love.graphics.newImage('graphics/pokebox/1.png'),
    ['Bulbasaur-back'] = love.graphics.newImage('graphics/pokebox/back/1.png'),
    ['Ivysaur-front'] = love.graphics.newImage('graphics/pokebox/2.png'),
    ['Ivysaur-back'] = love.graphics.newImage('graphics/pokebox/back/2.png'),
    ['Venusaur-front'] = love.graphics.newImage('graphics/pokebox/3.png'),
    ['Venusaur-back'] = love.graphics.newImage('graphics/pokebox/back/3.png'),
    ['Charmander-front'] = love.graphics.newImage('graphics/pokebox/4.png'),
    ['Charmander-back'] = love.graphics.newImage('graphics/pokebox/back/4.png'),
    ['Charmeleon-front'] = love.graphics.newImage('graphics/pokebox/5.png'),
    ['Charmeleon-back'] = love.graphics.newImage('graphics/pokebox/back/5.png'),
    ['Charizard-front'] = love.graphics.newImage('graphics/pokebox/6.png'),
    ['Charizard-back'] = love.graphics.newImage('graphics/pokebox/back/6.png'),
    ['Squirtle-front'] = love.graphics.newImage('graphics/pokebox/7.png'),
    ['Squirtle-back'] = love.graphics.newImage('graphics/pokebox/back/7.png'),
    ['Wartortle-front'] = love.graphics.newImage('graphics/pokebox/8.png'),
    ['Wartortle-back'] = love.graphics.newImage('graphics/pokebox/back/8.png'),
    ['Blastoise-front'] = love.graphics.newImage('graphics/pokebox/9.png'),
    ['Blastoise-back'] = love.graphics.newImage('graphics/pokebox/back/9.png'),
    ['Caterpie-front'] = love.graphics.newImage('graphics/pokebox/10.png'),
    ['Caterpie-back'] = love.graphics.newImage('graphics/pokebox/back/10.png'),
    ['Metapod-front'] = love.graphics.newImage('graphics/pokebox/11.png'),
    ['Metapod-back'] = love.graphics.newImage('graphics/pokebox/back/11.png'),
    ['Butterfree-front'] = love.graphics.newImage('graphics/pokebox/12.png'),
    ['Butterfree-back'] = love.graphics.newImage('graphics/pokebox/back/12.png'),
    ['Weedle-front'] = love.graphics.newImage('graphics/pokebox/13.png'),
    ['Weedle-back'] = love.graphics.newImage('graphics/pokebox/back/13.png'),
    ['Kakuna-front'] = love.graphics.newImage('graphics/pokebox/14.png'),
    ['Kakuna-back'] = love.graphics.newImage('graphics/pokebox/back/14.png'),
    ['Beedrill-front'] = love.graphics.newImage('graphics/pokebox/15.png'),
    ['Beedrill-back'] = love.graphics.newImage('graphics/pokebox/back/15.png'),
    ['Pidgey-front'] = love.graphics.newImage('graphics/pokebox/16.png'),
    ['Pidgey-back'] = love.graphics.newImage('graphics/pokebox/back/16.png'),
    ['Pidgeotto-front'] = love.graphics.newImage('graphics/pokebox/17.png'),
    ['Pidgeotto-back'] = love.graphics.newImage('graphics/pokebox/back/17.png'),
    ['Pidgeot-front'] = love.graphics.newImage('graphics/pokebox/18.png'),
    ['Pidgeot-back'] = love.graphics.newImage('graphics/pokebox/back/18.png'),
    ['Rattata-front'] = love.graphics.newImage('graphics/pokebox/19.png'),
    ['Rattata-back'] = love.graphics.newImage('graphics/pokebox/back/19.png'),
    ['Raticate-front'] = love.graphics.newImage('graphics/pokebox/20.png'),
    ['Raticate-back'] = love.graphics.newImage('graphics/pokebox/back/20.png'),
    ['Spearow-front'] = love.graphics.newImage('graphics/pokebox/21.png'),
    ['Spearow-back'] = love.graphics.newImage('graphics/pokebox/back/21.png'),
    ['Fearow-front'] = love.graphics.newImage('graphics/pokebox/22.png'),
    ['Fearow-back'] = love.graphics.newImage('graphics/pokebox/back/22.png'),
    ['Ekans-front'] = love.graphics.newImage('graphics/pokebox/23.png'),
    ['Ekans-back'] = love.graphics.newImage('graphics/pokebox/back/23.png'),
    ['Arbok-front'] = love.graphics.newImage('graphics/pokebox/24.png'),
    ['Arbok-back'] = love.graphics.newImage('graphics/pokebox/back/24.png'),
    ['Pikachu-front'] = love.graphics.newImage('graphics/pokebox/25.png'),
    ['Pikachu-back'] = love.graphics.newImage('graphics/pokebox/back/25.png'),
    ['Raichu-front'] = love.graphics.newImage('graphics/pokebox/26.png'),
    ['Raichu-back'] = love.graphics.newImage('graphics/pokebox/back/26.png'),
    ['Sandshrew-front'] = love.graphics.newImage('graphics/pokebox/27.png'),
    ['Sandshrew-back'] = love.graphics.newImage('graphics/pokebox/back/27.png'),
    ['Sandslash-front'] = love.graphics.newImage('graphics/pokebox/28.png'),
    ['Sandslash-back'] = love.graphics.newImage('graphics/pokebox/back/28.png'),
    ['NidoranM-front'] = love.graphics.newImage('graphics/pokebox/29.png'),
    ['NidoranM-back'] = love.graphics.newImage('graphics/pokebox/back/29.png'),
    ['NidoranF-front'] = love.graphics.newImage('graphics/pokebox/30.png'),
    ['NidoranF-back'] = love.graphics.newImage('graphics/pokebox/back/30.png'),
    ['Nidorina-front'] = love.graphics.newImage('graphics/pokebox/31.png'),
    ['Nidorina-back'] = love.graphics.newImage('graphics/pokebox/back/31.png'),
    ['Nidoqueen-front'] = love.graphics.newImage('graphics/pokebox/32.png'),
    ['Nidoqueen-back'] = love.graphics.newImage('graphics/pokebox/back/32.png'),
    ['Nidorino-front'] = love.graphics.newImage('graphics/pokebox/33.png'),
    ['Nidorino-back'] = love.graphics.newImage('graphics/pokebox/back/33.png'),
    ['Nidoking-front'] = love.graphics.newImage('graphics/pokebox/34.png'),
    ['Nidoking-back'] = love.graphics.newImage('graphics/pokebox/back/34.png'),
    ['Clefairy-front'] = love.graphics.newImage('graphics/pokebox/35.png'),
    ['Clefairy-back'] = love.graphics.newImage('graphics/pokebox/back/35.png'),
    ['Clefable-front'] = love.graphics.newImage('graphics/pokebox/36.png'),
    ['Clefable-back'] = love.graphics.newImage('graphics/pokebox/back/36.png'),
    ['Vulpix-front'] = love.graphics.newImage('graphics/pokebox/37.png'),
    ['Vulpix-back'] = love.graphics.newImage('graphics/pokebox/back/37.png'),
    ['Ninetales-front'] = love.graphics.newImage('graphics/pokebox/38.png'),
    ['Ninetales-back'] = love.graphics.newImage('graphics/pokebox/back/38.png'),
    ['Jigglypuff-front'] = love.graphics.newImage('graphics/pokebox/39.png'),
    ['Jigglypuff-back'] = love.graphics.newImage('graphics/pokebox/back/39.png'),
    ['Wigglytuff-front'] = love.graphics.newImage('graphics/pokebox/40.png'),
    ['Wigglytuff-back'] = love.graphics.newImage('graphics/pokebox/back/40.png'),
}

gFrames = {
    ['tiles'] = GenerateQuads(gTextures['tiles'], 16, 16),
    ['entities'] = GenerateQuads(gTextures['entities'], 16, 16)
}

gFonts = {
    ['small'] = love.graphics.newFont('fonts/font.ttf', 8),
    ['medium'] = love.graphics.newFont('fonts/font.ttf', 16),
    ['large'] = love.graphics.newFont('fonts/font.ttf', 32)
}

gSounds = {
    ['field-music'] = love.audio.newSource("sounds/102-palette_town_theme.mp3","static"),
    ['battle-music'] = love.audio.newSource('sounds/107-battle_(vs_wild_pokemon).mp3',"static"),
    ['blip'] = love.audio.newSource('sounds/blip.wav',"static"),
    ['powerup'] = love.audio.newSource('sounds/powerup.wav',"static"),
    ['hit'] = love.audio.newSource('sounds/hit.wav',"static"),
    ['run'] = love.audio.newSource('sounds/run.wav',"static"),
    ['heal'] = love.audio.newSource('sounds/heal.wav',"static"),
    ['exp'] = love.audio.newSource('sounds/exp.wav',"static"),
    ['levelup'] = love.audio.newSource('sounds/levelup.wav',"static"),
    ['victory-music'] = love.audio.newSource('sounds/victory.wav',"static"),
    ['intro-music'] = love.audio.newSource('sounds/intro.mp3',"static")
}