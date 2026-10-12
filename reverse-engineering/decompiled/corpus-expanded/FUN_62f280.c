/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x62f280; label: FUN_0062f280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0062f280(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 != -1) {
    iVar3 = (int)*(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_2 * 2);
    if (iVar3 != -1) {
      iVar3 = iVar3 * 0x54 + *(int *)(DAT_029130e4 + 0x18);
      if ((param_3 != -1) &&
         (iVar4 = (int)*(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_3 * 2), iVar4 != -1)) {
        iVar4 = iVar4 * 0x54 + *(int *)(DAT_029130e4 + 0x18);
        if (*(char *)(param_1 + 0x31) == '\0') {
          iVar1 = *(short *)(param_1 + 0x36) * 4;
          if ((*(int *)(iVar1 + *(int *)(iVar3 + 0xc)) != 0) &&
             (*(int *)(iVar1 + *(int *)(iVar4 + 0xc)) != 0)) {
            return 1;
          }
        }
        else {
          iVar3 = *(int *)(iVar3 + 0xc);
          iVar1 = *(short *)(param_1 + 0x32) * 4;
          if ((((*(int *)(iVar3 + iVar1) != 0) &&
               (iVar2 = *(short *)(param_1 + 0x34) * 4, *(int *)(iVar2 + iVar3) != 0)) &&
              (iVar3 = *(int *)(iVar4 + 0xc), *(int *)(iVar3 + iVar1) != 0)) &&
             (*(int *)(iVar3 + iVar2) != 0)) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

