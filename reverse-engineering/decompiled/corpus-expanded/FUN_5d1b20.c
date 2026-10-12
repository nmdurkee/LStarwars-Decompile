/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d1b20; label: FUN_005d1b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d1b20(int param_1)

{
  short sVar1;
  int iVar2;
  
  sVar1 = 0;
  if (0 < *(short *)(param_1 + 0x1b4)) {
    do {
      iVar2 = (int)sVar1;
      switch(*(undefined2 *)(param_1 + 0x1ba + iVar2 * 2)) {
      case 2:
        sVar1 = sVar1 + 4;
        break;
      case 3:
        sVar1 = sVar1 + 5;
        break;
      case 4:
      case 7:
      case 0xd:
      case 0xf:
        sVar1 = sVar1 + 3;
        break;
      case 9:
      case 10:
        *(undefined2 *)(param_1 + 0x1bc + iVar2 * 2) =
             *(undefined2 *)(&DAT_00963e50 + *(short *)(param_1 + 0x1bc + iVar2 * 2) * 4);
      case 0:
      case 1:
      case 0x11:
        sVar1 = sVar1 + 2;
        break;
      case 0xb:
        *(undefined2 *)(param_1 + 0x1c0 + iVar2 * 2) =
             *(undefined2 *)(&DAT_00963e50 + *(short *)(param_1 + 0x1c0 + iVar2 * 2) * 4);
        sVar1 = sVar1 + 4;
        break;
      case 0xc:
      case 0xe:
      case 0x10:
        sVar1 = sVar1 + 1;
      }
    } while (sVar1 < *(short *)(param_1 + 0x1b4));
  }
  return;
}

