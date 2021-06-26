# VinProjekt

Za Arduino projekt pri predmetu VIN, sem si izbral izdelavo 6x6 LED zaslona. Z arduino platformo sem že naredil nekaj projektov v srednji šoli, tako da ga sedaj že kar dobro poznam. Za izdelavo sem se odločiv, ker sem želel vključiti v projekt spajkanje in programiranje. V začetku sem želel narediti LED Cube 6x6x6, vendar nisem dobil pravočasno dovolj LED diod tako, da sem se potem odločil za izdelavo 6x6 zaslona.

Vezje ima povezane LED diode v vrstice in stolpce. LED kratica pomeni Light Emitting Diode, tako da kot vse ostale diode tudi pri LED elektrika potuje samo v eno smer, iz anode (+) v katodo(-), kar povzroči, da diode zasveti.
Če pravilno razporedimo anode (+ pozitivna stran) in katode (- negativna stran), lahko s pošiljanjem visokih in nizkih signalov preko Arduino naprave dosežemo, da lahko naslovimo vsako diodo posebaj.
Ker lahko imamo prižgano le eno diodo naenkrat, mi pa želimo imeti prižganih več diod, to dosežemo tako, da prižgemo vsako diodo le za kratek trenutek in tako zelo hitro preklamljamo med diodami, ki jih želimo imeti prižgane in tako povzročimo iluzijo, da vse diode gorijo hkrati.

Arduino je sprogramiran tako, da preko serijske ali Bluetooth povezave dobi niz 6 števil. Vsako izmed the števil predstavlja eno vrstico na zaslonu. Po prejetju števi, jih arduino vsakega posebaj pretvori v binarno število in potem prižge vse led diode na mestih, kjer je v binarnem številu enica. Če pošljemo število 7 za prvo vrstic to pretvorimo v 000111 pomeni, da bojo leve tri diode ugasnjene desne tri diode pa bojo svetile. Ker mu lahko ukažemo, da prižge več diod hkrati ke sprogramirano tako, da vsako diodo prižge le za trenutek in zelo hitro preklaplja med vsemi diodami.
