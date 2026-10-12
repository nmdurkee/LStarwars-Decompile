/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e7260; label: FUN_004e7260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e7260(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  DAT_0088a240 = FUN_00578750(8);
  _memset(&DAT_0088a248,0,0x3c);
  FUN_004e6590();
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0088a248,"blockrock",1);
  FUN_0054fa60();
  DAT_0088a276 = FUN_006e6b90();
  FUN_0054fa60();
  uVar1 = FUN_006e6b90();
  _DAT_0088a278 = CONCAT22(DAT_0088a27a,uVar1);
  FUN_0054fa60();
  sVar2 = FUN_006e6b90();
  _DAT_0088a278 = CONCAT22(sVar2,DAT_0088a278);
  if ((ushort)(DAT_0088a276 + 0x38dU) < 0x71b) {
    DAT_0088a276 = 0x555;
  }
  if ((ushort)(DAT_0088a278 + 0x38dU) < 0x71b) {
    _DAT_0088a278 = CONCAT22(sVar2,0x555);
  }
  if ((ushort)(sVar2 + 0x38dU) < 0x71b) {
    _DAT_0088a278 = CONCAT22(0x555,DAT_0088a278);
  }
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x50c0)) {
    iVar4 = 0;
    do {
      if (7 < DAT_0088a274) {
        return;
      }
      iVar6 = *(int *)(param_1 + 0x50c8) + iVar4;
      iVar3 = FUN_004f8a70(iVar6 + 0xf2,&DAT_0075e200);
      if (iVar3 != 0) {
        (&DAT_0088a254)[DAT_0088a274] = iVar6;
        DAT_0088a274 = DAT_0088a274 + 1;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x114;
    } while (iVar5 < *(int *)(param_1 + 0x50c0));
  }
  return;
}

