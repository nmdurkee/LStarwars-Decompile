/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x445910; label: FUN_00445910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00445910(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  local_4 = 1;
  if (param_6 != 0) {
    iVar3 = 0;
    if ((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) {
      iVar3 = *(int *)(param_3 + 0xd0);
    }
    iVar4 = 0;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"character");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8b10("FALSE",*(undefined4 *)(param_4 + iVar4 * 4));
          if (iVar2 == 0) {
            local_4 = 0;
          }
        }
        else if (DAT_00923904 != (code *)0x0) {
          iVar3 = (*DAT_00923904)(param_1,iVar2 + 10);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    *(int *)(param_2 + 0x6c) = iVar3;
  }
  piVar1 = *(int **)(param_2 + 0x6c);
  if (piVar1 != (int *)0x0) {
    if ((local_4 != 0) && (iVar3 = *piVar1, iVar3 != 0)) {
      *(undefined4 *)(iVar3 + 0x1010) = 0;
      *(undefined4 *)(iVar3 + 0x1008) = 0;
      if (*(char *)(iVar3 + 0x28b) != '\0') {
        *(undefined1 *)(iVar3 + 0x107f) = *(undefined1 *)(iVar3 + 0x107e);
        *(undefined1 *)(iVar3 + 0x28b) = 0;
        *(undefined1 *)(iVar3 + 0xe38) =
             *(undefined1 *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0xf5);
        *(undefined1 *)(iVar3 + 0xe39) = 4;
      }
      if (*(int *)(iVar3 + 0xcd0) != 0) {
        *(undefined4 *)(*(int *)(iVar3 + 0xcd0) + 0x1010) = 0;
        *(undefined4 *)(*(int *)(iVar3 + 0xcd0) + 0x1008) = 0;
        if (*(char *)(*(int *)(iVar3 + 0xcd0) + 0x28b) != '\0') {
          *(undefined1 *)(*(int *)(iVar3 + 0xcd0) + 0x28b) = 0;
          *(undefined1 *)(*(int *)(iVar3 + 0xcd0) + 0x107f) =
               *(undefined1 *)(*(int *)(iVar3 + 0xcd0) + 0x107e);
          *(undefined1 *)(*(int *)(iVar3 + 0xcd0) + 0xe38) =
               *(undefined1 *)(*(int *)(*(int *)(*(int *)(iVar3 + 0xcd0) + 0x54) + 0x24) + 0xf5);
          *(undefined1 *)(*(int *)(iVar3 + 0xcd0) + 0xe39) = 4;
        }
      }
    }
    piVar1[0x7f] = piVar1[0x7f] ^ (local_4 << 8 ^ piVar1[0x7f]) & 0x100U;
  }
  return 1;
}

