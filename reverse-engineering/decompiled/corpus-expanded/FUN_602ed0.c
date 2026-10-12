/* Ghidra pseudocode, not original source.
 * ev_57ca11fd66234800334e5f23d40b47e1bf5f9001c22ff37fd2f45222df4b5a02
 * Entry: 0x602ed0; label: FUN_00602ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00602ed0(int param_1,int param_2)

{
  void *_Dst;
  undefined4 uVar1;
  
  _Dst = (void *)FUN_004eef40(0x50,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0x2f4
                             );
  _memset(_Dst,0,0x50);
  *(int *)((int)_Dst + 4) = param_2;
  *(short *)((int)_Dst + 8) = (short)param_1;
  *(short *)((int)_Dst + 10) = (short)param_1;
  *(undefined1 *)((int)_Dst + 0x14) = 0xff;
  if (2 < param_2) {
    uVar1 = FUN_004eef40(param_1 * 2,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",
                         0x30b);
    *(undefined4 *)((int)_Dst + 0xc) = uVar1;
  }
  return _Dst;
}

