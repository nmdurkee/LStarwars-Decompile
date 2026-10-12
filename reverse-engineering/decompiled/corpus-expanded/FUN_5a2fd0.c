/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2fd0; label: FUN_005a2fd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a2fd0(int *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1 != (int *)0x0) && (iVar4 = 0, (short)param_1[1] != 0)) {
    iVar5 = 0;
    do {
      FUN_005cfc00(*param_1 + iVar5,0);
      *(undefined2 *)(iVar5 + 0x1e + *param_1) = 0;
      *(undefined2 *)(iVar5 + 0x1c + *param_1) = 0;
      *(undefined4 *)(*param_1 + iVar5 + 0x14) = *(undefined4 *)(*param_1 + 0x18 + iVar5);
      pcVar1 = (char *)(iVar5 + 0x20 + *param_1);
      if (*pcVar1 != '\0') {
        iVar2 = FUN_0055f450(0xffffffff,pcVar1);
        uVar3 = FUN_0055a020(*(undefined4 *)(iVar2 + 0x2ac8));
        *(undefined4 *)(iVar5 + 0x30 + *param_1) = uVar3;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x34;
    } while (iVar4 < (int)(uint)*(ushort *)(param_1 + 1));
  }
  return;
}

