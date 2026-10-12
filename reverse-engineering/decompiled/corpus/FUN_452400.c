/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x452400; label: FUN_00452400
 */

undefined4
FUN_00452400(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  float10 fVar4;
  
  if (param_3 != 0) {
    if ((param_6 != 0) && (iVar3 = 0, 0 < param_5)) {
      do {
        if ((DAT_009238b0 == (code *)0x0) ||
           (iVar1 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar3 * 4),param_3 + 0x13f),
           iVar1 == 0)) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"character=");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"ignore_radius");
            if (iVar1 == 0) {
              *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 2;
            }
            else {
              iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"can_go_off_path");
              if (iVar1 == 0) {
                *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 1;
              }
              else {
                iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"Opponent");
                if (iVar1 == 0) {
                  *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_3 + 0xe4);
                }
                else {
                  iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"TakeOverTarget");
                  if (iVar1 == 0) {
                    *(undefined4 *)(param_2 + 0x6c) =
                         *(undefined4 *)(**(int **)(param_3 + 0xd0) + 0xea4);
                  }
                  else {
                    fVar4 = (float10)FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar3 * 4));
                    *(float *)(param_3 + 0x180) = (float)fVar4;
                  }
                }
              }
            }
          }
          else if ((DAT_00923904 == (code *)0x0) ||
                  (puVar2 = (undefined4 *)(*DAT_00923904)(param_1,iVar1 + 10),
                  puVar2 == (undefined4 *)0x0)) {
            *(undefined4 *)(param_2 + 0x6c) = 0;
          }
          else {
            *(undefined4 *)(param_2 + 0x6c) = *puVar2;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
    if (*(int *)(param_2 + 0x6c) != 0) {
      FUN_00534e10(*(undefined4 *)(param_3 + 0xd0),*(int *)(param_2 + 0x6c),
                   *(undefined1 *)(param_2 + 0x68),*(undefined4 *)(param_3 + 0x180));
    }
    return 0;
  }
  return 1;
}

