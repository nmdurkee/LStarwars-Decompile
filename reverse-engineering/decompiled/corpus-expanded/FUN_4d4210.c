/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d4210; label: FUN_004d4210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d4210(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int local_c;
  int local_8;
  int local_4;
  
  iVar2 = FUN_004f7fb0(param_1);
  if ((((iVar2 != 0) &&
       (iVar2 = FUN_005cf5b0(*(undefined4 *)(DAT_00881c30 + 0x13c),&local_c,
                             *(undefined4 *)(param_1 + 0x510),1), iVar2 != 0)) &&
      (iVar3 = FUN_005d0420(&local_c), iVar2 = DAT_00881ae8, iVar3 != 0)) &&
     (cVar1 = *(char *)(DAT_00881ae8 + 0x77e0), cVar1 < '@')) {
    *(char *)(DAT_00881ae8 + 0x77e0) = cVar1 + '\x01';
    DAT_00881aec = (int *)(cVar1 * 0x140 + iVar2);
    piVar4 = &DAT_00881af0;
    piVar5 = DAT_00881aec;
    for (iVar2 = 0x50; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    *DAT_00881aec = local_c;
    DAT_00881aec[1] = local_8;
    DAT_00881aec[2] = local_4;
    DAT_00881aec[5] = *(int *)(iVar3 + 0x40);
    DAT_00881aec[3] = *(int *)(*(int *)(*DAT_00881aec + 0x54) + (uint)*(ushort *)(iVar3 + 0x5c) * 4)
    ;
    FUN_004f10e0(param_1,&PTR_s_yoffset_007ffaf8);
    iVar2 = FUN_004f7fb0(param_1);
    while (iVar2 != 0) {
      FUN_004fa020(param_1);
      iVar2 = FUN_004f7fb0(param_1);
    }
    FUN_004f11e0(param_1);
  }
  return;
}

