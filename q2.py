import numpy


def ropes(total_length,my_low,my_high,T,cond1,cond2):

    my_array = []
    S = []
    num_cond1=0
    num_cond2=0
    #s_flag=1
    i=0
    len_rope1=0
    len_rope2=0
    len_rope3=0
    #while(i<T):
    for i in range(0,T,1):
        print("\n"+"RUN #"+str(i)+"\n")

        a=numpy.random.randint(low=my_low,high=my_high)
        #print(a)
        b=numpy.random.randint(low=my_low,high=my_high)
        #print(b)

        if(a>b):
            len_rope1=total_length-a
            len_rope2=b
            len_rope3=a-b
        if(b>a):
            len_rope1=total_length-b
            len_rope2=a
            len_rope3=b-a
        if(a==b):
            len_rope1=(int)(total_length/3.0)
            len_rope2=len_rope1
            len_rope3=total_length-(len_rope1+len_rope3)

        print("len_rope1: "+str(len_rope1)+" "+"len_rope2: "+str(len_rope2)+" "+"len_rope3: "+str(len_rope3))

        S=max(len_rope1,len_rope2,len_rope3)
        s_flag=max(len_rope1,len_rope2,len_rope3)
        print("Selecting: "+str(S))

        my_array.append(S)

        print("S: "+str(S))

        total_length=S
        my_low=1
        print("my_low: "+str(my_low))
        my_high=total_length-1
        print("my_high: "+str(my_high))

        if(my_low==my_high or my_low==0 or my_high==0):
            print("my_array: "+str(my_array))
            print("T: "+str(T))
            print("Mean: "+str("%10.15f" % float(numpy.mean(my_array))))
            print("S.D: "+str("%10.15f" % float(numpy.std(my_array))))
            print("Probability of S greater than "+str(cond1)+" is: "+str("%10.15f" % float(num_cond1/T)))
            print("Probability of S greater than "+str(cond2)+" given S greater than " + str(cond1) + " is: "+str("%10.15f" % ((num_cond2/T)/(num_cond1/T))))

            print("\n")
            exit()


        if(S>cond1):
            print(str(S)+">"+str(cond1))
            num_cond1=num_cond1+1
        else:
            print(str(S)+"<"+str(cond1))
        if(S>cond2 and S>cond1):
            print(str(S)+">"+str(cond2))
            num_cond2=num_cond2+1
        else:
            print(str(S)+"<"+str(cond2))
            
    print("num_cond1: "+str(num_cond1))
    print("num_cond2: "+str(num_cond2))

    print("my_array: "+str(my_array))
    print("T: "+str(T))
    print("Mean: "+str("%10.15f" % float(numpy.mean(my_array))))
    print("S.D: "+str("%10.15f" % float(numpy.std(my_array))))
    print("Probability of S greater than "+str(cond1)+" is: "+str("%10.15f" % float(num_cond1/T)))
    print("Probability of S greater than "+str(cond2)+" given S greater than " + str(cond1) + " is: "+str("%10.15f" % float((num_cond2/T)/(num_cond1/T))))
    print("Result: "+str("%10.15f" % float((num_cond2/T)/(num_cond1/T))))
    print("Result Mean: "+str("%10.15f" % float(numpy.mean(my_array))))
    print("Result S.D: "+str("%10.15f" % float(numpy.std(my_array))))
    print("\n")


total_length=64.0
my_low=2.0
my_high=total_length-1
T=5
condA=4
condB=8

print("Task A")
ropes(total_length,my_low,my_high,T,condA,condB)

total_length2=1024
my_low=2.0
my_high=total_length2-1
T2=10
condA2=6
condB2=12

print("Task B")
ropes(total_length2,my_low,my_high,T2,condA2,condB2)


