"""Bounded CreateSplineCreatures original-PC contract, with explicit world services.
Does not launch the game. Records compact plans, calls and selected actor fields.
"""
import importlib.util,json,struct
from fractions import Fraction
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;D=n.DATA
SYS=D;PACKET=D+0x1000;CREATURE=D+0x2000;SELFREF=D+0x2800;RIDER=D+0x3000;PLAYER=D+0x3800;LOC=D+0x5000;STAB=D+0x6000;SPL=D+0x6100;NAMES=D+0x7000;WORLD=D+0xb000;ARGS=D+0x10000;TEXT=D+0x11000;ACTORS=D+0x20000
TYPECALL=n.STOP+0x100;RESOLVECALL=n.STOP+0x110;ENTRY=0x44a190
uses=next(r['uses'] for r in json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text(encoding='utf8'))['rows'] if r['name']=='CreateSplineCreatures')
def u(x):return x&0xffffffff
def i32(x):return (x+0x80000000)%0x100000000-0x80000000
def i16(x):return (x+0x8000)%0x10000-0x8000
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def fl(x):return struct.unpack('<f',struct.pack('<I',u(x)))[0]
def f32(x):return fl(bits(x))
def vec(x):return [bits(v) for v in x]
def rd(p):return n.read(p,256).split(b'\0')[0].decode('ascii')
def hashname(t):return sum(t.lower().encode('ascii'))
def rng(value):
    v=i32(value^0x75bd924);q=abs(v)//0x1f31d*(1 if v>=0 else -1)
    r=i32(v*0x41a7-q*0x7fffffff)
    if r<0:r=i32(r+0x7fffffff)
    return u(r^0x75bd924)
def number(text):
    if 'param' in text.lower():return 2.75
    if text.lower() in ['alpha','beta','gamma','delta']:return [2.75,1.5,3.,4.][['alpha','beta','gamma','delta'].index(text.lower())]
    k=0;v=0.;div=1.
    if text.startswith('-'):div=-1.;k=1
    while k<len(text) and '0'<=text[k]<='9':v=f32(f32(v*10)+int(text[k]));k+=1
    if k<len(text) and text[k]=='.':
        k+=1
        while k<len(text) and '0'<=text[k]<='9':div=f32(div*10);v=f32(f32(v*10)+int(text[k]));k+=1
    return f32(v/div)
def rounded(q,mantissa):
    """Round an exact rational to a binary float with the given mantissa width (nearest-even)."""
    if q==0:return Fraction(0)
    sign=-1 if q<0 else 1;q=abs(q);e=q.numerator.bit_length()-q.denominator.bit_length()
    while Fraction(2)**e>q:e-=1
    while Fraction(2)**(e+1)<=q:e+=1
    scale=Fraction(2)**(mantissa-1-e);m=q*scale;f=m.numerator//m.denominator;rem=m-f
    if rem>Fraction(1,2) or rem==Fraction(1,2) and f%2:f+=1
    return sign*Fraction(f)/scale
def lerp(minimum,maximum,r):
    # x87 extended (64-bit mantissa) products/sum, then one fstp to float.
    a=rounded((1-Fraction(r))*Fraction(minimum),64);b=rounded(Fraction(r)*Fraction(maximum),64)
    return float(rounded(rounded(a+b,64),24))

# Synthetic spline table: names from every authored spline=/splines= operand plus prefix probes.
SPLINES=[]
for use in uses:
    for t in use['args']:
        low=t.lower()
        for key in ['splines=','spline=']:
            if key in low and 'myspline' not in low:
                name=t[low.find(key)+len(key):]
                for cand in ([name+'_1',name+'_2'] if key=='splines=' else [name]):
                    if cand and cand.lower() not in [s.lower() for s in SPLINES]:SPLINES.append(cand)
                break
SPLINES+=[s for s in ['Alpha','alphabet','Beta','PrefixOne','prefixTwo','Other'] if s.lower() not in [x.lower() for x in SPLINES]]
assert len(SPLINES)<=160
def sid(p):return (p-SPL)//0xc if p else -1
def spline_ptr(i):return SPL+0xc*i if i>=0 else 0

checks={};errors=[];vectors=[];events=[];native_plan=None;attempts=0;opts={}
def check(group,got,want,meta):
    checks[group]=checks.get(group,0)+1
    if got!=want:errors.append(dict(group=group,input=meta,got=got,want=want))
def stop_return(mu,value=0):
    sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,u(value));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
def locid(p):return (p-LOC)//0x3c if p else -1
def actid(p):return (p-ACTORS)//0x1100 if p else -1
def snapshot_plan(sp):
    get=lambda o:n.unpack('<I',sp+o)[0]
    p={k:i32(get(o)) for k,o in dict(minimum=0x3c,maximum=0x44,count=0x28,set=0x50).items()}
    p.update({k:get(o) for k,o in dict(distance=0x48,mindistance=0x4c,maxdistance=0x54).items()})
    p.update({k:bool(get(o)) for k,o in dict(useSelected=0x20,looping=0x24,relativeToPlayer=0x5c).items()})
    p.update(relativeLocator=locid(get(0x38)),rider='rider' if get(0x40)==RIDER else ('none' if not get(0x40) else hex(get(0x40))),offset=list(n.unpack('<3I',sp+0x68)),script=rd(sp+0x138),
             types=list(n.unpack('<'+'h'*get(0x18),sp+0x124)),splines=[sid(n.unpack('<I',sp+0xa4+4*j)[0]) for j in range(get(0x10))])
    return p
def hook(mu,a,size,user):
    global native_plan,attempts
    sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda j:n.unpack('<I',sp+4+4*j)[0]
    if a==0x44a745:native_plan=snapshot_plan(sp);return
    if a==TYPECALL:
        name=rd(arg(0));events.append(['findtype',name]);stop_return(mu,255 if name.lower().startswith('missing') else hashname(name)%8);return
    if a==RESOLVECALL:events.append(['resolvetype',arg(0)]);stop_return(mu,0xffff if arg(0)==7 else arg(0)+1);return
    if a==0x51ac10:
        name=rd(arg(1));events.append(['locator',name]);stop_return(mu,0 if name.lower().startswith('missing') else LOC+0x3c*(hashname(name)%3));return
    if a==0x440120:
        name=rd(arg(1));events.append(['rider',name]);stop_return(mu,0 if name.lower().startswith('missing') else RIDER);return
    if a==0x43d890:
        events.append(['spawn',i32(arg(0)),arg(1),arg(2),rd(arg(3)),arg(4),arg(5),arg(6),sid(arg(7)),list(n.unpack('<3I',arg(8))),arg(9),i32(arg(10))])
        ix=attempts;attempts+=1
        if not opts.get('success',True) or opts.get('alternating') and ix%2:stop_return(mu);return
        p=ACTORS+ix*0x1100;n.write(p,bytes(0x1100));n.pack('<B',p+0x28d,10+ix)
        n.pack('<II',p+0xe64,arg(7),(arg(9)&1)<<16);n.pack('<f',p+0xe80,.5);n.write(p+0xe84,n.read(arg(8),12));stop_return(mu,p);return
    if a==0x4dca00:
        s=sid(arg(0));events.append(['levelspline',s]);n.pack('<i',arg(1),s+10);n.pack('<i',arg(2),s+20);stop_return(mu);return
    if a==0x551c40:
        base=arg(0);kind='player' if base==PLAYER+0x80 else locid(base-0x10)
        events.append(['relative',kind,sid(arg(2)),arg(3),i32(arg(4)),i32(arg(5))])
        n.pack('<8I',arg(1),arg(2),(2+(arg(3)&1))<<16,u(arg(4)),u(arg(5)),*n.unpack('<3I',base),bits(.25));stop_return(mu);return
    if a==0x5518a0:
        f=arg(0);t=fl(arg(1));events.append(['advance',actid(f-0xe64),arg(1)]);n.pack('<f',f+0x1c,f32(n.unpack('<f',f+0x1c)[0]+t));stop_return(mu);return
    if a==0x550a20:
        s=sid(arg(0));t=fl(arg(1));loop=i32(arg(5));events.append(['evaluate',s,arg(1),loop])
        n.pack('<3f',arg(2),f32(t*2),3.,f32(-t));n.pack('<H',arg(3),[0,0x4000,0x8000,0xc000][s%4]);n.pack('<I',arg(4),[0,0x4000,0xc000,0x8000][(s+loop)%4]);stop_return(mu);return
    if a==0x55d2b0:events.append(['update',actid(arg(0))]);stop_return(mu);return
    if a==0x488730:events.append(['ride','rider' if arg(0)==RIDER else hex(arg(0)),actid(arg(1)),arg(2),arg(3)]);stop_return(mu);return

hooks=[0x44a745,TYPECALL,RESOLVECALL,0x51ac10,0x440120,0x43d890,0x4dca00,0x551c40,0x5518a0,0x550a20,0x55d2b0,0x488730]
for address in hooks:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)

def setup(tokens,options):
    global native_plan,attempts,opts
    opts=options;native_plan=None;attempts=0;events.clear();n.write(D,bytes(0x80000))
    n.pack('<I',CREATURE+0xd0,0 if options.get('noRiderRef') else SELFREF);n.pack('<I',SELFREF,RIDER)
    n.pack('<I',PACKET+4,D+0xc000);n.pack('<4f',PACKET+0x14,2.75,1.5,3.,4.);n.pack('<B',PACKET+0xb0,7)
    n.pack('<I',PACKET+0xac,spline_ptr(options.get('mySpline',0)))
    for j,name in enumerate(['alpha','beta','gamma','delta']):n.write(D+0xc200+j*16,name.encode()+b'\0');n.pack('<I',D+0xc018+8*j,D+0xc200+j*16)
    n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x128,8);n.pack('<I',0x87b0a0,8 if options.get('sameLevel') else 9);n.pack('<I',WORLD+0x13c,STAB)
    n.pack('<II',STAB+0x30,len(SPLINES),SPL)
    for j,name in enumerate(SPLINES):n.write(NAMES+64*j,name.encode()+b'\0');n.pack('<I',SPL+0xc*j+4,NAMES+64*j)
    n.pack('<I',0x876d94,spline_ptr(options.get('selected',1)))
    n.pack('<3f',PLAYER+0x80,8.,9.,10.);n.pack('<I',0x93d810,PLAYER);n.pack('<3I',0x93d620,0,0,0)
    for j in range(3):n.pack('<3f',LOC+j*0x3c+0x10,10.+j,20.+j,30.+j)
    n.pack('<I',0x923884,0 if options.get('noTypeCallbacks') else TYPECALL);n.pack('<I',0x923894,0 if options.get('noTypeCallbacks') else RESOLVECALL)
    n.pack('<I',0x8066c0,options.get('seed',1));n.pack('<I',0x95e5d4,options.get('floatSeed',123));n.pack('<I',0x80253c,options.get('seed16',77))
    # Authoritative rotation helpers run unchanged against a cardinal LUT fixture.
    for ix,val in [(0,0.),(0x2000,1.),(0x4000,0.),(0x6000,-1.)]:n.pack('<f',0x29899a0+4*ix,val)
    for j,t in enumerate(tokens):n.write(TEXT+256*j,t.encode()+b'\0');n.pack('<I',ARGS+4*j,TEXT+256*j)

ACTOR_FIELDS=dict(follower=(0xe64,'<8I'),offset=(0xe84,'<3I'),angles=(0x58,'<2H'),pitchYaw=(0x278,'<2H'),position=(0x5c,'<3I'),p80=(0x80,'<3I'),p8c=(0x8c,'<3I'),p98=(0x98,'<3I'),p1b4=(0x1b4,'<3I'),p10bc=(0x10bc,'<3I'))
def actor_snapshots():
    result=[]
    for ix in range(attempts):
        p=ACTORS+ix*0x1100
        if n.unpack('<B',p+0x28d)[0]!=10+ix:continue
        a=dict(index=ix)
        for k,(o,fmt) in ACTOR_FIELDS.items():a[k]=list(n.unpack(fmt,p+o))
        a['follower'][0]=sid(a['follower'][0]);result.append(a)
    return result

def model(tokens,options,first):
    e=[];actors=[];rs=options.get('seed',1);rf=options.get('floatSeed',123);r16=options.get('seed16',77);g=[0,0,0]
    def out(plan=None,result=1):return dict(plan=plan,events=e,actors=actors,rng=rs,floatRng=rf,rng16=r16,globalPosition=g,result=result)
    if not first:return out()
    def call(*args):e.append(list(args))
    p=dict(minimum=-1,maximum=-1,count=1,set=0,distance=0,mindistance=bits(1e9),maxdistance=bits(1e9),useSelected=False,looping=False,relativeToPlayer=False,relativeLocator=-1,rider='none',offset=[0,0,0],script='default',types=[],splines=[])
    selected=options.get('selected',1);my=options.get('mySpline',0)
    order=['mingroupsize','maxgroupsize','groupsize','type','script','mindistance','maxdistance','distance','!use_selected_spline','splines=','spline=myspline','spline=','x_offset=','y_offset=','z_offset=','!looping','addtoset=myset','addtoset=','!relative_to_player','relative_to_locator=','ridden_by=myself','ridden_by=']
    skip={'mingroupsize':13,'maxgroupsize':13,'groupsize':10,'type':5,'script':7,'mindistance':12,'maxdistance':12,'distance':9,'splines=':8,'spline=':7,'x_offset=':9,'y_offset=':9,'z_offset=':9,'addtoset=':9,'relative_to_locator=':20,'ridden_by=':10}
    for token in tokens:
        lower=token.lower();key=None
        for k in order:
            if k=='!use_selected_spline' and selected<0:continue
            if (lower==k[1:]) if k.startswith('!') else (k in lower):key=k;break
        if key is None:continue
        a=lower.find(key.lstrip('!'));tail=token[a+skip.get(key,0):]
        if key in ['mingroupsize','maxgroupsize','groupsize']:p[{'mingroupsize':'minimum','maxgroupsize':'maximum','groupsize':'count'}[key]]=int(number(tail))
        elif key=='type':
            if not options.get('noTypeCallbacks'):
                call('findtype',tail)
                if not tail.lower().startswith('missing'):
                    index=hashname(tail)%8;call('resolvetype',index)
                    if index!=7 and len(p['types'])<10:p['types'].append(index+1)
        elif key=='script':p['script']=tail
        elif key in ['mindistance','maxdistance','distance']:p[key]=bits(number(tail))
        elif key=='!use_selected_spline':p['useSelected']=True
        elif key=='splines=':
            for j,s in enumerate(SPLINES):
                if len(p['splines'])>=32:break
                # 0x4f8b80 compares at least one byte, so an empty pattern matches no nonempty name.
                if tail and s.lower().startswith(tail.lower()):p['splines'].append(j)
        elif key=='spline=myspline':
            if my>=0:
                if len(p['splines'])>=32:raise ValueError('native writes past the 32-entry spline array')
                p['splines'].append(my)
        elif key=='spline=':
            lows=[s.lower() for s in SPLINES]
            if tail.lower() in lows and len(p['splines'])<32:p['splines'].append(lows.index(tail.lower()))
        elif key in ['x_offset=','y_offset=','z_offset=']:p['offset'][ord(key[0])-ord('x')]=bits(number(tail))
        elif key=='!looping':p['looping']=True
        elif key=='addtoset=myset':p['set']=7
        elif key=='addtoset=':p['set']=int(number(tail))
        elif key=='!relative_to_player':p['relativeToPlayer']=True
        elif key=='relative_to_locator=':
            call('locator',tail);p['relativeLocator']=-1 if tail.lower().startswith('missing') else hashname(tail)%3
        elif key=='ridden_by=myself':
            if not options.get('noRiderRef') and not options.get('noSelf'):p['rider']='rider'
        elif key=='ridden_by=':
            call('rider',tail);p['rider']='none' if tail.lower().startswith('missing') else 'rider'
    def draw():
        nonlocal rs
        rs=rng(rs);return i32(rs)
    if tokens and p['minimum']>=0 and p['minimum']<p['maximum']:p['count']=draw()%(p['maximum']-p['minimum']+1)+p['minimum']
    if p['mindistance']!=bits(1e9) and p['maxdistance']!=bits(1e9):
        rf=u(rf*0x19660d+0x3c6ef35f);r=(rf&0x7fffff)/(1<<23);p['distance']=bits(lerp(fl(p['mindistance']),fl(p['maxdistance']),r))
    plan=json.loads(json.dumps(p))
    if not (p['useSelected'] or p['splines']) or not p['types'] or p['count']<=0:return out(plan)
    if p['useSelected']:spline=selected
    else:r16=(r16*0x24cd+1)&0xffff;spline=p['splines'][r16//(0xffff//len(p['splines'])+1)]
    typ=p['types'][draw()%len(p['types'])];dist=fl(p['distance']);offset=[fl(x) for x in p['offset']]
    for ix in range(p['count']):
        call('spawn',typ,0,0,p['script'],0,0,0,spline,p['offset'],int(p['looping']),p['set'])
        if not options.get('success',True) or options.get('alternating') and ix%2:continue
        a=dict(index=ix,follower=[spline,int(p['looping'])<<16,0,0,0,0,0,bits(.5)],offset=list(p['offset']),angles=[0,0],pitchYaw=[0,0],position=[0,0,0],p80=[0,0,0],p8c=[0,0,0],p98=[0,0,0],p1b4=[0,0,0],p10bc=[0,0,0])
        if p['relativeToPlayer'] or p['relativeLocator']>=0:
            la=lb=-1
            if options.get('sameLevel'):call('levelspline',spline);la,lb=spline+10,spline+20
            kind='player' if p['relativeToPlayer'] else p['relativeLocator']
            basev=[8.,9.,10.] if kind=='player' else [10.+kind,20.+kind,30.+kind]
            call('relative',kind,spline,int(p['looping']),la,lb)
            a['follower']=[spline,(2+int(p['looping']))<<16,u(la),u(lb),*vec(basev),bits(.25)]
        if dist!=0 or dist!=dist:
            t=f32(fl(a['follower'][7])+dist);call('advance',ix,bits(dist));a['follower'][7]=bits(t)
            loop=(a['follower'][1]>>16)&0xff;call('evaluate',spline,bits(t),loop)
            pos=[f32(t*2),3.,f32(-t)];yaw=[0,0x4000,0x8000,0xc000][spline%4];pitch=[0,0x4000,0xc000,0x8000][(spline+loop)%4];neg=(-pitch)&0xffff
            a['angles']=[yaw,yaw];a['pitchYaw']=[neg,yaw]
            if any(v!=0 for v in offset):
                lut={0:0.,0x2000:1.,0x4000:0.,0x6000:-1.}
                sin=lambda ang:lut[(ang>>1)&0x7fff];cos=lambda ang:lut[((ang+0x4000)>>1)&0x7fff]
                x,y,z=offset;c,s=cos(neg),sin(neg);tmp=[x,f32(c*y-s*z),f32(y*s+c*z)]
                c,s=cos(yaw),sin(yaw);x,y,z=tmp;tmp=[f32(s*z+c*x),y,f32(z*c-x*s)]
                pos=[f32(m+k) for m,k in zip(pos,tmp)]
            pv=vec(pos);g=list(pv)
            for k in ['position','p80','p8c','p98','p1b4','p10bc']:a[k]=list(pv)
            call('update',ix)
        if p['rider']!='none':call('ride',p['rider'],ix,0,1)
        actors.append(a)
    return out(plan)

def run(tokens,options=None,first=True,source=None,group='targeted'):
    options=options or {};setup(tokens,options)
    try:
        ret=n.call(ENTRY,[SYS,PACKET,0 if options.get('noSelf') else CREATURE,ARGS,len(tokens),int(first)],count=2000000)
        got=dict(plan=native_plan,events=list(events),actors=actor_snapshots(),rng=n.unpack('<I',0x8066c0)[0],floatRng=n.unpack('<I',0x95e5d4)[0],rng16=n.unpack('<I',0x80253c)[0],globalPosition=list(n.unpack('<3I',0x93d620)),result=ret)
        want=model(tokens,options,first)
        for key in got:check(group+'-'+key,got[key],want[key],dict(tokens=tokens,options=options,first=first,source=source))
        vectors.append(dict(tokens=tokens,options=options,first=first,source=source,native=got))
    except Exception as ex:errors.append(dict(tokens=tokens,options=options,first=first,error=str(ex)));raise

if __name__=='__main__':
    base=['type=Test','spline=Alpha','script=Pod']
    for first in [False,True]:
        for ts in [[],base,['type=Test'],['spline=Alpha'],base+['groupsize=0'],base+['groupsize=3'],base+['mingroupsize=1','maxgroupsize=4'],base+['groupsize=2','mingroupsize=3','maxgroupsize=3'],base+['groupsize=2','mingroupsize=3','maxgroupsize=1']]:run(ts,first=first)
    variants=[{},{'success':False},{'alternating':True},{'sameLevel':True},{'noTypeCallbacks':True},{'selected':-1},{'selected':5,'sameLevel':True}]
    for tokens in [base+['distance=2'],base+['distance=2','x_offset=3','y_offset=-1','z_offset=4'],base+['distance=-1.5','z_offset=2','looping'],base+['distance=0','x_offset=3'],
                   base+['mindistance=1','maxdistance=9'],base+['mindistance=1'],base+['maxdistance=9','distance=4'],base+['distance=3','mindistance=2','maxdistance=2'],
                   ['type=Test','use_selected_spline','distance=1','x_offset=1'],['type=Test','USE_Selected_Spline','groupsize=2'],['type=Test','spline=myspline','distance=1'],
                   ['type=Test','splines=Prefix','distance=5','x_offset=2'],['type=Test','splines=','groupsize=3'],['type=Test','splines=alpha','spline=Beta','spline=missing'],
                   base+['relative_to_player','distance=2'],base+['relative_to_locator=Here','distance=2','y_offset=1'],base+['relative_to_locator=missing','distance=2'],base+['relative_to_player','relative_to_locator=Here'],
                   base+['ridden_by=myself','distance=1'],base+['ridden_by=Other','groupsize=2'],base+['ridden_by=missing'],base+['addtoset=myset'],base+['addtoset=3.9','addtoset=param'],
                   base+['type=Other','type=missing','type=Third'],base+['looping','LOOPING','prefixlooping'],base+['script=First','script=Last','unknown','spline=Other'],
                   base+['x_offset=beta','distance=gamma','groupsize=2'],base+['prefixdistance=2','prefixmindistance=1','prefixmaxdistance=3'],base+['sometype=Test2','subtype=missing']]:
        for options in variants:run(tokens,options)
    for seed in [1,2,7,123,0x7654321,0x7fffffff]:
        for count in range(1,5):
            run(base+['type=Second','type=Third','mingroupsize=1','maxgroupsize='+str(count),'mindistance=-3','maxdistance=7.5','x_offset=1','splines=alpha','splines=Prefix'],{'seed':seed,'floatSeed':u(seed*3+1),'seed16':seed&0xffff})
    for count in [9,10,11,12]:run(['type=Name'+str(j) for j in range(count)]+['spline=Alpha'])
    for count in [31,32,33]:run(['type=Test']+['spline=Alpha']*count+['distance=1'])
    for count in [30,31]:run(['type=Test']+['spline=Alpha']*count+['spline=myspline','splines=Prefix'])
    for ts in [['type=Test','spline=myspline'],['type=Test','use_selected_spline','spline=Beta']]:
        for options in [{'mySpline':-1},{'mySpline':3},{'selected':-1},{'noSelf':True},{'noRiderRef':True}]:run(ts+['ridden_by=myself'],options)
    # Actual authored commands, including retained unknown/misspelled tokens.
    for index,use in enumerate(uses):
        source=dict(index=index,source=use['source'],line=use['line'])
        for variant in [{'success':False},{'success':True},{'success':True,'sameLevel':True},{'success':True,'selected':-1}]:run(use['args'],variant,source=source,group='authored')
    result=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,examples=errors[:20],authoredOccurrences=len(uses),fixtureCases=len(vectors),splineTable=SPLINES,adapters=[hex(x) for x in hooks if x!=0x44a745],limits=['World/name/type/locator/rider/allocation/spline-evaluation/effect calls are explicit fixture adapters. The original parser, loop, spline-name table scans (0x5d0690/0x5d0740), scalar evaluator, all three RNGs and cardinal vector helpers execute unchanged.','The synthetic spline table holds every authored spline=/splines= name; it does not establish which splines exist in a live level.','Spline follower layout beyond the fields this command touches, spline evaluation and post-placement update are services.','Actor comparisons cover documented fields, not every byte or downstream effects.','The 33rd spline=myspline write past the native 32-entry array, nonfinite operands, and tokens whose fixed skip passes their terminator are outside the bounded core.','Compiled C# differential execution remains pending under the Windows execution denial.'])
    (BASE/'reports/gameplay-createsplinecreatures-tests.json').write_text(json.dumps(result,indent=2),encoding='utf8')
    (BASE/'reports/gameplay-createsplinecreatures-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,splines=SPLINES,cases=vectors),separators=(',',':')),encoding='utf8')
    print(json.dumps({k:result[k] for k in ['checks','mismatches','fixtureCases','authoredOccurrences']}))
    for ex in result['examples'][:6]:print(json.dumps(ex)[:900])
    if errors:raise SystemExit(1)
