/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e7d10; label: FUN_004e7d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e7d10(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_00951b50 == 0) {
    FUN_004e6000(param_1,(int)DAT_007f1994);
    FUN_004e6260(param_1);
  }
  if (DAT_0087a7f0 == 0) {
    DAT_0087a7f0 = FUN_0055ce20((int)DAT_007f199c,1,1,1,0);
  }
  if (DAT_00951b50 == 0) {
    if ((DAT_0087aa5c == 0) || (iVar1 = DAT_0087a7f0, *(float *)(DAT_0087aa5c + 0x28) != 1.0)) {
      iVar1 = 0;
    }
    FUN_004ba2d0(iVar1);
  }
  if (((DAT_0087a96c != (int *)0x0) && (*DAT_0087a96c != 0)) &&
     (*(int *)(*(int *)(*DAT_0087a96c + 0x28) + 0xc) == 2)) {
    FUN_005185e0(&DAT_0080029c,0x3f000000);
  }
  return;
}

