/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x573aa0; label: FUN_00573aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00573aa0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int local_4;
  
  local_4 = 0;
  if (*(short *)(param_1 + 0x1e0) != 0) {
    iVar3 = param_1 + 0x14;
    do {
      if ((*(int *)(param_2 + 0x120) != -1) && (0 < DAT_00951234)) {
        puVar4 = &DAT_00955fd0;
        iVar5 = 0;
        do {
          if ((*(short *)(puVar4 + 8) == *(short *)(iVar3 + 0x18)) &&
             (iVar1 = FUN_004f8b10(puVar4,iVar3), iVar1 == 0)) {
            return 1;
          }
          iVar5 = iVar5 + 1;
          puVar4 = puVar4 + 0xc;
        } while (iVar5 < DAT_00951234);
      }
      if (DAT_00951bd4 != 0) {
        iVar1 = *(short *)(iVar3 + 0x18) * 0x54 + DAT_00951bd4;
        iVar6 = 0;
        iVar5 = iVar1;
        if (*(char *)(iVar1 + 0x50) != '\0') {
          do {
            iVar2 = FUN_004f8b10(iVar5,iVar3);
            if (iVar2 == 0) {
              return 1;
            }
            iVar6 = iVar6 + 1;
            iVar5 = iVar5 + 8;
          } while (iVar6 < (int)(uint)*(byte *)(iVar1 + 0x50));
        }
      }
      local_4 = local_4 + 1;
      iVar3 = iVar3 + 0x30;
    } while (local_4 < (int)(uint)*(ushort *)(param_1 + 0x1e0));
  }
  return 0;
}

