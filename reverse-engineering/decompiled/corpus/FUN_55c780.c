/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55c780; label: FUN_0055c780
 */

undefined4 FUN_0055c780(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((DAT_0093b338 == 0) && (DAT_0093b2a8 == 0)) {
    iVar1 = *(int *)(param_1 + 300);
    if ((iVar1 != 0) && ((iVar1 != DAT_00951364 && ((*(ushort *)(iVar1 + 0x7a) & 0x146) == 0)))) {
      iVar1 = FUN_0058a900(0);
      if ((iVar1 == 0) && ((DAT_00856c08 == 0 && (DAT_0093b324 == 0)))) {
        iVar1 = FUN_0057e710();
        if ((iVar1 == 0) &&
           (((DAT_0095136c != 0 &&
             (*(char *)(DAT_0095136c + 1 + *(int *)(param_1 + 0x120) * 0xc) != '\0')) &&
            (0 < DAT_0095123c)))) {
          uVar2 = FUN_00573520(*(undefined4 *)(param_1 + 300),0);
          return uVar2;
        }
      }
    }
  }
  return 0;
}

