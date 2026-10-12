/* Ghidra pseudocode, not original source.
 * ev_b64bd83017f0ebae738352c8f5b7965ab01e6ce8652f7cf557bf7c06ee96df94
 * Entry: 0x6e7570; label: _malloc
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2005 Release */

void * __cdecl _malloc(size_t _Size)

{
  LPVOID pvVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t sVar4;
  uint dwBytes;
  
  if (0xffffffe0 < _Size) {
    __callnewh(_Size);
    puVar3 = (undefined4 *)FUN_006ead5f();
    *puVar3 = 0xc;
    return (void *)0x0;
  }
  do {
    if (DAT_0297c974 == (HANDLE)0x0) {
      __FF_MSGBANNER();
      FUN_006f09f8(0x1e);
      ___crtExitProcess(0xff);
    }
    if (DAT_029a9b28 == 1) {
      dwBytes = _Size;
      if (_Size == 0) {
        dwBytes = 1;
      }
LAB_006e75e1:
      pvVar1 = HeapAlloc(DAT_0297c974,0,dwBytes);
    }
    else if ((DAT_029a9b28 != 3) || (pvVar1 = (LPVOID)_V6_HeapAlloc(_Size), pvVar1 == (LPVOID)0x0))
    {
      sVar4 = _Size;
      if (_Size == 0) {
        sVar4 = 1;
      }
      dwBytes = sVar4 + 0xf & 0xfffffff0;
      goto LAB_006e75e1;
    }
    if (pvVar1 != (LPVOID)0x0) {
      return pvVar1;
    }
    if (DAT_0297cad0 == 0) {
      puVar3 = (undefined4 *)FUN_006ead5f();
      *puVar3 = 0xc;
      goto LAB_006e760f;
    }
    iVar2 = __callnewh(_Size);
    if (iVar2 == 0) {
LAB_006e760f:
      puVar3 = (undefined4 *)FUN_006ead5f();
      *puVar3 = 0xc;
      return (void *)0x0;
    }
  } while( true );
}

