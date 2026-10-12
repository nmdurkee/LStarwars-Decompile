/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x5a0320; label: FUN_005a0320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a0320(int param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  
  if (((DAT_008028a8 != -1) && (DAT_00804d08 != -1)) &&
     (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804d08 * 4) != 0)) {
    if (param_2 != 0) {
      FUN_0054a850(**(undefined4 **)(param_2 + 0xca4),0x3f19999a,0);
    }
    *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_008028a8;
    iVar1 = (int)DAT_00804d08;
    *(short *)(param_1 + 0x7aa) = DAT_00804d08;
    fVar2 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),iVar1,0,0,1);
    *(float *)(param_1 + 0x77c) = (float)fVar2;
    if (DAT_0095660c != (code *)0x0) {
      (*DAT_0095660c)(param_1);
    }
  }
  return;
}

