/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69a980; label: FUN_0069a980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069a980(int param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  void *_Dst;
  undefined4 local_4;
  
  if (*(char *)(in_ECX + 0x40) == '\0') {
    uVar1 = FUN_0069a680(param_1,param_2,param_3);
    return uVar1;
  }
  FUN_004ffaa0(DAT_02973a00);
  if (*(int *)(in_ECX + 0x318) == 0) {
    *param_3 = 0;
    return 0x80004005;
  }
  FUN_004ffae0();
  local_4 = 0;
  uVar2 = FUN_0069d8d0(in_ECX + 0x48,param_1,param_2,0,2,1,&local_4);
  if ((int)uVar2 < 0) {
    if (param_3 != (uint *)0x0) {
      *param_3 = 0;
    }
    FUN_004ffac0(DAT_02973a00);
    return 0x80004005;
  }
  _Dst = (void *)(param_1 + uVar2);
  uVar3 = uVar2;
  while (0 < (int)uVar3) {
    if (param_2 <= uVar2) goto LAB_0069aa71;
    uVar3 = FUN_0069d8d0(in_ECX + 0x48,_Dst,param_2 - uVar2,0,2,1,&local_4);
    if ((int)uVar3 < 0) {
      if (param_3 != (uint *)0x0) {
        *param_3 = 0;
      }
      FUN_004ffac0(DAT_02973a00);
      return 0x80004005;
    }
    uVar2 = uVar2 + uVar3;
    _Dst = (void *)((int)_Dst + uVar3);
  }
  if (uVar2 < param_2) {
    _memset(_Dst,0,param_2 - uVar2);
  }
LAB_0069aa71:
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar2;
  }
  FUN_004ffac0(DAT_02973a00);
  return 0;
}

