"""Bounded CreateCreatures original-PC contract, with explicit world services.
Does not launch the game. Records compact plans, calls and selected actor fields.
"""
import importlib.util,json,struct,math,random,hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_ESI,UC_X86_REG_EDI
n=native.NativeX86();BASE=native.BASE;D=n.DATA
SYS=D;PACKET=D+0x1000;CREATURE=D+0x2000;SELF=D+0x3000;LOC=D+0x5000;SET=D+0x6000;ZIP=D+0x7000;TYPE=D+0x9000;WORLD=D+0xb000;ARGS=D+0x10000;TEXT=D+0x11000;ACTORS=D+0x20000;TYPECALL=n.STOP+0x100;RESOLVECALL=n.STOP+0x110
uses=next(r['uses'] for r in json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text(encoding='utf8'))['rows'] if r['name']=='CreateCreatures')
def u(x):return x&0xffffffff
def i32(x):return (x+0x80000000)%0x100000000-0x80000000
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def fl(x):return struct.unpack('<f',struct.pack('<I',u(x)))[0]
def f32(x):return fl(bits(x))
def vec(x):return [bits(v) for v in x]
def rd(p):return n.read(p,256).split(b'\0')[0].decode('ascii')
def idof(p,base,stride):return (p-base)//stride if p else -1
def hashname(t):return sum(t.lower().encode('ascii'))
def rng(value):
    v=i32(value^0x75bd924); q=abs(v)//0x1f31d*(1 if v>=0 else -1)
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

checks={};errors=[];vectors=[];events=[];native_plan=None;attempts=0;selects=0;opts={};case_tokens=[];zip_active=False
def check(group,got,want,meta):
    checks[group]=checks.get(group,0)+1
    if got!=want:errors.append(dict(group=group,input=meta,got=got,want=want))
def stop_return(mu,value=0):
    sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,u(value));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
def snapshot_plan(sp):
    get=lambda o:n.unpack('<I',sp+o)[0]
    p={k:i32(get(o)) for k,o in dict(minimum=0x34,maximum=0x30,count=0x24,across=0xb4,set=0x7c).items()}
    p.update({k:bool(get(o)) for k,o in dict(grouped=0xa0,surface=0x3c,inherit=0xa8,start=0x4c,nearest=0x9c,offscreen=0xc4,onscreen=0x48,zipdown=0xb8,cheap=0xd0,nogun=0xc8,balloon=0xc0).items()})
    p.update({k:get(o) for k,o in dict(xspacing=0xac,zspacing=0xa4,maxrange=0x98,miny=0x50,maxy=0x68,crateheight=0xb0,cratedelay=0xcc,fall=0x94,addcap=0x80,removecap=0x8c).items()})
    p.update(offset=list(n.unpack('<3I',sp+0x70)),script=rd(sp+0x26c),state=rd(get(0xd4)) if get(0xd4) else None,setref=bool(get(0x18)),rider=bool(get(0x2c)),types=list(n.unpack('<'+'h'*get(0x14),sp+0x258)),locators=[idof(n.unpack('<I',sp+0xd8+4*j)[0],LOC,0x3c) for j in range(get(0x20))],zips=[idof(n.unpack('<I',sp+0x1d8+4*j)[0],ZIP,0x100) for j in range(get(0x54))])
    return p
def hook(mu,a,size,user):
    global native_plan,attempts,selects,zip_active
    sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda j:n.unpack('<I',sp+4+4*j)[0]
    if a==0x45776d:
        native_plan=snapshot_plan(sp);return
    if a==0x4577b0 and native_plan is None:
        native_plan=snapshot_plan(sp);return
    if a==TYPECALL:
        name=rd(arg(0));events.append(['findtype',name]);stop_return(mu,255 if name.lower().startswith('missing') else hashname(name)%8);return
    if a==RESOLVECALL:events.append(['resolvetype',arg(0)]);stop_return(mu,arg(0)+1);return
    if a==0x491800:events.append(['randommap']);stop_return(mu,4);return
    if a==0x440030:events.append(['generic']);stop_return(mu,3);return
    if a==0x51ac10:
        name=rd(arg(1));events.append(['locator',name]);stop_return(mu,0 if name.lower().startswith('missing') else LOC+0x3c*(hashname(name)%3));return
    if a==0x51ac70:
        name=rd(arg(1));events.append(['set',name]);stop_return(mu,0 if name.lower().startswith('missing') else SET);return
    if a==0x51fe60:events.append(['refresh']);stop_return(mu);return
    if a==0x449ee0:
        name=rd(arg(0));events.append(['zip',name]);stop_return(mu,0 if name.lower().startswith('missing') else ZIP+0x100*(hashname(name)%3));return
    if a==0x440120:
        name=rd(arg(1));events.append(['rider',name]);stop_return(mu,0 if name.lower().startswith('missing') else SELF);return
    if a==0x44d870:
        name=rd(mu.reg_read(UC_X86_REG_ESI));events.append(['capability',name]);stop_return(mu,4 if name.lower()=='gun' else 0x80000002);return
    if a in [0x440290,0x440470]:
        ls=[idof(n.unpack('<I',arg(0)+4*j)[0],LOC,0x3c) for j in range(arg(1))]
        events.append(['select',a==0x440470,ls,arg(2),bool(arg(3)),arg(4),arg(5),arg(6),arg(7)])
        chosen=0 if opts.get('selectFail') or not ls else LOC+0x3c*ls[selects%len(ls)];selects+=1;zip_active=False;stop_return(mu,chosen);return
    if a==0x449e60:
        ls=[idof(n.unpack('<I',mu.reg_read(UC_X86_REG_EDI)+4*j)[0],ZIP,0x100) for j in range(arg(0))]
        events.append(['selectzip',ls]);zip_active=True;stop_return(mu,0 if opts.get('selectFail') or not ls else ZIP+0x100*ls[selects%len(ls)]);selects+=1;return
    if a==0x517fd0:events.append(['formation',i32(arg(1)),arg(2),arg(3),arg(4)]);stop_return(mu,D+0xf000);return
    if a==0x43d890:
        orient=arg(4);oid=idof(orient-0x20,LOC,0x3c)+1 if LOC+0x20<=orient<LOC+3*0x3c else (-2 if orient else 0)
        events.append(['spawn',i32(arg(0)),list(n.unpack('<3I',arg(1))),arg(2),rd(arg(3)),oid,bool(arg(5)),bool(arg(6)),i32(arg(10))])
        ix=attempts;attempts+=1
        good=opts.get('success',True) and not zip_active and (not opts.get('alternating') or ix%2==0)
        if not good:stop_return(mu);return
        p=ACTORS+ix*0x1100;n.write(p,bytes(0x1100));n.pack('<B',p+0x28d,10+ix);n.pack('<I',p+0x1fc,0x1001);n.pack('<I',p+0xeec,0x1234567f);n.pack('<I',p+0x4bc,0x12345678);n.pack('<I',p+0x370,SET if opts.get('preinherit') else 0);n.pack('<3f',p+0x190,1.+ix,2.,3.);stop_return(mu,p);return
    if a==0x52c790:events.append(['state',idof(arg(0)-0x2c8,ACTORS,0x1100),rd(arg(1))]);stop_return(mu);return
    if a==0x4302e0:events.append(['crate',idof(arg(0),ACTORS,0x1100),arg(1),arg(2)]);stop_return(mu);return
    if a==0x58d430:events.append(['zipdown',idof(arg(0),ACTORS,0x1100)]);stop_return(mu);return
    if a==0x488730:events.append(['ride',idof(arg(1),ACTORS,0x1100)]);stop_return(mu);return
    if a==0x49d4d0:events.append(['balloon',idof(arg(0),ACTORS,0x1100)]);stop_return(mu);return
    if a==0x49d520:events.append(['balloonheight',idof(arg(0),ACTORS,0x1100),arg(1)]);stop_return(mu);return

hooks=[0x45776d,0x4577b0,TYPECALL,RESOLVECALL,0x491800,0x440030,0x51ac10,0x51ac70,0x51fe60,0x449ee0,0x440120,0x44d870,0x440290,0x440470,0x449e60,0x517fd0,0x43d890,0x52c790,0x4302e0,0x58d430,0x488730,0x49d4d0,0x49d520]
for address in hooks:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)

def setup(tokens,options):
    global native_plan,attempts,selects,opts,zip_active
    opts=options;native_plan=None;attempts=selects=0;zip_active=False;events.clear();n.write(D,bytes(0x80000))
    n.pack('<I',SYS+0x28,LOC);n.pack('<I',CREATURE+0xd0,SELF);n.pack('<I',SELF,SELF)
    n.pack('<3f',SELF+0x5c,2.,3.,4.);n.pack('<H',SELF+0x27a,0x4000);n.pack('<3f',SELF+0x438,8.,9.,10.)
    n.pack('<I',PACKET+4,D+0xc000);n.pack('<4f',PACKET+0x14,2.75,1.5,3.,4.);n.pack('<B',PACKET+0xb0,7);n.pack('<II',PACKET+0xa4,LOC+2*0x3c,SET)
    for j,name in enumerate(['alpha','beta','gamma','delta']):n.write(D+0xc200+j*16,name.encode()+b'\0');n.pack('<I',D+0xc018+8*j,D+0xc200+j*16)
    n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x128,7 if options.get('hub') else 8);n.pack('<I',0x951b94,7)
    n.pack('<II',SET+0x14,SET+0x100,SET+0x110);n.pack('<B',SET+0x10,3);n.write(SET+0x100,b'\0\1\2');n.write(SET+0x110,bytes(options.get('occupants',[255,0,255])))
    for j in range(3):
        n.pack('<3fI',LOC+j*0x3c+0x10,10.+j,20.+j,30.+j,[0,0x4000,0x8000][j]);n.pack('<3f',ZIP+j*0x100+0x10,40.+j,50.+j,60.+j)
    n.pack('<I',0x29130e4,TYPE);n.pack('<II',TYPE+0x1c,TYPE+0x800,TYPE+0x1000)
    for j in range(16):n.pack('<h',TYPE+0x800+2*j,j);n.pack('<If',TYPE+0x1000+j*0x4c+0x24,TYPE+0x2000+j*0x40,0.);n.pack('<f',TYPE+0x1000+j*0x4c+0x30,j+.5);n.pack('<f',TYPE+0x2000+j*0x40+0x1c,j+1.25)
    for a,v in [(0x7f18fc,2),(0x7f1958,3),(0x7f1a74,5)]:n.pack('<h',a,v)
    n.pack('<I',0x923884,0 if options.get('noTypeCallbacks') else TYPECALL);n.pack('<I',0x923894,0 if options.get('noTypeCallbacks') else RESOLVECALL)
    n.pack('<I',0x93d810,SELF);n.pack('<I',0x8066c0,options.get('seed',1));n.pack('<I',0x95e5d4,options.get('floatSeed',123))
    # Authoritative rotation helper runs unchanged against a cardinal LUT fixture.
    for ix,val in [(0,0.),(0x2000,1.),(0x4000,0.),(0x6000,-1.)]:n.pack('<f',0x29899a0+4*ix,val)
    for j,t in enumerate(tokens):n.write(TEXT+256*j,t.encode()+b'\0');n.pack('<I',ARGS+4*j,TEXT+256*j)

def actor_snapshots():
    result=[]
    for ix in range(attempts):
        p=ACTORS+ix*0x1100
        if n.unpack('<B',p+0x28d)[0]!=10+ix:continue
        result.append(dict(index=ix,locator=idof(n.unpack('<I',p+0x36c)[0],LOC,0x3c),setref=bool(n.unpack('<I',p+0x370)[0]),flags=n.unpack('<I',p+0x1fc)[0],gun=n.unpack('<I',p+0xeec)[0],capability=n.unpack('<I',p+0x4bc)[0],movement=n.unpack('<B',p+0x7b5)[0],kind=n.unpack('<H',p+0x7aa)[0],ziporigin=list(n.unpack('<3I',p+0x748))))
    return result

def model(tokens,options,first):
    e=[];actors=[];occupants=list(options.get('occupants',[255,0,255]));rs=options.get('seed',1);rf=options.get('floatSeed',123)
    def call(kind,*args):e.append([kind,*args])
    p=dict(minimum=-1,maximum=-1,count=1,across=2,set=0,grouped=True,surface=True,inherit=True,start=False,nearest=False,offscreen=False,onscreen=False,zipdown=False,cheap=False,nogun=False,balloon=False,xspacing=bits(.8),zspacing=bits(.8),maxrange=bits(1e9),miny=bits(1e9),maxy=bits(1e9),crateheight=0,cratedelay=0,fall=0,offset=[0,0,0],script='default',state=None,setref=False,rider=False,types=[],locators=[],zips=[],addcap=0,removecap=0)
    if not first:return dict(plan=None,events=e,actors=actors,occupants=occupants,rng=rs,floatRng=rf,result=1)
    def find(kind,name):
        call(kind,name)
        return None if name.lower().startswith('missing') else hashname(name)%3
    def addtype(v):
        if v!=-1 and len(p['types'])<10:p['types'].append(v)
    order=['mingroupsize','maxgroupsize','groupsize','start_locator_set=','!dont_inherit_locator_set','locator_set=','locator=','max_range_to_player=','mindy=','maxdy=','zipup','type=randommap','type=generic_goon','type','state=','script','xspacing','zspacing','xoffset','yoffset','zoffset','nacross','addtoset=myset','addtoset=','crate_height=','crate_delay=','!not_grouped','!dont_set_on_surface','!zipdown','!nearest_player','!off_screen','!offscreen','!on_screen','fall_chance=','!CheapAsChips','ridden_by=myself','ridden_by=','!no_gun','!ballooning','lose_capability=','capability=']
    numeric={'mingroupsize':('minimum',13),'maxgroupsize':('maximum',13),'groupsize':('count',10),'max_range_to_player=':('maxrange',20),'mindy=':('miny',6),'maxdy=':('maxy',6),'xspacing':('xspacing',9),'zspacing':('zspacing',9),'nacross':('across',8),'addtoset=':('set',9),'crate_height=':('crateheight',13),'crate_delay=':('cratedelay',12),'fall_chance=':('fall',12)}
    for token in tokens:
        lower=token.lower();key=None
        for k in order:
            if (lower==k[1:].lower()) if k.startswith('!') else (k in lower):key=k;break
        if key is None:continue
        a=lower.find(key.lstrip('!').lower());tail=lambda skip:token[a+skip:]
        if key in numeric:
            field,skip=numeric[key];v=number(tail(skip));p[field]=int(v) if field in ['minimum','maximum','count','across','set'] else bits(v)
        elif key in ['start_locator_set=','locator_set=']:
            name=tail(len(key));p['setref']=name.lower()=='myset' or find('set',name) is not None
            if key=='start_locator_set=':
                if p['setref']:p['start']=True
            elif p['setref']:
                call('refresh')
                p['locators'].extend([j for j,v in enumerate(occupants) if v==255][:64-len(p['locators'])])
        elif key=='locator=':
            if len(p['locators'])<64:
                name=tail(8);v=2 if name.lower()=='mylocator' else find('locator',name)
                if v is not None:p['locators'].append(v)
        elif key=='zipup':
            if len(p['locators'])<32:
                v=find('zip',tail(6))
                if v is not None:p['zips'].append(v)
        elif key=='type=randommap':
            if options.get('hub'):call('randommap');addtype(4)
        elif key=='type=generic_goon':
            if len(p['types'])<10:call('generic');addtype(3)
        elif key=='type':
            if not options.get('noTypeCallbacks'):
                name=tail(5)
                if options.get('hub'):
                    v={'barman':2,'jabba':3,'cantinaband':5}.get(name.lower())
                    if v is not None:addtype(v)
                else:
                    call('findtype',name)
                    if not name.lower().startswith('missing'):index=hashname(name)%8;call('resolvetype',index);addtype(index+1)
        elif key=='state=':p['state']=tail(6)
        elif key=='script':p['script']=tail(7)
        elif key in ['xoffset','yoffset','zoffset']:p['offset'][['xoffset','yoffset','zoffset'].index(key)]=bits(number(tail(8)))
        elif key=='addtoset=myset':p['set']=7
        elif key=='!dont_inherit_locator_set':p['inherit']=False
        elif key=='!not_grouped':p['grouped']=False
        elif key=='!dont_set_on_surface':p['surface']=False
        elif key=='!zipdown':p['zipdown']=True;p['surface']=False
        elif key=='!nearest_player':p['nearest']=True
        elif key in ['!off_screen','!offscreen']:p['offscreen']=True
        elif key=='!on_screen':p['onscreen']=True
        elif key=='!CheapAsChips':p['cheap']=True
        elif key=='ridden_by=myself':p['rider']=True
        elif key=='ridden_by=':p['rider']=find('rider',tail(10)) is not None
        elif key=='!no_gun':p['nogun']=True
        elif key=='!ballooning':p['balloon']=True;p['surface']=False
        elif key in ['capability=','lose_capability=']:
            name=tail(len(key));call('capability',name);p['addcap' if key=='capability=' else 'removecap']|=4 if name.lower()=='gun' else 0x80000002
    captured=json.loads(json.dumps(p));count=p['count']
    def draw():
        nonlocal rs
        rs=rng(rs);return i32(rs)
    if p['minimum']>=0:
        if p['minimum']<p['maximum']:count=draw()%(p['maximum']-p['minimum']+1)+p['minimum']
        elif p['minimum']==p['maximum']:count=p['minimum']
    pos=[2.,3.,4.];heading=0x4000;orientation=-2;offset=[fl(x) for x in p['offset']];applied=False;delay=0.;attempt=select=0
    while count!=0:
        if (not p['locators'] and not p['zips'] and not p['rider'] and not p['start']) or not p['types']:break
        typ=p['types'][draw()%len(p['types'])];loc=None;zipid=None
        if p['locators'] or p['start']:
            if p['start'] and p['setref']:loc=0
            else:
                ls=p['locators'];radius=bits(typ+1.) if p['offscreen'] else 0
                call('select',p['nearest'],ls,radius,p['nearest'] or p['maxrange']!=bits(1e9),p['maxrange'],int(p['onscreen']),p['maxy'],p['miny'])
                loc=None if options.get('selectFail') or not ls else ls[select%len(ls)];select+=1
            if loc is None:break
            pos=[10.+loc,20.+loc,30.+loc];heading=[0,0x4000,0x8000][loc];orientation=loc+1;applied=False
        elif p['zips']:
            call('selectzip',p['zips'])
            if options.get('selectFail'):break
            zipid=p['zips'][select%len(p['zips'])];select+=1;pos=[40.+zipid,50.+zipid,60.+zipid];orientation=0;p['surface']=False
        elif p['rider']:pos=[8.,9.,10.];heading=0x4000;orientation=-2
        if not applied and any(v!=0 for v in offset):
            x,y,z=offset;sin,cos={0:(0.,1.),0x4000:(1.,0.),0x8000:(0.,-1.)}[heading];offset=[f32(sin*z+cos*x),y,f32(cos*z-sin*x)];pos=[f32(a+b) for a,b in zip(pos,offset)];applied=True
        group=count if p['grouped'] else 1;count-=group
        for j in range(group):
            if j==0 and group>1:call('formation',p['across'],p['xspacing'],p['zspacing'],bits(typ+1.25))
            ix=attempt;attempt+=1;call('spawn',typ,vec(pos),heading,p['script'],orientation,group>1,p['surface'],p['set'])
            if not options.get('success',True) or zipid is not None or options.get('alternating') and ix%2:continue
            a=dict(index=ix,locator=loc if loc is not None else -1,setref=p['setref'] if p['inherit'] else options.get('preinherit',False),flags=0x1001,gun=0x1234567f,capability=0x12345678,movement=0,kind=0,ziporigin=[0,0,0])
            if p['state'] is not None:call('state',ix,p['state'])
            if p['nogun']:a['gun']&=0xfffffffb
            if p['crateheight']!=0:call('crate',ix,p['crateheight'],bits(delay))
            delay=f32(delay+fl(p['cratedelay']))
            if p['setref'] and loc is not None:occupants[loc]=10+ix
            fall=fl(p['fall']);drop=False
            if p['zipdown']:
                if fall<=0:drop=True
                else:rf=u(rf*0x19660d+0x3c6ef35f);drop=fall<=((rf&0x7fffff)/(1<<23))
            if drop:a.update(movement=0x35,kind=0x2a,ziporigin=vec([1.+ix,2.,3.]));call('zipdown',ix)
            if p['cheap']:a['flags']|=0x420
            if p['rider']:call('ride',ix)
            elif p['balloon']:
                call('balloon',ix)
                if loc is not None:call('balloonheight',ix,bits(20.+loc))
            a['capability']=(a['capability']|p['addcap'])&u(~p['removecap']);actors.append(a)
    return dict(plan=captured,events=e,actors=actors,occupants=occupants,rng=rs,floatRng=rf,result=1)

def run(tokens,options=None,first=True,source=None,group='targeted'):
    options=options or {};setup(tokens,options)
    try:
        ret=n.call(0x456c10,[SYS,PACKET,CREATURE,ARGS,len(tokens),int(first)],count=1500000)
        got=dict(plan=native_plan,events=list(events),actors=actor_snapshots(),occupants=list(n.read(SET+0x110,3)),rng=n.unpack('<I',0x8066c0)[0],floatRng=n.unpack('<I',0x95e5d4)[0],result=ret)
        want=model(tokens,options,first)
        for key in got:check(group+'-'+key,got[key],want[key],dict(tokens=tokens,options=options,first=first,source=source))
        vectors.append(dict(tokens=tokens,options=options,first=first,source=source,native=got))
    except Exception as ex:errors.append(dict(tokens=tokens,options=options,first=first,error=str(ex)));raise

if __name__=='__main__':
    base=['type=Test','locator=One','script=Default']
    for first in [False,True]:
        for ts in [[],base,['type=Test'],['locator=One'],base+['groupsize=0'],base+['groupsize=3'],base+['mingroupsize=1','maxgroupsize=4'],base+['groupsize=2','mingroupsize=3','maxgroupsize=1']]:run(ts,first=first)
    for tokens in [base+['no_gun','CheapAsChips','capability=gun','lose_capability=other','state=Spawn'],base+['ballooning'],['type=Test','ridden_by=myself','groupsize=2'],base+['ridden_by=Other','ballooning'],base+['zipdown','fall_chance=.5'],base+['zipdown','fall_chance=0'],base+['zipdown','fall_chance=1'],['type=Test','start_locator_set=Group'],['type=Test','start_locator_set=Group','locator_set=missing'],['type=Test','locator_set=myset','dont_inherit_locator_set'],['type=Test','locator=mylocator','addtoset=myset'],base+['groupsize=3','not_grouped','xoffset=2','yoffset=3','zoffset=4'],base+['groupsize=4','crate_height=5','crate_delay=.25'],base+['type=Other','type=generic_goon'],['type=Barman','type=Jabba','type=CantinaBand','type=Ignored','type=RandomMap','locator=One'],base+['nearest_player','offscreen','on_screen','mindy=-2','maxdy=5','max_range_to_player=30'],base+['prefixgroupsize=param3','xspacing=beta'],base+['groupsize=1','groupsize=4'],base+['unknown','oxff_screen','alert_to_player','yggoffset=5'],base+['zipup=zip'],['type=Test','zipup=zip','groupsize=2']]:
        for options in [{},{'success':False},{'alternating':True},{'selectFail':True},{'hub':True},{'noTypeCallbacks':True}]:run(tokens,options)
    for seed in [1,2,7,123,0x7654321,0x7fffffff]:
        for count in range(1,6):run(base+['mingroupsize=1','maxgroupsize='+str(count),'not_grouped','zipdown','fall_chance=.5'],{'seed':seed,'floatSeed':seed})
    for count in [9,10,11,12]:run(['type=Name'+str(j) for j in range(count)]+['locator=One'])
    for count in [31,32,33,63,64,65]:run(['type=Test']+['locator=One']*count+['zipup=zip'])
    for count in [0,1,31,32]:run(['type=Test']+['zipup=zip']*count)
    for ts in [base+['state=One','state=Two','script=First','script=Last'],base+['prefixMINGROUPSIZE=2.99','maxgroupsize 2'],base+['type=missing','type=generic_goon'],base+['prefixZIPDOWN','prefixOffScreen','prefixNo_Gun'],base+['locator_set=One','locator_set=missing'],base+['start_locator_set=One','start_locator_set=missing'],base+['locator_set=One','dont_inherit_locator_set'],base+['type=RandomMap','type=generic_goon']]:
        for options in [{},{'preinherit':True},{'occupants':[0,0,0]},{'hub':True}]:run(ts,options)
    # Actual authored commands, including retained unknown/misspelled tokens.
    for index,use in enumerate(uses):
        options={'hub':'/LEVELS/MAP/' in use['source']}
        source=dict(index=index,source=use['source'],line=use['line'])
        for variant in [{'success':False},{'success':True},{'success':True,'alternating':True}]:run(use['args'],dict(options,**variant),source=source,group='authored')
    result=dict(binarySha256=n.sha256,checks=sum(checks.values()),mismatches=len(errors),groups=checks,examples=errors[:20],authoredOccurrences=len(uses),fixtureCases=len(vectors),adapters=[hex(x) for x in hooks if x not in [0x45776d,0x4577b0]],limits=['World/name/type/candidate/formation/allocation/effect calls are explicit fixture adapters. Original parser, loop, field mutations, scalar evaluator, RNG and cardinal vector helpers execute unchanged.','Zip-up allocation returns null in these fixtures; successful zip-up setup is external, not verified or implemented.','Actor comparisons cover documented fields, not every byte or downstream effects.','Synthetic locator bindings are not the actual level world or source reachability.','Native negative-count loops, stack overflow inputs, nonfinite numeric operands and full hub loader behavior are outside the bounded core.','Compiled C# differential execution remains pending under the Windows execution denial.'])
    (BASE/'reports/gameplay-createcreatures-tests.json').write_text(json.dumps(result,indent=2),encoding='utf8')
    (BASE/'reports/gameplay-createcreatures-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':')),encoding='utf8')
    print(json.dumps(result))
    if errors:raise SystemExit(1)
