/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5b00b0; label: FUN_005b00b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b00b0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *param_1;
  iVar5 = 0;
  if (param_2 == 0) {
    *(byte *)(iVar1 + 0x38) = *(byte *)(iVar1 + 0x38) & 0xfe;
    return;
  }
  *(byte *)(iVar1 + 0x38) = *(byte *)(iVar1 + 0x38) | 1;
  *(undefined4 *)(iVar1 + 0x34) = 0xffffffff;
  FUN_0054fa60();
  iVar2 = FUN_006e6b90();
  iVar4 = 0;
  if (0 < *(int *)(iVar1 + 0x10)) {
    piVar3 = (int *)(iVar1 + 0x14);
    do {
      if ((iVar5 <= 1 - iVar2) && (1 - iVar2 <= *piVar3 + iVar5)) {
        *(int *)(iVar1 + 0x34) = iVar4;
        return;
      }
      iVar5 = iVar5 + *piVar3;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < *(int *)(iVar1 + 0x10));
  }
  return;
}

