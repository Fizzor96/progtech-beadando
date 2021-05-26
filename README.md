# Progtech  

A projekt amin dolgoztam egy konyvesboltot szimulal es a hozza tartozo tarolasi funkcionalitasokat (kivesz, berak, szures, feltoltes, stb.).
A fo cel a legtobb tervezesi minta implementalasa egy jol strukuralt modon, mint peldaul a bemenetek kezelese, kisbetu nagybetu megkulonboztetese vagy akar a validalas.
A program igazabol nem sikerult ugy ahogy kellett volna, mivel voltak gatlo tenyezok (ket "tipus" osszehasonlitasa nem lehetseges "C++"-ban) tehat nem teljesen latja el a program a funkciojat ilyen modon. Habar meg tudtam volna csinalni mas modon is, de akkor nem lenne benne ennyi tervezesi minta implementalva, vagy legalabbis a vaza.

## Design Patterns

### MVC Szerkezet
A szeles korben hasznalt MVC(Model View Conrol) minta implementalva.
Ez egy olyan tervezesi minta, ami segit a fejlesztonek konnyen atlani a projekt strukturajan, azzal, hogy 3 reszre bontja a fo programot.

### Models
* Books: (**Cost**: *float*, **Description**: *std::string*)
* Extension: (**Cost**: *float*, Description: *std::string*) **implements** Decorator minta
* Storage: (store, remove, add, validate, get) **implements** Singleton minta

### Views
A program konzolos hasznalatra lett kitalalva, egy egyszeru sugo rendszer lett implementalva alap osztalykent a nagyobb rugalmassag erdekeben, azonban amiota ez egy egyszeru projekt, igy meg 2 nezetet hoztam letre, az egyiket az arak kezelesere, a masikat pedig a bolt menedzselesere.

* Log: (Abstract, void promptOutput(): *static*, std::string getUserInput(): *static*)
* LogStorage (storageOptions: *String*, bookOptions: *String*, extensionOptions: *String*, isextensionOptions: *String*) : public Log
* LogCost (costChangeOption: *std::string*) : public Log


### Controllers
A projekt az alap bolt funkcioira alapult, bar velemenyem szerint egy kontroller boven eleg ezen feladatok elvegzesere, mivel a legtobb implementalt metodus, a tobbitol fugg.

* Storage Controller
  * handleUserInput() `index`
  * removeBookFromStorage() `destroy`
  * fillStorageByType() `store`
  * orderBook() `order`  
  * setPrice() `set`
  **Helpers:**  
  * chooseBookType()
  * chooseExtension()
  * makeBook()
  
### Singleton
Igazabol nem tudom, hogy miert raktam bele Singletont, mivel a gyakorlatban nem tudhatjuk pontosan elore, hogy mikor lehet szukseg akar tobb peldanyra, ezert nem sok ertelmet latom ennek a mintanak, nyilvan vannak kivetelek (pl.: multithredingnel ha mar konzolos alkalmazasoknal maradunk, akkor egy threadet masolni peldaul nem lehet, viszont a "tulajdonjogat" at lehet adni, es itt jon a kepbe a mozgatas szemantikaja). Azaz azzal, hogy egy Singletont letrehoztam lenyegeben ki kellett toroljem copy constructort es az assignment operatort. Tehat csak move constuctora lehet az osztalyomnak. Ezzel a modszerrel a Storage osztalyom konnyen Singletonna teheto.

### Decorator
Sok kulonbozo tipusu kony van, azonban ezekhez tarsul meg a kiterjesztes is, az alaptipus mellett.
Azert hogy meg lehessen oket kulonboztetni a tobbitol anelkul hogy szetvalasztanank oket, igy a Decorator minta tokeletesen megfelel erre a celra.
Minden konyv modell kiterjesztese az alap konyv osztalynak, a kiterjesztessel rendelkezo konyvek tulajdonsagai viszont oroklodnek az alaptipusabol, igy kulonbseget tudunk koztuk tenni.

### Factory 
A Factory minta celja, hogy elkulonitse a peldanyositas logikajat. Amig a controller kiveszi a reszet az peldanyositasbol, addig a factory eldonti, hogy mik legyenek peldanyositva.
