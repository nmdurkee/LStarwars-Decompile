/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x534f20; label: FUN_00534f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00534f20(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

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
    iVar2 = *(int *)(param_3 + 0xe4);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
      FUN_00534e10(*(undefined4 *)(param_3 + 0xd0),iVar2,*(undefined1 *)(param_2 + 0x68),
                   *(undefined4 *)(param_3 + 0x180));
    }
    return 0;
  }
  return 1;
}

