/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x412580; label: FUN_00412580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00412580(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x128);
  *(undefined4 *)(param_1 + 0x5118) = 1;
  if (iVar1 == DAT_0087b0f8) {
    iVar1 = FUN_00552670(param_1 + 0x104,param_1 + 0x108,0x64740);
    *(int *)(param_1 + 0x511c) = iVar1;
    *(int *)(iVar1 + 0x636d0) = iVar1 + 0x5d6d0;
    *(undefined4 *)(iVar1 + 0x636d4) = 0x100;
    *(undefined4 *)(*(int *)(param_1 + 0x511c) + 0x63728) = 0x3f800000;
    if ((*(int *)(param_1 + 0x128) == DAT_0087b0f8) &&
       (*(float *)(**(int **)(param_1 + 0x2988) + 0x70) != 0.0)) {
      *(float *)(*(int *)(param_1 + 0x511c) + 0x63728) =
           *(float *)(**(int **)(param_1 + 0x2988) + 0x70) / 11.0;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x511c) + 0x63734) = 0;
    return;
  }
  if (((iVar1 != DAT_0087b08c) && (iVar1 != DAT_0087b090)) && (iVar1 != DAT_0087b094)) {
    *(undefined4 *)(param_1 + 0x5118) = 0;
    return;
  }
  uVar2 = FUN_00552670(param_1 + 0x104,param_1 + 0x108,0xb030);
  *(undefined4 *)(param_1 + 0x511c) = uVar2;
  return;
}

