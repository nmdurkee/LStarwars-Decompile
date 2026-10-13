"""Read-only targeted native review of EngageOpponent arithmetic."""
import importlib.util,json,struct
from pathlib import Path
P=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('review',P/'gameplay-engage-opponent-verify.py');g=importlib.util.module_from_spec(s);s.loader.exec_module(g)
o=dict(goal=.5,fireRange=0,actorOverrides={'0':{'position':[0,0,0]},'1':{'position':[1,2.0**-12,2.0**-27]}})
g.run([],o,False,kind='review_float_tie')
report={'schema':'geometry-engage-review-v1','nativeAddress':'0x447f00','binarySHA256':g.n.sha256,'finding':'Distance squared helper loses a positive term at float32 tie when summing products in double instead of original64-significand x87.','affectedSource':'reconstructed/gameplay/LocatorCommands.cs:102','caller':'reconstructed/gameplay/EngageOpponent.cs:100','fixture':o,'exactDistanceExpression':'1 + 2^-24 + 2^-54','doubleThenFloat32Word':'0x3f800000','originalX87ThenFloat32Word':'0x3f800001','expectedNativeBehavior':'Movement intent mode1 because squared distance exceeds outer threshold1.','formerModelBehavior':'Face/no movement because squared distance equals1.','nativeModelMismatches':len(g.errors),'details':g.errors,'scope':'Read-only review; gameplay owner notified. No source edit or managed execution.'}
(P.parent/'reports/geometry-engage-review.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps({k:report[k]for k in ['finding','nativeModelMismatches','expectedNativeBehavior']}))

