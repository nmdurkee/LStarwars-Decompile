/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440660; label: FUN_00440660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00440660(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EDI;
  bool bVar6;
  
  iVar1 = param_2;
  bVar6 = param_2 != 0;
  param_2 = 0;
  if (((bVar6) && ('\x01' < *(char *)(iVar1 + 0x10))) && (unaff_EDI != 0)) {
    if (param_5 != 0) {
      FUN_0051fe60(param_1,iVar1);
    }
    iVar2 = (int)*(char *)(iVar1 + 0x10);
    iVar3 = *(int *)(*(int *)(unaff_EDI + 4) + 0xa4);
    iVar5 = (-(uint)((*(uint *)(unaff_EDI + 0x1fc) & 0x100000) != 0) & 0xfffffffe) + 1;
    if ((iVar3 != 0) && (0 < iVar2)) {
      iVar4 = 0;
      do {
        if (*(int *)(param_1 + 0x28) + (uint)*(byte *)(*(int *)(iVar1 + 0x14) + iVar4) * 0x3c ==
            iVar3) {
          *(undefined1 *)(iVar4 + *(int *)(iVar1 + 0x18)) = 0xff;
          iVar2 = iVar4;
          break;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
    iVar3 = iVar2;
    if (iVar2 == *(char *)(iVar1 + 0x10)) {
      iVar2 = FUN_0054fa60();
      iVar2 = iVar2 / ((int)(0xffff / (longlong)(int)*(char *)(iVar1 + 0x10)) + 1);
      iVar3 = iVar2;
    }
    do {
      while( true ) {
        iVar4 = (int)*(char *)(iVar1 + 0x10);
        iVar2 = iVar2 + iVar5;
        if (iVar2 < iVar4) {
          if (iVar2 < 0) {
            if (param_3 == 0) {
              *(uint *)(unaff_EDI + 0x1fc) = *(uint *)(unaff_EDI + 0x1fc) & 0xffefffff;
              iVar2 = 1;
              iVar5 = 1;
            }
            else {
              iVar2 = iVar4 + -1;
            }
          }
        }
        else {
          if (param_4 != 0) {
            *(undefined4 *)(*(int *)(unaff_EDI + 4) + 0xa4) = 0;
            return;
          }
          if (param_3 == 0) {
            iVar5 = -1;
            *(uint *)(unaff_EDI + 0x1fc) = *(uint *)(unaff_EDI + 0x1fc) | 0x100000;
            iVar2 = iVar4 + -2;
          }
          else {
            iVar2 = 0;
          }
        }
        if (iVar2 == iVar3) break;
        if ((param_5 == 0) || (*(char *)(iVar2 + *(int *)(iVar1 + 0x18)) == -1)) goto LAB_004407aa;
      }
    } while ((param_3 == 0) && (param_2 = param_2 + 1, param_2 < 2));
LAB_004407aa:
    *(uint *)(*(int *)(unaff_EDI + 4) + 0xa4) =
         *(int *)(param_1 + 0x28) + (uint)*(byte *)(*(int *)(iVar1 + 0x14) + iVar2) * 0x3c;
    *(undefined1 *)(iVar2 + *(int *)(iVar1 + 0x18)) = *(undefined1 *)(unaff_EDI + 0x28d);
  }
  return;
}

