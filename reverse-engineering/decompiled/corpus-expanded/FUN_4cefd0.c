/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cefd0; label: FUN_004cefd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004cefd0(void)

{
  int iVar1;
  
  if (((*(int *)(PTR_DAT_00802c54 + 300) == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_00951364)
      ) && (0 < *(int *)(PTR_DAT_00802c54 + 0x4684))) {
    iVar1 = FUN_0041a360(0x40000,0xffffffff,0xffffffff,0);
    if (iVar1 == 0) {
      return 0;
    }
    if (DAT_0093d7f0 != 0) {
      if ((*(byte *)(DAT_0093d7f0 + 0xe24) & 0x20) != 0) {
        return 1;
      }
      iVar1 = FUN_004ce220(DAT_0093d7f0,0x3fc80000);
      if (iVar1 != 0) {
        return 1;
      }
    }
    if (DAT_0093d7f4 != 0) {
      if (((*(byte *)(DAT_0093d7f4 + 0xe24) & 0x20) == 0) &&
         (iVar1 = FUN_004ce220(DAT_0093d7f4,0x3fc80000), iVar1 == 0)) {
        return 0;
      }
      return 1;
    }
  }
  return 0;
}

