"""Finite binary arithmetic with the PC's x87 64-significand-bit rounding.

Used only at the original timer's multiply/divide/store boundaries. Integer
arithmetic preserves intermediate rounding; this is not a general x87 emulator.
"""
import struct

def rounded(n,d):
 q,r=divmod(n,d)
 return q+(2*r>d or (2*r==d and q&1))

def rational(n,d=1,e=0):
 if n==0:return (0,0)
 sign=-1 if n<0 else 1;n=abs(n)
 k=n.bit_length()-d.bit_length()
 if (n<(d<<k))if k>=0 else ((n<<-k)<d):k-=1
 shift=63-k
 sig=rounded(n<<shift,d)if shift>=0 else rounded(n,d<<-shift)
 if sig==1<<64:sig>>=1;k+=1
 return (sign*sig,e+k-63)

def wide(x):
 n,d=float(x).as_integer_ratio()
 return rational(n,d)

def mul(a,b):return rational(a[0]*b[0],1,a[1]+b[1])

def add(a,b):
 e=min(a[1],b[1])
 return rational((a[0]<<(a[1]-e))+(b[0]<<(b[1]-e)),1,e)

def dot3_plus_constant(x,y,z,a,b,c,d):
 return store(add(add(add(mul(wide(x),wide(a)),mul(wide(y),wide(b))),mul(wide(z),wide(c))),wide(d)))

def div(a,b):
 if b[0]==0:raise ZeroDivisionError('finite animation arithmetic')
 return rational(a[0]*(-1 if b[0]<0 else 1),abs(b[0]),a[1]-b[1])

def store(a):
 n,e=a
 if not n:return 0.
 sign=0x80000000 if n<0 else 0;n=abs(n)
 raw=e+63+127
 shift=40+max(0,1-raw)
 sig=rounded(n,1<<shift)
 if raw<=0:bits=sign|sig
 else:
  if sig==1<<24:sig>>=1;raw+=1
  bits=sign|(0x7f800000 if raw>=255 else (raw<<23)|(sig&0x7fffff))
 return struct.unpack('<f',struct.pack('<I',bits))[0]

def scaled_rate(movement,reference,fps):
 return store(mul(div(wide(movement),wide(reference)),wide(fps)))

def frame_delta(step,multiplier,rate,reversed):
 value=wide(step)
 if reversed:value=mul(value,wide(multiplier))
 return store(mul(div(value,wide(-30 if reversed else 30)),wide(rate)))
