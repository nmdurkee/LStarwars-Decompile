/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x501300; label: FUN_00501300
 */

void FUN_00501300(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  ushort uVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  
  iVar2 = param_2[5];
  iVar6 = 0;
  if ((iVar2 != 0) && (DAT_00921384 != (code *)0x0)) {
    cVar1 = *(char *)(iVar2 + 0x5b);
    param_2[5] = 0;
    pcVar7 = *(char **)(*(int *)(param_1 + 0x58) + 0x50);
    uVar5 = (uint)*(ushort *)(*(int *)(*(int *)(param_1 + 0x58) + 0x18) + 4);
    if (uVar5 != 0) {
      do {
        iVar6 = iVar6 + 1;
        if (*pcVar7 == cVar1) {
          *(short *)(param_2 + 2) = (short)iVar6;
          break;
        }
        pcVar7 = pcVar7 + 0x10;
      } while (iVar6 < (int)uVar5);
    }
    if (*(ushort *)(param_2 + 2) != 0) {
      iVar6 = (*DAT_00921384)(param_1,*(ushort *)(param_2 + 2) - 1);
      *param_2 = iVar6;
      if (iVar6 != 0) {
        if ((int)(uint)*(byte *)(iVar2 + 0x5c) < *(int *)(iVar6 + 0x178)) {
          *(ushort *)((int)param_2 + 0x12) =
               *(byte *)(*(int *)(iVar6 + 0x17c) + (uint)*(byte *)(iVar2 + 0x5c)) + 1;
        }
        uVar3 = FUN_00501290(iVar6,*(undefined1 *)(iVar2 + 0x5d));
        *(ushort *)((int)param_2 + 10) = uVar3;
        if (uVar3 != 0) {
          uVar4 = FUN_005012d0(iVar6,*(undefined4 *)(*(int *)(iVar6 + 0xc) + -4 + (uint)uVar3 * 4));
          *(undefined2 *)(param_2 + 3) = uVar4;
        }
        uVar4 = FUN_00501290(iVar6,*(undefined1 *)(iVar2 + 0x5e));
        *(undefined2 *)((int)param_2 + 0xe) = uVar4;
        uVar4 = FUN_00501290(iVar6,*(undefined1 *)(iVar2 + 0x5f));
        *(undefined2 *)(param_2 + 4) = uVar4;
      }
    }
  }
  return;
}

