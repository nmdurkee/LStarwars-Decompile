"""Independent finite PC idle scheduling reconstruction."""
import importlib.util,struct
from pathlib import Path
s=importlib.util.spec_from_file_location('wide',Path(__file__).with_name('animation-x87.py'));w=importlib.util.module_from_spec(s);s.loader.exec_module(w)
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
def rand(state):
 state['seed']=(state['seed']*0x24cd+1)&65535
 return state['seed']
def alternate(ctx):return 118 if ctx['variant']==0 and ctx['characterFlags']&128 else 25
def base(o,clips,ctx):
 a=alternate(ctx)
 if ctx['throwHeld']:return 151
 return a if a in clips and(1 not in clips or o.u8(0xe22)&1 or o.u8(0xe33)==1)else 1
def duration(clip,ctx,state):
 if not ctx['durationLookup']:return 0.
 rate=w.div(w.wide(clip['fps']),w.wide(30.))
 seconds=w.store(w.mul(w.mul(w.div(w.wide(1.),rate),w.wide(0.03333333507180214)),w.wide(f32(clip['endFrame']-1))))
 state['blendOut']=clip['blendOut'];return seconds
def limit(clip,cycles,ctx,state):
 d=duration(clip,ctx,state)
 return w.store(w.add(w.mul(w.wide(d),w.wide(cycles)),w.wide(-state['blendOut'])))
def reset(o,clips,ctx,state,mode,action):
 if action==151:return
 o.put(0x2bc,0);o.s16(0x2c4,action);c=clips.get(action)
 if c and c['minimum']:
  repetitions=c['minimum']
  if repetitions<c['maximum']:repetitions+=rand(state)//(65535//(c['maximum']-repetitions)+1)
  value=limit(c,repetitions,ctx,state)
 else:value=w.store(w.add(w.mul(w.mul(w.wide(rand(state)),w.wide(1.5259021893143654e-05)),w.wide(7.)),w.wide(8.)))
 o.put(0x2c0,value)
 if mode>0:
  o.put(0x2b8,0)
  if mode>1:o.s16(0x2c6,-1)
def choose(o,clips,ctx,state,default):
 group=default==alternate(ctx);candidates=[i for i in range(233)if i in clips and clips[i]['flags']&16 and bool(clips[i]['flags']&0x800)==group]
 if not candidates:reset(o,clips,ctx,state,0,default);return
 while True:
  chosen=candidates[rand(state)//(65535//len(candidates)+1)]if len(candidates)>1 else candidates[0]
  o.s16(0x2c4,chosen)
  if len(candidates)==1 or chosen!=o.i16(0x2c6):break
 c=clips[chosen];minimum=c['minimum'];maximum=c['maximum'];cycles=minimum or 1
 if minimum and maximum and minimum<maximum:cycles=minimum+rand(state)//(65535//(maximum-minimum)+1)
 o.s16(0x2c6,chosen)
 if cycles>1 and not c['flags']&2:cycles=1
 o.put(0x2bc,0);o.put(0x2c0,limit(c,cycles,ctx,state))
def update(o,clips,ctx,state,dt):
 if not ctx['modelPresent']:return
 alt=alternate(ctx);requested=o.i16(0x42);previous=o.i16(0x40)
 if requested not in(1,alt):
  selected=base(o,clips,ctx)
  if selected!=-1:reset(o,clips,ctx,state,1,selected);return
 if(requested==1 and previous==alt)or(requested==alt and previous==1):reset(o,clips,ctx,state,1,requested);return
 if requested in(1,alt):
  o.put(0x2b8,f32(o.f(0x2b8)+dt));elapsed=f32(o.f(0x2bc)+dt);o.put(0x2bc,elapsed)
  if elapsed>=o.f(0x2c0):
   if o.i16(0x2c4)==requested:choose(o,clips,ctx,state,requested)
   else:reset(o,clips,ctx,state,1,requested)
  o.s16(0x42,o.i16(0x2c4));return
 reset(o,clips,ctx,state,1,base(o,clips,ctx))
