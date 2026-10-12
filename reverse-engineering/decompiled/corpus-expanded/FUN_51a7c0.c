/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51a7c0; label: FUN_0051a7c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0051a7c0(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x158) != param_2) {
    *(undefined4 *)(param_1 + 0x15c) = 0;
    *(undefined4 *)(param_1 + 0x160) = 0;
    *(undefined4 *)(param_1 + 0x164) = 0;
    *(undefined4 *)(param_1 + 0x168) = 0;
    *(undefined4 *)(param_1 + 0x16c) = 0;
    *(int *)(param_1 + 0x158) = param_2;
    *(undefined1 *)(param_1 + 0x161) = 0xff;
    *(undefined2 *)(param_1 + 0x13a) = 0;
    *(undefined2 *)(param_1 + 0x124) = 0xffff;
    *(undefined1 *)(param_1 + 0x13c) = 0xff;
    *(undefined1 *)(param_1 + 0x13d) = 0;
    *(undefined4 *)(param_1 + 0x17c) = 0;
    if ((param_2 != 0) && (iVar2 = 0, *(char *)(param_2 + 0x14) != '\0')) {
      iVar3 = 0;
      do {
        if ((*(uint *)(*(int *)(param_2 + 0x88) + 0x18 + iVar3) & *(uint *)(param_1 + 0x130)) != 0
            || (*(uint *)(*(int *)(param_2 + 0x88) + 0x1c + iVar3) & *(uint *)(param_1 + 0x134)) !=
               0) {
          uVar1 = __allshl();
          *(ushort *)(param_1 + 0x13a) = *(ushort *)(param_1 + 0x13a) | uVar1;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x28;
      } while (iVar2 < (int)(uint)*(byte *)(param_2 + 0x14));
    }
  }
  return;
}

