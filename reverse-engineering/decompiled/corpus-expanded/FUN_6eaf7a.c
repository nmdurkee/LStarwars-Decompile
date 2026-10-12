/* Ghidra pseudocode, not original source.
 * ev_73619ddf1363e83d16290e31c370c9dcae9e0ef7a000d1118e2b2a74fc34e424
 * Entry: 0x6eaf7a; label: _calloc
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _calloc
   
   Library: Visual Studio 2005 Release */

void * __cdecl _calloc(size_t _Count,size_t _Size)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  int local_8;
  
  local_8 = 0;
  pvVar2 = (void *)__calloc_impl(_Count,_Size,&local_8);
  iVar1 = local_8;
  if (((pvVar2 == (void *)0x0) && (local_8 != 0)) && (iVar3 = FUN_006ead5f(), iVar3 != 0)) {
    piVar4 = (int *)FUN_006ead5f();
    *piVar4 = iVar1;
  }
  return pvVar2;
}

