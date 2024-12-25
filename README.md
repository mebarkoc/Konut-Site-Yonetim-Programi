Proje C++ kullanılarak oluşturulmuştur.
Sakarya Üniversitesi Programlamaya Giriş Dersinin proje ödevi için bu programı yapmış bulunmaktayım.
Nesne Tabanlı Programlama için güzel bir örnek uygulamadır.

Konut Sitesi Yönetim Programı

  Bir tatil sitesi düşünelim. Bu tatil sitesinde binalar olsun. Bu binaların içerisinde de daireler bulunsun. Her bir dairede 
oturan daire sakinleri olsun. Bu tatil sitesinin Fitness, Yüzme Havuzu gibi ortak kullanım alanları bulunsun.

  Temel olarak bu dairede oturan insanların aidatları takip edilecek, ortak kullanım alanlarını kullanımları takip edilecek ve 
bu alanları kullanmaları kontrol edilecektir. Proje kabaca aşağıdaki gibidir:

--> Mekan isimli bir class ve bu classtan Daire, Fitness ve Havuz classları oluşturulmuştur.

--> Oturan classı oluşturulmuş ve bu classtan AileReisi ve Misafir classları oluşturulmuştur.

--> Mekan.txt isimli bir dosya oluşturulmuş ve bu dosyaya Daireler, Fitness vb kayıt edilmiştir.

--> Data.txt isimli bir dosya oluşturulmuş ve bu dosyada oturanlar kayıt edilmiştir.

--> Odeme.txt isimli bir dosya oluşturulmuş ve bu dosyada ödemeler kayıt edilmiştir.

--> HavuzKul.txt isimli bir dosya oluşturulmuş ve bu dosyada havuzu kullananlar kayıt edilmiştir. 

--> Fitness.txt isimli bir dosya oluşturulmuş ve bu dosyada fitness salonunu kullananlar kayıt edilmiştir.

--> Mekan için bir menü oluşturulmuştur. Oluşturulan menüde ekleme, silme, düzeltme, listeleme vb gibi işlevler bulunmaktadır.

--> Data.txt dosyasına kişiler ve bu kişilerin daire bilgileri kayıt edilmiştir. Menüdeki işlevlerin bu dosya için kullanımı sağlanmıştır.

--> Havuz kullanımında site sakini ve misafir havuzu kullanabilir. Site sakini geldiğinde daire borcu yoksa havuz kullandırılır ve HavuzKul.txt
dosyasına verisi kayıt edilir. Eğer dairenin borcu varsa havuz kullandırılmaz ve buna ilişkin veri ilgili dosyaya kayıt edilir.
Örneğin şu kişi havuzu kullandı veya şu kişi şu kadar borcu yüzünden havuzu kullanmadı gibi.

--> Fitness kullanımında da havuz kullanımı dinamiklerinin aynısı uygulanır.

--> Bu projenin UML class diyagramı bulunmaktadır.
