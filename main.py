import os,random,sys,time

c=0
s=["し","か","の","こ","た","ん"]

def get_seed():
    try: return int.from_bytes(os.urandom(4),byteorder='little')
    except: return int(time.time())

def f(i):
    global c
    if not c and not i: return
    print(s[i],end="")
    if i==5: f(4) if random.randint(0,1) else print(); return
    if i==3: v=random.randint(0,3); f(0 if v==0 else 3 if v==1 else 2); return
    f(1 if i==0 and random.randint(0,1) else 4 if i==0 else 2 if i==1 else 3 if i==2 else 5)

def main():
    global c
    if len(sys.argv)<2: print("Frequency not found. (e.g. python main.py 10)"); return 1
    random.seed(get_seed()); c=int(sys.argv[1])
    while c>0: f(0); c-=1
    return 0

if __name__=="__main__": sys.exit(main())