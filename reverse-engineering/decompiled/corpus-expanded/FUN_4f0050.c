/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f0050; label: FUN_004f0050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f0050(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  
  iVar4 = 0;
  if (0 < DAT_0297e064) {
    puVar5 = &DAT_029803e8;
    do {
      if (puVar5[-2] == 1) {
        uVar3 = puVar5[8];
        uVar1 = puVar5[7];
        iVar2 = FUN_006dede0(uVar1,uVar3);
        if (iVar2 == 0) {
          puVar5[-2] = 0xffffffff;
        }
        else {
          iVar2 = FUN_006dee00(uVar1,uVar3);
          if (iVar2 != 0) {
            *puVar5 = *puVar5 | 8;
          }
          uVar3 = FUN_006dee10(uVar1,uVar3);
          puVar5[6] = uVar3;
        }
      }
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 0x8d;
    } while (iVar4 < DAT_0297e064);
  }
  if (param_1 == (undefined4 *)0x0) {
    return DAT_0297e064;
  }
  *param_1 = &DAT_029803e0;
  return DAT_0297e064;
}

