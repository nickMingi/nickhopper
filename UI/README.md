UI
=====

# Introduction
>
>This is based on Experience and Research
>I'm glad to share my researches around the world
>
>Especially, I'm going to talk about machine application UIs
>

## List
>1. Analyzing Current UIs
>2. New UI Concepts
>3. Logics
>

## Contents
### * Analyzing Current UIs
>
>
>

### * New UI Concepts

1. Concept1(MacOS)
>
> This concept is almost imitation of Mac OS
> But this is open minded brain storming to come up with best ideas
>
> Why not machine application's look like that?
>
> Let's See
>
![Newgif](https://postfiles.pstatic.net/MjAxODEyMTNfNzgg/MDAxNTQ0NjcwMjMzNDk4.j2v08oUCZffQoh71duulrrm7jl9TpZpy-7ZiEAksUVQg.x7d9SU9DSsrMTLDfNisq9VLxuGzCMlWu8yfpCqiF_CYg.GIF.cjsvndtjs1/NewUIFlowLatest.gif?type=w966 "desc")
>
> You can look at the process flow of Design
> First of all, I wanted to change the mood of application. 
>
> Why machine program should be gray color tone?
>
> How about changing it to be pastel tone?
>
> * Background Image should be customable
> * Top & Bottom menu bar is fixed
> * Main page(Middle) is managed as **node**
> * Main page is changable by user
>
>
![New1](https://postfiles.pstatic.net/MjAxODEyMTNfMTM0/MDAxNTQ0NjY5NzAwODg5._YDwezNKKBlukAI4HcXAfdoUqRjP-1Jds_Ca4AsehL8g.lrcy3I9m8vw1PxeZk0nX2LJeCNGet4A0AIstOUL4XAsg.JPEG.cjsvndtjs1/NewUIBackground-flow1.jpg?type=w966 "desc")
>
> This page is basic concept page
>
> Most Left Top, LOGO should be located
>
> (MainMenus will be located in the list when you click LOGO)
>
> 
>
![New2](https://postfiles.pstatic.net/MjAxODEyMTNfMjM2/MDAxNTQ0NjY5NzAwODk1.g5WFL2gRAzTzOfqg46OTGeyDk_38tgM_IcOABDeTaJMg.n_J_KdE8UYKIcce09UHeLLytmMIQY4_IVYOkwD8JHLQg.JPEG.cjsvndtjs1/NewUIBackground-flow2.jpg?type=w966 "desc")
>
> When you click specific page, you can trace
>
> Page by looking at white circle at the bottom
>
> Also pagename is displayed on the top menu  
>
> Right side of pagename, there are user customized menus 
>
> 
>

![New3](https://postfiles.pstatic.net/MjAxODEyMTNfNzkg/MDAxNTQ0NjY5NzAwNzIx.lJICpJ7KeWj4xlCq9tdXzn-JVZAbga8c6-12X6inDvAg.tgYfunFkPG_74PDkv1tyA5QZfTOvg_a_MkedoBHGEXMg.JPEG.cjsvndtjs1/NewUIBackground-flow3.jpg?type=w966 "desc")
>
>
> The advantage of this concept is wide display
>
> 
>

![New4](https://postfiles.pstatic.net/MjAxODEyMTNfMTIw/MDAxNTQ0NjY5NzAwNzIy._DH2Ze0vcyYQKYAV2EIceYsz6afyzU3ouLFJ-j4xXlEg.hKoSqkKFdH57rX2ymY1i2RMJCTc8loOq5ukW8QPnW58g.JPEG.cjsvndtjs1/NewUIBackground-flow4.jpg?type=w966 "desc")
>
>
> Also You can customize 'Top menu bar' 
>
>
![New5](https://postfiles.pstatic.net/MjAxODEyMTNfNTkg/MDAxNTQ0NjY5NzAwNjkw.SQqwCMNACs-bw68NSpcK1uDNASYp2o9TL_S4VnLFBuQg.CY4_pbK_rrKFAz9dO8tIEdCmtzlYDfbWxe1gip3E0_4g.JPEG.cjsvndtjs1/NewUIBackground-flow5.jpg?type=w966 "desc")
>
>
> You can check latest Login History on the left side
> 
> Login button is at right side of password box
>
> If you click cancel button, Display will be changed to previous
>
> 
>
![New6](https://postfiles.pstatic.net/MjAxODEyMTNfOTAg/MDAxNTQ0NjY5NzAwNzIx.2ggvcyMbOgSn3Gafk6BoM3ZO-cB0HVnf1Q80rXWS6-wg.hNXZ466wkXk2U7LFnKA2W_R3Hwpcjds6SAeaEPHmV_Ig.JPEG.cjsvndtjs1/NewUIBackground-flow6.jpg?type=w966 "desc")
>
>
> If ID is selected from History, 
>
> ID will be automatically displayed on ID box
>
>


### * Logics
```
basically the display is divided into three sections

- Top
- Middle
- Bottom

Mainpage will be displayed in the middle section
Mainpage is managed as *LinkedList*
```
>
> Importantly, Mainpage is tracable by tracking its index 
>
> Also You can follow the history
>
> It is designed with Linked-List
>
![MainPage](https://postfiles.pstatic.net/MjAxODEyMTNfMTY1/MDAxNTQ0NjkxMjcwMzI3.UM7wWd827AA-zkRtYIt5ACu9qmKonEt7qZZjErJs2h4g.6Wtg-XyegkhGU6oolcQ4FhGWFfWA1C85Ueay4ELhZSgg.PNG.cjsvndtjs1/MainpageHistoryManaging.png?type=w966 "desc")
>
> If page is selected, Add(page) into Linked-List
>
> And then Add(another page) when user click another page
>
> If user clicked same page, you don't need to Add(page)
>
> But, In case of (Count >= 2) you should trace current index
>
> For example ) Count = 5, current index = 4  
>
> And you clicked **Previous** Button
>
> Current index should be changed to 3
> 
>  
>
![TopMenu](https://postfiles.pstatic.net/MjAxODEyMTNfMjMg/MDAxNTQ0NjkxMjcwMzM2.V1UsFvRfeyhbj6B52OERcpwMjQkhMTsz4rzndOtt6AQg.m5wFrwyGt_H_sDlmBA9tlsd_t8EtjcR7IUFAoy2Mnwkg.PNG.cjsvndtjs1/TopMenuCustomizing.png?type=w966 "desc")
>
> Top menu is designed as Tree System
>
> Main Node will be **PageName**
>
> Degree 1 of Nodes will be displayed in Top Menu  
>
> Nodes that over or equal of degree 2 will be showed
>
> On action of Mouse hover
>


