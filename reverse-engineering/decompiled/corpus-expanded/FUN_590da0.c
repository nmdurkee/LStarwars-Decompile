/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x590da0; label: FUN_00590da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00590da0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_1 != 0) {
    *(ushort *)(param_1 + 0x7a) = *(ushort *)(param_1 + 0x7a) | 2;
    if (*(int *)(param_1 + 0x18) == 0) {
      FUN_005a15e0(*(undefined4 *)(param_1 + 0x10),1);
      FUN_005a11f0(*(undefined4 *)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x48) = 0x3e99999a;
      *(undefined4 *)(param_1 + 0x44) = 0x3e99999a;
    }
    else {
      iVar1 = 0;
      if (*(char *)(param_1 + 0x6c) != '\0') {
        do {
          puVar3 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x14) + iVar1 * 4) + 0x24);
          puVar4 = puVar3 + 0x20;
          for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar4 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar4 = puVar4 + 1;
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < (int)(uint)*(byte *)(param_1 + 0x6c));
      }
    }
    *(undefined1 *)(param_1 + 0x6f) = 0;
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined1 *)(param_1 + 0x6f) = *(undefined1 *)(param_1 + 0x6c);
    }
    *(ushort *)(param_1 + 0x7a) = *(ushort *)(param_1 + 0x7a) & 0xfffb;
    *(undefined1 *)(param_1 + 0x6e) = 0;
    *(undefined1 *)(param_1 + 0x6d) = 2;
    if ((*(byte *)(param_1 + 0x72) & 2) != 0) {
      if (*(int *)(param_1 + 0x18) == 0) {
        FUN_005a15e0(*(int *)(param_1 + 0x10),0);
      }
      *(ushort *)(param_1 + 0x7a) = *(ushort *)(param_1 + 0x7a) & 0xfffd;
    }
    if (DAT_009555b4 != (code *)0x0) {
      (*DAT_009555b4)(param_1);
    }
  }
  return;
}

