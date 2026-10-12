"""Preserve a source affine matrix as two valid glTF TRS nodes using SVD.

Applied only to NODE_MATRIX_NON_TRS failures recorded by Khronos validation.
This does not approximate an authored shear away or bake changed coordinates.
For A = U diag(s) Vt, parent T*U*S and child Vt reproduce the original affine.
Original matrices and reconstruction errors remain in node extras / report.
"""
from pathlib import Path
import json, numpy as np

root=Path('reverse-engineering').resolve()
batch=json.loads((root/'reports/geometry-finalized-gsc.json').read_text(encoding='utf-8'))
report_path=root/'reports/geometry-affine-factorization.json'
records=json.loads(report_path.read_text(encoding='utf-8'))['records'] if report_path.exists() else []

def quaternion(m):
    tr=np.trace(m)
    if tr>0:
        s=np.sqrt(tr+1)*2
        q=np.array([(m[2,1]-m[1,2])/s,(m[0,2]-m[2,0])/s,(m[1,0]-m[0,1])/s,s/4])
    else:
        i=int(np.argmax(np.diag(m)));j=(i+1)%3;k=(j+1)%3
        s=np.sqrt(1+m[i,i]-m[j,j]-m[k,k])*2
        q=np.zeros(4);q[i]=s/4;q[j]=(m[j,i]+m[i,j])/s;q[k]=(m[k,i]+m[i,k])/s;q[3]=(m[k,j]-m[j,k])/s
    return q/np.linalg.norm(q)

def rotation(q):
    x,y,z,w=q
    return np.array([[1-2*(y*y+z*z),2*(x*y-z*w),2*(x*z+y*w)],
                     [2*(x*y+z*w),1-2*(x*x+z*z),2*(y*z-x*w)],
                     [2*(x*z-y*w),2*(y*z+x*w),1-2*(x*x+y*y)]])

count=0
for row in batch['results']:
    failed={int(p['pointer'].split('/')[2]) for p in row['validation']['problems'] if p['code']=='NODE_MATRIX_NON_TRS'}
    if not failed:continue
    file=Path(row['output'])/'scene.gltf';g=json.loads(file.read_text(encoding='utf-8'))
    changed=False
    for index in sorted(failed):
        node=g['nodes'][index]
        if 'matrix' not in node:continue
        original=node['matrix'];m=np.array(original).reshape(4,4).T
        if not np.array_equal(m[3],[0,0,0,1]):raise ValueError(f'Non-affine source matrix: {row["source"]} node {index}')
        u,s,v=np.linalg.svd(m[:3,:3])
        if np.linalg.det(u)<0:u[:,2]*=-1;s[2]*=-1
        if np.linalg.det(v)<0:v[2,:]*=-1;s[2]*=-1
        qu,qv=quaternion(u),quaternion(v)
        recovered=rotation(qu)@np.diag(s)@rotation(qv)
        error=float(np.max(np.abs(recovered-m[:3,:3])))
        relative=error/(1+float(np.max(np.abs(m[:3,:3]))))
        if relative>1e-12:raise ValueError('Affine reconstruction outside tolerance')
        child={'name':node.get('name',str(index))+' [affine basis]','rotation':qv.tolist(),
               'extras':{'affineFactorizationOfNode':index}}
        for key in ['mesh','skin','camera','children','weights']:
            if key in node:child[key]=node.pop(key)
        child_index=len(g['nodes']);g['nodes'].append(child)
        del node['matrix'];node.update(translation=m[:3,3].tolist(),rotation=qu.tolist(),scale=s.tolist(),children=[child_index])
        node.setdefault('extras',{}).update(originalAffineMatrix=original,affineFactorization='SVD into two TRS nodes',affineReconstructionMaxError=error)
        records.append({'source':row['source'],'node':index,'basisNode':child_index,'sourceMatrix':original,'maxAbsoluteError':error,'maxRelativeError':relative})
        count+=1;changed=True
    if changed:file.write_text(json.dumps(g,separators=(',',':')),encoding='utf-8')
report={'method':'NumPy SVD A = U diag(s) Vt, two proper rotations with signed scale; original matrix retained.',
        'numpy':np.__version__,'count':len(records),'maxAbsoluteError':max((r['maxAbsoluteError'] for r in records),default=0),
        'maxRelativeError':max((r['maxRelativeError'] for r in records),default=0),'records':records}
report_path.write_text(json.dumps(report,indent=2),encoding='utf-8')
print(json.dumps({'newlyFactored':count,'total':len(records),'maxAbsoluteError':report['maxAbsoluteError'],'maxRelativeError':report['maxRelativeError']}))
