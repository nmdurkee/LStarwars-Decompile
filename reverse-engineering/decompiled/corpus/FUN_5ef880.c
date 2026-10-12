/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5ef880; label: FUN_005ef880
 */

void FUN_005ef880(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (param_1[0x19] != 0) {
    FUN_005d3400(param_1[0x19]);
  }
  FUN_005ef050(param_1);
  iVar5 = 0;
  iVar4 = DAT_0097157c;
  if (0 < param_1[1]) {
    do {
      if ((-1 < *(int *)(*(int *)(param_1[2] + iVar5 * 4) + 0x18)) &&
         (iVar1 = *(int *)(*param_1 + iVar5 * 4), 0 < iVar1)) {
        iVar2 = *(int *)(iVar4 + -4 + iVar1 * 4);
        if ((iVar2 == 0) || (*(int *)(iVar2 + 0x18) < 1)) {
          FUN_005f8ed0(iVar2);
          iVar4 = DAT_0097157c;
          *(undefined4 *)(DAT_0097157c + -4 + iVar1 * 4) = 0;
        }
        else if (iVar2 != 0) {
          *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + -1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_1[1]);
  }
  piVar3 = (int *)param_1[0x10];
  if (piVar3 != (int *)0x0) {
    iVar5 = 0;
    iVar4 = *piVar3;
    while (iVar4 != 0) {
      FUN_005dee40(*(undefined4 *)(*piVar3 + 0x110));
      iVar5 = iVar5 + 1;
      piVar3 = (int *)(param_1[0x10] + iVar5 * 4);
      iVar4 = *piVar3;
    }
  }
  FUN_005dee40(param_1[0x44]);
  FUN_006026a0(param_1);
  return;
}

