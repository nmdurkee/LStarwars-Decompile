/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x5764b0; label: FUN_005764b0
 */

undefined4 FUN_005764b0(int param_1)

{
  int iVar1;
  
  if ((((DAT_009514b8 == (short *)0x0) || (*DAT_009514b8 != param_1)) && (-1 < param_1)) &&
     (*(int *)(DAT_00926c20 + param_1 * 4) != 0)) {
    iVar1 = FUN_00576480(param_1);
    if (((iVar1 != 0) && (*(char *)(iVar1 + 0x14) == '\0')) && (*(float *)(iVar1 + 0x18) <= 0.0)) {
      return 1;
    }
  }
  return 0;
}

