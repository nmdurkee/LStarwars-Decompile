/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56bfb0; label: FUN_0056bfb0
 */

undefined4 FUN_0056bfb0(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  if ((param_2 < 0x20) && ((*(uint *)(&DAT_008034cc + param_2 * 0xc) & 0x10000) != 0)) {
    if (param_2 != 5) {
      return 1;
    }
    if ((DAT_00950c4c != (code *)0x0) && (iVar1 = (*DAT_00950c4c)(param_1), iVar1 != 0)) {
      return 1;
    }
  }
  return 0;
}

