# GEPRExample12
### Inheritance and polymorphism

#### First thoughts:

- screen 1: start fight/exit
- screen 2: select fighter player 1 and 2
- screen 3: fighting screen
- screen 4: victory screen -> screen 1

```
Workflow:
 screen 1:
        selection start -> screen 2
        exit game -> exit

 screen 2:
        player 1 -> select player, player 2 -> select player -> screen 3
        abort -> screen 1

 screen 3:
        fight: if fight end -> screen 4
        abort -> screen 1

 screen 4: on keypress -> screen 1


 fighter:
        attributes:
                HP
                attack modifier
                block modifier
                dodge modifier

        actions:
                attack:
                block:
                dodge:

        mechanic:
                block = reduce damage
                attack = add damage
                dodge = avoid damage

                every action is probability based with a multiplicator

 arena:
        engage:
                contains the fight logic
```

