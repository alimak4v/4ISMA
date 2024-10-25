![Снимок экрана 2024-10-23 в 09.46.24.png](imported%2F%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202024-10-23%20%D0%B2%2009.46.24.png)
# Insurance company management model

The article considers the work of an insurance company that provides insurance for the population in three areas (types of insurance): home insurance, car insurance and health insurance.

The game simulates the work of an insurance company. The modeling step is one month, it includes the following operations:
1. payment of a permanent tax to the state on the total capital of the company
2. sale of all types of insurance to the public
3. payment of insurance amounts to the population according to insured events,
   what happened this month
4. Determining the terms of new insurance for the following months (the player must reject/accept the terms of people's applications)

**The purpose** is to identify insurance conditions that allow to increase its total capital.

**class usrs** (contains information about signed contracts)

public:
- addUser – adding the policyholder to the journal
- nextMonth – deletion from the insurance log with a completed contract
- check_var – payment for insured accidents
- get_type – type of insurance

  private:
- journal_ - vector of valid insurance, contains information about the type of insurance, duration of the contract, payment for an accident and the amount paid by the policyholder per month

**class Button** (working with buttons in the window)

public:
- setPosition – setting coordinates
- setText – setting the label
- setSize – setting the size
- show – rendering
- IsPressed – click detection
- setColor – setting the color

  private:
- rectangle_ - rectangle
- font_ - font of the text
- text_ - text

The whole game is divided into scenes:
-Start
![start.png](imported%2Fstart.png)
-settings
![settings.png](imported%2Fsettings.png)
-the gameplay itself
![game.png](imported%2Fgame.png)
-statistics window
![static.png](imported%2Fstatic.png)


class usrs is a child class of the insur class






















Report:
Statistics for recent launches by month (profit):
- 6993394 -626000 -634000 0 -127000 -123000
- 569000 0 505414 0 1047376 0
- 4537000 3372000 0 2342000 1234214 2344000
- 569000 0 505414 0 1047376 0


Settings:
- capital    (low : 500.000$ | middle : 1.000.000$ | high : 5.000.000$)
- tax        (low : 2% | middle : 13% | middle : 30%)
- demand     (low : 5ppl | middle : 10ppl | high : 20ppl)
- period     (low : 6 months | midlle : 12 months | high : 24 months)
- insurance  (low : 1% | middle : 10% | high : 50%)

Game screen:
- In the game by random you can agree with the insurance for car/house/health
- Insurance pay : how much you must pay in insurance case
- Will pay : hou much you'l get
- How long : duration of insurance