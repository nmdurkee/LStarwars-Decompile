import importlib.util,json
from pathlib import Path
s=importlib.util.spec_from_file_location('fixture',Path(__file__).with_name('native-connections-fixture.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
for ts in [[],['from=a','to=b','obj=test','off_flag=BLOCK','on_frames=1tolastframe','bothways'],['from=a','to=b','fakeanimid=0','on_frames=2to5'],['from=a','to=b','on_flag=JUMP','on_flag=DBLJUMP','on_flag=OBSTACLE_OPEN','off_flag=OBSTACLE_CLOSED','gizmo=test']]:print(json.dumps({'tokens':ts,'parsed':f.parse(ts,{}),'native':f.command(ts)}))
