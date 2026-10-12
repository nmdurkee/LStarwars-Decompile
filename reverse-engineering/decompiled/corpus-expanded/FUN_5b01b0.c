/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5b01b0; label: FUN_005b01b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b01b0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  iVar3 = FUN_0055f460();
  if ((iVar3 != 0) &&
     (piVar2 = *(int **)(iVar3 + 0x5104),
     piVar2[1] != (uint)*(byte *)(*(int *)(iVar3 + 0x128) + 0x103))) {
    iVar1 = *piVar2 + piVar2[1] * 0x3c;
    iVar4 = 0;
    *(int *)(iVar1 + 0x10) = param_2;
    if (0 < param_2) {
      puVar6 = (undefined4 *)(iVar1 + 0x14);
      do {
        *puVar6 = *(undefined4 *)(param_3 + iVar4 * 4);
        iVar4 = iVar4 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar4 < param_2);
    }
    FUN_004f1f40(iVar1,param_4,0x10);
    piVar2 = (int *)(*(int *)(iVar3 + 0x5104) + 4);
    *piVar2 = *piVar2 + 1;
    uVar5 = FUN_00559ee0(*(undefined4 *)(iVar3 + 0x2ac8),DAT_00806144,0,iVar1);
    return uVar5;
  }
  return 0;
}

