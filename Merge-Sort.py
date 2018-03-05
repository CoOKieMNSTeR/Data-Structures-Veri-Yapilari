def mergeSort(liste):
    print("Bölme: ",liste)
    if len(liste)>1:
        orta = len(liste)//2
        solyarı = liste[:orta]
        sagyarı = liste[orta:]

        mergeSort(solyarı)
        mergeSort(sagyarı)

        i=0
        j=0
        k=0
        while i<len(solyarı) and j<len(sagyarı):
            if solyarı[i]<sagyarı[j]:
                liste[k]=solyarı[i]
                i=i+1
            else:
                liste[k]=sagyarı[j]
                j=j+1
            k=k+1

        while i<len(solyarı):
            liste[k]=solyarı[i]
            i=i+1
            k=k+1

        while j<len(sagyarı):
            liste[k]=sagyarı[j]
            j=j+1
            k=k+1
    print("Birleştirme ",liste)

liste = [54,26,93,17,77,31,44,55,20]
mergeSort(liste)
print(liste)
