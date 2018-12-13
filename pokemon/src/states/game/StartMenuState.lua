StartMenuState = Class{__includes = BaseState}

function StartMenuState:init()
    self.startMenu = Menu{
        x = VIRTUAL_WIDTH - 128,
        y = VIRTUAL_HEIGHT - 64,
        width = 128,
        height = 64,
        items ={
            {
                text = 'New Game',
                onSelect = function()
                    gStateStack:push(FadeInState({
                        r = 255, g = 255, b = 255
                    }, 1,
                    function()
                        gStateStack:pop()
            
                        gStateStack:push(PlayState('new'))
                        gStateStack:push(DialogueState("" ..
                            "Welcome to the world of Mingi-Pokemon"
                        ))
                        gStateStack:push(FadeOutState({
                            r = 255, g = 255, b = 255
                        }, 1,
                        function() end))
                    end))
                end
            },
            {
                text = 'Load latest game',
                onSelect = function()
                    gStateStack:push(FadeInState({
                        r = 255, g = 255, b = 255
                    }, 1,
                    function()
                        gStateStack:pop()
            
                        gStateStack:push(PlayState('load'))
                        gStateStack:push(DialogueState("" ..
                            "Let's do it again"
                        ))
                        gStateStack:push(FadeOutState({
                            r = 255, g = 255, b = 255
                        }, 1,
                        function() end))
                    end))
                end
            }
        }
    }
end

function StartMenuState:update(dt)
    self.startMenu:update(dt)
end

function StartMenuState:render()
    self.startMenu:render()
end