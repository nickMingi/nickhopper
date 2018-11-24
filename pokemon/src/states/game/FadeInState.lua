--[[
    Remaking Pokemonmaster
    Writer: Mingi hong
    marin333669@gmail.com

    GD50
    Pokemon

    Author: Colton Odgen
    cogden@cs50.harvard.edu
]]

FadeInState = Class{__includes = BaseState}

function FadeInState:init(color, time, onFadeComplete)
    self.r = color.r
    self.g = color.g
    self.b = color.b
    self.opacity = 0
    self.time = time

    Timer.tween(self.time, {
        [self] = {opacity = 255}
    })
    :finish(function()
        gStateStack:pop()
        onFadeComplete()
    end)
end

function FadeInState:render()
    
end