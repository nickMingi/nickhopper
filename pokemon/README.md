POKEMON
=======

#Introduction
>This is based on Lua + Love2D + Tiled Map Editor
>Let's make my own world inside of it
>
>This game's author is Colton Ogden ( Harvard.edu )
>
>Now, I'm implementing other stuffs and modifying other configs

##Preparation
>1. Lua
>2. Love
>3. Tiled
>
##MACOS
```
brew install lua
brew cask install love
brew cask install tiled
```
##Windows
```
download LOVE
Add Configuration Path
```
>Then what you need to do is typing 'love .'
>
##Packaging
```
What you need to do is making .zip file first
Mac OS = zip -9 -r pokemon.love .
Windows = compress whole file 
          change ending with .love from .zip
          copy /b love.exe+pokemon.love pokemon.exe
```
![mingimon](https://postfiles.pstatic.net/MjAxODExMjVfMjQ3/MDAxNTQzMDgxNzU3Njk3.oOxaaJqlHwP3V67qlXtUBRz5FqG9Xq3VEsHxc-mrtYMg.0xiW7lkphXkFZwPvMCV11bTLxwZcEpCRpznd5XERS7gg.PNG.cjsvndtjs1/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2018-11-25_%EC%98%A4%EC%A0%84_2.42.33.png?type=w966 "desc")
>
>Let's get started!
> 
>Pokemon is turned (What I already added)
> It is Timer.tween
>
![mingimon2](https://postfiles.pstatic.net/MjAxODExMjVfNjUg/MDAxNTQzMTE3NjUyNzg4.vhF_qchotT2XdhbC-JNZ3Xidt7ivrmH0he8cADd6Ixkg.Vs_xm1hp3VqIIKZsdAmzsiqZnUGajCuJ7QNIp9T0hhYg.PNG.cjsvndtjs1/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2018-11-25_%EC%98%A4%ED%9B%84_12.43.31.png?type=w966 "desc")
>
>When you press enter, you will see the playState & DialogueState
>
>You must close the dialogue to move
>
![mingimon3](https://postfiles.pstatic.net/MjAxODExMjVfMjYw/MDAxNTQzMTE3Njg2MDM4.T4rGJfiV9bOclQz0bNzP-Vl8rOpAgF0-2JEOGm53ju8g.nnVFUlQO1FF3jnh4kCpz1ZmZpeA4OdVoPfLFgZ_VemAg.PNG.cjsvndtjs1/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2018-11-25_%EC%98%A4%ED%9B%84_12.43.46.png?type=w966 "desc")
>
>When you wondering around the grass, you will encounter the pokemon
>
![mingimon4](https://postfiles.pstatic.net/MjAxODExMjVfNjcg/MDAxNTQzMTE3NzE5MzI4.SVffL2m6IReTtoCgO_r4klYoiPKHaam3mJcvgPjK76gg.ZwVTixV8DsczgChxG65PO_P8Nj-BJeMPNaAAJNmU8iAg.PNG.cjsvndtjs1/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2018-11-25_%EC%98%A4%ED%9B%84_12.44.05.png?type=w966 "You can attack him or run")
>
> You can attack him or run
>
![mingimon5](https://postfiles.pstatic.net/MjAxODExMjVfMjE4/MDAxNTQzMTE3NzM4NzU5.79MP0F58MC8ncpaBbPCVfg4UlHux4aGb8D20jcq4pfcg.40h00HUiqRlt26-E_kHAkkaADOK8KCCCsqwkUDJHJeYg.PNG.cjsvndtjs1/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2018-11-25_%EC%98%A4%ED%9B%84_12.44.28.png?type=w966 "desc")
>
>You will win if you are stronger than enemy
> Getting experience
>
![mingimon6](https://postfiles.pstatic.net/MjAxODExMjVfMjMw/MDAxNTQzMTE3NzU5NTAx.G0CnbBvz_cxjw2jvdNGQCKBObZZUhWjuyphBpXB-R_4g.Te8miyBlUyt8MRcpWGx8GOp-4HIBm11C0zcnl8HCtoAg.PNG.cjsvndtjs1/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2018-11-25_%EC%98%A4%ED%9B%84_12.45.06.png?type=w966 "desc")
>
>If you are not strong enough to beat him, This message will be popped up
>