--[[
    Remaking Pokemonmaster
    Writer: Mingi hong
    marin333669@gmail.com

    GD50
    Pokemon

    Author: Colton Odgen
    cogden@cs50.harvard.edu
]]

PlayState = Class{__includes = BaseState}

function PlayState:init()
    self.level = Level()

    gSounds['field-music']:setLooping(true)
    gSounds['field-music']:play()

    self.dialogueOpened = false
end

function PlayState:update(dt)
    if  love.keyboard.wasPressed('b') then
        gSounds['blip']:play()
        -- show a menu for field
        gStateStack:push(FieldMenuState(self.level.player))
    end

    if not self.dialogueOpened and love.keyboard.wasPressed('p') then
        -- heal player pokemon
        gSounds['heal']:play()
        self.level.player.party.pokemon[1].currentHP = self.level.player.party.pokemon[1].HP

        -- show a dialogue for it, allowing us to do so again
        gStateStack:push(DialogueState('Your pokemon has been healed!',

        function()
            self.dialogueOpened = false
        end))
    end
    
    self.level:update(dt)
end

function PlayState:render()
    self.level:render()
end