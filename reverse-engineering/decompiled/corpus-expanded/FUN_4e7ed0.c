/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e7ed0; label: FUN_004e7ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e7ed0(int param_1)

{
  DAT_0087a7f0 = FUN_0055ce20((int)DAT_007f199c,1,1,0,0);
  DAT_0087aa5c = FUN_005aac00(DAT_0095df4c,"ShowHearts",0);
  DAT_0087a9e0 = FUN_0051adf0(*(int *)(param_1 + 0x2ae8),
                              *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2ae8) + 0x10) + 8),
                              "gap1_a","gap1_b",&DAT_0087a950);
  DAT_0087a96c = (int *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"obstacle3");
  if ((DAT_0087a96c != (int *)0x0) && (*DAT_0087a96c != 0)) {
    DAT_0087a908 = *DAT_0087a96c;
  }
  DAT_0087a970 = (int *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,&DAT_0075e28c);
  if ((DAT_0087a970 != (int *)0x0) && (*DAT_0087a970 != 0)) {
    DAT_0087a90c = *DAT_0087a970;
  }
  return;
}

