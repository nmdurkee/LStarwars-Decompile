/* Ghidra analysis pseudocode, not original source.
 * ev_d93daca17d105ef5f57eb8b76e4a8c3d960b6599f63d34fdaa382c813fb01a39
 * Entry: 0x578790; label: FUN_00578790
 */

undefined4 FUN_00578790(int param_1,int param_2)

{
  if ((((DAT_008028b0 != -1) && (param_1 != 0)) && (*(char *)(param_1 + 0x7b5) == DAT_008028b0)) &&
     (*(short *)(param_1 + 0x7aa) == param_2)) {
    return 1;
  }
  return 0;
}

