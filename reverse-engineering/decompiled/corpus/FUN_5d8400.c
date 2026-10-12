/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d8400; label: FUN_005d8400
 */

void FUN_005d8400(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (DAT_0097396c != 0) {
    iVar1 = (&DAT_009716a4)[param_1];
    FUN_004f3bd0(*(int *)(iVar1 + 0x10) + param_2 * 8);
    *(undefined4 *)(*(int *)(iVar1 + 0x24) + param_2 * 4) = param_3;
  }
  return;
}

