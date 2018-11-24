--[[
    Remaking Pokemonmaster
    Writer: Mingi hong
    marin333669@gmail.com

    GD50
    Pokemon

    Author: Colton ogden
    cogden@cs50.harvard.edu
]]

StartState = Class{__includes = BaseState}

function StartState:init()
    gSounds['intro-music']:play()

    self.sprite = POKEMON_DEFS[POKEMON_IDS[math.random(#POKEMON_IDS)]].battleSpriteFront
    self.spriteX = VIRTUAL_WIDTH / 2 - 18
    self.spriteY = VIRTUAL_HEIGHT / 2 - 24

    self.tween = Timer.every(3, function()
        Timer.tween(0.2, {
            [self] = {spriteX = -36}
        })
        :finish(function()
            self.sprite = POKEMON_DEFS[POKEMON_IDS[math.random(#POKEMON_IDS)]].battleSpriteFront
            self.spriteX = VIRTUAL_WIDTH 
            self.spriteY = VIRTUAL_HEIGHT / 2 - 24

            Timer.tween(0.2, {
                [self] = {spriteX = VIRTUAL_WIDTH / 2 - 36}
            })
        end)
    end)
end

function StartState:update(dt)
    if love.keyboard.wasPressed('esc') then
        love.event.quit()
    end

    if love.keyboard.wasPressed('enter') or love.keyboard.wasPressed('return') then
        gStateStack:push(FadeInState({
            r = 255, g = 255, b = 255
        }, 1,
        function()
            gSounds['intro-music']:stop()
            self.tween:remove()

            gStateStack:pop()

            gStateStack:push(PlayState())
            gStateStack:push(DialogueState("" ..
                "Welcome to the world of Mingi-Pokemon"
            ))
            gStateStack:push(FadeOutState({
                r = 255, g = 255, b = 255
            }, 1,
            function() end))
        end))
    end
end

function StartState:render()
   love.graphics.clear(188, 188, 188, 255)
   --love.graphics.clear()

   --love.graphics.setColor(24, 24, 24, 255)
   love.graphics.setColor(0,0,0)
   love.graphics.setFont(gFonts['large'])
   love.graphics.printf('Mingi-Mon', 0, VIRTUAL_HEIGHT / 2 - 72, VIRTUAL_WIDTH, 'center' )
   love.graphics.setFont(gFonts['medium'])
   love.graphics.printf('Press Enter', 0, VIRTUAL_HEIGHT / 2 + 68, VIRTUAL_WIDTH, 'center')
   love.graphics.setFont(gFonts['small'])

   --love.graphics.setColor(45, 184, 45, 255)
   love.graphics.setColor(0,1,0)
   love.graphics.ellipse('fill', VIRTUAL_WIDTH / 2, VIRTUAL_HEIGHT /2 + 32, 72, 24)

   --love.graphics.setColor(255, 255, 255, 255)
   love.graphics.setColor(1,1,1)
   love.graphics.draw(gTextures[self.sprite], self.spriteX, self.spriteY)
end