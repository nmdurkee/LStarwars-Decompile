/* Ghidra pseudocode, not original source.
 * ev_57ca11fd66234800334e5f23d40b47e1bf5f9001c22ff37fd2f45222df4b5a02
 * Entry: 0x602980; label: FUN_00602980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_00602980(void)

{
  int *_Dst;
  
  _Dst = (int *)FUN_004eef40(0x70,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0x6b);
  _memset(_Dst,0,0x70);
  if (DAT_02854f30 != (int *)0x0) {
    *(int **)((int)DAT_02854f30 + 4) = _Dst;
  }
  _DAT_02854f38 = _DAT_02854f38 + 1;
  *_Dst = (int)DAT_02854f30;
  _Dst[1] = 0;
  DAT_02854f30 = _Dst;
  return _Dst;
}

