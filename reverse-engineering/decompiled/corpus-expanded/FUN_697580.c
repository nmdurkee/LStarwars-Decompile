/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x697580; label: FUN_00697580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00697580(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  int *piVar6;
  
  iVar1 = param_1 * 0x34 + in_ECX;
  piVar6 = *(int **)(iVar1 + 0xc);
  if (piVar6 != (int *)0x0) {
    *(undefined4 *)(iVar1 + 0x18) = 0;
    if ((char)param_2 != '\0') {
      *(undefined4 *)(iVar1 + 0x18) = 1;
    }
    iVar2 = FUN_006e6b90();
    uVar3 = iVar2 + _DAT_00810dc0 & (0 < iVar2 + _DAT_00810dc0) - 1;
    if ((int)uVar3 < -10000) {
      uVar3 = 0xffffd8f0;
    }
    iVar2 = (**(code **)(*piVar6 + 0x3c))(piVar6,uVar3);
    if (iVar2 < 0) {
      FUN_00696ab0(iVar2);
    }
    *(uint *)(iVar1 + 0x3c) = param_2;
    iVar2 = *(int *)(*(int *)(iVar1 + 0x1c) * 0x40c + 0x408 + *(int *)(in_ECX + 0xd0c));
    uVar3 = (param_2 ^ (int)param_2 >> 0x1f) - ((int)param_2 >> 0x1f);
    uVar5 = (int)uVar3 >> 0x1f;
    iVar4 = ((uVar3 ^ uVar5) - uVar5) * iVar2;
    (**(code **)(**(int **)(iVar1 + 0xc) + 0x44))
              (*(int **)(iVar1 + 0xc),
               (((int)(iVar4 + (iVar4 >> 0x1f & 0xfffU)) >> 0xc) * 0x30) / (iVar2 / 1000));
    (**(code **)(**(int **)(iVar1 + 0xc) + 0x24))(*(int **)(iVar1 + 0xc),&stack0xfffffff4);
    if (((uint)piVar6 & 1) == 0) {
      (**(code **)(**(int **)(iVar1 + 0xc) + 0x30))
                (*(int **)(iVar1 + 0xc),0,0,*(undefined4 *)(iVar1 + 0x18));
      return;
    }
    FUN_00696a90();
  }
  return;
}

