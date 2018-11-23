Readme
======


## Mingi Hong
> Hi, my name is Mingi Hong. 
> I'm first kid in my family grew up in Anyang, Korea.
> I graduated Art High School majoring theater arts.
> Performed in Lamama theater in New York Off-Broadway.
> Now I'm attending Dakota State University majoring Computer Science.
> Nice to Meet you.
1. [Blog](https://blog.naver.com/cjsvndtjs1)
2. WebSite
3. [Youtube](https://www.youtube.com/channel/UC2eXwBPKsQ1OhcaZWdZw_hg)
4. [LinkedIn](https://www.linkedin.com/in/mingi-hong-630279ba/)

## Java
> Java practices.

## Hurdle Algorithm
> Developing Algorithm

![Hurdle1](https://postfiles.pstatic.net/MjAxODExMjNfMjIz/MDAxNTQyOTU0MjQ0MzA5.P_9cQOblrG-y6p4DmqbZzZWLVPQTKqMwwqg5GvZC-Qwg.fbcKoFYlLTSXuw2zBm34RAqAFyjsZgYTVvMcMfI0mwIg.PNG.cjsvndtjs1/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2018-11-23_%EC%98%A4%ED%9B%84_3.23.43.png?type=w966 "desc")

![Hurdle2](https://postfiles.pstatic.net/MjAxODExMjNfODQg/MDAxNTQyOTU0Njg0ODEz.6814PKJpVa_m_mdFJQuyXbsy7EjaxkOQu1DhjVfvsoQg.C9YjfEsMuANruMOmLjG6H9xOrtuLPfaJkDPitybQgssg.PNG.cjsvndtjs1/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2018-11-23_%EC%98%A4%ED%9B%84_3.31.00.png?type=w966 "desc")

```
int[] sortingMedianValues(int desiredCount, int[] originalArr)
```

> To responsive to user desired numbers and array numbers, It should be like above.
>
> I Need Walker
>
> I Need Step
>
> There are Two cases
>
> ( Array.Length / DesiredCount >= 2 )
>
> And Else
```
double walker = (double)(originalArr.Length - 2.0) / (double)((desiredCount - 2.0) * 2.0);
if(originalArr.Length/desiredCount >= 2 )
```
>
![Hurdle3](https://postfiles.pstatic.net/MjAxODExMjNfNDEg/MDAxNTQyOTYxMzgzNjY5.RALpJuV2MRaqK7wQaxjprBFFh0J6nAs1uis-2A0csUwg.mElok-eE7lqWTl-HXlf0qYtoiQzfk4fvF78LN50qJa4g.PNG.cjsvndtjs1/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2018-11-23_%EC%98%A4%ED%9B%84_5.22.35.png?type=w966 "desc")
>
> I still need to think if there is better way, but
>
> This works fine of Speed O(N)

![Hurdle4](https://postfiles.pstatic.net/MjAxODExMjNfMTM5/MDAxNTQyOTYzMTQwMDgw.fTzWEUjr_r4BHa7y3HbI0NSEH7V8pU1pnyfBES4hvdcg.NXuDlxJ_Ky0sy_JImzlRH_evlHLQDqRv4fLWVkRohjUg.PNG.cjsvndtjs1/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7_2018-11-23_%EC%98%A4%ED%9B%84_5.51.53.png?type=w966 "desc")
>
> First case is very easy
> 
> All we need to do is making logic and exceptions such as Skip and Holding ( Because we have to add last one )
>
>

