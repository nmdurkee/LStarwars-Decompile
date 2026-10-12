/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a1a70; label: FUN_005a1a70
 */

void FUN_005a1a70(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 0xc) != 0)) && (-1 < param_2)) &&
     (param_2 < DAT_00956614)) {
    iVar1 = *(int *)(DAT_0095661c + param_2 * 4);
    iVar3 = 0;
    if (0 < DAT_00956618) {
      do {
        if (*(int *)(*(int *)(param_1 + 0xc) + iVar3 * 4) == 0) {
          return;
        }
        *(int *)(*(int *)(*(int *)(param_1 + 0xc) + iVar3 * 4) + 0xc) =
             (int)*(char *)(iVar3 + iVar1);
        if ((*(int *)(*(int *)(*(int *)(param_1 + 0xc) + iVar3 * 4) + 0xc) == 1) ||
           (iVar2 = *(int *)(*(int *)(param_1 + 0xc) + iVar3 * 4), *(int *)(iVar2 + 0xc) == 3)) {
          iVar2 = *(int *)(*(int *)(param_1 + 0xc) + iVar3 * 4);
          if ((*(byte *)(iVar2 + 10) & 4) == 0) {
            FUN_005a0640(iVar2);
          }
        }
        else if ((*(byte *)(iVar2 + 10) & 4) != 0) {
          FUN_005a0720(iVar2);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_00956618);
    }
  }
  return;
}

