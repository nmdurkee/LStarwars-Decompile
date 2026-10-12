/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x521b30; label: FUN_00521b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00521b30(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (((in_EAX != 0) && (param_1 != 0)) &&
     (puVar4 = (undefined4 *)(in_EAX + 0x114), *(int *)(in_EAX + 0x114) == 0)) {
    piVar3 = (int *)(in_EAX + 0x18);
    if ((*(int *)(in_EAX + 0x18) == 0) ||
       (*(int *)(*(int *)(in_EAX + 0x18) + 0x2c) == *(int *)(param_1 + 0x2c))) {
      iVar1 = 0;
      piVar2 = piVar3;
      do {
        if (*piVar2 == 0) break;
        if (param_1 == *piVar2) {
          FUN_00521ad0();
          break;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar1 < 0x40);
      if (param_2 != 0) {
        iVar1 = 0;
        piVar2 = piVar3;
        do {
          if (param_2 == *piVar2) {
            if (iVar1 < 0x3f) {
              iVar5 = 0x3f - iVar1;
              do {
                *puVar4 = puVar4[-1];
                puVar4 = puVar4 + -1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
            *(int *)(in_EAX + 0x1c + iVar1 * 4) = param_1;
            return 1;
          }
          iVar1 = iVar1 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar1 < 0x40);
      }
      iVar1 = 0;
      do {
        if (*piVar3 == 0) {
          *(int *)(in_EAX + 0x18 + iVar1 * 4) = param_1;
          if (iVar1 + 1 < 0x40) {
            *(undefined4 *)(in_EAX + 0x1c + iVar1 * 4) = 0;
          }
          return 1;
        }
        iVar1 = iVar1 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar1 < 0x40);
    }
  }
  return 0;
}

