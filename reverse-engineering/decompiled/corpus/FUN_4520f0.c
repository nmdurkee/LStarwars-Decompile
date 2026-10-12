/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x4520f0; label: FUN_004520f0
 */

undefined4
FUN_004520f0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  float10 fVar4;
  
  if ((param_6 != 0) && (iVar3 = 0, 0 < param_5)) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"character=");
      if (iVar1 == 0) {
        fVar4 = (float10)FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar3 * 4));
        *(float *)(param_2 + 0x9c) = (float)fVar4;
      }
      else if ((DAT_00923904 == (code *)0x0) ||
              (puVar2 = (undefined4 *)(*DAT_00923904)(param_1,iVar1 + 10),
              puVar2 == (undefined4 *)0x0)) {
        *(undefined4 *)(param_2 + 0x6c) = 0;
      }
      else {
        *(undefined4 *)(param_2 + 0x6c) = *puVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_5);
  }
  if ((param_3 != 0) && (*(int *)(param_2 + 0x6c) != 0)) {
    *(int *)(param_3 + 0x1e4) = *(int *)(param_2 + 0x6c) + 0x5c;
  }
  if (0.0 < *(float *)(param_2 + 0x9c)) {
    param_7 = *(float *)(param_2 + 0x9c) - param_7;
    *(float *)(param_2 + 0x9c) = param_7;
    if (param_7 < 0.0 != (param_7 == 0.0)) {
      *(undefined4 *)(param_2 + 0x9c) = 0;
      return 1;
    }
  }
  return 0;
}

