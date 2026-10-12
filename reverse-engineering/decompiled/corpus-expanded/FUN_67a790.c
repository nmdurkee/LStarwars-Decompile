/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67a790; label: FUN_0067a790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067a790(int param_1,undefined4 *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (((DAT_0292fc68 != (int *)0x0) &&
      (sVar1 = *(short *)((int)DAT_02924af4 + param_1 * 2 + 0xc), sVar1 != -1)) &&
     (DAT_02961f50 < 0x80)) {
    puVar3 = (undefined4 *)(*DAT_02924af4 + sVar1 * 0x38);
    puVar4 = (undefined4 *)(*DAT_0292fc68 + (DAT_0292fc68[0x2922] + DAT_02961f50) * 0x38);
    for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar3 = (undefined4 *)(*DAT_0292fc68 + (DAT_0292fc68[0x2922] + DAT_02961f50) * 0x38);
    *puVar3 = *param_2;
    puVar3[1] = param_2[1];
    DAT_02961f50 = DAT_02961f50 + 1;
    puVar3[2] = param_2[2];
  }
  return;
}

