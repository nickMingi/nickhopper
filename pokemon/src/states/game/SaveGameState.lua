SaveGameState = Class{__includes = BaseState}

function SaveGameState:init(level)
    local filename = gFilenames['saved-game']
    gPlayerData["mapX"] = level.player.mapX
    gPlayerData["mapY"] = level.player.mapY
    print(gPlayerData["mapX"])
    print(gPlayerData["mapY"])
    print(gPlayerData)
    print(gMapData)
    print(gLevelData)
    assert(IsFileExist(filename))
    print(assert(readall(filename)))
    local contents = "gPlayerData = {\n"..
    "['mapX']="..level.player.mapX..",['mapY']="..level.player.mapY..",['width']="..level.player.width..",['height']="..level.player.height.."\n"..
    "}\n"..
    "gMapData = {\n"..
    "}\n"..
    "gLevelData = {\n"..
    "['tileWidth']="..level.tileWidth..",['tileHeight']="..level.tileHeight.."\n"..
    "}\n"
    write(filename, contents)
    self.dialogue = DialogueState("Saved!",function() 
        print("pop savegamestate")
        gStateStack:pop()
        end
    )
    print(assert(readall(filename)))
    gStateStack:push(self.dialogue)
end

function IsFileExist(path)
    local file = io.open(path, "rb")
    if file then file:close() end
    return file ~= nil
end

function readall(filename)
    local file = assert(io.open(filename, "rb"))
    local contents = assert(file:read("*a"))
    file:close()
    return contents
end

function write(filename, contents)
    local file = assert(io.open(filename, "wb"))
    file:write(contents)
    file:flush()
    file:close()
end

function modify(filename, modify_func)
    local contents = readall(filename)
    contents = modify_func(contents)
    write(filename, contents)
end

function SaveGameState:update(dt)
    self.dialogue:update(dt)
end

