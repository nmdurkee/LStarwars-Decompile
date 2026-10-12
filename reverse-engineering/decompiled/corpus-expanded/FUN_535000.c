/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x535000; label: FUN_00535000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00535000(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if (param_3 != 0) {
    if ((param_6 != 0) && (iVar2 = 0, 0 < param_5)) {
      do {
        if ((DAT_009238b0 == (code *)0x0) ||
           (iVar1 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar2 * 4),param_3 + 0x13f),
           iVar1 == 0)) {
          iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar2 * 4),"ignore_radius");
          if (iVar1 == 0) {
            *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 2;
          }
          else {
            iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar2 * 4),"can_go_off_path");
            if (iVar1 == 0) {
              *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 1;
            }
            else {
              fVar3 = (float10)FUN_00514920(param_3,param_2,*(undefined4 *)(param_4 + iVar2 * 4));
              *(float *)(param_3 + 0x180) = (float)fVar3;
            }
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_5);
    }
    iVar2 = *(int *)(param_1 + 0x138c);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
      FUN_00534e10(*(undefined4 *)(param_3 + 0xd0),iVar2,*(undefined1 *)(param_2 + 0x68),
                   *(undefined4 *)(param_3 + 0x180));
    }
    return 0;
  }
  return 1;
}

