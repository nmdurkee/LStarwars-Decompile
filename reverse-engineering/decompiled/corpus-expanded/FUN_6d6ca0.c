/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d6ca0; label: FUN_006d6ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d6ca0(uint *param_1,uint *param_2,undefined4 *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = DAT_02975908;
  iVar5 = DAT_029755a1 * 0x100;
  _DAT_02975904 = DAT_02975908;
  if ((&DAT_029751a0)[DAT_02975908 + iVar5] == '\0') {
    DAT_02975908 = 0;
  }
  uVar2 = 0;
  uVar1 = DAT_02975908;
  if (0 < DAT_029765ac) {
    do {
      if ((((uVar2 != 0x2a) && (uVar2 != 0x36)) && ((&DAT_029751a0)[uVar2 + iVar5] != '\0')) &&
         (uVar1 = uVar2, uVar2 != uVar4)) break;
      uVar2 = uVar2 + 1;
      uVar1 = DAT_02975908;
    } while ((int)uVar2 < DAT_029765ac);
  }
  DAT_02975908 = uVar1;
  uVar1 = DAT_02975908;
  uVar4 = -(uint)(uVar4 != DAT_02975908) & DAT_02975908;
  _DAT_02975900 = uVar4;
  if (param_3 != (undefined4 *)0x0) {
    if (((&DAT_029751ca)[iVar5] == '\0') && ((&DAT_029751d6)[iVar5] == '\0')) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    *param_3 = uVar3;
  }
  if (param_1 != (uint *)0x0) {
    *param_1 = uVar1;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar4;
  }
  iVar5 = FUN_006d6b70(uVar1);
  *param_4 = -(uint)(iVar5 != 0) & DAT_02975908;
  return;
}

