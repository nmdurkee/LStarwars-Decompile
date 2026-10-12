/* Ghidra pseudocode, not original source.
 * ev_3d36383f96f3bc0df86ca3b0bd2be0f2b31f3818026a757d33379a6c98cf77a3
 * Entry: 0x70a622; label: ___init_time
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    ___init_time
   
   Library: Visual Studio 2005 Release */

int __cdecl ___init_time(threadlocinfo *_LocInfo)

{
  undefined **ppuVar1;
  undefined **_Memory;
  int iVar2;
  int **ppiVar3;
  
  if (_LocInfo->lc_category[1].locale == (char *)0x0) {
    _Memory = &PTR_PTR_0082a948;
  }
  else {
    _Memory = __calloc_crt(1,0xb8);
    if (_Memory == (undefined **)0x0) {
      return 1;
    }
    iVar2 = __get_lc_time();
    if (iVar2 != 0) {
      ___free_lc_time(_Memory);
      _free(_Memory);
      return 1;
    }
    _Memory[0x2d] = (undefined *)0x1;
  }
  ppiVar3 = &_LocInfo[1].lc_category[0].wrefcount;
  ppuVar1 = (undefined **)*ppiVar3;
  if (ppuVar1 != &PTR_PTR_0082a948) {
    InterlockedDecrement((LONG *)(ppuVar1 + 0x2d));
  }
  *ppiVar3 = (int *)_Memory;
  return 0;
}

