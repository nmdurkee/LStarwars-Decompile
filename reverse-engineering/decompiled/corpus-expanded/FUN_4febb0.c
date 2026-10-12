/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4febb0; label: FUN_004febb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_004febb0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *local_4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_009211e8);
  puVar3 = (undefined4 *)FUN_00547240(DAT_0091f1b4);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[2] = puVar3[2] & 0xfffffffc;
    local_4 = puVar3 + 0x44;
    piVar6 = puVar3 + 4;
    *local_4 = (int)piVar6;
    *puVar3 = param_1;
    puVar3[1] = param_2;
    puVar3[0x45] = 0;
    if (param_3 != 7) {
      puVar5 = &param_3;
      do {
        *piVar6 = param_3;
        switch(param_3) {
        case 1:
        case 5:
          piVar1 = puVar5 + 1;
          puVar5 = puVar5 + 1;
          piVar6[1] = *piVar1;
          break;
        case 2:
          piVar1 = puVar5 + 1;
          puVar5 = puVar5 + 1;
          piVar6[1] = *piVar1;
          break;
        case 3:
          uVar2 = puVar5[1];
          puVar5 = puVar5 + 1;
          iVar4 = FUN_004f1ff0(uVar2);
          local_4 = (int *)((int)local_4 + (-1 - iVar4));
          piVar6[1] = (int)local_4;
          FUN_004f1f10(local_4,uVar2);
          break;
        case 4:
          piVar1 = puVar5 + 1;
          puVar5 = puVar5 + 1;
          piVar6[1] = *piVar1;
          break;
        case 6:
          piVar1 = puVar5 + 1;
          puVar5 = puVar5 + 1;
          piVar6[1] = *piVar1;
          break;
        default:
          FUN_004fe640(param_3);
        }
        param_3 = puVar5[1];
        puVar3[0x45] = puVar3[0x45] + 1;
        puVar5 = puVar5 + 1;
        piVar6 = piVar6 + 2;
      } while (param_3 != 7);
      param_3 = 7;
    }
    if (piVar6 <= local_4) goto LAB_004fecae;
  }
  FUN_004fe640();
LAB_004fecae:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_009211e8);
  if (puVar3 != (undefined4 *)0x0) {
    SetEvent(DAT_0091f1a8);
  }
  return puVar3;
}

