/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4dd4e0; label: thunk_FUN_004dd3b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_004dd3b0(int param_1)

{
  void *_Dst;
  int iVar1;
  float10 fVar2;
  
  DAT_008827e0 = FUN_00578750(0x14);
  if (*(int *)(param_1 + 0x511c) == 0) {
    FUN_00412580(param_1);
  }
  _Dst = *(void **)(param_1 + 0x511c);
  DAT_00882a6c = _Dst;
  _memset(_Dst,0,0xb030);
  if (DAT_00951b50 == 0) {
    FUN_0040f920(param_1,_Dst,0x20);
  }
  FUN_004d8990();
  _DAT_007ffd68 = 0xffffffff;
  _DAT_007ffd6c = 0xffffffff;
  _DAT_007ffd70 = 0xffffffff;
  _DAT_007ffd74 = 0xffffffff;
  DAT_007ffd78 = 0xffffffff;
  _DAT_007ffd7c = 0xffffffff;
  DAT_007ffd80 = 0xffffffff;
  _DAT_007ffd84 = 0xffffffff;
  FUN_004d9ed0();
  iVar1 = (int)*(short *)(*(int *)(DAT_029130e4 + 0x1c) + DAT_007f1b14 * 2);
  if ((iVar1 != -1) &&
     (iVar1 = iVar1 * 0x54 + *(int *)(DAT_029130e4 + 0x18), *(int *)(*(int *)(iVar1 + 0xc) + 4) != 0
     )) {
    fVar2 = (float10)FUN_0062a670(iVar1,1);
    _DAT_007fc1a0 = (float)fVar2;
  }
  return;
}

