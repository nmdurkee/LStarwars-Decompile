/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fe640; label: FUN_005fe640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fe640(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
                 undefined4 param_5,short param_6)

{
  undefined4 uVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  
  iVar4 = 0;
  psVar3 = &DAT_00981cc0;
  do {
    if (*psVar3 == 0) {
      iVar2 = iVar4 * 0x28;
      param_1[1] = (float)param_1[1] + 0.01;
      *(undefined4 *)(iVar2 + 0x981ca0) = *param_1;
      *(undefined4 *)(iVar2 + 0x981ca4) = param_1[1];
      uVar1 = param_1[2];
      *(undefined4 *)(iVar2 + 0x981cac) = param_2;
      *(undefined4 *)(iVar2 + 0x981cb4) = param_2;
      *(undefined4 *)(iVar2 + 0x981ca8) = uVar1;
      *(undefined4 *)(iVar2 + 0x981cb0) = param_3;
      (&DAT_00981cc0)[iVar4 * 0x14] = param_4;
      *(undefined2 *)(iVar2 + 0x981cc2) = param_4;
      *(undefined4 *)(iVar2 + 0x981cb8) = param_5;
      *(undefined4 *)(iVar2 + 0x981cbc) = 0;
      *(short *)(iVar2 + 0x981cc4) = param_6 * 4;
      return;
    }
    psVar3 = psVar3 + 0x14;
    iVar4 = iVar4 + 1;
  } while ((int)psVar3 < 0x9821c0);
  return;
}

