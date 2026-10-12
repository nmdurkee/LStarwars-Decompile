/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56db40; label: FUN_0056db40
 */

undefined4 FUN_0056db40(int param_1)

{
  if (((DAT_00802814 == -1) || (*(char *)(param_1 + 0x7b5) != DAT_00802814)) &&
     ((DAT_00802818 == -1 ||
      ((*(char *)(param_1 + 0x7b5) != DAT_00802818 || (*(int *)(param_1 + 0x798) == 0)))))) {
    return 0;
  }
  return 1;
}

