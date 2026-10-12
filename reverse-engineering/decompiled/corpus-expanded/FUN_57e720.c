/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57e720; label: FUN_0057e720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0057e720(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((((DAT_00951cb0 != (int *)0x0) && (-1 < param_1)) &&
      (param_1 < (int)(uint)*(ushort *)(DAT_00951cb0 + 2))) &&
     (iVar1 = (int)*(char *)(*(short *)(*DAT_00951cb0 + param_1 * 0x44) * 0x130 + 0xa3 +
                            DAT_00951b78), iVar1 != -1)) {
    iVar2 = iVar1 * 0x9c + DAT_00951354;
    if ((*(byte *)(iVar2 + 0x7a) & 2) == 0) {
      if ((DAT_0095136c != 0) && (*(char *)(DAT_0095136c + 1 + iVar1 * 0xc) != '\0')) {
        return 1;
      }
    }
    else {
      iVar1 = (int)*(char *)(iVar2 + 0x86);
      if (iVar1 != -1) {
        iVar1 = FUN_0059b700(DAT_00956290 + iVar1 * 0x1c,0);
        if (iVar1 != 0) {
          return 2;
        }
      }
    }
  }
  return 0;
}

