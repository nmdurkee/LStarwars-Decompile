/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58dd90; label: FUN_0058dd90
 */

void FUN_0058dd90(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 0x7b5);
  if (((cVar1 == -1) || ((cVar1 != DAT_00802868 && (cVar1 != DAT_00802864)))) &&
     (iVar3 = FUN_0062f1a0(param_1 + 8), iVar3 != -1)) {
    uVar2 = *(uint *)(*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 8) + iVar3 * 4) + 4);
    if ((uVar2 & 0x400) == 0) {
      if (((uVar2 & 0x800) != 0) && (*(float *)(param_1 + 0xd3c) < 1.0)) {
        if ((*(byte *)(param_1 + 0x38) & 4) == 0) {
          if (*(char *)(param_1 + 0xe33) == '\x01') {
            return;
          }
        }
        else if (*(char *)(param_1 + 0x39) != '\0') {
          cVar1 = *(char *)(param_1 + 0x7b5);
          if ((cVar1 != -1) && ((cVar1 == DAT_00802864 || (cVar1 == DAT_00802868)))) {
            *(undefined1 *)(param_1 + 0x7b5) = 0xff;
          }
          *(undefined1 *)(param_1 + 0xe33) = 1;
          *(undefined4 *)(param_1 + 0xd40) = 0x40a00000;
          return;
        }
        FUN_0058d430(param_1);
      }
    }
    else if (0.0 < *(float *)(param_1 + 0xd3c)) {
      if ((*(byte *)(param_1 + 0x38) & 4) == 0) {
        if (*(char *)(param_1 + 0xe33) == '\x02') {
          return;
        }
      }
      else if (*(char *)(param_1 + 0x39) != '\0') {
        cVar1 = *(char *)(param_1 + 0x7b5);
        if ((cVar1 != -1) && ((cVar1 == DAT_00802864 || (cVar1 == DAT_00802868)))) {
          *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        }
        *(undefined1 *)(param_1 + 0xe33) = 2;
        *(undefined4 *)(param_1 + 0xd40) = 0x40a00000;
        return;
      }
      FUN_0058d8e0(param_1);
      return;
    }
  }
  return;
}

