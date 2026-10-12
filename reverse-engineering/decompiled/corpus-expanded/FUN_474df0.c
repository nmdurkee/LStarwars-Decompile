/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x474df0; label: FUN_00474df0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00474df0(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  
  if (*(int *)(in_EAX + 0x18) != 0) {
    in_EAX = *(int *)(in_EAX + 0x18);
  }
  iVar3 = 0;
  if (*(char *)(in_EAX + 0x6c) != '\0') {
    do {
      piVar1 = (int *)(*(int *)(in_EAX + 0x14) + iVar3 * 4);
      if (*(int *)(*(int *)(in_EAX + 0x14) + iVar3 * 4) != 0) {
        if (param_1 <= iVar3) {
          iVar2 = *piVar1;
        }
        else {
          iVar2 = *piVar1;
        }
        FUN_005cfc00(iVar2 + 4,param_1 > iVar3);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(uint)*(byte *)(in_EAX + 0x6c));
  }
  return;
}

