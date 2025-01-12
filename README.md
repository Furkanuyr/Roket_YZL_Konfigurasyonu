# Roket_YZL_Konfigurasyonu
Şimdi ilk olarak içine stdint.h kütüphanesini ekliyorum. Çünkü toplam değerini 8 bit değerinde saklayacağım.(0b yapısında olduğu için bunları ikilik sistem şeklinde tutuyor.)
Ondan sonra enum verilerini oluşturuyorum. 
Struct Yapısının içinede bu enum veri tiplerini ve yazdırcağım configvalue atıyorum.
Fonksiyonu oluştururken pointer kullanıyorum çünkü öbür türlü sadece bir kopyasını oluşturuyor. Kaydırma işlemlerinide reg value göre yapıyorum.
Değerleri kullanıcadan alınmayacağı için kendim örnekteki değerleri kullanıyorum.
Son olarakta Printf'le istenilen değerler  kullanıcıya gösteriliyor.
