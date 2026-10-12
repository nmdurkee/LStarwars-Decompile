/* Ghidra pseudocode, not original source.
 * ev_18939eb5636c5080554c34c4c464805d15dff0cc807e45e19880c96644741519
 * Entry: 0x5af330; label: FUN_005af330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005af330(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
  }
  if (((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x13c), iVar1 != 0)) &&
     (param_3 != (undefined4 *)0x0)) {
    iVar3 = 0;
    iVar4 = 0;
    if (0 < *(int *)(iVar1 + 0x6c)) {
      iVar2 = 0;
      do {
        if ((*(char *)(*(int *)(iVar1 + 0x70) + 0x1a + iVar2) != '\0') && (iVar3 < 0x20)) {
          if ((*(byte *)(*(int *)(iVar1 + 0x70) + iVar2 + 0x1c) & 1) != 0) {
            param_3[(int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5] =
                 param_3[(int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5] | 1 << ((byte)iVar3 & 0x1f);
          }
          iVar3 = iVar3 + 1;
        }
        iVar1 = *(int *)(param_1 + 0x13c);
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + 0x20;
      } while (iVar4 < *(int *)(iVar1 + 0x6c));
    }
  }
  return;
}

