/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4ef660; label: FUN_004ef660
 */

void FUN_004ef660(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (param_1 < param_2) {
    if (param_3 != 0) {
      iVar2 = (int)param_2 - (int)param_1;
      do {
        param_3 = param_3 + -1;
        *param_1 = param_1[iVar2];
        param_1 = param_1 + 1;
      } while (param_3 != 0);
      return;
    }
  }
  else {
    param_2 = param_2 + param_3;
    param_1 = param_1 + param_3;
    for (; param_3 != 0; param_3 = param_3 + -1) {
      puVar1 = param_2 + -1;
      param_2 = param_2 + -1;
      param_1 = param_1 + -1;
      *param_1 = *puVar1;
    }
  }
  return;
}

